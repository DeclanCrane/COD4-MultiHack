#pragma once
#include <stdint.h>
#include "COD4Enums.h"
#include "Vec.h"

typedef struct color_t
{
	char r;
	char g;
	char b;
	char a;
} color_t;

typedef struct WeaponDef
{
	const char* szInternalName;
	const char* szDisplayName;
	const char* szOverlayName;
	int* gunXModel[16];
	int* handXModel;
	const char* szXAnims[33];
	const char* szModeName;
	unsigned __int16 hideTags[8];
	unsigned __int16 notetrackSoundMapKeys[16];
	unsigned __int16 notetrackSoundMapValues[16];
	int playerAnimType;
	weapType_t weapType;
	weapClass_t weapClass;
	PenetrateType penetrateType;
	ImpactType impactType;
	weapInventoryType_t inventoryType;
	weapFireType_t fireType;
	OffhandClass offhandClass;
	weapStance_t stance;
	int* viewFlashEffect;
	int* worldFlashEffect;
	int* pickupSound;
	int* pickupSoundPlayer;
	int* ammoPickupSound;
	int* ammoPickupSoundPlayer;
	int* projectileSound;
	int* pullbackSound;
	int* pullbackSoundPlayer;
	int* fireSound;
	int* fireSoundPlayer;
	int* fireLoopSound;
	int* fireLoopSoundPlayer;
	int* fireStopSound;
	int* fireStopSoundPlayer;
	int* fireLastSound;
	int* fireLastSoundPlayer;
	int* emptyFireSound;
	int* emptyFireSoundPlayer;
	int* meleeSwipeSound;
	int* meleeSwipeSoundPlayer;
	int* meleeHitSound;
	int* meleeMissSound;
	int* rechamberSound;
	int* rechamberSoundPlayer;
	int* reloadSound;
	int* reloadSoundPlayer;
	int* reloadEmptySound;
	int* reloadEmptySoundPlayer;
	int* reloadStartSound;
	int* reloadStartSoundPlayer;
	int* reloadEndSound;
	int* reloadEndSoundPlayer;
	int* detonateSound;
	int* detonateSoundPlayer;
	int* nightVisionWearSound;
	int* nightVisionWearSoundPlayer;
	int* nightVisionRemoveSound;
	int* nightVisionRemoveSoundPlayer;
	int* altSwitchSound;
	int* altSwitchSoundPlayer;
	int* raiseSound;
	int* raiseSoundPlayer;
	int* firstRaiseSound;
	int* firstRaiseSoundPlayer;
	int* putawaySound;
	int* putawaySoundPlayer;
	int** bounceSound;
	int* viewShellEjectEffect;
	int* worldShellEjectEffect;
	int* viewLastShotEjectEffect;
	int* worldLastShotEjectEffect;
	int* reticleCenter;
	int* reticleSide;
	int iReticleCenterSize;
	int iReticleSideSize;
	int iReticleMinOfs;
	activeReticleType_t activeReticleType;
	float vStandMove[3];
	float vStandRot[3];
	float vDuckedOfs[3];
	float vDuckedMove[3];
	float vDuckedRot[3];
	float vProneOfs[3];
	float vProneMove[3];
	float vProneRot[3];
	float fPosMoveRate;
	float fPosProneMoveRate;
	float fStandMoveMinSpeed;
	float fDuckedMoveMinSpeed;
	float fProneMoveMinSpeed;
	float fPosRotRate;
	float fPosProneRotRate;
	float fStandRotMinSpeed;
	float fDuckedRotMinSpeed;
	float fProneRotMinSpeed;
	int* worldModel[16];
	int* worldClipModel;
	int* rocketModel;
	int* knifeModel;
	int* worldKnifeModel;
	int* hudIcon;
	weaponIconRatioType_t hudIconRatio;
	int* ammoCounterIcon;
	weaponIconRatioType_t ammoCounterIconRatio;
	ammoCounterClipType_t ammoCounterClip;
	int iStartAmmo;
	const char* szAmmoName;
	int iAmmoIndex;
	const char* szClipName;
	int iClipIndex;
	int iMaxAmmo;
	int iClipSize;
	int shotCount;
	const char* szSharedAmmoCapName;
	int iSharedAmmoCapIndex;
	int iSharedAmmoCap;
	int damage;
	int playerDamage;
	int iMeleeDamage;
	int iDamageType;
	int iFireDelay;
	int iMeleeDelay;
	int meleeChargeDelay;
	int iDetonateDelay;
	int iFireTime;
	int iRechamberTime;
	int iRechamberBoltTime;
	int iHoldFireTime;
	int iDetonateTime;
	int iMeleeTime;
	int meleeChargeTime;
	int iReloadTime;
	int reloadShowRocketTime;
	int iReloadEmptyTime;
	int iReloadAddTime;
	int iReloadStartTime;
	int iReloadStartAddTime;
	int iReloadEndTime;
	int iDropTime;
	int iRaiseTime;
	int iAltDropTime;
	int iAltRaiseTime;
	int quickDropTime;
	int quickRaiseTime;
	int iFirstRaiseTime;
	int iEmptyRaiseTime;
	int iEmptyDropTime;
	int sprintInTime;
	int sprintLoopTime;
	int sprintOutTime;
	int nightVisionWearTime;
	int nightVisionWearTimeFadeOutEnd;
	int nightVisionWearTimePowerUp;
	int nightVisionRemoveTime;
	int nightVisionRemoveTimePowerDown;
	int nightVisionRemoveTimeFadeInStart;
	int fuseTime;
	int aiFuseTime;
	int requireLockonToFire;
	int noAdsWhenMagEmpty;
	float autoAimRange;
	float aimAssistRange;
	float aimAssistRangeAds;
	float aimPadding;
	float enemyCrosshairRange;
	int crosshairColorChange;
	float moveSpeedScale;
	float adsMoveSpeedScale;
	float sprintDurationScale;
	float fAdsZoomFov;
	float fAdsZoomInFrac;
	float fAdsZoomOutFrac;
	int* overlayMaterial;
	int* overlayMaterialLowRes;
	weapOverlayReticle_t overlayReticle;
	WeapOverlayInteface_t overlayInterface;
	float overlayWidth;
	float overlayHeight;
	float fAdsBobFactor;
	float fAdsViewBobMult;
	float fHipSpreadStandMin;
	float fHipSpreadDuckedMin;
	float fHipSpreadProneMin;
	float hipSpreadStandMax;
	float hipSpreadDuckedMax;
	float hipSpreadProneMax;
	float fHipSpreadDecayRate;
	float fHipSpreadFireAdd;
	float fHipSpreadTurnAdd;
	float fHipSpreadMoveAdd;
	float fHipSpreadDuckedDecay;
	float fHipSpreadProneDecay;
	float fHipReticleSidePos;
	int iAdsTransInTime;
	int iAdsTransOutTime;
	float fAdsIdleAmount;
	float fHipIdleAmount;
	float adsIdleSpeed;
	float hipIdleSpeed;
	float fIdleCrouchFactor;
	float fIdleProneFactor;
	float fGunMaxPitch;
	float fGunMaxYaw;
	float swayMaxAngle;
	float swayLerpSpeed;
	float swayPitchScale;
	float swayYawScale;
	float swayHorizScale;
	float swayVertScale;
	float swayShellShockScale;
	float adsSwayMaxAngle;
	float adsSwayLerpSpeed;
	float adsSwayPitchScale;
	float adsSwayYawScale;
	float adsSwayHorizScale;
	float adsSwayVertScale;
	int bRifleBullet;
	int armorPiercing;
	int bBoltAction;
	int aimDownSight;
	int bRechamberWhileAds;
	float adsViewErrorMin;
	float adsViewErrorMax;
	int bCookOffHold;
	int bClipOnly;
	int adsFireOnly;
	int cancelAutoHolsterWhenEmpty;
	int enhanced;
	int laserSightDuringNightvision;
	int* killIcon;
	weaponIconRatioType_t killIconRatio;
	int flipKillIcon;
	int* dpadIcon;
	weaponIconRatioType_t dpadIconRatio;
	int bNoPartialReload;
	int bSegmentedReload;
	int iReloadAmmoAdd;
	int iReloadStartAdd;
	const char* szAltWeaponName;
	unsigned int altWeaponIndex;
	int iDropAmmoMin;
	int iDropAmmoMax;
	int blocksProne;
	int silenced;
	int iExplosionRadius;
	int iExplosionRadiusMin;
	int iExplosionInnerDamage;
	int iExplosionOuterDamage;
	float damageConeAngle;
	int iProjectileSpeed;
	int iProjectileSpeedUp;
	int iProjectileSpeedForward;
	int iProjectileActivateDist;
	float projLifetime;
	float timeToAccelerate;
	float projectileCurvature;
	int* projectileModel;
	weapProjExposion_t projExplosion;
	int* projExplosionEffect;
	int projExplosionEffectForceNormalUp;
	int* projDudEffect;
	int* projExplosionSound;
	int* projDudSound;
	int bProjImpactExplode;
	WeapStickinessType stickiness;
	int hasDetonator;
	int timedDetonation;
	int rotate;
	int holdButtonToThrow;
	int freezeMovementWhenFiring;
	float parallelBounce[29];
	float perpendicularBounce[29];
	int* projTrailEffect;
	float vProjectileColor[3];
	guidedMissileType_t guidedMissileType;
	float maxSteeringAccel;
	int projIgnitionDelay;
	int* projIgnitionEffect;
	int* projIgnitionSound;
	float fAdsAimPitch;
	float fAdsCrosshairInFrac;
	float fAdsCrosshairOutFrac;
	int adsGunKickReducedKickBullets;
	float adsGunKickReducedKickPercent;
	float fAdsGunKickPitchMin;
	float fAdsGunKickPitchMax;
	float fAdsGunKickYawMin;
	float fAdsGunKickYawMax;
	float fAdsGunKickAccel;
	float fAdsGunKickSpeedMax;
	float fAdsGunKickSpeedDecay;
	float fAdsGunKickStaticDecay;
	float fAdsViewKickPitchMin;
	float fAdsViewKickPitchMax;
	float fAdsViewKickYawMin;
	float fAdsViewKickYawMax;
	float fAdsViewKickCenterSpeed;
	float fAdsViewScatterMin;
	float fAdsViewScatterMax;
	float fAdsSpread;
	int hipGunKickReducedKickBullets;
	float hipGunKickReducedKickPercent;
	float fHipGunKickPitchMin;
	float fHipGunKickPitchMax;
	float fHipGunKickYawMin;
	float fHipGunKickYawMax;
	float fHipGunKickAccel;
	float fHipGunKickSpeedMax;
	float fHipGunKickSpeedDecay;
	float fHipGunKickStaticDecay;
	float fHipViewKickPitchMin;
	float fHipViewKickPitchMax;
	float fHipViewKickYawMin;
	float fHipViewKickYawMax;
	float fHipViewKickCenterSpeed;
	float fHipViewScatterMin;
	float fHipViewScatterMax;
	float fightDist;
	float maxDist;
	const char* accuracyGraphName[2];
	float(*accuracyGraphKnots[2])[2];
	float(*originalAccuracyGraphKnots[2])[2];
	int accuracyGraphKnotCount[2];
	int originalAccuracyGraphKnotCount[2];
	int iPositionReloadTransTime;
	float leftArc;
	float rightArc;
	float topArc;
	float bottomArc;
	float accuracy;
	float aiSpread;
	float playerSpread;
	float minTurnSpeed[2];
	float maxTurnSpeed[2];
	float pitchConvergenceTime;
	float yawConvergenceTime;
	float suppressTime;
	float maxRange;
	float fAnimHorRotateInc;
	float fPlayerPositionDist;
	const char* szUseHintString;
	const char* dropHintString;
	int iUseHintStringIndex;
	int dropHintStringIndex;
	float horizViewJitter;
	float vertViewJitter;
	const char* szScript;
	float fOOPosAnimLength[2];
	int minDamage;
	int minPlayerDamage;
	float fMaxDamageRange;
	float fMinDamageRange;
	float destabilizationRateTime;
	float destabilizationCurvatureMax;
	int destabilizeDistance;
	float locationDamageMultipliers[19];
	const char* fireRumble;
	const char* meleeImpactRumble;
	float adsDofStart;
	float adsDofEnd;
	float hipDofStart;
	float hipDofEnd;
} WeaponDef;

