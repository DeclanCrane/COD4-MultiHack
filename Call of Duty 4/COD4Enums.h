#pragma once

enum entityType_t {
	GENERAL = 0,
	PLAYER,
	CORPSE,
	ITEM,
	MISSLE,
	INVISIBLE_ENTITY,
	SCRIPTMOVER,
	SOUND_BLEND,
	UNUSED_JUNK,
	LOOP_FX,
	PRIMARY_LIGHT,
	MG42,
	HELICOPTER,
	PLANE,
	VEHICLE,
	VEHICLE_COLLMAP,
	VEHICLE_CORPSE
};

enum perkFlags_t {
	PERK_JAMRADAR = 0,
	PERK_ACCURACY,
	PERK_FASTRELOAD,
	PERK_RATEOFFIRE,
	PERK_EXTRABREATH,
	PERK_EXTRABP,
	PERK_GRENADEDEATH,
	PERK_PISTOLDEATH,
	PERK_QUIETMOVE,
	PERK_PARABOLIC,
	PERK_LONGERSPRINT,
	PERK_DETECTEXPLOSIVE,
	PERK_EXPLOSIVEDMG, 
	PERK_EXPOSEENEMY,
	PERK_BULLETDMG,
	PERK_EXTRAAMMO,
	PERK_TWOPRIMARIES,
	PERK_ARMORVEST,
	PERK_FRAGGRENADE,
	PERK_SPECIALGRENADE,
	PERK_COUNT,
};

enum weapClass_t {
	WEAPCLASS_RIFLE = 0,
	WEAPCLASS_MG = 1,
	WEAPCLASS_SMG = 2,
	WEAPCLASS_SPREAD = 3,
	WEAPCLASS_PISTOL = 4,
	WEAPCLASS_GRENADE = 5,
	WEAPCLASS_ROCKETLAUNCHER = 6,
	WEAPCLASS_TURRET = 7,
	WEAPCLASS_NON_PLAYER = 8,
	WEAPCLASS_ITEM = 9,
	WEAPCLASS_NUM = 10,
};

enum weapType_t {
	WEAPTYPE_BULLET = 0,
	WEAPTYPE_GRENADE = 1,
	WEAPTYPE_PROJECTILE = 2,
	WEAPTYPE_BINOCULARS = 3,
	WEAPTYPE_NUM = 4,
};

enum PenetrateType {
	PENETRATE_TYPE_NONE = 0,
	PENETRATE_TYPE_SMALL = 1,
	PENETRATE_TYPE_MEDIUM = 2,
	PENETRATE_TYPE_LARGE = 3,
	PENETRATE_TYPE_COUNT = 4,
};

enum sessionState_t {
	SESS_STATE_PLAYING = 0,
	SESS_STATE_DEAD = 1,
	SESS_STATE_SPECTATOR = 2,
	SESS_STATE_INTERMISSION = 3,
};

enum TraceHitType {
	TRACE_HITTYPE_NONE = 0,
	TRACE_HITTYPE_ENTITY = 1,
	TRACE_HITTYPE_DYNENT_MODEL = 2,
	TRACE_HITTYPE_DYNENT_BRUSH = 3,
};

enum clientConnected_t {
	CON_DISCONNECTED = 0,
	CON_CONNECTING = 1,
	CON_CONNECTED = 2,
};

enum team_t {
	TEAM_FREE = 0,
	TEAM_AXIS = 1,
	TEAM_ALLIES = 2,
	TEAM_SPECTATOR = 3,
	TEAM_NUM_TEAMS = 4,
};

enum OffhandSecondaryClass
{
	PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
	PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
	PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
};

enum ViewLockTypes
{
	PLAYERVIEWLOCK_NONE = 0x0,
	PLAYERVIEWLOCK_FULL = 0x1,
	PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
	PLAYERVIEWLOCKCOUNT = 0x3,
};

enum ActionSlotType
{
	ACTIONSLOTTYPE_DONOTHING = 0x0,
	ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
	ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
	ACTIONSLOTTYPE_NIGHTVISION = 0x3,
	ACTIONSLOTTYPECOUNT = 0x4,
};

