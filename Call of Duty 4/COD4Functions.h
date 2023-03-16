#pragma once
#include "COD4Structs.h";

// Unfinished, doesn't return string
// Works though
/*
	Returns the name of the player associated with the client number
*/
void GetPlayerNameByClientNum(int clientNum);

// Gets the world position of a tag (e.g. player bone)
void AimTarget_GetTagPos(unsigned short tagName, centity_t* centity, vec3_t* origin);

/*
	Checks if the entity is valid.
	( Unsure what is considered valid. Needs more testing )
*/
bool IsTargetValid(centity_t* cEnt);

/*
	Checks if entity is visible to local player.
	Returns true if they're visible.
*/
bool IsTargetVisible(unsigned short tag, centity_t* cEnt);

/* 
	Casts a raytrace to a specified point, and returns hit informations
	( Used for checking if player is visible )
*/
void __cdecl CG_Trace(trace_t* pTrace, const vec3_t startPos, const vec3_t endPos, vec3_t min, vec3_t max, int skipNum, int traceFlags);

/*
	Checks whether both entities are on the same team.
	Returns true if they are.
*/
bool CG_OnSameTeam(gentity_s* gEnt, gentity_s* gEnt2);

/* 
	Disconnects client associated with the client number.
	( Pretty sure this is only works on LAN servers )
*/
typedef int(__cdecl* _ClientDisconnect)(int clientNum);
extern _ClientDisconnect ClientDisconnect;

/*
	Registers tags for later use.
	e.g. j_head
*/
typedef unsigned short(__cdecl* _RegisterTag)(const char* tagName, int always1, int sizeOfTagName);
extern _RegisterTag RegisterTag;

/*
	Switchs players' weapon
	Only works on local client
*/
typedef void(__cdecl* _CG_OutOfAmmoChange)(int localClientNum);
extern _CG_OutOfAmmoChange CG_OutOfAmmoChange;

typedef void(__cdecl* _FireWeapon)(gentity_s* gEnt, int gameTime);
extern _FireWeapon FireWeapon;

typedef int(__cdecl* _FireWeaponMelee)(int* gEnt, int gameTime);
extern _FireWeaponMelee FireWeaponMelee;

typedef void(__cdecl* _TeleportPlayer)(int* gEnt, vec3_t origin, vec3_t angles);
extern _TeleportPlayer TeleportPlayer;

// Changes other player's view angles.
// Does not work on local client
typedef void(__cdecl* _SetClientViewAngle)(gentity_s* gEnt, const vec3_t angles);
extern _SetClientViewAngle SetClientViewAngle;

/*
	Returns weapon index from weapName
*/
typedef int(__cdecl* _BG_GetWeaponIndexForName)(const char* weapName);
extern _BG_GetWeaponIndexForName BG_GetWeaponIndexForName;

typedef vec3_t(__cdecl* _BG_GetPlayerViewDirection)(playerState_s* ps, vec3_t* forward, vec3_t* right, vec3_t* up);
extern _BG_GetPlayerViewDirection BG_GetPlayerViewDirection;

typedef void(__cdecl* _BG_GetPlayerViewOrigin)(playerState_s* ps, vec3_t* origin, int time);
extern _BG_GetPlayerViewOrigin BG_GetPlayerViewOrigin;

typedef int(__cdecl* _BulletGetDamage)(WeaponDef* wd, BulletFireParams* bfp, BulletTraceResults* btr);
extern _BulletGetDamage BulletGetDamage;

typedef bool(__cdecl* _BG_AdvanceTrace)(BulletFireParams* bfp, BulletTraceResults* btr, float amount);
extern _BG_AdvanceTrace BG_AdvanceTrace;

void G_GetPlayerViewOrigin(int* client, vec3_t* origin);

void GetViewDirection(int* client, vec3_t* forward, vec3_t* right, vec3_t* up);

void GetWeaponSpread(playerState_s* ps, vec3_t* mins, vec3_t* maxs, WeaponDef* weapDef);

void WeaponFireRecoil(playerState_s* ps, vec3_t* speed, vec3_t* kick);