typedef struct WeaponParms {
	vec3_t forward;
	vec3_t right;
	vec3_t up;
	vec3_t muzzleTrace;
	vec3_t gunForward;
	WeaponDef* weaponDef;
};

typedef struct RefDef
{
	int32_t x; //0x0000
	int32_t y; //0x0004
	int32_t width; //0x0008
	int32_t height; //0x000C
	float tanHalfFovX; //0x0010
	float tanHalfFovY; //0x0014
	vec3_t vOrigin; //0x0018
	vec3_t mViewMatrix[3]; //0x0024
	vec3_t vCameraPos; //0x0048
	int32_t time; //0x0054
	float zNear; //0x0058
	float blurRadius; //0x005C
} RefDef; //Size: 0x0060

typedef struct ActionSlotParam_SpecifyWeapon
{
	unsigned int index;
};

typedef struct ActionSlotParam
{
	ActionSlotParam_SpecifyWeapon specifyWeapon;
};

typedef struct MantleState
{
	float yaw;
	int timer;
	int transIndex;
	int flags;
};

typedef struct SprintState
{
	int sprintButtonUpRequired;
	int sprintDelay;
	int lastSprintStart;
	int lastSprintEnd;
	int sprintStartMaxLength;
};

typedef struct score_t
{
	int32_t Client; //0x0000
	int32_t Score; //0x0004
	int32_t Ping; //0x0008
	int32_t Deaths; //0x000C
	int32_t Team; //0x0010
	int32_t Kills; //0x0014
	int32_t Rank; //0x0018
	int32_t Assists; //0x001C
	void* hStatusIcon; //0x0020
	void* hRankIcon; //0x0024
} score_t; //Size: 0x0028

