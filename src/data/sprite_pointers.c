#include "data/sprite_pointers.h"
#include "sprites_AI/sprites.h"
#include "data/sprites/animals.h"
#include "data/sprites/arachnus.h"
#include "data/sprites/area_banner.h"
#include "data/sprites/atmospheric_stabilizer.h"
#include "data/sprites/beam_core_x.h"
#include "data/sprites/blue_x.h"
#include "data/sprites/box.h"
#include "data/sprites/box_2.h"
#include "data/sprites/bull.h"
#include "data/sprites/choot.h"
#include "data/sprites/chozo_statue.h"
#include "data/sprites/core_x.h"
#include "data/sprites/core_x_downloading_varia.h"
#include "data/sprites/data_pad.h"
#include "data/sprites/dessgeega.h"
#include "data/sprites/destroyed_data_pad.h"
#include "data/sprites/electric_water.h"
#include "data/sprites/evir.h"
#include "data/sprites/frozen_ridley.h"
#include "data/sprites/fune_namihe.h"
#include "data/sprites/gadora.h"
#include "data/sprites/gate.h"
#include "data/sprites/geega.h"
#include "data/sprites/geemer.h"
#include "data/sprites/genesis.h"
#include "data/sprites/geruboss.h"
#include "data/sprites/geruta.h"
#include "data/sprites/gunship.h"
#include "data/sprites/halzyn.h"
#include "data/sprites/hornoad.h"
#include "data/sprites/ice_beam_ability.h"
#include "data/sprites/kago.h"
#include "data/sprites/kihunter.h"
#include "data/sprites/lab_debris.h"
#include "data/sprites/lava_plume.h"
#include "data/sprites/mega_x.h"
#include "data/sprites/memu.h"
#include "data/sprites/message_banner.h"
#include "data/sprites/metroid.h"
#include "data/sprites/metroid_husk.h"
#include "data/sprites/mimic.h"
#include "data/sprites/misc_pad.h"
#include "data/sprites/missile_geron.h"
#include "data/sprites/missile_hatch.h"
#include "data/sprites/moto.h"
#include "data/sprites/movable_platform.h"
#include "data/sprites/navigation_pad.h"
#include "data/sprites/nettori.h"
#include "data/sprites/nightmare.h"
#include "data/sprites/omega_metroid.h"
#include "data/sprites/omega_metroid_husk.h"
#include "data/sprites/operations_room_pad.h"
#include "data/sprites/owtch.h"
#include "data/sprites/pillar.h"
#include "data/sprites/powamp.h"
#include "data/sprites/power_bomb_geron.h"
#include "data/sprites/puyo.h"
#include "data/sprites/recharge_pad.h"
#include "data/sprites/reo.h"
#include "data/sprites/ridley.h"
#include "data/sprites/ridley_pre_spawn.h"
#include "data/sprites/ripper.h"
#include "data/sprites/sa_x.h"
#include "data/sprites/sa_x_monster.h"
#include "data/sprites/save_pad.h"
#include "data/sprites/scientist.h"
#include "data/sprites/sciser.h"
#include "data/sprites/security_pad.h"
#include "data/sprites/sidehopper.h"
#include "data/sprites/skree.h"
#include "data/sprites/skultera.h"
#include "data/sprites/sova.h"
#include "data/sprites/super_missile_geron.h"
#include "data/sprites/toxic_gas.h"
#include "data/sprites/waver.h"
#include "data/sprites/yakuza.h"
#include "data/sprites/yameba.h"
#include "data/sprites/yard.h"
#include "data/sprites/zazabi.h"
#include "data/sprites/zebesian_aqua.h"
#include "data/sprites/zebesian_ground.h"
#include "data/sprites/zebesian_wall.h"
#include "data/sprites/zeela.h"
#include "data/sprites/zombie_researcher.h"
#include "data/sprites/zoro.h"
#include "data/sprites/zoro_cocoon.h"
#include "data/sprites/zozoro.h"
#include "sprites_AI/animals.h"
#include "sprites_AI/arachnus.h"
#include "sprites_AI/area_banner.h"
#include "sprites_AI/atmospheric_stabilizer.h"
#include "sprites_AI/beam_core_x.h"
#include "sprites_AI/blue_x.h"
#include "sprites_AI/box.h"
#include "sprites_AI/box_2.h"
#include "sprites_AI/bull.h"
#include "sprites_AI/choot.h"
#include "sprites_AI/chozo_statue.h"
#include "sprites_AI/continual_x_spanwer.h"
#include "sprites_AI/core_x.h"
#include "sprites_AI/core_x_downloading_varia.h"
#include "sprites_AI/data_pad.h"
#include "sprites_AI/dessgeega.h"
#include "sprites_AI/electric_water.h"
#include "sprites_AI/electric_water_damage_box2.h"
#include "sprites_AI/evir.h"
#include "sprites_AI/frozen_ridley.h"
#include "sprites_AI/fune_namihe.h"
#include "sprites_AI/gadora.h"
#include "sprites_AI/gate.h"
#include "sprites_AI/geega.h"
#include "sprites_AI/geemer.h"
#include "sprites_AI/genesis.h"
#include "sprites_AI/geruboss.h"
#include "sprites_AI/geruta.h"
#include "sprites_AI/gold_enemy_door_lock.h"
#include "sprites_AI/gunship.h"
#include "sprites_AI/halzyn.h"
#include "sprites_AI/hornoad.h"
#include "sprites_AI/ice_beam_ability.h"
#include "sprites_AI/kago.h"
#include "sprites_AI/kihunter.h"
#include "sprites_AI/lab_debris.h"
#include "sprites_AI/lava_plume.h"
#include "sprites_AI/mega_x.h"
#include "sprites_AI/memu.h"
#include "sprites_AI/message_banner.h"
#include "sprites_AI/metroid.h"
#include "sprites_AI/mimic.h"
#include "sprites_AI/misc_pad.h"
#include "sprites_AI/missile_geron.h"
#include "sprites_AI/missile_hatch.h"
#include "sprites_AI/moto.h"
#include "sprites_AI/movable_platform.h"
#include "sprites_AI/navigation_pad.h"
#include "sprites_AI/nettori.h"
#include "sprites_AI/nightmare.h"
#include "sprites_AI/omega_metroid.h"
#include "sprites_AI/omega_metroid_husk.h"
#include "sprites_AI/operations_room_pad.h"
#include "sprites_AI/owtch.h"
#include "sprites_AI/pillar.h"
#include "sprites_AI/powamp.h"
#include "sprites_AI/power_bomb_geron.h"
#include "sprites_AI/puyo.h"
#include "sprites_AI/recharge_pad.h"
#include "sprites_AI/reo.h"
#include "sprites_AI/ridley.h"
#include "sprites_AI/ridley_pre_spawn.h"
#include "sprites_AI/ripper.h"
#include "sprites_AI/sa_x.h"
#include "sprites_AI/sa_x_arc.h"
#include "sprites_AI/sa_x_boss.h"
#include "sprites_AI/sa_x_lab.h"
#include "sprites_AI/sa_x_monster.h"
#include "sprites_AI/sa_x_noc.h"
#include "sprites_AI/sa_x_omega.h"
#include "sprites_AI/sa_x_tro_1.h"
#include "sprites_AI/sa_x_tro_2.h"
#include "sprites_AI/save_pad.h"
#include "sprites_AI/scientist.h"
#include "sprites_AI/sciser.h"
#include "sprites_AI/security_pad.h"
#include "sprites_AI/shake_trigger.h"
#include "sprites_AI/sidehopper.h"
#include "sprites_AI/skree.h"
#include "sprites_AI/skultera.h"
#include "sprites_AI/sova.h"
#include "sprites_AI/super_missile_geron.h"
#include "sprites_AI/toxic_gas.h"
#include "sprites_AI/waver.h"
#include "sprites_AI/x_parasite.h"
#include "sprites_AI/yakuza.h"
#include "sprites_AI/yameba.h"
#include "sprites_AI/yard.h"
#include "sprites_AI/zazabi.h"
#include "sprites_AI/zebesian_aqua.h"
#include "sprites_AI/zebesian_ground.h"
#include "sprites_AI/zebesian_wall.h"
#include "sprites_AI/zeela.h"
#include "sprites_AI/zombie_researcher.h"
#include "sprites_AI/zoro.h"
#include "sprites_AI/zoro_cocoon.h"
#include "sprites_AI/zozoro.h"
extern const u8 sBlob_2e5cae_2e6160[];
extern const u8 sBlob_2e6382_2e6ba4[];
extern const u8 sBlob_39ad58_39e638[];
extern const u8 sBlob_39ec90_39f4b0[];

