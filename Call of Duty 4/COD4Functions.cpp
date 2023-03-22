#include "COD4Functions.h"

_ClientDisconnect ClientDisconnect = (_ClientDisconnect)0x4A67C0;
_RegisterTag RegisterTag = (_RegisterTag)0x512DA0;
_CG_OutOfAmmoChange CG_OutOfAmmoChange = (_CG_OutOfAmmoChange)0x453E60;
_FireWeapon FireWeapon = (_FireWeapon)0x4E4BB0;
_FireWeaponMelee FireWeaponMelee = (_FireWeaponMelee)0x04E4DA0;
_TeleportPlayer TeleportPlayer = (_TeleportPlayer)0x4BC020;
_SetClientViewAngle SetClientViewAngle = (_SetClientViewAngle)0x4A5B00;
_BG_GetWeaponIndexForName BG_GetWeaponIndexForName = (_BG_GetWeaponIndexForName)0x0415370;
_BG_GetPlayerViewDirection BG_GetPlayerViewDirection = (_BG_GetPlayerViewDirection)0x55DAD0;
_BG_GetPlayerViewOrigin BG_GetPlayerViewOrigin = (_BG_GetPlayerViewOrigin)0x04A5E30;
_BulletGetDamage BulletGetDamage = (_BulletGetDamage)0x4A1E40;
_BG_AdvanceTrace BG_AdvanceTrace = (_BG_AdvanceTrace)0x414BF0;

// These functions are used in hooks
_Engine Engine = nullptr;
_CL_WritePacket CL_WritePacket = nullptr;
_ClientEndFrame ClientEndFrame = nullptr;

bool CG_OnSameTeam(gentity_s* gEnt, gentity_s* gEnt2) {
    int bSameTeam = 0;
    int fnOnSameTeam = 0x4DB990;
    __asm {
        mov ecx, gEnt2;
        mov eax, gEnt;
        call fnOnSameTeam;
        mov bSameTeam, eax;
    }
    return (bSameTeam == 1);
}

void G_GetPlayerViewOrigin(int* client, vec3_t* origin)
{
    int dwFunc = 0x4A5E30;
    __asm {
        mov eax, client;
        mov ecx, origin;
        call dwFunc;
    }
}

void GetViewDirection(int* client, vec3_t* forward, vec3_t* right, vec3_t* up)
{
    int dwFunc = 0x55DAD0;
    __asm {
        mov edx, client;
        mov eax, up
        push eax;
        add edx, 0x108;
        mov edi, forward;
        mov esi, right;
        call dwFunc;
    }
}

void GetWeaponSpread(playerState_s* ps, vec3_t* mins, vec3_t* maxs, WeaponDef* weapDef)
{
    int dwFunc = 0x415980;
    __asm {
        mov edx, ps;
        mov esi, mins;
        mov edi, maxs;
        mov ecx, weapDef;
        call dwFunc;
    }
}

void WeaponFireRecoil(playerState_s* ps, vec3_t* speed, vec3_t* kick)
{
    int dwFunc = 0x419410;
    __asm {
        push kick;
        mov edi, speed;
        mov eax, ps;
        call dwFunc;
        add esp, 4;
    }
}

void NameFromNum(int clientNum, char* dest)
{
    int dwFunc = 0x471550;
    __asm {
        mov esi, clientNum;
        mov ecx, dest;
        push ecx;
        call dwFunc;
        add esp, 4;
    }
}

int WeaponCheck(int weapId)
{
    int test = 0;
    int dwFunc = 0x416140;
    __asm {
        mov eax, weapId;
        call dwFunc;
        mov test, eax;
    }
    return test;
}

void WeaponStuff(playerState_s* ps, int clientNum)
{
    int dwFunc = 0x454510;
    __asm {
        push clientNum;
        mov eax, ps;
        call dwFunc;
        add esp, 4;
    }
}

void CG_CalcEyePoint(int clientNum, vec3_t* pos)
{
    int dwFunc = 0x454E60;
    __asm {
        mov edi, pos;
        mov eax, clientNum;
        call dwFunc;
    }
}

void FillWeaponParms(WeaponParms* weapParms, gentity_s* gEnt)
{
    int fnFunc = 0x4E1860;
    __asm {
        mov eax, weapParms;
        mov ecx, gEnt;
        call fnFunc;
    }
}

bool CreateProfile(const char* profileName)
{
    bool bSuccess = false;
    int dwFunc = 0x4F5B40;
    __asm {
        mov esi, profileName;
        call dwFunc;
        mov bSuccess, al;
    }
    return bSuccess;
}

void CalcMuzzlePointsASM(WeaponParms* weapParms, gentity_s* gEnt, WeaponDef* weapDef)
{
    int dwFunc = 0x4E4B50;
    __asm {
        push gEnt;
        mov eax, weapParms;
        call dwFunc;
        add esp, 4;
    }
}

void WeaponMelee(int time, WeaponParms* wp, gentity_s* gEnt, float range, float width, float height)
{
    int dwFunc = 0x4E4690;
    __asm {
        push height;
        push width;
        push range;
        mov ecx, wp;
        mov edi, gEnt;
        push ecx;
        mov ecx, time;
        call dwFunc;
        add esp, 0x10;
    }
}