typedef struct objective_t
{
	objectiveState_t state;
	float origin[3];
	int entNum;
	int teamNum;
	int icon;
} objective_t;

typedef struct trajectory_t
{
	int32_t trType; //0x0000
	int32_t trTime; //0x0004
	int32_t trDuration; //0x0008
	vec3_t trBase; //0x000C
	vec3_t trDelta; //0x0018
}; //Size: 0x0024

// Junk for now
typedef struct shellshock_t
{
	char pad_0000[32]; //0x0000
} shellshock_t; //Size: 0x0020

typedef struct LerpEntityState
{
	int32_t eFlags; //0x0000
	class trajectory_t trOrigin; //0x0004
	class trajectory_t trAngles; //0x0028
	char LerpEntityStateTypeUnion[7][4]; //0x004C
} LerpEntityState; //Size: 0x0068

typedef struct playerState_s
{
	int32_t CommandTime; //0x0000
	int32_t pm_type; //0x0004
	int32_t bobCycle; //0x0008
	int32_t pm_flags; //0x000C
	int32_t weapFlags; //0x0010
	int32_t otherFlags; //0x0014
	int32_t pm_time; //0x0018
	vec3_t vOrigin; //0x001C
	vec3_t vVelocity; //0x0028
	vec3_t vOldVelocity; //0x0034
	int32_t weaponTime; //0x0040
	int32_t grenadeTimeLeft; //0x0044
	int32_t throwBackGrenadeOwner; //0x0048
	int32_t throwBackGrenadeTimeLeft; //0x004C
	int32_t weaponRestrictKickTime; //0x0050
	int32_t foliageSoundTime; //0x0054
	int32_t gravity; //0x0058
	float lean_f; //0x005C
	int32_t speed; //0x0060
	vec3_t deltaAngles; //0x0064
	int32_t groundEntityNum; //0x0070
	vec3_t vLadderVec; //0x0074
	int32_t jumpTime; //0x0080
	float jumpOriginZ; //0x0084
	int32_t legsTimer; //0x0088
	int32_t legsAnim; //0x008C
	int32_t torsoTimer; //0x0090
	int32_t torsoAnim; //0x0094
	int32_t legsAnimDuration; //0x0098
	int32_t torsoAnimDuration; //0x009C
	int32_t damageTimer; //0x00A0
	int32_t damageDuration; //0x00A4
	int32_t flinchYawAnim; //0x00A8
	int32_t movementDirection; //0x00AC
	int32_t eFlags; //0x00B0
	int32_t eventSequence; //0x00B4
	char events[4][4]; //0x00B8
	char eventParms[4][4]; //0x00C8
	int32_t oldEventSequence; //0x00D8
	int32_t clientNum; //0x00DC
	int32_t offHandIndex; //0x00E0
	int32_t offHandSecondary; //0x00E4
	int32_t weapon; //0x00E8
	int32_t weaponState; //0x00EC
	int32_t weaponShotCount; //0x00F0
	float fWeaponPosFrac; //0x00F4
	int32_t adsDelayTime; //0x00F8
	int32_t spreadOverride; //0x00FC
	int32_t spreadOverrideState; //0x0100
	int32_t viewModelIndex; //0x0104
	vec3_t vViewAngles; //0x0108
	int32_t viewHeightTarget; //0x0114
	float viewHeightCurrent; //0x0118
	int32_t viewHeightLerpTime; //0x011C
	int32_t viewHeightLerpTarget; //0x0120
	int32_t viewHeightLerpDown; //0x0124
	vec2_t vViewAngleClampBase; //0x0128
	vec2_t vViewAngleClampRange; //0x0130
	int32_t damageEvent; //0x0138
	int32_t damageYaw; //0x013C
	int32_t damagePitch; //0x0140
	int32_t damageCount; //0x0144
	char stats[5][4]; //0x0148
	char ammo[128][4]; //0x015C
	char ammoClip[128][4]; //0x035C
	char weapons[4][4]; //0x055C
	char weaponsOld[4][4]; //0x056C
	char weaponsRechamber[4][4]; //0x057C
	float proneDirection; //0x058C
	float proneDirectionPitch; //0x0590
	float proneTorsoPitch; //0x0594
	int32_t viewLocked; //0x0598
	int32_t viewLocked_entNum; //0x059C
	int32_t cursorHint; //0x05A0
	int32_t cursorHintString; //0x05A4
	int32_t cursorHintIndex; //0x05A8
	int32_t iCompassPlayerInfo; //0x05AC
	int32_t radarEnabled; //0x05B0
	int32_t locationSelectionInfo; //0x05B4
	char sprintState[5][4]; //0x05B8
	float fTorsoPitch; //0x05CC
	float fWaistPitch; //0x05D0
	float holdBreathScale; //0x05D4
	int32_t holdBreathTimer; //0x05D8
	float moveSpeedScaleMultiplier; //0x05DC
	char mantleState[4][4]; //0x05E0
	float meleeChargeYaw; //0x05F0
	int32_t meleeChargeDist; //0x05F4
	int32_t meleeChargeTime; //0x05F8
	int32_t perks; //0x05FC
	char actionSlotType[4][4]; //0x0600
	char actionSlotParam[4][4]; //0x0610
	int32_t entityEventSequence; //0x0620
	int32_t weaponAnim; //0x0624
	float aimSpreadScale; //0x0628
	int32_t shellshockIndex; //0x062C
	int32_t shellshockTime; //0x0630
	int32_t shellshockDuration; //0x0634
	float dofNearStart; //0x0638
	float dofNearEnd; //0x063C
	float dofFarStart; //0x0640
	float dofFarEnd; //0x0644
	float dofNearBlur; //0x0648
	float dofFarBlur; //0x064C
	int32_t hudElemLastAssignedSoundID; //0x0650
	struct objective_t objective[16]; //0x0654
	char pad_0814[9552]; //0x0814
} playerState_s; //Size: 0x2D64

