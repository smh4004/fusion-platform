#include "menus/navigation_conversation.h"

#include "gba.h"
#include "globals.h"
#include "macros.h"

#include "data/event_data.h"
#include "data/menus/pause_screen_misc_data.h"
#include "data/sa_x_close_up.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/menus/pause_screen.h"
#include "constants/navigation.h"

#include "structs/connection.h"
#include "structs/event.h"
#include "structs/menus/pause_screen.h"

#include "audio_wrappers.h"
#include "dma.h"
#include "syscalls.h"
#include "text.h"

#include "constants/audio.h"


static Func_T sNavConversationPopUpFunctions[3] = {
    unk_7bde0,
    NavigationConversationUpdateXParasitePopUp,
    NavigationConversationClearPopUpGraphics
};

static u8 sBlob_79c17c_79c27c[] = INCBIN_U8("data/Blob_79c17c_79c27c.bin");

// 0x08079AFC
NAKED_FUNCTION
void NavigationConversationProcessText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	ldr r0, _08079B14 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0x17]\n\
	adds r5, r0, #0\n\
	cmp r1, #0\n\
	beq _08079B18\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x10\n\
	b _08079B1C\n\
	.align 2, 0\n\
_08079B14: .4byte gNonGameplayRam\n\
_08079B18:\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #8\n\
_08079B1C:\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08079B24\n\
	b _0807A0EC\n\