enum he_type_t
{
	HE_TYPE_FREE = 0x0,
	HE_TYPE_TEXT = 0x1,
	HE_TYPE_VALUE = 0x2,
	HE_TYPE_PLAYERNAME = 0x3,
	HE_TYPE_MAPNAME = 0x4,
	HE_TYPE_GAMETYPE = 0x5,
	HE_TYPE_MATERIAL = 0x6,
	HE_TYPE_TIMER_DOWN = 0x7,
	HE_TYPE_TIMER_UP = 0x8,
	HE_TYPE_TENTHS_TIMER_DOWN = 0x9,
	HE_TYPE_TENTHS_TIMER_UP = 0xA,
	HE_TYPE_CLOCK_DOWN = 0xB,
	HE_TYPE_CLOCK_UP = 0xC,
	HE_TYPE_WAYPOINT = 0xD,
	HE_TYPE_COUNT = 0xE,
};

enum objectiveState_t
{
	OBJST_EMPTY = 0x0,
	OBJST_ACTIVE = 0x1,
	OBJST_INVISIBLE = 0x2,
	OBJST_DONE = 0x3,
	OBJST_CURRENT = 0x4,
	OBJST_FAILED = 0x5,
	OBJST_NUMSTATES = 0x6,
};

/* 750 */
enum ImpactType
{
	IMPACT_TYPE_NONE = 0x0,
	IMPACT_TYPE_BULLET_SMALL = 0x1,
	IMPACT_TYPE_BULLET_LARGE = 0x2,
	IMPACT_TYPE_BULLET_AP = 0x3,
	IMPACT_TYPE_SHOTGUN = 0x4,
	IMPACT_TYPE_GRENADE_BOUNCE = 0x5,
	IMPACT_TYPE_GRENADE_EXPLODE = 0x6,
	IMPACT_TYPE_ROCKET_EXPLODE = 0x7,
	IMPACT_TYPE_PROJECTILE_DUD = 0x8,
	IMPACT_TYPE_COUNT = 0x9,
};

/* 753 */
enum weapInventoryType_t
{
	WEAPINVENTORY_PRIMARY = 0x0,
	WEAPINVENTORY_OFFHAND = 0x1,
	WEAPINVENTORY_ITEM = 0x2,
	WEAPINVENTORY_ALTMODE = 0x3,
	WEAPINVENTORYCOUNT = 0x4,
};

/* 756 */
enum weapFireType_t
{
	WEAPON_FIRETYPE_FULLAUTO = 0x0,
	WEAPON_FIRETYPE_SINGLESHOT = 0x1,
	WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
	WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
	WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
	WEAPON_FIRETYPECOUNT = 0x5,
};

/* 744 */
enum OffhandClass
{
	OFFHAND_CLASS_NONE = 0x0,
	OFFHAND_CLASS_FRAG_GRENADE = 0x1,
	OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
	OFFHAND_CLASS_FLASH_GRENADE = 0x3,
	OFFHAND_CLASS_COUNT = 0x4,
};

/* 762 */
enum weapStance_t
{
	WEAPSTANCE_STAND = 0x0,
	WEAPSTANCE_DUCK = 0x1,
	WEAPSTANCE_PRONE = 0x2,
	WEAPSTANCE_NUM = 0x3,
};

/* 746 */
enum activeReticleType_t
{
	VEH_ACTIVE_RETICLE_NONE = 0x0,
	VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
	VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
	VEH_ACTIVE_RETICLE_COUNT = 0x3,
};

/* 763 */
enum weaponIconRatioType_t
{
	WEAPON_ICON_RATIO_1TO1 = 0x0,
	WEAPON_ICON_RATIO_2TO1 = 0x1,
	WEAPON_ICON_RATIO_4TO1 = 0x2,
	WEAPON_ICON_RATIO_COUNT = 0x3,
};

