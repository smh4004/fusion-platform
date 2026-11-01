#ifndef DIED_ON_SR388_COLLISION_H
#define DIED_ON_SR388_COLLISION_H

#include "types.h"

#include "structs/cutscene.h"

boolu32 DiedFromSr388CollisionHandler(void);
void DiedOnSr388CollisionInit(void);
boolu32 DiedOnSr388CollisionProcess(void);
boolu32 DiedOnSr388Collision(void);
void DiedOnSr388CollisionProcessFallingBsl(struct SpecialCutsceneOam* pOam);
void unk_979d0(struct SpecialCutsceneOam* pOam);
u8 DiedOnSr388CollisionSetupOam(u8 type, s16 xPosition, s16 yPosition, boolu8 descendingSearch);
void DiedOnSr388CollisionVblank(void);
void DiedOnSr388CollisionVblank_Unused(void);
u8 DiedOnSr388CollisionGetPositionAndSlotOfOamByType(u8 type, s16* pXPosition, s16* pYPosition);
void unk_97dcc(struct SpecialCutsceneOam* pOam);

#endif /* DIED_ON_SR388_COLLISION_H */
