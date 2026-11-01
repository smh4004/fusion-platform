#include "save_file.h"
#include "globals.h"
#include "macros.h"
#include "dma.h"
#include "event.h"
#include "minimap.h"
#include "constants/connection.h"
#include "constants/event.h"
#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/sprite.h"
#include "structs/scroll.h"
#include "structs/block.h"
#include "structs/connection.h"
#include "structs/event.h"
#include "structs/menus/boot_debug.h"
#include "structs/minimap.h"
#include "callbacks.h"
#include "audio/track_internal.h"
#include "constants/samus.h"
#include "structs/samus.h"
#include "sram_misc.h"
#include "sram/sram.h"

#include "data/generic_data.h"
#include "data/sram_pointers.h"
#include "data/menus/pause_screen_misc_data.h"

#include "structs/save_file.h"

// Defined in connection.c's data
extern const struct Door* sAreaDoorPointers[AREA_END];

/**
 * @brief 7eea4 | 18 | Reads all of flash sram into ewram and ram
 * 
 */
void Sram_ReadAll(void)
{
    Sram_ReadHeader();
    unk_7fb84();
    SramRead_MostRecentSaveFile();
    SramRead_Language();
}

/**
 * @brief 7eebc | 6c | Writes the sram header
 * 
 */
void Sram_WriteHeader(void)
{
    s32 i;
    u32* ptr;
    s32 checksum;
    struct SramHeader* pHeader;

    pHeader = &gSram.header;
    pHeader->unk_8 = 0x30;
    pHeader->unk_9 = 0x31;
    pHeader->unk_A = gSramHeaderUnk_3000010;
    pHeader->unk_B = 2;

    for (i = 0; i < SRAM_VERSION_TEXT_SIZE; i++)
        pHeader->versionText[i] = sSramHeaderVersionText[i];

    pHeader->checksum = 0;
    pHeader->notChecksum = -1;

    ptr = (u32*)&gSram.header;
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SramHeader, 4, u32) - 1; i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pHeader->checksum = checksum;
    pHeader->notChecksum = ~checksum;
    unk_c98();
}