const Func_T sPrimarySpritesAiPointers[PSPRITE_END] = {
    [PSPRITE_TARGET_CIRCLES] = TargetCircles,
	[PSPRITE_TARGET_DIAGONAL] = TargetDiagonal,
	[PSPRITE_TARGET_SIDEWAYS] = TargetSideways,
	[PSPRITE_UNUSED_3] = UnusedSprites,
	[PSPRITE_UNUSED_4] = UnusedSprites,
	[PSPRITE_UNUSED_5] = UnusedSprites,
	[PSPRITE_UNUSED_6] = UnusedSprites,
	[PSPRITE_UNUSED_7] = UnusedSprites,
	[PSPRITE_UNUSED_8] = UnusedSprites,
	[PSPRITE_UNUSED_9] = UnusedSprites,
	[PSPRITE_UNUSED_10] = UnusedSprites,
	[PSPRITE_UNUSED_11] = UnusedSprites,
	[PSPRITE_UNUSED_12] = UnusedSprites,
	[PSPRITE_UNUSED_13] = UnusedSprites,
	[PSPRITE_CORE_X_TARGET] = TargetCoreX,
	[PSPRITE_UNUSED_15] = UnusedSprites,
	[PSPRITE_UNUSED_16] = UnusedSprites,
	[PSPRITE_SA_X_ELEVATOR] = SaXElevator,
	[PSPRITE_HORNOAD] = Hornoad,
	[PSPRITE_HALZYN] = Halzyn,
	[PSPRITE_ZEBESIAN_WALL] = ZebesianWall,
	[PSPRITE_HORNOAD_SPAWNER] = HornoadSpawner,
	[PSPRITE_GATE] = Gate,
	[PSPRITE_MOVABLE_PLATFORM_1] = MovablePlatform,
	[PSPRITE_MOTO] = Moto,
	[PSPRITE_NAVIGATION_PAD] = NavPad,
	[PSPRITE_GUNSHIP] = Gunship,
	[PSPRITE_YAMEBA] = Yameba,
	[PSPRITE_SECURITY_PAD] = SecurityPad,
	[PSPRITE_AREA_BANNER] = AreaBanner,
	[PSPRITE_DATA_PAD] = DataPad,
	[PSPRITE_SAVE_PAD] = SavePad,
	[PSPRITE_PRE_BOX_CEILING_DEBRIS] = PreBoxCeilingDebris,
	[PSPRITE_MESSAGE_BANNER] = MessageBanner,
	[PSPRITE_KAGO] = Kago,
	[PSPRITE_ELECTRIC_WATER_DAMAGE] = ElectricWaterDamage,
	[PSPRITE_ELECTRIC_WATER] = ElectricWater,
	[PSPRITE_WIRE] = ElectricWire,
	[PSPRITE_SAMUS_EATER_BUD] = SamusEaterBud,
	[PSPRITE_SAMUS_EATER] = SamusEater,
	[PSPRITE_ENERGY_RECHARGE_PAD] = RechargePad,
	[PSPRITE_AMMO_RECHARGE_PAD] = RechargePad,
	[PSPRITE_ENERGY_AMMO_RECHARGE_PAD] = RechargePad,
	[PSPRITE_ATMOSPHERIC_STABILIZER_PARASITE] = AtmosphericStabilizerParasite,
	[PSPRITE_ATMOSPHERIC_STABILIZER_1] = AtmosphericStabilizer,
	[PSPRITE_ATMOSPHERIC_STABILIZER_2] = AtmosphericStabilizer,
	[PSPRITE_ATMOSPHERIC_STABILIZER_3] = AtmosphericStabilizer,
	[PSPRITE_ATMOSPHERIC_STABILIZER_4] = AtmosphericStabilizer,
	[PSPRITE_ATMOSPHERIC_STABILIZER_5] = AtmosphericStabilizer,
	[PSPRITE_ZEELA] = Zeela,
	[PSPRITE_X_PARASITE_CORE_X_OR_PARASITE] = XParasiteCoreXOrStabilizer,
	[PSPRITE_SKREE] = Skree,
	[PSPRITE_X_PARASITE_IN_ROOM] = XParasiteInRoom,
	[PSPRITE_TOXIC_GAS] = ToxicGas,
	[PSPRITE_X_PARASITE_IN_ROOM_PROXIMITY] = XParasiteInRoom,
	[PSPRITE_ZOMBIE] = Zombie,
	[PSPRITE_X_PARASITE] = XParasite,
	[PSPRITE_GEEMER] = Geemer,
	[PSPRITE_ARACHNUS] = Arachnus,
	[PSPRITE_WAVER] = Waver,
	[PSPRITE_SCISER] = Sciser,
	[PSPRITE_SIDEHOPPER] = Sidehopper,
	[PSPRITE_DESSGEEGA] = Dessgeega,
	[PSPRITE_MORPH_BALL_ABILITY] = CoreXAbility,
	[PSPRITE_X_PARASITE_CORE_X_FORMATION] = XParasiteBossFormation,
	[PSPRITE_GERON_MISSILE_1] = MissileGeron,
	[PSPRITE_GERON_MISSILE_2] = MissileGeron,
	[PSPRITE_GERON_MISSILE_3] = MissileGeron,
	[PSPRITE_HIGH_JUMP_ABILITY] = CoreXAbility,
	[PSPRITE_SPEEDBOOSTER_ABILITY] = CoreXAbility,
	[PSPRITE_VARIA_SUIT_ABILITY] = VariaSuitAbility,
	[PSPRITE_SPACE_JUMP_ABILITY] = CoreXAbility,
	[PSPRITE_GRAVITY_SUIT_ABILITY] = CoreXAbility,
	[PSPRITE_SCREW_ATTACK_ABILITY] = CoreXAbility,
	[PSPRITE_MOVABLE_PLATFORM_2] = MovablePlatform,
	[PSPRITE_ZAZABI] = Zazabi,
	[PSPRITE_OMEGA_METROID_HUSK] = OmegaMetroidHusk,
	[PSPRITE_ICE_BEAM_ABILITY] = IceBeamAbility,
	[PSPRITE_MOVABLE_PLATFORM_3] = MovablePlatform,
	[PSPRITE_MOVABLE_PLATFORM_4] = MovablePlatform,
	[PSPRITE_MOVABLE_PLATFORM_5] = MovablePlatform,
	[PSPRITE_YAKUZA] = Yakuza,
	[PSPRITE_CHOZO_STATUE] = ChozoStatue,
	[PSPRITE_SCIENTIST] = Scientist,
	[PSPRITE_NETTORI] = Nettori,
	[PSPRITE_BOX_2] = Box2,
	[PSPRITE_CHARGE_BEAM_CORE_X] = BeamCoreX,
	[PSPRITE_WIDE_BEAM_CORE_X] = BeamCoreX,
	[PSPRITE_PLASMA_BEAM_CORE_X] = BeamCoreX,
	[PSPRITE_WAVE_BEAM_CORE_X] = BeamCoreX,
	[PSPRITE_ZORO] = Zoro,
	[PSPRITE_KIHUNTER_FLYING] = KihunterFlying,
	[PSPRITE_KIHUNTER_GROUND] = KihunterGround,
	[PSPRITE_KIHUNTER_HIVE] = KihunterHive,
	[PSPRITE_REO] = Reo,
	[PSPRITE_LAVA_PLUME] = LavaPlume,
	[PSPRITE_NAHIME] = Namihe,
	[PSPRITE_FUNE] = Fune,
	[PSPRITE_BOX] = Box,
	[PSPRITE_BLUE_ZORO] = Zoro,
	[PSPRITE_GERUTA] = Geruta,
	[PSPRITE_PUMP_CONTROL_PAD] = MiscPad,
	[PSPRITE_BOILER_CONTROL_PAD] = MiscPad,
	[PSPRITE_AUXILARY_POWER_PAD] = MiscPad,
	[PSPRITE_HABITAION_PAD] = MiscPad,
	[PSPRITE_OPERATIONS_ROOM_PAD] = OperationsRoomPad,
	[PSPRITE_SKULTERA_LARGE] = Skultera,
	[PSPRITE_SKULTERA_SMALL_1] = Skultera,
	[PSPRITE_SOVA] = Sova,
	[PSPRITE_YARD] = Yard,
	[PSPRITE_EVIR] = Evir,
	[PSPRITE_BULL] = Bull,
	[PSPRITE_MEMU] = Memu,
	[PSPRITE_GERUBOSS] = Geruboss,
	[PSPRITE_CHOOT] = Choot,
	[PSPRITE_ZEBESIAN_GROUND] = ZebesianGround,
	[PSPRITE_BLUE_X] = BlueX,
	[PSPRITE_MISSILE_HATCH] = MissileHatch,
	[PSPRITE_QUARANTINE_BAY_HORNOAD] = Hornoad,
	[PSPRITE_BOX_DEBRIS] = BoxDebris,
	[PSPRITE_GERON_SUPER_MISSILE_1] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_2] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_3] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_4] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_5] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_6] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_7] = SuperMissileGeron,
	[PSPRITE_GERON_SUPER_MISSILE_8] = SuperMissileGeron,
	[PSPRITE_GERON_POWER_BOMB_1] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_2] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_3] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_4] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_5] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_6] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_7] = PowerBombGeron,
	[PSPRITE_GERON_POWER_BOMB_8] = PowerBombGeron,
	[PSPRITE_RIPPER] = Ripper,
	[PSPRITE_ZORO_COCOON] = ZoroCocoon,
	[PSPRITE_ZORO_HUSK] = ZoroHusk,
	[PSPRITE_GOLD_SCISER] = Sciser,
	[PSPRITE_SA_X_TRO_1] = SaXTro1,
	[PSPRITE_SA_X_NOC] = SaXNoc,
	[PSPRITE_PRE_DESTROYED_DATA_PAD] = (Func_T)0x804378d,
	[PSPRITE_GADORA_ARACHNUS] = Gadora,
	[PSPRITE_GADORA_CHARGE_BEAM] = Gadora,
	[PSPRITE_GADORA_ZAZABI] = Gadora,
	[PSPRITE_GADORA_SERRIS] = Gadora,
	[PSPRITE_GADORA_VARIA_CORE] = Gadora,
	[PSPRITE_GADORA_WIDE_BEAM] = Gadora,
	[PSPRITE_GADORA_NIGHTMARE] = Gadora,
	[PSPRITE_GADORA_RIDLEY] = Gadora,
	[PSPRITE_GADORA_NETTORI] = Gadora,
	[PSPRITE_GADORA_YAKUZA] = Gadora,
	[PSPRITE_GADORA_1] = Gadora,
	[PSPRITE_GADORA_2] = Gadora,
	[PSPRITE_GADORA_3] = Gadora,
	[PSPRITE_GADORA_4] = Gadora,
	[PSPRITE_GADORA_5] = Gadora,
	[PSPRITE_GADORA_6] = Gadora,
	[PSPRITE_SHAKE_TRIGGER] = ShakeTrigger,
	[PSPRITE_SA_X_ARC] = SaXArc,
	[PSPRITE_ELEVATOR_PAD] = ElevatorPad,
	[PSPRITE_GOLD_ZEBESIAN] = ZebesianGround,
	[PSPRITE_RED_ZEELA] = Zeela,
	[PSPRITE_OWTCH] = Owtch,
	[PSPRITE_GEEGA] = Geega,
	[PSPRITE_SERRIS] = Serris,
	[PSPRITE_PILLAR] = Pillar,
	[PSPRITE_GENESIS] = Genesis,
	[PSPRITE_PUYO] = Puyo,
	[PSPRITE_BUBBLES_1] = Bubbles1,
	[PSPRITE_BUBBLES_2] = Bubbles2,
	[PSPRITE_WATER_DROP] = WaterDrop,
	[PSPRITE_MIMIC_ENERGY_TANK] = MimicEnergyTank,
	[PSPRITE_MIMIC_MISSILE_TANK] = MimicMissileTank,
	[PSPRITE_CORE_X_ABILITY_BEFORE_VARIA_CORE] = CoreXAbilityBeforeVariaCore,
	[PSPRITE_BIG_FLASHING_NUMBER] = BigFlashingNumber,
	[PSPRITE_FLASHING_NUMBER] = FlashingNumber,
	[PSPRITE_DESTROYED_DATA_PAD] = (Func_T)0x804378d,
	[PSPRITE_ZEBESIAN_AQUA] = ZebesianAqua,
	[PSPRITE_ZEBESIAN_PRE_AQUA] = ZebesianGround,
	[PSPRITE_SKULTERA_SMALL_2] = Skultera,
	[PSPRITE_ETECOON] = Etecoon,
	[PSPRITE_TIRE_SWING] = TireSwing,
	[PSPRITE_DACHORA] = Dachora,
	[PSPRITE_X_PARASITE_AQUA_ZEBESIAN] = XParasiteAquaZebesian,
	[PSPRITE_METROID] = Metroid,
	[PSPRITE_LAB_DEBRIS] = LabDebris,
	[PSPRITE_SA_X_LAB] = SaXLab,
	[PSPRITE_POWAMP] = Powamp,
	[PSPRITE_ZOZORO] = Zozoro,
	[PSPRITE_CONTINUAL_X_SPAWNER] = ContinualXSpawner,
	[PSPRITE_SA_X_BOSS] = SaXBoss,
	[PSPRITE_SA_X_MONSTER] = SaXMonster,
	[PSPRITE_ICE_BEAM_CORE_X] = BeamCoreX,
	[PSPRITE_OMEGA_METROID] = OmegaMetroid,
	[PSPRITE_GUNSHIP_END] = GunshipEnd,
	[PSPRITE_ELECTRIC_WATER_DAMAGE_BOX_2] = ElectricWaterDamageBox2,
	[PSPRITE_FROZEN_RIDLEY] = FrozenRidley,
	[PSPRITE_GOLD_SCISER_DOOR_LOCK] = GoldSciserDoorLock,
	[PSPRITE_GOLD_ZEBESIAN_DOOR_LOCK] = GoldZebesianDoorLock,
	[PSPRITE_SA_X_OMEGA_CUTSCENE] = SaXOmega,
	[PSPRITE_METROID_HUSK] = (Func_T)0x8059055,
	[PSPRITE_RIDLEY] = Ridley,
	[PSPRITE_PRE_SPAWN] = RidleyPreSpawn,
	[PSPRITE_SA_X_TRO_2] = SaXTro2,
	[PSPRITE_NIGHTMARE] = Nightmare
};