typedef struct playerEntity_t
{
	float fLastWeaponPosFrac; //0x0000
	int32_t bPositionToADS; //0x0004
	vec3_t vPositionLastOrigin; //0x0008
	float fLastIdleFactor; //0x0014
	vec3_t vLastMoveOrg; //0x0018
	vec3_t vLastMoveAng; //0x0024
} playerEntity_t; //Size: 0x0030

typedef struct entityState_s
{
	int32_t number; //0x0000
	int32_t eType; //0x0004
	struct LerpEntityState lerpEntityState; //0x0008
	int32_t time2; //0x0070
	int32_t otherEntityNum; //0x0074
	int32_t attackerEntityNum; //0x0078
	int32_t groundEntityNum; //0x007C
	int32_t loopSound; //0x0080
	int32_t surfType; //0x0084
	int32_t index; //0x0088
	int32_t clientNum; //0x008C
	int32_t iHeadIcon; //0x0090
	int32_t iHeadIconTeam; //0x0094
	int32_t solid; //0x0098
	int32_t eventParam; //0x009C
	int32_t eventSequence; //0x00A0
	char events[4][4]; //0x00A4
	char eventParms[4][4]; //0x00B4
	int32_t weapon; //0x00C4
	int32_t weaponModel; //0x00C8
	int32_t legsAnim; //0x00CC
	int32_t torsoAnim; //0x00D0
	int32_t un1; //0x00D4
	int32_t un2; //0x00D8
	float fTorsoPitch; //0x00DC
	float fWaistPitch; //0x00E0
	char partBits[4][4]; //0x00E4
} entityState_s; //Size: 0x00F4

