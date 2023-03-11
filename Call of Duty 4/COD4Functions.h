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

typedef void(__cdecl* _TeleportPlayer)(gentity_s* gEnt, vec3_t origin, vec3_t angles);
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