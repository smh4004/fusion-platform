#ifndef MISC_PAD_DATA_H
#define MISC_PAD_DATA_H

#include "macros.h"
#include "oam.h"

extern const u32 sControlPadGfx[];
extern const u16 sControlPadPal[];

extern const struct FrameData sControlPadConsoleOam_Inactive[5];
extern const struct FrameData sControlPadConsoleOam_Active[5];
extern const struct FrameData sControlPadOam_PressingSwitch[5];
extern const struct FrameData sControlPadOam_ReleasingSwitch[5];
extern const struct FrameData sControlPadOam_SwitchUnpressed[2];
extern const struct FrameData sControlPadOam_SwitchPressed[2];

extern const u32 sHabitationPadGfx[];
extern const u16 sHabitationPadPal[];

extern const struct FrameData sHabitationPadConsoleOam_Inactive[5];
extern const struct FrameData sHabitationPadConsoleOam_Active[5];
extern const struct FrameData sHabitationPadOam_PressingSwitch[5];
extern const struct FrameData sHabitationPadOam_ReleasingSwitch[5];
extern const struct FrameData sHabitationPadOam_SwitchUnpressed[2];
extern const struct FrameData sHabitationPadOam_SwitchPressed[2];

#endif /* MISC_PAD_DATA_H */
