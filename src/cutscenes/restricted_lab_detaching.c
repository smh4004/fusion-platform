#include "cutscene.h"
#include "globals.h"
#include "macros.h"
#include "callbacks.h"
#include "syscalls.h"
#include "init_helpers.h"
#include "oam.h"
#include "text.h"
#include "audio_wrappers.h"
#include "music_wrappers.h"
#include "audio/track_internal.h"
#include "new_file_intro.h"

#include "constants/audio.h"
#include "constants/text.h"

#include "data/audio.h"
#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/sprite_data.h"
#include "data/haze_data.h"

/**
 * @brief 9ae18 | 8c | Main handler for the restricted lab detaching cutscene
 * 
 */
boolu32 CutsceneRestrictedLabDetaching(void)
{
    boolu32 ended;

    ended = FALSE;

    switch (CUTSCENE_OAM_DATA.stage)
    {
        case 0:
            CUTSCENE_OAM_DATA.stage = 1;
            CutsceneRestrictedLabDetachingInit();
            break;

        case 1:
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                SoundPlay_3b1c(SOUND_248);

            CutsceneFadeIn();
            if (gWrittenToBldy == 0)
                CUTSCENE_OAM_DATA.stage++;
            break;

        case 2:
            if (CutsceneRestrictedLabDetachingProcess())
            {
                CUTSCENE_OAM_DATA.stage = 3;
                WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
            }
            break;

        case 3:
            CutsceneFadeOut();
            if (gWrittenToBldy == BLDY_MAX_VALUE)
                ended = TRUE;
            break;
    }

    return ended;
}

