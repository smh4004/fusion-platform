#ifndef ENDING_IN_SHIP_H
#define ENDING_IN_SHIP_H

#include "types.h"

#include "structs/cutscene.h"

void EndingMonologueInit(void);
void EndingAdamConversationInit(void);
void EndingAnimalsInit(void);
boolu32 EndingInShipProcess(void);
boolu32 EndingInShip(void);
void EndingProcessMonologueCursor(struct SpecialCutsceneOam* pOam);
void unk_969e0(struct SpecialCutsceneOam* pOam);
void EndingProcessSr388RadarView(struct SpecialCutsceneOam* pOam);
void EndingProcessSamusViewRadarView(struct SpecialCutsceneOam* pOam);
void unk_96a70(struct SpecialCutsceneOam* pOam);
void EndingProcessAdamTextCursor(struct SpecialCutsceneOam* pOam);
void EndingProcessAdamPanel(struct SpecialCutsceneOam* pOam);
void EndingProcessAdamIcon(struct SpecialCutsceneOam* pOam);
void EndingProcessAnimalsScrolling(struct SpecialCutsceneOam* pOam);
void unk_96f00(struct SpecialCutsceneOam* pOam);
u8 EndingDialogueSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
void EndingMonologueVblank(void);
void EndingConversationAndAnimalsVblank(void);
u8 EndingGetPositionAndSlotOfOamByType_2(u8 type, s16* pXPosition, s16* pYPosition);
void unk_97418(struct SpecialCutsceneOam* pOam);

#endif /* ENDING_IN_SHIP_H */
