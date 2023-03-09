#include "COD4Functions.h"

_ClientDisconnect ClientDisconnect = (_ClientDisconnect)0x4A67C0;
_RegisterTag RegisterTag = (_RegisterTag)0x512DA0;
_CG_OutOfAmmoChange CG_OutOfAmmoChange = (_CG_OutOfAmmoChange)0x453E60;
_FireWeapon FireWeapon = (_FireWeapon)0x4E4BB0;
_FireWeaponMelee FireWeaponMelee = (_FireWeaponMelee)0x04E4DA0;
_TeleportPlayer TeleportPlayer = (_TeleportPlayer)0x4BC020;
_SetClientViewAngle SetClientViewAngle = (_SetClientViewAngle)0x4A5B00;
_BG_GetWeaponIndexForName BG_GetWeaponIndexForName = (_BG_GetWeaponIndexForName)0x0415370;

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
        mov edi, 0x08474B4
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