typedef struct entityShared_t
{
	int8_t linked; //0x0000
	int8_t bmodel; //0x0001
	int8_t svFlags; //0x0002
	int8_t undef; //0x0003
	char clientMask[2][4]; //0x0004
	int8_t inUse; //0x000C
	int8_t undef2; //0x000D
	int8_t undef3; //0x000E
	int8_t undef4; //0x000F
	int32_t broadcastTime; //0x0010
	vec3_t mins; //0x0014
	vec3_t maxs; //0x0020
	int32_t contents; //0x002C
	vec3_t absmin; //0x0030
	vec3_t absmax; //0x003C
	vec3_t currentOrigin; //0x0048
	vec3_t currentAngles; //0x0054
	int32_t ownerNum; //0x0060
	int32_t eventTime; //0x0064
}; //Size: 0x0068

typedef struct cpose_t
{
	int16_t lightingHandle; //0x0000
	int8_t eType; //0x0002
	int8_t eTypeUnion; //0x0003
	int8_t localClientNum; //0x0004
	int8_t Undef1; //0x0005
	int8_t Undef2; //0x0006
	int8_t Undef3; //0x0007
	int32_t cullIn; //0x0008
	int8_t isRagdoll; //0x000C
	int8_t Undef4; //0x000D
	int8_t Undef5; //0x000E
	int8_t Undef6; //0x000F
	int32_t ragdollHandle; //0x0010
	int32_t killcamRagdollHandle; //0x0014
	int32_t physObjId; //0x0018
	vec3_t origin; //0x001C
	vec3_t angles; //0x0028
	char zUnknown[12][4]; //0x0034
} cpose_t; //Size: 0x0064

typedef struct usercmd_s
{
	int32_t serverTime; //0x0000
	int8_t bHoldingShift; //0x0004
	int8_t Stance; //0x0005
	int8_t InMenu; //0x0006
	int8_t N0001E138; //0x0007
	int32_t Pitch; //0x0008
	int32_t Yaw; //0x000C
	int32_t Roll; //0x0010
	int8_t WeaponIndex; //0x0014
	int8_t OffHandIndex; //0x0015
	int8_t ForwardBackward; //0x0016
	int8_t LeftRight; //0x0017
	int32_t zJunk; //0x0018
	int32_t zJunk2; //0x001C
} usercmd_s; //Size: 0x0020

struct updatedCmd_s {
	int serverTime; // 0x0
	int eFlags; // 0x4
	int Pitch; // 0x8
	int Yaw; // 0xC
	int Roll; // 0x10
	int zUnknown[3]; // 0x14 - 0x1C
};

struct input_t
{
	updatedCmd_s cmds[128];
	int currentCmdNum;
}; //Size: 0x1004

typedef struct centity_t {
	cpose_t pose;
	LerpEntityState lerpEntityState;
	entityState_s entityState;
	char padding[28];
} centity_t;

typedef struct playerTeamState_t
{
	int32_t location; //0x0000
} playerTeamState_t; //Size: 0x0004

typedef struct clientState_s
{
	int32_t clientIndex; //0x0000
	int32_t team_t; //0x0004
	int32_t modelIndex; //0x0008
	char attachModelIndex[6][4]; //0x000C
	char attachTagIndex[6][4]; //0x0024
	char name[16]; //0x003C
	int32_t zJunk; //0x004C
	int32_t rank; //0x0050
	int32_t zJunk2; //0x0054
	int32_t voiceConnectivityBits; //0x0058
	int32_t clanIndex; //0x005C
	char clanAbbrev[8]; //0x0060
	int32_t attachedVehEntNum; //0x0068
	int32_t attachedVehSlotIndex; //0x006C
	int32_t zJunk3; //0x0070
	int32_t bIntermission; //0x0074
	char pad_0078[9280]; //0x0078
} clientState_s; //Size: 0x24B8

typedef struct clientSession_t
{
	int32_t sessionState_t; //0x0000
	int32_t forceSpectatorClient; //0x0004
	int32_t status_icon; //0x0008
	int32_t bDead; //0x000C
	int32_t zJunk; //0x0010
	int32_t points; //0x0014
	int32_t deaths; //0x0018
	int32_t kills; //0x001C
	int32_t assists; //0x0020
	int16_t scriptPerIds; //0x0024
	int8_t zJunk1; //0x0026
	int8_t zJunk2; //0x0027
	int32_t clientConnected_t; //0x0028
	struct usercmd_s cmd; //0x002C
	struct usercmd_s oldcmd; //0x004C
	int32_t localClient; //0x006C
	int32_t predictItemPickup; //0x0070
	char name[16]; //0x0074
	int32_t maxHealth; //0x0084
	int32_t zJunk3; //0x0088
	int32_t zJunk4; //0x008C
	int32_t zJunk5; //0x0090
	int32_t zJunk6; //0x0094
	float fMovementSpeed; //0x0098
	int32_t teamState; //0x009C
	int32_t oldTeamState; //0x00A0
	int32_t zJunk7; //0x00A4
	struct clientState_s clientState; //0x00A8
	int32_t psOffsetTime; //0x2560
} clientSession_t; //Size: 0x2564