// 0x0807EF28
NAKED_FUNCTION
void Sram_ReadHeader(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sb\n\
	mov r6, r8\n\
	push {r6, r7}\n\
	sub sp, #4\n\
	bl SramTestFlash\n\
	ldr r0, _0807EFA0 @ =0x03000B8E\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807EF42\n\
	bl ReadSramHeaderToEwram\n\
_0807EF42:\n\
	movs r0, #0\n\
	bl Sram_VerifyHeader\n\
	adds r6, r0, #0\n\
	movs r0, #1\n\
	bl Sram_VerifyHeader\n\
	mov sb, r0\n\
	movs r0, #2\n\
	bl Sram_VerifyHeader\n\
	mov r8, r0\n\
	cmp r6, #0\n\
	beq _0807F00C\n\
	mov r0, sp\n\
	ldr r1, _0807EFA4 @ =0x0000FFFF\n\
	adds r2, r1, #0\n\
	strh r2, [r0]\n\
	ldr r4, _0807EFA8 @ =0x040000D4\n\
	str r0, [r4]\n\
	ldr r5, _0807EFAC @ =0x02038000\n\
	str r5, [r4, #4]\n\
	ldr r1, _0807EFB0 @ =0x81000040\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _0807EFD8\n\
	mov r0, sp\n\
	strh r2, [r0]\n\
	str r0, [r4]\n\
	ldr r0, _0807EFB4 @ =0x0203F100\n\
	str r0, [r4, #4]\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	beq _0807EFBC\n\
	mov r0, sp\n\
	strh r2, [r0]\n\
	str r0, [r4]\n\
	ldr r0, _0807EFB8 @ =0x02038080\n\
	str r0, [r4, #4]\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	b _0807F034\n\
	.align 2, 0\n\
_0807EFA0: .4byte 0x03000B8E\n\
_0807EFA4: .4byte 0x0000FFFF\n\
_0807EFA8: .4byte 0x040000D4\n\
_0807EFAC: .4byte 0x02038000\n\
_0807EFB0: .4byte 0x81000040\n\
_0807EFB4: .4byte 0x0203F100\n\
_0807EFB8: .4byte 0x02038080\n\
_0807EFBC:\n\
	ldr r0, _0807EFD0 @ =0x02038080\n\
	str r0, [r4]\n\
	str r5, [r4, #4]\n\
	ldr r0, _0807EFD4 @ =0x80000040\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r6, #0\n\
	bl unk_c98\n\
	b _0807F034\n\
	.align 2, 0\n\
_0807EFD0: .4byte 0x02038080\n\
_0807EFD4: .4byte 0x80000040\n\
_0807EFD8:\n\
	ldr r0, _0807F000 @ =0x0203F100\n\
	str r0, [r4]\n\
	str r5, [r4, #4]\n\
	ldr r7, _0807F004 @ =0x80000040\n\
	str r7, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r6, #0\n\
	bl unk_c98\n\
	mov r1, sb\n\
	cmp r1, #0\n\
	beq _0807F034\n\
	str r5, [r4]\n\
	ldr r0, _0807F008 @ =0x02038080\n\
	str r0, [r4, #4]\n\
	str r7, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl unk_cd8\n\
	b _0807F034\n\
	.align 2, 0\n\
_0807F000: .4byte 0x0203F100\n\
_0807F004: .4byte 0x80000040\n\
_0807F008: .4byte 0x02038080\n\
_0807F00C:\n\
	ldr r4, _0807F040 @ =0x040000D4\n\
	ldr r7, _0807F044 @ =0x02038000\n\
	str r7, [r4]\n\
	ldr r0, _0807F048 @ =0x02038080\n\
	str r0, [r4, #4]\n\
	ldr r5, _0807F04C @ =0x80000040\n\
	str r5, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl unk_cd8\n\
	mov r0, r8\n\
	cmp r0, #0\n\
	beq _0807F034\n\
	str r7, [r4]\n\
	ldr r0, _0807F050 @ =0x0203F100\n\
	str r0, [r4, #4]\n\
	str r5, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	bl unk_cf0\n\
_0807F034:\n\
	cmp r6, #0\n\
	bne _0807F058\n\
	ldr r0, _0807F054 @ =0x03000010\n\
	strb r6, [r0]\n\
	b _0807F066\n\
	.align 2, 0\n\
_0807F040: .4byte 0x040000D4\n\
_0807F044: .4byte 0x02038000\n\
_0807F048: .4byte 0x02038080\n\
_0807F04C: .4byte 0x80000040\n\
_0807F050: .4byte 0x0203F100\n\
_0807F054: .4byte 0x03000010\n\
_0807F058:\n\
	bl EraseSram\n\
	ldr r1, _0807F074 @ =0x03000010\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	bl Sram_WriteHeader\n\
_0807F066:\n\
	add sp, #4\n\
	pop {r3, r4}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807F074: .4byte 0x03000010\n\
    .syntax divided\n");
}

// 0x0807F078
NAKED_FUNCTION
u32 Sram_VerifyHeader(u8 header)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	movs r4, #0\n\
	ldr r1, _0807F0EC @ =0x0203F100\n\
	cmp r0, #2\n\
	beq _0807F08E\n\
	ldr r1, _0807F0F0 @ =0x02038000\n\
	cmp r0, #1\n\
	bne _0807F08E\n\
	adds r1, #0x80\n\
_0807F08E:\n\
	movs r2, #0\n\
	ldr r7, [r1]\n\
	adds r5, r1, #0\n\
	adds r5, #0xc\n\
	ldr r0, [r1, #4]\n\
	mov ip, r0\n\
	movs r3, #7\n\
_0807F09C:\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	ldm r1!, {r0}\n\
	adds r2, r2, r0\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0807F09C\n\
	cmp r7, r2\n\
	beq _0807F0BA\n\
	movs r0, #1\n\
	orrs r4, r0\n\
_0807F0BA:\n\
	movs r3, #0\n\
	adds r2, r5, #0\n\
	ldr r6, _0807F0F4 @ =0x08582248\n\
	movs r5, #2\n\
_0807F0C2:\n\
	adds r0, r2, r3\n\
	adds r1, r3, r6\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0807F0D0\n\
	orrs r4, r5\n\
_0807F0D0:\n\
	adds r3, #1\n\
	cmp r3, #0x13\n\
	ble _0807F0C2\n\
	mov r1, ip\n\
	mvns r0, r1\n\
	cmp r7, r0\n\
	beq _0807F0E2\n\
	movs r0, #4\n\
	orrs r4, r0\n\
_0807F0E2:\n\
	adds r0, r4, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807F0EC: .4byte 0x0203F100\n\
_0807F0F0: .4byte 0x02038000\n\
_0807F0F4: .4byte 0x08582248\n\
    .syntax divided\n");
}

/**
 * @brief 7f0f8 | 138 | Saves the game after the intro, split in several stages
 * 
 */
void Sram_ProcessIntroSave(u8 stage)
{
    if (gSaveFilesInfo[gMostRecentSaveFile].hasSaved)
    {
        switch (stage)
        {
            case 0:
                gDisableSoftReset = TRUE;
                gGameCompletion.introPlayed = TRUE;
                gSaveFilesInfo[gMostRecentSaveFile].introPlayed = TRUE;
                break;

            case 1:
            case 2:
                break;

            case 3:
                DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile],
                    (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile], sizeof(struct SaveFile), 16);

            default:
                gDisableSoftReset = FALSE;
        }
    }
    else
    {
        switch (stage)
        {
            case 0:
                gDisableSoftReset = TRUE;
                gGameCompletion.introPlayed = TRUE;
                gSaveFilesInfo[gMostRecentSaveFile].introPlayed = TRUE;
                gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;
                BitFill(3, 0, (void*)sSaveDataEwramPointers[gMostRecentSaveFile], 0x300, 16);
                break;

            case 1:
                Sram_WriteHeaderAndGameInfo();
                break;

            case 2:
                WriteMostRecentFileToSram();
                break;

            case 3:
                DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile],
                    (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
                gDisableSoftReset = FALSE;
                break;

            default:
                gDisableSoftReset = FALSE;
        }
    }
}

/**
 * @brief 7f230 | 84 | Writes the header and game completion of the current save file
 * 
 */
void Sram_WriteHeaderAndGameInfo(void)
{
    s32 i;
    u32* ptr;
    s32 checksum;
    struct SaveFile* pFile;

    pFile = (struct SaveFile*)sSaveDataEwramPointers[gMostRecentSaveFile];
    Sram_StringCopy_MetroidEpisode4A(pFile->MetroidEpisode4A_Text, sSramMetroidEpisodeText);

    pFile->checksum = 0;
    pFile->notChecksum = -1;
    pFile->gameCompletion.introPlayed = gGameCompletion.introPlayed;
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;

    Sram_StringCopy_SAVE_END(pFile->SAVE_END_Text, sSramSaveEndText);

    ptr = (u32*)sSaveDataEwramPointers[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32) - 1; i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 7f2b4 | 90 | Saves the game after the ending, split in several stages
 * 
 */
void Sram_ProcessEndingSave(u8 stage)
{
    switch (stage)
    {
        case 0:
            ReadMostRecentFileToEwram();
            break;

        case 1:
            gGameCompletion.completedGame = stage;
            Sram_CopyGameCompletion();
            break;

        case 2:
            WriteMostRecentFileToSram();
            gSaveFilesInfo[gMostRecentSaveFile].completedGame = gGameCompletion.completedGame;
            break;

        case 3:
            DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile],
                (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            break;
    }
}

/**
 * @brief 7f344 | 68 | Copies the game completion flag to the current save file and updates its checksum
 * 
 */
void Sram_CopyGameCompletion(void)
{
    s32 i;
    u32* ptr;
    s32 checksum;
    struct SaveFile* pFile;

    pFile = (struct SaveFile*)sSaveDataEwramPointers[gMostRecentSaveFile];
    pFile->checksum = 0;
    pFile->notChecksum = -1;
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;

    ptr = (u32*)sSaveDataEwramPointers[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32) - 1; i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 7f3ac | a4 | Saves the game, split in several stages
 * 
 */
void Sram_QuickSave(u8 stage)
{
    switch (stage)
    {
        case 0:
            gDisableSoftReset = TRUE;
            gHasSaved = TRUE;
            WriteMostRecentFileBackupToSram();
            break;

        case 1:
            SramWrite_WorldData();
            SramWrite_ToEwram();
            break;

        case 2:
            WriteMostRecentFileToSram();
            gSaveFilesInfo[gMostRecentSaveFile].exists = TRUE;
            break;

        case 3:
            DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile],
                (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile], sizeof(struct SaveFile), 16);

        default:
            gDisableSoftReset = FALSE;
    }
}

/**
 * @brief 7f450 | 370 | Writes the current game state to the current save file in ewram
 * 
 */
void SramWrite_ToEwram(void)
{
    s32 i;
    u32* ptr;
    s32 checksum;
    struct SaveFile* pFile;
    struct SaveMusicInfo musicInfo;

    musicInfo.musicTrack = gMusicInfo.musicTrack;
    musicInfo.unk_2 = gMusicInfo.unk_1E;
    musicInfo.unk_4 = gMusicInfo.unk_20;
    musicInfo.priority = gMusicInfo.priority;
    musicInfo.unk_6 = gMusicInfo.unk_2;

    pFile = (struct SaveFile*)sSaveDataEwramPointers[gMostRecentSaveFile];
    Sram_StringCopy_MetroidEpisode4A(pFile->MetroidEpisode4A_Text, sSramMetroidEpisodeText);

    pFile->checksum = 0;
    pFile->notChecksum = -1;

    pFile->gameCompletion = gGameCompletion;
    pFile->hasSaved = gHasSaved;
    pFile->currentArea = gCurrentArea;
    pFile->currentRoom = gCurrentRoom;
    pFile->lastDoorUsed = gLastDoorUsed;
    pFile->abilityCount = gAbilityCount;
    pFile->eventCounter = gEventCounter;
    pFile->previousNavigationConversation = gPreviousNavigationConversation;
    pFile->previousCutscene = gPreviousCutscene;
    pFile->mapX = gMinimapX;
    pFile->mapY = gMinimapY;
    pFile->soundEventCounter = gSoundEventCounter;
    pFile->previousSoundEvent = gPreviousSoundEvent;
    pFile->unk_2A = gUnk_300004d;
    pFile->securityHatchLevelBackup = gSecurityHatchLevelBackup;

    pFile->camera = gCamera;
    pFile->bg0XPosition = gBg0XPosition;
    pFile->bg0YPosition = gBg0YPosition;
    pFile->bg1XPosition = gBg1XPosition;
    pFile->bg1YPosition = gBg1YPosition;
    pFile->bg2XPosition = gBg2XPosition;
    pFile->bg2YPosition = gBg2YPosition;
    pFile->bg3XPosition = gBg3XPosition;
    pFile->bg3YPosition = gBg3YPosition;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        pFile->numberOfNeverReformBlocksBroken[i] = gNumberOfNeverReformBlocks[i];

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        pFile->numberOfItemsCollected[i] = gNumberOfCollectedTanks[i];

    pFile->samusData = gSamusData;
    pFile->samusAnimationInfo = gSamusAnimationInfo;
    pFile->samusEcho = gSamusEcho;
    pFile->environmentalEffects[0] = gSamusEnvironmentalEffects[0];
    pFile->environmentalEffects[1] = gSamusEnvironmentalEffects[1];
    pFile->equipment = gEquipment;
    pFile->preventMovementTimer = gPreventMovementTimer;
    pFile->disableDrawingSamusAndScrolling = gDisableDrawingSamusAndScrollingFlag;

    pFile->atmosphericStabilizersOnline = gAtmosphericStabilizersOnline;
    pFile->missileGeronsDestroyed = gMissileGeronsDestroyed;
    pFile->superMissileGeronsDestroyed = gSuperMissileGeronsDestroyed;
    pFile->powerBombGeronsDestroyed = gPowerBombGeronsDestroyed;
    pFile->gadorasDestroyed = gGadorasDestroyed;
    pFile->missileHatchDestroyed = gMissileHatchDestroyed;
    pFile->waterLowered = gWaterLowered;
    pFile->inGameTimer = gInGameTimer;
    pFile->musicInfo = musicInfo;

    Sram_StringCopy_SAVE_END(pFile->SAVE_END_Text, sSramSaveEndText);

    ptr = (u32*)sSaveDataEwramPointers[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32) - 1; i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 7f7c0 | 2e8 | Loads the current save file in ewram into the game state
 * 
 */
void SramRead_FromEwram(void)
{
    s32 i;
    struct SaveFile* pFile;
    struct SaveMusicInfo musicInfo;

    pFile = (struct SaveFile*)sSaveDataEwramPointers[gMostRecentSaveFile];

    gGameCompletion = pFile->gameCompletion;
    gHasSaved = pFile->hasSaved;
    gCurrentArea = pFile->currentArea;
    gCurrentRoom = pFile->currentRoom;
    gLastDoorUsed = pFile->lastDoorUsed;
    gAbilityCount = pFile->abilityCount;
    gEventCounter = pFile->eventCounter;
    gPreviousNavigationConversation = pFile->previousNavigationConversation;
    gPreviousCutscene = pFile->previousCutscene;
    gMinimapX = pFile->mapX;
    gMinimapY = pFile->mapY;
    gSoundEventCounter = pFile->soundEventCounter;
    gPreviousSoundEvent = pFile->previousSoundEvent;
    gUnk_300004d = pFile->unk_2A;
    gSecurityHatchLevelBackup = pFile->securityHatchLevelBackup;

    gCamera = pFile->camera;
    gBg0XPosition = pFile->bg0XPosition;
    gBg0YPosition = pFile->bg0YPosition;
    gBg1XPosition = pFile->bg1XPosition;
    gBg1YPosition = pFile->bg1YPosition;
    gBg2XPosition = pFile->bg2XPosition;
    gBg2YPosition = pFile->bg2YPosition;
    gBg3XPosition = pFile->bg3XPosition;
    gBg3YPosition = pFile->bg3YPosition;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        gNumberOfNeverReformBlocks[i] = pFile->numberOfNeverReformBlocksBroken[i];

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        gNumberOfCollectedTanks[i] = pFile->numberOfItemsCollected[i];

    gSamusData = pFile->samusData;
    gSamusAnimationInfo = pFile->samusAnimationInfo;
    gSamusEcho = pFile->samusEcho;
    gSamusEnvironmentalEffects[0] = pFile->environmentalEffects[0];
    gSamusEnvironmentalEffects[1] = pFile->environmentalEffects[1];
    gEquipment = pFile->equipment;
    gPreventMovementTimer = pFile->preventMovementTimer;
    gDisableDrawingSamusAndScrollingFlag = pFile->disableDrawingSamusAndScrolling;

    gAtmosphericStabilizersOnline = pFile->atmosphericStabilizersOnline;
    gMissileGeronsDestroyed = pFile->missileGeronsDestroyed;
    gSuperMissileGeronsDestroyed = pFile->superMissileGeronsDestroyed;
    gPowerBombGeronsDestroyed = pFile->powerBombGeronsDestroyed;
    gGadorasDestroyed = pFile->gadorasDestroyed;
    gMissileHatchDestroyed = pFile->missileHatchDestroyed;
    gWaterLowered = pFile->waterLowered;
    gInGameTimer = pFile->inGameTimer;
    musicInfo = pFile->musicInfo;

    gMusicInfo.musicTrack = musicInfo.musicTrack;
    gMusicInfo.unk_1E = musicInfo.unk_2;
    gMusicInfo.unk_20 = musicInfo.unk_4;
    gMusicInfo.priority = musicInfo.priority;
    gMusicInfo.unk_2 = musicInfo.unk_6;
}

/**
 * @brief 7faa8 | 1c | Copies the MetroidEpisode4A text
 * 
 */
void Sram_StringCopy_MetroidEpisode4A(u8* dst, const u8* src)
{
    s32 i;

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
        dst[i] = src[i];
}

/**
 * @brief 7fac4 | 1c | Copies the SAVE_END text
 * 
 */
void Sram_StringCopy_SAVE_END(u8* dst, const u8* src)
{
    s32 i;

    for (i = 0; i < SRAM_END_TEXT_SIZE; i++)
        dst[i] = src[i];
}

/**
 * @brief 7fae0 | 68 | Tests that flash sram can be written to
 * 
 */
void SramTestFlash(void)
{
    u32 result;
    s32 i;
    u8 buffer[SRAM_TEXT_SIZE];

    result = 0;
    gSramCorruptFlag = result;

    result |= SramWriteChecked((u8*)sSramTestFlashText, (u8*)SRAM_BASE + 0x7FE0, SRAM_TEXT_SIZE) != NULL;
    SramWriteUnchecked((u8*)SRAM_BASE + 0x7FE0, buffer, SRAM_TEXT_SIZE);

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
        buffer[i]++;

    if (SramWriteChecked(buffer, (u8*)SRAM_BASE + 0x7FE0, SRAM_TEXT_SIZE) != NULL)
        result |= 2;

    gSramCorruptFlag = result != 0;
}

/**
 * @brief 7fb48 | 3c | Backs up the current save file (unused)
 * 
 */
void Sram_BackupCurrentFile_Unused(void)
{
    DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile], (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile],
        sizeof(struct SaveFile), 16);
    WriteMostRecentFileBackupToSram();
}

// 0x0807FB84
NAKED_FUNCTION
void unk_7fb84(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #0x1c\n\
	add r0, sp, #4\n\
	movs r1, #0\n\
	movs r2, #0x14\n\
	bl memset\n\
	ldr r2, _0807FC1C @ =0x03000B94\n\
	movs r5, #2\n\
_0807FB9E:\n\
	adds r1, r2, #0\n\
	add r0, sp, #4\n\
	ldm r0!, {r3, r4, r6}\n\
	stm r1!, {r3, r4, r6}\n\
	ldm r0!, {r3, r4}\n\
	stm r1!, {r3, r4}\n\
	adds r2, #0x14\n\
	subs r5, #1\n\
	cmp r5, #0\n\
	bge _0807FB9E\n\
	ldr r4, _0807FC20 @ =0x03000B8D\n\
	movs r1, #0\n\
	strb r1, [r4]\n\
	ldr r0, _0807FC24 @ =gIsLoadingFile\n\
	strb r1, [r0]\n\
	ldr r0, _0807FC28 @ =0x03000B8E\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807FBC8\n\
	bl ReadAllFilesToEwram\n\
_0807FBC8:\n\
	movs r5, #0\n\
	adds r7, r4, #0\n\
	movs r6, #0x10\n\
	ldr r0, _0807FC1C @ =0x03000B94\n\
	str r0, [sp, #0x18]\n\
	ldr r1, _0807FC2C @ =0x0858225C\n\
	mov sl, r1\n\
	ldr r3, _0807FC30 @ =0x0000FFFF\n\
	mov sb, r3\n\
	movs r4, #0x90\n\
	lsls r4, r4, #5\n\
	mov r8, r4\n\
_0807FBE0:\n\
	strb r5, [r7]\n\
	bl unk_7fd10\n\
	ldrb r0, [r7]\n\
	lsls r2, r0, #2\n\
	adds r0, r2, r0\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807FC1C @ =0x03000B94\n\
	adds r0, r0, r1\n\
	ldrb r4, [r0, #1]\n\
	cmp r4, #0\n\
	bne _0807FC38\n\
	mov r3, sl\n\
	adds r0, r2, r3\n\
	ldr r1, [r0]\n\
	ldr r4, _0807FC34 @ =0x08582268\n\
	adds r0, r2, r4\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	bl DmaTransfer\n\
	bl WriteMostRecentFileBackupToSram\n\
	movs r0, #1\n\
	ldr r1, [sp, #0x18]\n\
	strb r0, [r1]\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FC1C: .4byte 0x03000B94\n\
_0807FC20: .4byte 0x03000B8D\n\
_0807FC24: .4byte gIsLoadingFile\n\
_0807FC28: .4byte 0x03000B8E\n\
_0807FC2C: .4byte 0x0858225C\n\
_0807FC30: .4byte 0x0000FFFF\n\
_0807FC34: .4byte 0x08582268\n\
_0807FC38:\n\
	cmp r4, #1\n\
	bne _0807FC60\n\
	ldr r3, _0807FC5C @ =0x08582268\n\
	adds r0, r2, r3\n\
	ldr r1, [r0]\n\
	mov r3, sl\n\
	adds r0, r2, r3\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	bl DmaTransfer\n\
	ldr r0, [sp, #0x18]\n\
	strb r4, [r0]\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FC5C: .4byte 0x08582268\n\
_0807FC60:\n\
	cmp r4, #2\n\
	bne _0807FC94\n\
	mov r1, sl\n\
	adds r0, r2, r1\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #2\n\
	ldr r3, _0807FC90 @ =0x08582268\n\
	adds r0, r0, r3\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FC90: .4byte 0x08582268\n\
_0807FC94:\n\
	cmp r4, #3\n\
	bne _0807FCE4\n\
	mov r4, sl\n\
	adds r0, r2, r4\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	bl WriteMostRecentFileToSram\n\
	ldrb r0, [r7]\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807FCDC @ =0x08582268\n\
	adds r0, r0, r1\n\
	ldr r2, [r0]\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	mov r1, sb\n\
	mov r3, r8\n\
	bl BitFill\n\
	bl WriteMostRecentFileBackupToSram\n\
	ldrb r1, [r7]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	ldr r3, _0807FCE0 @ =0x03000B94\n\
	adds r0, r0, r3\n\
	movs r1, #0\n\
	strb r1, [r0, #1]\n\
	b _0807FCE6\n\
	.align 2, 0\n\
_0807FCDC: .4byte 0x08582268\n\
_0807FCE0: .4byte 0x03000B94\n\
_0807FCE4:\n\
	b _0807FCE4\n\
_0807FCE6:\n\
	ldr r4, [sp, #0x18]\n\
	adds r4, #0x14\n\
	str r4, [sp, #0x18]\n\
	adds r5, #1\n\
	cmp r5, #2\n\
	bgt _0807FCF4\n\
	b _0807FBE0\n\
_0807FCF4:\n\
	movs r1, #0\n\
	ldr r0, _0807FD0C @ =0x03000B8D\n\
	strb r1, [r0]\n\
	add sp, #0x1c\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807FD0C: .4byte 0x03000B8D\n\
    .syntax divided\n");
}

// 0x0807FD10
NAKED_FUNCTION
void unk_7fd10(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r0, #0\n\
	bl unk_7fdb0\n\
	adds r4, r0, #0\n\
	movs r0, #1\n\
	bl unk_7fdb0\n\
	adds r2, r0, #0\n\
	cmp r4, #0\n\
	bne _0807FD40\n\
	ldr r2, _0807FD38 @ =0x03000B94\n\
	ldr r0, _0807FD3C @ =0x03000B8D\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	strb r4, [r0, #1]\n\
	b _0807FDAA\n\
	.align 2, 0\n\
_0807FD38: .4byte 0x03000B94\n\
_0807FD3C: .4byte 0x03000B8D\n\
_0807FD40:\n\
	cmp r4, #1\n\
	bne _0807FD6C\n\
	ldr r5, _0807FD64 @ =0x03000B94\n\
	ldr r3, _0807FD68 @ =0x03000B8D\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, #2\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	strb r4, [r0, #1]\n\
	cmp r2, #0\n\
	beq _0807FDAA\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r5\n\
	b _0807FDA6\n\
	.align 2, 0\n\
_0807FD64: .4byte 0x03000B94\n\
_0807FD68: .4byte 0x03000B8D\n\
_0807FD6C:\n\
	ldr r4, _0807FD90 @ =0x03000B94\n\
	ldr r3, _0807FD94 @ =0x03000B8D\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #3\n\
	strb r0, [r1, #1]\n\
	cmp r2, #0\n\
	bne _0807FD98\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #1\n\
	b _0807FDA8\n\
	.align 2, 0\n\
_0807FD90: .4byte 0x03000B94\n\
_0807FD94: .4byte 0x03000B8D\n\
_0807FD98:\n\
	cmp r2, #1\n\
	bne _0807FDAA\n\
	ldrb r0, [r3]\n\
	lsls r1, r0, #2\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
_0807FDA6:\n\
	movs r0, #2\n\
_0807FDA8:\n\
	strb r0, [r1, #1]\n\
_0807FDAA:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0807FDB0
NAKED_FUNCTION
u32 unk_7fdb0(u8 useBackup)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	movs r5, #0\n\
	movs r7, #0\n\
	cmp r0, #0\n\
	bne _0807FDC8\n\
	ldr r1, _0807FDC4 @ =0x0858225C\n\
	b _0807FDCA\n\
	.align 2, 0\n\
_0807FDC4: .4byte 0x0858225C\n\
_0807FDC8:\n\
	ldr r1, _0807FE50 @ =0x08582268\n\
_0807FDCA:\n\
	ldr r0, _0807FE54 @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r4, [r0]\n\
	adds r3, r4, #0\n\
	movs r1, #0\n\
	ldr r6, [r4, #0x10]\n\
	movs r2, #0x8f\n\
_0807FDDC:\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	ldm r3!, {r0}\n\
	adds r1, r1, r0\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bge _0807FDDC\n\
	cmp r6, r1\n\
	bne _0807FE0E\n\
	ldr r0, [r4, #0x14]\n\
	mvns r0, r0\n\
	cmp r6, r0\n\
	beq _0807FE12\n\
_0807FE0E:\n\
	movs r0, #1\n\
	orrs r5, r0\n\
_0807FE12:\n\
	movs r2, #0\n\
	ldr r6, _0807FE58 @ =0x08582200\n\
	movs r3, #1\n\
_0807FE18:\n\
	adds r0, r2, r6\n\
	adds r1, r4, r2\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0807FE26\n\
	orrs r7, r3\n\
_0807FE26:\n\
	adds r2, #1\n\
	cmp r2, #0xf\n\
	ble _0807FE18\n\
	adds r0, r7, #0\n\
	adds r5, r5, r0\n\
	cmp r5, #1\n\
	ble _0807FE46\n\
	ldr r1, _0807FE5C @ =0x0000FFFF\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	adds r2, r4, #0\n\
	bl BitFill\n\
_0807FE46:\n\
	adds r0, r5, #0\n\
	add sp, #4\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807FE50: .4byte 0x08582268\n\
_0807FE54: .4byte 0x03000B8D\n\
_0807FE58: .4byte 0x08582200\n\
_0807FE5C: .4byte 0x0000FFFF\n\
    .syntax divided\n");
}

/**
 * @brief 7fe60 | 34 | Loads the current save file if a file is being loaded
 * 
 */
void SramLoad_CurrentSave(void)
{
    if (gIsLoadingFile == TRUE)
    {
        SramRead_FromEwram();
        SramRead_WorldData();
        gSamusData.pose = SPOSE_LOADING_SAVE;
        gSamusData.animationDurationCounter = 0;
        gSamusData.currentAnimationFrame = 0;
    }
}

/**
 * @brief 7fe94 | 10 | Loads the current save file (unused)
 * 
 */
void SramLoad_CurrentSave_Unused(void)
{
    SramRead_FromEwram();
    SramRead_WorldData();
}

/**
 * @brief 7fea4 | d8 | Writes the world data (minimap, broken blocks and collected tanks) to the current save file
 * 
 */
void SramWrite_WorldData(void)
{
    u8* dst;
    s32 offset;
    s32 i;
    s32 size;
    s32 area;

    dst = (u8*)sUnk_582274[gMostRecentSaveFile];
    DmaTransfer(3, gVisitedMinimapTiles, dst, AREA_NORMAL_COUNT * MINIMAP_SIZE / 8, 16);
    offset = AREA_NORMAL_COUNT * MINIMAP_SIZE / 8;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        size = gNumberOfNeverReformBlocks[i] * 3;
        if (size & 3)
        {
            size &= 0xFFFC;
            size += 4;
        }

        if (size != 0)
        {
            area = i;
            if (i != 0)
                area = i + 1;

            DmaTransfer(3, (u8*)gNeverReformBlocks + area * NEVER_REFORM_BLOCKS_SIZE, dst + offset, size, 16);
            offset += size;
        }
    }

    offset = 0xC80;
    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        size = gNumberOfCollectedTanks[i] * 4;
        if (size != 0)
        {
            area = i;
            if (area != 0)
                area = i + 1;

            DmaTransfer(3, (u8*)gCollectedTanks + area * COLLECTED_TANKS_SIZE, dst + offset, size, 16);
            offset += size;
        }
    }
}

/**
 * @brief 7ff7c | ec | Reads the world data (minimap, broken blocks and collected tanks) from the current save file
 * 
 */
void SramRead_WorldData(void)
{
    u8* src;
    s32 offset;
    s32 i;
    s32 size;
    s32 area;

    src = (u8*)sUnk_582274[gMostRecentSaveFile];
    DmaTransfer(3, src, gVisitedMinimapTiles, AREA_NORMAL_COUNT * MINIMAP_SIZE / 8, 16);
    BitFill(3, USHORT_MAX, gNeverReformBlocks, 0x1B00, 16);
    offset = AREA_NORMAL_COUNT * MINIMAP_SIZE / 8;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        size = gNumberOfNeverReformBlocks[i] * 3;
        if (size & 3)
        {
            size &= 0xFFFC;
            size += 4;
        }

        if (size != 0)
        {
            area = i;
            if (i != 0)
                area = i + 1;

            DmaTransfer(3, src + offset, (u8*)gNeverReformBlocks + area * NEVER_REFORM_BLOCKS_SIZE, size, 16);
            offset += size;
        }
    }

    offset = 0xC80;
    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        size = gNumberOfCollectedTanks[i] * 4;
        if (size != 0)
        {
            area = i;
            if (area != 0)
                area = i + 1;

            DmaTransfer(3, src + offset, (u8*)gCollectedTanks + area * COLLECTED_TANKS_SIZE, size, 16);
            offset += size;
        }
    }
}

// 0x08080068
NAKED_FUNCTION
void SramWrite_MostRecentSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r5, _080800E4 @ =0x0203F000\n\
	adds r3, r5, #0\n\
	movs r1, #0\n\
	movs r0, #0x1e\n\
	strb r0, [r5]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
	strh r1, [r5, #2]\n\
	ldr r0, _080800E8 @ =0x0000FFFF\n\
	strh r0, [r5, #4]\n\
	ldr r0, _080800EC @ =0x03000B8D\n\
	ldrb r0, [r0]\n\
	strb r0, [r5, #0x16]\n\
	ldr r2, _080800F0 @ =0x08582288\n\
	adds r1, r5, #6\n\
	movs r4, #0xf\n\
_0808008C:\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	ldrb r0, [r2, #0x10]\n\
	strb r0, [r1, #0x11]\n\
	adds r2, #1\n\
	adds r1, #1\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _0808008C\n\
	movs r1, #0\n\
	movs r4, #7\n\
_080800A2:\n\
	ldrh r0, [r3]\n\
	adds r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r2, [r3]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r3, #2\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _080800A2\n\
	strh r1, [r5, #2]\n\
	ldr r2, _080800E8 @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	subs r0, r0, r1\n\
	strh r0, [r5, #4]\n\
	bl unk_dd4\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080800E4: .4byte 0x0203F000\n\
_080800E8: .4byte 0x0000FFFF\n\
_080800EC: .4byte 0x03000B8D\n\
_080800F0: .4byte 0x08582288\n\
    .syntax divided\n");
}

// 0x080800F4
NAKED_FUNCTION
void SramRead_MostRecentSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	ldr r0, _08080194 @ =0x0203F000\n\
	mov ip, r0\n\
	ldrb r0, [r0]\n\
	movs r1, #0x1e\n\
	eors r0, r1\n\
	rsbs r1, r0, #0\n\
	orrs r1, r0\n\
	lsrs r4, r1, #0x1f\n\
	ldr r6, _08080198 @ =0x03000B8D\n\
	cmp r4, #0\n\
	bne _080801A0\n\
	mov r1, ip\n\
	movs r3, #0\n\
	ldrh r5, [r1, #2]\n\
	movs r2, #7\n\
_08080116:\n\
	ldrh r0, [r1]\n\
	adds r0, r3, r0\n\
	lsls r0, r0, #0x10\n\
	adds r1, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r3, [r1]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	adds r1, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r3, [r1]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	adds r1, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r3, [r1]\n\
	adds r0, r0, r3\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	adds r1, #2\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	bge _08080116\n\
	cmp r5, r3\n\
	beq _0808014A\n\
	movs r4, #2\n\
_0808014A:\n\
	cmp r4, #0\n\
	bne _080801A0\n\
	movs r2, #0\n\
	ldr r0, _0808019C @ =0x08582288\n\
	mov r3, ip\n\
	ldrb r1, [r3, #6]\n\
	adds r3, r0, #0\n\
	ldrb r0, [r3]\n\
	cmp r1, r0\n\
	bne _080801A0\n\
_0808015E:\n\
	mov r0, ip\n\
	adds r0, #0x17\n\
	adds r0, r0, r2\n\
	adds r1, r3, #0\n\
	adds r1, #0x10\n\
	adds r1, r2, r1\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bne _080801A0\n\
	adds r2, #1\n\
	cmp r2, #0xf\n\
	bgt _0808018A\n\
	mov r0, ip\n\
	adds r0, #6\n\
	adds r0, r0, r2\n\
	adds r1, r2, r3\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0808015E\n\
	movs r4, #3\n\
_0808018A:\n\
	cmp r4, #0\n\
	bne _080801A0\n\
	mov r1, ip\n\
	ldrb r0, [r1, #0x16]\n\
	b _080801BA\n\
	.align 2, 0\n\
_08080194: .4byte 0x0203F000\n\
_08080198: .4byte 0x03000B8D\n\
_0808019C: .4byte 0x08582288\n\
_080801A0:\n\
	mov r1, sp\n\
	ldr r2, _080801C4 @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r1, _080801C8 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r1]\n\
	ldr r0, _080801CC @ =0x0203F000\n\
	str r0, [r1, #4]\n\
	ldr r0, _080801D0 @ =0x81000020\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #0\n\
_080801BA:\n\
	strb r0, [r6]\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080801C4: .4byte 0x0000FFFF\n\
_080801C8: .4byte 0x040000D4\n\
_080801CC: .4byte 0x0203F000\n\
_080801D0: .4byte 0x81000020\n\
    .syntax divided\n");
}

// 0x080801D4
NAKED_FUNCTION
void SramWrite_Language(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r5, _08080254 @ =0x0203F040\n\
	adds r3, r5, #0\n\
	movs r1, #0\n\
	movs r0, #0x1f\n\
	strb r0, [r5]\n\
	ldrb r0, [r5, #1]\n\
	adds r0, #1\n\
	strb r0, [r5, #1]\n\
	strh r1, [r5, #2]\n\
	ldr r0, _08080258 @ =0x0000FFFF\n\
	strh r0, [r5, #4]\n\
	ldr r0, _0808025C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	strb r0, [r5, #0x16]\n\
	ldr r2, _08080260 @ =0x085822A8\n\
	adds r1, r5, #6\n\
	movs r4, #0xf\n\
_080801F8:\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	ldrb r0, [r2, #0x10]\n\
	strb r0, [r1, #0x11]\n\
	adds r2, #1\n\
	adds r1, #1\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _080801F8\n\
	movs r1, #0\n\
	movs r4, #7\n\
_0808020E:\n\
	ldrh r0, [r3]\n\
	adds r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r2, [r3]\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #0x10\n\
	adds r3, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r3]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r3, #2\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _0808020E\n\
	strh r1, [r5, #2]\n\
	ldr r2, _08080258 @ =0x0000FFFF\n\
	adds r0, r2, #0\n\
	subs r0, r0, r1\n\
	strh r0, [r5, #4]\n\
	movs r0, #0\n\
	bl unk_dec\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08080254: .4byte 0x0203F040\n\
_08080258: .4byte 0x0000FFFF\n\
_0808025C: .4byte 0x03000011\n\
_08080260: .4byte 0x085822A8\n\
    .syntax divided\n");
}

// 0x08080264
NAKED_FUNCTION
void SramRead_Language(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	movs r0, #0\n\
	mov r8, r0\n\
	ldr r1, _080802E8 @ =0x08582280\n\
	mov sb, r1\n\
	ldr r6, _080802EC @ =0x040000D4\n\
	ldr r2, _080802F0 @ =0x81000020\n\
	mov sl, r2\n\
_0808027E:\n\
	mov r1, r8\n\
	lsls r0, r1, #2\n\
	add r0, sb\n\
	ldr r5, [r0]\n\
	adds r2, r5, #0\n\
	ldrb r1, [r5]\n\
	movs r0, #0x1f\n\
	eors r1, r0\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r4, r0, #0x1f\n\
	cmp r4, #0\n\
	bne _08080326\n\
	movs r1, #0\n\
	ldrh r7, [r5, #2]\n\
	movs r3, #7\n\
_0808029E:\n\
	ldrh r0, [r2]\n\
	adds r0, r1, r0\n\
	lsls r0, r0, #0x10\n\
	adds r2, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r2, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	adds r2, #2\n\
	lsrs r0, r0, #0x10\n\
	ldrh r1, [r2]\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r2, #2\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	bge _0808029E\n\
	cmp r7, r1\n\
	beq _080802D2\n\
	movs r4, #2\n\
_080802D2:\n\
	cmp r4, #0\n\
	bne _08080326\n\
	movs r3, #0\n\
	ldr r0, _080802F4 @ =0x085822A8\n\
	ldrb r1, [r5, #6]\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2]\n\
	cmp r1, r0\n\
	beq _080802FC\n\
	b _08080324\n\
	.align 2, 0\n\
_080802E8: .4byte 0x08582280\n\
_080802EC: .4byte 0x040000D4\n\
_080802F0: .4byte 0x81000020\n\
_080802F4: .4byte 0x085822A8\n\
_080802F8:\n\
	movs r4, #4\n\
	b _08080326\n\
_080802FC:\n\
	adds r0, r5, #0\n\
	adds r0, #0x17\n\
	adds r0, r0, r3\n\
	adds r1, r2, #0\n\
	adds r1, #0x10\n\
	adds r1, r3, r1\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bne _080802F8\n\
	adds r3, #1\n\
	cmp r3, #0xf\n\
	bgt _08080326\n\
	adds r0, r5, #6\n\
	adds r0, r0, r3\n\
	adds r1, r3, r2\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _080802FC\n\
_08080324:\n\
	movs r4, #3\n\
_08080326:\n\
	mov r1, r8\n\
	cmp r1, #0\n\
	bne _0808034C\n\
	cmp r4, #0\n\
	bne _08080384\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	str r0, [r6]\n\
	ldr r0, [r2, #4]\n\
	str r0, [r6, #4]\n\
	ldr r0, _08080348 @ =0x80000020\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
	movs r0, #1\n\
	bl unk_dec\n\
	b _08080390\n\
	.align 2, 0\n\
_08080348: .4byte 0x80000020\n\
_0808034C:\n\
	cmp r4, #0\n\
	beq _080803A0\n\
	mov r0, sp\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	str r0, [r6]\n\
	mov r2, sb\n\
	ldr r0, [r2]\n\
	str r0, [r6, #4]\n\
	mov r0, sl\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
	movs r0, #0\n\
	bl unk_dec\n\
	mov r0, sp\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	str r0, [r6]\n\
	mov r2, sb\n\
	ldr r0, [r2, #4]\n\
	str r0, [r6, #4]\n\
	mov r0, sl\n\
	str r0, [r6, #8]\n\
	ldr r0, [r6, #8]\n\
	movs r0, #1\n\
	bl unk_dec\n\
_08080384:\n\
	movs r1, #1\n\
	add r8, r1\n\
	mov r2, r8\n\
	cmp r2, #1\n\
	bgt _08080390\n\
	b _0808027E\n\
_08080390:\n\
	cmp r4, #0\n\
	bne _080803C8\n\
	ldr r1, _0808039C @ =0x03000011\n\
	ldrb r0, [r5, #0x16]\n\
	b _080803CC\n\
	.align 2, 0\n\
_0808039C: .4byte 0x03000011\n\
_080803A0:\n\
	ldr r1, _080803BC @ =0x040000D4\n\
	ldr r2, _080803C0 @ =0x08582280\n\
	ldr r0, [r2, #4]\n\
	str r0, [r1]\n\
	ldr r0, [r2]\n\
	str r0, [r1, #4]\n\
	ldr r0, _080803C4 @ =0x80000020\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #0\n\
	bl unk_dec\n\
	b _08080390\n\
	.align 2, 0\n\
_080803BC: .4byte 0x040000D4\n\
_080803C0: .4byte 0x08582280\n\
_080803C4: .4byte 0x80000020\n\
_080803C8:\n\
	ldr r1, _080803E0 @ =0x03000011\n\
	movs r0, #0\n\
_080803CC:\n\
	strb r0, [r1]\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080803E0: .4byte 0x03000011\n\
    .syntax divided\n");
}

// 0x080803E4
NAKED_FUNCTION
void Sram_InitSaveFile(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	ldr r2, _080804C8 @ =0x02037C00\n\
	movs r3, #0xe0\n\
	lsls r3, r3, #2\n\
	movs r4, #0x10\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl BitFill\n\
	ldr r5, _080804CC @ =0x0000FFFF\n\
	ldr r2, _080804D0 @ =0x02036000\n\
	movs r3, #0x90\n\
	lsls r3, r3, #5\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	ldr r2, _080804D4 @ =0x02037200\n\
	movs r3, #0x90\n\
	lsls r3, r3, #4\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	adds r1, r5, #0\n\
	bl BitFill\n\
	movs r1, #0\n\
	ldr r4, _080804D8 @ =0x03000033\n\
	movs r2, #0\n\
	ldr r3, _080804DC @ =0x0300003B\n\
_08080424:\n\
	adds r0, r1, r4\n\
	strb r2, [r0]\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	adds r1, #1\n\
	cmp r1, #7\n\
	ble _08080424\n\
	ldr r1, _080804E0 @ =gInGameTimer\n\
	ldr r0, _080804E4 @ =0x085822D4\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldr r1, _080804E8 @ =gDisableDrawingSamusAndScrollingFlag\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0\n\
	bl EventSet\n\
	ldr r0, _080804EC @ =gPreviousNavigationConversation\n\
	movs r3, #0xff\n\
	strb r3, [r0]\n\
	ldr r0, _080804F0 @ =gPreviousSoundEvent\n\
	movs r1, #0xff\n\
	strh r1, [r0]\n\
	ldr r2, _080804F4 @ =gEquipment\n\
	ldrb r0, [r2, #0xd]\n\
	orrs r0, r3\n\
	strb r0, [r2, #0xd]\n\
	ldr r0, _080804F8 @ =gSecurityHatchLevel\n\
	strb r1, [r0]\n\
	ldr r0, _080804FC @ =gSecurityHatchLevelBackup\n\
	strb r1, [r0]\n\
	movs r1, #0\n\
	strb r1, [r2, #0xe]\n\
	ldr r0, _08080500 @ =gAbilityCount\n\
	strb r1, [r0]\n\
	ldr r0, _08080504 @ =gCurrentArea\n\
	strb r1, [r0]\n\
	ldr r0, _08080508 @ =gPreviousArea\n\
	strb r1, [r0]\n\
	ldr r0, _0808050C @ =gCurrentRoom\n\
	strb r1, [r0]\n\
	ldr r0, _08080510 @ =gLastDoorUsed\n\
	strb r1, [r0]\n\
	ldr r0, _08080514 @ =0x0300004C\n\
	strb r1, [r0]\n\
	ldr r0, _08080518 @ =0x0300004D\n\
	strb r1, [r0]\n\
	ldr r0, _0808051C @ =0x0879B894\n\
	ldr r2, [r0]\n\
	ldrb r0, [r2, #2]\n\
	movs r6, #7\n\
	ldrsb r6, [r2, r6]\n\
	ldr r3, _08080520 @ =gPreviousXPosition\n\
	ldr r4, _08080524 @ =gSamusData\n\
	lsls r1, r0, #6\n\
	adds r0, r6, #0\n\
	adds r0, #8\n\
	lsls r0, r0, #2\n\
	adds r1, r1, r0\n\
	movs r5, #0\n\
	strh r1, [r4, #0x16]\n\
	strh r1, [r3]\n\
	ldrb r0, [r2, #5]\n\
	adds r0, #1\n\
	movs r6, #8\n\
	ldrsb r6, [r2, r6]\n\
	ldr r2, _08080528 @ =gPreviousYPosition\n\
	lsls r0, r0, #6\n\
	lsls r1, r6, #2\n\
	adds r0, r0, r1\n\
	subs r0, #1\n\
	strh r0, [r4, #0x18]\n\
	strh r0, [r2]\n\
	bl MinimapLoadInitial\n\
	ldr r0, _0808052C @ =gIsLoadingFile\n\
	strb r5, [r0]\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080804C8: .4byte 0x02037C00\n\
_080804CC: .4byte 0x0000FFFF\n\
_080804D0: .4byte 0x02036000\n\
_080804D4: .4byte 0x02037200\n\
_080804D8: .4byte 0x03000033\n\
_080804DC: .4byte 0x0300003B\n\
_080804E0: .4byte gInGameTimer\n\
_080804E4: .4byte 0x085822D4\n\
_080804E8: .4byte gDisableDrawingSamusAndScrollingFlag\n\
_080804EC: .4byte gPreviousNavigationConversation\n\
_080804F0: .4byte gPreviousSoundEvent\n\
_080804F4: .4byte gEquipment\n\
_080804F8: .4byte gSecurityHatchLevel\n\
_080804FC: .4byte gSecurityHatchLevelBackup\n\
_08080500: .4byte gAbilityCount\n\
_08080504: .4byte gCurrentArea\n\
_08080508: .4byte gPreviousArea\n\
_0808050C: .4byte gCurrentRoom\n\
_08080510: .4byte gLastDoorUsed\n\
_08080514: .4byte 0x0300004C\n\
_08080518: .4byte 0x0300004D\n\
_0808051C: .4byte 0x0879B894\n\
_08080520: .4byte gPreviousXPosition\n\
_08080524: .4byte gSamusData\n\
_08080528: .4byte gPreviousYPosition\n\
_0808052C: .4byte gIsLoadingFile\n\
    .syntax divided\n");
}

/**
 * @brief 80530 | 134 | Resets the save data before a demo
 * 
 */
void Sram_ResetForDemo(void)
{
    s32 i;

    gBootDebugOptions = sBootDebugOptions_Default;
    gButtonAssignments = sDefaultButtonAssignments;

    BitFill(3, USHORT_MAX, gVisitedMinimapTiles, AREA_NORMAL_COUNT * MINIMAP_SIZE / 8, 16);
    BitFill(3, USHORT_MAX, gNeverReformBlocks, 0x1200, 16);
    BitFill(3, USHORT_MAX, gCollectedTanks, 0x900, 16);

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        gNumberOfNeverReformBlocks[i] = 0;
        gNumberOfCollectedTanks[i] = 0;
    }

    gInGameTimer = sInGameTimer_Empty;
    gDisableDrawingSamusAndScrollingFlag = FALSE;
    gPreviousNavigationConversation = UCHAR_MAX;
    gPreviousSoundEvent = UCHAR_MAX;
    gUnk_300004c = 0;
    gUnk_300004d = 0;
    gIsLoadingFile = FALSE;

    gUnk_3000be3 = FALSE;
    gMonochromeFading = 0;
    gDisableSoftReset = FALSE;
    gMaxInGameTimeFlag = TRUE;
    gDisableMusicFlag = FALSE;
    gSkipDoorTransition = FALSE;
    gPauseScreenFlag = 0;
    gUnk_3000b85 = 0;
    gDisablePauseFlag = FALSE;
    gSamusDoorPositionOffset = 0;
    gDebugFlag = FALSE;
}

/**
 * @brief 80664 | e0 | Checks if the current save file exists, and either loads it or initializes a new one
 * 
 */
void Sram_CheckLoadSaveFile(void)
{
    s32 loading;

    gButtonAssignments = sDefaultButtonAssignments;
    gBootDebugOptions = sBootDebugOptions_Default;

    loading = gIsLoadingFile = gSaveFilesInfo[gMostRecentSaveFile].exists;
    if (loading == FALSE)
    {
        Sram_InitSaveFile();
        gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;
        gGameCompletion.introPlayed = gSaveFilesInfo[gMostRecentSaveFile].introPlayed;
        gGameCompletion.unk_2 = loading;
    }
    else
    {
        SramLoad_CurrentSave();
    }

    gUnk_3000be3 = FALSE;
    gMonochromeFading = 0;
    gDisableSoftReset = FALSE;
    gMaxInGameTimeFlag = FALSE;
    gDisableMusicFlag = FALSE;
    gSkipDoorTransition = FALSE;
    gPauseScreenFlag = 0;
    gUnk_3000b85 = 0;
    gDisablePauseFlag = FALSE;
    gSamusDoorPositionOffset = 0;
    gDebugFlag = FALSE;
}

/**
 * @brief 80744 | a8 | Erases the current save file, split in several stages
 * 
 */
void Sram_EraseFile(u8 stage)
{
    struct SaveFileInfo emptyInfo = { 0 };

    if (stage == 0)
    {
        gDisableSoftReset = TRUE;
        gSaveFilesInfo[gMostRecentSaveFile] = emptyInfo;
        BitFill(3, USHORT_MAX, (void*)sSaveDataEwramPointers[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
    }
    else if (stage == 1)
    {
        WriteMostRecentFileToSram();
    }
    else if (stage == 2)
    {
        BitFill(3, USHORT_MAX, (void*)sSaveDataEwramBackupPointers[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
    }
    else
    {
        if (stage == 3)
            WriteMostRecentFileBackupToSram();

        gDisableSoftReset = FALSE;
    }
}

/**
 * @brief 807ec | c8 | Copies the current save file to another file, split in several stages
 * 
 */
void Sram_CopyFile(u8 dst, u8 stage)
{
    u8 currentFile;

    if (stage == 0)
    {
        gDisableSoftReset = TRUE;
        gSaveFilesInfo[dst] = gSaveFilesInfo[gMostRecentSaveFile];
        DmaTransfer(3, sSaveDataEwramPointers[gMostRecentSaveFile], (void*)sSaveDataEwramPointers[dst],
            sizeof(struct SaveFile), 16);
    }
    else if (stage == 1)
    {
        currentFile = gMostRecentSaveFile;
        gMostRecentSaveFile = dst;
        WriteMostRecentFileToSram();
        gMostRecentSaveFile = currentFile;
    }
    else if (stage == 2)
    {
        DmaTransfer(3, sSaveDataEwramBackupPointers[gMostRecentSaveFile], (void*)sSaveDataEwramBackupPointers[dst],
            sizeof(struct SaveFile), 16);
    }
    else
    {
        if (stage == 3)
        {
            currentFile = gMostRecentSaveFile;
            gMostRecentSaveFile = dst;
            WriteMostRecentFileBackupToSram();
            gMostRecentSaveFile = currentFile;
        }

        gDisableSoftReset = FALSE;
    }
}

/**
 * @brief 808b4 | 9c | Fills the file info of every save file
 * 
 */
void Sram_WriteFileInfo(void)
{
    s32 i;
    struct SaveFile* pFile;

    for (i = 0; i < 3; i++)
    {
        if (gSaveFilesInfo[i].exists == TRUE)
        {
            pFile = (struct SaveFile*)sSaveDataEwramPointers[i];
            gSaveFilesInfo[i].currentArea = pFile->currentArea;
            gSaveFilesInfo[i].eventCounter = pFile->eventCounter;
            gSaveFilesInfo[i].currentEnergy = pFile->equipment.currentEnergy;
            gSaveFilesInfo[i].maxEnergy = pFile->equipment.maxEnergy;
            gSaveFilesInfo[i].currentMissiles = pFile->equipment.currentMissiles;
            gSaveFilesInfo[i].maxMissiles = pFile->equipment.maxMissiles;
            gSaveFilesInfo[i].weaponsStatus = pFile->equipment.weaponsStatus;
            gSaveFilesInfo[i].igtHours = pFile->inGameTimer.hours;
            gSaveFilesInfo[i].igtMinutes = pFile->inGameTimer.minutes;
            gSaveFilesInfo[i].hasSaved = pFile->hasSaved;
            gSaveFilesInfo[i].completedGame = pFile->gameCompletion.completedGame;
            gSaveFilesInfo[i].introPlayed = pFile->gameCompletion.introPlayed;
        }

        if (gSaveFilesInfo[i].exists == FALSE || gSaveFilesInfo[i].hasSaved == FALSE)
        {
            gSaveFilesInfo[i].exists = FALSE;
            gSaveFilesInfo[i].currentArea = 0;
            gSaveFilesInfo[i].eventCounter = 0;
            gSaveFilesInfo[i].currentEnergy = 0;
            gSaveFilesInfo[i].maxEnergy = 0;
            gSaveFilesInfo[i].currentMissiles = 0;
            gSaveFilesInfo[i].maxMissiles = 0;
            gSaveFilesInfo[i].weaponsStatus = 0;
            gSaveFilesInfo[i].igtHours = 0;
            gSaveFilesInfo[i].igtMinutes = 0;
        }
    }
}

/**
 * @brief 80950 | c | V-blank code while loading a file
 * 
 */
void Sram_LoadingfileVblank(void)
{
    vu8 c;

    c = 0;
}

/**
 * @brief 8095c | c | V-blank code after loading a file
 * 
 */
void Sram_AfterLoadingFileVblank(void)
{
    UpdateAudio();
}

/**
 * @brief 80968 | 2c | Checks and loads the current save file with the loading v-blank
 * 
 */
s32 Sram_ChecLoadSaveFileWithBlank(void)
{
    CallbackSetVBlank(Sram_AfterLoadingFileVblank);
    Sram_CheckLoadSaveFile();
    CallbackSetVBlank(Sram_LoadingfileVblank);
    return gIsLoadingFile;
}

/**
 * @brief 80994 | 5c | Writes a file to flash sram if it was flagged as corrupted
 * 
 */
void Sram_SetCurrentFile(u8 file)
{
    u8 previousFile;

    previousFile = gMostRecentSaveFile;
    gMostRecentSaveFile = file;

    switch (gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag)
    {
        case 1:
            WriteMostRecentFileToSram();
            break;

        case 2:
            WriteMostRecentFileToSram();
            WriteMostRecentFileBackupToSram();
        case 0:
            break;
    }

    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
    gMostRecentSaveFile = previousFile;
}
