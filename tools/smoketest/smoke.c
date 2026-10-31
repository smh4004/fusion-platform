/*
 * Headless mGBA runner for automated smoke tests.
 *
 *   smoke <rom.gba> <script.txt>
 *
 * The script is read line by line:
 *   wait <frames>                 run with no buttons held
 *   hold <keys> <frames>          hold buttons (A,B,SELECT,START,RIGHT,LEFT,UP,DOWN,R,L joined by +)
 *   shot <file.ppm>               save the current frame
 *   print8|print16|print32 <addr> print a value read from the bus
 *   until8 <addr> <value> <max>   run until a byte equals value, at most max frames
 *   expect8 <addr> <value>        fail unless the byte equals value
 *
 * Exits 0 when every expectation and until holds, 1 otherwise. Output lines
 * are "ok ..." or "FAIL ..." so a wrapper can report them.
 */
#include <mgba/core/core.h>
#include <mgba/core/log.h>
#include <mgba/gba/interface.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void quiet_log(struct mLogger* logger, int category, enum mLogLevel level, const char* format, va_list args)
{
    (void)logger; (void)category; (void)level; (void)format; (void)args;
}

static struct mLogger sLogger = { .log = quiet_log };

static int key_bits(const char* spec)
{
    static const char* names[] = { "A", "B", "SELECT", "START", "RIGHT", "LEFT", "UP", "DOWN", "R", "L" };
    int bits = 0;
    char buf[128];
    strncpy(buf, spec, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = 0;
    for (char* tok = strtok(buf, "+"); tok; tok = strtok(NULL, "+"))
    {
        int found = 0;
        for (int i = 0; i < 10; i++)
        {
            if (!strcmp(tok, names[i]))
            {
                bits |= 1 << i;
                found = 1;
            }
        }
        if (!found)
            fprintf(stderr, "unknown key %s\n", tok);
    }
    return bits;
}

static void save_ppm(const char* path, const color_t* buf, unsigned w, unsigned h, size_t stride)
{
    FILE* f = fopen(path, "wb");
    if (!f)
        return;
    fprintf(f, "P6\n%u %u\n255\n", w, h);
    for (unsigned y = 0; y < h; y++)
    {
        for (unsigned x = 0; x < w; x++)
        {
            color_t c = buf[y * stride + x];
            unsigned char rgb[3] = { c & 0xFF, (c >> 8) & 0xFF, (c >> 16) & 0xFF };
            fwrite(rgb, 1, 3, f);
        }
    }
    fclose(f);
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: %s <rom.gba> <script.txt>\n", argv[0]);
        return 2;
    }
    mLogSetDefaultLogger(&sLogger);

    struct mCore* core = mCoreFind(argv[1]);
    if (!core || !core->init(core))
    {
        fprintf(stderr, "cannot create core for %s\n", argv[1]);
        return 2;
    }
    mCoreInitConfig(core, NULL);

    unsigned w, h;
    core->desiredVideoDimensions(core, &w, &h);
    color_t* video = calloc((size_t)w * h, sizeof(color_t));
    core->setVideoBuffer(core, video, w);

    if (!mCoreLoadFile(core, argv[1]))
    {
        fprintf(stderr, "cannot load %s\n", argv[1]);
        return 2;
    }
    core->reset(core);

    FILE* script = fopen(argv[2], "r");
    if (!script)
    {
        fprintf(stderr, "cannot open %s\n", argv[2]);
        return 2;
    }

    char line[256];
    int failed = 0;
    unsigned long frame = 0;
    while (fgets(line, sizeof(line), script))
    {
        char cmd[32], a[128] = "", b[64] = "", c[64] = "";
        if (line[0] == '#' || sscanf(line, "%31s %127s %63s %63s", cmd, a, b, c) < 1)
            continue;

        if (!strcmp(cmd, "wait") || !strcmp(cmd, "hold"))
        {
            int keys = !strcmp(cmd, "hold") ? key_bits(a) : 0;
            long n = strtol(!strcmp(cmd, "hold") ? b : a, NULL, 0);
            core->setKeys(core, keys);
            for (long i = 0; i < n; i++, frame++)
                core->runFrame(core);
            core->setKeys(core, 0);
        }
        else if (!strcmp(cmd, "shot"))
        {
            save_ppm(a, video, w, h, w);
            printf("ok shot %s at frame %lu\n", a, frame);
        }
        else if (!strncmp(cmd, "print", 5))
        {
            unsigned long addr = strtoul(a, NULL, 0);
            unsigned long v = !strcmp(cmd, "print8") ? core->busRead8(core, addr)
                            : !strcmp(cmd, "print16") ? core->busRead16(core, addr)
                            : core->busRead32(core, addr);
            printf("ok %s %s = 0x%lx at frame %lu\n", cmd, a, v, frame);
        }
        else if (!strcmp(cmd, "until8"))
        {
            unsigned long addr = strtoul(a, NULL, 0), want = strtoul(b, NULL, 0);
            long max = strtol(c, NULL, 0), i = 0;
            while (core->busRead8(core, addr) != want && i < max)
            {
                core->runFrame(core);
                i++;
                frame++;
            }
            if (core->busRead8(core, addr) == want)
                printf("ok until8 %s == 0x%lx after %ld frames\n", a, want, i);
            else
            {
                printf("FAIL until8 %s == 0x%lx (is 0x%x) after %ld frames\n", a, want, core->busRead8(core, addr), i);
                failed = 1;
            }
        }
        else if (!strcmp(cmd, "expect8"))
        {
            unsigned long addr = strtoul(a, NULL, 0), want = strtoul(b, NULL, 0);
            unsigned v = core->busRead8(core, addr);
            printf("%s expect8 %s == 0x%lx (is 0x%x)\n", v == want ? "ok" : "FAIL", a, want, v);
            failed |= v != want;
        }
        else
        {
            fprintf(stderr, "unknown command %s\n", cmd);
        }
    }

    fclose(script);
    core->deinit(core);
    free(video);
    return failed;
}