typedef struct gclient_s
{
	struct playerState_s playerState;
	char padding[128][4]; //0x2D64
	struct clientSession_t clientSession; //0x2F64
	int8_t bHoldingShift; //0x54C8
	int8_t Stance; //0x54C9
	int8_t bMenu; //0x54CA
	int8_t zJunk; //0x54CB
	int8_t bHoldingShift1; //0x54CC
	int8_t Stance1; //0x54CD
	int8_t bMenu1; //0x54CE
	int8_t zJunk1; //0x54CF
	int32_t zJunk2; //0x54D0
	int32_t zJunk3; //0x54D4
	vec3_t oldOrigin; //0x54D8
	vec3_t oldAngles; //0x54E4
	vec3_t hitGroundOrigin; //0x54F0
	char pad_54FC[16]; //0x54FC
	int32_t time; //0x550C
	char pad_5510[12]; //0x5510
	float forwardVelocityPercentage; //0x551C
	char pad_5520[36]; //0x5520
	int32_t unknown; //0x5544
	char pad_5548[16]; //0x5548
	vec3_t viewAngles; //0x5558
	char pad_5564[4]; //0x5564
	char viewAngleChange[4][4]; //0x5568
	char pad_5578[16]; //0x5578
	float N0001E2AA; //0x5588
	char pad_558C[24]; //0x558C
	int32_t gameTime; //0x55A4
	int32_t serverTime; //0x55A8
	char pad_55AC[4]; //0x55AC
	int32_t weapon; //0x55B0
	int8_t bFiring; //0x55B4
	int8_t zJunk4; //0x55B5
	int8_t bSprinting; //0x55B6
	int8_t zJunk5; //0x55B7
	int32_t zJunk6; //0x55B8
	int32_t zJunk7; //0x55BC
	int32_t zJunk8; //0x55C0
} gclient_s; //Size: 0x55C4

typedef struct gentity_s {
	struct entityState_s entityState;
	struct entityShared_t entityShared; //0x00F4
	gclient_s* client; //0x015C
	int32_t pTurretInfo; //0x0160
	int32_t scr_vehicle; //0x0164
	int16_t model; //0x0168
	int8_t physicsObject; //0x016A
	int8_t takeDamage; //0x016B
	int8_t active; //0x016C
	int8_t noPickup; //0x016D
	int8_t handler; //0x016E
	int8_t team; //0x016F
	int16_t className; //0x0170
	int16_t target; //0x0172
	int16_t targetName; //0x0174
	int8_t undef; //0x0176
	int8_t undef1; //0x0177
	int32_t attachIgnoreCollision; //0x0178
	int32_t spawnFlags; //0x017C
	int32_t flags; //0x0180
	int32_t eventTime; //0x0184
	int32_t freeAfterEvent; //0x0188
	int32_t unlinkAfterEvent; //0x018C
	int32_t clipMask; //0x0190
	int32_t processedFrame; //0x0194
	void* parent; //0x0198
	int32_t nextThink; //0x019C
	int32_t health; //0x01A0
	int32_t maxHealth; //0x01A4
	int32_t damage; //0x01A8
	int32_t count; //0x01AC
	void* chain; //0x01B0
	char ___u30[24][4]; //0x01B4
	void* tagInfo; //0x0214
	void* tagChildren; //0x0218
	char attachModelNames[9][4]; //0x021C
	char attachTagNames[10][4]; //0x0240
	int32_t useCount; //0x0268
	void* nextFree; //0x026C
} gentity_s; //Size: 0x0270

// Needs work
typedef struct snapshot_clientState
{
	char name[16]; //0x0000
	char pad_0010[4]; //0x0010
	int32_t rank; //0x0014
	char pad_0018[76]; //0x0018
} snapshot_clientState; //Size: 0x0064

typedef struct snapshot_s
{
	int32_t snapFlags; //0x0000
	int32_t ping; //0x0004
	int32_t serverTime; //0x0008
	struct playerState_s playerState; //0x000C
	char zJunk[128][4]; //0x2D70
	int32_t numEntities; //0x2F70
	int32_t numClients; //0x2F74
	class entityState_s entities[512]; //0x2F78
	int32_t zJunk1; //0x21778
	int32_t zUnknown; //0x2177C
	int32_t zUnknown1; //0x21780
	int32_t zUnknown3; //0x21784
	char zJunk2[11][4]; //0x21788
	class snapshot_clientState clientStates[63]; //0x217B4
	char zJunk3[10][4]; //0x23050
	int32_t serverCommandSequence; //0x23078
} snapshot_s; //Size: 0x2307C

typedef struct CGs_t
{
	int32_t viewX; //0x0000
	int32_t viewY; //0x0004
	int32_t ScreenWidth; //0x0008
	int32_t ScreenHeight; //0x000C
	float AspectRatio; //0x0010
	int32_t serverCommandSequence; //0x0014
	int32_t processedSnapshotNum; //0x0018
	int32_t localServer; //0x001C
	char gameType[32]; //0x0020
	char serverName[256]; //0x0040
	int32_t maxClients; //0x0140
	char mapname[64]; //0x0144
	int32_t gameEndTime; //0x0184
	int32_t voteTime; //0x0188
	int32_t voteYes; //0x018C
	int32_t voteNo; //0x0190
	char voteString[256]; //0x0194
	int32_t redCrosshair; //0x0294
	char gameModels[512][4]; //0x0298
	char FXs[100][4]; //0x0A98
	char pad_0C28[1896]; //0x0C28
	char teamChatMsgTimes[8][4]; //0x1390
	int32_t teamChatPos; //0x13B0
	int32_t teamLastChatPos; //0x13B4
	char pad_13B8[3196]; //0x13B8
}; //Size: 0x2034