/* 748 */
enum ammoCounterClipType_t
{
	AMMO_COUNTER_CLIP_NONE = 0x0,
	AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
	AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
	AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
	AMMO_COUNTER_CLIP_ROCKET = 0x4,
	AMMO_COUNTER_CLIP_BELTFED = 0x5,
	AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
	AMMO_COUNTER_CLIP_COUNT = 0x7,
};

/* 761 */
enum weapOverlayReticle_t
{
	WEAPOVERLAYRETICLE_NONE = 0x0,
	WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
	WEAPOVERLAYRETICLE_NUM = 0x2,
};

/* 755 */
enum WeapOverlayInteface_t
{
	WEAPOVERLAYINTERFACE_NONE = 0x0,
	WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
	WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
	WEAPOVERLAYINTERFACECOUNT = 0x3,
};

/* 745 */
enum weapProjExposion_t
{
	WEAPPROJEXP_GRENADE = 0x0,
	WEAPPROJEXP_ROCKET = 0x1,
	WEAPPROJEXP_FLASHBANG = 0x2,
	WEAPPROJEXP_NONE = 0x3,
	WEAPPROJEXP_DUD = 0x4,
	WEAPPROJEXP_SMOKE = 0x5,
	WEAPPROJEXP_HEAVY = 0x6,
	WEAPPROJEXP_NUM = 0x7,
};

/* 758 */
enum WeapStickinessType
{
	WEAPSTICKINESS_NONE = 0x0,
	WEAPSTICKINESS_ALL = 0x1,
	WEAPSTICKINESS_GROUND = 0x2,
	WEAPSTICKINESS_GROUND_WITH_YAW = 0x3,
	WEAPSTICKINESS_COUNT = 0x4,
};

/* 743 */
enum guidedMissileType_t
{
	MISSILE_GUIDANCE_NONE = 0x0,
	MISSILE_GUIDANCE_SIDEWINDER = 0x1,
	MISSILE_GUIDANCE_HELLFIRE = 0x2,
	MISSILE_GUIDANCE_JAVELIN = 0x3,
	MISSILE_GUIDANCE_COUNT = 0x4,
};