const u32* const sSpritesGraphicsPointers[PSPRITE_END - 0x10] = {
    [PSPRITE_UNUSED_16 - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_SA_X_ELEVATOR - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_HORNOAD - 0x10] = (const u32*)sHornoadGfx,
	[PSPRITE_HALZYN - 0x10] = (const u32*)sHalzynGfx,
	[PSPRITE_ZEBESIAN_WALL - 0x10] = (const u32*)sZebesianWallGfx,
	[PSPRITE_HORNOAD_SPAWNER - 0x10] = (const u32*)sHornoadGfx,
	[PSPRITE_GATE - 0x10] = (const u32*)sGateGfx,
	[PSPRITE_MOVABLE_PLATFORM_1 - 0x10] = (const u32*)sMovablePlatformGfx,
	[PSPRITE_MOTO - 0x10] = (const u32*)sMotoGfx,
	[PSPRITE_NAVIGATION_PAD - 0x10] = (const u32*)sNavigationPadGfx,
	[PSPRITE_GUNSHIP - 0x10] = (const u32*)sGunshipGfx,
	[PSPRITE_YAMEBA - 0x10] = (const u32*)sYamebaGfx,
	[PSPRITE_SECURITY_PAD - 0x10] = (const u32*)sSecurityPadGfx,
	[PSPRITE_AREA_BANNER - 0x10] = (const u32*)sAreaBannerGfx,
	[PSPRITE_DATA_PAD - 0x10] = (const u32*)sDataPadGfx,
	[PSPRITE_SAVE_PAD - 0x10] = (const u32*)sSavePadGfx,
	[PSPRITE_PRE_BOX_CEILING_DEBRIS - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_MESSAGE_BANNER - 0x10] = (const u32*)sMessageBannerGfx,
	[PSPRITE_KAGO - 0x10] = (const u32*)sKagoGfx,
	[PSPRITE_ELECTRIC_WATER_DAMAGE - 0x10] = (const u32*)sElectricWaterGfx,
	[PSPRITE_ELECTRIC_WATER - 0x10] = (const u32*)sElectricWaterGfx,
	[PSPRITE_WIRE - 0x10] = (const u32*)sElectricWaterGfx,
	[PSPRITE_SAMUS_EATER_BUD - 0x10] = (const u32*)sNettoriGfx,
	[PSPRITE_SAMUS_EATER - 0x10] = (const u32*)sNettoriGfx,
	[PSPRITE_ENERGY_RECHARGE_PAD - 0x10] = (const u32*)sRechargePadGfx,
	[PSPRITE_AMMO_RECHARGE_PAD - 0x10] = (const u32*)sRechargePadGfx,
	[PSPRITE_ENERGY_AMMO_RECHARGE_PAD - 0x10] = (const u32*)sRechargePadGfx,
	[PSPRITE_ATMOSPHERIC_STABILIZER_PARASITE - 0x10] = (const u32*)sAtmosphericStabilizerGfx,
	[PSPRITE_ATMOSPHERIC_STABILIZER_1 - 0x10] = (const u32*)sAtmosphericStabilizerGfx,
	[PSPRITE_ATMOSPHERIC_STABILIZER_2 - 0x10] = (const u32*)sAtmosphericStabilizerGfx,
	[PSPRITE_ATMOSPHERIC_STABILIZER_3 - 0x10] = (const u32*)sAtmosphericStabilizerGfx,
	[PSPRITE_ATMOSPHERIC_STABILIZER_4 - 0x10] = (const u32*)sAtmosphericStabilizerGfx,
	[PSPRITE_ATMOSPHERIC_STABILIZER_5 - 0x10] = (const u32*)sAtmosphericStabilizerGfx,
	[PSPRITE_ZEELA - 0x10] = (const u32*)sZeelaGfx,
	[PSPRITE_X_PARASITE_CORE_X_OR_PARASITE - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_SKREE - 0x10] = (const u32*)sSkreeGfx,
	[PSPRITE_X_PARASITE_IN_ROOM - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_TOXIC_GAS - 0x10] = (const u32*)sToxicGasGfx,
	[PSPRITE_X_PARASITE_IN_ROOM_PROXIMITY - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_ZOMBIE - 0x10] = (const u32*)sZombieGfx,
	[PSPRITE_X_PARASITE - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_GEEMER - 0x10] = (const u32*)sGeemerGfx,
	[PSPRITE_ARACHNUS - 0x10] = (const u32*)sArachnusGfx,
	[PSPRITE_WAVER - 0x10] = (const u32*)sWaverGfx,
	[PSPRITE_SCISER - 0x10] = (const u32*)sSciserGfx,
	[PSPRITE_SIDEHOPPER - 0x10] = (const u32*)sSidehopperGfx,
	[PSPRITE_DESSGEEGA - 0x10] = (const u32*)sDessgeegaGfx,
	[PSPRITE_MORPH_BALL_ABILITY - 0x10] = (const u32*)sMorphBallCoreXGfx,
	[PSPRITE_X_PARASITE_CORE_X_FORMATION - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_GERON_MISSILE_1 - 0x10] = (const u32*)sMissileGeronGfx,
	[PSPRITE_GERON_MISSILE_2 - 0x10] = (const u32*)sMissileGeronGfx,
	[PSPRITE_GERON_MISSILE_3 - 0x10] = (const u32*)sMissileGeronGfx,
	[PSPRITE_HIGH_JUMP_ABILITY - 0x10] = (const u32*)sHiJumpCoreXGfx,
	[PSPRITE_SPEEDBOOSTER_ABILITY - 0x10] = (const u32*)sSpeedBoosterCoreXGfx,
	[PSPRITE_VARIA_SUIT_ABILITY - 0x10] = (const u32*)sMegaXGfx,
	[PSPRITE_SPACE_JUMP_ABILITY - 0x10] = (const u32*)sSpaceJumpCoreXGfx,
	[PSPRITE_GRAVITY_SUIT_ABILITY - 0x10] = (const u32*)sGravityCoreXGfx,
	[PSPRITE_SCREW_ATTACK_ABILITY - 0x10] = (const u32*)sScrewAttackCoreXGfx,
	[PSPRITE_MOVABLE_PLATFORM_2 - 0x10] = (const u32*)sMovablePlatformGfx,
	[PSPRITE_ZAZABI - 0x10] = (const u32*)sZazabiGfx,
	[PSPRITE_OMEGA_METROID_HUSK - 0x10] = (const u32*)sOmegaMetroidHuskGfx,
	[PSPRITE_ICE_BEAM_ABILITY - 0x10] = (const u32*)sIceBeamAbilityOmegaGfx,
	[PSPRITE_MOVABLE_PLATFORM_3 - 0x10] = (const u32*)sMovablePlatformGfx,
	[PSPRITE_MOVABLE_PLATFORM_4 - 0x10] = (const u32*)sMovablePlatformGfx,
	[PSPRITE_MOVABLE_PLATFORM_5 - 0x10] = (const u32*)sMovablePlatformGfx,
	[PSPRITE_YAKUZA - 0x10] = (const u32*)sYakuzaGfx,
	[PSPRITE_CHOZO_STATUE - 0x10] = (const u32*)sChozoStatueGfx,
	[PSPRITE_SCIENTIST - 0x10] = (const u32*)sScientistGfx,
	[PSPRITE_NETTORI - 0x10] = (const u32*)sNettoriGfx,
	[PSPRITE_BOX_2 - 0x10] = (const u32*)sBox2Gfx,
	[PSPRITE_CHARGE_BEAM_CORE_X - 0x10] = (const u32*)sChargeBeamCoreXGfx,
	[PSPRITE_WIDE_BEAM_CORE_X - 0x10] = (const u32*)sWideBeamCoreXGfx,
	[PSPRITE_PLASMA_BEAM_CORE_X - 0x10] = (const u32*)sPlasmaBeamCoreXGfx,
	[PSPRITE_WAVE_BEAM_CORE_X - 0x10] = (const u32*)sWaveBeamCoreXGfx,
	[PSPRITE_ZORO - 0x10] = (const u32*)sZoroGfx,
	[PSPRITE_KIHUNTER_FLYING - 0x10] = (const u32*)sKihunterGfx,
	[PSPRITE_KIHUNTER_GROUND - 0x10] = (const u32*)sKihunterGfx,
	[PSPRITE_KIHUNTER_HIVE - 0x10] = (const u32*)sKihunterGfx,
	[PSPRITE_REO - 0x10] = (const u32*)sReoGfx,
	[PSPRITE_LAVA_PLUME - 0x10] = (const u32*)sLavaPlumeGfx,
	[PSPRITE_NAHIME - 0x10] = (const u32*)sFuneNamiheGfx,
	[PSPRITE_FUNE - 0x10] = (const u32*)sFuneNamiheGfx,
	[PSPRITE_BOX - 0x10] = (const u32*)sBoxGfx,
	[PSPRITE_BLUE_ZORO - 0x10] = (const u32*)sBlueZoroGfx,
	[PSPRITE_GERUTA - 0x10] = (const u32*)sGerutaGfx,
	[PSPRITE_PUMP_CONTROL_PAD - 0x10] = (const u32*)sControlPadGfx,
	[PSPRITE_BOILER_CONTROL_PAD - 0x10] = (const u32*)sControlPadGfx,
	[PSPRITE_AUXILARY_POWER_PAD - 0x10] = (const u32*)sControlPadGfx,
	[PSPRITE_HABITAION_PAD - 0x10] = (const u32*)sHabitationPadGfx,
	[PSPRITE_OPERATIONS_ROOM_PAD - 0x10] = (const u32*)sOperationsRoomPadGfx,
	[PSPRITE_SKULTERA_LARGE - 0x10] = (const u32*)sSkulteraGfx,
	[PSPRITE_SKULTERA_SMALL_1 - 0x10] = (const u32*)sSkulteraGfx,
	[PSPRITE_SOVA - 0x10] = (const u32*)sSovaGfx,
	[PSPRITE_YARD - 0x10] = (const u32*)sYardGfx,
	[PSPRITE_EVIR - 0x10] = (const u32*)sEvirGfx,
	[PSPRITE_BULL - 0x10] = (const u32*)sBullGfx,
	[PSPRITE_MEMU - 0x10] = (const u32*)sMemuGfx,
	[PSPRITE_GERUBOSS - 0x10] = (const u32*)sGerubossGfx,
	[PSPRITE_CHOOT - 0x10] = (const u32*)sChootGfx,
	[PSPRITE_ZEBESIAN_GROUND - 0x10] = (const u32*)sZebesianGroundGfx,
	[PSPRITE_BLUE_X - 0x10] = (const u32*)sBlueXGfx,
	[PSPRITE_MISSILE_HATCH - 0x10] = (const u32*)sMissileHatchGfx,
	[PSPRITE_QUARANTINE_BAY_HORNOAD - 0x10] = (const u32*)sHornoadGfx,
	[PSPRITE_BOX_DEBRIS - 0x10] = (const u32*)sBoxGfx,
	[PSPRITE_GERON_SUPER_MISSILE_1 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_2 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_3 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_4 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_5 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_6 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_7 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_SUPER_MISSILE_8 - 0x10] = (const u32*)sSuperMissileGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_1 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_2 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_3 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_4 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_5 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_6 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_7 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_GERON_POWER_BOMB_8 - 0x10] = (const u32*)sPowerBombGeronGfx,
	[PSPRITE_RIPPER - 0x10] = (const u32*)sRipperGfx,
	[PSPRITE_ZORO_COCOON - 0x10] = (const u32*)sZoroCocoonGfx,
	[PSPRITE_ZORO_HUSK - 0x10] = (const u32*)sZoroHuskGfx,
	[PSPRITE_GOLD_SCISER - 0x10] = (const u32*)sGoldSciserGfx,
	[PSPRITE_SA_X_TRO_1 - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_SA_X_NOC - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_PRE_DESTROYED_DATA_PAD - 0x10] = (const u32*)sDataPadGfx,
	[PSPRITE_GADORA_ARACHNUS - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_CHARGE_BEAM - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_ZAZABI - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_SERRIS - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_VARIA_CORE - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_WIDE_BEAM - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_NIGHTMARE - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_RIDLEY - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_NETTORI - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_YAKUZA - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_1 - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_2 - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_3 - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_4 - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_5 - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_GADORA_6 - 0x10] = (const u32*)sGadoraGfx,
	[PSPRITE_SHAKE_TRIGGER - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_SA_X_ARC - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_ELEVATOR_PAD - 0x10] = sElevatorPadGfx,
	[PSPRITE_GOLD_ZEBESIAN - 0x10] = (const u32*)sGoldZebesianGfx,
	[PSPRITE_RED_ZEELA - 0x10] = (const u32*)sRedZeelaGfx,
	[PSPRITE_OWTCH - 0x10] = (const u32*)sOwtchGfx,
	[PSPRITE_GEEGA - 0x10] = (const u32*)sGeegaGfx,
	[PSPRITE_SERRIS - 0x10] = sSerrisGfx,
	[PSPRITE_PILLAR - 0x10] = (const u32*)sPillarGfx,
	[PSPRITE_GENESIS - 0x10] = (const u32*)sGenesisGfx,
	[PSPRITE_PUYO - 0x10] = (const u32*)sPuyoGfx,
	[PSPRITE_BUBBLES_1 - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_BUBBLES_2 - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_WATER_DROP - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_MIMIC_ENERGY_TANK - 0x10] = (const u32*)sMimicEnergyTankGfx,
	[PSPRITE_MIMIC_MISSILE_TANK - 0x10] = (const u32*)sMimicMissileTankGfx,
	[PSPRITE_CORE_X_ABILITY_BEFORE_VARIA_CORE - 0x10] = (const u32*)sCoreXDownloadingVariaGfx,
	[PSPRITE_BIG_FLASHING_NUMBER - 0x10] = sBigFlashingNumberGfx,
	[PSPRITE_FLASHING_NUMBER - 0x10] = sFlashingNumberGfx,
	[PSPRITE_DESTROYED_DATA_PAD - 0x10] = (const u32*)sDestroyedDataPadGfx,
	[PSPRITE_ZEBESIAN_AQUA - 0x10] = (const u32*)sZebesianAquaGfx,
	[PSPRITE_ZEBESIAN_PRE_AQUA - 0x10] = (const u32*)sZebesianGroundGfx,
	[PSPRITE_SKULTERA_SMALL_2 - 0x10] = (const u32*)sSkulteraGfx,
	[PSPRITE_ETECOON - 0x10] = (const u32*)sAnimalsGfx,
	[PSPRITE_TIRE_SWING - 0x10] = (const u32*)sAnimalsGfx,
	[PSPRITE_DACHORA - 0x10] = (const u32*)sAnimalsGfx,
	[PSPRITE_X_PARASITE_AQUA_ZEBESIAN - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_METROID - 0x10] = (const u32*)sMetroidGfx,
	[PSPRITE_LAB_DEBRIS - 0x10] = (const u32*)sLabDebrisGfx,
	[PSPRITE_SA_X_LAB - 0x10] = (const u32*)sSaXLabExplosionsGfx,
	[PSPRITE_POWAMP - 0x10] = (const u32*)sPowampGfx,
	[PSPRITE_ZOZORO - 0x10] = (const u32*)sZozoroGfx,
	[PSPRITE_CONTINUAL_X_SPAWNER - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_SA_X_BOSS - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_SA_X_MONSTER - 0x10] = (const u32*)sSaXMonsterGfx,
	[PSPRITE_ICE_BEAM_CORE_X - 0x10] = (const u32*)sIceBeamCoreXGfx,
	[PSPRITE_OMEGA_METROID - 0x10] = (const u32*)sOmegaMetroidGfx,
	[PSPRITE_GUNSHIP_END - 0x10] = (const u32*)(&sBlob_39ad58_39e638),
	[PSPRITE_ELECTRIC_WATER_DAMAGE_BOX_2 - 0x10] = (const u32*)(&sBlob_39ec90_39f4b0),
	[PSPRITE_FROZEN_RIDLEY - 0x10] = (const u32*)sFrozenRidleyGfx,
	[PSPRITE_GOLD_SCISER_DOOR_LOCK - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_GOLD_ZEBESIAN_DOOR_LOCK - 0x10] = (const u32*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x2),
	[PSPRITE_SA_X_OMEGA_CUTSCENE - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_METROID_HUSK - 0x10] = (const u32*)sMetroidHuskGfx,
	[PSPRITE_RIDLEY - 0x10] = (const u32*)sRidleyGfx,
	[PSPRITE_PRE_SPAWN - 0x10] = (const u32*)sRidleyPreSpawnGfx,
	[PSPRITE_SA_X_TRO_2 - 0x10] = (const u32*)sSaXWeaponsGfx,
	[PSPRITE_NIGHTMARE - 0x10] = (const u32*)sNightmareGfx
};