typedef struct CG_s
{
	int32_t clientNum; //0x0000
	int32_t localClientNum; //0x0004
	int32_t demoType; //0x0008
	int32_t cubeMapShot; //0x000C
	int32_t cubeMapSize; //0x0010
	int32_t renderScreen; //0x0014
	int32_t latestSnapshotNum; //0x0018
	int32_t latestSnapshotTime; //0x001C
	void* snap; //0x0020
	void* nextSnap; //0x0024
	struct snapshot_s snapOne; //0x0028
	struct snapshot_s snapTwo; //0x230A4
	float frameInterpolation; //0x46120
	int32_t frameTime; //0x46124
	int32_t time; //0x46128
	int32_t oldTime; //0x4612C
	int32_t physicsTime; //0x46130
	int32_t mapRestart; //0x46134
	int32_t renderingThirdPerson; //0x46138
	struct playerState_s predictedPlayerState; //0x4613C
	char zJunk1[128][4]; //0x48EA0
	struct centity_t predictedPlayerEntity; //0x490A0
	struct playerEntity_t playerEntity; //0x4927C
	int32_t predictedErrorTime; //0x492AC
	vec3_t predictedError; //0x492B0
	float landChange; //0x492BC
	int32_t landTime; //0x492C0
	float heightToCeiling; //0x492C4
	struct RefDef refdef; //0x492C8
	char pad_49328[16440]; //0x49328
	vec3_t refDefViewAngles; //0x4D360
	vec3_t lastViewOrg; //0x4D36C
	vec3_t swayViewAngles; //0x4D378
	vec3_t swayAngles; //0x4D384
	vec3_t swayOffset; //0x4D390
	char iEntityLastType[1024][4]; //0x4D39C
	char pEntityLastXModel[1024][4]; //0x4E39C
	float zoomSensitivity; //0x4F39C
	int8_t isLoading; //0x4F3A0
	char objectiveText[1024]; //0x4F3A1
	char scriptMainMenu[128]; //0x4F7A1
	char zJunk2[30][4]; //0x4F821
	int8_t zJunk3; //0x4F899
	int8_t zJunk4; //0x4F89A
	int8_t zJunk5; //0x4F89B
	int8_t zJunk6; //0x4F89C
	int8_t zJunk7; //0x4F89D
	int8_t zJunk8; //0x4F89E
	int8_t zJunk9; //0x4F89F
	int32_t zJunk10; //0x4F8A0
	int32_t scoresRequestTime; //0x4F8A4
	int32_t numScores; //0x4F8A8
	char teamScores[4][4]; //0x4F8AC
	char teamPingsAverages[4][4]; //0x4F8BC
	char teamNumPlayers[4][4]; //0x4F8CC
	struct score_t scores[64]; //0x4F8DC
	int32_t scoreLimit; //0x502DC
	int32_t scoreFadeTime; //0x502E0
	int32_t scoresTop; //0x502E4
	int32_t scoresOffBottom; //0x502E8
	int32_t scoresBottom; //0x502EC
	int32_t selectedGamerIndex; //0x502F0
	int32_t drawHud; //0x502F4
	int32_t crosshairClientNum; //0x502F8
	int32_t crosshairClientLastTime; //0x502FC
	int32_t crosshairClientStartTime; //0x50300
	int32_t identifyClientNum; //0x50304
	int32_t cursorHintIcon; //0x50308
	int32_t cursorHintTime; //0x5030C
	int32_t cursorHintFade; //0x50310
	int32_t cursorHintString; //0x50314
	int32_t lastClipFlashTime; //0x50318
	int32_t lastHealthPulseTime; //0x5031C
	int32_t lastHealthLerpDelay; //0x50320
	int32_t lastHealthClient; //0x50324
	char pad_50328[12]; //0x50328
	float healthOverlayPulse; //0x50334
	float healthOverlayToAlpha; //0x50338
	int32_t healthOverlayPulseTime; //0x5033C
	int32_t healthOverlayPulseDuration; //0x50340
	int32_t healthOverlayPulsePhase; //0x50344
	int8_t healthOverlayHurt; //0x50348
	int8_t undef; //0x50349
	int8_t undef1; //0x5034A
	int8_t undef2; //0x5034B
	int32_t healthOverlayLastHitTime; //0x5034C
	float healthOverlayOldHealth; //0x50350
	int32_t healthOverlayPulseIndex; //0x50354
	int32_t proneBlockedEndTime; //0x50358
	int32_t lastStance; //0x5035C
	int32_t lastStanceChangeTime; //0x50360
	int32_t lastStanceFlashTime; //0x50364
	int32_t voiceTime; //0x50368
	int32_t weaponSelect; //0x5036C
	int32_t weaponSelectTime; //0x50370
	int32_t weaponLatestPrimaryIndex; //0x50374
	int32_t prevViewmodelWeapon; //0x50378
	int32_t equippedOffHand; //0x5037C
	char zJunk11[24][4]; //0x50380
	int32_t damageTime; //0x503E0
	float damageX; //0x503E4
	float damageY; //0x503E8
	float damageValue; //0x503EC
	float viewFade; //0x503F0
	int32_t weaponIdleTime; //0x503F4
	int32_t nomarks; //0x503F8
	int32_t v_dmg_time; //0x503FC
	float v_dmg_pitch; //0x50400
	float v_dmg_roll; //0x50404
	float fBobCycle; //0x50408
	float xySpeed; //0x5040C
	vec3_t kickAVelocity; //0x50410
	vec3_t kickAngles; //0x5041C
	vec3_t offsetAngles; //0x50428
	float gunPitch; //0x50434
	float gunYaw; //0x50438
	float gunXOfs; //0x5043C
	float gunYOfs; //0x50440
	float gunZOfs; //0x50444
	vec3_t vGunOffset; //0x50448
	vec3_t vGunSpeed; //0x50454
	vec3_t viewModelMatrix[3]; //0x50460
	vec3_t viewModelAxis; //0x50484
	float rumbleScale; //0x50490
	float compassNorthYaw; //0x50494
	vec2_t compassNorth; //0x50498
	void* compassMapMaterial; //0x504A0
	vec2_t compassUpperLeft; //0x504A4
	vec2_t compassMapWorldSize; //0x504AC
	int32_t compassFadeTime; //0x504B4
	int32_t healthFadeTime; //0x504B8
	int32_t ammoFadeTime; //0x504BC
	int32_t stanceFadeTime; //0x504C0
	int32_t offhandFadeTime; //0x504C4
	int32_t offhandFlashTime; //0x504C8
	struct shellshock_t shellshock; //0x504CC
	char testShock[3][4]; //0x504EC
	int32_t holdBreathTime; //0x504F8
	int32_t holdBreathInTime; //0x504FC
	int32_t holdBreathDelay; //0x50500
	float holdBreathFrac; //0x50504
	float radarProgress; //0x50508
	vec2_t selectedLocation; //0x5050C
	struct SprintState sprintStates; //0x50514
	int32_t adsViewErrorDone; //0x50528
	int32_t inKillCam; //0x5052C
}; //Size: 0x50530