enum entityEvents_t
{
	EV_NONE = 0,
	EV_FOLIAGE_SOUND,
	EV_STOP_WEAPON_SOUND,
	EV_SOUND_ALIAS,
	EV_SOUND_ALIAS_AS_MASTER,
	EV_STOPSOUNDS,
	EV_STANCE_FORCE_STAND,
	EV_STANCE_FORCE_CROUCH,
	EV_STANCE_FORCE_PRONE,
	EV_ITEM_PICKUP,
	EV_AMMO_PICKUP,
	EV_NOAMMO,
	EV_EMPTYCLIP,
	EV_EMPTY_OFFHAND,
	EV_RESET_ADS,
	EV_RELOAD,
	EV_RELOAD_FROM_EMPTY,
	EV_RELOAD_START,
	EV_RELOAD_END,
	EV_RELOAD_START_NOTIFY,
	EV_RELOAD_ADDAMMO,
	EV_RAISE_WEAPON,
	EV_FIRST_RAISE_WEAPON,
	EV_PUTAWAY_WEAPON,
	EV_WEAPON_ALT,
	EV_PULLBACK_WEAPON,
	EV_FIRE_WEAPON,
	EV_FIRE_WEAPON_LASTSHOT,
	EV_RECHAMBER_WEAPON,
	EV_EJECT_BRASS,
	EV_MELEE_SWIPE,
	EV_FIRE_MELEE,
	EV_PREP_OFFHAND,
	EV_USE_OFFHAND,
	EV_SWITCH_OFFHAND,
	EV_MELEE_HIT,
	EV_MELEE_MISS,
	EV_MELEE_BLOOD,
	EV_FIRE_WEAPON_MG42,
	EV_FIRE_QUADBARREL_1,
	EV_FIRE_QUADBARREL_2,
	EV_BULLET_HIT,
	EV_BULLET_HIT_CLIENT_SMALL,
	EV_BULLET_HIT_CLIENT_LARGE,
	EV_GRENADE_BOUNCE,
	EV_GRENADE_EXPLODE,
	EV_ROCKET_EXPLODE,
	EV_ROCKET_EXPLODE_NOMARKS,
	EV_FLASHBANG_EXPLODE,
	EV_CUSTOM_EXPLODE,
	EV_CUSTOM_EXPLODE_NOMARKS,
	EV_CHANGE_TO_DUD,
	EV_DUD_EXPLODE,
	EV_DUD_IMPACT,
	EV_BULLET,
	EV_PLAY_FX,
	EV_PLAY_FX_ON_TAG,
	EV_PHYS_EXPLOSION_SPHERE,
	EV_PHYS_EXPLOSION_CYLINDER,
	EV_PHYS_EXPLOSION_JOLT,
	EV_PHYS_JITTER,
	EV_EARTHQUAKE,
	EV_GRENADE_SUICIDE,
	EV_DETONATE,
	EV_NIGHTVISION_WEAR,
	EV_NIGHTVISION_REMOVE,
	EV_OBITUARY,
	EV_NO_FRAG_GRENADE_HINT,
	EV_NO_SPECIAL_GRENADE_HINT,
	EV_TARGET_TOO_CLOSE_HINT,
	EV_TARGET_NOT_ENOUGH_CLEARANCE,
	EV_LOCKON_REQUIRED_HINT,
	EV_FOOTSTEP_SPRINT,
	EV_FOOTSTEP_RUN,
	EV_FOOTSTEP_WALK,
	EV_FOOTSTEP_PRONE,
	EV_JUMP,
	EV_LANDING_DEFAULT,
	EV_LANDING_BARK,
	EV_LANDING_BRICK,
	EV_LANDING_CARPET,
	EV_LANDING_CLOTH,
	EV_LANDING_CONCRETE,
	EV_LANDING_DIRT,
	EV_LANDING_FLESH,
	EV_LANDING_FOLIAGE,
	EV_LANDING_GLASS,
	EV_LANDING_GRASS,
	EV_LANDING_GRAVEL,
	EV_LANDING_ICE,
	EV_LANDING_METAL,
	EV_LANDING_MUD,
	EV_LANDING_PAPER,
	EV_LANDING_PLASTER,
	EV_LANDING_ROCK,
	EV_LANDING_SAND,
	EV_LANDING_SNOW,
	EV_LANDING_WATER,
	EV_LANDING_WOOD,
	EV_LANDING_ASPHALT,
	EV_LANDING_CERAMIC,
	EV_LANDING_PLASTIC,
	EV_LANDING_RUBBER,
	EV_LANDING_CUSHION,
	EV_LANDING_FRUIT,
	EV_LANDING_PAINTEDMETAL,
	EV_LANDING_PAIN_DEFAULT,
	EV_LANDING_PAIN_BARK,
	EV_LANDING_PAIN_BRICK,
	EV_LANDING_PAIN_CARPET,
	EV_LANDING_PAIN_CLOTH,
	EV_LANDING_PAIN_CONCRETE,
	EV_LANDING_PAIN_DIRT,
	EV_LANDING_PAIN_FLESH,
	EV_LANDING_PAIN_FOLIAGE,
	EV_LANDING_PAIN_GLASS,
	EV_LANDING_PAIN_GRASS,
	EV_LANDING_PAIN_GRAVEL,
	EV_LANDING_PAIN_ICE,
	EV_LANDING_PAIN_METAL,
	EV_LANDING_PAIN_MUD,
	EV_LANDING_PAIN_PAPER,
	EV_LANDING_PAIN_PLASTER,
	EV_LANDING_PAIN_ROCK,
	EV_LANDING_PAIN_SAND,
	EV_LANDING_PAIN_SNOW,
	EV_LANDING_PAIN_WATER,
	EV_LANDING_PAIN_WOOD,
	EV_LANDING_PAIN_ASPHALT,
	EV_LANDING_PAIN_CERAMIC,
	EV_LANDING_PAIN_PLASTIC,
	EV_LANDING_PAIN_RUBBER,
	EV_LANDING_PAIN_CUSHION,
	EV_LANDING_PAIN_FRUIT,
	EV_LANDING_PAIN_PAINTEDMETAL
};