const u16* const sSpritesPalettePointers[PSPRITE_END - 0x10] = {
    [PSPRITE_UNUSED_16 - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_SA_X_ELEVATOR - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_HORNOAD - 0x10] = (const u16*)sHornoadPal,
	[PSPRITE_HALZYN - 0x10] = (const u16*)sHalzynPal,
	[PSPRITE_ZEBESIAN_WALL - 0x10] = (const u16*)sZebesianWallPal,
	[PSPRITE_HORNOAD_SPAWNER - 0x10] = (const u16*)sHornoadPal,
	[PSPRITE_GATE - 0x10] = (const u16*)sGatePal,
	[PSPRITE_MOVABLE_PLATFORM_1 - 0x10] = (const u16*)sMovablePlatformPal,
	[PSPRITE_MOTO - 0x10] = (const u16*)sMotoPal,
	[PSPRITE_NAVIGATION_PAD - 0x10] = (const u16*)sNavigationPadPal,
	[PSPRITE_GUNSHIP - 0x10] = (const u16*)sGunshipPal,
	[PSPRITE_YAMEBA - 0x10] = (const u16*)sYamebaPal,
	[PSPRITE_SECURITY_PAD - 0x10] = (const u16*)sSecurityPadPal,
	[PSPRITE_AREA_BANNER - 0x10] = (const u16*)sAreaBannerPal,
	[PSPRITE_DATA_PAD - 0x10] = (const u16*)sDataPadPal,
	[PSPRITE_SAVE_PAD - 0x10] = (const u16*)sSavePadPal,
	[PSPRITE_PRE_BOX_CEILING_DEBRIS - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_MESSAGE_BANNER - 0x10] = (const u16*)sMessageBannerPal,
	[PSPRITE_KAGO - 0x10] = (const u16*)sKagoPal,
	[PSPRITE_ELECTRIC_WATER_DAMAGE - 0x10] = (const u16*)sElectricWaterPal,
	[PSPRITE_ELECTRIC_WATER - 0x10] = (const u16*)sElectricWaterPal,
	[PSPRITE_WIRE - 0x10] = (const u16*)sElectricWaterPal,
	[PSPRITE_SAMUS_EATER_BUD - 0x10] = (const u16*)sNettoriPal,
	[PSPRITE_SAMUS_EATER - 0x10] = (const u16*)sNettoriPal,
	[PSPRITE_ENERGY_RECHARGE_PAD - 0x10] = (const u16*)sRechargePadPal,
	[PSPRITE_AMMO_RECHARGE_PAD - 0x10] = (const u16*)sRechargePadPal,
	[PSPRITE_ENERGY_AMMO_RECHARGE_PAD - 0x10] = (const u16*)sRechargePadPal,
	[PSPRITE_ATMOSPHERIC_STABILIZER_PARASITE - 0x10] = (const u16*)sAtmosphericStabilizerPal,
	[PSPRITE_ATMOSPHERIC_STABILIZER_1 - 0x10] = (const u16*)sAtmosphericStabilizerPal,
	[PSPRITE_ATMOSPHERIC_STABILIZER_2 - 0x10] = (const u16*)sAtmosphericStabilizerPal,
	[PSPRITE_ATMOSPHERIC_STABILIZER_3 - 0x10] = (const u16*)sAtmosphericStabilizerPal,
	[PSPRITE_ATMOSPHERIC_STABILIZER_4 - 0x10] = (const u16*)sAtmosphericStabilizerPal,
	[PSPRITE_ATMOSPHERIC_STABILIZER_5 - 0x10] = (const u16*)sAtmosphericStabilizerPal,
	[PSPRITE_ZEELA - 0x10] = (const u16*)sZeelaPal,
	[PSPRITE_X_PARASITE_CORE_X_OR_PARASITE - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_SKREE - 0x10] = (const u16*)sSkreePal,
	[PSPRITE_X_PARASITE_IN_ROOM - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_TOXIC_GAS - 0x10] = (const u16*)sToxicGasPal,
	[PSPRITE_X_PARASITE_IN_ROOM_PROXIMITY - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_ZOMBIE - 0x10] = (const u16*)sZombiePal,
	[PSPRITE_X_PARASITE - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_GEEMER - 0x10] = (const u16*)sGeemerPal,
	[PSPRITE_ARACHNUS - 0x10] = (const u16*)sArachnusPal,
	[PSPRITE_WAVER - 0x10] = (const u16*)sWaverPal,
	[PSPRITE_SCISER - 0x10] = (const u16*)sSciserPal,
	[PSPRITE_SIDEHOPPER - 0x10] = (const u16*)sSidehopperPal,
	[PSPRITE_DESSGEEGA - 0x10] = (const u16*)sDessgeegaPal,
	[PSPRITE_MORPH_BALL_ABILITY - 0x10] = (const u16*)sMorphBallCoreXPal,
	[PSPRITE_X_PARASITE_CORE_X_FORMATION - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_GERON_MISSILE_1 - 0x10] = (const u16*)sMissileGeronPal,
	[PSPRITE_GERON_MISSILE_2 - 0x10] = (const u16*)sMissileGeronPal,
	[PSPRITE_GERON_MISSILE_3 - 0x10] = (const u16*)sMissileGeronPal,
	[PSPRITE_HIGH_JUMP_ABILITY - 0x10] = (const u16*)sHiJumpCoreXPal,
	[PSPRITE_SPEEDBOOSTER_ABILITY - 0x10] = (const u16*)sSpeedBoosterCoreXPal,
	[PSPRITE_VARIA_SUIT_ABILITY - 0x10] = (const u16*)sMegaXPal,
	[PSPRITE_SPACE_JUMP_ABILITY - 0x10] = (const u16*)sSpaceJumpCoreXPal,
	[PSPRITE_GRAVITY_SUIT_ABILITY - 0x10] = (const u16*)sGravityCoreXPal,
	[PSPRITE_SCREW_ATTACK_ABILITY - 0x10] = (const u16*)sScrewAttackCoreXPal,
	[PSPRITE_MOVABLE_PLATFORM_2 - 0x10] = (const u16*)sMovablePlatformPal,
	[PSPRITE_ZAZABI - 0x10] = (const u16*)sZazabiPal,
	[PSPRITE_OMEGA_METROID_HUSK - 0x10] = (const u16*)sOmegaMetroidHuskPal,
	[PSPRITE_ICE_BEAM_ABILITY - 0x10] = (const u16*)sIceBeamAbilityOmegaPal,
	[PSPRITE_MOVABLE_PLATFORM_3 - 0x10] = (const u16*)sMovablePlatformPal,
	[PSPRITE_MOVABLE_PLATFORM_4 - 0x10] = (const u16*)sMovablePlatformPal,
	[PSPRITE_MOVABLE_PLATFORM_5 - 0x10] = (const u16*)sMovablePlatformPal,
	[PSPRITE_YAKUZA - 0x10] = (const u16*)sYakuzaPal,
	[PSPRITE_CHOZO_STATUE - 0x10] = (const u16*)sChozoStatuePal,
	[PSPRITE_SCIENTIST - 0x10] = (const u16*)sScientistPal,
	[PSPRITE_NETTORI - 0x10] = (const u16*)sNettoriPal,
	[PSPRITE_BOX_2 - 0x10] = (const u16*)sBox2Pal,
	[PSPRITE_CHARGE_BEAM_CORE_X - 0x10] = (const u16*)sChargeBeamCoreXPal,
	[PSPRITE_WIDE_BEAM_CORE_X - 0x10] = (const u16*)sWideBeamCoreXPal,
	[PSPRITE_PLASMA_BEAM_CORE_X - 0x10] = (const u16*)sPlasmaBeamCoreXPal,
	[PSPRITE_WAVE_BEAM_CORE_X - 0x10] = (const u16*)sWaveBeamCoreXPal,
	[PSPRITE_ZORO - 0x10] = (const u16*)sZoroPal,
	[PSPRITE_KIHUNTER_FLYING - 0x10] = (const u16*)sKihunterPal,
	[PSPRITE_KIHUNTER_GROUND - 0x10] = (const u16*)sKihunterPal,
	[PSPRITE_KIHUNTER_HIVE - 0x10] = (const u16*)sKihunterPal,
	[PSPRITE_REO - 0x10] = (const u16*)sReoPal,
	[PSPRITE_LAVA_PLUME - 0x10] = (const u16*)(&sLavaPlumePal),
	[PSPRITE_NAHIME - 0x10] = (const u16*)sFuneNamihePal,
	[PSPRITE_FUNE - 0x10] = (const u16*)sFuneNamihePal,
	[PSPRITE_BOX - 0x10] = (const u16*)sBoxPal,
	[PSPRITE_BLUE_ZORO - 0x10] = (const u16*)sBlueZoroPal,
	[PSPRITE_GERUTA - 0x10] = (const u16*)sGerutaPal,
	[PSPRITE_PUMP_CONTROL_PAD - 0x10] = (const u16*)sControlPadPal,
	[PSPRITE_BOILER_CONTROL_PAD - 0x10] = (const u16*)sControlPadPal,
	[PSPRITE_AUXILARY_POWER_PAD - 0x10] = (const u16*)sControlPadPal,
	[PSPRITE_HABITAION_PAD - 0x10] = (const u16*)sHabitationPadPal,
	[PSPRITE_OPERATIONS_ROOM_PAD - 0x10] = (const u16*)sOperationsRoomPadPal,
	[PSPRITE_SKULTERA_LARGE - 0x10] = (const u16*)sSkulteraPal,
	[PSPRITE_SKULTERA_SMALL_1 - 0x10] = (const u16*)sSkulteraPal,
	[PSPRITE_SOVA - 0x10] = (const u16*)sSovaPal,
	[PSPRITE_YARD - 0x10] = (const u16*)sYardPal,
	[PSPRITE_EVIR - 0x10] = (const u16*)sEvirPal,
	[PSPRITE_BULL - 0x10] = (const u16*)sBullPal,
	[PSPRITE_MEMU - 0x10] = (const u16*)sMemuPal,
	[PSPRITE_GERUBOSS - 0x10] = (const u16*)sGerubossPal,
	[PSPRITE_CHOOT - 0x10] = (const u16*)sChootPal,
	[PSPRITE_ZEBESIAN_GROUND - 0x10] = (const u16*)sZebesianGroundPal,
	[PSPRITE_BLUE_X - 0x10] = (const u16*)sBlueXPal,
	[PSPRITE_MISSILE_HATCH - 0x10] = (const u16*)sMissileHatchPal,
	[PSPRITE_QUARANTINE_BAY_HORNOAD - 0x10] = (const u16*)sHornoadPal,
	[PSPRITE_BOX_DEBRIS - 0x10] = (const u16*)sBoxPal,
	[PSPRITE_GERON_SUPER_MISSILE_1 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_2 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_3 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_4 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_5 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_6 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_7 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_SUPER_MISSILE_8 - 0x10] = (const u16*)sSuperMissileGeronPal,
	[PSPRITE_GERON_POWER_BOMB_1 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_2 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_3 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_4 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_5 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_6 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_7 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_GERON_POWER_BOMB_8 - 0x10] = (const u16*)sPowerBombGeronPal,
	[PSPRITE_RIPPER - 0x10] = (const u16*)sRipperPal,
	[PSPRITE_ZORO_COCOON - 0x10] = (const u16*)sZoroCocoonPal,
	[PSPRITE_ZORO_HUSK - 0x10] = (const u16*)sZoroHuskPal,
	[PSPRITE_GOLD_SCISER - 0x10] = (const u16*)sGoldSciserPal,
	[PSPRITE_SA_X_TRO_1 - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_SA_X_NOC - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_PRE_DESTROYED_DATA_PAD - 0x10] = (const u16*)sDataPadPal,
	[PSPRITE_GADORA_ARACHNUS - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_CHARGE_BEAM - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_ZAZABI - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_SERRIS - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_VARIA_CORE - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_WIDE_BEAM - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_NIGHTMARE - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_RIDLEY - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_NETTORI - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_YAKUZA - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_1 - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_2 - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_3 - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_4 - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_5 - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_GADORA_6 - 0x10] = (const u16*)sGadoraPal,
	[PSPRITE_SHAKE_TRIGGER - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_SA_X_ARC - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_ELEVATOR_PAD - 0x10] = sElevatorPadPal,
	[PSPRITE_GOLD_ZEBESIAN - 0x10] = (const u16*)sGoldZebesianPal,
	[PSPRITE_RED_ZEELA - 0x10] = (const u16*)sRedZeelaPal,
	[PSPRITE_OWTCH - 0x10] = (const u16*)sOwtchPal,
	[PSPRITE_GEEGA - 0x10] = (const u16*)sGeegaPal,
	[PSPRITE_SERRIS - 0x10] = sSerrisPal,
	[PSPRITE_PILLAR - 0x10] = (const u16*)sPillarPal,
	[PSPRITE_GENESIS - 0x10] = (const u16*)sGenesisPal,
	[PSPRITE_PUYO - 0x10] = (const u16*)sPuyoPal,
	[PSPRITE_BUBBLES_1 - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_BUBBLES_2 - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_WATER_DROP - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_MIMIC_ENERGY_TANK - 0x10] = (const u16*)sMimicEnergyTankPal,
	[PSPRITE_MIMIC_MISSILE_TANK - 0x10] = (const u16*)sMimicMissileTankPal,
	[PSPRITE_CORE_X_ABILITY_BEFORE_VARIA_CORE - 0x10] = (const u16*)sCoreXDownloadingVariaPal,
	[PSPRITE_BIG_FLASHING_NUMBER - 0x10] = sBigFlashingNumberPal,
	[PSPRITE_FLASHING_NUMBER - 0x10] = sFlashingNumberPal,
	[PSPRITE_DESTROYED_DATA_PAD - 0x10] = (const u16*)sDestroyedDataPadPal,
	[PSPRITE_ZEBESIAN_AQUA - 0x10] = (const u16*)sZebesianAquaPal,
	[PSPRITE_ZEBESIAN_PRE_AQUA - 0x10] = (const u16*)sZebesianGroundPal,
	[PSPRITE_SKULTERA_SMALL_2 - 0x10] = (const u16*)sSkulteraPal,
	[PSPRITE_ETECOON - 0x10] = (const u16*)sAnimalsPal,
	[PSPRITE_TIRE_SWING - 0x10] = (const u16*)sAnimalsPal,
	[PSPRITE_DACHORA - 0x10] = (const u16*)sAnimalsPal,
	[PSPRITE_X_PARASITE_AQUA_ZEBESIAN - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_METROID - 0x10] = (const u16*)sMetroidPal,
	[PSPRITE_LAB_DEBRIS - 0x10] = (const u16*)sLabDebrisPal,
	[PSPRITE_SA_X_LAB - 0x10] = (const u16*)sSaXLabExplosionsPal,
	[PSPRITE_POWAMP - 0x10] = (const u16*)sPowampPal,
	[PSPRITE_ZOZORO - 0x10] = (const u16*)sZozoroPal,
	[PSPRITE_CONTINUAL_X_SPAWNER - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_SA_X_BOSS - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_SA_X_MONSTER - 0x10] = (const u16*)sSaXMonsterPal,
	[PSPRITE_ICE_BEAM_CORE_X - 0x10] = (const u16*)sIceBeamCoreXPal,
	[PSPRITE_OMEGA_METROID - 0x10] = (const u16*)sOmegaMetroidPal,
	[PSPRITE_GUNSHIP_END - 0x10] = (const u16*)((const u8*)&sBlob_39ad58_39e638 + 0x3800),
	[PSPRITE_ELECTRIC_WATER_DAMAGE_BOX_2 - 0x10] = (const u16*)((const u8*)&sBlob_39ec90_39f4b0 + 0x800),
	[PSPRITE_FROZEN_RIDLEY - 0x10] = (const u16*)sFrozenRidleyPal,
	[PSPRITE_GOLD_SCISER_DOOR_LOCK - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_GOLD_ZEBESIAN_DOOR_LOCK - 0x10] = (const u16*)((const u8*)&sBlob_2e6382_2e6ba4 + 0x802),
	[PSPRITE_SA_X_OMEGA_CUTSCENE - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_METROID_HUSK - 0x10] = (const u16*)sMetroidHuskPal,
	[PSPRITE_RIDLEY - 0x10] = (const u16*)sRidleyPal,
	[PSPRITE_PRE_SPAWN - 0x10] = (const u16*)sRidleyPreSpawnPal,
	[PSPRITE_SA_X_TRO_2 - 0x10] = (const u16*)sSaXPalette_Default,
	[PSPRITE_NIGHTMARE - 0x10] = (const u16*)sNightmarePal
};