_08079B24:\n\
	ldrb r0, [r5, #0x18]\n\
	ldr r1, _08079B70 @ =0x06007000\n\
	mov r8, r1\n\
	cmp r0, #0\n\
	beq _08079B32\n\
	ldr r2, _08079B74 @ =0x06006000\n\
	mov r8, r2\n\
_08079B32:\n\
	movs r7, #0\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r4, r5, #0\n\
	adds r4, #0xe\n\
	adds r2, r0, r4\n\
	ldrh r1, [r2]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08079B80\n\
	ldr r0, _08079B78 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08079B56\n\
	b _0807A0EC\n\
_08079B56:\n\
	ldr r0, _08079B7C @ =0x00000203\n\
	bl SoundPlay\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	movs r6, #0\n\
	strh r7, [r0]\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r4, #4\n\
	b _08079B94\n\
	.align 2, 0\n\
_08079B70: .4byte 0x06007000\n\
_08079B74: .4byte 0x06006000\n\
_08079B78: .4byte gChangedInput\n\
_08079B7C: .4byte 0x00000203\n\
_08079B80:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08079BDA\n\
	movs r6, #0\n\
	strh r7, [r2]\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r4, r5, #0\n\
	adds r4, #0x12\n\
_08079B94:\n\
	adds r0, r0, r4\n\
	ldrh r0, [r0]\n\
	cmp r0, #0xe0\n\
	bls _08079BA2\n\
	movs r0, #2\n\
	bl TextClearGraphics\n\
_08079BA2:\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	movs r1, #0xe0\n\
	strh r1, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x36\n\
	movs r1, #0xb\n\
	strb r1, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x34\n\
	strb r6, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x35\n\
	strb r6, [r0]\n\
	b _0807A0EC\n\
_08079BDA:\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08079C48\n\
	ldr r0, _08079C40 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08079BF0\n\
	b _0807A0EC\n\
_08079BF0:\n\
	ldr r0, _08079C44 @ =0x00000203\n\
	bl SoundPlay\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r4\n\
	movs r4, #0\n\
	strh r7, [r0]\n\
	movs r0, #1\n\
	bl TextClearGraphics\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #0\n\
	adds r1, #0x12\n\
	adds r0, r0, r1\n\
	strh r7, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x36\n\
	movs r1, #0xb\n\
	strb r1, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x34\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x35\n\
	strb r4, [r0]\n\
	b _0807A0EC\n\
	.align 2, 0\n\
_08079C40: .4byte gChangedInput\n\
_08079C44: .4byte 0x00000203\n\
_08079C48:\n\
	ldr r0, _08079C60 @ =0x0000E001\n\
	cmp r1, r0\n\
	bne _08079C64\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08079C5C\n\
	b _0807A0EC\n\
_08079C5C:\n\
	strh r7, [r2]\n\
	b _0807A0EC\n\
	.align 2, 0\n\
_08079C60: .4byte 0x0000E001\n\
_08079C64:\n\
	ldrb r0, [r5, #0x1f]\n\
	cmp r0, #0\n\
	beq _08079C70\n\
	subs r0, #1\n\
	strb r0, [r5, #0x1f]\n\
	b _0807A0EC\n\
_08079C70:\n\
	ldrb r0, [r5, #0x1a]\n\
	ldr r2, _08079CA8 @ =gButtonInput\n\
	cmp r0, #0\n\
	beq _08079C84\n\
	ldrh r1, [r2]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _08079C84\n\
	strb r7, [r5, #0x1a]\n\
_08079C84:\n\
	ldrb r1, [r5, #0x18]\n\
	lsls r1, r1, #1\n\
	adds r0, r5, #0\n\
	adds r0, #0xe\n\
	adds r1, r1, r0\n\
	ldrh r0, [r1]\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	ldrh r1, [r2]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08079CAC\n\
	ldrb r0, [r5, #0x1a]\n\
	cmp r0, #0\n\
	bne _08079CAC\n\
	movs r7, #1\n\
	b _08079CC0\n\
	.align 2, 0\n\
_08079CA8: .4byte gButtonInput\n\
_08079CAC:\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #0\n\
	adds r1, #0xe\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	ldrb r1, [r5, #0x1d]\n\
	cmp r0, r1\n\
	bhs _08079CC0\n\
	b _0807A0EC\n\
_08079CC0:\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #0\n\
	adds r1, #0xe\n\
	adds r0, r0, r1\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	movs r2, #0x88\n\
	lsls r2, r2, #2\n\
	adds r0, r5, r2\n\
	ldrb r1, [r0]\n\
	subs r0, r1, #1\n\
	lsls r3, r0, #1\n\
	ldr r0, _08079D24 @ =gPreviousNavigationConversation\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	bne _08079CE4\n\
	adds r3, #1\n\
_08079CE4:\n\
	ldr r1, _08079D28 @ =0x0879C0F0\n\
	ldr r0, _08079D2C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r1\n\
	ldr r6, [r0]\n\
	ldrh r0, [r5, #0xc]\n\
	lsls r1, r0, #1\n\
	adds r6, r6, r1\n\
	adds r0, #1\n\
	strh r0, [r5, #0xc]\n\
_08079D04:\n\
	movs r3, #0\n\
	ldrh r0, [r6]\n\
	lsrs r1, r0, #0xc\n\
	movs r4, #0xff\n\
	lsls r4, r4, #8\n\
	ands r4, r0\n\
	subs r1, #8\n\
	adds r2, r0, #0\n\
	cmp r1, #7\n\
	bls _08079D1A\n\
	b _08079F9C\n\
_08079D1A:\n\
	lsls r0, r1, #2\n\
	ldr r1, _08079D30 @ =_08079D34\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08079D24: .4byte gPreviousNavigationConversation\n\
_08079D28: .4byte 0x0879C0F0\n\
_08079D2C: .4byte 0x03000011\n\
_08079D30: .4byte _08079D34\n\
_08079D34: @ jump table\n\
	.4byte _08079F2C @ case 0\n\
	.4byte _08079F0C @ case 1\n\
	.4byte _08079EEC @ case 2\n\
	.4byte _08079E96 @ case 3\n\
	.4byte _08079E90 @ case 4\n\
	.4byte _08079F9C @ case 5\n\
	.4byte _08079DCE @ case 6\n\
	.4byte _08079D54 @ case 7\n\
_08079D54:\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	bne _08079D60\n\
	movs r0, #1\n\
	b _08079DB8\n\
_08079D60:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	bne _08079D78\n\
_08079D68:\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #0\n\
	adds r1, #0xe\n\
	adds r0, r0, r1\n\
	strh r2, [r0]\n\
_08079D74:\n\
	movs r3, #1\n\
	b _08079F9C\n\
_08079D78:\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	beq _08079D88\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	bne _08079DAC\n\
_08079D88:\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #0\n\
	adds r1, #0xe\n\
	adds r0, r0, r1\n\
	strh r2, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x36\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x1a]\n\
	movs r3, #2\n\
	b _08079F9C\n\
_08079DAC:\n\
	movs r0, #0xfb\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	beq _08079DB6\n\
	b _08079F9C\n\
_08079DB6:\n\
	movs r0, #2\n\
_08079DB8:\n\
	strb r0, [r5, #0x1c]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x36\n\
	movs r1, #3\n\
	strb r1, [r0]\n\
	movs r3, #2\n\
	b _08079F9C\n\
_08079DCE:\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079E00\n\
	lsls r0, r2, #0x10\n\
	lsrs r2, r0, #0x10\n\
	cmp r2, r4\n\
	bne _08079DF4\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08079D74\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r2, #0\n\
	orrs r0, r1\n\
	b _08079E82\n\
_08079DF4:\n\
	ldr r0, _08079DFC @ =0x0000E001\n\
	cmp r2, r0\n\
	bne _08079D74\n\
	b _08079D68\n\
	.align 2, 0\n\
_08079DFC: .4byte 0x0000E001\n\
_08079E00:\n\
	movs r0, #0xe1\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079E0C\n\
	strb r2, [r5, #0x1f]\n\
	b _08079D74\n\
_08079E0C:\n\
	movs r0, #0xe2\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079E5C\n\
	ldrh r1, [r6]\n\
	adds r0, #1\n\
	cmp r1, r0\n\
	bne _08079E2C\n\
	ldrh r0, [r5, #4]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strh r0, [r5, #4]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x18]\n\
	strb r1, [r5, #0x19]\n\
	b _08079E56\n\
_08079E2C:\n\
	ldr r0, _08079E44 @ =0x0000E202\n\
	cmp r1, r0\n\
	bne _08079E48\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strh r0, [r5, #4]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x18]\n\
	movs r0, #2\n\
	strb r0, [r5, #0x19]\n\
	b _08079E56\n\
	.align 2, 0\n\
_08079E44: .4byte 0x0000E202\n\
_08079E48:\n\
	ldrh r0, [r5, #4]\n\
	movs r2, #1\n\
	movs r1, #0\n\
	orrs r0, r2\n\
	strh r0, [r5, #4]\n\
	strb r1, [r5, #0x18]\n\
	strb r2, [r5, #0x19]\n\
_08079E56:\n\
	ldrh r0, [r6]\n\
	strb r0, [r5, #0x17]\n\
	b _08079D74\n\
_08079E5C:\n\
	movs r0, #0xe3\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079D74\n\
	lsls r0, r2, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, r4\n\
	bne _08079E74\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x40\n\
	orrs r0, r1\n\
	b _08079E82\n\
_08079E74:\n\
	ldr r0, _08079E88 @ =0x0000E301\n\
	cmp r1, r0\n\
	beq _08079E7C\n\
	b _08079D74\n\
_08079E7C:\n\
	ldrh r1, [r5, #4]\n\
	ldr r0, _08079E8C @ =0x0000FFBF\n\
	ands r0, r1\n\
_08079E82:\n\
	strh r0, [r5, #4]\n\
	b _08079D74\n\
	.align 2, 0\n\
_08079E88: .4byte 0x0000E301\n\
_08079E8C: .4byte 0x0000FFBF\n\
_08079E90:\n\
	movs r0, #6\n\
	strb r0, [r5, #0x1c]\n\
	b _08079D74\n\
_08079E96:\n\
	lsls r0, r2, #0x10\n\
	lsrs r1, r0, #0x10\n\
	ldr r0, _08079EA8 @ =0x0000B001\n\
	cmp r1, r0\n\
	bne _08079EAC\n\
	movs r0, #0x99\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	b _08079EB8\n\
	.align 2, 0\n\
_08079EA8: .4byte 0x0000B001\n\
_08079EAC:\n\
	ldr r0, _08079EC0 @ =0x0000B002\n\
	cmp r1, r0\n\
	bne _08079EC4\n\
	movs r2, #0x99\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
_08079EB8:\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _08079D74\n\
	.align 2, 0\n\
_08079EC0: .4byte 0x0000B002\n\
_08079EC4:\n\
	ldr r0, _08079EE8 @ =0x0000B003\n\
	cmp r1, r0\n\
	bne _08079F9C\n\
	ldrb r0, [r5, #0x1c]\n\
	cmp r0, #5\n\
	beq _08079F9A\n\
	cmp r0, #3\n\
	beq _08079F9A\n\
	movs r0, #0x2a\n\
	movs r1, #2\n\
	bl PlayMusic\n\
	movs r0, #0\n\
	movs r1, #0xb\n\
	bl SoundEventUpdate\n\
	b _08079F9A\n\
	.align 2, 0\n\
_08079EE8: .4byte 0x0000B003\n\
_08079EEC:\n\
	ldr r1, _08079F04 @ =0x00000221\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	rsbs r1, r0, #0\n\
	orrs r1, r0\n\
	ldr r0, _08079F08 @ =0x00000FFF\n\
	ands r0, r2\n\
	lsrs r1, r1, #0x1f\n\
	bl unk_3c14\n\
	b _08079F9A\n\
	.align 2, 0\n\
_08079F04: .4byte 0x00000221\n\
_08079F08: .4byte 0x00000FFF\n\
_08079F0C:\n\
	ldr r1, _08079F24 @ =0x00000221\n\
	adds r0, r5, r1\n\
	ldrb r0, [r0]\n\
	rsbs r1, r0, #0\n\
	orrs r1, r0\n\
	ldr r0, _08079F28 @ =0x00000FFF\n\
	ands r0, r2\n\
	lsrs r1, r1, #0x1f\n\
	bl unk_3bd4\n\
	b _08079F9A\n\
	.align 2, 0\n\
_08079F24: .4byte 0x00000221\n\
_08079F28: .4byte 0x00000FFF\n\
_08079F2C:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079F46\n\
	ldrb r1, [r5, #0x18]\n\
	lsls r1, r1, #1\n\
	adds r0, r5, #0\n\
	adds r0, #0x12\n\
	adds r1, r1, r0\n\
	movs r0, #0xff\n\
	ands r0, r2\n\
	ldrh r2, [r1]\n\
	b _08079F96\n\
_08079F46:\n\
	movs r0, #0x81\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079F52\n\
	strb r2, [r5, #0x1e]\n\
	b _08079F9A\n\
_08079F52:\n\
	movs r0, #0x82\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079F68\n\
	strb r2, [r5, #0x1d]\n\
	lsls r0, r2, #0x18\n\
	cmp r0, #0\n\
	bne _08079F9A\n\
	movs r0, #8\n\
	strb r0, [r5, #0x1d]\n\
	b _08079F9A\n\
_08079F68:\n\
	movs r0, #0x83\n\
	lsls r0, r0, #8\n\
	cmp r4, r0\n\
	bne _08079F9A\n\
	ldrb r0, [r5, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r5, #0\n\
	adds r1, #0x12\n\
	adds r1, r0, r1\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xdf\n\
	bls _08079F84\n\
	movs r0, #0xe0\n\
	b _08079F86\n\
_08079F84:\n\
	movs r0, #0\n\
_08079F86:\n\
	strh r0, [r1]\n\
	ldrb r1, [r5, #0x18]\n\
	lsls r1, r1, #1\n\
	adds r0, r5, #0\n\
	adds r0, #0x12\n\
	adds r1, r1, r0\n\
	ldrh r0, [r1]\n\
	ldrb r2, [r6]\n\
_08079F96:\n\
	adds r0, r0, r2\n\
	strh r0, [r1]\n\
_08079F9A:\n\
	movs r3, #3\n\
_08079F9C:\n\
	cmp r3, #3\n\
	bne _08079FB4\n\
	ldr r1, _08079FB0 @ =gNonGameplayRam\n\
	ldrh r0, [r1, #0xc]\n\
	adds r0, #1\n\
	strh r0, [r1, #0xc]\n\
	adds r6, #2\n\
	adds r5, r1, #0\n\
	b _08079D04\n\
	.align 2, 0\n\
_08079FB0: .4byte gNonGameplayRam\n\
_08079FB4:\n\
	cmp r3, #2\n\
	bne _08079FE0\n\
	ldr r2, _08079FDC @ =gNonGameplayRam\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	adds r0, #0x34\n\
	movs r3, #0\n\
	strb r3, [r0]\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	adds r0, #0x35\n\
	strb r3, [r0]\n\
	b _0807A0EC\n\
	.align 2, 0\n\
_08079FDC: .4byte gNonGameplayRam\n\
_08079FE0:\n\
	cmp r3, #1\n\
	bne _08079FE6\n\
	b _0807A0EC\n\
_08079FE6:\n\
	ldrh r0, [r6]\n\
	bl TextGetCharacterWidth\n\
	ldr r4, _0807A01C @ =gNonGameplayRam\n\
	strb r0, [r4, #0x16]\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r5, r4, #0\n\
	adds r5, #0x12\n\
	adds r2, r0, r5\n\
	ldrh r1, [r2]\n\
	ldrb r0, [r4, #0x16]\n\
	adds r3, r1, r0\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	cmp r3, r0\n\
	ble _0807A020\n\
	movs r0, #2\n\
	bl TextClearGraphics\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r5\n\
	movs r1, #0xe0\n\
	strh r1, [r0]\n\
	b _0807A02C\n\
	.align 2, 0\n\
_0807A01C: .4byte gNonGameplayRam\n\
_0807A020:\n\
	cmp r3, #0xe0\n\
	ble _0807A02C\n\
	cmp r1, #0xdf\n\
	bhi _0807A02C\n\
	movs r0, #0xe0\n\
	strh r0, [r2]\n\
_0807A02C:\n\
	ldr r0, _0807A098 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #0x18]\n\
	lsls r1, r1, #1\n\
	adds r2, r0, #0\n\
	adds r2, #0x12\n\
	adds r1, r1, r2\n\
	ldrh r2, [r1]\n\
	adds r5, r0, #0\n\
	cmp r2, #0\n\
	beq _0807A044\n\
	cmp r2, #0xe0\n\
	bne _0807A046\n\
_0807A044:\n\
	strh r2, [r1]\n\
_0807A046:\n\
	adds r4, r5, #0\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r4, #0\n\
	adds r1, #0x12\n\
	adds r1, r0, r1\n\
	ldrh r3, [r1]\n\
	cmp r3, #0xdf\n\
	bls _0807A060\n\
	movs r0, #0x80\n\
	lsls r0, r0, #4\n\
	add r8, r0\n\
	subs r3, #0xe0\n\
_0807A060:\n\
	asrs r0, r3, #3\n\
	lsls r3, r0, #5\n\
	add r8, r3\n\
	ldrh r1, [r1]\n\
	movs r3, #7\n\
	ldrh r0, [r6]\n\
	ldrb r2, [r4, #0x16]\n\
	ands r3, r1\n\
	ldrb r1, [r4, #0x1e]\n\
	str r1, [sp]\n\
	mov r1, r8\n\
	bl TextDrawCharacter\n\
	cmp r7, #0\n\
	bne _0807A0BA\n\
	ldrh r0, [r6]\n\
	cmp r0, #0x40\n\
	beq _0807A0BA\n\
	ldrb r0, [r4, #0x17]\n\
	cmp r0, #1\n\
	bne _0807A09C\n\
	ldrh r0, [r6]\n\
	movs r1, #0x21\n\
	bl PlayCharacterAppearingSound\n\
	movs r0, #2\n\
	strb r0, [r4, #0x1b]\n\
	b _0807A0BA\n\
	.align 2, 0\n\
_0807A098: .4byte gNonGameplayRam\n\
_0807A09C:\n\
	cmp r0, #2\n\
	bne _0807A0AE\n\
	ldrh r0, [r6]\n\
	movs r1, #0x41\n\
	bl PlayCharacterAppearingSound\n\
	movs r0, #3\n\
	strb r0, [r4, #0x1b]\n\
	b _0807A0BA\n\
_0807A0AE:\n\
	ldrh r0, [r6]\n\
	movs r1, #1\n\
	bl PlayCharacterAppearingSound\n\
	movs r0, #1\n\
	strb r0, [r5, #0x1b]\n\
_0807A0BA:\n\
	movs r3, #1\n\
	ldrh r2, [r6, #2]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r2\n\
	cmp r0, #0\n\
	beq _0807A0D4\n\
	movs r1, #0xf0\n\
	lsls r1, r1, #8\n\
	bics r1, r2\n\
	rsbs r0, r1, #0\n\
	orrs r0, r1\n\
	lsrs r3, r0, #0x1f\n\
_0807A0D4:\n\
	cmp r3, #0\n\
	beq _0807A0EC\n\
	ldr r2, _0807A0F8 @ =gNonGameplayRam\n\
	ldrb r1, [r2, #0x18]\n\
	lsls r1, r1, #1\n\
	adds r0, r2, #0\n\
	adds r0, #0x12\n\
	adds r1, r1, r0\n\
	ldrh r0, [r1]\n\
	ldrb r2, [r2, #0x16]\n\
	adds r0, r0, r2\n\
	strh r0, [r1]\n\
_0807A0EC:\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807A0F8: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x0807A0FC
NAKED_FUNCTION
u8 unk_7a0fc(u8 arg0)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	lsls r0, r0, #0x18\n\
	lsrs r3, r0, #0x18\n\
	ldr r2, _0807A120 @ =gNonGameplayRam\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	mov ip, r2\n\
	cmp r0, #0\n\
	bne _0807A124\n\
	movs r0, #0\n\
	b _0807A2C2\n\
	.align 2, 0\n\
_0807A120: .4byte gNonGameplayRam\n\
_0807A124:\n\
	movs r0, #0\n\
	mov sl, r0\n\
	mov sb, r0\n\
	lsls r3, r3, #2\n\
	str r3, [sp, #4]\n\
	mov r5, ip\n\
	mov r6, ip\n\
	adds r6, #0x21\n\
	movs r1, #0x20\n\
	add r1, ip\n\
	mov r8, r1\n\
_0807A13A:\n\
	ldr r1, _0807A174 @ =0x0879CDF4\n\
	ldr r0, _0807A178 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r2, [sp, #4]\n\
	adds r0, r2, r0\n\
	adds r0, #0xac\n\
	ldr r4, [r0]\n\
	ldr r7, _0807A17C @ =0x06007000\n\
	ldrb r0, [r6]\n\
	lsls r0, r0, #1\n\
	adds r4, r4, r0\n\
	ldrh r1, [r4]\n\
	adds r3, r1, #0\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r3, r0\n\
	bne _0807A180\n\
	movs r0, #0\n\
	mov r1, r8\n\
	strb r0, [r1]\n\
	movs r0, #0xe0\n\
	mov r2, ip\n\
	b _0807A1D2\n\
	.align 2, 0\n\
_0807A174: .4byte 0x0879CDF4\n\
_0807A178: .4byte 0x03000011\n\
_0807A17C: .4byte 0x06007000\n\
_0807A180:\n\
	movs r2, #0xff\n\
	lsls r2, r2, #8\n\
	adds r0, r2, #0\n\
	ands r1, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807A1A0\n\
	movs r0, #0\n\
	mov r1, r8\n\
	strb r0, [r1]\n\
	ldrh r0, [r5, #0x22]\n\
	ldrb r4, [r4]\n\
	adds r0, r0, r4\n\
	strh r0, [r5, #0x22]\n\
	b _0807A1D4\n\
_0807A1A0:\n\
	movs r0, #0x83\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807A1E0\n\
	movs r1, #0\n\
	mov r2, r8\n\
	strb r1, [r2]\n\
	ldrh r0, [r5, #0x22]\n\
	cmp r0, #0xdf\n\
	bls _0807A1BA\n\
	movs r0, #0xe0\n\
	strh r0, [r5, #0x22]\n\
	b _0807A1BC\n\
_0807A1BA:\n\
	strh r1, [r5, #0x22]\n\
_0807A1BC:\n\
	ldrb r1, [r4]\n\
	mov r2, ip\n\
	ldrh r0, [r2, #0x22]\n\
	adds r3, r0, r1\n\
	strh r3, [r2, #0x22]\n\
	ldrh r1, [r4]\n\
	ldr r0, _0807A1DC @ =0x000083A0\n\
	cmp r1, r0\n\
	bne _0807A1D4\n\
	adds r0, r3, #0\n\
	subs r0, #0x10\n\
_0807A1D2:\n\
	strh r0, [r2, #0x22]\n\
_0807A1D4:\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	b _0807A13A\n\
	.align 2, 0\n\
_0807A1DC: .4byte 0x000083A0\n\
_0807A1E0:\n\
	mov r0, sb\n\
	cmp r0, #0\n\
	bne _0807A22E\n\
	cmp r3, #0x40\n\
	beq _0807A228\n\
	ldrh r0, [r5, #0x22]\n\
	cmp r0, #0xdf\n\
	bhi _0807A228\n\
	ldrb r0, [r5, #0x1a]\n\
	ldr r2, _0807A2D4 @ =gButtonInput\n\
	cmp r0, #0\n\
	beq _0807A206\n\
	ldrh r1, [r2]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807A206\n\
	mov r1, sb\n\
	strb r1, [r5, #0x1a]\n\
_0807A206:\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	adds r3, r0, #1\n\
	strb r3, [r1]\n\
	ldrh r1, [r2]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A220\n\
	mov r2, ip\n\
	ldrb r0, [r2, #0x1a]\n\
	cmp r0, #0\n\
	beq _0807A228\n\
_0807A220:\n\
	lsls r0, r3, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _0807A2C0\n\
_0807A228:\n\
	movs r0, #0\n\
	mov r1, r8\n\
	strb r0, [r1]\n\
_0807A22E:\n\
	ldrh r0, [r4]\n\
	bl TextGetCharacterWidth\n\
	ldr r2, _0807A2D8 @ =gNonGameplayRam\n\
	strb r0, [r2, #0x16]\n\
	ldrh r1, [r2, #0x22]\n\
	ldrb r0, [r2, #0x16]\n\
	adds r0, r1, r0\n\
	cmp r0, #0xe0\n\
	ble _0807A24A\n\
	cmp r1, #0xdf\n\
	bhi _0807A24A\n\
	movs r0, #0xe0\n\
	strh r0, [r2, #0x22]\n\
_0807A24A:\n\
	ldr r1, _0807A2D8 @ =gNonGameplayRam\n\
	ldrh r0, [r1, #0x22]\n\
	cmp r0, #0\n\
	beq _0807A256\n\
	cmp r0, #0xe0\n\
	bne _0807A258\n\
_0807A256:\n\
	strh r0, [r1, #0x22]\n\
_0807A258:\n\
	ldrh r0, [r4]\n\
	cmp r0, #0x40\n\
	beq _0807A292\n\
	movs r1, #1\n\
	bl PlayCharacterAppearingSound\n\
	ldr r2, _0807A2D8 @ =gNonGameplayRam\n\
	ldrh r0, [r2, #0x22]\n\
	cmp r0, #0xdf\n\
	bls _0807A278\n\
	movs r1, #1\n\
	mov sb, r1\n\
	movs r1, #0x80\n\
	lsls r1, r1, #4\n\
	adds r7, r7, r1\n\
	subs r0, #0xe0\n\
_0807A278:\n\
	asrs r0, r0, #3\n\
	lsls r0, r0, #5\n\
	adds r7, r7, r0\n\
	ldrh r1, [r2, #0x22]\n\
	movs r3, #7\n\
	ldrh r0, [r4]\n\
	ldrb r2, [r2, #0x16]\n\
	ands r3, r1\n\
	movs r1, #0\n\
	str r1, [sp]\n\
	adds r1, r7, #0\n\
	bl TextDrawCharacter\n\
_0807A292:\n\
	ldrh r0, [r5, #0x22]\n\
	ldrb r2, [r5, #0x16]\n\
	adds r0, r0, r2\n\
	strh r0, [r5, #0x22]\n\
	ldrb r0, [r6]\n\
	adds r0, #1\n\
	strb r0, [r6]\n\
	ldrh r0, [r4, #2]\n\
	ldr r1, _0807A2D8 @ =gNonGameplayRam\n\
	mov ip, r1\n\
	movs r2, #0xff\n\
	lsls r2, r2, #8\n\
	cmp r0, r2\n\
	bne _0807A2B2\n\
	movs r0, #1\n\
	mov sl, r0\n\
_0807A2B2:\n\
	mov r1, sb\n\
	cmp r1, #0\n\
	beq _0807A2C0\n\
	mov r2, sl\n\
	cmp r2, #0\n\
	bne _0807A2C0\n\
	b _0807A13A\n\
_0807A2C0:\n\
	mov r0, sl\n\
_0807A2C2:\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807A2D4: .4byte gButtonInput\n\
_0807A2D8: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

/**
 * @brief 7a2dc | c8 | Gets the current navigation conversation
 * 
 */
void NavigationConversationGetCurrentConversation(void)
{
    s32 i;

    for (i = gEventCounter; i > 0; i--)
    {
        if (sEventLocationAndNavigationInfo[i].navConversation != NAV_CONVO_NONE)
            break;
    }

    PAUSE_SCREEN_DATA.conversationNumber = sEventLocationAndNavigationInfo[i].navConversation;

    if (PAUSE_SCREEN_DATA.conversationNumber == gPreviousNavigationConversation)
        PAUSE_SCREEN_DATA.conversationOnRepeat = TRUE;
    else
        PAUSE_SCREEN_DATA.conversationOnRepeat = FALSE;

    TextClearGraphics(0);
    NavigationConversationUpdateTarget(TRUE);
    NavigationConversationSetupOam();

    PAUSE_SCREEN_DATA.unk_238 = 0;
    PAUSE_SCREEN_DATA.unk_239 = 0;
    PAUSE_SCREEN_DATA.unk_23C = 0;
    PAUSE_SCREEN_DATA.unk_23D = 0;
    PAUSE_SCREEN_DATA.unk_250 = 0;
    PAUSE_SCREEN_DATA.unk_251 = 0;
    PAUSE_SCREEN_DATA.unk_252 = 0;
}

// 0x0807A3A4
NAKED_FUNCTION
u8 NavigationConversationHandler(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	bl unk_7b674\n\
	bl NavigationConversionScrollToTarget\n\
	bl unk_7b56c\n\
	bl NavConversationUpdateBottomTextBoxOam\n\
	bl NavConversationUpdateTopTextBoxOam\n\
	movs r7, #0\n\
	ldr r0, _0807A3D4 @ =gNonGameplayRam\n\
	ldrb r0, [r0, #7]\n\
	cmp r0, #0x15\n\
	bls _0807A3C8\n\
	bl _0807AE42\n\
_0807A3C8:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807A3D8 @ =_0807A3DC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807A3D4: .4byte gNonGameplayRam\n\
_0807A3D8: .4byte _0807A3DC\n\
_0807A3DC: @ jump table\n\
	.4byte _0807A434 @ case 0\n\
	.4byte _0807A468 @ case 1\n\
	.4byte _0807A51A @ case 2\n\
	.4byte _0807A6C0 @ case 3\n\
	.4byte _0807A700 @ case 4\n\
	.4byte _0807A718 @ case 5\n\
	.4byte _0807A76C @ case 6\n\
	.4byte _0807A79E @ case 7\n\
	.4byte _0807A7B0 @ case 8\n\
	.4byte _0807A890 @ case 9\n\
	.4byte _0807A938 @ case 10\n\
	.4byte _0807AA2A @ case 11\n\
	.4byte _0807AA48 @ case 12\n\
	.4byte _0807AA84 @ case 13\n\
	.4byte _0807AAE0 @ case 14\n\
	.4byte _0807AB14 @ case 15\n\
	.4byte _0807AB40 @ case 16\n\
	.4byte _0807ABB4 @ case 17\n\
	.4byte _0807AC28 @ case 18\n\
	.4byte _0807ACAE @ case 19\n\
	.4byte _0807AD6C @ case 20\n\
	.4byte _0807ADE8 @ case 21\n\
_0807A434:\n\
	ldr r4, _0807A454 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r4, #6]\n\
	bl NavigationConversationSetupOam\n\
	ldr r1, _0807A458 @ =0x00000221\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807A45C\n\
	movs r0, #4\n\
	strb r0, [r4, #0x1c]\n\
	movs r0, #0x11\n\
	strb r0, [r4, #7]\n\
	bl _0807AE42\n\
	.align 2, 0\n\
_0807A454: .4byte gNonGameplayRam\n\
_0807A458: .4byte 0x00000221\n\
_0807A45C:\n\
	strb r0, [r4, #0x1c]\n\
	ldrb r0, [r4, #7]\n\
	adds r0, #1\n\
	strb r0, [r4, #7]\n\
	bl _0807AE42\n\
_0807A468:\n\
	ldr r1, _0807A4D4 @ =gNonGameplayRam\n\
	movs r2, #0x9a\n\
	lsls r2, r2, #2\n\
	adds r3, r1, r2\n\
	ldrh r2, [r3]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	adds r0, r4, #0\n\
	movs r5, #0\n\
	orrs r0, r2\n\
	strh r0, [r3]\n\
	movs r2, #1\n\
	strb r2, [r1, #9]\n\
	strb r2, [r1, #0xb]\n\
	movs r0, #8\n\
	strb r0, [r1, #0x1d]\n\
	strb r5, [r1, #0x1e]\n\
	strb r5, [r1, #0x1f]\n\
	movs r3, #0x88\n\
	lsls r3, r3, #2\n\
	adds r0, r1, r3\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	lsls r3, r0, #1\n\
	ldr r4, _0807A4D8 @ =0x00000221\n\
	adds r0, r1, r4\n\
	ldrb r0, [r0]\n\
	adds r4, r1, #0\n\
	cmp r0, #0\n\
	beq _0807A4A6\n\
	adds r3, #1\n\
_0807A4A6:\n\
	ldr r1, _0807A4DC @ =0x0879C0F0\n\
	ldr r0, _0807A4E0 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldrh r3, [r0]\n\
	ldr r0, _0807A4E4 @ =0x0000E201\n\
	cmp r3, r0\n\
	bne _0807A4E8\n\
	ldrh r0, [r4, #4]\n\
	movs r1, #2\n\
	orrs r0, r1\n\
	strh r0, [r4, #4]\n\
	strb r2, [r4, #0x18]\n\
	strb r1, [r4, #0x19]\n\
	strb r2, [r4, #0x17]\n\
	b _0807A512\n\
	.align 2, 0\n\
_0807A4D4: .4byte gNonGameplayRam\n\
_0807A4D8: .4byte 0x00000221\n\
_0807A4DC: .4byte 0x0879C0F0\n\
_0807A4E0: .4byte 0x03000011\n\
_0807A4E4: .4byte 0x0000E201\n\
_0807A4E8:\n\
	ldr r0, _0807A500 @ =0x0000E202\n\
	cmp r3, r0\n\
	bne _0807A504\n\
	ldrh r0, [r4, #4]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strh r0, [r4, #4]\n\
	strb r2, [r4, #0x18]\n\
	movs r0, #2\n\
	strb r0, [r4, #0x19]\n\
	strb r0, [r4, #0x17]\n\
	b _0807A512\n\
	.align 2, 0\n\
_0807A500: .4byte 0x0000E202\n\
_0807A504:\n\
	ldrh r0, [r4, #4]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strh r0, [r4, #4]\n\
	strb r5, [r4, #0x18]\n\
	strb r1, [r4, #0x19]\n\
	strb r5, [r4, #0x17]\n\
_0807A512:\n\
	ldrb r0, [r4, #7]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	b _0807AC3E\n\
_0807A51A:\n\
	ldr r1, _0807A584 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #0x1b]\n\
	ldrb r0, [r1, #0x1c]\n\
	adds r4, r1, #0\n\
	cmp r0, #1\n\
	bne _0807A5B8\n\
	ldr r0, _0807A588 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A590\n\
	ldrh r1, [r4, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807A59C\n\
	ldr r1, _0807A58C @ =0x00000241\n\
	adds r0, r4, r1\n\
	ldrb r5, [r0]\n\
	cmp r5, #0\n\
	bne _0807A590\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x36\n\
	strb r5, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x34\n\
	strb r5, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x35\n\
	strb r5, [r0]\n\
	movs r0, #0\n\
	bl TextClearGraphics\n\
	movs r0, #3\n\
	strb r0, [r4, #7]\n\
	strb r5, [r4, #6]\n\
	bl _0807AE42\n\
	.align 2, 0\n\
_0807A584: .4byte gNonGameplayRam\n\
_0807A588: .4byte gChangedInput\n\
_0807A58C: .4byte 0x00000241\n\
_0807A590:\n\
	ldrh r1, [r4, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A5F2\n\
_0807A59C:\n\
	ldrh r1, [r4, #4]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #3\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A5AE\n\
	bl _0807AE42\n\
_0807A5AE:\n\
	adds r0, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r4, #4]\n\
	bl _0807AE42\n\
_0807A5B8:\n\
	cmp r0, #2\n\
	bne _0807A5E6\n\
	ldrh r1, [r4, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	bne _0807A5F2\n\
	adds r0, r4, #0\n\
	adds r0, #0x24\n\
	strb r1, [r0]\n\
	adds r2, r4, #0\n\
	adds r2, #0x25\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	strb r0, [r4, #0x1a]\n\
	strb r1, [r4, #0x1b]\n\
	movs r0, #8\n\
	strb r0, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	b _0807A5F2\n\
_0807A5E6:\n\
	cmp r0, #6\n\
	bne _0807A5EE\n\
	movs r7, #1\n\
	b _0807A5F2\n\
_0807A5EE:\n\
	bl NavigationConversationProcessText\n\
_0807A5F2:\n\
	ldr r3, _0807A628 @ =gNonGameplayRam\n\
	ldrb r0, [r3, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	adds r0, r1, #0\n\
	adds r0, #0x36\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0807A630\n\
	movs r0, #0x74\n\
	strh r0, [r1, #0x2e]\n\
	ldrb r0, [r3, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	ldr r2, _0807A62C @ =0x085766E0\n\
	ldrb r0, [r3, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r2, #1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	strh r0, [r1, #0x2c]\n\
	bl _0807AE42\n\
	.align 2, 0\n\
_0807A628: .4byte gNonGameplayRam\n\
_0807A62C: .4byte 0x085766E0\n\
_0807A630:\n\
	movs r2, #0\n\
	strh r2, [r1, #0x2e]\n\
	ldrb r1, [r3, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	strh r2, [r0, #0x2c]\n\
	ldrb r0, [r3, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r3, #0\n\
	adds r1, #0x12\n\
	adds r0, r0, r1\n\
	ldrh r2, [r0]\n\
	cmp r2, #0xdf\n\
	bls _0807A68C\n\
	ldrb r1, [r3, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	ldr r4, _0807A684 @ =0x0000FF28\n\
	adds r1, r2, r4\n\
	ldrh r2, [r0, #0x2e]\n\
	adds r1, r1, r2\n\
	strh r1, [r0, #0x2e]\n\
	ldrb r0, [r3, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r3\n\
	ldr r2, _0807A688 @ =0x085766E0\n\
	ldrb r0, [r3, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	adds r0, #0x10\n\
	ldrh r3, [r1, #0x2c]\n\
	adds r0, r0, r3\n\
	strh r0, [r1, #0x2c]\n\
	bl _0807AE42\n\
	.align 2, 0\n\
_0807A684: .4byte 0x0000FF28\n\
_0807A688: .4byte 0x085766E0\n\
_0807A68C:\n\
	ldrb r1, [r3, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r3\n\
	adds r1, r2, #0\n\
	adds r1, #8\n\
	ldrh r4, [r0, #0x2e]\n\
	adds r1, r1, r4\n\
	strh r1, [r0, #0x2e]\n\
	ldrb r0, [r3, #0x19]\n\
	lsls r2, r0, #1\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	adds r2, r2, r3\n\
	ldr r0, _0807A6BC @ =0x085766E0\n\
	ldrb r1, [r3, #0x18]\n\
	lsls r1, r1, #1\n\
	adds r1, r1, r0\n\
	ldrh r0, [r2, #0x2c]\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	strh r0, [r2, #0x2c]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807A6BC: .4byte 0x085766E0\n\
_0807A6C0:\n\
	ldr r1, _0807A6F4 @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #0x1b]\n\
	movs r2, #0x88\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldr r2, _0807A6F8 @ =gPreviousNavigationConversation\n\
	ldrb r0, [r0]\n\
	ldrb r3, [r2]\n\
	cmp r0, r3\n\
	beq _0807A6E6\n\
	strb r0, [r2]\n\
	ldr r4, _0807A6FC @ =0x00000221\n\
	adds r0, r1, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807A6E6\n\
	bl SoundEventUpdateForNavConversation\n\
_0807A6E6:\n\
	ldr r0, _0807A6F4 @ =gNonGameplayRam\n\
	ldrb r1, [r0, #7]\n\
	adds r1, #1\n\
	movs r2, #0\n\
	strb r1, [r0, #7]\n\
	strb r2, [r0, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807A6F4: .4byte gNonGameplayRam\n\
_0807A6F8: .4byte gPreviousNavigationConversation\n\
_0807A6FC: .4byte 0x00000221\n\
_0807A700:\n\
	ldr r2, _0807A714 @ =gNonGameplayRam\n\
	ldrb r0, [r2, #6]\n\
	cmp r0, #8\n\
	bhi _0807A70A\n\
	b _0807AE42\n\
_0807A70A:\n\
	ldrb r0, [r2, #7]\n\
	adds r0, #1\n\
	movs r1, #0\n\
	b _0807A798\n\
	.align 2, 0\n\
_0807A714: .4byte gNonGameplayRam\n\
_0807A718:\n\
	ldr r3, _0807A768 @ =gNonGameplayRam\n\
	movs r0, #0x9a\n\
	lsls r0, r0, #2\n\
	adds r2, r3, r0\n\
	ldrh r0, [r2]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	adds r1, r4, #0\n\
	eors r0, r1\n\
	strh r0, [r2]\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A73C\n\
	movs r0, #0x40\n\
	eors r0, r1\n\
	strh r0, [r3, #4]\n\
_0807A73C:\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A74C\n\
	movs r0, #8\n\
	eors r0, r1\n\
	strh r0, [r3, #4]\n\
_0807A74C:\n\
	ldrh r1, [r3, #4]\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A75C\n\
	movs r0, #0x10\n\
	eors r0, r1\n\
	strh r0, [r3, #4]\n\
_0807A75C:\n\
	ldrb r0, [r3, #7]\n\
	adds r0, #1\n\
	strb r0, [r3, #7]\n\
	movs r0, #0\n\
	strb r0, [r3, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807A768: .4byte gNonGameplayRam\n\
_0807A76C:\n\
	ldr r2, _0807A790 @ =gNonGameplayRam\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807A78C\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807A78C\n\
	movs r0, #4\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	cmp r1, #0\n\
	beq _0807A794\n\
_0807A78C:\n\
	movs r0, #0\n\
	b _0807AE44\n\
	.align 2, 0\n\
_0807A790: .4byte gNonGameplayRam\n\
_0807A794:\n\
	ldrb r0, [r2, #7]\n\
	adds r0, #1\n\
_0807A798:\n\
	strb r0, [r2, #7]\n\
	strb r1, [r2, #6]\n\
	b _0807AE42\n\
_0807A79E:\n\
	movs r7, #1\n\
	ldr r1, _0807A7AC @ =gNonGameplayRam\n\
	movs r0, #0\n\
	strb r0, [r1, #7]\n\
	strb r0, [r1, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807A7AC: .4byte gNonGameplayRam\n\
_0807A7B0:\n\
	ldr r5, _0807A818 @ =gNonGameplayRam\n\
	adds r6, r5, #0\n\
	adds r6, #0x24\n\
	ldrb r4, [r6]\n\
	cmp r4, #0\n\
	bne _0807A824\n\
	ldr r0, _0807A81C @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x83\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807A7CA\n\
	b _0807AE42\n\
_0807A7CA:\n\
	ldr r0, _0807A820 @ =0x00000203\n\
	bl SoundPlay\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x36\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x34\n\
	strb r4, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x35\n\
	strb r4, [r0]\n\
	movs r0, #1\n\
	bl TextClearGraphics\n\
	movs r0, #1\n\
	strb r0, [r6]\n\
	movs r0, #3\n\
	strb r0, [r5, #0x1c]\n\
	adds r0, r5, #0\n\
	adds r0, #0x20\n\
	strb r4, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	strh r4, [r5, #0x22]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807A818: .4byte gNonGameplayRam\n\
_0807A81C: .4byte gChangedInput\n\
_0807A820: .4byte 0x00000203\n\
_0807A824:\n\
	cmp r4, #2\n\
	bne _0807A832\n\
	movs r1, #0\n\
	movs r0, #9\n\
	strb r0, [r5, #7]\n\
	strb r1, [r5, #6]\n\
	b _0807AE42\n\
_0807A832:\n\
	movs r0, #0\n\
	bl unk_7a0fc\n\
	cmp r0, #0\n\
	bne _0807A83E\n\
	b _0807AE42\n\
_0807A83E:\n\
	movs r3, #0\n\
	movs r2, #2\n\
	strb r2, [r6]\n\
	movs r0, #1\n\
	strb r0, [r5, #0x1a]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x36\n\
	strb r2, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x34\n\
	strb r3, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x35\n\
	strb r3, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	movs r1, #0x8c\n\
	strh r1, [r0, #0x2c]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	movs r1, #0x34\n\
	strh r1, [r0, #0x2e]\n\
	b _0807AE42\n\
_0807A890:\n\
	movs r3, #0\n\
	ldr r2, _0807A8C8 @ =gNonGameplayRam\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	movs r5, #0\n\
	movs r1, #0x8c\n\
	strh r1, [r0, #0x2c]\n\
	ldr r0, _0807A8CC @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	adds r4, r2, #0\n\
	cmp r0, #0\n\
	beq _0807A8D0\n\
	adds r5, r4, #0\n\
	adds r5, #0x25\n\
	ldrb r0, [r5]\n\
	movs r2, #1\n\
	eors r0, r2\n\
	rsbs r1, r0, #0\n\
	orrs r1, r0\n\
	lsrs r3, r1, #0x1f\n\
	strb r2, [r5]\n\
	b _0807A8F8\n\
	.align 2, 0\n\
_0807A8C8: .4byte gNonGameplayRam\n\
_0807A8CC: .4byte gChangedInput\n\
_0807A8D0:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A8E8\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _0807A8E4\n\
	movs r3, #1\n\
_0807A8E4:\n\
	strb r5, [r1]\n\
	b _0807A8F8\n\
_0807A8E8:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807A8F8\n\
	movs r3, #2\n\
	movs r0, #0xa\n\
	strb r0, [r4, #7]\n\
	strb r5, [r4, #6]\n\
_0807A8F8:\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807A910\n\
	ldrb r0, [r4, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #0x34\n\
	b _0807A91C\n\
_0807A910:\n\
	ldrb r0, [r4, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #0x84\n\
_0807A91C:\n\
	strh r0, [r1, #0x2e]\n\
	cmp r3, #1\n\
	bne _0807A924\n\
	b _0807AD3E\n\
_0807A924:\n\
	cmp r3, #2\n\
	beq _0807A92A\n\
	b _0807AE42\n\
_0807A92A:\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807A936\n\
	b _0807AD56\n\
_0807A936:\n\
	b _0807AD60\n\
_0807A938:\n\
	ldr r2, _0807A994 @ =gNonGameplayRam\n\
	ldrh r1, [r2, #4]\n\
	movs r0, #0xc0\n\
	ands r0, r1\n\
	adds r4, r2, #0\n\
	cmp r0, #0\n\
	bne _0807AA18\n\
	movs r0, #0x10\n\
	strb r0, [r4, #7]\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	ldrb r2, [r0]\n\
	cmp r2, #0\n\
	bne _0807A9DA\n\
	ldr r0, _0807A998 @ =0x03000031\n\
	ldrb r1, [r0]\n\
	movs r3, #0x84\n\
	lsls r3, r3, #2\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
	ldr r0, _0807A99C @ =0x03000032\n\
	ldrb r1, [r0]\n\
	adds r3, #1\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
	ldr r1, _0807A9A0 @ =0x00000212\n\
	adds r0, r4, r1\n\
	ldr r1, _0807A9A4 @ =gCurrentArea\n\
	ldrb r0, [r0]\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	beq _0807A9A8\n\
	movs r0, #0xb\n\
	strb r0, [r4, #7]\n\
	subs r3, #0x5b\n\
	adds r0, r4, r3\n\
	strb r2, [r0]\n\
	movs r1, #0xda\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	strb r2, [r0]\n\
	subs r3, #1\n\
	adds r0, r4, r3\n\
	strb r2, [r0]\n\
	b _0807A9B8\n\
	.align 2, 0\n\
_0807A994: .4byte gNonGameplayRam\n\
_0807A998: .4byte 0x03000031\n\
_0807A99C: .4byte 0x03000032\n\
_0807A9A0: .4byte 0x00000212\n\
_0807A9A4: .4byte gCurrentArea\n\
_0807A9A8:\n\
	movs r1, #0xd5\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807A9B8\n\
	movs r0, #0xf\n\
	strb r0, [r4, #7]\n\
_0807A9B8:\n\
	movs r2, #0xd5\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r3, #0xd4\n\
	lsls r3, r3, #1\n\
	adds r0, r4, r3\n\
	strb r1, [r0]\n\
	subs r2, #1\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	movs r2, #0\n\
	strh r1, [r4, #0xc]\n\
	adds r3, #0x71\n\
	adds r0, r4, r3\n\
	strb r2, [r0]\n\
_0807A9DA:\n\
	movs r0, #1\n\
	bl TextClearGraphics\n\
	ldr r2, _0807AA14 @ =gNonGameplayRam\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	adds r0, #0x36\n\
	movs r3, #0\n\
	strb r3, [r0]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x1a]\n\
	ldrb r0, [r2, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r2, #0\n\
	adds r1, #0x12\n\
	adds r0, r0, r1\n\
	movs r4, #0\n\
	strh r3, [r0]\n\
	ldrb r0, [r2, #0x18]\n\
	lsls r0, r0, #1\n\
	subs r1, #4\n\
	adds r0, r0, r1\n\
	strh r3, [r0]\n\
	strb r4, [r2, #0x1c]\n\
	b _0807AE40\n\
	.align 2, 0\n\
_0807AA14: .4byte gNonGameplayRam\n\
_0807AA18:\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807AA22\n\
	b _0807AE42\n\
_0807AA22:\n\
	movs r0, #0x40\n\
	eors r0, r1\n\
	strh r0, [r4, #4]\n\
	b _0807AE42\n\
_0807AA2A:\n\
	ldr r1, _0807AA44 @ =gNonGameplayRam\n\
	movs r0, #0x94\n\
	lsls r0, r0, #2\n\
	adds r4, r1, r0\n\
	ldrb r2, [r4]\n\
	movs r0, #1\n\
	movs r3, #0\n\
	orrs r0, r2\n\
	strb r0, [r4]\n\
	strb r3, [r1, #6]\n\
	movs r0, #0xc\n\
	strb r0, [r1, #7]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AA44: .4byte gNonGameplayRam\n\
_0807AA48:\n\
	ldr r5, _0807AA78 @ =gNonGameplayRam\n\
	movs r1, #0x94\n\
	lsls r1, r1, #2\n\
	adds r0, r5, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807AA5C\n\
	b _0807AE42\n\
_0807AA5C:\n\
	ldr r0, _0807AA7C @ =gCurrentArea\n\
	ldrb r1, [r0]\n\
	ldr r2, _0807AA80 @ =0x00000212\n\
	adds r0, r5, r2\n\
	movs r4, #0\n\
	strb r1, [r0]\n\
	movs r0, #1\n\
	bl unk_75988\n\
	strb r4, [r5, #6]\n\
	movs r0, #0xd\n\
	strb r0, [r5, #7]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AA78: .4byte gNonGameplayRam\n\
_0807AA7C: .4byte gCurrentArea\n\
_0807AA80: .4byte 0x00000212\n\
_0807AA84:\n\
	ldr r6, _0807AAC8 @ =gNonGameplayRam\n\
	ldrb r0, [r6, #6]\n\
	cmp r0, #4\n\
	bhi _0807AA8E\n\
	b _0807AE42\n\
_0807AA8E:\n\
	ldr r3, _0807AACC @ =0x00000212\n\
	adds r4, r6, r3\n\
	ldrb r0, [r4]\n\
	ldr r5, _0807AAD0 @ =0x02034000\n\
	adds r1, r5, #0\n\
	bl MinimapGetData\n\
	ldrb r0, [r4]\n\
	bl MinimapSetVisitedTilesAndCollectedItems\n\
	ldr r1, _0807AAD4 @ =0x040000D4\n\
	str r5, [r1]\n\
	ldr r0, _0807AAD8 @ =0x0600E000\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807AADC @ =0x80000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r1, #0\n\
	movs r0, #0xe\n\
	strb r0, [r6, #7]\n\
	strb r1, [r6, #6]\n\
	movs r4, #0x94\n\
	lsls r4, r4, #2\n\
	adds r2, r6, r4\n\
	ldrb r1, [r2]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AAC8: .4byte gNonGameplayRam\n\
_0807AACC: .4byte 0x00000212\n\
_0807AAD0: .4byte 0x02034000\n\
_0807AAD4: .4byte 0x040000D4\n\
_0807AAD8: .4byte 0x0600E000\n\
_0807AADC: .4byte 0x80000400\n\
_0807AAE0:\n\
	ldr r2, _0807AB10 @ =gNonGameplayRam\n\
	movs r1, #0x94\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0]\n\
	cmp r1, #0\n\
	beq _0807AAF0\n\
	b _0807AE42\n\
_0807AAF0:\n\
	movs r4, #0xdb\n\
	lsls r4, r4, #1\n\
	adds r3, r2, r4\n\
	movs r0, #1\n\
	strb r0, [r3]\n\
	movs r3, #0xda\n\
	lsls r3, r3, #1\n\
	adds r0, r2, r3\n\
	strb r1, [r0]\n\
	subs r4, #1\n\
	adds r0, r2, r4\n\
	strb r1, [r0]\n\
	strb r1, [r2, #6]\n\
	movs r0, #0x10\n\
	strb r0, [r2, #7]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AB10: .4byte gNonGameplayRam\n\
_0807AB14:\n\
	ldr r4, _0807AB38 @ =gNonGameplayRam\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	ldr r2, _0807AB3C @ =0x00000211\n\
	adds r1, r4, r2\n\
	ldrb r1, [r1]\n\
	bl NavigationConversationScrollMapToDestination\n\
	cmp r0, #0\n\
	bne _0807AB2E\n\
	b _0807AE42\n\
_0807AB2E:\n\
	movs r0, #0\n\
	strb r0, [r4, #6]\n\
	movs r0, #0x10\n\
	strb r0, [r4, #7]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AB38: .4byte gNonGameplayRam\n\
_0807AB3C: .4byte 0x00000211\n\
_0807AB40:\n\
	ldr r4, _0807ABAC @ =gNonGameplayRam\n\
	ldrb r0, [r4, #6]\n\
	cmp r0, #0x10\n\
	bhi _0807AB4A\n\
	b _0807AE42\n\
_0807AB4A:\n\
	movs r0, #0\n\
	bl NavigationConversationUpdateTarget\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	movs r3, #0\n\
	movs r1, #8\n\
	strh r1, [r0, #0x2e]\n\
	ldrb r0, [r4, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	ldr r2, _0807ABB0 @ =0x085766E0\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	strh r0, [r1, #0x2c]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x36\n\
	movs r1, #0xb\n\
	strb r1, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x34\n\
	strb r3, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x35\n\
	strb r3, [r0]\n\
	movs r0, #1\n\
	strb r0, [r4, #7]\n\
	strb r3, [r4, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807ABAC: .4byte gNonGameplayRam\n\
_0807ABB0: .4byte 0x085766E0\n\
_0807ABB4:\n\
	ldr r5, _0807AC24 @ =gNonGameplayRam\n\
	movs r3, #0x9a\n\
	lsls r3, r3, #2\n\
	adds r1, r5, r3\n\
	ldrh r3, [r1]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	adds r0, r4, #0\n\
	movs r2, #0\n\
	movs r4, #0\n\
	orrs r0, r3\n\
	strh r0, [r1]\n\
	movs r0, #8\n\
	strb r0, [r5, #0x1d]\n\
	strb r2, [r5, #0x1e]\n\
	strb r2, [r5, #0x1f]\n\
	ldrh r0, [r5, #4]\n\
	movs r1, #1\n\
	orrs r0, r1\n\
	strh r0, [r5, #4]\n\
	strb r2, [r5, #0x18]\n\
	strb r1, [r5, #0x19]\n\
	strb r2, [r5, #0x17]\n\
	adds r0, r5, #0\n\
	adds r0, #0x24\n\
	strb r1, [r0]\n\
	adds r0, #0x1e\n\
	strb r2, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x34\n\
	strb r2, [r0]\n\
	ldrb r1, [r5, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r5\n\
	adds r0, #0x35\n\
	strb r2, [r0]\n\
	adds r0, r5, #0\n\
	adds r0, #0x20\n\
	strb r2, [r0]\n\
	adds r0, #1\n\
	strb r2, [r0]\n\
	strh r4, [r5, #0x22]\n\
	movs r0, #5\n\
	strb r0, [r5, #0x1c]\n\
	ldrb r0, [r5, #7]\n\
	adds r0, #1\n\
	strb r0, [r5, #7]\n\
	strb r2, [r5, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AC24: .4byte gNonGameplayRam\n\
_0807AC28:\n\
	ldr r4, _0807AC44 @ =gNonGameplayRam\n\
	adds r5, r4, #0\n\
	adds r5, #0x24\n\
	ldrb r0, [r5]\n\
	cmp r0, #0\n\
	bne _0807AC36\n\
	b _0807AE42\n\
_0807AC36:\n\
	cmp r0, #2\n\
	bne _0807AC48\n\
	movs r1, #0\n\
	movs r0, #0x13\n\
_0807AC3E:\n\
	strb r0, [r4, #7]\n\
	strb r1, [r4, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AC44: .4byte gNonGameplayRam\n\
_0807AC48:\n\
	movs r0, #1\n\
	bl unk_7a0fc\n\
	cmp r0, #0\n\
	bne _0807AC54\n\
	b _0807AE42\n\
_0807AC54:\n\
	movs r3, #0\n\
	movs r2, #2\n\
	strb r2, [r5]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x1a]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x36\n\
	strb r2, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x34\n\
	strb r3, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x35\n\
	strb r3, [r0]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	movs r2, #0\n\
	movs r1, #0x8c\n\
	strh r1, [r0, #0x2c]\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	movs r1, #0x84\n\
	strh r1, [r0, #0x2e]\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	strb r2, [r0]\n\
	b _0807AE42\n\
_0807ACAE:\n\
	movs r3, #0\n\
	ldr r2, _0807ACE4 @ =gNonGameplayRam\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	movs r5, #0\n\
	movs r1, #0x8c\n\
	strh r1, [r0, #0x2c]\n\
	ldr r0, _0807ACE8 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #0x20\n\
	ands r0, r1\n\
	adds r4, r2, #0\n\
	cmp r0, #0\n\
	beq _0807ACEC\n\
	adds r5, r4, #0\n\
	adds r5, #0x25\n\
	ldrb r0, [r5]\n\
	movs r2, #1\n\
	eors r0, r2\n\
	rsbs r1, r0, #0\n\
	orrs r1, r0\n\
	lsrs r3, r1, #0x1f\n\
	strb r2, [r5]\n\
	b _0807AD14\n\
	.align 2, 0\n\
_0807ACE4: .4byte gNonGameplayRam\n\
_0807ACE8: .4byte gChangedInput\n\
_0807ACEC:\n\
	movs r0, #0x10\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807AD04\n\
	adds r1, r4, #0\n\
	adds r1, #0x25\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _0807AD00\n\
	movs r3, #1\n\
_0807AD00:\n\
	strb r5, [r1]\n\
	b _0807AD14\n\
_0807AD04:\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807AD14\n\
	movs r3, #2\n\
	movs r0, #0x14\n\
	strb r0, [r4, #7]\n\
	strb r5, [r4, #6]\n\
_0807AD14:\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807AD2C\n\
	ldrb r0, [r4, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #0x34\n\
	b _0807AD38\n\
_0807AD2C:\n\
	ldrb r0, [r4, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r4\n\
	movs r0, #0x84\n\
_0807AD38:\n\
	strh r0, [r1, #0x2e]\n\
	cmp r3, #1\n\
	bne _0807AD48\n\
_0807AD3E:\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	b _0807AE42\n\
_0807AD48:\n\
	cmp r3, #2\n\
	bne _0807AE42\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807AD60\n\
_0807AD56:\n\
	movs r0, #0x81\n\
	lsls r0, r0, #2\n\
	bl SoundPlay\n\
	b _0807AE42\n\
_0807AD60:\n\
	ldr r0, _0807AD68 @ =0x00000205\n\
	bl SoundPlay\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807AD68: .4byte 0x00000205\n\
_0807AD6C:\n\
	ldr r4, _0807ADDC @ =gNonGameplayRam\n\
	movs r5, #0\n\
	movs r0, #0x15\n\
	strb r0, [r4, #7]\n\
	adds r0, r4, #0\n\
	adds r0, #0x25\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807ADA4\n\
	ldr r1, _0807ADE0 @ =gPreviousNavigationConversation\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	movs r1, #0xd5\n\
	lsls r1, r1, #1\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	movs r2, #0xd4\n\
	lsls r2, r2, #1\n\
	adds r0, r4, r2\n\
	strb r5, [r0]\n\
	ldr r3, _0807ADE4 @ =0x000001A9\n\
	adds r0, r4, r3\n\
	strb r5, [r0]\n\
	movs r1, #0\n\
	strh r5, [r4, #0xc]\n\
	adds r2, #0x71\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
_0807ADA4:\n\
	movs r0, #1\n\
	bl TextClearGraphics\n\
	ldrb r1, [r4, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, #0x36\n\
	strb r5, [r0]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x1a]\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r1, r4, #0\n\
	adds r1, #0x12\n\
	adds r0, r0, r1\n\
	movs r2, #0\n\
	strh r5, [r0]\n\
	ldrb r0, [r4, #0x18]\n\
	lsls r0, r0, #1\n\
	subs r1, #4\n\
	adds r0, r0, r1\n\
	strh r5, [r0]\n\
	strb r2, [r4, #0x1c]\n\
	strb r2, [r4, #6]\n\
	b _0807AE42\n\
	.align 2, 0\n\
_0807ADDC: .4byte gNonGameplayRam\n\
_0807ADE0: .4byte gPreviousNavigationConversation\n\
_0807ADE4: .4byte 0x000001A9\n\
_0807ADE8:\n\
	ldr r2, _0807AE4C @ =gNonGameplayRam\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	movs r4, #0\n\
	movs r1, #8\n\
	strh r1, [r0, #0x2e]\n\
	ldrb r0, [r2, #0x19]\n\
	lsls r1, r0, #1\n\
	adds r1, r1, r0\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r3, _0807AE50 @ =0x085766E0\n\
	ldrb r0, [r2, #0x18]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	strh r0, [r1, #0x2c]\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	adds r0, #0x36\n\
	movs r1, #0xb\n\
	strb r1, [r0]\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	adds r0, #0x34\n\
	strb r4, [r0]\n\
	ldrb r1, [r2, #0x19]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	adds r0, #0x35\n\
	strb r4, [r0]\n\
	movs r0, #1\n\
	strb r0, [r2, #7]\n\
_0807AE40:\n\
	strb r4, [r2, #6]\n\
_0807AE42:\n\
	adds r0, r7, #0\n\
_0807AE44:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807AE4C: .4byte gNonGameplayRam\n\
_0807AE50: .4byte 0x085766E0\n\
    .syntax divided\n");
}

// 0x0807AE54
NAKED_FUNCTION
void NavigationConversationSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	ldr r6, _0807AF60 @ =gNonGameplayRam\n\
	adds r1, r6, #0\n\
	adds r1, #0x5e\n\
	movs r0, #0\n\
	mov sb, r0\n\
	movs r2, #0\n\
	mov sl, r2\n\
	movs r0, #0x7c\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	movs r0, #0xcc\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	movs r0, #0x4b\n\
	strb r0, [r1]\n\
	adds r0, r6, #0\n\
	adds r0, #0x58\n\
	mov r3, sb\n\
	strb r3, [r0]\n\
	adds r0, #1\n\
	strb r3, [r0]\n\
	movs r0, #1\n\
	bl NavConversationSetBottomTextBoxOam\n\
	movs r4, #0x73\n\
	adds r4, r4, r6\n\
	mov r8, r4\n\
	ldrb r1, [r4]\n\
	movs r2, #0xd\n\
	rsbs r2, r2, #0\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	movs r5, #4\n\
	orrs r0, r5\n\
	strb r0, [r4]\n\
	movs r0, #0x43\n\
	adds r0, r0, r6\n\
	mov ip, r0\n\
	ldrb r1, [r0]\n\
	movs r7, #4\n\
	rsbs r7, r7, #0\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	mov r1, ip\n\
	strb r0, [r1]\n\
	movs r3, #0x5b\n\
	adds r3, r3, r6\n\
	ldrb r1, [r3]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	strb r0, [r3]\n\
	movs r4, #0x67\n\
	adds r4, r4, r6\n\
	ldrb r1, [r4]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	strb r0, [r4]\n\
	movs r5, #0x85\n\
	lsls r5, r5, #2\n\
	adds r1, r6, r5\n\
	ldr r0, _0807AF64 @ =0x085766D4\n\
	ldm r0!, {r3, r4, r5}\n\
	stm r1!, {r3, r4, r5}\n\
	mov r0, sb\n\
	strb r0, [r6, #0x1a]\n\
	mov r1, sl\n\
	strh r1, [r6, #4]\n\
	adds r5, r6, #0\n\
	adds r5, #0xa3\n\
	ldrb r0, [r5]\n\
	adds r4, r2, #0\n\
	ands r4, r0\n\
	movs r3, #4\n\
	orrs r4, r3\n\
	strb r4, [r5]\n\
	adds r3, r6, #0\n\
	adds r3, #0x4f\n\
	ldrb r1, [r3]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	strb r0, [r3]\n\
	adds r3, #0x48\n\
	ldrb r1, [r3]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	strb r0, [r3]\n\
	subs r3, #0xc\n\
	ldrb r1, [r3]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	strb r0, [r3]\n\
	subs r3, #0xc\n\
	ldrb r1, [r3]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	ands r0, r2\n\
	strb r0, [r3]\n\
	adds r0, r6, #0\n\
	adds r0, #0x82\n\
	movs r2, #0xd4\n\
	strh r2, [r0]\n\
	subs r0, #2\n\
	movs r1, #0x44\n\
	strh r1, [r0]\n\
	subs r0, #0xa\n\
	strh r2, [r0]\n\
	subs r0, #2\n\
	strh r1, [r0]\n\
	ldrb r0, [r6]\n\
	cmp r0, #0\n\
	beq _0807AF68\n\
	mov r1, r8\n\
	ldrb r0, [r1]\n\
	adds r1, r7, #0\n\
	ands r1, r0\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	mov r2, r8\n\
	strb r1, [r2]\n\
	ands r4, r7\n\
	orrs r4, r0\n\
	strb r4, [r5]\n\
	b _0807AF7C\n\
	.align 2, 0\n\
_0807AF60: .4byte gNonGameplayRam\n\
_0807AF64: .4byte 0x085766D4\n\
_0807AF68:\n\
	ands r4, r7\n\
	movs r2, #2\n\
	orrs r4, r2\n\
	strb r4, [r5]\n\
	mov r3, r8\n\
	ldrb r1, [r3]\n\
	adds r0, r7, #0\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strb r0, [r3]\n\
_0807AF7C:\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

/**
 * @brief 7af8c | 70 | Updates the navigation target and its map marker
 * 
 */
void NavigationConversationUpdateTarget(u8 updateOam)
{
    u8 oamId;

    if (!NavigationConverstionFindTarget() || !updateOam)
        return;

    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].animationDurationCounter = 0;
    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].currentAnimationFrame = 0;

    if (PAUSE_SCREEN_DATA.unk_20F == 1)
        oamId = sNavConversationTargetTextOamIds[PAUSE_SCREEN_DATA.navTargetTextDirection];
    else
    {
        u8 area = PAUSE_SCREEN_DATA.currentArea;
        oamId = PAUSE_OAM_ID_MAP_ELEVATOR_UP_ARROWS;
        if (area == AREA_MAIN_DECK)
            oamId = PAUSE_OAM_ID_MAP_ELEVATOR_DOWN_ARROWS;
    }

    PAUSE_SCREEN_DATA.oam[PAUSE_OAM_IDX_MAP_TARGET].oamId = oamId;
}

/**
 * @brief 7affc | 15c | Finds the map target of the current navigation conversation
 * 
 */
bools32 NavigationConverstionFindTarget(void)
{
    s32 found;
    u32 i;
    u8 x;
    u8 y;

    PAUSE_SCREEN_DATA.unk_20F = 0;
    PAUSE_SCREEN_DATA.navTargetX = UCHAR_MAX;
    PAUSE_SCREEN_DATA.navTargetY = UCHAR_MAX;
    PAUSE_SCREEN_DATA.navTargetArea = AREA_MAIN_DECK;
    PAUSE_SCREEN_DATA.navTargetTextDirection = NAV_TARGET_TEXT_ABOVE;

    if (gPauseScreenFlag == 4)
        return FALSE;

    gNavConversationTargetLocation = NAV_TARGET_LOC_NONE;
    found = FALSE;
    for (i = 0; i < ARRAY_SIZE(sNavConversationTargets); i++)
    {
        if (PAUSE_SCREEN_DATA.conversationNumber == sNavConversationTargets[i].conversation)
        {
            found = TRUE;
            PAUSE_SCREEN_DATA.navTargetTextDirection = sNavConversationTargets[i].textDirection;
            break;
        }
    }

    if (!found)
        return FALSE;

    gNavConversationTargetLocation = sNavConversationTargets[i].location;
    PAUSE_SCREEN_DATA.navTargetArea = sNavigationTargetLocationAreas[gNavConversationTargetLocation];

    if (PAUSE_SCREEN_DATA.currentArea == PAUSE_SCREEN_DATA.navTargetArea)
    {
        // Target is in the current area
        x = sNavConversationTargets[i].x;
        y = sNavConversationTargets[i].y;
        PAUSE_SCREEN_DATA.unk_20F = 1;
    }
    else if (PAUSE_SCREEN_DATA.currentArea == AREA_MAIN_DECK)
    {
        // Point to the elevator leading to the target's sector
        x = sMainDeckElevatorMapPositions[PAUSE_SCREEN_DATA.navTargetArea][0];
        y = sMainDeckElevatorMapPositions[PAUSE_SCREEN_DATA.navTargetArea][1];
        PAUSE_SCREEN_DATA.unk_20F = 2;
    }
    else
    {
        // Point to the elevator leading out of the current sector
        x = sSectorElevatorMapPositions[PAUSE_SCREEN_DATA.currentArea][0];
        y = sSectorElevatorMapPositions[PAUSE_SCREEN_DATA.currentArea][1];
        if (PAUSE_SCREEN_DATA.navTargetArea == AREA_MAIN_DECK)
            PAUSE_SCREEN_DATA.unk_20F = 2;
        else
            PAUSE_SCREEN_DATA.unk_20F = 3;
    }

    PAUSE_SCREEN_DATA.navTargetX = x - 1;
    PAUSE_SCREEN_DATA.navTargetY = y - 1;

    found = FALSE;
    if (gPreviousNavigationConversation == PAUSE_SCREEN_DATA.conversationNumber)
        found = TRUE;

    return found;
}

// 0x0807B158
NAKED_FUNCTION
void NavigationConversionScrollToTarget(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r1, _0807B178 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #8]\n\
	adds r0, #1\n\
	strb r0, [r1, #8]\n\
	ldrb r0, [r1, #9]\n\
	adds r7, r1, #0\n\
	cmp r0, #0xd\n\
	bls _0807B16C\n\
	b _0807B4BC\n\
_0807B16C:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807B17C @ =_0807B180\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807B178: .4byte gNonGameplayRam\n\
_0807B17C: .4byte _0807B180\n\
_0807B180: @ jump table\n\
	.4byte _0807B4BC @ case 0\n\
	.4byte _0807B1B8 @ case 1\n\
	.4byte _0807B226 @ case 2\n\
	.4byte _0807B236 @ case 3\n\
	.4byte _0807B46C @ case 4\n\
	.4byte _0807B23E @ case 5\n\
	.4byte _0807B300 @ case 6\n\
	.4byte _0807B30A @ case 7\n\
	.4byte _0807B32A @ case 8\n\
	.4byte _0807B400 @ case 9\n\
	.4byte _0807B420 @ case 10\n\
	.4byte _0807B46C @ case 11\n\
	.4byte _0807B488 @ case 12\n\
	.4byte _0807B4BC @ case 13\n\
_0807B1B8:\n\
	movs r2, #0\n\
	movs r1, #0x83\n\
	lsls r1, r1, #2\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _0807B200\n\
	ldr r3, _0807B204 @ =0x0000020D\n\
	adds r0, r7, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xff\n\
	beq _0807B200\n\
	movs r4, #0xd5\n\
	lsls r4, r4, #1\n\
	adds r0, r7, r4\n\
	ldr r1, _0807B208 @ =0x085767EC\n\
	ldrb r0, [r0]\n\
	ldrb r3, [r1]\n\
	cmp r0, r3\n\
	beq _0807B200\n\
	ldrb r4, [r1, #1]\n\
	cmp r0, r4\n\
	beq _0807B200\n\
	ldrb r3, [r1, #2]\n\
	cmp r0, r3\n\
	beq _0807B200\n\
	ldrb r1, [r1, #3]\n\
	cmp r0, r1\n\
	beq _0807B200\n\
	cmp r0, #0xe\n\
	beq _0807B200\n\
	cmp r0, #0xf\n\
	bne _0807B1FC\n\
	movs r2, #1\n\
_0807B1FC:\n\
	cmp r2, #0\n\
	beq _0807B20C\n\
_0807B200:\n\
	movs r0, #0xc\n\
	b _0807B4BA\n\
	.align 2, 0\n\
_0807B204: .4byte 0x0000020D\n\
_0807B208: .4byte 0x085767EC\n\
_0807B20C:\n\
	movs r0, #2\n\
	strb r0, [r7, #9]\n\
	ldrh r1, [r7, #4]\n\
	movs r4, #0x80\n\
	lsls r4, r4, #1\n\
	adds r0, r4, #0\n\
	orrs r0, r1\n\
	movs r2, #0x80\n\
	lsls r2, r2, #2\n\
	adds r1, r2, #0\n\
	orrs r0, r1\n\
	strh r0, [r7, #4]\n\
	b _0807B4BC\n\
_0807B226:\n\
	ldrh r1, [r7, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807B234\n\
	b _0807B4BC\n\
_0807B234:\n\
	b _0807B4B2\n\
_0807B236:\n\
	movs r0, #0\n\
	strb r0, [r7, #8]\n\
	movs r0, #4\n\
	b _0807B4BA\n\
_0807B23E:\n\
	movs r3, #0x83\n\
	lsls r3, r3, #2\n\
	adds r0, r7, r3\n\
	ldrb r0, [r0]\n\
	ldr r4, _0807B270 @ =0x0000020D\n\
	adds r1, r7, r4\n\
	ldrb r1, [r1]\n\
	bl NavigationConversationScrollMapToDestination\n\
	cmp r0, #0\n\
	bne _0807B256\n\
	b _0807B4BC\n\
_0807B256:\n\
	ldr r1, _0807B274 @ =0x0000020F\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807B280\n\
	ldr r1, _0807B278 @ =0x085767EC\n\
	ldr r2, _0807B27C @ =0x00000213\n\
	adds r0, r7, r2\n\
	ldrb r0, [r0]\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	b _0807B28E\n\
	.align 2, 0\n\
_0807B270: .4byte 0x0000020D\n\
_0807B274: .4byte 0x0000020F\n\
_0807B278: .4byte 0x085767EC\n\
_0807B27C: .4byte 0x00000213\n\
_0807B280:\n\
	ldr r3, _0807B2B8 @ =0x00000212\n\
	adds r0, r7, r3\n\
	ldrb r0, [r0]\n\
	movs r2, #0xe\n\
	cmp r0, #0\n\
	bne _0807B28E\n\
	movs r2, #0xf\n\
_0807B28E:\n\
	ldr r5, _0807B2BC @ =gNonGameplayRam\n\
	movs r4, #0xd5\n\
	lsls r4, r4, #1\n\
	adds r0, r5, r4\n\
	movs r1, #0\n\
	strb r2, [r0]\n\
	movs r2, #0xd4\n\
	lsls r2, r2, #1\n\
	adds r0, r5, r2\n\
	strb r1, [r0]\n\
	ldr r3, _0807B2C0 @ =0x000001A9\n\
	adds r0, r5, r3\n\
	strb r1, [r0]\n\
	strb r1, [r5, #8]\n\
	adds r4, #0x65\n\
	adds r0, r5, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807B2C4\n\
	movs r0, #0xc\n\
	b _0807B2C6\n\
	.align 2, 0\n\
_0807B2B8: .4byte 0x00000212\n\
_0807B2BC: .4byte gNonGameplayRam\n\
_0807B2C0: .4byte 0x000001A9\n\
_0807B2C4:\n\
	movs r0, #6\n\
_0807B2C6:\n\
	strb r0, [r5, #9]\n\
	ldr r0, _0807B2F0 @ =0x00000119\n\
	bl SoundStop\n\
	ldr r1, _0807B2F4 @ =gNonGameplayRam\n\
	movs r2, #0x83\n\
	lsls r2, r2, #2\n\
	adds r0, r1, r2\n\
	ldrb r2, [r0]\n\
	movs r3, #0x96\n\
	lsls r3, r3, #2\n\
	adds r0, r1, r3\n\
	strb r2, [r0]\n\
	ldr r4, _0807B2F8 @ =0x0000020D\n\
	adds r0, r1, r4\n\
	ldrb r0, [r0]\n\
	ldr r2, _0807B2FC @ =0x00000259\n\
	adds r1, r1, r2\n\
	strb r0, [r1]\n\
	b _0807B4BC\n\
	.align 2, 0\n\
_0807B2F0: .4byte 0x00000119\n\
_0807B2F4: .4byte gNonGameplayRam\n\
_0807B2F8: .4byte 0x0000020D\n\
_0807B2FC: .4byte 0x00000259\n\
_0807B300:\n\
	ldrb r0, [r7, #8]\n\
	cmp r0, #0x3c\n\
	bhi _0807B308\n\
	b _0807B4BC\n\
_0807B308:\n\
	b _0807B4B2\n\
_0807B30A:\n\
	movs r3, #0x94\n\
	lsls r3, r3, #2\n\
	adds r2, r7, r3\n\
	movs r1, #0\n\
	movs r0, #1\n\
	strb r0, [r2]\n\
	movs r4, #0xd5\n\
	lsls r4, r4, #1\n\
	adds r0, r7, r4\n\
	strb r1, [r0]\n\
	movs r2, #0xdb\n\
	lsls r2, r2, #1\n\
	adds r0, r7, r2\n\
	strb r1, [r0]\n\
	strb r1, [r7, #8]\n\
	b _0807B4B6\n\
_0807B32A:\n\
	movs r3, #0x94\n\
	lsls r3, r3, #2\n\
	adds r0, r7, r3\n\
	ldrb r1, [r0]\n\
	movs r0, #4\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807B33C\n\
	b _0807B4BC\n\
_0807B33C:\n\
	ldr r4, _0807B36C @ =0x0000020F\n\
	adds r0, r7, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0807B34E\n\
	ldr r0, _0807B370 @ =0x0000020E\n\
	adds r1, r7, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
_0807B34E:\n\
	ldr r1, _0807B370 @ =0x0000020E\n\
	adds r3, r7, r1\n\
	ldrb r0, [r3]\n\
	cmp r0, #0\n\
	bne _0807B37C\n\
	ldr r2, _0807B374 @ =0x08576218\n\
	ldr r4, _0807B378 @ =0x00000212\n\
	adds r3, r7, r4\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	subs r4, #2\n\
	b _0807B38C\n\
	.align 2, 0\n\
_0807B36C: .4byte 0x0000020F\n\
_0807B370: .4byte 0x0000020E\n\
_0807B374: .4byte 0x08576218\n\
_0807B378: .4byte 0x00000212\n\
_0807B37C:\n\
	ldr r2, _0807B3E0 @ =0x08576226\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	movs r4, #0x84\n\
	lsls r4, r4, #2\n\
_0807B38C:\n\
	adds r1, r7, r4\n\
	strb r0, [r1]\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #1\n\
	adds r2, #1\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	subs r0, #1\n\
	ldr r2, _0807B3E4 @ =0x00000211\n\
	adds r1, r7, r2\n\
	strb r0, [r1]\n\
	ldr r3, _0807B3E8 @ =0x0000020E\n\
	adds r0, r7, r3\n\
	ldrb r0, [r0]\n\
	ldr r1, _0807B3EC @ =0x00000212\n\
	adds r4, r7, r1\n\
	movs r6, #0\n\
	strb r0, [r4]\n\
	ldrb r0, [r4]\n\
	ldr r5, _0807B3F0 @ =0x02034000\n\
	adds r1, r5, #0\n\
	bl MinimapGetData\n\
	ldrb r0, [r4]\n\
	bl MinimapSetVisitedTilesAndCollectedItems\n\
	ldr r1, _0807B3F4 @ =0x040000D4\n\
	str r5, [r1]\n\
	ldr r0, _0807B3F8 @ =0x0600E000\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807B3FC @ =0x80000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	movs r0, #1\n\
	bl unk_75988\n\
	movs r0, #0\n\
	bl NavigationConversationUpdateTarget\n\
	strb r6, [r7, #8]\n\
	b _0807B4B6\n\
	.align 2, 0\n\
_0807B3E0: .4byte 0x08576226\n\
_0807B3E4: .4byte 0x00000211\n\
_0807B3E8: .4byte 0x0000020E\n\
_0807B3EC: .4byte 0x00000212\n\
_0807B3F0: .4byte 0x02034000\n\
_0807B3F4: .4byte 0x040000D4\n\
_0807B3F8: .4byte 0x0600E000\n\
_0807B3FC: .4byte 0x80000400\n\
_0807B400:\n\
	ldrb r0, [r7, #8]\n\
	cmp r0, #8\n\
	bls _0807B4BC\n\
	movs r0, #0\n\
	strb r0, [r7, #8]\n\
	ldrb r0, [r7, #9]\n\
	adds r0, #1\n\
	strb r0, [r7, #9]\n\
	movs r3, #0x94\n\
	lsls r3, r3, #2\n\
	adds r2, r7, r3\n\
	ldrb r1, [r2]\n\
	movs r0, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	b _0807B4BC\n\
_0807B420:\n\
	movs r4, #0x94\n\
	lsls r4, r4, #2\n\
	adds r0, r7, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _0807B4BC\n\
	ldr r1, _0807B460 @ =0x0000020E\n\
	adds r0, r7, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	beq _0807B442\n\
	ldr r2, _0807B464 @ =0x00000212\n\
	adds r0, r7, r2\n\
	ldrb r0, [r0]\n\
	movs r2, #0xf\n\
	cmp r0, #0\n\
	bne _0807B444\n\
_0807B442:\n\
	movs r2, #0xe\n\
_0807B444:\n\
	movs r3, #0xdb\n\
	lsls r3, r3, #1\n\
	adds r0, r7, r3\n\
	movs r1, #0\n\
	strb r2, [r0]\n\
	movs r4, #0xda\n\
	lsls r4, r4, #1\n\
	adds r0, r7, r4\n\
	strb r1, [r0]\n\
	ldr r2, _0807B468 @ =0x000001B5\n\
	adds r0, r7, r2\n\
	strb r1, [r0]\n\
	strb r1, [r7, #8]\n\
	b _0807B4B6\n\
	.align 2, 0\n\
_0807B460: .4byte 0x0000020E\n\
_0807B464: .4byte 0x00000212\n\
_0807B468: .4byte 0x000001B5\n\
_0807B46C:\n\
	ldrb r0, [r7, #8]\n\
	cmp r0, #0x1e\n\
	bls _0807B4BC\n\
	movs r0, #0\n\
	strb r0, [r7, #8]\n\
	movs r0, #5\n\
	strb r0, [r7, #9]\n\
	ldr r0, _0807B484 @ =0x00000119\n\
	bl SoundPlay\n\
	b _0807B4BC\n\
	.align 2, 0\n\
_0807B484: .4byte 0x00000119\n\
_0807B488:\n\
	adds r2, r7, #0\n\
	ldrh r1, [r2, #4]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #2\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807B49E\n\
	adds r0, r3, #0\n\
	eors r0, r1\n\
	strh r0, [r2, #4]\n\
_0807B49E:\n\
	ldrh r1, [r2, #4]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #3\n\
	adds r0, r3, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807B4B2\n\
	adds r0, r3, #0\n\
	eors r0, r1\n\
	strh r0, [r2, #4]\n\
_0807B4B2:\n\
	movs r0, #0\n\
	strb r0, [r7, #8]\n\
_0807B4B6:\n\
	ldrb r0, [r7, #9]\n\
	adds r0, #1\n\
_0807B4BA:\n\
	strb r0, [r7, #9]\n\
_0807B4BC:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

/**
 * @brief 7b4c4 | a8 | Scrolls the map towards a destination, returns whether it reached it
 * 
 */
u8 NavigationConversationScrollMapToDestination(u8 x, u8 y)
{
    s32 ended;
    s32 targetX;
    s32 targetY;
    s32 diffX;
    s32 diffY;
    s32 speedX;

    ended = TRUE;

    targetX = BLOCK_SIZE * 8 - (15 - x) * 8;
    targetY = BLOCK_SIZE * 8 - (10 - y) * 8;

    diffX = gBackgroundPositions.bg[3].x - targetX;
    diffY = gBackgroundPositions.bg[3].y - targetY;

    if (diffX < 0)
        diffX = -diffX;
    if (diffY < 0)
        diffY = -diffY;

    // Scroll speed, diffY is reused for the vertical speed
    speedX = (diffX >> 4) + 1;
    diffY = (diffY >> 4) + 1;

    diffX = gBackgroundPositions.bg[3].x - targetX;
    if (diffX != 0)
    {
        ended = FALSE;
        if (diffX > 0)
        {
            gBackgroundPositions.bg[3].x -= speedX;
            if (gBackgroundPositions.bg[3].x < targetX)
                gBackgroundPositions.bg[3].x = targetX;
        }
        else if (diffX < 0)
        {
            gBackgroundPositions.bg[3].x += speedX;
            if (gBackgroundPositions.bg[3].x > targetX)
                gBackgroundPositions.bg[3].x = targetX;
        }
    }

    diffX = gBackgroundPositions.bg[3].y - targetY;
    if (diffX != 0)
    {
        ended = FALSE;
        if (diffX > 0)
        {
            gBackgroundPositions.bg[3].y -= diffY;
            if (gBackgroundPositions.bg[3].y < targetY)
                gBackgroundPositions.bg[3].y = targetY;
        }
        else if (diffX < 0)
        {
            gBackgroundPositions.bg[3].y += diffY;
            if (gBackgroundPositions.bg[3].y > targetY)
                gBackgroundPositions.bg[3].y = targetY;
        }
    }

    return ended;
}

// 0x0807B56C
NAKED_FUNCTION
void unk_7b56c(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r1, _0807B588 @ =gNonGameplayRam\n\
	ldrb r0, [r1, #0xa]\n\
	adds r0, #1\n\
	strb r0, [r1, #0xa]\n\
	ldrb r0, [r1, #0xb]\n\
	adds r5, r1, #0\n\
	cmp r0, #9\n\
	bhi _0807B668\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807B58C @ =_0807B590\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807B588: .4byte gNonGameplayRam\n\
_0807B58C: .4byte _0807B590\n\
_0807B590: @ jump table\n\
	.4byte _0807B668 @ case 0\n\
	.4byte _0807B5B8 @ case 1\n\
	.4byte _0807B5BE @ case 2\n\
	.4byte _0807B5CE @ case 3\n\
	.4byte _0807B5EE @ case 4\n\
	.4byte _0807B612 @ case 5\n\
	.4byte _0807B624 @ case 6\n\
	.4byte _0807B650 @ case 7\n\
	.4byte _0807B668 @ case 8\n\
	.4byte _0807B668 @ case 9\n\
_0807B5B8:\n\
	movs r0, #0\n\
	strb r0, [r5, #0xa]\n\
	b _0807B662\n\
_0807B5BE:\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807B668\n\
	movs r0, #0\n\
	strb r0, [r5, #0xa]\n\
	b _0807B662\n\
_0807B5CE:\n\
	adds r1, r5, #0\n\
	adds r1, #0xea\n\
	movs r4, #0\n\
	movs r0, #0x41\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0xe8\n\
	strb r4, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
	strb r4, [r5, #0xa]\n\
	b _0807B662\n\
_0807B5EE:\n\
	ldrb r0, [r5, #0xa]\n\
	cmp r0, #0x1e\n\
	bls _0807B668\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r2, #0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	strb r2, [r5, #0xa]\n\
	ldrb r0, [r5, #0xb]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xb]\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x80\n\
	orrs r0, r1\n\
	strh r0, [r5, #4]\n\
	b _0807B668\n\
_0807B612:\n\
	ldrh r1, [r5, #4]\n\
	movs r0, #0x40\n\
	ands r0, r1\n\
	lsls r0, r0, #0x10\n\
	lsrs r0, r0, #0x10\n\
	cmp r0, #0\n\
	bne _0807B668\n\
	strb r0, [r5, #0xa]\n\
	b _0807B662\n\
_0807B624:\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r4, #0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	adds r1, r5, #0\n\
	adds r1, #0xea\n\
	movs r0, #0x42\n\
	strb r0, [r1]\n\
	adds r0, r5, #0\n\
	adds r0, #0xe8\n\
	strb r4, [r0]\n\
	adds r0, #1\n\
	strb r4, [r0]\n\
	ldr r0, _0807B64C @ =0x0000011D\n\
	bl SoundPlay\n\
	strb r4, [r5, #0xa]\n\
	b _0807B662\n\
	.align 2, 0\n\
_0807B64C: .4byte 0x0000011D\n\
_0807B650:\n\
	ldrb r0, [r5, #0xa]\n\
	cmp r0, #0x1e\n\
	bls _0807B668\n\
	ldrh r1, [r5, #4]\n\
	ldr r0, _0807B670 @ =0x0000FF7F\n\
	ands r0, r1\n\
	movs r1, #0\n\
	strh r0, [r5, #4]\n\
	strb r1, [r5, #0xa]\n\
_0807B662:\n\
	ldrb r0, [r5, #0xb]\n\
	adds r0, #1\n\
	strb r0, [r5, #0xb]\n\
_0807B668:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807B670: .4byte 0x0000FF7F\n\
    .syntax divided\n");
}

// 0x0807B674
NAKED_FUNCTION
void unk_7b674(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r2, _0807B6AC @ =gNonGameplayRam\n\
	movs r1, #0x94\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	adds r4, r2, #0\n\
	cmp r0, #0\n\
	bne _0807B68C\n\
	b _0807B8C4\n\
_0807B68C:\n\
	ldr r2, _0807B6B0 @ =0x00000252\n\
	adds r0, r4, r2\n\
	ldrb r1, [r0]\n\
	adds r1, #1\n\
	strb r1, [r0]\n\
	ldr r1, _0807B6B4 @ =0x00000251\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #8\n\
	bls _0807B6A2\n\
	b _0807B8C4\n\
_0807B6A2:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807B6B8 @ =_0807B6BC\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807B6AC: .4byte gNonGameplayRam\n\
_0807B6B0: .4byte 0x00000252\n\
_0807B6B4: .4byte 0x00000251\n\
_0807B6B8: .4byte _0807B6BC\n\
_0807B6BC: @ jump table\n\
	.4byte _0807B6E0 @ case 0\n\
	.4byte _0807B72C @ case 1\n\
	.4byte _0807B82C @ case 2\n\
	.4byte _0807B780 @ case 3\n\
	.4byte _0807B7BC @ case 4\n\
	.4byte _0807B7D4 @ case 5\n\
	.4byte _0807B82C @ case 6\n\
	.4byte _0807B858 @ case 7\n\
	.4byte _0807B8B0 @ case 8\n\
_0807B6E0:\n\
	movs r2, #0x94\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldrb r1, [r0]\n\
	movs r2, #1\n\
	adds r0, r2, #0\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807B700\n\
	ldr r1, _0807B6FC @ =0x00000251\n\
	adds r0, r4, r1\n\
	strb r2, [r0]\n\
	b _0807B710\n\
	.align 2, 0\n\
_0807B6FC: .4byte 0x00000251\n\
_0807B700:\n\
	movs r0, #2\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807B710\n\
	ldr r2, _0807B720 @ =0x00000251\n\
	adds r1, r4, r2\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
_0807B710:\n\
	ldr r1, _0807B724 @ =gPreviousArea\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	ldr r0, _0807B728 @ =0x00000252\n\
	adds r1, r4, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _0807B8C4\n\
	.align 2, 0\n\
_0807B720: .4byte 0x00000251\n\
_0807B724: .4byte gPreviousArea\n\
_0807B728: .4byte 0x00000252\n\
_0807B72C:\n\
	ldr r1, _0807B770 @ =0x00000252\n\
	adds r2, r4, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #7\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807B73C\n\
	b _0807B8C4\n\
_0807B73C:\n\
	ldr r0, _0807B774 @ =gWrittenToMosaic_L\n\
	ldrh r1, [r0]\n\
	adds r1, #0x11\n\
	strh r1, [r0]\n\
	ldr r0, _0807B778 @ =0x08576802\n\
	lsls r1, r1, #0x10\n\
	lsrs r1, r1, #0x10\n\
	ldrb r0, [r0]\n\
	cmp r1, r0\n\
	beq _0807B752\n\
	b _0807B8C4\n\
_0807B752:\n\
	movs r0, #0\n\
	strb r0, [r2]\n\
	ldr r2, _0807B77C @ =0x00000251\n\
	adds r1, r4, r2\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0x94\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	b _0807B8C4\n\
	.align 2, 0\n\
_0807B770: .4byte 0x00000252\n\
_0807B774: .4byte gWrittenToMosaic_L\n\
_0807B778: .4byte 0x08576802\n\
_0807B77C: .4byte 0x00000251\n\
_0807B780:\n\
	ldr r0, _0807B7B0 @ =0x00000252\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #7\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807B790\n\
	b _0807B8C4\n\
_0807B790:\n\
	ldr r1, _0807B7B4 @ =gWrittenToMosaic_L\n\
	ldrh r0, [r1]\n\
	subs r0, #0x11\n\
	strh r0, [r1]\n\
	lsls r0, r0, #0x10\n\
	lsrs r3, r0, #0x10\n\
	cmp r3, #0\n\
	beq _0807B7A2\n\
	b _0807B8C4\n\
_0807B7A2:\n\
	ldr r0, _0807B7B8 @ =0x00000251\n\
	adds r1, r4, r0\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	strb r3, [r2]\n\
	b _0807B8C4\n\
	.align 2, 0\n\
_0807B7B0: .4byte 0x00000252\n\
_0807B7B4: .4byte gWrittenToMosaic_L\n\
_0807B7B8: .4byte 0x00000251\n\
_0807B7BC:\n\
	ldr r1, _0807B7CC @ =0x00000253\n\
	adds r0, r4, r1\n\
	movs r2, #0\n\
	strb r2, [r0]\n\
	ldr r0, _0807B7D0 @ =0x00000251\n\
	adds r1, r4, r0\n\
	movs r0, #5\n\
	b _0807B846\n\
	.align 2, 0\n\
_0807B7CC: .4byte 0x00000253\n\
_0807B7D0: .4byte 0x00000251\n\
_0807B7D4:\n\
	ldr r2, _0807B81C @ =0x00000253\n\
	adds r5, r4, r2\n\
	ldrb r1, [r5]\n\
	movs r2, #0x50\n\
	subs r0, r2, r1\n\
	asrs r0, r0, #4\n\
	cmp r0, #3\n\
	bgt _0807B7E6\n\
	movs r0, #4\n\
_0807B7E6:\n\
	adds r0, r1, r0\n\
	strb r0, [r5]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0x50\n\
	bls _0807B814\n\
	strb r2, [r5]\n\
	ldr r0, _0807B820 @ =0x00000252\n\
	adds r1, r4, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	ldr r2, _0807B824 @ =0x00000251\n\
	adds r1, r4, r2\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0x94\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrb r0, [r2]\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
_0807B814:\n\
	ldr r3, _0807B828 @ =0x04000046\n\
	ldrb r2, [r5]\n\
	b _0807B89A\n\
	.align 2, 0\n\
_0807B81C: .4byte 0x00000253\n\
_0807B820: .4byte 0x00000252\n\
_0807B824: .4byte 0x00000251\n\
_0807B828: .4byte 0x04000046\n\
_0807B82C:\n\
	movs r1, #0x94\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	ldrb r1, [r0]\n\
	movs r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807B8C4\n\
	ldr r2, _0807B850 @ =0x00000251\n\
	adds r1, r4, r2\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	movs r2, #0\n\
_0807B846:\n\
	strb r0, [r1]\n\
	ldr r1, _0807B854 @ =0x00000252\n\
	adds r0, r4, r1\n\
	strb r2, [r0]\n\
	b _0807B8C4\n\
	.align 2, 0\n\
_0807B850: .4byte 0x00000251\n\
_0807B854: .4byte 0x00000252\n\
_0807B858:\n\
	ldr r2, _0807B884 @ =0x00000253\n\
	adds r3, r4, r2\n\
	ldrb r1, [r3]\n\
	movs r0, #0x50\n\
	subs r0, r0, r1\n\
	asrs r0, r0, #4\n\
	cmp r0, #3\n\
	bgt _0807B86A\n\
	movs r0, #4\n\
_0807B86A:\n\
	subs r0, r1, r0\n\
	cmp r0, #0\n\
	bge _0807B890\n\
	movs r2, #0\n\
	strb r2, [r3]\n\
	ldr r0, _0807B888 @ =0x00000251\n\
	adds r1, r4, r0\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	ldr r1, _0807B88C @ =0x00000252\n\
	adds r0, r4, r1\n\
	strb r2, [r0]\n\
	b _0807B892\n\
	.align 2, 0\n\
_0807B884: .4byte 0x00000253\n\
_0807B888: .4byte 0x00000251\n\
_0807B88C: .4byte 0x00000252\n\
_0807B890:\n\
	strb r0, [r3]\n\
_0807B892:\n\
	ldr r3, _0807B8A8 @ =0x04000046\n\
	ldr r2, _0807B8AC @ =0x00000253\n\
	adds r0, r4, r2\n\
	ldrb r2, [r0]\n\
_0807B89A:\n\
	lsls r1, r2, #8\n\
	movs r0, #0xa0\n\
	subs r0, r0, r2\n\
	orrs r1, r0\n\
	strh r1, [r3]\n\
	b _0807B8C4\n\
	.align 2, 0\n\
_0807B8A8: .4byte 0x04000046\n\
_0807B8AC: .4byte 0x00000253\n\
_0807B8B0:\n\
	ldr r1, _0807B8CC @ =0x00000252\n\
	adds r0, r4, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r2, _0807B8D0 @ =0x00000251\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
	subs r2, #1\n\
	adds r0, r4, r2\n\
	strb r1, [r0]\n\
_0807B8C4:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807B8CC: .4byte 0x00000252\n\
_0807B8D0: .4byte 0x00000251\n\
    .syntax divided\n");
}

// 0x0807B8D4
NAKED_FUNCTION
void ProcessPauseScreenText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	ldr r4, _0807B93C @ =0x0200C000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	adds r2, r4, #0\n\
	bl BitFill\n\
	movs r6, #0\n\
	ldr r2, _0807B940 @ =0x0879C10C\n\
	ldr r0, _0807B944 @ =0x03000011\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	lsls r1, r1, #2\n\
	adds r1, r1, r2\n\
	ldr r0, _0807B948 @ =gEventCounter\n\
	ldrb r0, [r0]\n\
	ldr r1, [r1]\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r7, [r0]\n\
	ldrh r2, [r7]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	adds r0, r1, #0\n\
	cmp r2, r0\n\
	beq _0807B9D8\n\
	movs r5, #0x80\n\
	lsls r5, r5, #8\n\
	mov sl, r5\n\
	movs r1, #0xfe\n\
	lsls r1, r1, #8\n\
	mov sb, r1\n\
_0807B926:\n\
	movs r5, #1\n\
	adds r1, r0, #0\n\
	ands r1, r2\n\
	cmp r1, sl\n\
	bne _0807B94C\n\
	movs r5, #0xff\n\
	mov r8, r5\n\
	mov r0, r8\n\
	ands r0, r2\n\
	mov r8, r0\n\
	b _0807B9C2\n\
	.align 2, 0\n\
_0807B93C: .4byte 0x0200C000\n\
_0807B940: .4byte 0x0879C10C\n\
_0807B944: .4byte 0x03000011\n\
_0807B948: .4byte gEventCounter\n\
_0807B94C:\n\
	movs r0, #0x83\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807B95E\n\
	movs r1, #0\n\
	mov r8, r1\n\
	movs r6, #0xff\n\
	ands r6, r2\n\
	b _0807B9C2\n\
_0807B95E:\n\
	cmp r2, sb\n\
	bne _0807B96E\n\
	movs r2, #0\n\
	mov r8, r2\n\
	cmp r6, #0xe0\n\
	bgt _0807B9D8\n\
	movs r6, #0xe0\n\
	movs r5, #0\n\
_0807B96E:\n\
	cmp r5, #0\n\
	beq _0807B9C2\n\
	ldrh r0, [r7]\n\
	bl TextGetCharacterWidth\n\
	mov r8, r0\n\
	adds r5, r6, r0\n\
	cmp r5, #0xe0\n\
	ble _0807B988\n\
	cmp r6, #0xdf\n\
	bgt _0807B988\n\
	movs r6, #0xe0\n\
	b _0807B990\n\
_0807B988:\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	cmp r5, r0\n\
	bgt _0807B9D8\n\
_0807B990:\n\
	cmp r6, #0xdf\n\
	ble _0807B99E\n\
	movs r5, #0x80\n\
	lsls r5, r5, #4\n\
	adds r4, r6, #0\n\
	subs r4, #0xe0\n\
	b _0807B9A2\n\
_0807B99E:\n\
	movs r5, #0\n\
	adds r4, r6, #0\n\
_0807B9A2:\n\
	asrs r0, r4, #3\n\
	lsls r0, r0, #5\n\
	adds r5, r5, r0\n\
	movs r3, #7\n\
	ldrh r0, [r7]\n\
	ldr r2, _0807B9E8 @ =0x0200C000\n\
	adds r1, r2, r5\n\
	mov r5, r8\n\
	lsls r2, r5, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ands r4, r3\n\
	movs r3, #0\n\
	str r3, [sp]\n\
	adds r3, r4, #0\n\
	bl TextDrawCharacter\n\
_0807B9C2:\n\
	adds r7, #2\n\
	add r6, r8\n\
	ldr r0, _0807B9EC @ =0x000001BF\n\
	cmp r6, r0\n\
	bgt _0807B9D8\n\
	ldrh r2, [r7]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	adds r0, r1, #0\n\
	cmp r2, r0\n\
	bne _0807B926\n\
_0807B9D8:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807B9E8: .4byte 0x0200C000\n\
_0807B9EC: .4byte 0x000001BF\n\
    .syntax divided\n");
}

// 0x0807B9F0
NAKED_FUNCTION
void ProcessEasySleepText(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #4\n\
	ldr r2, _0807BA80 @ =0x0200D000\n\
	movs r5, #0x80\n\
	lsls r5, r5, #5\n\
	movs r4, #0x10\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	adds r3, r5, #0\n\
	bl BitFill\n\
	ldr r2, _0807BA84 @ =0x0200E000\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	adds r3, r5, #0\n\
	bl BitFill\n\
	ldr r2, _0807BA88 @ =0x0200F000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #4\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	movs r1, #0\n\
	bl BitFill\n\
	movs r3, #0\n\
_0807BA30:\n\
	ldr r0, _0807BA84 @ =0x0200E000\n\
	mov sl, r0\n\
	cmp r3, #0\n\
	bne _0807BA3C\n\
	ldr r1, _0807BA80 @ =0x0200D000\n\
	mov sl, r1\n\
_0807BA3C:\n\
	ldr r1, _0807BA8C @ =0x0879CDF4\n\
	ldr r0, _0807BA90 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r1, [r0]\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r1\n\
	adds r0, #0xb4\n\
	ldr r6, [r0]\n\
	movs r7, #0\n\
	ldrh r2, [r6]\n\
	movs r4, #0xff\n\
	lsls r4, r4, #8\n\
	adds r0, r4, #0\n\
	adds r3, #1\n\
	mov sb, r3\n\
	cmp r2, r4\n\
	beq _0807BB24\n\
_0807BA66:\n\
	movs r5, #1\n\
	adds r1, r0, #0\n\
	ands r1, r2\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807BA94\n\
	movs r1, #0xff\n\
	mov r8, r1\n\
	mov r4, r8\n\
	ands r4, r2\n\
	mov r8, r4\n\
	b _0807BB0E\n\
	.align 2, 0\n\
_0807BA80: .4byte 0x0200D000\n\
_0807BA84: .4byte 0x0200E000\n\
_0807BA88: .4byte 0x0200F000\n\
_0807BA8C: .4byte 0x0879CDF4\n\
_0807BA90: .4byte 0x03000011\n\
_0807BA94:\n\
	movs r0, #0x83\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807BAA6\n\
	movs r5, #0\n\
	mov r8, r5\n\
	movs r7, #0xff\n\
	ands r7, r2\n\
	b _0807BB0E\n\
_0807BAA6:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r2, r0\n\
	bne _0807BABA\n\
	movs r1, #0\n\
	mov r8, r1\n\
	cmp r7, #0xe0\n\
	bgt _0807BB24\n\
	movs r7, #0xe0\n\
	movs r5, #0\n\
_0807BABA:\n\
	cmp r5, #0\n\
	beq _0807BB0E\n\
	ldrh r0, [r6]\n\
	bl TextGetCharacterWidth\n\
	mov r8, r0\n\
	adds r5, r7, r0\n\
	cmp r5, #0xe0\n\
	ble _0807BAD4\n\
	cmp r7, #0xdf\n\
	bgt _0807BAD4\n\
	movs r7, #0xe0\n\
	b _0807BADC\n\
_0807BAD4:\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	cmp r5, r0\n\
	bgt _0807BB24\n\
_0807BADC:\n\
	cmp r7, #0xdf\n\
	ble _0807BAEA\n\
	movs r5, #0x80\n\
	lsls r5, r5, #4\n\
	adds r4, r7, #0\n\
	subs r4, #0xe0\n\
	b _0807BAEE\n\
_0807BAEA:\n\
	movs r5, #0\n\
	adds r4, r7, #0\n\
_0807BAEE:\n\
	asrs r0, r4, #3\n\
	lsls r0, r0, #5\n\
	adds r5, r5, r0\n\
	movs r3, #7\n\
	ldrh r0, [r6]\n\
	mov r2, sl\n\
	adds r1, r2, r5\n\
	mov r5, r8\n\
	lsls r2, r5, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ands r4, r3\n\
	movs r3, #0\n\
	str r3, [sp]\n\
	adds r3, r4, #0\n\
	bl TextDrawCharacter\n\
_0807BB0E:\n\
	adds r6, #2\n\
	add r7, r8\n\
	ldr r0, _0807BB60 @ =0x000001BF\n\
	cmp r7, r0\n\
	bgt _0807BB24\n\
	ldrh r2, [r6]\n\
	movs r1, #0xff\n\
	lsls r1, r1, #8\n\
	adds r0, r1, #0\n\
	cmp r2, r1\n\
	bne _0807BA66\n\
_0807BB24:\n\
	mov r3, sb\n\
	cmp r3, #1\n\
	ble _0807BA30\n\
	ldr r2, _0807BB64 @ =0x0200F000\n\
	mov sl, r2\n\
	ldr r1, _0807BB68 @ =0x0879CDF4\n\
	ldr r0, _0807BB6C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	adds r0, #0xbc\n\
	ldr r6, [r0]\n\
	movs r7, #0\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	beq _0807BBE0\n\
	movs r5, #1\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807BB70\n\
	movs r4, #0\n\
	mov r8, r4\n\
	movs r7, #0x70\n\
	b _0807BBB2\n\
	.align 2, 0\n\
_0807BB60: .4byte 0x000001BF\n\
_0807BB64: .4byte 0x0200F000\n\
_0807BB68: .4byte 0x0879CDF4\n\
_0807BB6C: .4byte 0x03000011\n\
_0807BB70:\n\
	ldrh r1, [r6]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #8\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807BB80\n\
	movs r5, #0\n\
	mov r8, r5\n\
_0807BB80:\n\
	cmp r5, #0\n\
	beq _0807BBB2\n\
	ldrh r0, [r6]\n\
	bl TextGetCharacterWidth\n\
	mov r8, r0\n\
	adds r5, r7, r0\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #1\n\
	cmp r5, r0\n\
	bgt _0807BBE0\n\
	asrs r0, r7, #3\n\
	lsls r5, r0, #5\n\
	movs r3, #7\n\
	ldrh r0, [r6]\n\
	mov r2, sl\n\
	adds r1, r2, r5\n\
	mov r4, r8\n\
	lsls r2, r4, #0x18\n\
	lsrs r2, r2, #0x18\n\
	ands r3, r7\n\
	movs r4, #0\n\
	str r4, [sp]\n\
	bl TextDrawCharacter\n\
_0807BBB2:\n\
	adds r6, #2\n\
	add r7, r8\n\
	ldr r0, _0807BBDC @ =0x000001BF\n\
	cmp r7, r0\n\
	bgt _0807BBE0\n\
	ldrh r1, [r6]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	beq _0807BBE0\n\
	movs r5, #1\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _0807BB70\n\
	movs r5, #0\n\
	mov r8, r5\n\
	cmp r7, #0x70\n\
	bgt _0807BBE0\n\
	movs r7, #0x70\n\
	b _0807BBB2\n\
	.align 2, 0\n\
_0807BBDC: .4byte 0x000001BF\n\
_0807BBE0:\n\
	add sp, #4\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0807BBF0
NAKED_FUNCTION
u8 GetFlashingSectorNumber(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r0, _0807BC80 @ =0x0300004D\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	ldr r1, _0807BC84 @ =gEventCounter\n\
	ldrb r2, [r1]\n\
	adds r6, r0, #0\n\
	ldr r1, _0807BC88 @ =0x08575A60\n\
	ldr r7, _0807BC8C @ =gPreviousNavigationConversation\n\
	cmp r2, #0\n\
	ble _0807BC2A\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r3, r0, #2\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0, #6]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0\n\
	bne _0807BC2A\n\
	adds r3, r3, r1\n\
_0807BC1A:\n\
	subs r3, #0xc\n\
	subs r2, #1\n\
	cmp r2, #0\n\
	ble _0807BC2A\n\
	movs r0, #6\n\
	ldrsb r0, [r3, r0]\n\
	cmp r0, #0\n\
	beq _0807BC1A\n\
_0807BC2A:\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r2\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	movs r3, #6\n\
	ldrsb r3, [r0, r3]\n\
	ldrb r4, [r7]\n\
	cmp r4, r3\n\
	bne _0807BC76\n\
	movs r3, #0\n\
	movs r2, #0\n\
	ldr r0, _0807BC90 @ =0x085766E4\n\
	movs r1, #0\n\
	ldrsb r1, [r0, r1]\n\
	adds r5, r0, #0\n\
	cmp r4, r1\n\
	beq _0807BC68\n\
_0807BC4C:\n\
	adds r2, #1\n\
	cmp r2, #0x20\n\
	bhi _0807BC64\n\
	ldrb r0, [r7]\n\
	lsls r1, r2, #3\n\
	adds r1, r1, r5\n\
	ldrb r1, [r1]\n\
	lsls r1, r1, #0x18\n\
	asrs r1, r1, #0x18\n\
	cmp r0, r1\n\
	bne _0807BC4C\n\
	movs r3, #1\n\
_0807BC64:\n\
	cmp r3, #0\n\
	beq _0807BC76\n\
_0807BC68:\n\
	lsls r0, r2, #3\n\
	adds r0, r0, r5\n\
	ldrb r2, [r0, #1]\n\
	ldr r0, _0807BC94 @ =0x08576066\n\
	adds r0, r2, r0\n\
	ldrb r0, [r0]\n\
	strb r0, [r6]\n\
_0807BC76:\n\
	ldrb r0, [r6]\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_0807BC80: .4byte 0x0300004D\n\
_0807BC84: .4byte gEventCounter\n\
_0807BC88: .4byte 0x08575A60\n\
_0807BC8C: .4byte gPreviousNavigationConversation\n\
_0807BC90: .4byte 0x085766E4\n\
_0807BC94: .4byte 0x08576066\n\
    .syntax divided\n");
}

// 0x0807BC98
NAKED_FUNCTION
void NavigationConversationLoadPopUpGraphics(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	movs r4, #3\n\
	ldr r0, _0807BD68 @ =gNonGameplayRam\n\
	movs r1, #0x88\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrb r2, [r0]\n\
	ldr r0, _0807BD6C @ =0x0857BCC8\n\
	movs r1, #8\n\
	ldrsb r1, [r0, r1]\n\
	adds r3, r0, #0\n\
	cmp r2, r1\n\
	beq _0807BCC8\n\
	adds r1, r3, #0\n\
	adds r1, #8\n\
_0807BCB8:\n\
	subs r1, #4\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	ble _0807BCC8\n\
	movs r0, #0\n\
	ldrsb r0, [r1, r0]\n\
	cmp r2, r0\n\
	bne _0807BCB8\n\
_0807BCC8:\n\
	cmp r4, #0\n\
	beq _0807BD5E\n\
	subs r4, #1\n\
	lsls r0, r4, #2\n\
	adds r4, r0, r3\n\
	ldrb r0, [r4, #1]\n\
	cmp r0, #0\n\
	beq _0807BCF0\n\
	ldr r2, _0807BD70 @ =0x0857BC50\n\
	adds r1, r0, #0\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r2, #0x14\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x12\n\
	bl LZ77UncompVram\n\
_0807BCF0:\n\
	ldrb r0, [r4, #2]\n\
	cmp r0, #0\n\
	beq _0807BD0C\n\
	ldr r2, _0807BD70 @ =0x0857BC50\n\
	adds r1, r0, #0\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r2, #0x14\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	ldr r1, _0807BD74 @ =0x02004000\n\
	bl LZ77UncompVram\n\
_0807BD0C:\n\
	ldrb r0, [r4, #3]\n\
	cmp r0, #0\n\
	beq _0807BD28\n\
	ldr r2, _0807BD70 @ =0x0857BC50\n\
	adds r1, r0, #0\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r2, #0x14\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	ldr r1, _0807BD78 @ =0x02008000\n\
	bl LZ77UncompVram\n\
_0807BD28:\n\
	movs r4, #5\n\
	ldr r5, _0807BD7C @ =0x06015700\n\
	movs r6, #0x20\n\
_0807BD2E:\n\
	str r6, [sp]\n\
	movs r0, #3\n\
	movs r1, #1\n\
	rsbs r1, r1, #0\n\
	adds r2, r5, #0\n\
	movs r3, #0x80\n\
	lsls r3, r3, #1\n\
	bl BitFill\n\
	ldr r0, _0807BD80 @ =0xFFFFFC00\n\
	adds r5, r5, r0\n\
	subs r4, #1\n\
	cmp r4, #0\n\
	bge _0807BD2E\n\
	movs r0, #0\n\
	str r0, [sp, #4]\n\
	ldr r1, _0807BD84 @ =0x040000D4\n\
	add r0, sp, #4\n\
	str r0, [r1]\n\
	ldr r0, _0807BD88 @ =0x050003E0\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807BD8C @ =0x85000008\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
_0807BD5E:\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807BD68: .4byte gNonGameplayRam\n\
_0807BD6C: .4byte 0x0857BCC8\n\
_0807BD70: .4byte 0x0857BC50\n\
_0807BD74: .4byte 0x02004000\n\
_0807BD78: .4byte 0x02008000\n\
_0807BD7C: .4byte 0x06015700\n\
_0807BD80: .4byte 0xFFFFFC00\n\
_0807BD84: .4byte 0x040000D4\n\
_0807BD88: .4byte 0x050003E0\n\
_0807BD8C: .4byte 0x85000008\n\
    .syntax divided\n");
}

/**
 * @brief 7bd90 | 50 | Updates the navigation conversation pop-up
 * 
 */
void NavigationConversationUpdatePopUp(void)
{
    if (PAUSE_SCREEN_DATA.currentPopUp == 0)
        return;

    PAUSE_SCREEN_DATA.unk_21B++;
    sNavConversationPopUpFunctions[PAUSE_SCREEN_DATA.currentPopUp - 1]();

    if (PAUSE_SCREEN_DATA.unk_21D != 0)
        NavigationConversationFadeInPopUpPalette();
}

// 0x0807BDE0
NAKED_FUNCTION
void unk_7bde0(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r2, _0807BE2C @ =gNonGameplayRam\n\
	ldr r0, _0807BE30 @ =0x0000021A\n\
	adds r1, r2, r0\n\
	movs r0, #0xff\n\
	strb r0, [r1]\n\
	movs r3, #3\n\
	movs r1, #0x88\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrb r4, [r0]\n\
	ldr r0, _0807BE34 @ =0x0857BCC8\n\
	movs r1, #8\n\
	ldrsb r1, [r0, r1]\n\
	adds r6, r2, #0\n\
	adds r2, r0, #0\n\
	cmp r4, r1\n\
	beq _0807BE18\n\
	adds r1, r2, #0\n\
	adds r1, #8\n\
_0807BE08:\n\
	subs r1, #4\n\
	subs r3, #1\n\
	cmp r3, #0\n\
	ble _0807BE18\n\
	movs r0, #0\n\
	ldrsb r0, [r1, r0]\n\
	cmp r4, r0\n\
	bne _0807BE08\n\
_0807BE18:\n\
	subs r3, #1\n\
	cmp r3, #0xff\n\
	bne _0807BE38\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r1, r6, r2\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	b _0807BFAE\n\
	.align 2, 0\n\
_0807BE2C: .4byte gNonGameplayRam\n\
_0807BE30: .4byte 0x0000021A\n\
_0807BE34: .4byte 0x0857BCC8\n\
_0807BE38:\n\
	ldr r1, _0807BE4C @ =0x00000219\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807BE50\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0, #2]\n\
	b _0807BE62\n\
	.align 2, 0\n\
_0807BE4C: .4byte 0x00000219\n\
_0807BE50:\n\
	cmp r0, #2\n\
	bne _0807BE5C\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0, #3]\n\
	b _0807BE62\n\
_0807BE5C:\n\
	lsls r0, r3, #2\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0, #1]\n\
_0807BE62:\n\
	ldr r2, _0807BE7C @ =0x0000021A\n\
	adds r0, r6, r2\n\
	strb r1, [r0]\n\
	ldr r1, _0807BE7C @ =0x0000021A\n\
	adds r0, r6, r1\n\
	ldrb r3, [r0]\n\
	cmp r3, #0\n\
	bne _0807BE80\n\
	movs r2, #0x86\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	strb r3, [r0]\n\
	b _0807BFAE\n\
	.align 2, 0\n\
_0807BE7C: .4byte 0x0000021A\n\
_0807BE80:\n\
	ldr r1, _0807BEA4 @ =0x00000229\n\
	adds r0, r6, r1\n\
	movs r1, #0\n\
	strb r1, [r0]\n\
	movs r2, #0x8a\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	strb r1, [r0]\n\
	ldr r1, _0807BEA8 @ =0x00000219\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807BEB0\n\
	subs r2, #0x14\n\
	adds r1, r6, r2\n\
	ldr r0, _0807BEAC @ =0x02004000\n\
	b _0807BECE\n\
	.align 2, 0\n\
_0807BEA4: .4byte 0x00000229\n\
_0807BEA8: .4byte 0x00000219\n\
_0807BEAC: .4byte 0x02004000\n\
_0807BEB0:\n\
	cmp r0, #2\n\
	bne _0807BEC4\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r6, r0\n\
	ldr r0, _0807BEC0 @ =0x02008000\n\
	b _0807BECE\n\
	.align 2, 0\n\
_0807BEC0: .4byte 0x02008000\n\
_0807BEC4:\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r6, r2\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x12\n\
_0807BECE:\n\
	str r0, [r1]\n\
	ldr r2, _0807BF28 @ =0x0857BC50\n\
	ldr r1, _0807BF2C @ =0x0000021A\n\
	adds r0, r6, r1\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1, #0x12]\n\
	lsls r2, r0, #0x1c\n\
	lsrs r0, r2, #0x1c\n\
	cmp r0, #8\n\
	bne _0807BF40\n\
	ldrb r2, [r1, #0x11]\n\
	lsls r0, r2, #0x1c\n\
	lsrs r3, r0, #0x1c\n\
	cmp r3, #0\n\
	ble _0807BF82\n\
	ldr r5, _0807BF30 @ =0x040000D4\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	ldr r1, [r0]\n\
	lsls r0, r3, #0xa\n\
	adds r4, r0, r1\n\
	ldr r0, _0807BF34 @ =0xFFFFFC00\n\
	mov ip, r0\n\
	lsls r7, r2, #0x18\n\
_0807BF08:\n\
	add r4, ip\n\
	subs r3, #1\n\
	lsls r2, r3, #0xa\n\
	str r4, [r5]\n\
	lsrs r0, r7, #0x1c\n\
	lsls r0, r0, #0xa\n\
	ldr r1, _0807BF38 @ =0x06014300\n\
	adds r0, r0, r1\n\
	adds r2, r2, r0\n\
	str r2, [r5, #4]\n\
	ldr r0, _0807BF3C @ =0x80000080\n\
	str r0, [r5, #8]\n\
	ldr r0, [r5, #8]\n\
	cmp r3, #0\n\
	bgt _0807BF08\n\
	b _0807BF82\n\
	.align 2, 0\n\
_0807BF28: .4byte 0x0857BC50\n\
_0807BF2C: .4byte 0x0000021A\n\
_0807BF30: .4byte 0x040000D4\n\
_0807BF34: .4byte 0xFFFFFC00\n\
_0807BF38: .4byte 0x06014300\n\
_0807BF3C: .4byte 0x80000080\n\
_0807BF40:\n\
	lsrs r0, r2, #0x1c\n\
	cmp r0, #4\n\
	bne _0807BF82\n\
	ldrb r2, [r1, #0x11]\n\
	lsls r0, r2, #0x1c\n\
	lsrs r3, r0, #0x1c\n\
	cmp r3, #0\n\
	ble _0807BF82\n\
	ldr r5, _0807BFB4 @ =0x040000D4\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r6, r1\n\
	ldr r1, [r0]\n\
	lsls r0, r3, #0xa\n\
	adds r4, r0, r1\n\
	lsls r7, r2, #0x18\n\
_0807BF60:\n\
	ldr r2, _0807BFB8 @ =0xFFFFFC00\n\
	adds r4, r4, r2\n\
	subs r3, #1\n\
	lsls r2, r3, #0xa\n\
	str r4, [r5]\n\
	lsrs r0, r7, #0x1c\n\
	lsls r0, r0, #0xa\n\
	ldr r1, _0807BFBC @ =0x06014300\n\
	adds r0, r0, r1\n\
	adds r2, r2, r0\n\
	adds r2, #0x40\n\
	str r2, [r5, #4]\n\
	ldr r0, _0807BFC0 @ =0x80000040\n\
	str r0, [r5, #8]\n\
	ldr r0, [r5, #8]\n\
	cmp r3, #0\n\
	bgt _0807BF60\n\
_0807BF82:\n\
	ldr r1, _0807BFC4 @ =0x0000021A\n\
	adds r0, r6, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #3\n\
	bne _0807BF92\n\
	ldr r0, _0807BFC8 @ =0x00000125\n\
	bl SoundPlay\n\
_0807BF92:\n\
	ldr r2, _0807BFCC @ =0x0000021D\n\
	adds r1, r6, r2\n\
	movs r2, #0\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r6, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	ldr r1, _0807BFD0 @ =0x0000021B\n\
	adds r0, r6, r1\n\
	strb r2, [r0]\n\
_0807BFAE:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807BFB4: .4byte 0x040000D4\n\
_0807BFB8: .4byte 0xFFFFFC00\n\
_0807BFBC: .4byte 0x06014300\n\
_0807BFC0: .4byte 0x80000040\n\
_0807BFC4: .4byte 0x0000021A\n\
_0807BFC8: .4byte 0x00000125\n\
_0807BFCC: .4byte 0x0000021D\n\
_0807BFD0: .4byte 0x0000021B\n\
    .syntax divided\n");
}

// 0x0807BFD4
NAKED_FUNCTION
void NavigationConversationFadeInPopUpPalette(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, sl\n\
	mov r6, sb\n\
	mov r5, r8\n\
	push {r5, r6, r7}\n\
	sub sp, #8\n\
	ldr r2, _0807C068 @ =0x0857BC50\n\
	ldr r3, _0807C06C @ =gNonGameplayRam\n\
	ldr r1, _0807C070 @ =0x0000021A\n\
	adds r0, r3, r1\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r2, #8\n\
	adds r0, r0, r2\n\
	ldr r2, [r0]\n\
	ldr r6, _0807C074 @ =0x050003E0\n\
	movs r0, #0\n\
	mov ip, r0\n\
	mov sb, sp\n\
	movs r1, #0xf8\n\
	lsls r1, r1, #7\n\
	mov sl, r1\n\
	add r5, sp, #4\n\
_0807C006:\n\
	ldrb r1, [r2]\n\
	movs r0, #0x1f\n\
	ands r0, r1\n\
	mov r1, sb\n\
	strb r0, [r1]\n\
	ldrh r1, [r2]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	lsrs r0, r0, #5\n\
	mov r1, sb\n\
	strb r0, [r1, #1]\n\
	ldrh r1, [r2]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0xa\n\
	mov r1, sb\n\
	strb r0, [r1, #2]\n\
	ldrb r1, [r6]\n\
	movs r0, #0x1f\n\
	ands r0, r1\n\
	strb r0, [r5]\n\
	ldrh r1, [r6]\n\
	movs r0, #0xf8\n\
	lsls r0, r0, #2\n\
	ands r0, r1\n\
	lsrs r0, r0, #5\n\
	strb r0, [r5, #1]\n\
	ldrh r1, [r6]\n\
	mov r0, sl\n\
	ands r0, r1\n\
	lsrs r0, r0, #0xa\n\
	strb r0, [r5, #2]\n\
	movs r4, #0\n\
	movs r0, #1\n\
	add ip, r0\n\
	adds r7, r2, #2\n\
	adds r1, r6, #2\n\
	mov r8, r1\n\
	adds r3, r5, #0\n\
_0807C056:\n\
	mov r1, sp\n\
	adds r0, r1, r4\n\
	ldrb r2, [r3]\n\
	ldrb r1, [r0]\n\
	adds r0, r2, #0\n\
	cmp r1, r0\n\
	bls _0807C078\n\
	adds r0, r2, #1\n\
	b _0807C07E\n\
	.align 2, 0\n\
_0807C068: .4byte 0x0857BC50\n\
_0807C06C: .4byte gNonGameplayRam\n\
_0807C070: .4byte 0x0000021A\n\
_0807C074: .4byte 0x050003E0\n\
_0807C078:\n\
	cmp r1, r0\n\
	bhs _0807C080\n\
	subs r0, r2, #1\n\
_0807C07E:\n\
	strb r0, [r3]\n\
_0807C080:\n\
	adds r3, #1\n\
	adds r4, #1\n\
	cmp r4, #2\n\
	ble _0807C056\n\
	ldrb r0, [r5]\n\
	ldrb r1, [r5, #1]\n\
	lsls r1, r1, #5\n\
	orrs r0, r1\n\
	ldrb r1, [r5, #2]\n\
	lsls r1, r1, #0xa\n\
	orrs r0, r1\n\
	strh r0, [r6]\n\
	adds r2, r7, #0\n\
	mov r6, r8\n\
	mov r0, ip\n\
	cmp r0, #0xf\n\
	ble _0807C006\n\
	ldr r1, _0807C0B4 @ =gNonGameplayRam\n\
	ldr r0, _0807C0B8 @ =0x0000021D\n\
	adds r3, r1, r0\n\
	ldrb r0, [r3]\n\
	cmp r0, #0x20\n\
	bls _0807C0BC\n\
	movs r0, #0\n\
	b _0807C0BE\n\
	.align 2, 0\n\
_0807C0B4: .4byte gNonGameplayRam\n\
_0807C0B8: .4byte 0x0000021D\n\
_0807C0BC:\n\
	adds r0, #1\n\
_0807C0BE:\n\
	strb r0, [r3]\n\
	add sp, #8\n\
	pop {r3, r4, r5}\n\
	mov r8, r3\n\
	mov sb, r4\n\
	mov sl, r5\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x0807C0D0
NAKED_FUNCTION
void NavigationConversationUpdateXParasitePopUp(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	bl unk_7c3b4\n\
	ldr r0, _0807C148 @ =0x0857BC50\n\
	mov ip, r0\n\
	ldr r3, _0807C14C @ =gNonGameplayRam\n\
	ldr r1, _0807C150 @ =0x0000021A\n\
	adds r6, r3, r1\n\
	ldrb r1, [r6]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	mov r2, ip\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1, #0x12]\n\
	lsls r2, r0, #0x1c\n\
	lsrs r0, r2, #0x1c\n\
	cmp r0, #8\n\
	beq _0807C0F8\n\
	b _0807C20C\n\
_0807C0F8:\n\
	ldr r7, [r1]\n\
	ldr r0, _0807C154 @ =0x0000021B\n\
	adds r2, r3, r0\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r4, r3, r1\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrb r1, [r2]\n\
	ldrb r0, [r0, #1]\n\
	cmp r1, r0\n\
	bhs _0807C114\n\
	b _0807C2F4\n\
_0807C114:\n\
	movs r5, #0\n\
	strb r5, [r2]\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
	ldrb r2, [r6]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #3\n\
	add r1, ip\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #4]\n\
	cmp r0, r1\n\
	blo _0807C134\n\
	strb r5, [r4]\n\
_0807C134:\n\
	ldr r2, _0807C158 @ =0x00000219\n\
	adds r0, r3, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807C160\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	ldr r0, _0807C15C @ =0x02004000\n\
	b _0807C17E\n\
	.align 2, 0\n\
_0807C148: .4byte 0x0857BC50\n\
_0807C14C: .4byte gNonGameplayRam\n\
_0807C150: .4byte 0x0000021A\n\
_0807C154: .4byte 0x0000021B\n\
_0807C158: .4byte 0x00000219\n\
_0807C15C: .4byte 0x02004000\n\
_0807C160:\n\
	cmp r0, #2\n\
	bne _0807C174\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	ldr r0, _0807C170 @ =0x02008000\n\
	b _0807C17E\n\
	.align 2, 0\n\
_0807C170: .4byte 0x02008000\n\
_0807C174:\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x12\n\
_0807C17E:\n\
	str r0, [r1]\n\
	ldr r3, _0807C1F0 @ =0x0857BC50\n\
	ldr r2, _0807C1F4 @ =gNonGameplayRam\n\
	ldr r1, _0807C1F8 @ =0x0000021A\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0, #0x11]\n\
	lsls r3, r0, #0x1c\n\
	lsrs r6, r0, #4\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrb r1, [r0]\n\
	movs r0, #3\n\
	ands r0, r1\n\
	lsls r4, r0, #8\n\
	lsrs r1, r1, #2\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #0xb\n\
	adds r4, r4, r0\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r2, r2, r0\n\
	ldr r0, [r2]\n\
	adds r5, r0, r4\n\
	str r5, [r2]\n\
	lsrs r4, r3, #0x1c\n\
	cmp r4, #0\n\
	bgt _0807C1CA\n\
	b _0807C2F4\n\
_0807C1CA:\n\
	ldr r3, _0807C1FC @ =0x040000D4\n\
	lsls r2, r4, #0xa\n\
	ldr r0, _0807C200 @ =0x06014300\n\
	adds r1, r2, r0\n\
	lsls r0, r6, #0xa\n\
	adds r1, r1, r0\n\
	adds r2, r2, r5\n\
	ldr r5, _0807C204 @ =0xFFFFFC00\n\
	ldr r6, _0807C208 @ =0x80000080\n\
_0807C1DC:\n\
	adds r1, r1, r5\n\
	adds r2, r2, r5\n\
	subs r4, #1\n\
	str r2, [r3]\n\
	str r1, [r3, #4]\n\
	str r6, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	cmp r4, #0\n\
	bgt _0807C1DC\n\
	b _0807C2F4\n\
	.align 2, 0\n\
_0807C1F0: .4byte 0x0857BC50\n\
_0807C1F4: .4byte gNonGameplayRam\n\
_0807C1F8: .4byte 0x0000021A\n\
_0807C1FC: .4byte 0x040000D4\n\
_0807C200: .4byte 0x06014300\n\
_0807C204: .4byte 0xFFFFFC00\n\
_0807C208: .4byte 0x80000080\n\
_0807C20C:\n\
	lsrs r0, r2, #0x1c\n\
	cmp r0, #4\n\
	bne _0807C2F4\n\
	ldr r7, [r1]\n\
	ldr r1, _0807C260 @ =0x0000021B\n\
	adds r2, r3, r1\n\
	movs r0, #0x87\n\
	lsls r0, r0, #2\n\
	adds r4, r3, r0\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrb r1, [r2]\n\
	ldrb r0, [r0, #1]\n\
	cmp r1, r0\n\
	blo _0807C2F4\n\
	movs r5, #0\n\
	strb r5, [r2]\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
	ldrb r2, [r6]\n\
	lsls r1, r2, #1\n\
	adds r1, r1, r2\n\
	lsls r1, r1, #3\n\
	add r1, ip\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #4]\n\
	cmp r0, r1\n\
	blo _0807C24C\n\
	strb r5, [r4]\n\
_0807C24C:\n\
	ldr r1, _0807C264 @ =0x00000219\n\
	adds r0, r3, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #1\n\
	bne _0807C26C\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	ldr r0, _0807C268 @ =0x02004000\n\
	b _0807C28A\n\
	.align 2, 0\n\
_0807C260: .4byte 0x0000021B\n\
_0807C264: .4byte 0x00000219\n\
_0807C268: .4byte 0x02004000\n\
_0807C26C:\n\
	cmp r0, #2\n\
	bne _0807C280\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	ldr r0, _0807C27C @ =0x02008000\n\
	b _0807C28A\n\
	.align 2, 0\n\
_0807C27C: .4byte 0x02008000\n\
_0807C280:\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x12\n\
_0807C28A:\n\
	str r0, [r1]\n\
	ldr r3, _0807C2FC @ =0x0857BC50\n\
	ldr r2, _0807C300 @ =gNonGameplayRam\n\
	ldr r1, _0807C304 @ =0x0000021A\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #3\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0, #0x11]\n\
	lsls r3, r0, #0x1c\n\
	lsrs r6, r0, #4\n\
	movs r1, #0x87\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r7\n\
	ldrb r1, [r0]\n\
	movs r0, #7\n\
	ands r0, r1\n\
	lsls r4, r0, #7\n\
	lsrs r1, r1, #3\n\
	lsls r1, r1, #0xc\n\
	adds r4, r4, r1\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r2, r2, r0\n\
	ldr r0, [r2]\n\
	adds r5, r0, r4\n\
	str r5, [r2]\n\
	lsrs r4, r3, #0x1c\n\
	cmp r4, #0\n\
	ble _0807C2F4\n\
	ldr r3, _0807C308 @ =0x040000D4\n\
	lsls r2, r4, #0xa\n\
	ldr r0, _0807C30C @ =0x06014340\n\
	adds r1, r2, r0\n\
	lsls r0, r6, #0xa\n\
	adds r1, r1, r0\n\
	adds r2, r2, r5\n\
	ldr r5, _0807C310 @ =0xFFFFFC00\n\
	ldr r6, _0807C314 @ =0x80000040\n\
_0807C2E2:\n\
	adds r1, r1, r5\n\
	adds r2, r2, r5\n\
	subs r4, #1\n\
	str r2, [r3]\n\
	str r1, [r3, #4]\n\
	str r6, [r3, #8]\n\
	ldr r0, [r3, #8]\n\
	cmp r4, #0\n\
	bgt _0807C2E2\n\
_0807C2F4:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807C2FC: .4byte 0x0857BC50\n\
_0807C300: .4byte gNonGameplayRam\n\
_0807C304: .4byte 0x0000021A\n\
_0807C308: .4byte 0x040000D4\n\
_0807C30C: .4byte 0x06014340\n\
_0807C310: .4byte 0xFFFFFC00\n\
_0807C314: .4byte 0x80000040\n\
    .syntax divided\n");
}

/**
 * @brief 7c318 | 9c | Clears the navigation conversation pop-up graphics
 * 
 */
void NavigationConversationClearPopUpGraphics(void)
{
    s32 i;
    u8* dst;

    i = 5;
    dst = VRAM_OBJ + 0x5700;
    do
    {
        BitFill(3, USHORT_MAX | (USHORT_MAX << 16), dst, 0x100, 32);
        dst -= 0x400;
        i--;
    } while (i >= 0);

    DMA3_FILL_32(0, PALRAM_OBJ + PAL_ROW_SIZE * 15, PAL_ROW_SIZE);

    if (PAUSE_SCREEN_DATA.unk_21A == 3)
        SoundStop(SOUND_125);

    PAUSE_SCREEN_DATA.currentPopUp = 0;
    PAUSE_SCREEN_DATA.unk_21C = 0;
    PAUSE_SCREEN_DATA.unk_21B = 0;
    PAUSE_SCREEN_DATA.unk_21D = 0;
    PAUSE_SCREEN_DATA.unk_219++;
}

// 0x0807C3B4
void unk_7c3b4(void)
{
    const u16* pColor;
    const u16* pPalette;

    if (sNavConversationPopUps[PAUSE_SCREEN_DATA.unk_21A].flashingPaletteDelay == 0)
        return;

    PAUSE_SCREEN_DATA.unk_229++;
    if (PAUSE_SCREEN_DATA.unk_229 < sNavConversationPopUps[PAUSE_SCREEN_DATA.unk_21A].flashingPaletteDelay)
        return;

    PAUSE_SCREEN_DATA.unk_229 = 0;
    pColor = &sNavConversationPopUps[PAUSE_SCREEN_DATA.unk_21A].pFlashingPalette[PAUSE_SCREEN_DATA.unk_228];
    if (*pColor == 0)
    {
        PAUSE_SCREEN_DATA.unk_228 = 0;
        pColor = sNavConversationPopUps[PAUSE_SCREEN_DATA.unk_21A].pFlashingPalette;
    }

    *(u16*)(PALRAM_OBJ + PAL_ROW_SIZE * 15 + 15 * sizeof(u16)) = *pColor;

    PAUSE_SCREEN_DATA.unk_228++;
    if (PAUSE_SCREEN_DATA.unk_228 > 15)
        PAUSE_SCREEN_DATA.unk_228 = 0;
}

// 0x0807C440
NAKED_FUNCTION
void unk_7c440(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	ldr r2, _0807C518 @ =gNonGameplayRam\n\
	ldr r0, _0807C51C @ =0x00000225\n\
	adds r5, r2, r0\n\
	ldrb r0, [r5]\n\
	adds r0, #1\n\
	movs r7, #0\n\
	strb r0, [r5]\n\
	ldr r3, _0807C520 @ =0x0857BEB4\n\
	movs r1, #0x89\n\
	lsls r1, r1, #2\n\
	adds r4, r2, r1\n\
	ldrb r1, [r4]\n\
	adds r1, r1, r3\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	adds r6, r2, #0\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _0807C4B0\n\
	strb r7, [r5]\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bls _0807C47A\n\
	strb r7, [r4]\n\
_0807C47A:\n\
	movs r3, #0xa0\n\
	lsls r3, r3, #0x13\n\
	ldr r1, _0807C524 @ =0x0857BCD4\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	strh r0, [r3, #0x24]\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r1\n\
	ldrh r0, [r0]\n\
	strh r0, [r3, #0x26]\n\
	adds r1, r3, #0\n\
	adds r1, #0x44\n\
	ldr r2, _0807C528 @ =0x0857BCF4\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
_0807C4B0:\n\
	adds r1, r6, #0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	beq _0807C59C\n\
	cmp r0, #1\n\
	bne _0807C53C\n\
	ldr r6, _0807C52C @ =0x0000022D\n\
	adds r3, r1, r6\n\
	ldrb r0, [r3]\n\
	adds r0, #1\n\
	movs r5, #0\n\
	strb r0, [r3]\n\
	ldr r2, _0807C530 @ =0x0857BEB8\n\
	subs r6, #1\n\
	adds r4, r1, r6\n\
	ldrb r1, [r4]\n\
	adds r1, r1, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _0807C59C\n\
	strb r5, [r3]\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #3\n\
	bls _0807C4EE\n\
	strb r5, [r4]\n\
_0807C4EE:\n\
	ldr r3, _0807C534 @ =0x05000138\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #4\n\
	adds r0, #0xc\n\
	adds r2, r0, #0\n\
	movs r1, #0\n\
	ldr r4, _0807C538 @ =0x0857BD34\n\
_0807C4FC:\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r3]\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	adds r3, #2\n\
	cmp r1, #3\n\
	bls _0807C4FC\n\
	b _0807C59C\n\
	.align 2, 0\n\
_0807C518: .4byte gNonGameplayRam\n\
_0807C51C: .4byte 0x00000225\n\
_0807C520: .4byte 0x0857BEB4\n\
_0807C524: .4byte 0x0857BCD4\n\
_0807C528: .4byte 0x0857BCF4\n\
_0807C52C: .4byte 0x0000022D\n\
_0807C530: .4byte 0x0857BEB8\n\
_0807C534: .4byte 0x05000138\n\
_0807C538: .4byte 0x0857BD34\n\
_0807C53C:\n\
	cmp r0, #2\n\
	bne _0807C59C\n\
	ldr r0, _0807C5A4 @ =0x0000022D\n\
	adds r3, r6, r0\n\
	ldrb r0, [r3]\n\
	adds r0, #1\n\
	movs r5, #0\n\
	strb r0, [r3]\n\
	ldr r2, _0807C5A8 @ =0x0857BEBC\n\
	movs r1, #0x8b\n\
	lsls r1, r1, #2\n\
	adds r4, r6, r1\n\
	ldrb r1, [r4]\n\
	adds r1, r1, r2\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	blo _0807C59C\n\
	strb r5, [r3]\n\
	ldrb r0, [r4]\n\
	adds r0, #1\n\
	strb r0, [r4]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _0807C574\n\
	strb r5, [r4]\n\
_0807C574:\n\
	ldr r3, _0807C5AC @ =0x05000194\n\
	ldrb r0, [r4]\n\
	lsls r0, r0, #4\n\
	adds r0, #0xa\n\
	adds r2, r0, #0\n\
	movs r1, #0\n\
	ldr r4, _0807C5B0 @ =0x0857BDB4\n\
_0807C582:\n\
	lsls r0, r2, #1\n\
	adds r0, r0, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r3]\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r1, r0, #0x10\n\
	adds r0, r2, #1\n\
	lsls r0, r0, #0x10\n\
	lsrs r2, r0, #0x10\n\
	adds r3, #2\n\
	cmp r1, #5\n\
	bls _0807C582\n\
_0807C59C:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807C5A4: .4byte 0x0000022D\n\
_0807C5A8: .4byte 0x0857BEBC\n\
_0807C5AC: .4byte 0x05000194\n\
_0807C5B0: .4byte 0x0857BDB4\n\
    .syntax divided\n");
}

/**
 * @brief 7c5b4 | 7c | Loads the graphics needed by special navigation conversations
 * 
 */
void NavigationConversationLoadSpecialGraphics(void)
{
    if (PAUSE_SCREEN_DATA.conversationNumber == NAV_CONVO_GO_TO_OPERATIONS_ROOM)
    {
        LZ77UncompVram((const void*)0x857C0C4, EWRAM_BASE);
        LZ77UncompVram((const void*)0x857FCA0, EWRAM_BASE + 0x6000);
        LZ77UncompVram((const void*)0x8580238, EWRAM_BASE + 0x6800);
        LZ77UncompVram((const void*)0x85807D0, EWRAM_BASE + 0x7000);
        LZ77UncompVram((const void*)0x8580D68, EWRAM_BASE + 0x7800);
    }
    else if (PAUSE_SCREEN_DATA.conversationNumber == NAV_CONVO_FIND_SECURITY_ROOM_AND_DOWNLOAD_BOMBS)
    {
        LZ77UncompVram(sSaXCloseUpGfx, EWRAM_BASE);
    }
}

// 0x0807C630
NAKED_FUNCTION
void unk_7c630(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	sub sp, #4\n\
	ldr r1, _0807C650 @ =gNonGameplayRam\n\
	ldr r2, _0807C654 @ =0x00000265\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	adds r4, r1, #0\n\
	cmp r0, #0x25\n\
	bls _0807C646\n\
	bl _0807CE56\n\
_0807C646:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807C658 @ =_0807C65C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807C650: .4byte gNonGameplayRam\n\
_0807C654: .4byte 0x00000265\n\
_0807C658: .4byte _0807C65C\n\
_0807C65C: @ jump table\n\
	.4byte _0807C6F4 @ case 0\n\
	.4byte _0807C770 @ case 1\n\
	.4byte _0807C79C @ case 2\n\
	.4byte _0807C7B8 @ case 3\n\
	.4byte _0807C7E4 @ case 4\n\
	.4byte _0807C810 @ case 5\n\
	.4byte _0807C82C @ case 6\n\
	.4byte _0807C858 @ case 7\n\
	.4byte _0807C884 @ case 8\n\
	.4byte _0807C8A0 @ case 9\n\
	.4byte _0807C8CC @ case 10\n\
	.4byte _0807C924 @ case 11\n\
	.4byte _0807C940 @ case 12\n\
	.4byte _0807C970 @ case 13\n\
	.4byte _0807C99C @ case 14\n\
	.4byte _0807C9C8 @ case 15\n\
	.4byte _0807C9F0 @ case 16\n\
	.4byte _0807CA10 @ case 17\n\
	.4byte _0807CA50 @ case 18\n\
	.4byte _0807CA90 @ case 19\n\
	.4byte _0807CAD0 @ case 20\n\
	.4byte _0807CAFC @ case 21\n\
	.4byte _0807CB20 @ case 22\n\
	.4byte _0807CB58 @ case 23\n\
	.4byte _0807CBB0 @ case 24\n\
	.4byte _0807CBE0 @ case 25\n\
	.4byte _0807CC18 @ case 26\n\
	.4byte _0807CC4C @ case 27\n\
	.4byte _0807CC70 @ case 28\n\
	.4byte _0807CC9C @ case 29\n\
	.4byte _0807CCC8 @ case 30\n\
	.4byte _0807CCE4 @ case 31\n\
	.4byte _0807CD30 @ case 32\n\
	.4byte _0807CD5C @ case 33\n\
	.4byte _0807CD78 @ case 34\n\
	.4byte _0807CDA4 @ case 35\n\
	.4byte _0807CDD0 @ case 36\n\
	.4byte _0807CE10 @ case 37\n\
_0807C6F4:\n\
	movs r0, #0x80\n\
	lsls r0, r0, #0x13\n\
	ldrh r1, [r0]\n\
	ldr r3, _0807C74C @ =0x0000026A\n\
	adds r0, r4, r3\n\
	movs r2, #0\n\
	strh r1, [r0]\n\
	ldr r0, _0807C750 @ =0x0400000E\n\
	ldrh r1, [r0]\n\
	adds r3, #2\n\
	adds r0, r4, r3\n\
	strh r1, [r0]\n\
	ldr r0, _0807C754 @ =0x0400000C\n\
	ldrh r1, [r0]\n\
	adds r3, #2\n\
	adds r0, r4, r3\n\
	strh r1, [r0]\n\
	ldr r0, _0807C758 @ =0x04000050\n\
	ldrh r1, [r0]\n\
	adds r3, #2\n\
	adds r0, r4, r3\n\
	strh r1, [r0]\n\
	ldr r0, _0807C75C @ =0x04000052\n\
	ldrh r1, [r0]\n\
	adds r3, #2\n\
	adds r0, r4, r3\n\
	strh r1, [r0]\n\
	movs r1, #0x9a\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	strh r2, [r0]\n\
	ldr r1, _0807C760 @ =0x040000D4\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1]\n\
	ldr r0, _0807C764 @ =0x02035000\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807C768 @ =0x80000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _0807C76C @ =0x00000265\n\
	adds r1, r4, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C74C: .4byte 0x0000026A\n\
_0807C750: .4byte 0x0400000E\n\
_0807C754: .4byte 0x0400000C\n\
_0807C758: .4byte 0x04000050\n\
_0807C75C: .4byte 0x04000052\n\
_0807C760: .4byte 0x040000D4\n\
_0807C764: .4byte 0x02035000\n\
_0807C768: .4byte 0x80000100\n\
_0807C76C: .4byte 0x00000265\n\
_0807C770:\n\
	ldr r1, _0807C78C @ =0x06004000\n\
	ldr r2, _0807C790 @ =0x02008000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C794 @ =gNonGameplayRam\n\
	ldr r3, _0807C798 @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C78C: .4byte 0x06004000\n\
_0807C790: .4byte 0x02008000\n\
_0807C794: .4byte gNonGameplayRam\n\
_0807C798: .4byte 0x00000265\n\
_0807C79C:\n\
	ldr r1, _0807C7B0 @ =0x06005000\n\
	ldr r2, _0807C7B4 @ =0x02009000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807C7B0: .4byte 0x06005000\n\
_0807C7B4: .4byte 0x02009000\n\
_0807C7B8:\n\
	ldr r1, _0807C7D4 @ =0x06006000\n\
	ldr r2, _0807C7D8 @ =0x0200A000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C7DC @ =gNonGameplayRam\n\
	ldr r2, _0807C7E0 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C7D4: .4byte 0x06006000\n\
_0807C7D8: .4byte 0x0200A000\n\
_0807C7DC: .4byte gNonGameplayRam\n\
_0807C7E0: .4byte 0x00000265\n\
_0807C7E4:\n\
	ldr r1, _0807C800 @ =0x06007000\n\
	ldr r2, _0807C804 @ =0x0200B000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C808 @ =gNonGameplayRam\n\
	ldr r3, _0807C80C @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C800: .4byte 0x06007000\n\
_0807C804: .4byte 0x0200B000\n\
_0807C808: .4byte gNonGameplayRam\n\
_0807C80C: .4byte 0x00000265\n\
_0807C810:\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x12\n\
	ldr r2, _0807C828 @ =0x06004000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807C828: .4byte 0x06004000\n\
_0807C82C:\n\
	ldr r1, _0807C848 @ =0x02001000\n\
	ldr r2, _0807C84C @ =0x06005000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C850 @ =gNonGameplayRam\n\
	ldr r2, _0807C854 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C848: .4byte 0x02001000\n\
_0807C84C: .4byte 0x06005000\n\
_0807C850: .4byte gNonGameplayRam\n\
_0807C854: .4byte 0x00000265\n\
_0807C858:\n\
	ldr r1, _0807C874 @ =0x02002000\n\
	ldr r2, _0807C878 @ =0x06006000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C87C @ =gNonGameplayRam\n\
	ldr r3, _0807C880 @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C874: .4byte 0x02002000\n\
_0807C878: .4byte 0x06006000\n\
_0807C87C: .4byte gNonGameplayRam\n\
_0807C880: .4byte 0x00000265\n\
_0807C884:\n\
	ldr r1, _0807C898 @ =0x02003000\n\
	ldr r2, _0807C89C @ =0x06007000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807C898: .4byte 0x02003000\n\
_0807C89C: .4byte 0x06007000\n\
_0807C8A0:\n\
	ldr r1, _0807C8BC @ =0x02004000\n\
	ldr r2, _0807C8C0 @ =0x06008000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C8C4 @ =gNonGameplayRam\n\
	ldr r2, _0807C8C8 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C8BC: .4byte 0x02004000\n\
_0807C8C0: .4byte 0x06008000\n\
_0807C8C4: .4byte gNonGameplayRam\n\
_0807C8C8: .4byte 0x00000265\n\
_0807C8CC:\n\
	ldr r1, _0807C8F8 @ =0x02005000\n\
	ldr r2, _0807C8FC @ =0x06009000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r4, #0x10\n\
	str r4, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r2, _0807C900 @ =gNonGameplayRam\n\
	movs r3, #0x88\n\
	lsls r3, r3, #2\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0x35\n\
	bne _0807C908\n\
	ldr r0, _0807C904 @ =0x00000265\n\
	adds r1, r2, r0\n\
	movs r0, #0xd\n\
	strb r0, [r1]\n\
	b _0807CE56\n\
	.align 2, 0\n\
_0807C8F8: .4byte 0x02005000\n\
_0807C8FC: .4byte 0x06009000\n\
_0807C900: .4byte gNonGameplayRam\n\
_0807C904: .4byte 0x00000265\n\
_0807C908:\n\
	ldr r1, _0807C918 @ =gWrittenToBldalpha_Evb\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0807C91C @ =gWrittenToBldalpha_Eva\n\
	strh r4, [r0]\n\
	ldr r3, _0807C920 @ =0x00000265\n\
	adds r1, r2, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C918: .4byte gWrittenToBldalpha_Evb\n\
_0807C91C: .4byte gWrittenToBldalpha_Eva\n\
_0807C920: .4byte 0x00000265\n\
_0807C924:\n\
	ldr r1, _0807C938 @ =0x02006000\n\
	ldr r2, _0807C93C @ =0x0600A000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807C938: .4byte 0x02006000\n\
_0807C93C: .4byte 0x0600A000\n\
_0807C940:\n\
	ldr r1, _0807C960 @ =0x02007000\n\
	ldr r2, _0807C964 @ =0x0600B000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r0, _0807C968 @ =gNonGameplayRam\n\
	ldr r1, _0807C96C @ =0x00000265\n\
	adds r0, r0, r1\n\
	movs r1, #0x15\n\
	strb r1, [r0]\n\
	b _0807CE56\n\
	.align 2, 0\n\
_0807C960: .4byte 0x02007000\n\
_0807C964: .4byte 0x0600B000\n\
_0807C968: .4byte gNonGameplayRam\n\
_0807C96C: .4byte 0x00000265\n\
_0807C970:\n\
	ldr r1, _0807C98C @ =0x02006000\n\
	ldr r2, _0807C990 @ =0x0600A000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C994 @ =gNonGameplayRam\n\
	ldr r2, _0807C998 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C98C: .4byte 0x02006000\n\
_0807C990: .4byte 0x0600A000\n\
_0807C994: .4byte gNonGameplayRam\n\
_0807C998: .4byte 0x00000265\n\
_0807C99C:\n\
	ldr r1, _0807C9B8 @ =0x02007000\n\
	ldr r2, _0807C9BC @ =0x0600B000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807C9C0 @ =gNonGameplayRam\n\
	ldr r3, _0807C9C4 @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807C9B8: .4byte 0x02007000\n\
_0807C9BC: .4byte 0x0600B000\n\
_0807C9C0: .4byte gNonGameplayRam\n\
_0807C9C4: .4byte 0x00000265\n\
_0807C9C8:\n\
	ldr r1, _0807C9E0 @ =0x040000D4\n\
	ldr r0, _0807C9E4 @ =0x0857BEC4\n\
	str r0, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807C9E8 @ =0x80000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _0807C9EC @ =PauseScreenVBlank_Unused\n\
	b _0807CDE4\n\
	.align 2, 0\n\
_0807C9E0: .4byte 0x040000D4\n\
_0807C9E4: .4byte 0x0857BEC4\n\
_0807C9E8: .4byte 0x80000100\n\
_0807C9EC: .4byte PauseScreenVBlank_Unused\n\
_0807C9F0:\n\
	ldr r1, _0807CA08 @ =0x0300000A\n\
	ldr r2, _0807CA0C @ =0x00001407\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r3, #0x9a\n\
	lsls r3, r3, #2\n\
	adds r2, r4, r3\n\
	ldrh r1, [r2]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #4\n\
	b _0807CB7C\n\
	.align 2, 0\n\
_0807CA08: .4byte 0x0300000A\n\
_0807CA0C: .4byte 0x00001407\n\
_0807CA10:\n\
	ldr r3, _0807CA3C @ =0x00000266\n\
	adds r2, r4, r3\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r1, _0807CA40 @ =0x0879C17C\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bhi _0807CA28\n\
	b _0807CE56\n\
_0807CA28:\n\
	ldr r1, _0807CA44 @ =0x0300000A\n\
	ldr r3, _0807CA48 @ =0x00001507\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0807CA4C @ =0x00000265\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _0807CC38\n\
	.align 2, 0\n\
_0807CA3C: .4byte 0x00000266\n\
_0807CA40: .4byte 0x0879C17C\n\
_0807CA44: .4byte 0x0300000A\n\
_0807CA48: .4byte 0x00001507\n\
_0807CA4C: .4byte 0x00000265\n\
_0807CA50:\n\
	ldr r1, _0807CA7C @ =0x00000266\n\
	adds r2, r4, r1\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r1, _0807CA80 @ =0x0879C17C\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #1]\n\
	cmp r0, r1\n\
	bhi _0807CA68\n\
	b _0807CE56\n\
_0807CA68:\n\
	ldr r1, _0807CA84 @ =0x0300000A\n\
	ldr r3, _0807CA88 @ =0x00001607\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0807CA8C @ =0x00000265\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _0807CC38\n\
	.align 2, 0\n\
_0807CA7C: .4byte 0x00000266\n\
_0807CA80: .4byte 0x0879C17C\n\
_0807CA84: .4byte 0x0300000A\n\
_0807CA88: .4byte 0x00001607\n\
_0807CA8C: .4byte 0x00000265\n\
_0807CA90:\n\
	ldr r1, _0807CABC @ =0x00000266\n\
	adds r2, r4, r1\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r1, _0807CAC0 @ =0x0879C17C\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #2]\n\
	cmp r0, r1\n\
	bhi _0807CAA8\n\
	b _0807CE56\n\
_0807CAA8:\n\
	ldr r1, _0807CAC4 @ =0x0300000A\n\
	ldr r3, _0807CAC8 @ =0x00001707\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	ldr r0, _0807CACC @ =0x00000265\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _0807CC38\n\
	.align 2, 0\n\
_0807CABC: .4byte 0x00000266\n\
_0807CAC0: .4byte 0x0879C17C\n\
_0807CAC4: .4byte 0x0300000A\n\
_0807CAC8: .4byte 0x00001707\n\
_0807CACC: .4byte 0x00000265\n\
_0807CAD0:\n\
	ldr r1, _0807CAF0 @ =0x00000266\n\
	adds r2, r4, r1\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r1, _0807CAF4 @ =0x0879C17C\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #3]\n\
	cmp r0, r1\n\
	bhi _0807CAE8\n\
	b _0807CE56\n\
_0807CAE8:\n\
	ldr r3, _0807CAF8 @ =0x00000265\n\
	adds r0, r4, r3\n\
	b _0807CC34\n\
	.align 2, 0\n\
_0807CAF0: .4byte 0x00000266\n\
_0807CAF4: .4byte 0x0879C17C\n\
_0807CAF8: .4byte 0x00000265\n\
_0807CAFC:\n\
	ldr r0, _0807CB10 @ =0x087338C0\n\
	ldr r1, _0807CB14 @ =0x06007800\n\
	bl LZ77UncompVram\n\
	ldr r0, _0807CB18 @ =0x08733D58\n\
	ldr r1, _0807CB1C @ =0x0600B800\n\
	bl LZ77UncompVram\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807CB10: .4byte 0x087338C0\n\
_0807CB14: .4byte 0x06007800\n\
_0807CB18: .4byte 0x08733D58\n\
_0807CB1C: .4byte 0x0600B800\n\
_0807CB20:\n\
	ldr r1, _0807CB40 @ =0x040000D4\n\
	ldr r0, _0807CB44 @ =0x0872F0E0\n\
	str r0, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807CB48 @ =0x80000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _0807CB4C @ =PauseScreenVBlank_Unused\n\
	bl CallbackSetVBlank\n\
	ldr r1, _0807CB50 @ =gNonGameplayRam\n\
	ldr r2, _0807CB54 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CB40: .4byte 0x040000D4\n\
_0807CB44: .4byte 0x0872F0E0\n\
_0807CB48: .4byte 0x80000100\n\
_0807CB4C: .4byte PauseScreenVBlank_Unused\n\
_0807CB50: .4byte gNonGameplayRam\n\
_0807CB54: .4byte 0x00000265\n\
_0807CB58:\n\
	ldr r1, _0807CB98 @ =0x0400000C\n\
	ldr r3, _0807CB9C @ =0x00000F06\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _0807CBA0 @ =0x00001707\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	ldr r3, _0807CBA4 @ =0x00000844\n\
	adds r0, r3, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x9a\n\
	lsls r0, r0, #2\n\
	adds r2, r4, r0\n\
	ldrh r1, [r2]\n\
	movs r3, #0xc0\n\
	lsls r3, r3, #4\n\
_0807CB7C:\n\
	adds r0, r3, #0\n\
	movs r3, #0\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r0, _0807CBA8 @ =0x00000265\n\
	adds r1, r4, r0\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	ldr r1, _0807CBAC @ =0x00000266\n\
	adds r0, r4, r1\n\
	strb r3, [r0]\n\
	b _0807CE56\n\
	.align 2, 0\n\
_0807CB98: .4byte 0x0400000C\n\
_0807CB9C: .4byte 0x00000F06\n\
_0807CBA0: .4byte 0x00001707\n\
_0807CBA4: .4byte 0x00000844\n\
_0807CBA8: .4byte 0x00000265\n\
_0807CBAC: .4byte 0x00000266\n\
_0807CBB0:\n\
	ldr r3, _0807CBD4 @ =0x00000266\n\
	adds r2, r4, r3\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r1, _0807CBD8 @ =0x0873421C\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1]\n\
	cmp r0, r1\n\
	bhi _0807CBC8\n\
	b _0807CE56\n\
_0807CBC8:\n\
	ldr r1, _0807CBDC @ =0x00000265\n\
	adds r0, r4, r1\n\
	ldrb r1, [r0]\n\
	adds r1, #1\n\
	b _0807CC36\n\
	.align 2, 0\n\
_0807CBD4: .4byte 0x00000266\n\
_0807CBD8: .4byte 0x0873421C\n\
_0807CBDC: .4byte 0x00000265\n\
_0807CBE0:\n\
	ldr r1, _0807CBF8 @ =gWrittenToBldalpha_Eva\n\
	ldrh r0, [r1]\n\
	adds r2, r0, #0\n\
	cmp r2, #0\n\
	bne _0807CC04\n\
	ldr r3, _0807CBFC @ =0x00000265\n\
	adds r0, r4, r3\n\
	ldrb r1, [r0]\n\
	adds r1, #1\n\
	strb r1, [r0]\n\
	ldr r1, _0807CC00 @ =0x00000266\n\
	b _0807CE52\n\
	.align 2, 0\n\
_0807CBF8: .4byte gWrittenToBldalpha_Eva\n\
_0807CBFC: .4byte 0x00000265\n\
_0807CC00: .4byte 0x00000266\n\
_0807CC04:\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	ldr r2, _0807CC14 @ =gWrittenToBldalpha_Evb\n\
	movs r1, #0x10\n\
	subs r1, r1, r0\n\
	strh r1, [r2]\n\
	b _0807CE56\n\
	.align 2, 0\n\
_0807CC14: .4byte gWrittenToBldalpha_Evb\n\
_0807CC18:\n\
	ldr r3, _0807CC40 @ =0x00000266\n\
	adds r2, r4, r3\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	ldr r1, _0807CC44 @ =0x0873421C\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	ldrb r1, [r1, #1]\n\
	cmp r0, r1\n\
	bhi _0807CC30\n\
	b _0807CE56\n\
_0807CC30:\n\
	ldr r1, _0807CC48 @ =0x00000265\n\
	adds r0, r4, r1\n\
_0807CC34:\n\
	movs r1, #0x1b\n\
_0807CC36:\n\
	strb r1, [r0]\n\
_0807CC38:\n\
	movs r0, #0\n\
	strb r0, [r2]\n\
	b _0807CE56\n\
	.align 2, 0\n\
_0807CC40: .4byte 0x00000266\n\
_0807CC44: .4byte 0x0873421C\n\
_0807CC48: .4byte 0x00000265\n\
_0807CC4C:\n\
	movs r2, #0x9a\n\
	lsls r2, r2, #2\n\
	adds r1, r4, r2\n\
	movs r2, #0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r3, _0807CC68 @ =0x00000265\n\
	adds r1, r4, r3\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	ldr r1, _0807CC6C @ =0x00000266\n\
	b _0807CE52\n\
	.align 2, 0\n\
_0807CC68: .4byte 0x00000265\n\
_0807CC6C: .4byte 0x00000266\n\
_0807CC70:\n\
	ldr r1, _0807CC8C @ =0x08561FA8\n\
	ldr r2, _0807CC90 @ =0x06008000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807CC94 @ =gNonGameplayRam\n\
	ldr r2, _0807CC98 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CC8C: .4byte 0x08561FA8\n\
_0807CC90: .4byte 0x06008000\n\
_0807CC94: .4byte gNonGameplayRam\n\
_0807CC98: .4byte 0x00000265\n\
_0807CC9C:\n\
	ldr r1, _0807CCB8 @ =0x08562FA8\n\
	ldr r2, _0807CCBC @ =0x06009000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807CCC0 @ =gNonGameplayRam\n\
	ldr r3, _0807CCC4 @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CCB8: .4byte 0x08562FA8\n\
_0807CCBC: .4byte 0x06009000\n\
_0807CCC0: .4byte gNonGameplayRam\n\
_0807CCC4: .4byte 0x00000265\n\
_0807CCC8:\n\
	ldr r1, _0807CCDC @ =0x08563FA8\n\
	ldr r2, _0807CCE0 @ =0x0600A000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807CCDC: .4byte 0x08563FA8\n\
_0807CCE0: .4byte 0x0600A000\n\
_0807CCE4:\n\
	ldr r1, _0807CD10 @ =0x08564FA8\n\
	ldr r2, _0807CD14 @ =0x0600B000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #4\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807CD18 @ =0x040000D4\n\
	ldr r0, _0807CD1C @ =0x06009800\n\
	str r0, [r1]\n\
	ldr r0, _0807CD20 @ =0x06009400\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807CD24 @ =0x80000200\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r1, _0807CD28 @ =gNonGameplayRam\n\
	ldr r2, _0807CD2C @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CD10: .4byte 0x08564FA8\n\
_0807CD14: .4byte 0x0600B000\n\
_0807CD18: .4byte 0x040000D4\n\
_0807CD1C: .4byte 0x06009800\n\
_0807CD20: .4byte 0x06009400\n\
_0807CD24: .4byte 0x80000200\n\
_0807CD28: .4byte gNonGameplayRam\n\
_0807CD2C: .4byte 0x00000265\n\
_0807CD30:\n\
	ldr r1, _0807CD4C @ =0x02008000\n\
	ldr r2, _0807CD50 @ =0x06004000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807CD54 @ =gNonGameplayRam\n\
	ldr r3, _0807CD58 @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CD4C: .4byte 0x02008000\n\
_0807CD50: .4byte 0x06004000\n\
_0807CD54: .4byte gNonGameplayRam\n\
_0807CD58: .4byte 0x00000265\n\
_0807CD5C:\n\
	ldr r1, _0807CD70 @ =0x02009000\n\
	ldr r2, _0807CD74 @ =0x06005000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	b _0807CDE8\n\
	.align 2, 0\n\
_0807CD70: .4byte 0x02009000\n\
_0807CD74: .4byte 0x06005000\n\
_0807CD78:\n\
	ldr r1, _0807CD94 @ =0x0200A000\n\
	ldr r2, _0807CD98 @ =0x06006000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807CD9C @ =gNonGameplayRam\n\
	ldr r2, _0807CDA0 @ =0x00000265\n\
	adds r1, r1, r2\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CD94: .4byte 0x0200A000\n\
_0807CD98: .4byte 0x06006000\n\
_0807CD9C: .4byte gNonGameplayRam\n\
_0807CDA0: .4byte 0x00000265\n\
_0807CDA4:\n\
	ldr r1, _0807CDC0 @ =0x0200B000\n\
	ldr r2, _0807CDC4 @ =0x06007000\n\
	movs r3, #0x80\n\
	lsls r3, r3, #5\n\
	movs r0, #0x10\n\
	str r0, [sp]\n\
	movs r0, #3\n\
	bl DmaTransfer\n\
	ldr r1, _0807CDC8 @ =gNonGameplayRam\n\
	ldr r3, _0807CDCC @ =0x00000265\n\
	adds r1, r1, r3\n\
	b _0807CDEE\n\
	.align 2, 0\n\
_0807CDC0: .4byte 0x0200B000\n\
_0807CDC4: .4byte 0x06007000\n\
_0807CDC8: .4byte gNonGameplayRam\n\
_0807CDCC: .4byte 0x00000265\n\
_0807CDD0:\n\
	ldr r1, _0807CDF8 @ =0x040000D4\n\
	ldr r0, _0807CDFC @ =0x02035000\n\
	str r0, [r1]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807CE00 @ =0x80000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r0, _0807CE04 @ =PauseScreenVBlank\n\
_0807CDE4:\n\
	bl CallbackSetVBlank\n\
_0807CDE8:\n\
	ldr r1, _0807CE08 @ =gNonGameplayRam\n\
	ldr r0, _0807CE0C @ =0x00000265\n\
	adds r1, r1, r0\n\
_0807CDEE:\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	strb r0, [r1]\n\
	b _0807CE56\n\
	.align 2, 0\n\
_0807CDF8: .4byte 0x040000D4\n\
_0807CDFC: .4byte 0x02035000\n\
_0807CE00: .4byte 0x80000100\n\
_0807CE04: .4byte PauseScreenVBlank\n\
_0807CE08: .4byte gNonGameplayRam\n\
_0807CE0C: .4byte 0x00000265\n\
_0807CE10:\n\
	ldr r1, _0807CE60 @ =0x0400000E\n\
	movs r2, #0x9b\n\
	lsls r2, r2, #2\n\
	adds r0, r4, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	ldr r3, _0807CE64 @ =0x0000026E\n\
	adds r0, r4, r3\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #0x44\n\
	adds r2, #4\n\
	adds r0, r4, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	adds r3, #4\n\
	adds r0, r4, r3\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	ldr r1, _0807CE68 @ =0x0000026A\n\
	adds r0, r4, r1\n\
	ldrh r1, [r0]\n\
	subs r2, #8\n\
	adds r0, r4, r2\n\
	movs r2, #0\n\
	strh r1, [r0]\n\
	subs r3, #0xd\n\
	adds r0, r4, r3\n\
	strb r2, [r0]\n\
	movs r1, #0x99\n\
	lsls r1, r1, #2\n\
_0807CE52:\n\
	adds r0, r4, r1\n\
	strb r2, [r0]\n\
_0807CE56:\n\
	add sp, #4\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807CE60: .4byte 0x0400000E\n\
_0807CE64: .4byte 0x0000026E\n\
_0807CE68: .4byte 0x0000026A\n\
    .syntax divided\n");
}

// 0x0807CE6C
NAKED_FUNCTION
void unk_7ce6c(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #4\n\
	ldr r3, _0807CEBC @ =gCurrentArea\n\
	ldrb r0, [r3]\n\
	cmp r0, #6\n\
	bls _0807CE7A\n\
	b _0807CF8A\n\
_0807CE7A:\n\
	ldr r2, _0807CEC0 @ =gNonGameplayRam\n\
	movs r0, #0x90\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	ldr r0, _0807CEC4 @ =0x08581500\n\
	ldm r0!, {r4, r5, r6}\n\
	stm r1!, {r4, r5, r6}\n\
	ldr r0, [r0]\n\
	str r0, [r1]\n\
	ldrb r0, [r2]\n\
	adds r6, r2, #0\n\
	cmp r0, #0\n\
	beq _0807CF8A\n\
	ldr r0, _0807CEC8 @ =gPauseScreenFlag\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	beq _0807CF8A\n\
	ldrb r0, [r3]\n\
	cmp r0, #0\n\
	beq _0807CED4\n\
	ldr r2, _0807CECC @ =0x0857607D\n\
	ldr r1, _0807CED0 @ =0x08576073\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	adds r0, r0, r2\n\
	ldrb r1, [r0]\n\
	movs r2, #0x91\n\
	lsls r2, r2, #2\n\
	adds r0, r6, r2\n\
	b _0807CEDE\n\
	.align 2, 0\n\
_0807CEBC: .4byte gCurrentArea\n\
_0807CEC0: .4byte gNonGameplayRam\n\
_0807CEC4: .4byte 0x08581500\n\
_0807CEC8: .4byte gPauseScreenFlag\n\
_0807CECC: .4byte 0x0857607D\n\
_0807CED0: .4byte 0x08576073\n\
_0807CED4:\n\
	ldr r0, _0807CF48 @ =0x0857607D\n\
	ldrb r1, [r0, #7]\n\
	movs r4, #0x91\n\
	lsls r4, r4, #2\n\
	adds r0, r6, r4\n\
_0807CEDE:\n\
	strb r1, [r0]\n\
	ldr r1, _0807CF4C @ =0x0879C180\n\
	movs r5, #0x91\n\
	lsls r5, r5, #2\n\
	adds r0, r6, r5\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	adds r1, r6, #0\n\
	adds r1, #0xc6\n\
	strb r0, [r1]\n\
	subs r1, #8\n\
	movs r0, #0x1c\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	movs r0, #0x32\n\
	strh r0, [r1]\n\
	adds r2, r6, #0\n\
	adds r2, #0xc7\n\
	ldrb r1, [r2]\n\
	movs r4, #4\n\
	rsbs r4, r4, #0\n\
	adds r0, r4, #0\n\
	ands r0, r1\n\
	movs r5, #1\n\
	orrs r0, r5\n\
	movs r1, #0xd\n\
	rsbs r1, r1, #0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	movs r0, #0xa\n\
	movs r1, #0\n\
	bl UpdateMenuOamDataId\n\
	adds r1, r6, #0\n\
	adds r1, #0xaf\n\
	ldrb r0, [r1]\n\
	ands r4, r0\n\
	orrs r4, r5\n\
	strb r4, [r1]\n\
	ldr r2, _0807CF50 @ =gCurrentArea\n\
	ldrb r0, [r2]\n\
	cmp r0, #0\n\
	beq _0807CF5C\n\
	ldr r1, _0807CF54 @ =0x08576073\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	ldr r2, _0807CF58 @ =0x00000249\n\
	adds r0, r6, r2\n\
	b _0807CF6C\n\
	.align 2, 0\n\
_0807CF48: .4byte 0x0857607D\n\
_0807CF4C: .4byte 0x0879C180\n\
_0807CF50: .4byte gCurrentArea\n\
_0807CF54: .4byte 0x08576073\n\
_0807CF58: .4byte 0x00000249\n\
_0807CF5C:\n\
	ldr r1, _0807CF94 @ =0x085760E8\n\
	ldr r0, _0807CF98 @ =gCurrentRoom\n\
	ldrb r0, [r0]\n\
	adds r0, #1\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	ldr r4, _0807CF9C @ =0x00000249\n\
	adds r0, r6, r4\n\
_0807CF6C:\n\
	strb r1, [r0]\n\
	bl unk_7d27c\n\
	mov r1, sp\n\
	ldr r5, _0807CFA0 @ =0x00007A73\n\
	adds r0, r5, #0\n\
	strh r0, [r1]\n\
	ldr r1, _0807CFA4 @ =0x040000D4\n\
	mov r6, sp\n\
	str r6, [r1]\n\
	ldr r0, _0807CFA8 @ =0x05000342\n\
	str r0, [r1, #4]\n\
	ldr r0, _0807CFAC @ =0x8100000C\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
_0807CF8A:\n\
	add sp, #4\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807CF94: .4byte 0x085760E8\n\
_0807CF98: .4byte gCurrentRoom\n\
_0807CF9C: .4byte 0x00000249\n\
_0807CFA0: .4byte 0x00007A73\n\
_0807CFA4: .4byte 0x040000D4\n\
_0807CFA8: .4byte 0x05000342\n\
_0807CFAC: .4byte 0x8100000C\n\
    .syntax divided\n");
}

// 0x0807CFB0
NAKED_FUNCTION
void unk_7cfb0(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	ldr r1, _0807D034 @ =gNonGameplayRam\n\
	ldrb r0, [r1]\n\
	mov ip, r1\n\
	cmp r0, #0\n\
	bne _0807CFBE\n\
	b _0807D270\n\
_0807CFBE:\n\
	ldr r0, _0807D038 @ =gPauseScreenFlag\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #4\n\
	bne _0807CFCC\n\
	b _0807D270\n\
_0807CFCC:\n\
	movs r1, #0x92\n\
	lsls r1, r1, #2\n\
	add r1, ip\n\
	ldrb r0, [r1]\n\
	adds r0, #1\n\
	movs r2, #0\n\
	strb r0, [r1]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #7\n\
	bls _0807D014\n\
	strb r2, [r1]\n\
	ldr r3, _0807D03C @ =0x00000247\n\
	add r3, ip\n\
	ldrb r0, [r3]\n\
	adds r0, #1\n\
	strb r0, [r3]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #5\n\
	bls _0807CFF8\n\
	strb r2, [r3]\n\
_0807CFF8:\n\
	ldr r0, _0807D040 @ =0x00000249\n\
	add r0, ip\n\
	ldrb r4, [r0]\n\
	lsls r1, r4, #1\n\
	ldr r0, _0807D044 @ =0x05000340\n\
	adds r1, r1, r0\n\
	ldr r2, _0807D048 @ =0x08581300\n\
	ldrb r0, [r3]\n\
	lsls r0, r0, #4\n\
	adds r0, r0, r4\n\
	lsls r0, r0, #1\n\
	adds r0, r0, r2\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
_0807D014:\n\
	ldr r1, _0807D04C @ =0x0000024A\n\
	add r1, ip\n\
	ldrb r0, [r1]\n\
	cmp r0, #2\n\
	bne _0807D050\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	mov r1, ip\n\
	adds r1, #0xa6\n\
	movs r0, #0x1c\n\
	strh r0, [r1]\n\
	subs r1, #2\n\
	movs r0, #0x32\n\
	strh r0, [r1]\n\
	b _0807D0DA\n\
	.align 2, 0\n\
_0807D034: .4byte gNonGameplayRam\n\
_0807D038: .4byte gPauseScreenFlag\n\
_0807D03C: .4byte 0x00000247\n\
_0807D040: .4byte 0x00000249\n\
_0807D044: .4byte 0x05000340\n\
_0807D048: .4byte 0x08581300\n\
_0807D04C: .4byte 0x0000024A\n\
_0807D050:\n\
	cmp r0, #3\n\
	bne _0807D0DA\n\
	ldr r0, _0807D090 @ =0x0857608A\n\
	ldr r1, _0807D094 @ =0x0300004C\n\
	ldrb r1, [r1]\n\
	adds r0, r1, r0\n\
	movs r4, #0\n\
	ldrsb r4, [r0, r4]\n\
	cmp r4, #0\n\
	blt _0807D09C\n\
	movs r0, #0x91\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	adds r4, r4, r0\n\
	cmp r4, #0x23\n\
	ble _0807D078\n\
	subs r4, #0x24\n\
_0807D078:\n\
	mov r1, ip\n\
	adds r1, #0xbe\n\
	ldr r3, _0807D098 @ =0x0879C1A4\n\
	lsls r2, r4, #1\n\
	adds r2, r2, r4\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	ldrh r1, [r1]\n\
	adds r0, r0, r1\n\
	b _0807D0B2\n\
	.align 2, 0\n\
_0807D090: .4byte 0x0857608A\n\
_0807D094: .4byte 0x0300004C\n\
_0807D098: .4byte 0x0879C1A4\n\
_0807D09C:\n\
	mov r4, ip\n\
	adds r4, #0xbe\n\
	ldr r3, _0807D108 @ =0x0879C210\n\
	lsls r2, r1, #1\n\
	adds r2, r2, r1\n\
	adds r0, r2, r3\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	ldrh r4, [r4]\n\
	adds r0, r0, r4\n\
_0807D0B2:\n\
	mov r1, ip\n\
	adds r1, #0xa6\n\
	strh r0, [r1]\n\
	adds r1, #0x16\n\
	adds r0, r3, #1\n\
	adds r0, r2, r0\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	ldrh r1, [r1]\n\
	adds r0, r0, r1\n\
	mov r1, ip\n\
	adds r1, #0xa4\n\
	strh r0, [r1]\n\
	adds r3, #2\n\
	adds r2, r2, r3\n\
	ldrb r0, [r2]\n\
	adds r0, #0x16\n\
	adds r1, #0xa\n\
	strb r0, [r1]\n\
_0807D0DA:\n\
	movs r2, #0x90\n\
	lsls r2, r2, #2\n\
	add r2, ip\n\
	ldrb r0, [r2]\n\
	cmp r0, #0\n\
	bne _0807D0E8\n\
	b _0807D270\n\
_0807D0E8:\n\
	ldr r0, _0807D10C @ =0x00000242\n\
	add r0, ip\n\
	ldrb r1, [r0]\n\
	adds r1, #1\n\
	strb r1, [r0]\n\
	ldrb r0, [r2]\n\
	subs r0, #1\n\
	cmp r0, #5\n\
	bls _0807D0FC\n\
	b _0807D270\n\
_0807D0FC:\n\
	lsls r0, r0, #2\n\
	ldr r1, _0807D110 @ =_0807D114\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_0807D108: .4byte 0x0879C210\n\
_0807D10C: .4byte 0x00000242\n\
_0807D110: .4byte _0807D114\n\
_0807D114: @ jump table\n\
	.4byte _0807D12C @ case 0\n\
	.4byte _0807D142 @ case 1\n\
	.4byte _0807D164 @ case 2\n\
	.4byte _0807D19C @ case 3\n\
	.4byte _0807D1C4 @ case 4\n\
	.4byte _0807D1EC @ case 5\n\
_0807D12C:\n\
	mov r0, ip\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807D13C\n\
	b _0807D270\n\
_0807D13C:\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	b _0807D1DE\n\
_0807D142:\n\
	mov r0, ip\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807D152\n\
	b _0807D270\n\
_0807D152:\n\
	ldr r1, _0807D160 @ =0x0000024A\n\
	add r1, ip\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	b _0807D1B6\n\
	.align 2, 0\n\
_0807D160: .4byte 0x0000024A\n\
_0807D164:\n\
	ldr r1, _0807D194 @ =0x00000242\n\
	add r1, ip\n\
	ldrb r0, [r1]\n\
	cmp r0, #8\n\
	bhi _0807D170\n\
	b _0807D270\n\
_0807D170:\n\
	movs r3, #0\n\
	strb r3, [r1]\n\
	movs r2, #0x91\n\
	lsls r2, r2, #2\n\
	add r2, ip\n\
	ldrb r0, [r2]\n\
	adds r0, #1\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0x23\n\
	ble _0807D18A\n\
	strb r3, [r2]\n\
_0807D18A:\n\
	ldr r1, _0807D198 @ =0x0879C180\n\
	movs r0, #0\n\
	ldrsb r0, [r2, r0]\n\
	b _0807D266\n\
	.align 2, 0\n\
_0807D194: .4byte 0x00000242\n\
_0807D198: .4byte 0x0879C180\n\
_0807D19C:\n\
	mov r0, ip\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _0807D270\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	add r1, ip\n\
	movs r0, #5\n\
	strb r0, [r1]\n\
	ldr r1, _0807D1C0 @ =0x00000241\n\
_0807D1B6:\n\
	add r1, ip\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
	b _0807D270\n\
	.align 2, 0\n\
_0807D1C0: .4byte 0x00000241\n\
_0807D1C4:\n\
	mov r0, ip\n\
	ldrh r1, [r0, #4]\n\
	movs r0, #0x80\n\
	lsls r0, r0, #3\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	bne _0807D270\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	add r1, ip\n\
	movs r0, #6\n\
	strb r0, [r1]\n\
	ldr r1, _0807D1E8 @ =0x0000024A\n\
_0807D1DE:\n\
	add r1, ip\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	b _0807D270\n\
	.align 2, 0\n\
_0807D1E8: .4byte 0x0000024A\n\
_0807D1EC:\n\
	movs r2, #0x91\n\
	lsls r2, r2, #2\n\
	add r2, ip\n\
	ldr r0, _0807D21C @ =0x00000245\n\
	add r0, ip\n\
	ldrb r4, [r2]\n\
	movs r1, #0\n\
	ldrsb r1, [r2, r1]\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r1, r0\n\
	bne _0807D224\n\
	movs r1, #0x90\n\
	lsls r1, r1, #2\n\
	add r1, ip\n\
	movs r2, #0\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	ldr r0, _0807D220 @ =0x00000241\n\
	add r0, ip\n\
	strb r2, [r0]\n\
	b _0807D270\n\
	.align 2, 0\n\
_0807D21C: .4byte 0x00000245\n\
_0807D220: .4byte 0x00000241\n\
_0807D224:\n\
	ldr r1, _0807D248 @ =0x00000242\n\
	add r1, ip\n\
	ldrb r0, [r1]\n\
	cmp r0, #8\n\
	bls _0807D270\n\
	movs r3, #0\n\
	strb r3, [r1]\n\
	ldr r0, _0807D24C @ =0x00000246\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	adds r0, r4, r0\n\
	strb r0, [r2]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	cmp r0, #0x23\n\
	ble _0807D250\n\
	strb r3, [r2]\n\
	b _0807D258\n\
	.align 2, 0\n\
_0807D248: .4byte 0x00000242\n\
_0807D24C: .4byte 0x00000246\n\
_0807D250:\n\
	cmp r0, #0\n\
	bge _0807D258\n\
	movs r0, #0x23\n\
	strb r0, [r2]\n\
_0807D258:\n\
	ldr r1, _0807D278 @ =0x0879C180\n\
	movs r0, #0x91\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
_0807D266:\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	mov r0, ip\n\
	adds r0, #0xc6\n\
	strb r1, [r0]\n\
_0807D270:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807D278: .4byte 0x0879C180\n\
    .syntax divided\n");
}

// 0x0807D27C
NAKED_FUNCTION
void unk_7d27c(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	ldr r0, _0807D294 @ =0x0300004C\n\
	ldrb r1, [r0]\n\
	adds r5, r0, #0\n\
	cmp r1, #0\n\
	bne _0807D29C\n\
	ldr r0, _0807D298 @ =gNonGameplayRam\n\
	movs r2, #0x90\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	b _0807D33E\n\
	.align 2, 0\n\
_0807D294: .4byte 0x0300004C\n\
_0807D298: .4byte gNonGameplayRam\n\
_0807D29C:\n\
	ldr r0, _0807D2C4 @ =gNonGameplayRam\n\
	movs r2, #0x90\n\
	lsls r2, r2, #2\n\
	adds r1, r0, r2\n\
	movs r4, #1\n\
	strb r4, [r1]\n\
	subs r2, #0x20\n\
	adds r1, r0, r2\n\
	ldr r2, _0807D2C8 @ =gPreviousNavigationConversation\n\
	ldrb r1, [r1]\n\
	adds r3, r0, #0\n\
	ldrb r2, [r2]\n\
	cmp r1, r2\n\
	bne _0807D2D0\n\
	ldr r0, _0807D2CC @ =0x0000024A\n\
	adds r1, r3, r0\n\
	movs r0, #2\n\
	strb r0, [r1]\n\
	b _0807D2D6\n\
	.align 2, 0\n\
_0807D2C4: .4byte gNonGameplayRam\n\
_0807D2C8: .4byte gPreviousNavigationConversation\n\
_0807D2CC: .4byte 0x0000024A\n\
_0807D2D0:\n\
	ldr r1, _0807D324 @ =0x0000024A\n\
	adds r0, r3, r1\n\
	strb r4, [r0]\n\
_0807D2D6:\n\
	ldr r1, _0807D328 @ =0x0857607D\n\
	ldrb r0, [r5]\n\
	adds r0, r0, r1\n\
	ldrb r1, [r0]\n\
	movs r2, #0\n\
	ldrsb r2, [r0, r2]\n\
	cmp r2, #0\n\
	blt _0807D340\n\
	ldr r0, _0807D32C @ =0x00000245\n\
	adds r5, r3, r0\n\
	strb r1, [r5]\n\
	movs r1, #0x91\n\
	lsls r1, r1, #2\n\
	adds r4, r3, r1\n\
	movs r0, #0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r2, r0\n\
	beq _0807D340\n\
	movs r2, #0x90\n\
	lsls r2, r2, #2\n\
	adds r1, r3, r2\n\
	movs r0, #4\n\
	strb r0, [r1]\n\
	movs r1, #0\n\
	ldrsb r1, [r5, r1]\n\
	movs r0, #0\n\
	ldrsb r0, [r4, r0]\n\
	subs r1, r1, r0\n\
	movs r0, #1\n\
	cmp r1, #0\n\
	bge _0807D316\n\
	subs r0, #2\n\
_0807D316:\n\
	muls r1, r0, r1\n\
	cmp r1, #0x12\n\
	ble _0807D330\n\
	movs r1, #1\n\
	rsbs r1, r1, #0\n\
	b _0807D338\n\
	.align 2, 0\n\
_0807D324: .4byte 0x0000024A\n\
_0807D328: .4byte 0x0857607D\n\
_0807D32C: .4byte 0x00000245\n\
_0807D330:\n\
	cmp r1, #0x12\n\
	bne _0807D336\n\
	movs r0, #1\n\
_0807D336:\n\
	movs r1, #1\n\
_0807D338:\n\
	muls r1, r0, r1\n\
	ldr r2, _0807D348 @ =0x00000246\n\
	adds r0, r3, r2\n\
_0807D33E:\n\
	strb r1, [r0]\n\
_0807D340:\n\
	pop {r4, r5}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0807D348: .4byte 0x00000246\n\
    .syntax divided\n");
}