void CG_FireWeapon(int localClientNum, centity_t* cent, int eventNum, unsigned short tagName, playerState_s* ps)
{
    int dwFunc = 0x454570;
    __asm {
        movzx edx, tagName;
        push ps;
        push edx;
        push eventNum;
        push cent;
        push localClientNum;
        call dwFunc;
        add esp, 0x14;
    }
}

void Weapon_Throw_Grenade(WeaponParms* wp, gentity_s* ent, int grenType, int grenModel)
{
    int dwFunc = 0x4E4790;
    __asm {
        push grenModel;
        push grenType;
        push ent;
        mov eax, wp;
        call dwFunc;
        add esp, 0xC;
    }
}

bool Bullet_Trace(BulletTraceResults* btr, WeaponDef* weapDef, BulletFireParams* bfp, gentity_s* attacker, int zero)
{
    bool bSuccess = false;
    int dwFunc = 0x4A2000;
    __asm {
        push zero;
        push attacker;
        push weapDef;
        mov eax, btr;
        mov ecx, bfp;
        call dwFunc;
        add esp, 0xC;
        mov bSuccess, al;
    }
    return bSuccess;
}

int GetBulletDamage(WeaponDef* weapDef, BulletFireParams* bfp, BulletTraceResults* btr)
{
    int damage = 0;
    int dwFunc = 0x4A1E40;
    __asm {
        mov esi, weapDef;
        mov edi, btr;
        mov edx, bfp;
        call dwFunc;
        mov damage, eax;
    }
    return damage;
}

int BG_WeaponAmmo(int weaponId, playerState_s* ps)
{
    int totalAmmo = 0;
    int dwFunc = 0x4161F0;
    __asm {
        mov eax, weaponId;
        mov ecx, ps;
        call dwFunc;
        mov totalAmmo, eax;
    }
}

int G_GivePlayerWeapon(int weaponId, gclient_s* client, unsigned char altModelIndex)
{
    int dwFunc = 0x4E4E40;
    __asm {
        mov eax, weaponId;
        mov ecx, client;
        push altModelIndex;
        call dwFunc;
        add esp, 4;
    }
    return 0;
}

int Add_Ammo(gentity_s* gEnt, int weaponIndex, char weaponModel, int ammo, int fillClip)
{
    int dwFunc = 0x4B6610;
    __asm {
        push fillClip;
        push ammo;
        push weaponModel;
        push weaponIndex;
        mov eax, gEnt;
        call dwFunc;
        add esp, 0x10;
    }
    return 0;
}

int CG_EntityEvent(int clientNum, entityEvents_t eventNum, centity_t* predictedPlayerEntity)
{
    int func = 0x434220;
    __asm {
        movzx ebx, eventNum;
        mov ecx, clientNum;
        mov eax, ebx;
        push predictedPlayerEntity;
        call func;
        add esp, 4;
    }
    return 0;
}

int CurrentPrimaryWeapon(playerState_s* ps)
{
    int func = 0x4B67B0;
    int result = 0;
    __asm {
        mov esi, ps;
        call func;
        mov result, eax;
    }
    return result;
}

gentity_s* Drop_Weapon(int weaponId, gentity_s* gEnt, char weaponModel, unsigned int tag)
{
    gentity_s* result = 0;
    int func = 0x4B7AC0;
    __asm {
        mov eax, weaponId;
        movzx ecx, tag;
        push tag;
        push ecx;
        push gEnt;
        call func;
        mov result, eax;
        add esp, 0xC;
    }
    return result;
}

int WeaponPickup_Grab(gentity_s* weapEnt, gentity_s* playerEnt, int weapId, int pickupEvent)
{
    int func = 0x4B6D70;
    __asm {
        mov ecx, weapEnt;
        mov eax, playerEnt;
        push weapId;
        push pickupEvent;
        call func;
        add esp, 8;
    }
    return 0;
}

void GetPlayerNameByClientNum(int clientNum) {
    int fnGetPlayerNameByClientNum = 0x471550;
    char name[40];
    __asm {
        mov esi, clientNum;
        lea edx, name;
        push edx;
        call fnGetPlayerNameByClientNum;
        add esp, 4;
    }
}

bool IsTargetValid(centity_t* cEnt) {
    int fnIsTargetValid = 0x403360;
    int cg_s = 0x746338;
    bool bValid = false;

    __asm {
        mov eax, cEnt;
        mov ecx, cg_s;
        call fnIsTargetValid;
        mov bValid, al;
    }
    return bValid;
}

bool IsTargetVisible(unsigned short tag, centity_t* cEnt) {
    bool bVisible = false;
    int fnIsTargetVisible = 0x403470;
    __asm {
        movzx esi, tag
        mov edi, cEnt
        push edi
        mov eax, esi
        call fnIsTargetVisible
        add esp, 4
        mov bVisible, al
    }
    return bVisible;
}