const Func_T sSecondarySpritesAiPointers[SSPRITE_END] = {
    [SSPRITE_SA_X_ICE_BEAM] = SaXBeam,
	[SSPRITE_SA_X_SUPER_MISSILE] = SaXMissile,
	[SSPRITE_HORNOAD_SPIT] = HornoadSpit,
	[SSPRITE_HALZYN_WING] = HalzynWing,
	[SSPRITE_SCISER_PROJECTILE] = SciserProjectile,
	[SSPRITE_ZEBESIAN_BEAM] = ZebesianBeam,
	[SSPRITE_GUNSHIP_PART] = GunshipPart,
	[SSPRITE_NAVIGATION_CONSOLE] = NavConsole,
	[SSPRITE_NAVIGATION_CONSOLE_SCREEN] = NavConsoleScreen,
	[SSPRITE_NAVIGATION_SCREEN] = NavScreen,
	[SSPRITE_SAVE_PLATFORM] = SavePlatform,
	[SSPRITE_MOTO_FRONT] = MotoFront,
	[SSPRITE_GEEMER_FLASHING_LIGHT] = GeemerFlashingLight,
	[SSPRITE_GUNSHIP_BEAM] = GunshipBeam,
	[SSPRITE_E] = KagoInsect,
	[SSPRITE_GATE_SWITCH] = GateSwitch,
	[SSPRITE_KIHUNTER_WINGS] = KihunterWings,
	[SSPRITE_KIHUNTER_SPIT] = KihunterSpit,
	[SSPRITE_12] = SecurityPadScreen,
	[SSPRITE_ATMOSPHERIC_STABILIZER_COVER_DOWN] = AtmosphericStabilizerCover,
	[SSPRITE_14] = BoxMissile,
	[SSPRITE_ARACHNUS_SHELL] = ArachnusShell,
	[SSPRITE_ARACHNUS_BEAM] = ArachnusSlash,
	[SSPRITE_ARACHNUS_HEAD] = ArachnusHead,
	[SSPRITE_ARACHNUS_LEFT_ARM] = ArachnusArm1,
	[SSPRITE_ARACHNUS_RIGHT_ARM] = ArachnusArm2,
	[SSPRITE_ARACHNUS_FIRE_BALL] = ArachnusFire,
	[SSPRITE_CORE_X_SHELL_MORPH_BALL] = CoreXShell,
	[SSPRITE_ABILITY_AURA] = AbilityAura,
	[SSPRITE_GERON_MISSILE_STEM] = MissileGeronStem,
	[SSPRITE_DATA_PAD_CENTER] = DataPadCenter,
	[SSPRITE_DATA_PAD_SIDES] = DataPadSides,
	[SSPRITE_ARACHNUS_BEAM_TRAIL] = ArachnusSlashTrail,
	[SSPRITE_RECHARGE_PAD_MONITOR] = RechargePadMonitor,
	[SSPRITE_RECHARGE_PAD_SCREEN] = RechargePadScreen,
	[SSPRITE_ATMOSPHERIC_STABILIZER_COVER_RIGHT] = AtmosphericStabilizerCover,
	[SSPRITE_ATMOSPHERIC_STABILIZER_COVER_LEFT] = AtmosphericStabilizerCover,
	[SSPRITE_SECURITY_PAD_MONITOR] = SecurityPadMonitor,
	[SSPRITE_SAVE_YES_NO_CURSOR] = SaveYesNoCursor,
	[SSPRITE_FAKE_CHOZO_BALL] = FakeChozoBall,
	[SSPRITE_CHARGE_BEAM_CORE_X_SHELL] = BeamCoreXShell,
	[SSPRITE_CHARGE_BEAM_CORE_X_EYE] = BeamCoreXEye,
	[SSPRITE_TOXIC_GAS_EXPLOSION] = ToxicGasExplosion,
	[SSPRITE_KIHUNTER_BUG] = KihunterBug,
	[SSPRITE_REO_WING] = ReoWings,
	[SSPRITE_LAVA_PLUME_WARNING] = LavaPlumeWarning,
	[SSPRITE_NAMIHE_SPIT] = NamiheSpit,
	[SSPRITE_FUNE_SPIT] = FuneSpit,
	[SSPRITE_SAVE_PAD_HOLOGRAM] = SavePadHologram,
	[SSPRITE_BOX_PART] = BoxPart,
	[SSPRITE_DESSGEEGA_SPIKE] = DessgeegaSpike,
	[SSPRITE_33] = MiscPadConsole,
	[SSPRITE_OPERATIONS_ROOM_PAD_CONSOLE] = OperationsRoomPadConsole,
	[SSPRITE_OPERATIONS_ROOM_PAD_CONSOLE_SCREEN] = OperationsRoomPadConsoleScreen,
	[SSPRITE_OPERATIONS_ROOM_PAD_SCREEN] = OperationsRoomPadScreen,
	[SSPRITE_WAVER_DEBRIS] = WaverExplosion,
	[SSPRITE_ZEELA_PROJECTILE] = ZeelaProjectile,
	[SSPRITE_SOVA_FIRE] = SovaFire,
	[SSPRITE_YARD_PROJECTILE] = YardProjectile,
	[SSPRITE_EVIR_COLLISION] = EvirCollision,
	[SSPRITE_EVIR_PROJECTILE] = EvirProjectile,
	[SSPRITE_BULL_SMOKE] = BullSmoke,
	[SSPRITE_CHOOT_SPIT] = ChootSpit,
	[SSPRITE_ZEBESIAN_GROUND_BEAM] = ZebesianGroundBeam,
	[SSPRITE_BLUE_X_ABSORPTION] = BlueXAbsorbtion,
	[SSPRITE_41] = MissileHatchDebris,
	[SSPRITE_GERON_SUPER_MISSILE_STEM] = SuperMissileGeronStem,
	[SSPRITE_GERON_POWER_BOMB_STEM] = PowerBombGeronStem,
	[SSPRITE_SA_X_POWER_BOMB] = SaXPowerBomb,
	[SSPRITE_GADORA_ROOTS] = GadoraRoots,
	[SSPRITE_GADORA_BEAM] = GadoraBeam,
	[SSPRITE_GADORA_EYE] = GadoraEye,
	[SSPRITE_48] = Gadora_UnusedSprite,
	[SSPRITE_NIGHTMARE_FALLING_ARM] = NightmareFallingArm,
	[SSPRITE_MEGA_X_SHIELD] = MegaXShield,
	[SSPRITE_BOX_FALLING_DEBRIS] = BoxFallingDebris,
	[SSPRITE_NETTORI_PART] = NettoriPart,
	[SSPRITE_4D] = BeamCoreXGlowing,
	[SSPRITE_BEAM_CORE_X_CHARGE_BEAM] = CoreXChargeBeam,
	[SSPRITE_BEAM_CORE_X_WIDE_BEAM] = CoreXWideBeam,
	[SSPRITE_BEAM_CORE_X_PLASMA_BEAM] = CoreXPlasmaBeam,
	[SSPRITE_BEAM_CORE_X_WAVE_BEAM] = CoreXWaveIceBeam,
	[SSPRITE_SAMUS_EATER_SPORE] = SamusEaterSpore,
	[SSPRITE_NETTORI_PLASMA_BEAM] = NettoriPlasmaBeam,
	[SSPRITE_WIDE_BEAM_CORE_X_SHELL] = BeamCoreXShell,
	[SSPRITE_WIDE_BEAM_CORE_X_EYE] = BeamCoreXEye,
	[SSPRITE_PLASMA_BEAM_CORE_X_SHELL] = BeamCoreXShell,
	[SSPRITE_PLASMA_BEAM_CORE_X_EYE] = BeamCoreXEye,
	[SSPRITE_WAVE_BEAM_CORE_X_SHELL] = BeamCoreXShell,
	[SSPRITE_WAVE_BEAM_CORE_X_EYE] = BeamCoreXEye,
	[SSPRITE_ZAZABI_PART] = ZazabiPart,
	[SSPRITE_SERRIS_PART] = SerrisPart,
	[SSPRITE_CORE_X_STATIC_BEFORE_VARIA_CORE] = CoreXStaticBeforeVariaCore,
	[SSPRITE_CORE_X_SHELL_BEFORE_VARIA_CORE] = CoreXShellBeforeVariaCore,
	[SSPRITE_CORE_X_SHELL_HIGH_JUMP] = CoreXShell,
	[SSPRITE_CORE_X_SHELL_SPEEDBOOSTER] = CoreXShell,
	[SSPRITE_CORE_X_SHELL_VARIA] = CoreXShellVaria,
	[SSPRITE_CORE_X_SHELL_SPACE_JUMP] = CoreXShell,
	[SSPRITE_CORE_X_SHELL_GRAVITY] = CoreXShell,
	[SSPRITE_CORE_X_SHELL_SCREW_ATTACK] = CoreXShell,
	[SSPRITE_YAKUZA_PART] = YakuzaPart,
	[SSPRITE_GENESIS_SPIT] = GenesisSpit,
	[SSPRITE_ZEBESIAN_AQUA_PROJECTILE] = ZebesianAquaProjectile,
	[SSPRITE_HABITATION_GATE] = HabitationGate,
	[SSPRITE_HABITATION_GATE_LIGHT] = HabitationGateLight,
	[SSPRITE_BABY_DACHORA] = BabyDachora,
	[SSPRITE_SA_X_SHOOTING_AT_LAB_EXPLOSION] = LabExplosion,
	[SSPRITE_SA_X_MONSTER_PART] = SaXMonsterPart,
	[SSPRITE_BOX_2_PART] = Box2Part,
	[SSPRITE_BOX_2_MISSILE] = Box2Missile,
	[SSPRITE_BOX_2_BRAIN_TOP] = Box2BrainTop,
	[SSPRITE_BOX_2_BRAIN_BOTTOM] = Box2BrainBottom,
	[SSPRITE_OMEGA_METROID_PART] = OmegaMetroidPart,
	[SSPRITE_BOX_BOMB] = BoxBomb,
	[SSPRITE_BOX_FIRE] = BoxFire,
	[SSPRITE_FROZEN_RIDLEY_X] = FrozenRidleyX,
	[SSPRITE_BEAM_CORE_X_ICE_BEAM] = CoreXWaveIceBeam,
	[SSPRITE_ICE_BEAM_CORE_X_SHELL] = BeamCoreXShell,
	[SSPRITE_ICE_BEAM_CORE_X_EYE] = BeamCoreXEye,
	[SSPRITE_SERRIS_BLOCK] = SerrisBlock,
	[SSPRITE_MEGA_X] = MegaX,
	[SSPRITE_GUNSHIP_END_BEAM] = GunshipEndBeam,
	[SSPRITE_7A] = GunshipEndBottom,
	[SSPRITE_RIDLEY_PART] = RidleyPart,
	[SSPRITE_RIDLEY_TAIL_PART] = RidleyTailPart,
	[SSPRITE_RIDLEY_FIRE] = RidleyFire,
	[SSPRITE_YAKUZA_PROJECTILE] = YakuzaProjectile,
	[SSPRITE_YAKUZA_FALLING_LEG] = YakuzaFallingLeg,
	[SSPRITE_NIGHTMARE_PART] = NightmarePart,
	[SSPRITE_NIGHTMARE_BEAM] = NightmareBeam
};