// Use unknown.
// Works though
void WeaponStuff(playerState_s* ps, int clientNum);

// Works
void CG_CalcEyePoint(int clientNum, vec3_t* pos);

// Works, but not using it right.
// Game crashes
void FillWeaponParms(WeaponParms* weapParms, gentity_s* gEnt);

bool CreateProfile(const char* profileName);

void CalcMuzzlePointsASM(WeaponParms* weapParms, gentity_s* gEnt, WeaponDef* weapDef);

void WeaponMelee(int time, WeaponParms* wp, gentity_s* gEnt, float range, float width, float height);

void CG_FireWeapon(int localClientNum, centity_t* cent, int eventNum, unsigned short tagName, playerState_s* ps);

void Weapon_Throw_Grenade(WeaponParms* wp, gentity_s* ent, int grenType, int grenModel);

// Works need to check damage though
bool Bullet_Trace(BulletTraceResults* btr, WeaponDef* weapDef, BulletFireParams* bfp, gentity_s* attacker, int zero);

// Doesn't seem to do much. Kind of pointless anyways.
int GetBulletDamage(WeaponDef* weapDef, BulletFireParams* bfp, BulletTraceResults* btr);

// Returns total amount of player's weapon ammo
int BG_WeaponAmmo(int weaponId, playerState_s* ps);

// Gives player specified weapon by id
int G_GivePlayerWeapon(int weaponId, gclient_s* client, unsigned char altModelIndex);

// Gives player ammo for specified weapon
int Add_Ammo(gentity_s* gEnt, int weaponIndex, char weaponModel, int ammo, int fillClip);

// WARNING: centity_t* is not the one found in cEntitiesArray
// Get it at pCG->predictedPlayerEntity
int CG_EntityEvent(int clientNum, entityEvents_t event, centity_t* predictedPlayerEntity);

int CurrentPrimaryWeapon(playerState_s* ps);

// How to use weaponModel
// *game.players[1].playerState->weaponsOld[weap + 8]
gentity_s* Drop_Weapon(int weaponId, gentity_s* gEnt, char weaponModel, unsigned int tag);

// Doesn't work
int WeaponPickup_Grab(gentity_s* weapEnt, gentity_s* playerEnt, int weapId, int pickupEvent);

// Returns true is player is in a scoped weapon ADS
// (e.g. Sniper scope )
int IsScopedADS(playerState_s* ps);

// Returns false is weapon is fire, or using melee
int IsWeaponReady(playerState_s* ps);

// Removes takeAwayAmmo from player's gun clip
// Returns remaining clip ammo
int TakeAwayClipAmmo(int takeAwayAmmo, int weaponId, playerState_s* ps);

int IsClipEmpty(playerState_s* ps);

// Need more reversing
int UnknownFunc(int weaponId, playerState_s* ps, char a3);

bool IsPlayerFiring(WeaponDef* weapDef, playerState_s* ps);

int CG_FireWeaponEasy(playerState_s* ps, int reloadType);

void CG_FireMeleeEasy(playerState_s* ps);

void RaiseWeapon(playerState_s* ps);

void RaiseWeapon_2(playerState_s* ps);

// Seems kind of useless
void ReadyWeapon(playerState_s* ps);

void CG_ThrowGrenadeEasy(playerState_s* ps);

void Play_RaiseFromGrenadeThrow(playerState_s* ps);

bool IsMantling(gclient_s* client);

// Something to do with holding breath
void Unknown1(playerState_s* ps);

// Returns true if player is holding specified weapon
bool IsHoldingWeapon(int weapId, playerState_s* ps);

// Same as IsHoldingWeapon afaik
bool PlayerHasSpecificWeapon(int weapId, playerState_s* ps);

// Has something to do with footsteps?
float BG_GetBobCycle(playerState_s* ps);

// Returns CMD for modifying packets in CL_WritePacket
int GetUserCmd(int currentCmdNum, usercmd_s* cmd);

// Decrements player's reserve ammo, and fills clip
void FillClip(gclient_s* client, int weapId);