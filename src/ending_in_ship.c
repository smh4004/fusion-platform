#include "globals.h"
#include "macros.h"

// 0x08095E24
NAKED_FUNCTION
void EndingMonologueInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	sub sp, #4\n\
	ldr r3, _08095F78 @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _08095F7C @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08095F80 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08095F84 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _08095F88 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08095F8C @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r6, #0\n\
	str r6, [sp]\n\
	ldr r4, _08095F90 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r1, _08095F94 @ =gNonGameplayRam\n\
	mov r8, r1\n\
	str r1, [r4, #4]\n\
	ldr r0, _08095F98 @ =0x85000150\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095F9C @ =0x086150E8\n\
	ldr r1, _08095FA0 @ =0x06010000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095FA4 @ =0x08636638\n\
	str r0, [r4]\n\
	ldr r0, _08095FA8 @ =0x05000200\n\
	str r0, [r4, #4]\n\
	ldr r5, _08095FAC @ =0x84000080\n\
	str r5, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095FB0 @ =0x086186A4\n\
	ldr r1, _08095FB4 @ =0x06008000\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095FB8 @ =0x086377F8\n\
	ldr r1, _08095FBC @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _08095FC0 @ =0x08636438\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	str r5, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095FC4 @ =0x08662804\n\
	movs r5, #0x80\n\
	lsls r5, r5, #0x12\n\
	adds r1, r5, #0\n\
	bl LZ77UncompWram\n\
	str r5, [r4]\n\
	ldr r0, _08095FC8 @ =0x06004800\n\
	str r0, [r4, #4]\n\
	ldr r0, _08095FCC @ =0x84000200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	str r6, [sp]\n\
	mov r2, sp\n\
	str r2, [r4]\n\
	movs r0, #0xc0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	ldr r0, _08095FD0 @ =0x85001200\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095FD4 @ =0x08663820\n\
	str r0, [r4]\n\
	ldr r0, _08095FD8 @ =0x05000180\n\
	str r0, [r4, #4]\n\
	ldr r0, _08095FDC @ =0x84000020\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _08095FE0 @ =gBg1XPosition\n\
	strh r6, [r0]\n\
	ldr r0, _08095FE4 @ =gBg1YPosition\n\
	strh r6, [r0]\n\
	ldr r0, _08095FE8 @ =0x0300122C\n\
	strh r6, [r0]\n\
	ldr r0, _08095FEC @ =0x0300122E\n\
	strh r6, [r0]\n\
	ldr r0, _08095FF0 @ =0x03001230\n\
	strh r6, [r0]\n\
	ldr r0, _08095FF4 @ =0x03001232\n\
	strh r6, [r0]\n\
	ldr r0, _08095FF8 @ =0x04000010\n\
	strh r6, [r0]\n\
	ldr r1, _08095FFC @ =0x04000012\n\
	movs r0, #4\n\
	strh r0, [r1]\n\
	ldr r0, _08096000 @ =0x04000014\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	adds r0, #2\n\
	strh r6, [r0]\n\
	subs r1, #0xa\n\
	movs r2, #0x90\n\
	lsls r2, r2, #4\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r2, _08096004 @ =0x00001E01\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #4\n\
	ldr r2, _08096008 @ =0x00001F0B\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _0809600C @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08096010 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _08096014 @ =gWrittenToBldalpha_Eva\n\
	strh r6, [r0]\n\
	ldr r0, _08096018 @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	movs r1, #0x82\n\
	lsls r1, r1, #1\n\
	movs r0, #1\n\
	movs r2, #0xb4\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r0, _0809601C @ =0x0863A19C\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xc0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08096020 @ =EndingMonologueVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08095F78: .4byte 0x04000208\n\
_08095F7C: .4byte 0x04000004\n\
_08095F80: .4byte 0x0000FFEF\n\
_08095F84: .4byte 0x04000200\n\
_08095F88: .4byte 0x0000FFFD\n\
_08095F8C: .4byte unk_99940\n\
_08095F90: .4byte 0x040000D4\n\
_08095F94: .4byte gNonGameplayRam\n\
_08095F98: .4byte 0x85000150\n\
_08095F9C: .4byte 0x086150E8\n\
_08095FA0: .4byte 0x06010000\n\
_08095FA4: .4byte 0x08636638\n\
_08095FA8: .4byte 0x05000200\n\
_08095FAC: .4byte 0x84000080\n\
_08095FB0: .4byte 0x086186A4\n\
_08095FB4: .4byte 0x06008000\n\
_08095FB8: .4byte 0x086377F8\n\
_08095FBC: .4byte 0x0600F800\n\
_08095FC0: .4byte 0x08636438\n\
_08095FC4: .4byte 0x08662804\n\
_08095FC8: .4byte 0x06004800\n\
_08095FCC: .4byte 0x84000200\n\
_08095FD0: .4byte 0x85001200\n\
_08095FD4: .4byte 0x08663820\n\
_08095FD8: .4byte 0x05000180\n\
_08095FDC: .4byte 0x84000020\n\
_08095FE0: .4byte gBg1XPosition\n\
_08095FE4: .4byte gBg1YPosition\n\
_08095FE8: .4byte 0x0300122C\n\
_08095FEC: .4byte 0x0300122E\n\
_08095FF0: .4byte 0x03001230\n\
_08095FF4: .4byte 0x03001232\n\
_08095FF8: .4byte 0x04000010\n\
_08095FFC: .4byte 0x04000012\n\
_08096000: .4byte 0x04000014\n\
_08096004: .4byte 0x00001E01\n\
_08096008: .4byte 0x00001F0B\n\
_0809600C: .4byte gWrittenToBldy\n\
_08096010: .4byte 0x04000054\n\
_08096014: .4byte gWrittenToBldalpha_Eva\n\
_08096018: .4byte gWrittenToBldalpha_Evb\n\
_0809601C: .4byte 0x0863A19C\n\
_08096020: .4byte EndingMonologueVblank\n\
    .syntax divided\n");
}

// 0x08096024
NAKED_FUNCTION
void EndingAdamConversationInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	sub sp, #8\n\
	ldr r3, _0809617C @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _08096180 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08096184 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _08096188 @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _0809618C @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _08096190 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r4, _08096194 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r6, _08096198 @ =0x030016A0\n\
	str r6, [r4, #4]\n\
	ldr r0, _0809619C @ =0x850000B4\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	add r1, sp, #4\n\
	strh r5, [r1]\n\
	str r1, [r4]\n\
	ldr r2, _080961A0 @ =0xFFFFFDF8\n\
	adds r0, r6, r2\n\
	str r0, [r4, #4]\n\
	ldr r2, _080961A4 @ =0x8100007E\n\
	str r2, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r5, [r1]\n\
	str r1, [r4]\n\
	ldr r1, _080961A8 @ =0xFFFFFEF4\n\
	adds r0, r6, r1\n\
	str r0, [r4, #4]\n\
	str r2, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080961AC @ =0x086131C8\n\
	ldr r1, _080961B0 @ =0x06008000\n\
	bl LZ77UncompVram\n\
	ldr r0, _080961B4 @ =0x08637238\n\
	ldr r1, _080961B8 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _080961BC @ =0x08598898\n\
	ldr r1, _080961C0 @ =0x0600E000\n\
	bl LZ77UncompVram\n\
	ldr r0, _080961C4 @ =0x08636438\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	ldr r0, _080961C8 @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080961CC @ =0x03001224\n\
	ldr r1, _080961D0 @ =0x0000FFF8\n\
	adds r2, r1, #0\n\
	strh r2, [r0]\n\
	ldr r0, _080961D4 @ =0x03001226\n\
	movs r1, #8\n\
	strh r1, [r0]\n\
	ldr r0, _080961D8 @ =gBg1XPosition\n\
	strh r5, [r0]\n\
	ldr r0, _080961DC @ =gBg1YPosition\n\
	strh r5, [r0]\n\
	ldr r0, _080961E0 @ =0x0300122C\n\
	strh r5, [r0]\n\
	ldr r0, _080961E4 @ =0x0300122E\n\
	strh r5, [r0]\n\
	ldr r0, _080961E8 @ =0x03001230\n\
	strh r5, [r0]\n\
	ldr r0, _080961EC @ =0x03001232\n\
	strh r5, [r0]\n\
	ldr r0, _080961F0 @ =0x04000010\n\
	strh r2, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	ldr r1, _080961F4 @ =0x04000008\n\
	ldr r2, _080961F8 @ =0x00001C08\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #6\n\
	ldr r2, _080961FC @ =0x00001F0B\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _08096200 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08096204 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _08096208 @ =gWrittenToBldalpha_Eva\n\
	strh r1, [r0]\n\
	ldr r0, _0809620C @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	ldr r2, _08096210 @ =0x04000052\n\
	lsls r0, r1, #8\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #2\n\
	movs r1, #0x70\n\
	movs r2, #0x50\n\
	movs r3, #1\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #3\n\
	movs r1, #0x70\n\
	movs r2, #0x50\n\
	movs r3, #1\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #4\n\
	movs r1, #0x70\n\
	movs r2, #0x50\n\
	movs r3, #1\n\
	bl EndingDialogueSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r0, _08096214 @ =0xFFFFFDE4\n\
	adds r6, r6, r0\n\
	ldr r0, _08096218 @ =0x0863A19C\n\
	str r0, [r6]\n\
	str r5, [sp]\n\
	mov r1, sp\n\
	str r1, [r4]\n\
	ldr r0, _0809621C @ =0x0600D000\n\
	str r0, [r4, #4]\n\
	ldr r0, _08096220 @ =0x85000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xc8\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08096224 @ =EndingConversationAndAnimalsVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #8\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_0809617C: .4byte 0x04000208\n\
_08096180: .4byte 0x04000004\n\
_08096184: .4byte 0x0000FFEF\n\
_08096188: .4byte 0x04000200\n\
_0809618C: .4byte 0x0000FFFD\n\
_08096190: .4byte unk_99940\n\
_08096194: .4byte 0x040000D4\n\
_08096198: .4byte 0x030016A0\n\
_0809619C: .4byte 0x850000B4\n\
_080961A0: .4byte 0xFFFFFDF8\n\
_080961A4: .4byte 0x8100007E\n\
_080961A8: .4byte 0xFFFFFEF4\n\
_080961AC: .4byte 0x086131C8\n\
_080961B0: .4byte 0x06008000\n\
_080961B4: .4byte 0x08637238\n\
_080961B8: .4byte 0x0600F800\n\
_080961BC: .4byte 0x08598898\n\
_080961C0: .4byte 0x0600E000\n\
_080961C4: .4byte 0x08636438\n\
_080961C8: .4byte 0x84000080\n\
_080961CC: .4byte 0x03001224\n\
_080961D0: .4byte 0x0000FFF8\n\
_080961D4: .4byte 0x03001226\n\
_080961D8: .4byte gBg1XPosition\n\
_080961DC: .4byte gBg1YPosition\n\
_080961E0: .4byte 0x0300122C\n\
_080961E4: .4byte 0x0300122E\n\
_080961E8: .4byte 0x03001230\n\
_080961EC: .4byte 0x03001232\n\
_080961F0: .4byte 0x04000010\n\
_080961F4: .4byte 0x04000008\n\
_080961F8: .4byte 0x00001C08\n\
_080961FC: .4byte 0x00001F0B\n\
_08096200: .4byte gWrittenToBldy\n\
_08096204: .4byte 0x04000054\n\
_08096208: .4byte gWrittenToBldalpha_Eva\n\
_0809620C: .4byte gWrittenToBldalpha_Evb\n\
_08096210: .4byte 0x04000052\n\
_08096214: .4byte 0xFFFFFDE4\n\
_08096218: .4byte 0x0863A19C\n\
_0809621C: .4byte 0x0600D000\n\
_08096220: .4byte 0x85000400\n\
_08096224: .4byte EndingConversationAndAnimalsVblank\n\
    .syntax divided\n");
}

// 0x08096228
NAKED_FUNCTION
void EndingAnimalsInit(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	mov r6, r8\n\
	push {r6}\n\
	sub sp, #8\n\
	ldr r3, _08096390 @ =0x04000208\n\
	movs r0, #0\n\
	strh r0, [r3]\n\
	ldr r2, _08096394 @ =0x04000004\n\
	ldrh r1, [r2]\n\
	ldr r0, _08096398 @ =0x0000FFEF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	ldr r2, _0809639C @ =0x04000200\n\
	ldrh r1, [r2]\n\
	ldr r0, _080963A0 @ =0x0000FFFD\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #1\n\
	strh r0, [r3]\n\
	ldr r0, _080963A4 @ =unk_99940\n\
	bl CallbackSetVBlank\n\
	movs r5, #0\n\
	str r5, [sp]\n\
	ldr r4, _080963A8 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r4]\n\
	ldr r1, _080963AC @ =0x030016A0\n\
	mov r8, r1\n\
	str r1, [r4, #4]\n\
	ldr r0, _080963B0 @ =0x850000B4\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	add r6, sp, #4\n\
	strh r5, [r6]\n\
	str r6, [r4]\n\
	ldr r0, _080963B4 @ =0xFFFFFDF8\n\
	add r0, r8\n\
	str r0, [r4, #4]\n\
	ldr r1, _080963B8 @ =0x8100007E\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	strh r5, [r6]\n\
	str r6, [r4]\n\
	ldr r0, _080963BC @ =0xFFFFFEF4\n\
	add r0, r8\n\
	str r0, [r4, #4]\n\
	str r1, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080963C0 @ =0x0861B89C\n\
	movs r1, #0xc0\n\
	lsls r1, r1, #0x13\n\
	bl LZ77UncompVram\n\
	ldr r0, _080963C4 @ =0x086217A8\n\
	ldr r1, _080963C8 @ =0x06008000\n\
	bl LZ77UncompVram\n\
	ldr r0, _080963CC @ =0x08638654\n\
	ldr r1, _080963D0 @ =0x0600F000\n\
	bl LZ77UncompVram\n\
	ldr r0, _080963D4 @ =0x08637DB8\n\
	ldr r1, _080963D8 @ =0x0600F800\n\
	bl LZ77UncompVram\n\
	ldr r0, _080963DC @ =0x08636838\n\
	str r0, [r4]\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r4, #4]\n\
	ldr r0, _080963E0 @ =0x84000080\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r2, _080963E4 @ =0x000002FF\n\
	adds r0, r2, #0\n\
	strh r0, [r6]\n\
	str r6, [r4]\n\
	ldr r0, _080963E8 @ =0x0600F500\n\
	str r0, [r4, #4]\n\
	ldr r0, _080963EC @ =0x81000180\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	ldr r0, _080963F0 @ =0x03001224\n\
	strh r5, [r0]\n\
	ldr r0, _080963F4 @ =0x03001226\n\
	strh r5, [r0]\n\
	ldr r0, _080963F8 @ =gBg1XPosition\n\
	strh r5, [r0]\n\
	ldr r0, _080963FC @ =gBg1YPosition\n\
	strh r5, [r0]\n\
	ldr r0, _08096400 @ =0x0300122C\n\
	strh r5, [r0]\n\
	ldr r0, _08096404 @ =0x03001230\n\
	strh r5, [r0]\n\
	ldr r1, _08096408 @ =0x0300122E\n\
	ldr r2, _0809640C @ =0x0000FFE2\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08096410 @ =0x03001232\n\
	movs r1, #0xe2\n\
	strh r1, [r0]\n\
	ldr r0, _08096414 @ =0x04000010\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r5, [r0]\n\
	adds r0, #2\n\
	strh r1, [r0]\n\
	ldr r1, _08096418 @ =0x0400000C\n\
	ldr r2, _0809641C @ =0x00001E0A\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	adds r2, #0xf9\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	adds r1, #0x42\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	ldr r0, _08096420 @ =gWrittenToBldy\n\
	movs r1, #0x10\n\
	strh r1, [r0]\n\
	ldr r0, _08096424 @ =0x04000054\n\
	strh r1, [r0]\n\
	ldr r0, _08096428 @ =gWrittenToBldalpha_Eva\n\
	strh r1, [r0]\n\
	ldr r0, _0809642C @ =gWrittenToBldalpha_Evb\n\
	strh r1, [r0]\n\
	ldr r2, _08096430 @ =0x04000052\n\
	lsls r0, r1, #8\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0x14\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	ldr r0, _08096434 @ =0xFFFFFDE4\n\
	add r8, r0\n\
	ldr r0, _08096438 @ =0x0863A19C\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	str r5, [sp]\n\
	mov r2, sp\n\
	str r2, [r4]\n\
	ldr r0, _0809643C @ =0x0600D000\n\
	str r0, [r4, #4]\n\
	ldr r0, _08096440 @ =0x85000400\n\
	str r0, [r4, #8]\n\
	ldr r0, [r4, #8]\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x13\n\
	movs r2, #0xe0\n\
	lsls r2, r2, #5\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	ldr r0, _08096444 @ =EndingConversationAndAnimalsVblank\n\
	bl CallbackSetVBlank\n\
	add sp, #8\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08096390: .4byte 0x04000208\n\
_08096394: .4byte 0x04000004\n\
_08096398: .4byte 0x0000FFEF\n\
_0809639C: .4byte 0x04000200\n\
_080963A0: .4byte 0x0000FFFD\n\
_080963A4: .4byte unk_99940\n\
_080963A8: .4byte 0x040000D4\n\
_080963AC: .4byte 0x030016A0\n\
_080963B0: .4byte 0x850000B4\n\
_080963B4: .4byte 0xFFFFFDF8\n\
_080963B8: .4byte 0x8100007E\n\
_080963BC: .4byte 0xFFFFFEF4\n\
_080963C0: .4byte 0x0861B89C\n\
_080963C4: .4byte 0x086217A8\n\
_080963C8: .4byte 0x06008000\n\
_080963CC: .4byte 0x08638654\n\
_080963D0: .4byte 0x0600F000\n\
_080963D4: .4byte 0x08637DB8\n\
_080963D8: .4byte 0x0600F800\n\
_080963DC: .4byte 0x08636838\n\
_080963E0: .4byte 0x84000080\n\
_080963E4: .4byte 0x000002FF\n\
_080963E8: .4byte 0x0600F500\n\
_080963EC: .4byte 0x81000180\n\
_080963F0: .4byte 0x03001224\n\
_080963F4: .4byte 0x03001226\n\
_080963F8: .4byte gBg1XPosition\n\
_080963FC: .4byte gBg1YPosition\n\
_08096400: .4byte 0x0300122C\n\
_08096404: .4byte 0x03001230\n\
_08096408: .4byte 0x0300122E\n\
_0809640C: .4byte 0x0000FFE2\n\
_08096410: .4byte 0x03001232\n\
_08096414: .4byte 0x04000010\n\
_08096418: .4byte 0x0400000C\n\
_0809641C: .4byte 0x00001E0A\n\
_08096420: .4byte gWrittenToBldy\n\
_08096424: .4byte 0x04000054\n\
_08096428: .4byte gWrittenToBldalpha_Eva\n\
_0809642C: .4byte gWrittenToBldalpha_Evb\n\
_08096430: .4byte 0x04000052\n\
_08096434: .4byte 0xFFFFFDE4\n\
_08096438: .4byte 0x0863A19C\n\
_0809643C: .4byte 0x0600D000\n\
_08096440: .4byte 0x85000400\n\
_08096444: .4byte EndingConversationAndAnimalsVblank\n\
    .syntax divided\n");
}

// 0x08096448
NAKED_FUNCTION
void EndingInShipProcess(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	movs r6, #0\n\
	ldr r2, _08096474 @ =gNonGameplayRam\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	ldrh r1, [r0]\n\
	adds r1, #1\n\
	strh r1, [r0]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r0, r2, r7\n\
	ldrb r0, [r0]\n\
	adds r5, r2, #0\n\
	cmp r0, #0xf\n\
	bls _0809646A\n\
	b _08096920\n\
_0809646A:\n\
	lsls r0, r0, #2\n\
	ldr r1, _08096478 @ =_0809647C\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	mov pc, r0\n\
	.align 2, 0\n\
_08096474: .4byte gNonGameplayRam\n\
_08096478: .4byte _0809647C\n\
_0809647C: @ jump table\n\
	.4byte _080964BC @ case 0\n\
	.4byte _080964F2 @ case 1\n\
	.4byte _08096550 @ case 2\n\
	.4byte _080965F4 @ case 3\n\
	.4byte _0809663C @ case 4\n\
	.4byte _08096698 @ case 5\n\
	.4byte _080966E0 @ case 6\n\
	.4byte _080966FC @ case 7\n\
	.4byte _08096716 @ case 8\n\
	.4byte _0809673C @ case 9\n\
	.4byte _0809678A @ case 10\n\
	.4byte _0809681C @ case 11\n\
	.4byte _08096828 @ case 12\n\
	.4byte _08096878 @ case 13\n\
	.4byte _080968A0 @ case 14\n\
	.4byte _080968E8 @ case 15\n\
_080964BC:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #7\n\
	beq _080964CA\n\
	b _080968D8\n\
_080964CA:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _080964DC @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _080964E0\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
	b _080968D8\n\
	.align 2, 0\n\
_080964DC: .4byte gWrittenToBldy\n\
_080964E0:\n\
	movs r0, #0x56\n\
	movs r1, #0xe\n\
	bl PlayMusic\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #1\n\
	b _080968D6\n\
_080964F2:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrh r0, [r1]\n\
	cmp r0, #0x46\n\
	beq _08096500\n\
	b _080968D8\n\
_08096500:\n\
	movs r4, #0\n\
	movs r2, #0\n\
	strh r2, [r1]\n\
	movs r3, #0x80\n\
	lsls r3, r3, #0x13\n\
	ldrh r0, [r3]\n\
	movs r7, #0x80\n\
	lsls r7, r7, #1\n\
	adds r1, r7, #0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	strh r2, [r5, #0x12]\n\
	strh r2, [r5, #0x10]\n\
	strh r2, [r5, #0xe]\n\
	strh r2, [r5, #0xc]\n\
	ldr r1, _08096544 @ =0x00000212\n\
	adds r0, r5, r1\n\
	strb r4, [r0]\n\
	ldr r1, _08096548 @ =0x0879C5A4\n\
	ldr r0, _0809654C @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	ldr r0, [r0, #0x1c]\n\
	str r0, [r5]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #2\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096544: .4byte 0x00000212\n\
_08096548: .4byte 0x0879C5A4\n\
_0809654C: .4byte 0x03000011\n\
_08096550:\n\
	ldr r0, [r5]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08096578\n\
	ldr r0, _08096598 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _08096578\n\
	movs r7, #0x86\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _08096578\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_08096578:\n\
	ldr r3, _0809659C @ =gNonGameplayRam\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r4, #0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	ldrb r2, [r0]\n\
	cmp r2, #2\n\
	bne _080965A0\n\
	strb r4, [r0]\n\
	b _080965AE\n\
	.align 2, 0\n\
_08096598: .4byte gChangedInput\n\
_0809659C: .4byte gNonGameplayRam\n\
_080965A0:\n\
	cmp r2, #3\n\
	bne _080965AE\n\
	strb r4, [r0]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r0, r3, r7\n\
	strb r2, [r0]\n\
_080965AE:\n\
	bl EndingCheckMonologueEnded\n\
	cmp r0, #0\n\
	beq _080965CC\n\
	ldr r3, _080965DC @ =gNonGameplayRam\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r3, r0\n\
	movs r2, #0\n\
	movs r0, #3\n\
	strb r0, [r1]\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r0, r3, r1\n\
	strb r2, [r0]\n\
_080965CC:\n\
	ldr r0, _080965DC @ =gNonGameplayRam\n\
	ldr r2, _080965E0 @ =0x00000213\n\
	adds r1, r0, r2\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080965E4\n\
	movs r0, #0x64\n\
	b _080968D6\n\
	.align 2, 0\n\
_080965DC: .4byte gNonGameplayRam\n\
_080965E0: .4byte 0x00000213\n\
_080965E4:\n\
	cmp r0, #1\n\
	beq _080965EA\n\
	b _080968D8\n\
_080965EA:\n\
	movs r0, #0x64\n\
	strb r0, [r1]\n\
	bl SpecialCutsceneProcessMonologue\n\
	b _080968D8\n\
_080965F4:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _08096618\n\
	ldr r1, _08096610 @ =gWrittenToBldalpha_Evb\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096614 @ =gWrittenToBldalpha_Eva\n\
_08096608:\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	b _080968D8\n\
	.align 2, 0\n\
_08096610: .4byte gWrittenToBldalpha_Evb\n\
_08096614: .4byte gWrittenToBldalpha_Eva\n\
_08096618:\n\
	cmp r0, #0x14\n\
	beq _0809661E\n\
	b _080968D8\n\
_0809661E:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096634 @ =0x04000050\n\
	ldr r2, _08096638 @ =0x00001841\n\
	adds r0, r2, #0\n\
	strh r0, [r1]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #4\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096634: .4byte 0x04000050\n\
_08096638: .4byte 0x00001841\n\
_0809663C:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #4\n\
	beq _0809664A\n\
	b _080968D8\n\
_0809664A:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r2, _0809668C @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r2]\n\
	cmp r0, #0xf\n\
	bhi _0809665A\n\
	adds r0, #1\n\
	strh r0, [r2]\n\
_0809665A:\n\
	ldr r1, _08096690 @ =gWrittenToBldalpha_Eva\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _08096666\n\
	subs r0, #1\n\
	strh r0, [r1]\n\
_08096666:\n\
	ldrh r0, [r2]\n\
	cmp r0, #0x10\n\
	beq _0809666E\n\
	b _080968D8\n\
_0809666E:\n\
	ldrh r0, [r1]\n\
	cmp r0, #0\n\
	beq _08096676\n\
	b _080968D8\n\
_08096676:\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _08096694 @ =0x0000FEFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #5\n\
	b _080968D6\n\
	.align 2, 0\n\
_0809668C: .4byte gWrittenToBldalpha_Evb\n\
_08096690: .4byte gWrittenToBldalpha_Eva\n\
_08096694: .4byte 0x0000FEFF\n\
_08096698:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r2, r5, r7\n\
	ldrh r0, [r2]\n\
	cmp r0, #0xa\n\
	bne _080966B2\n\
	movs r0, #0x1e\n\
	movs r1, #0x78\n\
	movs r2, #0x50\n\
	movs r3, #1\n\
	bl EndingDialogueSetupOam\n\
	b _080968D8\n\
_080966B2:\n\
	cmp r0, #0x27\n\
	bne _080966C0\n\
	ldr r1, _080966BC @ =gWrittenToBldy\n\
	b _08096608\n\
	.align 2, 0\n\
_080966BC: .4byte gWrittenToBldy\n\
_080966C0:\n\
	cmp r0, #0x28\n\
	beq _080966C6\n\
	b _080968D8\n\
_080966C6:\n\
	ldr r1, _080966DC @ =0x04000050\n\
	movs r0, #0xff\n\
	strh r0, [r1]\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #6\n\
	b _080968D6\n\
	.align 2, 0\n\
_080966DC: .4byte 0x04000050\n\
_080966E0:\n\
	movs r2, #0x84\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	beq _080966EE\n\
	b _080968D8\n\
_080966EE:\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r7, #0x85\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #7\n\
	b _080968D6\n\
_080966FC:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	bl EndingAdamConversationInit\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #8\n\
	strb r0, [r1]\n\
	b _08096920\n\
_08096716:\n\
	ldr r1, _08096738 @ =gWrittenToBldy\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	movs r0, #0x93\n\
	lsls r0, r0, #2\n\
	bl SoundPlay\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #9\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096738: .4byte gWrittenToBldy\n\
_0809673C:\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r4, r5, r1\n\
	ldrh r0, [r4]\n\
	cmp r0, #0xa\n\
	beq _08096806\n\
	cmp r0, #0x28\n\
	bne _08096806\n\
	movs r0, #0xff\n\
	movs r1, #0\n\
	movs r2, #0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #6\n\
	movs r1, #0x14\n\
	movs r2, #0xc0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #7\n\
	movs r1, #0x80\n\
	movs r2, #0xc0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #9\n\
	movs r1, #0x80\n\
	movs r2, #0xc0\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
	movs r0, #0\n\
	strh r0, [r4]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xa\n\
	b _08096804\n\
_0809678A:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r0, [r5]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _080967BC\n\
	ldr r0, _080967D4 @ =gChangedInput\n\
	ldrh r1, [r0]\n\
	movs r0, #1\n\
	ands r0, r1\n\
	cmp r0, #0\n\
	beq _080967BC\n\
	movs r0, #0x86\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrb r0, [r1]\n\
	cmp r0, #0\n\
	bne _080967BC\n\
	movs r0, #1\n\
	strb r0, [r1]\n\
_080967BC:\n\
	movs r1, #0x86\n\
	lsls r1, r1, #2\n\
	adds r3, r5, r1\n\
	ldrb r0, [r3]\n\
	cmp r0, #2\n\
	bne _080967DC\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	ldr r0, _080967D8 @ =0x00000203\n\
	bl SoundPlay\n\
	b _08096806\n\
	.align 2, 0\n\
_080967D4: .4byte gChangedInput\n\
_080967D8: .4byte 0x00000203\n\
_080967DC:\n\
	cmp r0, #3\n\
	bne _08096806\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _08096814 @ =0x0000FEFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r0, #0\n\
	strb r0, [r3]\n\
	ldr r0, _08096818 @ =0x00000203\n\
	bl SoundPlay\n\
	movs r0, #0xa\n\
	bl FadeMusic\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xb\n\
_08096804:\n\
	strb r0, [r1]\n\
_08096806:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	bl EndingProcessAdamText\n\
	b _08096920\n\
	.align 2, 0\n\
_08096814: .4byte 0x0000FEFF\n\
_08096818: .4byte 0x00000203\n\
_0809681C:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	b _080968D8\n\
_08096828:\n\
	movs r0, #0x84\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	ldrh r0, [r1]\n\
	cmp r0, #1\n\
	bne _0809685C\n\
	ldr r2, _08096850 @ =0x080A8CDC\n\
	ldr r0, _08096854 @ =0x080A8D3C\n\
	ldr r1, _08096858 @ =0x00001264\n\
	adds r0, r0, r1\n\
	ldrh r1, [r0]\n\
	lsls r0, r1, #1\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r2\n\
	ldr r0, [r0]\n\
	movs r1, #0\n\
	bl ApplyMusicSoundFading\n\
	b _080968D8\n\
	.align 2, 0\n\
_08096850: .4byte 0x080A8CDC\n\
_08096854: .4byte 0x080A8D3C\n\
_08096858: .4byte 0x00001264\n\
_0809685C:\n\
	cmp r0, #0xa\n\
	bne _080968D8\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096874 @ =gWrittenToBldy\n\
	movs r0, #0x10\n\
	strh r0, [r1]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xd\n\
	b _080968D6\n\
	.align 2, 0\n\
_08096874: .4byte gWrittenToBldy\n\
_08096878:\n\
	bl EndingAnimalsInit\n\
	ldr r2, _08096898 @ =gNonGameplayRam\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r0, r2, r7\n\
	movs r1, #0\n\
	strh r1, [r0]\n\
	ldr r0, _0809689C @ =gWrittenToBldy\n\
	strh r1, [r0]\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r2, r0\n\
	movs r0, #0xe\n\
	strb r0, [r1]\n\
	b _08096920\n\
	.align 2, 0\n\
_08096898: .4byte gNonGameplayRam\n\
_0809689C: .4byte gWrittenToBldy\n\
_080968A0:\n\
	movs r1, #0x84\n\
	lsls r1, r1, #2\n\
	adds r2, r5, r1\n\
	ldrh r1, [r2]\n\
	cmp r1, #1\n\
	bne _080968B6\n\
	movs r0, #0x53\n\
	movs r1, #0xe\n\
	bl PlayMusic\n\
	b _080968D8\n\
_080968B6:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #2\n\
	cmp r1, r0\n\
	bne _080968D8\n\
	movs r0, #0\n\
	strh r0, [r2]\n\
	movs r2, #0x80\n\
	lsls r2, r2, #0x13\n\
	ldrh r1, [r2]\n\
	ldr r0, _080968E4 @ =0x0000FBFF\n\
	ands r0, r1\n\
	strh r0, [r2]\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r1, r5, r2\n\
	movs r0, #0xf\n\
_080968D6:\n\
	strb r0, [r1]\n\
_080968D8:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
	b _08096920\n\
	.align 2, 0\n\
_080968E4: .4byte 0x0000FBFF\n\
_080968E8:\n\
	movs r7, #0x84\n\
	lsls r7, r7, #2\n\
	adds r1, r5, r7\n\
	ldrh r0, [r1]\n\
	cmp r0, #2\n\
	bne _08096918\n\
	movs r0, #0\n\
	strh r0, [r1]\n\
	ldr r1, _08096908 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809690C\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _08096918\n\
	.align 2, 0\n\
_08096908: .4byte gWrittenToBldy\n\
_0809690C:\n\
	movs r0, #0x85\n\
	lsls r0, r0, #2\n\
	adds r1, r5, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	movs r6, #1\n\
_08096918:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_08096920:\n\
	adds r0, r6, #0\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x08096928
NAKED_FUNCTION
void EndingInShip(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, lr}\n\
	movs r5, #0\n\
	ldr r4, _08096940 @ =gNonGameplayRam\n\
	ldrh r0, [r4, #8]\n\
	cmp r0, #1\n\
	beq _08096954\n\
	cmp r0, #1\n\
	bgt _08096944\n\
	cmp r0, #0\n\
	beq _0809694E\n\
	b _080969A8\n\
	.align 2, 0\n\
_08096940: .4byte gNonGameplayRam\n\
_08096944:\n\
	cmp r0, #2\n\
	beq _0809696C\n\
	cmp r0, #3\n\
	beq _08096988\n\
	b _080969A8\n\
_0809694E:\n\
	bl EndingMonologueInit\n\
	b _08096960\n\
_08096954:\n\
	bl SpecialCutsceneFadeIn\n\
	ldr r0, _08096968 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	cmp r0, #0\n\
	bne _080969A8\n\
_08096960:\n\
	movs r0, #2\n\
	strh r0, [r4, #8]\n\
	b _080969A8\n\
	.align 2, 0\n\
_08096968: .4byte gWrittenToBldy\n\
_0809696C:\n\
	bl EndingInShipProcess\n\
	cmp r0, #0\n\
	beq _080969A8\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	subs r1, #1\n\
	adds r0, r4, r1\n\
	strb r5, [r0]\n\
	movs r0, #3\n\
	strh r0, [r4, #8]\n\
	b _080969A8\n\
_08096988:\n\
	ldr r1, _08096998 @ =gWrittenToBldy\n\
	ldrh r0, [r1]\n\
	cmp r0, #0xf\n\
	bhi _0809699C\n\
	adds r0, #1\n\
	strh r0, [r1]\n\
	b _080969A0\n\
	.align 2, 0\n\
_08096998: .4byte gWrittenToBldy\n\
_0809699C:\n\
	strh r5, [r4, #8]\n\
	movs r5, #1\n\
_080969A0:\n\
	bl SpecialCutsceneProcessOam\n\
	bl SpecialCutsceneDrawAllOam\n\
_080969A8:\n\
	adds r0, r5, #0\n\
	pop {r4, r5}\n\
	pop {r1}\n\
	bx r1\n\
    .syntax divided\n");
}

// 0x080969B0
NAKED_FUNCTION
void EndingProcessMonologueCursor(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldr r3, _080969D0 @ =gNonGameplayRam\n\
	ldr r0, [r3]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _080969D4\n\
	movs r0, #0x76\n\
	strh r0, [r2, #0xc]\n\
	ldrh r0, [r3, #0xe]\n\
	lsls r0, r0, #3\n\
	adds r0, #0x18\n\
	strh r0, [r2, #0xe]\n\
	b _080969DA\n\
	.align 2, 0\n\
_080969D0: .4byte gNonGameplayRam\n\
_080969D4:\n\
	movs r0, #0x82\n\
	lsls r0, r0, #1\n\
	strh r0, [r2, #0xc]\n\
_080969DA:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x080969E0
NAKED_FUNCTION
void unk_969e0(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _08096A02\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _08096A02\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _08096A02\n\
	strb r1, [r2, #0x12]\n\
_08096A02:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08096A08
NAKED_FUNCTION
void EndingProcessSr388RadarView(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _08096A34\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _08096A34\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _08096A34\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
	ldr r0, _08096A38 @ =0x08633EC4\n\
	str r0, [r2, #0x1c]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
_08096A34:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08096A38: .4byte 0x08633EC4\n\
    .syntax divided\n");
}

// 0x08096A3C
NAKED_FUNCTION
void EndingProcessSamusViewRadarView(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _08096A68\n\
	ldrb r0, [r2, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r2, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _08096A68\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _08096A68\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
	ldr r0, _08096A6C @ =0x08633F0C\n\
	str r0, [r2, #0x1c]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
_08096A68:\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08096A6C: .4byte 0x08633F0C\n\
    .syntax divided\n");
}

// 0x08096A70
NAKED_FUNCTION
void unk_96a70(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r6, r1, r0\n\
	ldrb r5, [r4, #0x14]\n\
	cmp r5, #0\n\
	bne _08096AB4\n\
	ldr r0, [r4, #0x10]\n\
	ldr r1, _08096AAC @ =0x00FFFF00\n\
	ands r0, r1\n\
	ldr r1, _08096AB0 @ =0x00010100\n\
	cmp r0, r1\n\
	bne _08096A96\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #1\n\
	bl SoundPlay\n\
_08096A96:\n\
	ldrb r0, [r6, #4]\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r0, r1\n\
	bne _08096B06\n\
	ldrb r0, [r6, #0xc]\n\
	cmp r0, #0\n\
	bne _08096B06\n\
	strb r5, [r4, #0x12]\n\
	movs r0, #1\n\
	strb r0, [r4, #0x14]\n\
	b _08096B06\n\
	.align 2, 0\n\
_08096AAC: .4byte 0x00FFFF00\n\
_08096AB0: .4byte 0x00010100\n\
_08096AB4:\n\
	cmp r5, #1\n\
	bne _08096AE8\n\
	movs r1, #0\n\
	strb r1, [r4, #0x12]\n\
	ldr r0, _08096ADC @ =gNonGameplayRam\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xb\n\
	bne _08096B06\n\
	strb r1, [r4, #0x11]\n\
	ldr r0, _08096AE0 @ =0x08633244\n\
	str r0, [r4, #0x1c]\n\
	ldr r0, _08096AE4 @ =0x0000011D\n\
	bl SoundPlay\n\
	movs r0, #2\n\
	strb r0, [r4, #0x14]\n\
	b _08096B06\n\
	.align 2, 0\n\
_08096ADC: .4byte gNonGameplayRam\n\
_08096AE0: .4byte 0x08633244\n\
_08096AE4: .4byte 0x0000011D\n\
_08096AE8:\n\
	cmp r5, #2\n\
	bne _08096B06\n\
	ldrb r0, [r6, #4]\n\
	ldrb r1, [r4, #0x12]\n\
	cmp r0, r1\n\
	bne _08096B06\n\
	ldrb r1, [r6, #0xc]\n\
	cmp r1, #0\n\
	bne _08096B06\n\
	strb r1, [r4, #0x10]\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4, #0x18]\n\
_08096B06:\n\
	pop {r4, r5, r6}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided\n");
}

// 0x08096B0C
NAKED_FUNCTION
void EndingProcessAdamTextCursor(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldr r3, _08096B28 @ =gNonGameplayRam\n\
	ldr r0, [r3]\n\
	ldrh r1, [r0]\n\
	movs r0, #0xff\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08096B2C\n\
	movs r0, #0x91\n\
	lsls r0, r0, #1\n\
	strh r0, [r2, #0xc]\n\
	b _08096B8E\n\
	.align 2, 0\n\
_08096B28: .4byte gNonGameplayRam\n\
_08096B2C:\n\
	movs r0, #0xfe\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	beq _08096B70\n\
	movs r0, #0xfd\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08096B54\n\
	movs r0, #0\n\
	movs r1, #0x91\n\
	lsls r1, r1, #1\n\
	strh r1, [r2, #0xc]\n\
	strb r0, [r2, #0x12]\n\
	strb r0, [r2, #0x11]\n\
	ldr r0, _08096B50 @ =0x08633E8C\n\
	str r0, [r2, #0x1c]\n\
	b _08096B8E\n\
	.align 2, 0\n\
_08096B50: .4byte 0x08633E8C\n\
_08096B54:\n\
	movs r0, #0xfc\n\
	lsls r0, r0, #8\n\
	cmp r1, r0\n\
	bne _08096B70\n\
	movs r0, #0x78\n\
	strh r0, [r2, #0xc]\n\
	movs r0, #0x9a\n\
	strh r0, [r2, #0xe]\n\
	ldr r0, _08096B6C @ =0x08633E64\n\
	str r0, [r2, #0x1c]\n\
	b _08096B8E\n\
	.align 2, 0\n\
_08096B6C: .4byte 0x08633E64\n\
_08096B70:\n\
	ldrh r0, [r3, #0xc]\n\
	ldr r4, _08096B94 @ =0x00000212\n\
	adds r1, r3, r4\n\
	lsls r0, r0, #3\n\
	ldrb r1, [r1]\n\
	adds r0, r0, r1\n\
	adds r0, #0xe\n\
	movs r1, #0\n\
	strh r0, [r2, #0xc]\n\
	ldrh r0, [r3, #0xe]\n\
	lsls r0, r0, #3\n\
	adds r0, #0x84\n\
	strh r0, [r2, #0xe]\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
_08096B8E:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08096B94: .4byte 0x00000212\n\
    .syntax divided\n");
}

// 0x08096B98
NAKED_FUNCTION
void EndingProcessAdamPanel(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r4, r0, #0\n\
	ldrb r0, [r4, #0x14]\n\
	cmp r0, #0\n\
	bne _08096BD4\n\
	strb r0, [r4, #0x12]\n\
	strb r0, [r4, #0x11]\n\
	ldrh r1, [r4, #0xe]\n\
	movs r2, #0xe\n\
	ldrsh r0, [r4, r2]\n\
	cmp r0, #0x80\n\
	ble _08096BB8\n\
	adds r0, r1, #0\n\
	subs r0, #8\n\
	strh r0, [r4, #0xe]\n\
	b _08096D34\n\
_08096BB8:\n\
	movs r0, #0x80\n\
	strh r0, [r4, #0xe]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #7\n\
	bne _08096BC8\n\
	ldr r0, _08096BD0 @ =0x0000020A\n\
	bl SoundPlay\n\
_08096BC8:\n\
	movs r0, #1\n\
	strb r0, [r4, #0x14]\n\
	b _08096D34\n\
	.align 2, 0\n\
_08096BD0: .4byte 0x0000020A\n\
_08096BD4:\n\
	cmp r0, #1\n\
	bne _08096C64\n\
	ldrb r0, [r4, #0x11]\n\
	lsls r0, r0, #3\n\
	ldr r1, [r4, #0x1c]\n\
	adds r1, r1, r0\n\
	ldrb r0, [r1, #4]\n\
	ldrb r3, [r4, #0x12]\n\
	cmp r0, r3\n\
	bne _08096C12\n\
	ldrb r1, [r1, #0xc]\n\
	cmp r1, #0\n\
	bne _08096BF4\n\
	strb r1, [r4, #0x12]\n\
	movs r0, #2\n\
	strb r0, [r4, #0x14]\n\
_08096BF4:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #7\n\
	beq _08096BFC\n\
	b _08096D34\n\
_08096BFC:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0xa\n\
	bne _08096C12\n\
	movs r0, #0xc\n\
	ldrsh r1, [r4, r0]\n\
	movs r3, #0xe\n\
	ldrsh r2, [r4, r3]\n\
	movs r0, #8\n\
	movs r3, #0\n\
	bl EndingDialogueSetupOam\n\
_08096C12:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #7\n\
	beq _08096C1A\n\
	b _08096D34\n\
_08096C1A:\n\
	ldrb r0, [r4, #0x11]\n\
	cmp r0, #0xb\n\
	beq _08096C22\n\
	b _08096D34\n\
_08096C22:\n\
	ldrb r0, [r4, #0x12]\n\
	cmp r0, #0xf\n\
	beq _08096C2A\n\
	b _08096D34\n\
_08096C2A:\n\
	ldr r2, _08096C54 @ =gNonGameplayRam\n\
	ldr r0, _08096C58 @ =0x00000212\n\
	adds r1, r2, r0\n\
	movs r0, #0\n\
	strb r0, [r1]\n\
	strh r0, [r2, #0xe]\n\
	strh r0, [r2, #0xc]\n\
	ldr r1, _08096C5C @ =0x0879C3AC\n\
	ldr r0, _08096C60 @ =0x03000011\n\
	ldrb r0, [r0]\n\
	lsls r0, r0, #0x18\n\
	asrs r0, r0, #0x18\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, #0xe0\n\
	lsls r1, r1, #1\n\
	adds r0, r0, r1\n\
	ldr r0, [r0]\n\
	str r0, [r2]\n\
	b _08096D34\n\
	.align 2, 0\n\
_08096C54: .4byte gNonGameplayRam\n\
_08096C58: .4byte 0x00000212\n\
_08096C5C: .4byte 0x0879C3AC\n\
_08096C60: .4byte 0x03000011\n\
_08096C64:\n\
	cmp r0, #2\n\
	bne _08096C82\n\
	movs r1, #0\n\
	strb r1, [r4, #0x12]\n\
	ldrb r0, [r4, #0x13]\n\
	adds r0, #1\n\
	strb r0, [r4, #0x13]\n\
	lsls r0, r0, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #1\n\
	bne _08096D34\n\
	strb r1, [r4, #0x13]\n\
	movs r0, #3\n\
	strb r0, [r4, #0x14]\n\
	b _08096D34\n\
_08096C82:\n\
	cmp r0, #3\n\
	bne _08096CCC\n\
	movs r1, #0\n\
	strb r1, [r4, #0x12]\n\
	ldr r0, _08096CAC @ =gNonGameplayRam\n\
	movs r2, #0x85\n\
	lsls r2, r2, #2\n\
	adds r0, r0, r2\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xb\n\
	bne _08096D34\n\
	strb r1, [r4, #0x11]\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #7\n\
	bne _08096CB8\n\
	ldr r0, _08096CB0 @ =0x086332FC\n\
	str r0, [r4, #0x1c]\n\
	ldr r0, _08096CB4 @ =0x0000020B\n\
	bl SoundPlay\n\
	b _08096CC0\n\
	.align 2, 0\n\
_08096CAC: .4byte gNonGameplayRam\n\
_08096CB0: .4byte 0x086332FC\n\
_08096CB4: .4byte 0x0000020B\n\
_08096CB8:\n\
	cmp r0, #9\n\
	bne _08096CC0\n\
	ldr r0, _08096CC8 @ =0x086333CC\n\
	str r0, [r4, #0x1c]\n\
_08096CC0:\n\
	movs r0, #4\n\
	strb r0, [r4, #0x14]\n\
	b _08096D34\n\
	.align 2, 0\n\
_08096CC8: .4byte 0x086333CC\n\
_08096CCC:\n\
	cmp r0, #4\n\
	bne _08096CFC\n\
	ldr r0, [r4, #0x10]\n\
	ldr r1, _08096CF4 @ =0x00FFFF00\n\
	ands r0, r1\n\
	ldr r1, _08096CF8 @ =0x00030B00\n\
	cmp r0, r1\n\
	bne _08096D34\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #7\n\
	bne _08096CE8\n\
	movs r0, #8\n\
	bl SpecialCutsceneDestroyOamOfType\n\
_08096CE8:\n\
	movs r0, #0\n\
	strb r0, [r4, #0x12]\n\
	movs r0, #5\n\
	strb r0, [r4, #0x14]\n\
	b _08096D34\n\
	.align 2, 0\n\
_08096CF4: .4byte 0x00FFFF00\n\
_08096CF8: .4byte 0x00030B00\n\
_08096CFC:\n\
	cmp r0, #5\n\
	bne _08096D34\n\
	movs r2, #0\n\
	strb r2, [r4, #0x12]\n\
	ldrh r1, [r4, #0xe]\n\
	movs r3, #0xe\n\
	ldrsh r0, [r4, r3]\n\
	cmp r0, #0xbf\n\
	bgt _08096D16\n\
	adds r0, r1, #0\n\
	adds r0, #8\n\
	strh r0, [r4, #0xe]\n\
	b _08096D34\n\
_08096D16:\n\
	ldrb r0, [r4, #0x10]\n\
	cmp r0, #7\n\
	bne _08096D28\n\
	ldr r0, _08096D3C @ =gNonGameplayRam\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	movs r1, #0xc\n\
	strb r1, [r0]\n\
_08096D28:\n\
	strb r2, [r4, #0x10]\n\
	ldrb r1, [r4, #0x18]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	strb r0, [r4, #0x18]\n\
_08096D34:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_08096D3C: .4byte gNonGameplayRam\n\
    .syntax divided\n");
}

// 0x08096D40
NAKED_FUNCTION
void EndingProcessAdamIcon(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	adds r2, r0, #0\n\
	ldrb r3, [r2, #0x11]\n\
	lsls r1, r3, #3\n\
	ldr r0, [r2, #0x1c]\n\
	adds r4, r0, r1\n\
	ldrb r1, [r2, #0x14]\n\
	cmp r1, #0\n\
	bne _08096D80\n\
	cmp r3, #3\n\
	bne _08096D62\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
	ldr r0, _08096D78 @ =0x086338A4\n\
	str r0, [r2, #0x1c]\n\
	movs r0, #1\n\
	strb r0, [r2, #0x14]\n\
_08096D62:\n\
	ldr r0, _08096D7C @ =gNonGameplayRam\n\
	movs r3, #0x85\n\
	lsls r3, r3, #2\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xb\n\
	bne _08096DC0\n\
	strb r1, [r2, #0x12]\n\
	strb r1, [r2, #0x11]\n\
	b _08096D98\n\
	.align 2, 0\n\
_08096D78: .4byte 0x086338A4\n\
_08096D7C: .4byte gNonGameplayRam\n\
_08096D80:\n\
	cmp r1, #1\n\
	bne _08096DAC\n\
	ldr r0, _08096DA4 @ =gNonGameplayRam\n\
	movs r1, #0x85\n\
	lsls r1, r1, #2\n\
	adds r0, r0, r1\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xb\n\
	bne _08096DC0\n\
	movs r0, #0\n\
	strb r0, [r2, #0x12]\n\
	strb r0, [r2, #0x11]\n\
_08096D98:\n\
	ldr r0, _08096DA8 @ =0x0863345C\n\
	str r0, [r2, #0x1c]\n\
	movs r0, #2\n\
	strb r0, [r2, #0x14]\n\
	b _08096DC0\n\
	.align 2, 0\n\
_08096DA4: .4byte gNonGameplayRam\n\
_08096DA8: .4byte 0x0863345C\n\
_08096DAC:\n\
	cmp r1, #2\n\
	bne _08096DC0\n\
	ldrb r0, [r4, #4]\n\
	ldrb r3, [r2, #0x12]\n\
	cmp r0, r3\n\
	bne _08096DC0\n\
	ldrb r0, [r4, #0xc]\n\
	cmp r0, #0\n\
	bne _08096DC0\n\
	strb r0, [r2, #0x12]\n\
_08096DC0:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08096DC8
NAKED_FUNCTION
void EndingProcessAnimalsScrolling(void)
{
    asm(" .syntax unified\n\
	push {r4, lr}\n\
	sub sp, #4\n\
	adds r2, r0, #0\n\
	ldrb r0, [r2, #0x13]\n\
	adds r1, r0, #1\n\
	movs r3, #0\n\
	strb r1, [r2, #0x13]\n\
	ldrb r0, [r2, #0x14]\n\
	cmp r0, #0\n\
	bne _08096E48\n\
	ldr r0, _08096E20 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r2, #0xc]\n\
	ldr r0, _08096E24 @ =0x0300122E\n\
	ldrh r1, [r0]\n\
	strh r1, [r2, #0xe]\n\
	ldr r0, _08096E28 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r2]\n\
	ldr r0, _08096E2C @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r2, #2]\n\
	lsls r1, r1, #0x10\n\
	asrs r1, r1, #0x10\n\
	movs r0, #0x20\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	bge _08096E3C\n\
	movs r0, #0x80\n\
	lsls r0, r0, #7\n\
	strh r0, [r2, #0xa]\n\
	str r3, [sp]\n\
	ldr r1, _08096E30 @ =0x040000D4\n\
	mov r0, sp\n\
	str r0, [r1]\n\
	ldrh r0, [r2, #0xa]\n\
	ldr r3, _08096E34 @ =0x06008000\n\
	adds r0, r0, r3\n\
	str r0, [r1, #4]\n\
	ldr r0, _08096E38 @ =0x85000400\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _08096E42\n\
	.align 2, 0\n\
_08096E20: .4byte 0x0300122C\n\
_08096E24: .4byte 0x0300122E\n\
_08096E28: .4byte 0x03001230\n\
_08096E2C: .4byte 0x03001232\n\
_08096E30: .4byte 0x040000D4\n\
_08096E34: .4byte 0x06008000\n\
_08096E38: .4byte 0x85000400\n\
_08096E3C:\n\
	movs r0, #0xa0\n\
	lsls r0, r0, #7\n\
	strh r0, [r2, #0xa]\n\
_08096E42:\n\
	movs r0, #0\n\
	strb r0, [r2, #0x13]\n\
	b _08096E56\n\
_08096E48:\n\
	cmp r0, #1\n\
	bne _08096E5C\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #0xa\n\
	bne _08096EF6\n\
	strb r3, [r2, #0x13]\n\
_08096E56:\n\
	movs r0, #2\n\
	strb r0, [r2, #0x14]\n\
	b _08096EF6\n\
_08096E5C:\n\
	ldr r0, _08096ED8 @ =gNonGameplayRam\n\
	movs r4, #0x85\n\
	lsls r4, r4, #2\n\
	adds r0, r0, r4\n\
	ldrb r0, [r0]\n\
	cmp r0, #0xe\n\
	bne _08096EF4\n\
	lsls r0, r1, #0x18\n\
	lsrs r0, r0, #0x18\n\
	cmp r0, #2\n\
	bne _08096EA6\n\
	strb r3, [r2, #0x13]\n\
	ldrh r3, [r2, #0xe]\n\
	movs r0, #0xe\n\
	ldrsh r1, [r2, r0]\n\
	movs r0, #0xa0\n\
	rsbs r0, r0, #0\n\
	cmp r1, r0\n\
	ble _08096E8C\n\
	subs r0, r3, #1\n\
	strh r0, [r2, #0xe]\n\
	ldrh r0, [r2, #8]\n\
	adds r0, #1\n\
	strh r0, [r2, #8]\n\
_08096E8C:\n\
	ldrh r1, [r2, #2]\n\
	movs r3, #2\n\
	ldrsh r0, [r2, r3]\n\
	cmp r0, #0\n\
	ble _08096E9A\n\
	subs r0, r1, #1\n\
	strh r0, [r2, #2]\n\
_08096E9A:\n\
	ldr r1, _08096EDC @ =0x0300122E\n\
	ldrh r0, [r2, #0xe]\n\
	strh r0, [r1]\n\
	ldr r1, _08096EE0 @ =0x03001232\n\
	ldrh r0, [r2, #2]\n\
	strh r0, [r1]\n\
_08096EA6:\n\
	movs r4, #8\n\
	ldrsh r0, [r2, r4]\n\
	cmp r0, #9\n\
	bne _08096EF6\n\
	movs r1, #0\n\
	strh r1, [r2, #8]\n\
	ldrh r0, [r2, #0xa]\n\
	cmp r0, #0\n\
	beq _08096EF6\n\
	ldr r3, _08096EE4 @ =0xFFFFFC00\n\
	adds r0, r0, r3\n\
	strh r0, [r2, #0xa]\n\
	str r1, [sp]\n\
	ldr r1, _08096EE8 @ =0x040000D4\n\
	mov r4, sp\n\
	str r4, [r1]\n\
	ldrh r0, [r2, #0xa]\n\
	ldr r2, _08096EEC @ =0x06008000\n\
	adds r0, r0, r2\n\
	str r0, [r1, #4]\n\
	ldr r0, _08096EF0 @ =0x85000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	b _08096EF6\n\
	.align 2, 0\n\
_08096ED8: .4byte gNonGameplayRam\n\
_08096EDC: .4byte 0x0300122E\n\
_08096EE0: .4byte 0x03001232\n\
_08096EE4: .4byte 0xFFFFFC00\n\
_08096EE8: .4byte 0x040000D4\n\
_08096EEC: .4byte 0x06008000\n\
_08096EF0: .4byte 0x85000100\n\
_08096EF4:\n\
	strb r3, [r2, #0x13]\n\
_08096EF6:\n\
	add sp, #4\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08096F00
NAKED_FUNCTION
void unk_96f00(void)
{
    asm(" .syntax unified\n\
	movs r1, #0\n\
	strb r1, [r0, #0x10]\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08096F08
NAKED_FUNCTION
void EndingDialogueSetupOam(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, #4\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	lsls r1, r1, #0x10\n\
	lsrs r6, r1, #0x10\n\
	lsls r2, r2, #0x10\n\
	lsrs r2, r2, #0x10\n\
	mov r8, r2\n\
	lsls r3, r3, #0x18\n\
	cmp r3, #0\n\
	bne _08096F68\n\
	movs r2, #0\n\
	ldr r0, _08096F64 @ =gNonGameplayRam\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
	adds r1, r0, r3\n\
	ldrb r1, [r1]\n\
	mov ip, r0\n\
	cmp r1, #0\n\
	beq _08096F58\n\
	mov r4, ip\n\
_08096F38:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0x80\n\
	lsls r1, r1, #0x11\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bgt _08096FA8\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08096F38\n\
_08096F58:\n\
	lsls r0, r2, #0x18\n\
	asrs r1, r0, #0x18\n\
	adds r7, r0, #0\n\
	cmp r1, #0x13\n\
	ble _08096FB0\n\
	b _08096FA8\n\
	.align 2, 0\n\
_08096F64: .4byte gNonGameplayRam\n\
_08096F68:\n\
	movs r2, #0x13\n\
	ldr r0, _08096FAC @ =gNonGameplayRam\n\
	movs r3, #0x9b\n\
	lsls r3, r3, #3\n\
	adds r1, r0, r3\n\
	ldrb r1, [r1]\n\
	mov ip, r0\n\
	cmp r1, #0\n\
	beq _08096FA0\n\
	mov r4, ip\n\
	movs r3, #0x8b\n\
	lsls r3, r3, #2\n\
_08096F80:\n\
	lsls r0, r2, #0x18\n\
	movs r1, #0xff\n\
	lsls r1, r1, #0x18\n\
	adds r0, r0, r1\n\
	lsrs r2, r0, #0x18\n\
	asrs r1, r0, #0x18\n\
	cmp r1, #0\n\
	blt _08096FA8\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r0, r0, r4\n\
	adds r0, r0, r3\n\
	ldrb r0, [r0]\n\
	cmp r0, #0\n\
	bne _08096F80\n\
_08096FA0:\n\
	lsls r0, r2, #0x18\n\
	adds r7, r0, #0\n\
	cmp r7, #0\n\
	bge _08096FB0\n\
_08096FA8:\n\
	movs r0, #0x14\n\
	b _08097272\n\
	.align 2, 0\n\
_08096FAC: .4byte gNonGameplayRam\n\
_08096FB0:\n\
	movs r0, #0\n\
	str r0, [sp]\n\
	ldr r2, _08097014 @ =0x040000D4\n\
	mov r3, sp\n\
	str r3, [r2]\n\
	asrs r1, r7, #0x18\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r4, r0, #2\n\
	ldr r3, _08097018 @ =0x030016A0\n\
	adds r0, r4, r3\n\
	str r0, [r2, #4]\n\
	ldr r0, _0809701C @ =0x85000009\n\
	str r0, [r2, #8]\n\
	ldr r0, [r2, #8]\n\
	ldr r1, _08097020 @ =0xFFFFFDE4\n\
	adds r0, r3, r1\n\
	adds r2, r4, r0\n\
	movs r1, #0x8a\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	strh r6, [r0]\n\
	adds r1, #2\n\
	adds r0, r2, r1\n\
	mov r1, r8\n\
	strh r1, [r0]\n\
	movs r1, #0x8b\n\
	lsls r1, r1, #2\n\
	adds r0, r2, r1\n\
	strb r5, [r0]\n\
	movs r0, #0x8d\n\
	lsls r0, r0, #2\n\
	adds r6, r2, r0\n\
	ldrb r1, [r6]\n\
	movs r0, #1\n\
	orrs r1, r0\n\
	strb r1, [r6]\n\
	cmp r5, #1\n\
	bne _0809702C\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08097024 @ =0x08633E64\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08097028 @ =EndingProcessMonologueCursor\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_08097014: .4byte 0x040000D4\n\
_08097018: .4byte 0x030016A0\n\
_0809701C: .4byte 0x85000009\n\
_08097020: .4byte 0xFFFFFDE4\n\
_08097024: .4byte 0x08633E64\n\
_08097028: .4byte EndingProcessMonologueCursor\n\
_0809702C:\n\
	cmp r5, #2\n\
	bne _08097064\n\
	ldr r1, _08097058 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _0809705C @ =0x086338D4\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08097060 @ =unk_969e0\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_08097058: .4byte 0x00000236\n\
_0809705C: .4byte 0x086338D4\n\
_08097060: .4byte unk_969e0\n\
_08097064:\n\
	cmp r5, #3\n\
	bne _0809709C\n\
	ldr r0, _08097090 @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08097094 @ =0x086339D4\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08097098 @ =EndingProcessSr388RadarView\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_08097090: .4byte 0x00000236\n\
_08097094: .4byte 0x086339D4\n\
_08097098: .4byte EndingProcessSr388RadarView\n\
_0809709C:\n\
	cmp r5, #4\n\
	bne _080970D4\n\
	ldr r1, _080970C8 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _080970CC @ =0x08633C4C\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _080970D0 @ =EndingProcessSamusViewRadarView\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_080970C8: .4byte 0x00000236\n\
_080970CC: .4byte 0x08633C4C\n\
_080970D0: .4byte EndingProcessSamusViewRadarView\n\
_080970D4:\n\
	cmp r5, #5\n\
	bne _0809710C\n\
	ldr r0, _08097100 @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #8\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08097104 @ =0x086331EC\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _08097108 @ =unk_96a70\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_08097100: .4byte 0x00000236\n\
_08097104: .4byte 0x086331EC\n\
_08097108: .4byte unk_96a70\n\
_0809710C:\n\
	cmp r5, #6\n\
	bne _08097130\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08097128 @ =0x08633E8C\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809712C @ =EndingProcessAdamTextCursor\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_08097128: .4byte 0x08633E8C\n\
_0809712C: .4byte EndingProcessAdamTextCursor\n\
_08097130:\n\
	cmp r5, #7\n\
	bne _08097158\n\
	ldr r1, _08097150 @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08097154 @ =0x08633294\n\
	b _080971AE\n\
	.align 2, 0\n\
_08097150: .4byte 0x00000236\n\
_08097154: .4byte 0x08633294\n\
_08097158:\n\
	cmp r5, #8\n\
	bne _08097190\n\
	ldr r0, _08097184 @ =0x00000236\n\
	adds r2, r2, r0\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _08097188 @ =0x08633434\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _0809718C @ =EndingProcessAdamIcon\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_08097184: .4byte 0x00000236\n\
_08097188: .4byte 0x08633434\n\
_0809718C: .4byte EndingProcessAdamIcon\n\
_08097190:\n\
	cmp r5, #9\n\
	bne _080971C8\n\
	ldr r1, _080971BC @ =0x00000236\n\
	adds r2, r2, r1\n\
	ldrb r1, [r2]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	adds r0, r3, #0\n\
	adds r0, #0x1c\n\
	adds r0, r4, r0\n\
	ldr r1, _080971C0 @ =0x08633364\n\
_080971AE:\n\
	str r1, [r0]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _080971C4 @ =EndingProcessAdamPanel\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_080971BC: .4byte 0x00000236\n\
_080971C0: .4byte 0x08633364\n\
_080971C4: .4byte EndingProcessAdamPanel\n\
_080971C8:\n\
	cmp r5, #0x14\n\
	bne _080971E4\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r1, r0\n\
	strb r1, [r6]\n\
	adds r0, r3, #0\n\
	adds r0, #0x20\n\
	adds r0, r4, r0\n\
	ldr r1, _080971E0 @ =EndingProcessAnimalsScrolling\n\
	str r1, [r0]\n\
	b _08097270\n\
	.align 2, 0\n\
_080971E0: .4byte EndingProcessAnimalsScrolling\n\
_080971E4:\n\
	cmp r5, #0x1e\n\
	bne _08097238\n\
	ldr r0, _08097224 @ =0x0000012D\n\
	bl SoundPlay\n\
	ldr r4, _08097228 @ =gNonGameplayRam\n\
	asrs r0, r7, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	adds r3, r2, r4\n\
	ldr r0, _0809722C @ =0x00000236\n\
	adds r3, r3, r0\n\
	ldrb r1, [r3]\n\
	movs r0, #0xd\n\
	rsbs r0, r0, #0\n\
	ands r0, r1\n\
	movs r1, #4\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r1, #0x8e\n\
	lsls r1, r1, #2\n\
	adds r0, r4, r1\n\
	adds r0, r2, r0\n\
	ldr r1, _08097230 @ =0x08633F24\n\
	str r1, [r0]\n\
	movs r3, #0x8f\n\
	lsls r3, r3, #2\n\
	adds r4, r4, r3\n\
	adds r2, r2, r4\n\
	ldr r0, _08097234 @ =unk_97418\n\
	b _0809726E\n\
	.align 2, 0\n\
_08097224: .4byte 0x0000012D\n\
_08097228: .4byte gNonGameplayRam\n\
_0809722C: .4byte 0x00000236\n\
_08097230: .4byte 0x08633F24\n\
_08097234: .4byte unk_97418\n\
_08097238:\n\
	cmp r5, #0xff\n\
	bne _08097270\n\
	asrs r0, r7, #0x18\n\
	lsls r2, r0, #3\n\
	adds r2, r2, r0\n\
	lsls r2, r2, #2\n\
	mov r0, ip\n\
	adds r1, r2, r0\n\
	movs r3, #0x8d\n\
	lsls r3, r3, #2\n\
	adds r1, r1, r3\n\
	ldrb r3, [r1]\n\
	movs r0, #2\n\
	rsbs r0, r0, #0\n\
	ands r0, r3\n\
	strb r0, [r1]\n\
	movs r0, #0x8e\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	adds r0, r2, r0\n\
	ldr r1, _08097280 @ =0x086331EC\n\
	str r1, [r0]\n\
	movs r0, #0x8f\n\
	lsls r0, r0, #2\n\
	add r0, ip\n\
	adds r2, r2, r0\n\
	ldr r0, _08097284 @ =unk_96f00\n\
_0809726E:\n\
	str r0, [r2]\n\
_08097270:\n\
	lsrs r0, r7, #0x18\n\
_08097272:\n\
	add sp, #4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
_08097280: .4byte 0x086331EC\n\
_08097284: .4byte unk_96f00\n\
    .syntax divided\n");
}

// 0x08097288
NAKED_FUNCTION
void EndingMonologueVblank(void)
{
    asm(" .syntax unified\n\
	push {lr}\n\
	ldr r1, _080972EC @ =0x040000D4\n\
	ldr r0, _080972F0 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _080972F4 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _080972F8 @ =0x04000052\n\
	ldr r0, _080972FC @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08097300 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08097304 @ =0x04000054\n\
	ldr r0, _08097308 @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _0809730C @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097310 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097314 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097318 @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _0809731C @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _08097320 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bl unk_98158\n\
	pop {r0}\n\
	bx r0\n\
	.align 2, 0\n\
_080972EC: .4byte 0x040000D4\n\
_080972F0: .4byte gOamData\n\
_080972F4: .4byte 0x84000100\n\
_080972F8: .4byte 0x04000052\n\
_080972FC: .4byte gWrittenToBldalpha_Evb\n\
_08097300: .4byte gWrittenToBldalpha_Eva\n\
_08097304: .4byte 0x04000054\n\
_08097308: .4byte gWrittenToBldy\n\
_0809730C: .4byte gBg1XPosition\n\
_08097310: .4byte gBg1YPosition\n\
_08097314: .4byte 0x0300122C\n\
_08097318: .4byte 0x0300122E\n\
_0809731C: .4byte 0x03001230\n\
_08097320: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x08097324
NAKED_FUNCTION
void EndingConversationAndAnimalsVblank(void)
{
    asm(" .syntax unified\n\
	ldr r1, _08097380 @ =0x040000D4\n\
	ldr r0, _08097384 @ =gOamData\n\
	str r0, [r1]\n\
	movs r0, #0xe0\n\
	lsls r0, r0, #0x13\n\
	str r0, [r1, #4]\n\
	ldr r0, _08097388 @ =0x84000100\n\
	str r0, [r1, #8]\n\
	ldr r0, [r1, #8]\n\
	ldr r2, _0809738C @ =0x04000052\n\
	ldr r0, _08097390 @ =gWrittenToBldalpha_Evb\n\
	ldrh r0, [r0]\n\
	lsls r0, r0, #8\n\
	ldr r1, _08097394 @ =gWrittenToBldalpha_Eva\n\
	ldrh r1, [r1]\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	ldr r1, _08097398 @ =0x04000054\n\
	ldr r0, _0809739C @ =gWrittenToBldy\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r1, #0x40\n\
	ldr r0, _080973A0 @ =gBg1XPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080973A4 @ =gBg1YPosition\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080973A8 @ =0x0300122C\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080973AC @ =0x0300122E\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080973B0 @ =0x03001230\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	adds r1, #2\n\
	ldr r0, _080973B4 @ =0x03001232\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	bx lr\n\
	.align 2, 0\n\
_08097380: .4byte 0x040000D4\n\
_08097384: .4byte gOamData\n\
_08097388: .4byte 0x84000100\n\
_0809738C: .4byte 0x04000052\n\
_08097390: .4byte gWrittenToBldalpha_Evb\n\
_08097394: .4byte gWrittenToBldalpha_Eva\n\
_08097398: .4byte 0x04000054\n\
_0809739C: .4byte gWrittenToBldy\n\
_080973A0: .4byte gBg1XPosition\n\
_080973A4: .4byte gBg1YPosition\n\
_080973A8: .4byte 0x0300122C\n\
_080973AC: .4byte 0x0300122E\n\
_080973B0: .4byte 0x03001230\n\
_080973B4: .4byte 0x03001232\n\
    .syntax divided\n");
}

// 0x080973B8
NAKED_FUNCTION
void EndingGetPositionAndSlotOfOamByType_2(void)
{
    asm(" .syntax unified\n\
	push {r4, r5, r6, r7, lr}\n\
	adds r4, r1, #0\n\
	lsls r0, r0, #0x18\n\
	lsrs r5, r0, #0x18\n\
	movs r1, #0\n\
	ldr r7, _080973F0 @ =gNonGameplayRam\n\
	movs r6, #0x8b\n\
	lsls r6, r6, #2\n\
_080973C8:\n\
	lsls r0, r1, #3\n\
	adds r0, r0, r1\n\
	lsls r0, r0, #2\n\
	adds r3, r0, r7\n\
	adds r0, r3, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, r5\n\
	bne _080973F8\n\
	movs r5, #0x8a\n\
	lsls r5, r5, #2\n\
	adds r0, r3, r5\n\
	ldrh r0, [r0]\n\
	strh r0, [r4]\n\
	ldr r4, _080973F4 @ =0x0000022A\n\
	adds r0, r3, r4\n\
	ldrh r0, [r0]\n\
	strh r0, [r2]\n\
	adds r0, r1, #0\n\
	b _08097410\n\
	.align 2, 0\n\
_080973F0: .4byte gNonGameplayRam\n\
_080973F4: .4byte 0x0000022A\n\
_080973F8:\n\
	adds r0, r1, #1\n\
	lsls r0, r0, #0x18\n\
	lsrs r1, r0, #0x18\n\
	cmp r1, #0x13\n\
	bls _080973C8\n\
	movs r5, #0x96\n\
	lsls r5, r5, #1\n\
	adds r0, r5, #0\n\
	strh r0, [r4]\n\
	movs r0, #0xc8\n\
	strh r0, [r2]\n\
	movs r0, #0x14\n\
_08097410:\n\
	pop {r4, r5, r6, r7}\n\
	pop {r1}\n\
	bx r1\n\
	.align 2, 0\n\
    .syntax divided\n");
}

// 0x08097418
NAKED_FUNCTION
void unk_97418(void)
{
    asm(" .syntax unified\n\
	bx lr\n\
	.align 2, 0\n\
    .syntax divided\n");
}