const u8* const sSpritesetPointers[130] = {
    [0] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2),
	[1] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xa),
	[2] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xe),
	[3] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2c),
	[4] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x30),
	[5] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x48),
	[6] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4c),
	[7] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x52),
	[8] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x5a),
	[9] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x60),
	[10] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x64),
	[11] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x76),
	[12] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x7e),
	[13] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x88),
	[14] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x90),
	[15] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xa0),
	[16] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xac),
	[17] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xba),
	[18] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xd2),
	[19] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xe2),
	[20] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xee),
	[21] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xf2),
	[22] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0xf6),
	[23] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x102),
	[24] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x10e),
	[25] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x11e),
	[26] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x130),
	[27] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x134),
	[28] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x142),
	[29] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x14c),
	[30] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x15e),
	[31] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x16c),
	[32] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x170),
	[33] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x17c),
	[34] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x180),
	[35] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x18a),
	[36] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1a4),
	[37] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1ac),
	[38] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1b2),
	[39] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1c2),
	[40] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1d0),
	[41] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1de),
	[42] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1e2),
	[43] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1f0),
	[44] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1f8),
	[45] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x1fe),
	[46] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x208),
	[47] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x20e),
	[48] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x218),
	[49] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x224),
	[50] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x22a),
	[51] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x23c),
	[52] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x246),
	[53] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x254),
	[54] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x264),
	[55] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x268),
	[56] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x278),
	[57] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x284),
	[58] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x28c),
	[59] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x290),
	[60] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x29a),
	[61] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2aa),
	[62] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2b4),
	[63] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2c4),
	[64] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2d0),
	[65] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2e2),
	[66] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2f2),
	[67] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x2fe),
	[68] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x30a),
	[69] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x318),
	[70] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x328),
	[71] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x32c),
	[72] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x336),
	[73] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x340),
	[74] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x346),
	[75] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x35c),
	[76] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x36e),
	[77] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x378),
	[78] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x380),
	[79] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x38a),
	[80] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x390),
	[81] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x398),
	[82] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3a6),
	[83] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3ae),
	[84] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3ba),
	[85] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3be),
	[86] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3cc),
	[87] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3d8),
	[88] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3ec),
	[89] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3f4),
	[90] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x3fc),
	[91] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x402),
	[92] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x406),
	[93] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x410),
	[94] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x41a),
	[95] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x428),
	[96] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x434),
	[97] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x442),
	[98] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x450),
	[99] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x454),
	[100] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x460),
	[101] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x464),
	[102] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x46c),
	[103] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x470),
	[104] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x480),
	[105] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x482),
	[106] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x484),
	[107] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x486),
	[108] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x488),
	[109] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x48a),
	[110] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x48c),
	[111] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x48e),
	[112] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x490),
	[113] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x492),
	[114] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x494),
	[115] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x496),
	[116] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x498),
	[117] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x49a),
	[118] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x49c),
	[119] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x49e),
	[120] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4a0),
	[121] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4a2),
	[122] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4a4),
	[123] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4a6),
	[124] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4a8),
	[125] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4aa),
	[126] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4ac),
	[127] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4ae),
	[128] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x4b0),
	[129] = (const u8*)((const u8*)&sBlob_2e5cae_2e6160 + 0x8)
};