// 0x0809AEA4
NAKED_FUNCTION
void CutsceneRestrictedLabDetachingInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	ldr r3, _0809AF9C @ =0x04000208\n\
	movs r5, #0\n\
	strh r5, [r3]\n\
	ldr r2, _0809AFA0 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809AFA4 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809AFA8 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809AFAC @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _0809AFB0 @ =unk_9c1bc\n\
	bl CallbackSetVBlank\n\
	bl unk_36c4\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	mov r8, r0\n\
	strh r5, [r0]\n\
	ldr r0, _0809AFB4 @ =0x0867D7CC\n\
	ldr r1, _0809AFB8 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r4, _0809AFBC @ =0x040000D4\n\
	ldr r0, _0809AFC0 @ =0x0868121C\n\
	str r0, [r4]\n\
	ldr r0, _0809AFC4 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r6, _0809AFC8 @ =0x84000080\n\
	str r6, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809AFCC @ =0x08679420\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809AFD0 @ =0x086820A4\n\
	ldr r1, _0809AFD4 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809AFD8 @ =0x08681A1C\n\
	ldr r1, _0809AFDC @ =0x0600E800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0809AFE0 @ =0x0868259C\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	str r6, [r4, #8]\n\
	ldr r1, [r4, #8]\n\
	strh r5, [r0]\n\
	ldr r1, _0809AFE4 @ =0x0400000A\n\
	movs r2, #0xe8\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	subs r2, #0xfd\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #5\n\
	adds r0, r1, #0\n\
	mov r2, r8\n\
	strh r0, [r2]\n\
	ldr r1, _0809AFE8 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r0, #1\n\
	movs r1, #0x96\n\
	movs r2, #0x5a\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #3\n\
	movs r1, #0x96\n\
	movs r2, #0x5a\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #2\n\
	movs r1, #0x96\n\
	movs r2, #0x5a\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #4\n\
	movs r1, #0x78\n\
	movs r2, #0\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	ldr r0, _0809AFEC @ =gNonGameplayRam\n\
	movs r1, #0\n\
	strh r1, [r0, #0xa]\n\
	strh r1, [r0, #0xc]\n\
	movs r1, #0xc\n\
	ldrsh r0, [r0, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809AFF0 @ =0x0868101C\n\
	adds r0, r0, r1\n\
	str r0, [r4]\n\
	ldr r0, _0809AFF4 @ =0x05000120\n\
	str r0, [r4, #4]\n\
	ldr r0, _0809AFF8 @ =0x84000008\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _0809AFFC @ =CutsceneRestrictedLabDetachingVblank\n\
	bl CallbackSetVBlank\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809AF9C: .4byte 0x04000208\n\
_0809AFA0: .4byte 0x04000004\n\
_0809AFA4: .4byte 0x0000FFEF\n\
_0809AFA8: .4byte 0x04000200\n\
_0809AFAC: .4byte 0x0000FFFD\n\
_0809AFB0: .4byte unk_9c1bc\n\
_0809AFB4: .4byte 0x0867D7CC\n\
_0809AFB8: .4byte 0x06010000\n\
_0809AFBC: .4byte 0x040000D4\n\
_0809AFC0: .4byte 0x0868121C\n\
_0809AFC4: .4byte 0x05000200\n\
_0809AFC8: .4byte 0x84000080\n\
_0809AFCC: .4byte 0x08679420\n\
_0809AFD0: .4byte 0x086820A4\n\
_0809AFD4: .4byte 0x0600E000\n\
_0809AFD8: .4byte 0x08681A1C\n\
_0809AFDC: .4byte 0x0600E800\n\
_0809AFE0: .4byte 0x0868259C\n\
_0809AFE4: .4byte 0x0400000A\n\
_0809AFE8: .4byte gWrittenToBldy\n\
_0809AFEC: .4byte gNonGameplayRam\n\
_0809AFF0: .4byte 0x0868101C\n\
_0809AFF4: .4byte 0x05000120\n\
_0809AFF8: .4byte 0x84000008\n\
_0809AFFC: .4byte CutsceneRestrictedLabDetachingVblank\n\
    .syntax divided\n");
}

// 0x0809B000
NAKED_FUNCTION
boolu32 CutsceneRestrictedLabDetachingProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #0xc\n\
	movs r7, #0\n\
	ldr r0, _0809B01C @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0x10]\n\
	adds r5, r0, #0\n\
	cmp r1, #0xa\n\
	bls _0809B012\n\
	b _0809B356\n\
_0809B012:\n\
	lsls r0, r1, #2\n\
	ldr r1, _0809B020 @ =_0809B024\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0809B01C: .4byte gNonGameplayRam\n\
_0809B020: .4byte _0809B024\n\
_0809B024: @ jump table\n\
	.4byte _0809B050 @ case 0\n\
	.4byte _0809B068 @ case 1\n\
	.4byte _0809B178 @ case 2\n\
	.4byte _0809B356 @ case 3\n\
	.4byte _0809B356 @ case 4\n\
	.4byte _0809B1B0 @ case 5\n\
	.4byte _0809B218 @ case 6\n\
	.4byte _0809B236 @ case 7\n\
	.4byte _0809B268 @ case 8\n\
	.4byte _0809B2C8 @ case 9\n\
	.4byte _0809B308 @ case 10\n\
_0809B050:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #1\n\
	beq _0809B060\n\
	b _0809B356\n\
_0809B060:\n\
	movs r0, #0\n\
	strh r0, [r5, #8]\n\
	strb r1, [r5, #0x10]\n\
	b _0809B356\n\
_0809B068:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _0809B0C0\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #2\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x14\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x14\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #2\n\
	rsbs r3, r3, #0\n\
	movs r0, #6\n\
	str r0, [sp]\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x46\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x1a\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	movs r0, #4\n\
	b _0809B156\n\
_0809B0C0:\n\
	cmp r0, #0x10\n\
	bne _0809B10C\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #2\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x1e\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x1e\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #2\n\
	rsbs r3, r3, #0\n\
	movs r5, #8\n\
	str r5, [sp]\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x32\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #8\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #1\n\
	rsbs r3, r3, #0\n\
	str r5, [sp]\n\
	b _0809B158\n\
_0809B10C:\n\
	cmp r0, #0x14\n\
	bne _0809B160\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #2\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0x50\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0xe\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #3\n\
	rsbs r3, r3, #0\n\
	movs r0, #6\n\
	str r0, [sp]\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	add r0, sp, #4\n\
	ldrh r1, [r0]\n\
	subs r1, #0xa\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	ldrh r2, [r4]\n\
	subs r2, #0x12\n\
	lsls r2, r2, #0x10\n\
	asrs r2, r2, #0x10\n\
	movs r3, #2\n\
	rsbs r3, r3, #0\n\
	movs r0, #2\n\
_0809B156:\n\
	str r0, [sp]\n\
_0809B158:\n\
	movs r0, #0x11\n\
	bl unk_9c0b4\n\
	b _0809B356\n\
_0809B160:\n\
	cmp r0, #0xaa\n\
	beq _0809B166\n\
	b _0809B356\n\
_0809B166:\n\
	strh r1, [r5, #8]\n\
	movs r0, #2\n\
	strb r0, [r5, #0x10]\n\
	ldr r0, _0809B174 @ =gWrittenToBldy\n\
	strh r1, [r0]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B174: .4byte gWrittenToBldy\n\
_0809B178:\n\
	ldr r1, _0809B1A0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bls _0809B1B8\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r0, #0\n\
	str r0, [sp, #8]\n\
	ldr r1, _0809B1A4 @ =0x040000D4\n\
	add r0, sp, #8\n\
	str r0, [r1]\n\
	ldr r2, _0809B1A8 @ =0x0300149C\n\
	str r2, [r1, #4]\n\
	ldr r0, _0809B1AC @ =0x85000090\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r2, #0x18\n\
	movs r0, #5\n\
	strb r0, [r2, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B1A0: .4byte gWrittenToBldy\n\
_0809B1A4: .4byte 0x040000D4\n\
_0809B1A8: .4byte 0x0300149C\n\
_0809B1AC: .4byte 0x85000090\n\
_0809B1B0:\n\
	ldr r1, _0809B1C0 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809B1C4\n\
_0809B1B8:\n\
	adds r0, #2\n\
	strh r0, [r1]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B1C0: .4byte gWrittenToBldy\n\
_0809B1C4:\n\
	movs r5, #0\n\
	str r5, [sp, #8]\n\
	ldr r1, _0809B208 @ =0x040000D4\n\
	add r0, sp, #8\n\
	str r0, [r1]\n\
	ldr r4, _0809B20C @ =0x0300149C\n\
	str r4, [r1, #4]\n\
	ldr r0, _0809B210 @ =0x85000090\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	subs r4, #0x18\n\
	strh r5, [r4, #8]\n\
	movs r0, #4\n\
	movs r1, #0\n\
	movs r2, #0\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #0x1e\n\
	movs r1, #0xcd\n\
	movs r2, #0xa\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	movs r0, #0xc\n\
	movs r1, #0x8c\n\
	movs r2, #0x50\n\
	bl CutsceneRestrictedLabDetachingSetupOam\n\
	ldr r0, _0809B214 @ =0x04000018\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	movs r0, #6\n\
	strb r0, [r4, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B208: .4byte 0x040000D4\n\
_0809B20C: .4byte 0x0300149C\n\
_0809B210: .4byte 0x85000090\n\
_0809B214: .4byte 0x04000018\n\
_0809B218:\n\
	ldr r2, _0809B228 @ =gWrittenToBldy\n\
	ldrh r0, [r2]\n\
	adds r1, r0, #0\n\
	cmp r1, #0\n\
	beq _0809B22C\n\
	subs r0, #2\n\
	strh r0, [r2]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B228: .4byte gWrittenToBldy\n\
_0809B22C:\n\
	strh r1, [r2]\n\
	strh r1, [r5, #8]\n\
	movs r0, #7\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
_0809B236:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x95\n\
	bne _0809B258\n\
	ldr r0, _0809B250 @ =gWrittenToBldalpha_Eva\n\
	movs r1, #0xa\n\
	strh r1, [r0]\n\
	ldr r0, _0809B254 @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B250: .4byte gWrittenToBldalpha_Eva\n\
_0809B254: .4byte gWrittenToBldalpha_Evb\n\
_0809B258:\n\
	cmp r0, #0x96\n\
	beq _0809B25E\n\
	b _0809B356\n\
_0809B25E:\n\
	movs r0, #0\n\
	strh r0, [r5, #8]\n\
	movs r0, #8\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
_0809B268:\n\
	ldrh r0, [r5, #8]\n\
	adds r0, #1\n\
	movs r6, #0\n\
	strh r0, [r5, #8]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #1\n\
	bne _0809B356\n\
	ldr r1, _0809B2C0 @ =0x04000050\n\
	ldr r2, _0809B2C4 @ =0x00001C42\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r0, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #2\n\
	adds r1, r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	mov r4, sp\n\
	adds r4, #6\n\
	movs r0, #0xc\n\
	add r1, sp, #4\n\
	adds r2, r4, #0\n\
	bl CutsceneRestrictedLabDetachingGetPositionOfOamByType\n\
	movs r0, #0xc\n\
	bl CutsceneDestroyOamOfType\n\
	add r0, sp, #4\n\
	movs r2, #0\n\
	ldrsh r1, [r0, r2]\n\
	movs r3, #0\n\
	ldrsh r2, [r4, r3]\n\
	str r6, [sp]\n\
	movs r0, #0x10\n\
	movs r3, #0\n\
	bl unk_9c0b4\n\
	strh r6, [r5, #8]\n\
	movs r0, #9\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B2C0: .4byte 0x04000050\n\
_0809B2C4: .4byte 0x00001C42\n\
_0809B2C8:\n\
	ldrh r0, [r5, #8]\n\
	adds r1, r0, #1\n\
	movs r3, #0\n\
	strh r1, [r5, #8]\n\
	ldrh r2, [r5, #0xc]\n\
	movs r4, #0xc\n\
	ldrsh r0, [r5, r4]\n\
	cmp r0, #0xe\n\
	bgt _0809B2EE\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #4\n\
	bne _0809B356\n\
	strh r3, [r5, #8]\n\
	movs r0, #1\n\
	strh r0, [r5, #0xa]\n\
	adds r0, r2, #1\n\
	strh r0, [r5, #0xc]\n\
	b _0809B356\n\
_0809B2EE:\n\
	lsls r0, r1, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	bne _0809B356\n\
	strh r3, [r5, #8]\n\
	ldr r0, _0809B304 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	movs r0, #0xa\n\
	strb r0, [r5, #0x10]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B304: .4byte gWrittenToBldy\n\
_0809B308:\n\
	adds r3, r5, #0\n\
	ldrh r0, [r3, #8]\n\
	adds r2, r0, #1\n\
	movs r4, #0\n\
	strh r2, [r3, #8]\n\
	ldr r6, _0809B32C @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r6]\n\
	cmp r1, #0xf\n\
	bhi _0809B330\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #6\n\
	bne _0809B356\n\
	strh r4, [r3, #8]\n\
	adds r0, r1, #1\n\
	strh r0, [r6]\n\
	b _0809B356\n\
	.align 2, 0\n\
_0809B32C: .4byte gWrittenToBldalpha_Eva\n\
_0809B330:\n\
	ldr r1, _0809B368 @ =0x04000050\n\
	movs r0, #0xbf\n\
	strh r0, [r1]\n\
	lsls r0, r2, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0x10\n\
	bne _0809B356\n\
	strh r4, [r5, #8]\n\
	str r4, [sp, #8]\n\
	adds r1, #0x84\n\
	add r0, sp, #8\n\
	str r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0x18\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809B36C @ =0x85000090\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r7, #1\n\
_0809B356:\n\
	bl CutsceneProcessOam\n\
	bl CutsceneDrawAllOam\n\
	adds r0, r7, #0\n\
	add sp, #0xc\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809B368: .4byte 0x04000050\n\
_0809B36C: .4byte 0x85000090\n\
    .syntax divided\n");
}

/**
 * @brief 9b370 | cc | Processes the falling restricted lab
 * 
 */
void CutsceneRestrictedLabDetachingProcessFallingLab(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = (pOam->unk_E >> 1) + pOam->spawnX;
        pOam->yPosition = pOam->spawnY - (pOam->unk_E >> 2);
    }

    pOam->timer++;
    if (pOam->timer == 10)
    {
        pOam->timer = 0;
        if (pOam->unk_E < 220)
            pOam->scaling += 2;
        else if (pOam->unk_E < 440)
            pOam->scaling += 4;
        else
            pOam->scaling += 6;

        if (pOam->scaling > 0x1FF)
            pOam->scaling = 0x200;
    }

    pOam->unk_A++;
    if (pOam->unk_A == 6)
    {
        pOam->unk_A = 0;
        pOam->unk_C++;
        if (pOam->unk_C > 15)
            pOam->unk_C = 0;
    }

    if ((u16)(pOam->xPosition + 16) > 306 || pOam->yPosition < -50 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

// 0x0809B43C
NAKED_FUNCTION
u8 CutsceneRestrictedLabDetachingSetupOam(u8 type, s16 xPosition, s16 yPosition)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r4, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	mov sb, r1\n\
	lsls r2, r2, #0x10\n\
	lsrs r6, r2, #0x10\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldr r1, _0809B490 @ =gNonGameplayRam\n\
	adds r0, r1, #0\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	adds r7, r1, #0\n\
	cmp r0, #0\n\
	beq _0809B484\n\
_0809B466:\n\
	mov r0, r8\n\
	adds r0, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	mov r8, r0\n\
	cmp r0, #0xf\n\
	bhi _0809B48A\n\
	lsls r0, r0, #3\n\
	add r0, r8\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	adds r0, #0x28\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0809B466\n\
_0809B484:\n\
	mov r2, r8\n\
	cmp r2, #0xf\n\
	bls _0809B494\n\
_0809B48A:\n\
	movs r0, #0x10\n\
	b _0809B896\n\
	.align 2, 0\n\
_0809B490: .4byte gNonGameplayRam\n\
_0809B494:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r1, _0809B500 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r1]\n\
	mov r0, r8\n\
	lsls r2, r0, #3\n\
	adds r0, r2, r0\n\
	lsls r5, r0, #2\n\
	ldr r3, _0809B504 @ =0x0300149C\n\
	mov ip, r3\n\
	adds r0, r5, r3\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809B508 @ =0x85000009\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	mov r0, ip\n\
	subs r0, #0x18\n\
	adds r3, r5, r0\n\
	mov r0, sb\n\
	strh r0, [r3, #0x18]\n\
	strh r6, [r3, #0x1a]\n\
	adds r0, r3, #0\n\
	adds r0, #0x28\n\
	strb r4, [r0]\n\
	adds r6, r3, #0\n\
	adds r6, #0x2e\n\
	ldrb r1, [r6]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strb r1, [r6]\n\
	cmp r4, #1\n\
	bne _0809B510\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	ldrb r0, [r6]\n\
	movs r1, #6\n\
	orrs r0, r1\n\
	strb r0, [r6]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B50C @ =0x08680D54\n\
	b _0809B570\n\
	.align 2, 0\n\
_0809B500: .4byte 0x040000D4\n\
_0809B504: .4byte 0x0300149C\n\
_0809B508: .4byte 0x85000009\n\
_0809B50C: .4byte 0x08680D54\n\
_0809B510:\n\
	cmp r4, #2\n\
	bne _0809B544\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	ldrb r0, [r6]\n\
	movs r1, #6\n\
	orrs r0, r1\n\
	strb r0, [r6]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B540 @ =0x08680D64\n\
	b _0809B570\n\
	.align 2, 0\n\
_0809B540: .4byte 0x08680D64\n\
_0809B544:\n\
	cmp r4, #3\n\
	bne _0809B588\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	ldrb r0, [r6]\n\
	movs r1, #6\n\
	orrs r0, r1\n\
	strb r0, [r6]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B580 @ =0x08680D74\n\
_0809B570:\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B584 @ =CutsceneRestrictedLabDetachingProcessBslPart\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B580: .4byte 0x08680D74\n\
_0809B584: .4byte CutsceneRestrictedLabDetachingProcessBslPart\n\
_0809B588:\n\
	cmp r4, #4\n\
	bne _0809B5A4\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r6]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B5A0 @ =CutsceneRestrictedLabDetachingProcessScrolling\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B5A0: .4byte CutsceneRestrictedLabDetachingProcessScrolling\n\
_0809B5A4:\n\
	cmp r4, #5\n\
	bne _0809B5B8\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B5B4 @ =0x08680E2C\n\
	b _0809B5D6\n\
	.align 2, 0\n\
_0809B5B4: .4byte 0x08680E2C\n\
_0809B5B8:\n\
	cmp r4, #6\n\
	bne _0809B5EC\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B5E4 @ =0x08680E3C\n\
_0809B5D6:\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B5E8 @ =unk_9ba50\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B5E4: .4byte 0x08680E3C\n\
_0809B5E8: .4byte unk_9ba50\n\
_0809B5EC:\n\
	cmp r4, #7\n\
	bne _0809B620\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B618 @ =0x08680DA4\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B61C @ =unk_9bac0\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B618: .4byte 0x08680DA4\n\
_0809B61C: .4byte unk_9bac0\n\
_0809B620:\n\
	cmp r4, #8\n\
	bne _0809B654\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B64C @ =0x08680D94\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B650 @ =unk_9bb30\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B64C: .4byte 0x08680D94\n\
_0809B650: .4byte unk_9bb30\n\
_0809B654:\n\
	cmp r4, #9\n\
	bne _0809B69C\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	adds r2, r3, #0\n\
	adds r2, #0x30\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldrb r1, [r6]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r6]\n\
	mov r0, ip\n\
	adds r0, #0x1c\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B694 @ =0x08680D84\n\
	str r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B698 @ =unk_9bc04\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B694: .4byte 0x08680D84\n\
_0809B698: .4byte unk_9bc04\n\
_0809B69C:\n\
	cmp r4, #0xa\n\
	bne _0809B6B8\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r6]\n\
	mov r0, ip\n\
	adds r0, #0x20\n\
	adds r0, r5, r0\n\
	ldr r1, _0809B6B4 @ =unk_9bcdc\n\
	str r1, [r0]\n\
	b _0809B894\n\
	.align 2, 0\n\
_0809B6B4: .4byte unk_9bcdc\n\
_0809B6B8:\n\
	cmp r4, #0xb\n\
	bne _0809B6DC\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r0, r7, #0\n\
	adds r0, #0x34\n\
	adds r0, r2, r0\n\
	ldr r1, _0809B6D4 @ =0x08680DCC\n\
	str r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B6D8 @ =unk_9bac0\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B6D4: .4byte 0x08680DCC\n\
_0809B6D8: .4byte unk_9bac0\n\
_0809B6DC:\n\
	cmp r4, #0xc\n\
	bne _0809B72C\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r3, r2, r7\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	adds r4, r3, #0\n\
	adds r4, #0x30\n\
	ldrb r1, [r4]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r3, #0x2e\n\
	ldrb r1, [r3]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r7, #0\n\
	adds r0, #0x34\n\
	adds r0, r2, r0\n\
	ldr r1, _0809B724 @ =0x08680FEC\n\
	str r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B728 @ =unk_9bd24\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B724: .4byte 0x08680FEC\n\
_0809B728: .4byte unk_9bd24\n\
_0809B72C:\n\
	cmp r4, #0xd\n\
	bne _0809B77C\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r3, r2, r7\n\
	movs r0, #0x80\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	adds r4, r3, #0\n\
	adds r4, #0x30\n\
	ldrb r1, [r4]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r3, #0x2e\n\
	ldrb r1, [r3]\n\
	movs r0, #7\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r7, #0\n\
	adds r0, #0x34\n\
	adds r0, r2, r0\n\
	ldr r1, _0809B774 @ =0x08680FC4\n\
	str r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B778 @ =unk_9bdf8\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B774: .4byte 0x08680FC4\n\
_0809B778: .4byte unk_9bdf8\n\
_0809B77C:\n\
	cmp r4, #0xe\n\
	bne _0809B7A0\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r1, r2, r7\n\
	adds r1, #0x2e\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B79C @ =unk_9be8c\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B79C: .4byte unk_9be8c\n\
_0809B7A0:\n\
	cmp r4, #0xf\n\
	bne _0809B7C4\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r1, r2, r7\n\
	adds r1, #0x2e\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B7C0 @ =unk_9bf54\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B7C0: .4byte unk_9bf54\n\
_0809B7C4:\n\
	cmp r4, #0x10\n\
	bne _0809B80C\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r3, r2, r7\n\
	adds r4, r3, #0\n\
	adds r4, #0x2e\n\
	ldrb r1, [r4]\n\
	movs r0, #0x19\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r3, #0x30\n\
	ldrb r1, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r7, #0\n\
	adds r0, #0x34\n\
	adds r0, r2, r0\n\
	ldr r1, _0809B804 @ =0x08680F9C\n\
	str r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B808 @ =unk_9bfb8\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B804: .4byte 0x08680F9C\n\
_0809B808: .4byte unk_9bfb8\n\
_0809B80C:\n\
	cmp r4, #0x11\n\
	bne _0809B830\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r0, r7, #0\n\
	adds r0, #0x34\n\
	adds r0, r2, r0\n\
	ldr r1, _0809B828 @ =0x08680F74\n\
	str r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B82C @ =unk_9bfb8\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B828: .4byte 0x08680F74\n\
_0809B82C: .4byte unk_9bfb8\n\
_0809B830:\n\
	cmp r4, #0x12\n\
	bne _0809B854\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r1, r2, r7\n\
	adds r1, #0x2e\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B850 @ =unk_9c04c\n\
	b _0809B892\n\
	.align 2, 0\n\
_0809B850: .4byte unk_9c04c\n\
_0809B854:\n\
	cmp r4, #0x1e\n\
	bne _0809B894\n\
	add r2, r8\n\
	lsls r2, r2, #2\n\
	adds r3, r2, r7\n\
	movs r0, #0xd0\n\
	lsls r0, r0, #1\n\
	strh r0, [r3, #0x1c]\n\
	adds r4, r3, #0\n\
	adds r4, #0x30\n\
	ldrb r1, [r4]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r4]\n\
	adds r3, #0x2e\n\
	ldrb r0, [r3]\n\
	movs r1, #6\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	adds r0, r7, #0\n\
	adds r0, #0x34\n\
	adds r0, r2, r0\n\
	ldr r1, _0809B8A4 @ =0x08680F2C\n\
	str r1, [r0]\n\
	adds r0, r7, #0\n\
	adds r0, #0x38\n\
	adds r2, r2, r0\n\
	ldr r0, _0809B8A8 @ =CutsceneRestrictedLabDetachingProcessFallingLab\n\
_0809B892:\n\
	str r0, [r2]\n\
_0809B894:\n\
	mov r0, r8\n\
_0809B896:\n\
	add sp, #4\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0809B8A4: .4byte 0x08680F2C\n\
_0809B8A8: .4byte CutsceneRestrictedLabDetachingProcessFallingLab\n\
    .syntax divided\n");
}

// 0x0809B8AC
NAKED_FUNCTION
void CutsceneRestrictedLabDetachingProcessBslPart(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldrb r3, [r2, #0x14]\n\
	cmp r3, #0\n\
	bne _0809B98C\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #9\n\
	bne _0809B8CC\n\
	strb r3, [r2, #0x13]\n\
	ldrh r0, [r2]\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
_0809B8CC:\n\
	ldrh r0, [r2, #0xe]\n\
	adds r0, #1\n\
	strh r0, [r2, #0xe]\n\
	movs r4, #6\n\
	ldrsh r1, [r2, r4]\n\
	cmp r1, #1\n\
	beq _0809B90C\n\
	cmp r1, #1\n\
	bgt _0809B8E4\n\
	cmp r1, #0\n\
	beq _0809B8EA\n\
	b _0809B954\n\
_0809B8E4:\n\
	cmp r1, #2\n\
	beq _0809B930\n\
	b _0809B954\n\
_0809B8EA:\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #4\n\
	bne _0809B964\n\
	strh r3, [r2, #0xe]\n\
	ldrh r0, [r2, #4]\n\
	adds r0, #2\n\
	strh r0, [r2, #4]\n\
	lsls r0, r0, #0x10\n\
	ldr r1, _0809B908 @ =0x017F0000\n\
	cmp r0, r1\n\
	ble _0809B964\n\
	movs r0, #1\n\
	strh r0, [r2, #6]\n\
	b _0809B964\n\
	.align 2, 0\n\
_0809B908: .4byte 0x017F0000\n\
_0809B90C:\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #5\n\
	bne _0809B964\n\
	strh r3, [r2, #0xe]\n\
	ldrh r0, [r2, #4]\n\
	adds r0, #2\n\
	strh r0, [r2, #4]\n\
	lsls r0, r0, #0x10\n\
	ldr r1, _0809B92C @ =0x019F0000\n\
	cmp r0, r1\n\
	ble _0809B964\n\
	movs r0, #2\n\
	strh r0, [r2, #6]\n\
	b _0809B964\n\
	.align 2, 0\n\
_0809B92C: .4byte 0x019F0000\n\
_0809B930:\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #6\n\
	bne _0809B964\n\
	strh r3, [r2, #0xe]\n\
	ldrh r0, [r2, #4]\n\
	adds r0, #2\n\
	strh r0, [r2, #4]\n\
	lsls r0, r0, #0x10\n\
	ldr r1, _0809B950 @ =0x01BF0000\n\
	cmp r0, r1\n\
	ble _0809B964\n\
	movs r0, #3\n\
	strh r0, [r2, #6]\n\
	b _0809B964\n\
	.align 2, 0\n\
_0809B950: .4byte 0x01BF0000\n\
_0809B954:\n\
	ldrh r0, [r2, #0xe]\n\
	cmp r0, #7\n\
	bne _0809B964\n\
	movs r0, #0\n\
	strh r0, [r2, #0xe]\n\
	ldrh r0, [r2, #4]\n\
	adds r0, #2\n\
	strh r0, [r2, #4]\n\
_0809B964:\n\
	movs r1, #4\n\
	ldrsh r0, [r2, r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	cmp r0, r1\n\
	ble _0809B972\n\
	strh r1, [r2, #4]\n\
_0809B972:\n\
	ldr r0, _0809B988 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0x10]\n\
	cmp r1, #1\n\
	bne _0809BA1C\n\
	movs r0, #0\n\
	strb r1, [r2, #0x14]\n\
	strb r0, [r2, #0x13]\n\
	strh r0, [r2, #6]\n\
	strh r0, [r2, #0xe]\n\
	b _0809BA1C\n\
	.align 2, 0\n\
_0809B988: .4byte gNonGameplayRam\n\
_0809B98C:\n\
	cmp r3, #1\n\
	bne _0809B9C0\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #9\n\
	bne _0809B9A8\n\
	strb r1, [r2, #0x13]\n\
	ldrh r0, [r2]\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
_0809B9A8:\n\
	ldrb r0, [r2, #0x10]\n\
	cmp r0, #3\n\
	bne _0809B9B6\n\
	ldrh r0, [r2, #2]\n\
	adds r0, #6\n\
	strh r0, [r2, #2]\n\
	strh r0, [r2, #8]\n\
_0809B9B6:\n\
	strh r1, [r2, #0xe]\n\
	strh r1, [r2, #0xa]\n\
	movs r0, #2\n\
	strb r0, [r2, #0x14]\n\
	b _0809BA1C\n\
_0809B9C0:\n\
	cmp r3, #2\n\
	bne _0809BA1C\n\
	ldrb r0, [r2, #0x13]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strb r0, [r2, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #9\n\
	bne _0809B9DC\n\
	strb r1, [r2, #0x13]\n\
	ldrh r0, [r2]\n\
	subs r0, #1\n\
	strh r0, [r2]\n\
_0809B9DC:\n\
	ldrh r0, [r2, #0xa]\n\
	adds r0, #1\n\
	strh r0, [r2, #0xa]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #7\n\
	bne _0809BA00\n\
	strh r1, [r2, #0xa]\n\
	ldrh r0, [r2, #4]\n\
	adds r0, #2\n\
	strh r0, [r2, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	movs r1, #0x80\n\
	lsls r1, r1, #2\n\
	cmp r0, r1\n\
	ble _0809BA00\n\
	strh r1, [r2, #4]\n\
_0809BA00:\n\
	ldrh r0, [r2, #0xe]\n\
	adds r0, #1\n\
	strh r0, [r2, #0xe]\n\
	ldrb r0, [r2, #0x10]\n\
	cmp r0, #3\n\
	bne _0809BA1C\n\
	ldrh r0, [r2, #0xe]\n\
	adds r4, r0, #0\n\
	muls r4, r0, r4\n\
	adds r0, r4, #0\n\
	asrs r0, r0, #0xa\n\
	ldrh r1, [r2, #8]\n\
	adds r0, r0, r1\n\
	strh r0, [r2, #2]\n\
_0809BA1C:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

/**
 * @brief 9ba24 | 2c | Processes the scrolling of the restricted lab detaching cutscene
 * 
 */
void CutsceneRestrictedLabDetachingProcessScrolling(struct CutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 30)
    {
        pOam->timer = 0;
        pOam->xPosition--;
    }

    WRITE_16(REG_BG3HOFS, pOam->xPosition);
}

/**
 * @brief 9ba50 | 70 | Processes a debris
 * 
 */
void unk_9ba50(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9bac0 | 70 | Processes a debris
 * 
 */
void unk_9bac0(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

// 0x0809BB30
NAKED_FUNCTION
void unk_9bb30(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3, #0x14]\n\
	cmp r0, #0\n\
	bne _0809BB48\n\
	ldrh r0, [r3]\n\
	strh r0, [r3, #6]\n\
	ldrh r0, [r3, #2]\n\
	strh r0, [r3, #8]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x14]\n\
	b _0809BB6A\n\
_0809BB48:\n\
	cmp r0, #1\n\
	bne _0809BB6A\n\
	ldrh r0, [r3, #0xe]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xe]\n\
	ldrh r0, [r3, #0xe]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsrs r1, r1, #4\n\
	ldrh r0, [r3, #6]\n\
	subs r0, r0, r1\n\
	strh r0, [r3]\n\
	ldrh r0, [r3, #0xe]\n\
	lsrs r0, r0, #3\n\
	ldrh r1, [r3, #8]\n\
	adds r0, r0, r1\n\
	strh r0, [r3, #2]\n\
_0809BB6A:\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xc\n\
	bne _0809BB8C\n\
	movs r0, #0\n\
	strb r0, [r3, #0x13]\n\
	ldrh r0, [r3, #4]\n\
	subs r0, #2\n\
	strh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bgt _0809BB8C\n\
	movs r0, #2\n\
	strh r0, [r3, #4]\n\
_0809BB8C:\n\
	ldrh r0, [r3, #0xa]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r3, #0xa]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0x10\n\
	bne _0809BBC6\n\
	strh r1, [r3, #0xa]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _0809BBAE\n\
	strh r1, [r3, #0xc]\n\
_0809BBAE:\n\
	ldr r2, _0809BBF4 @ =0x040000D4\n\
	movs r1, #0xc\n\
	ldrsh r0, [r3, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809BBF8 @ =0x0868161C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0809BBFC @ =0x05000220\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809BC00 @ =0x84000008\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
_0809BBC6:\n\
	ldrh r0, [r3]\n\
	adds r0, #0x10\n\
	lsls r0, r0, #0x10\n\
	movs r1, #0x88\n\
	lsls r1, r1, #0x11\n\
	cmp r0, r1\n\
	bhi _0809BBE4\n\
	movs r0, #2\n\
	ldrsh r1, [r3, r0]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	blt _0809BBE4\n\
	cmp r1, #0xb0\n\
	ble _0809BBF0\n\
_0809BBE4:\n\
	movs r0, #0\n\
	strb r0, [r3, #0x10]\n\
	ldrb r1, [r3, #0x16]\n\
	subs r0, #2\n\
	ands r0, r1\n\
	strb r0, [r3, #0x16]\n\
_0809BBF0:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809BBF4: .4byte 0x040000D4\n\
_0809BBF8: .4byte 0x0868161C\n\
_0809BBFC: .4byte 0x05000220\n\
_0809BC00: .4byte 0x84000008\n\
    .syntax divided\n");
}

// 0x0809BC04
NAKED_FUNCTION
void unk_9bc04(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3, #0x14]\n\
	cmp r0, #0\n\
	bne _0809BC1C\n\
	ldrh r0, [r3]\n\
	strh r0, [r3, #6]\n\
	ldrh r0, [r3, #2]\n\
	strh r0, [r3, #8]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x14]\n\
	b _0809BC42\n\
_0809BC1C:\n\
	cmp r0, #1\n\
	bne _0809BC42\n\
	ldrh r0, [r3, #0xe]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xe]\n\
	ldrh r1, [r3, #0xe]\n\
	movs r0, #0xb\n\
	muls r0, r1, r0\n\
	lsrs r0, r0, #6\n\
	ldrh r1, [r3, #6]\n\
	adds r0, r0, r1\n\
	strh r0, [r3]\n\
	ldrh r0, [r3, #0xe]\n\
	lsls r1, r0, #3\n\
	adds r1, r1, r0\n\
	asrs r1, r1, #6\n\
	ldrh r0, [r3, #8]\n\
	subs r0, r0, r1\n\
	strh r0, [r3, #2]\n\
_0809BC42:\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xc\n\
	bne _0809BC64\n\
	movs r0, #0\n\
	strb r0, [r3, #0x13]\n\
	ldrh r0, [r3, #4]\n\
	subs r0, #2\n\
	strh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	cmp r0, #0\n\
	bgt _0809BC64\n\
	movs r0, #2\n\
	strh r0, [r3, #4]\n\
_0809BC64:\n\
	ldrh r0, [r3, #0xa]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r3, #0xa]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #6\n\
	bne _0809BC9E\n\
	strh r1, [r3, #0xa]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _0809BC86\n\
	strh r1, [r3, #0xc]\n\
_0809BC86:\n\
	ldr r2, _0809BCCC @ =0x040000D4\n\
	movs r1, #0xc\n\
	ldrsh r0, [r3, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809BCD0 @ =0x0868141C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0809BCD4 @ =0x05000200\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809BCD8 @ =0x84000008\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
_0809BC9E:\n\
	ldrh r0, [r3]\n\
	adds r0, #0x10\n\
	lsls r0, r0, #0x10\n\
	movs r1, #0x88\n\
	lsls r1, r1, #0x11\n\
	cmp r0, r1\n\
	bhi _0809BCBC\n\
	movs r0, #2\n\
	ldrsh r1, [r3, r0]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	blt _0809BCBC\n\
	cmp r1, #0xb0\n\
	ble _0809BCC8\n\
_0809BCBC:\n\
	movs r0, #0\n\
	strb r0, [r3, #0x10]\n\
	ldrb r1, [r3, #0x16]\n\
	subs r0, #2\n\
	ands r0, r1\n\
	strb r0, [r3, #0x16]\n\
_0809BCC8:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809BCCC: .4byte 0x040000D4\n\
_0809BCD0: .4byte 0x0868141C\n\
_0809BCD4: .4byte 0x05000200\n\
_0809BCD8: .4byte 0x84000008\n\
    .syntax divided\n");
}

/**
 * @brief 9bcdc | 48 | Processes the scrolling of the restricted lab
 * 
 */
void unk_9bcdc(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        WRITE_16(REG_BG2HOFS, pOam->xPosition);
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        WRITE_16(REG_BG2HOFS, ((pOam->unk_C * pOam->unk_E) >> 7) + pOam->xPosition);
    }
}

// 0x0809BD24
NAKED_FUNCTION
void unk_9bd24(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3, #0x14]\n\
	cmp r0, #0\n\
	bne _0809BD3C\n\
	ldrh r0, [r3]\n\
	strh r0, [r3, #6]\n\
	ldrh r0, [r3, #2]\n\
	strh r0, [r3, #8]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x14]\n\
	b _0809BD5A\n\
_0809BD3C:\n\
	cmp r0, #1\n\
	bne _0809BD5A\n\
	ldrh r0, [r3, #0xe]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xe]\n\
	ldrh r1, [r3, #0xe]\n\
	lsrs r1, r1, #3\n\
	ldrh r0, [r3, #6]\n\
	subs r0, r0, r1\n\
	strh r0, [r3]\n\
	ldrh r0, [r3, #0xe]\n\
	lsrs r0, r0, #4\n\
	ldrh r1, [r3, #8]\n\
	adds r0, r0, r1\n\
	strh r0, [r3, #2]\n\
_0809BD5A:\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bne _0809BD7E\n\
	movs r0, #0\n\
	strb r0, [r3, #0x13]\n\
	ldrh r0, [r3, #4]\n\
	subs r0, #4\n\
	strh r0, [r3, #4]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #2\n\
	bgt _0809BD7E\n\
	movs r0, #2\n\
	strh r0, [r3, #4]\n\
_0809BD7E:\n\
	ldrh r0, [r3, #0xa]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	strh r0, [r3, #0xa]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	bne _0809BDB8\n\
	strh r1, [r3, #0xa]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #3\n\
	ble _0809BDA0\n\
	strh r1, [r3, #0xc]\n\
_0809BDA0:\n\
	ldr r2, _0809BDE8 @ =0x040000D4\n\
	movs r1, #0xc\n\
	ldrsh r0, [r3, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809BDEC @ =0x0868181C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0809BDF0 @ =0x05000260\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809BDF4 @ =0x84000008\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
_0809BDB8:\n\
	ldrh r0, [r3]\n\
	adds r0, #0x10\n\
	lsls r0, r0, #0x10\n\
	movs r1, #0x88\n\
	lsls r1, r1, #0x11\n\
	cmp r0, r1\n\
	bhi _0809BDD6\n\
	movs r0, #2\n\
	ldrsh r1, [r3, r0]\n\
	movs r0, #0x10\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	blt _0809BDD6\n\
	cmp r1, #0xb0\n\
	ble _0809BDE2\n\
_0809BDD6:\n\
	movs r0, #0\n\
	strb r0, [r3, #0x10]\n\
	ldrb r1, [r3, #0x16]\n\
	subs r0, #2\n\
	ands r0, r1\n\
	strb r0, [r3, #0x16]\n\
_0809BDE2:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809BDE8: .4byte 0x040000D4\n\
_0809BDEC: .4byte 0x0868181C\n\
_0809BDF0: .4byte 0x05000260\n\
_0809BDF4: .4byte 0x84000008\n\
    .syntax divided\n");
}

/**
 * @brief 9bdf8 | 94 | Processes a debris
 * 
 */
void unk_9bdf8(struct CutsceneOam* pOam)
{
    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    pOam->timer++;
    if (pOam->timer == 5)
    {
        pOam->timer = 0;
        pOam->scaling -= 4;
        if (pOam->scaling <= 2)
            pOam->scaling = 2;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

// 0x0809BE8C
NAKED_FUNCTION
void unk_9be8c(struct CutsceneOam* pOam)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3, #0x14]\n\
	cmp r0, #0\n\
	bne _0809BEBC\n\
	ldr r1, _0809BEAC @ =0x040000D4\n\
	ldr r0, _0809BEB0 @ =0x0868101C\n\
	str r0, [r1]\n\
	ldr r0, _0809BEB4 @ =0x05000120\n\
	str r0, [r1, #4]\n\
	ldr r0, _0809BEB8 @ =0x84000008\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #1\n\
	strb r0, [r3, #0x14]\n\
	b _0809BF46\n\
	.align 2, 0\n\
_0809BEAC: .4byte 0x040000D4\n\
_0809BEB0: .4byte 0x0868101C\n\
_0809BEB4: .4byte 0x05000120\n\
_0809BEB8: .4byte 0x84000008\n\
_0809BEBC:\n\
	cmp r0, #1\n\
	bne _0809BF14\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #8\n\
	bne _0809BF46\n\
	movs r0, #0\n\
	strb r0, [r3, #0x13]\n\
	ldrh r0, [r3, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r3, #0xc]\n\
	lsls r0, r0, #0x10\n\
	asrs r0, r0, #0x10\n\
	cmp r0, #0xe\n\
	ble _0809BEE8\n\
	movs r0, #0xf\n\
	strh r0, [r3, #0xc]\n\
	movs r0, #2\n\
	strb r0, [r3, #0x14]\n\
_0809BEE8:\n\
	ldr r2, _0809BF04 @ =0x040000D4\n\
	movs r1, #0xc\n\
	ldrsh r0, [r3, r1]\n\
	lsls r0, r0, #5\n\
	ldr r1, _0809BF08 @ =0x0868101C\n\
	adds r0, r0, r1\n\
	str r0, [r2]\n\
	ldr r0, _0809BF0C @ =0x05000120\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809BF10 @ =0x84000008\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	b _0809BF46\n\
	.align 2, 0\n\
_0809BF04: .4byte 0x040000D4\n\
_0809BF08: .4byte 0x0868101C\n\
_0809BF0C: .4byte 0x05000120\n\
_0809BF10: .4byte 0x84000008\n\
_0809BF14:\n\
	cmp r0, #2\n\
	bne _0809BF46\n\
	ldrb r0, [r3, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r3, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #6\n\
	bne _0809BF46\n\
	movs r0, #0\n\
	strb r0, [r3, #0x13]\n\
	ldr r1, _0809BF4C @ =gWrittenToBldalpha_Eva\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809BF46\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0xf\n\
	bhi _0809BF46\n\
	ldr r1, _0809BF50 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
_0809BF46:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809BF4C: .4byte gWrittenToBldalpha_Eva\n\
_0809BF50: .4byte gWrittenToBldalpha_Evb\n\
    .syntax divided\n");
}

/**
 * @brief 9bf54 | 64 | Shakes the screen
 * 
 */
void unk_9bf54(struct CutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 1)
    {
        pOam->timer = 0;
        CUTSCENE_OAM_DATA.unk_A += 2;
        if (CUTSCENE_OAM_DATA.unk_A > 160)
            CUTSCENE_OAM_DATA.unk_A = 160;
    }

    pOam->animationDurationCounter++;
    if (pOam->animationDurationCounter == 32)
        pOam->animationDurationCounter = 0;

    WRITE_16(REG_BG1HOFS, sRandomNumberTable[pOam->animationDurationCounter]);
    WRITE_16(REG_BG1VOFS, sRandomNumberTable[pOam->animationDurationCounter]);
}

/**
 * @brief 9bfb8 | 94 | Processes a debris
 * 
 */
void unk_9bfb8(struct CutsceneOam* pOam)
{
    const struct FrameData* pFrame;

    if (pOam->stage == 0)
    {
        pOam->spawnX = pOam->xPosition;
        pOam->spawnY = pOam->yPosition;
        pOam->stage = 1;
    }
    else if (pOam->stage == 1)
    {
        pOam->unk_E++;
        pOam->xPosition = ((pOam->unk_C * pOam->unk_E) >> 6) + pOam->spawnX;
        pOam->yPosition = ((pOam->unk_A * pOam->unk_E) >> 6) + pOam->spawnY;
    }

    if ((u16)(pOam->xPosition + 16) > 272 || pOam->yPosition < -16 || pOam->yPosition > 176)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }

    pFrame = &pOam->pOam[pOam->currentAnimationFrame];
    if (pFrame[0].timer == pOam->animationDurationCounter && pFrame[1].timer == 0)
    {
        pOam->type = 0;
        pOam->enabled = FALSE;
    }
}

/**
 * @brief 9c04c | 34 | To document
 * 
 */
void unk_9c04c(struct CutsceneOam* pOam)
{
    pOam->timer++;
    if (pOam->timer == 40)
    {
        pOam->timer = 0;
        if (pOam->xPosition > 0)
            pOam->xPosition--;
    }

    WRITE_16(REG_BG2HOFS, pOam->xPosition);
}

/**
 * @brief 9c080 | 34 | Sets up a restricted lab detaching OAM with a parameter
 * 
 */
u8 unk_9c080(u8 type, s16 xPosition, s16 yPosition, u16 param_4)
{
    u8 slot;

    slot = CutsceneRestrictedLabDetachingSetupOam(type, xPosition, yPosition);
    CUTSCENE_OAM_DATA.oam[slot].unk_C = param_4;
    return slot;
}

/**
 * @brief 9c0b4 | 3c | Sets up a restricted lab detaching OAM with two parameters
 * 
 */
u8 unk_9c0b4(u8 type, s16 xPosition, s16 yPosition, u16 param_4, u16 param_5)
{
    u8 slot;

    slot = CutsceneRestrictedLabDetachingSetupOam(type, xPosition, yPosition);
    CUTSCENE_OAM_DATA.oam[slot].unk_A = param_5;
    CUTSCENE_OAM_DATA.oam[slot].unk_C = param_4;
    return slot;
}

/**
 * @brief 9c0f0 | 48 | Gets the position of a restricted lab detaching OAM by type
 * 
 */
void CutsceneRestrictedLabDetachingGetPositionOfOamByType(u8 type, s16* pXPosition, s16* pYPosition)
{
    u8 slot;

    for (slot = 0; slot < ARRAY_SIZE(CUTSCENE_OAM_DATA.oam); slot++)
    {
        if (CUTSCENE_OAM_DATA.oam[slot].type == type)
        {
            *pXPosition = CUTSCENE_OAM_DATA.oam[slot].xPosition;
            *pYPosition = CUTSCENE_OAM_DATA.oam[slot].yPosition;
            return;
        }
    }

    *pXPosition = 300;
    *pYPosition = 200;
}

/**
 * @brief 9c138 | 84 | V-blank for the restricted lab detaching cutscene
 * 
 */
void CutsceneRestrictedLabDetachingVblank(void)
{
    DMA3_COPY_32(gOamData, OAM_BASE, OAM_SIZE / 4);
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_Evb, gWrittenToBldalpha_Eva));
    WRITE_16(REG_BLDY, gWrittenToBldy);

    if (CUTSCENE_OAM_DATA.unk_A == 1)
    {
        CUTSCENE_OAM_DATA.unk_A = 0;
        DMA3_COPY_32(&((const u16*)0x868101c)[CUTSCENE_OAM_DATA.unk_C * 16], PALRAM_BASE + 0x120, PAL_ROW_SIZE / 4);
    }
}

/**
 * @brief 9c1bc | c | V-blank that only updates the audio
 * 
 */
void unk_9c1bc(void)
{
    UpdateAudio();
}
