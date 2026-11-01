#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include "types.h"

void Sram_ReadAll(void);
void Sram_WriteHeader(void);
void Sram_ReadHeader(void);
u32 Sram_VerifyHeader(u8 header);
void Sram_ProcessIntroSave(u8 stage);
void Sram_WriteHeaderAndGameInfo(void);
void Sram_ProcessEndingSave(u8 stage);
void Sram_CopyGameCompletion(void);
void Sram_QuickSave(u8 stage);
void SramWrite_ToEwram(void);
void SramRead_FromEwram(void);
void Sram_StringCopy_MetroidEpisode4A(u8* dst, const u8* src);
void Sram_StringCopy_SAVE_END(u8* dst, const u8* src);
void SramTestFlash(void);
void Sram_BackupCurrentFile_Unused(void);
void unk_7fb84(void);
void unk_7fd10(void);
u32 unk_7fdb0(u8 useBackup);
void SramLoad_CurrentSave(void);
void SramLoad_CurrentSave_Unused(void);
void SramWrite_WorldData(void);
void SramRead_WorldData(void);
void SramWrite_MostRecentSaveFile(void);
void SramRead_MostRecentSaveFile(void);
void SramWrite_Language(void);
void SramRead_Language(void);
void Sram_InitSaveFile(void);
void Sram_ResetForDemo(void);
void Sram_CheckLoadSaveFile(void);
void Sram_EraseFile(u8 stage);
void Sram_CopyFile(u8 dst, u8 stage);
void Sram_WriteFileInfo(void);
void Sram_LoadingfileVblank(void);
void Sram_AfterLoadingFileVblank(void);
u32 Sram_ChecLoadSaveFileWithBlank(void);
void Sram_SetCurrentFile(u8 file);

#endif /* SAVE_FILE_H */
