#pragma once
#include <Windows.h>
#include "Structs.h"
#include "COD4Structs.h"

// gentity_s array
extern int pGEntities;

// centity_t array
extern int pCEntities;

// clSnapshot_t
extern int pCLSnapshot;

// Base address for the Dynamic Entity List
extern int pDynamicEntBase;

// Table of all WeaponInfo
extern int pWeaponInfoBase;

// Dynamic Entity List Address ( Holds entities such as; C4, Vehicles, Weapons, Dead Bodies, etc.)
extern DynamicEntityList* pDynamicEntList;

// Holds all camera information
extern RefDef* pRefDef;

// Holds the players view angles
extern ViewAngles* pViewAngles;

// Holds game information (e.g. Number of clients)
//extern clSnapshot_t* pCLSnapshot;

// Holds local client info
extern playerState_s* pPlayerState;

extern CGs_t* pCGs;

extern CG_s* pCG;

typedef void(__cdecl *CGTrace)(CTrace* pTrace, vec3_t StartPos, vec3_t EndPos, vec3_t Min, vec3_t Max, int skipNum, DWORD dwTraceFlags);
extern CGTrace fnCGTrace;

typedef int(__fastcall* SendServerCommand)(int clientId, const char* cmd);
extern SendServerCommand fnSendServerCommand;

typedef void(__cdecl* CMD_AddCommand)(int num, const char* command);
extern CMD_AddCommand fnCMDAddCommand;

typedef void(__cdecl* SendCommandToConsole)(int numOne, int numTwo, const char* command);
extern SendCommandToConsole fnSendCommandToConsole;

typedef void(__cdecl* _G_GetPlayerViewOrigin)(int* pPlayerState, float* vViewOrigin);
extern _G_GetPlayerViewOrigin GetPlayerViewOrigin;

typedef int(__cdecl* CL_InitMapLoad_FastFile)(const char* mapName);
extern CL_InitMapLoad_FastFile fnCL_InitMapLoad_FastFile;

typedef void(__cdecl* _CL_DisconnectLocalClient)(int value);
extern _CL_DisconnectLocalClient CL_DisconnectLocalClient;

typedef int(__cdecl* _Com_PrintWarning)(int type, const char* msg, char ArgList);
extern _Com_PrintWarning Com_PrintWarning;

typedef float(__cdecl* GetDistance)(vec3_t src, vec3_t dst);
extern GetDistance fnGetDistance;

typedef void(__cdecl* _CG_SelectWeaponIndex)(int localClientNum, unsigned int weaponIndex);
extern _CG_SelectWeaponIndex CG_SelectWeaponIndex;

// Int* should be replaced with gentity_s*
typedef int* (__cdecl* _Scr_GetEntity)(unsigned int index);
extern _Scr_GetEntity Scr_GetEntity;

// Not working for some reason.
typedef int(__cdecl* _OnSameTeam)(int* gEnt, int* gEnt2);
extern _OnSameTeam OnSameTeam;

typedef void(__cdecl* _GetTagPos)(int localClientNum, int* cEnt, unsigned int tagName, float* pos);
extern _GetTagPos GetTagPos;

typedef BOOL(__cdecl* _AimTarget_IsTargetVisible)(int* cEnt, unsigned int bone);
extern _AimTarget_IsTargetVisible AimTarget_IsTargetVisible;

typedef int(__cdecl* _CG_DObjGetWorldTagPos)(int tag, void* obj, void* ent, float* pos);
extern _CG_DObjGetWorldTagPos CG_DObjGetWorldTagPos;

typedef int(__cdecl* _SV_GetUserCmd)(int clientNum);
extern _SV_GetUserCmd SV_GetUserCmd;

typedef void(__cdecl* _GetNameFromClientNum)(int clientNum, char* outClientName);
extern _GetNameFromClientNum GetNameFromClientNum;

// Kind of useless...
// Just returns the player's real rank
// Rankindex + 1
typedef const char* (__cdecl* _CG_GetRank)(int rankIndex);
extern _CG_GetRank CG_GetRank;

// 0x533730
// Parameter 'errorType' should be an enum of msgLocErrType_t 
typedef const char* (__cdecl* SEH_LocalizeTextMessage)(const char* pszInputBuffer, const char* pszMessageType, int errorType);

//Weapon_Melee_internal_4E4510
//gentity_s *__cdecl Weapon_Melee_internal(gentity_s *ent, weaponParms *wp, double range, double width, double height)

//CG_ReadNextSnapshot_44B140
//snapshot_s* __cdecl ( no args )