void AimTarget_GetTagPos(unsigned short tagName, centity_t* entity, vec3_t* origin)
{
    int fnGetTagPos = 0x403180;

    __asm {
        push origin
        movzx esi, tagName
        mov ecx, entity
        movzx eax, byte ptr[ecx + 4]
        mov edi, fnGetTagPos
        call edi
        add esp, 0x4
    }
}

void __cdecl CG_Trace(trace_t* pTrace, const vec3_t startPos, const vec3_t endPos, vec3_t min, vec3_t max, int skipNum, int traceFlags)
{
    int fnCGTrace = 0x0456800;

    _asm
    {
        push 0
        push 0
        push traceFlags
        push skipNum
        push endPos
        push max
        push startPos
        mov edi, pTrace
        mov eax, min
        call[fnCGTrace]
        add esp, 0x1C
    }
}

int IsScopedADS(playerState_s* ps)
{
    int result = false;
    int func = 0x416140;
    __asm {
        mov eax, ps;
        call func;
        mov result, eax;
    }
    return result;
}

int IsWeaponReady(playerState_s* ps)
{
    int result = 0;
    int func = 0x416170;
    __asm {
        mov eax, ps;
        call func;
        mov result, eax;
    }
    return result;
}

int TakeAwayClipAmmo(int takeAwayAmmo, int weaponId, playerState_s* ps)
{
    int result = 0;
    int func = 0x416310;
    __asm {
        mov edx, takeAwayAmmo;
        mov ecx, weaponId;
        mov esi, ps;
        call func;
        mov result, eax;
    }
    return result;
}

int IsClipEmpty(playerState_s* ps)
{
    int result = 0;
    int func = 0x416340;
    __asm {
        mov eax, ps;
        call func;
        mov result, eax;
    }
    return result;
}

int UnknownFunc(int weaponId, playerState_s* ps, char a3)
{
    int result = 0;
    int func = 0x416840;
    __asm {
        mov edx, weaponId;
        mov esi, ps;
        push a3;
        call func;
        add esp, 4;
        mov result, eax;
    }
    return result;
}

bool IsPlayerFiring(WeaponDef* weapDef, playerState_s* ps)
{
    bool result = false;
    int func = 0x4178B0;
    __asm {
        mov eax, weapDef;
        mov ecx, ps;
        call func;
        mov result, al;
    }
    return result;
}

int CG_FireWeaponEasy(playerState_s* ps, int reloadType)
{
    int result = 0;
    int func = 0x418270;
    __asm {
        push reloadType;
        mov eax, ps;
        call func;
        add esp, 4;
    }

    return result;
}

void CG_FireMeleeEasy(playerState_s* ps)
{
    int func = 0x418470;
    __asm {
        mov esi, ps;
        call func;
    }
}

void RaiseWeapon(playerState_s* ps)
{
    int func = 0x418380;
    __asm {
        mov eax, ps;
        call func;
    }
}

void RaiseWeapon_2(playerState_s* ps)
{
    int func = 0x418410;
    __asm {
        mov eax, ps;
        call func;
    }
}

void ReadyWeapon(playerState_s* ps)
{
    int func = 0x418690;
    __asm {
        mov eax, ps;
        call func;
    }
}

void CG_ThrowGrenadeEasy(playerState_s* ps)
{
    int func = 0x418770;
    __asm {
        mov eax, ps;
        call func;
    }
}

void Play_RaiseFromGrenadeThrow(playerState_s* ps)
{
    int func = 0x418A50;
    __asm {
        mov eax, ps;
        call func;
    }
}

bool IsMantling(gclient_s* client)
{
    bool result = false;
    int func = 0x408F20;
    __asm {
        mov eax, client;
        call func;
        mov result, al;
    }
    return result;
}

void Unknown1(playerState_s* ps)
{
    int func = 0x415ED0;
    __asm {
        mov esi, ps;
        call func;
    }
}

bool IsHoldingWeapon(int weapId, playerState_s* ps)
{
    bool result = false;
    int func = 0x415510;
    __asm {
        push ps;
        mov eax, weapId;
        call func;
        add esp, 4;
        mov result, al;
    }
    return result;
}

bool PlayerHasSpecificWeapon(int weapId, playerState_s* ps)
{
    bool result = false;
    int func = 0x409040;
    __asm {
        push ps;
        mov edx, weapId;
        call func;
        add esp, 4;
        mov result, al;
    }
    return result;
}

float BG_GetBobCycle(playerState_s* ps)
{
    float result = 0.f;
    int func = 0x419670;
    __asm {
        mov eax, ps;
        call func;
        fstp result;
    }
    return result;
}

int GetUserCmd(int currentCmdNum, usercmd_s* cmd)
{
    int func = 0x4573f0;
    __asm {
        mov eax, currentCmdNum;
        mov ecx, cmd;
        push ecx;
        call func;
        add esp, 4;
    }
    return 0;
}

void FillClip(gclient_s* client, int weapId)
{
    int func = 0x4B65B0;
    __asm {
        mov ecx, weapId;
        mov edx, client;
        call func;
    }
}

//void CL_WritePacket()
//{
//    int func = 0x460270;
//    __asm {
//        call func;
//    }
//}
