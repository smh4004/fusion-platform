#ifndef SECURITY_PAD_DATA_H
#define SECURITY_PAD_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sSecurityPadGfx[];
extern const u16 sSecurityPadPal[];

extern const struct FrameData sSecurityPadMonitorOam_Idle[2];
extern const struct FrameData sSecurityPadMonitorOam_ArmExtending[6];
extern const struct FrameData sSecurityPadScreenOam_Idle[5];
extern const struct FrameData sSecurityPadScreenOam_Unlocking[5];
extern const struct FrameData sSecurityPadScreenOam_Inactive[5];
extern const struct FrameData sSecurityPadMonitorOam_ArmRetracting[6];
extern const struct FrameData sSecurityPadOam_Pressing[5];
extern const struct FrameData sSecurityPadOam_Depressing[5];
extern const struct FrameData sSecurityPadOam_Idle[2];
extern const struct FrameData sSecurityPadOam_Pressed[2];
extern const struct FrameData sSecurityPadMonitorOam_ArmExtended[2];

extern const u16 sSecurityPad_2f78cc[];

#endif /* SECURITY_PAD_DATA_H */
