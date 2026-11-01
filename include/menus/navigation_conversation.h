#ifndef NAVIGATION_CONVERSATION_H
#define NAVIGATION_CONVERSATION_H

#include "types.h"

void NavigationConversationProcessText(void);
u8 unk_7a0fc(u8 arg0);
void NavigationConversationGetCurrentConversation(void);
u8 NavigationConversationHandler(void);
void NavigationConversationSetupOam(void);
void NavigationConversationUpdateTarget(u8 arg0);
u8 NavigationConverstionFindTarget(void);
void NavigationConversionScrollToTarget(void);
u8 NavigationConversationScrollMapToDestination(u8 x, u8 y);
void unk_7b56c(void);
void unk_7b674(void);
void ProcessPauseScreenText(void);
void ProcessEasySleepText(void);
u8 GetFlashingSectorNumber(void);
void NavigationConversationLoadPopUpGraphics(void);
void NavigationConversationUpdatePopUp(void);
void unk_7bde0(void);
void NavigationConversationFadeInPopUpPalette(void);
void NavigationConversationUpdateXParasitePopUp(void);
void NavigationConversationClearPopUpGraphics(void);
void unk_7c3b4(void);
void unk_7c440(void);
void NavigationConversationLoadSpecialGraphics(void);
void unk_7c630(void);
void unk_7ce6c(void);
void unk_7cfb0(void);
void unk_7d27c(void);

#endif /* NAVIGATION_CONVERSATION_H */