typedef union hudelem_color_t
{
	color_t color;
	int rgba;
};

typedef struct hudelem_s
{
	he_type_t type;
	float x;
	float y;
	float z;
	float fontScale;
	int font;
	int alignOrg;
	int alignScreen;
	hudelem_color_t color;
	hudelem_color_t fromColor;
	int fadeStartTime;
	int fadeTime;
	int label;
	int width;
	int height;
	int materialIndex;
	int fromWidth;
	int fromHeight;
	int scaleStartTime;
	int scaleTime;
	float fromX;
	float fromY;
	int fromAlignOrg;
	int fromAlignScreen;
	int moveStartTime;
	int moveTime;
	int time;
	int duration;
	float value;
	int text;
	float sort;
	hudelem_color_t glowColor;
	int fxBirthTime;
	int fxLetterTime;
	int fxDecayStartTime;
	int fxDecayDuration;
	int soundID;
	int flags;
};

typedef struct hud_t
{
	hudelem_s current[31];
	hudelem_s archival[31];
};

typedef struct DvarValueStringBuf {
	int* pad;
	char string[12];
};

typedef union DvarValue {
	int8_t value;
	int integer;
	int unsignedInt;
	float valuef;
	float vector[4];
	char* string;
	DvarValueStringBuf stringBuf;
	color_t color;
};

typedef struct dvar_s {
	char* name;
	char* description;
	int16_t flags;
	int8_t type;
	int8_t modified;
	DvarValue current;
	DvarValue latched;
	DvarValue reset;
};

struct trace_t
{
	float Fraction;
	vec3_t normal;
	int surfaceFlags;
	int contents;
	char* material;
	TraceHitType hitType;
	unsigned char szUnknown0[264];
};

typedef struct BulletTraceResults 
{
	trace_t trace;
	int* hitEnt;
	vec3_t hitPos;
	int8_t ignoreHitEnt;
	int8_t zJunk;
	int8_t zJunk1;
	int8_t zJunk2;
};

typedef struct BulletFireParams
{
	int weaponEntIndex;
	int ignoreEntindex;
	float damageMultiplier;
	int methodOfDeath;
	vec3_t origStart;
	vec3_t start;
	vec3_t end;
	vec3_t dir;
};

struct clSnapshot_t
{
	int valid; //0x0000
	int snapFlags; //0x0004
	int serverTime; //0x0008
	int messageNum; //0x000C
	int deltaNum; //0x0010
	int ping; //0x0014
	int cmdNum; //0x0018
	char PlayerState[3033][4]; //0x001C
	int numEntities; //0x2F80
	int numClients; //0x2F84
	int parseEntitiesNum; //0x2F88
	int parseClientsNum; //0x2F8C
	int serverCommandNum; //0x2F90
}; //Size: 0x2F94

//struct gameState_t
//{
//	int stringOffsets[2304];
//	char stringData[131072];
//	int dataCount;
//};

//struct clientActive_t {
//	bool usingADS;
//	char padding[3];
//	int timeoutCount;
//	clSnapshot_t snap;
//	int serverTime;
//	int oldServerTime;
//	int oldFrameServerTime;
//	int serverTimeDelta;
//	int oldSnapServerTime;
//	int extrapolatedSnapshot;
//	int newSnapshots;
//	gameState_t gameState;
//	char mapname[32];
//};