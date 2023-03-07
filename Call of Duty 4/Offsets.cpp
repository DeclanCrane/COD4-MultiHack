#include "Offsets.h"
#include "COD4Structs.h"

// Pointers
int numOfEntities = *(int*)0x13e36b4;
int numClients = *(int*)0xC5A8BC;

// Base Addresses
int pGEntities = 0x1280500;
int cEntitiesArray = 0x8472D8;
int pDynamicEntBase = 0x7492D0;
int pWeaponInfoBase = 0x72EDB8;

// Structures
DynamicEntityList* pDynamicEntList = (DynamicEntityList*)0x7492D0;
RefDef* pRefDef = (RefDef*)0x78F600;
ViewAngles* pViewAngles = (ViewAngles*)0xC7CFD8;
//clSnapshot_t* pCLSnapshot = (clSnapshot_t*)0x0C57938;
playerState_s* pPlayerState = (playerState_s*)0x078C474;
CGs_t* pCGs = (CGs_t*)0x0742908;
CG_s* pCG = (CG_s*)0x0746338;

// Functions
_BG_GetWeaponIndexForName BG_GetWeaponIndexForName = (_BG_GetWeaponIndexForName)0x0415370;

SendServerCommand fnSendServerCommand = (SendServerCommand)0x056c230;
CMD_AddCommand fnCMDAddCommand = (CMD_AddCommand)0x4F7740;
SendCommandToConsole fnSendCommandToConsole = (SendCommandToConsole)0x04f4660;

_G_GetPlayerViewOrigin G_GetPlayerViewOrigin = (_G_GetPlayerViewOrigin)0x04A5E30;

CL_InitMapLoad_FastFile fnCL_InitMapLoad_FastFile = (CL_InitMapLoad_FastFile)0x458750;
_CL_DisconnectLocalClient CL_DisconnectLocalClient = (_CL_DisconnectLocalClient)0x0466420;

_Com_PrintWarning Com_PrintWarning = (_Com_PrintWarning)0x4F78C0;

RegisterTag fnRegisterTag = (RegisterTag)0x512DA0;

_CG_OutOfAmmoChange CG_OutOfAmmoChange = (_CG_OutOfAmmoChange)0x453E60;
_CG_SelectWeaponIndex CG_SelectWeaponIndex = (_CG_SelectWeaponIndex)0x455820;
_CG_DObjGetWorldTagPos CG_DObjGetWorldTagPos = (_CG_DObjGetWorldTagPos)0x432740;
_CG_GetRank CG_GetRank = (_CG_GetRank)0x4700A0;

_Scr_GetEntity Scr_GetEntity = (_Scr_GetEntity)0x4DADD0;

_FireWeapon FireWeapon = (_FireWeapon)0x4E4BB0;
_FireWeaponMelee FireWeaponMelee = (_FireWeaponMelee)0x04E4DA0;
_GetTagPos GetTagPos = (_GetTagPos)0x403180;
_AimTarget_IsTargetVisible AimTarget_IsTargetVisible = (_AimTarget_IsTargetVisible)0x403470;

// Needs more reversing
_SV_GetUserCmd SV_GetUserCmd = (_SV_GetUserCmd)0x513450;

_TeleportPlayer TeleportPlayer = (_TeleportPlayer)0x4BC020;

_SetPlayerViewAngles SetPlayerViewAngles = (_SetPlayerViewAngles)0x4A5B00;

_OnSameTeam OnSameTeam = (_OnSameTeam)0x4DB990;
_GetNameFromClientNum GetNameFromClientNum = (_GetNameFromClientNum)0x471550;
_SetClientViewAngle SetClientViewAngle = (_SetClientViewAngle)0x4A5B00;