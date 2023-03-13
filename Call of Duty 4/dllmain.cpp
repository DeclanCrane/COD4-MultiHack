// dllmain.cpp : Defines the entry point for the DLL application.
#include <iostream>
#include <Windows.h>
#include "Console.h"
#include "Offsets.h"
#include "Entity.h"
#include "EndScene.h"
#include "Drawing.h"
#include "COD4Structs.h"
#include "Aimbot.h"
#include "Entity.h"
#include "Game.h"
#include "COD4Constants.h"
#include "COD4Functions.h"
#include "Hack.h"
#include "Vec.h"
#include "Wall.h"

#include <iomanip>

//clientActive_t* clientActive = (clientActive_t*)0xC57930;
dvar_s* svCheats = (dvar_s*)0xCBA3808;

// RenderScene
typedef void(__cdecl* tRenderScene)(RefDef* rd);
tRenderScene oRenderScene;

typedef void(__cdecl* _ClientEndFrame)(int unknown);
_ClientEndFrame ClientEndFrame;

void __cdecl newClientEndFrame(int unknown) {
    if (GetAsyncKeyState(VK_NUMPAD1) & 0x01) {
        /*headBone = RegisterTag("j_head", 1, 7);*/
        //if (AimTarget_IsTargetVisible(headBone, (int*)(0x08474B4))) {
        //    std::cout << "Visible\n";
        //}
        //else {
        //    std::cout << "Invisible\n";
        //}
        //vec3_t bonePos = {};
        //GetTagPos_0(headBone, (int*)(0x08474B4), &bonePos);
        //std::cout << "X: " << bonePos.x << std::endl;
    }
    ClientEndFrame(unknown);
}

void __cdecl myRenderScene() {
    int a = 1;
    a += 1;
}

void __cdecl newrenderscene(RefDef* rd)
{
    _asm pushad;
    myRenderScene();
    _asm popad;
    oRenderScene(rd);
}

void __cdecl hCG_FastTrace(CTrace* pTrace, const vec3_t StartPos, const vec3_t EndPos, vec3_t Min, vec3_t Max, int iSkipNum, DWORD dwTraceFlags)
{
    DWORD dwTraceAddress = 0x0456800;

    _asm
    {
        PUSH 0;
        PUSH 0;
        PUSH dwTraceFlags;
        PUSH iSkipNum;
        PUSH EndPos;
        PUSH Max;
        PUSH StartPos;
        MOV EDI, pTrace;
        MOV EAX, Min;
        CALL[dwTraceAddress];
        ADD ESP, 0x1C;
    }
}

void FillClip(int* playerState, int weapon) {
    DWORD dwFunc = 0x4B65B0;
    __asm {
        mov edx, playerState;
        mov ecx, weapon;
        call dwFunc;
    }
}

bool TraceIsVisible(vec3_t v3EndPos, float nHeight)
{
    CTrace mTrace;
    v3EndPos.z += nHeight;
    vec3_t v3Zero = { 0.0f, 0.0f, 0.0f };
    hCG_FastTrace(&mTrace, pRefDef->vCameraPos, v3EndPos, v3Zero, v3Zero, 0, 0x2803001);
    return(mTrace.Fraction == 1.0f);
}

//void WallDynEntity(DynamicEntity* pEntity, RefDef* refdef)
//{
//
//        vec2_t enemyScreenPos;
//        vec2_t enemyHead2D;
//
//        if (Drawing.WorldToScreen(pEntity->vOrigin, enemyScreenPos, refdef)) {
//
//            // Line ESP
//            if (true)
//            {
//                Drawing.DrawLine(enemyScreenPos.x, enemyScreenPos.y, refdef->width / 2, refdef->height, 1,
//                    D3DCOLOR_ARGB(255, int(0 * 255), int(1 * 255), int(0 * 255)));
//            }
//
//            // Top of box
//            vec3_t vHeadOrigin;
//            vHeadOrigin.x = pEntity->vOrigin.x;
//            vHeadOrigin.y = pEntity->vOrigin.y;
//            vHeadOrigin.z = pEntity->vOrigin.z + 15.f; // Height of Zombie / Bot
//
//            if (Drawing.WorldToScreen(vHeadOrigin, enemyHead2D, refdef)) {
//                Drawing.DrawEspBox2D(enemyScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(1 * 255), int(0 * 255), int(0 * 255)));
//            }
//        }
//}

D3D9Hook Hook;
std::vector<Entity*> Entities = {};
std::vector<DynamicEntity*> DynEntities = {};

HWND hWindow = FindWindowA(0, "Call of Duty 4");
// Make sure D3D9 device is only passed once
static bool bGotDraw = false;

// EndScene Detour
HRESULT __stdcall myDetour(IDirect3DDevice9* pDevice)
{
    // Pass the pDevice pointer to Drawing for drawing on screen
    if (!bGotDraw) {
        Drawing.pDevice = pDevice;
        bGotDraw = true;
    }

    for (int i = 1; i < game.players.size(); i++) { // Set i to 1, skips our own player
        ESP(game.players[i]);
    }

    //GetDynamicEntities(DynEntities);
    //for (int i = 0; i < DynEntities.size(); i++) {
    //    Wall(DynEntities[i], pRefDef);
    //}

    if (GetAsyncKeyState('X') & 0x01) {
        int bestTarget = GetBestTarget();
        if (bestTarget > 0) // If there's a valid target
            DoAimbot(bestTarget);
        Sleep(1); // Prevents jitter?
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x01) {
        //headBone = fnRegisterTag("j_head", 1, 7);
        //if (IsTargetVisible(headBone, (int*)(0x08474B4))) {
        //    std::cout << "Visible\n";
        //}
        //else {
        //    std::cout << "Not Visible\n";
        //}
        //if (IsTargetValid((int*)(0x08474B4))) {
        //    std::cout << "Valid\n";
        //}
        //else {
        //    std::cout << "Invalid\n";
        //}

        //GetPlayerNameByClientNum();

        //const char* rankName = CG_GetRank(47);
        //std::cout << rankName << "\n";

        //if (CG_OnSameTeam((int*)0x1280500, (int*)0x1280774)) {
        //    std::cout << "Same team!\n";
        //}
        //else {
        //    std::cout << "Enemy!\n";
        //}

        //std::cout << "MaxClients: " << pCGs->maxClients;
        /*std::cout << "Team: " << ((gentity_s*)0x1280500)->client->clientSession.clientState.team_t;*/
        //gentity_s* pLocal = (gentity_s*)0x1280774;
        //vec3_t newAngles = { (pLocal->client->viewAngles[0] + 28.f), (pLocal->client->viewAngles[1] + 28.f), 0.f};
        //SetClientViewAngle((int*)0x1280774, newAngles);

        //for (int i = 0; i < 1; i++) {
        //    Player tempPlayer(i);
        //    players.push_back(tempPlayer);
        //}

        //std::cout << players[0].GetWeaponID() << "\n";
        //WeaponDef* weapon = players[0].GetWeaponDef();
        //weapon->fireType = WEAPON_FIRETYPE_FULLAUTO;
        //std::cout << players[0].GetTeam() << "\n";
        //std::cout << players[0].IsOnLadder() << "\n";

        if (CG_OnSameTeam((gentity_s*)0x1280500, (gentity_s*)0x1280774)) {
            std::cout << "Friendly!\n";
        }
        else {
            std::cout << "Enemy!\n";
        }

        unsigned short head = RegisterTag("j_head", 1, 7);
        if (IsTargetVisible(head, (centity_t*)0x08474B4)) {
            std::cout << "Visible!\n";
        }
        else {
            std::cout << "Invisible!\n";
        }

        FireWeapon((gentity_s*)0x1280500, game.GetServerTime());
    }

    if (GetAsyncKeyState(VK_F1) & 0x01) {
        std::cout << "Weapon: " << pPlayerState->weapon << "\n";
        WeaponDef* currentWeapon = nullptr;
        GetPlayerWeaponDef(pPlayerState->weapon, currentWeapon);
        if (currentWeapon) {
            std::cout << currentWeapon->fireType << "\n";
            // Damage and Penetration
            currentWeapon->penetrateType = PENETRATE_TYPE_LARGE;
            currentWeapon->impactType = IMPACT_TYPE_BULLET_AP;
            currentWeapon->fireType = WEAPON_FIRETYPE_FULLAUTO;
            currentWeapon->bRifleBullet = 1;
            currentWeapon->armorPiercing = 1;
            currentWeapon->damage = 1000;
            currentWeapon->playerDamage = 300;
            currentWeapon->iFireTime = 50;

            // Spread and Recoil
            // ADS View Kick
            currentWeapon->fAdsViewKickPitchMin = 0.f;
            currentWeapon->fAdsViewKickPitchMax = 0.f;
            currentWeapon->fAdsViewKickYawMin = 0.f;
            currentWeapon->fAdsViewKickYawMax = 0.f;
            // ADS Gun Kick
            currentWeapon->fAdsGunKickPitchMin = 0.f;
            currentWeapon->fAdsGunKickPitchMax = 0.f;
            currentWeapon->fAdsGunKickYawMin = 0.f;
            currentWeapon->fAdsGunKickYawMax = 0.f;

            // Hip View Kick
            currentWeapon->fHipViewKickPitchMin = 0.f;
            currentWeapon->fHipViewKickPitchMax = 0.f;
            currentWeapon->fHipViewKickYawMin = 0.f;
            currentWeapon->fHipViewKickYawMax = 0.f;
        }

        svCheats->current.integer = 1;

    }

    if (GetAsyncKeyState(VK_NUMPAD2) & 0x01) {
        //WeaponDef* weapDef = game.players[0].GetWeaponDef();
        //WeaponParms parms;
        //vec3_t zero;
        //parms.forward = zero;
        //parms.right = zero;
        //parms.up = zero;
        //parms.muzzleTrace = zero;
        //parms.gunForward = zero;
        //parms.weaponDef = weapDef;
        //Weapon_Melee((gentity_s*)0x1280500, &parms, 2000.f, 2000.f, 2000.f, game.GetServerTime() + 1);

        vec3_t forward;
        vec3_t mins;
        vec3_t maxs;
        //G_GetPlayerViewOrigin((int*)0x131D5A8, &forward);
        //WeaponDef* def = game.players[0].GetWeaponDef();
        //char* name = nullptr;
        //NameFromNum(0, name);
        //std::cout << "Name: " << name << "\n";
        //std::cout << "X: " << maxs.x << " " << "Y: " << maxs.y << " " << "Z: " << maxs.z << "\n";

        //CG_CalcEyePoint(0, &mins);
        //std::cout << "X: " << mins.x << " " << "Y: " << mins.y << " " << "Z: " << mins.z << "\n";
        // 
        //const char* name = "HelloWorld";
        //CreateProfile(name);

        WeaponParms weapParms = {};

        weapParms.weaponDef = game.players[0].GetWeaponDef();
        CalcMuzzlePointsASM(&weapParms, game.players[0].gEntity, game.players[0].GetWeaponDef());
        std::cout << "X: " << weapParms.forward.x << " " << "Y: " << weapParms.forward.y << " " << "Z: " << weapParms.forward.z << "\n";
        //WeaponMelee(game.GetServerTime() + 1, &weapParms, game.players[0].gEntity, 5000.f, 5000.f, 5000.f);
        //CG_FireWeapon(0, game.players[0].cEntity, 0x1A, (unsigned short)0x13FEF22, pPlayerState);
        //CG_FireWeapon(0, game.players[0].cEntity, 0x1A, (unsigned short)0x2F0, pPlayerState);
        /*Weapon_Throw_Grenade(&weapParms, game.players[0].gEntity, game.players[0].gEntity->entityState.weapon, game.players[0].gEntity->entityState.weaponModel);*/

        vec3_t vZero(0.f, 0.f, 0.f);
        BulletFireParams bulletParams = {};
        bulletParams.dir = weapParms.muzzleTrace;
        bulletParams.origStart = vZero;
        bulletParams.start = pRefDef->vCameraPos;
        bulletParams.end = *game.players[1].vOrigin;
        bulletParams.damageMultiplier = 1.f;
        bulletParams.weaponEntIndex = game.players[0].GetWeaponID();
        bulletParams.ignoreEntindex = 0;
        BulletTraceResults btr = {};

        if (Bullet_Trace(&btr, game.players[0].GetWeaponDef(), &bulletParams, game.players[0].gEntity, 0)) {
            std::cout << "Result: " << btr.trace.Fraction << "\n";
            std::cout << "Hit Type: " << btr.trace.hitType << "\n";
        }

        int damage = GetBulletDamage(&btr, game.players[0].GetWeaponDef(), game.players[0].gEntity);
        std::cout << "Damage: " << damage << "\n";
    }

    // Call original endScene after detour
    return Hook.pEndScene(pDevice);
}

// Reset Detour
HRESULT __stdcall myResetDetour(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return Hook.pReset(pDevice, pPresentationParameters);
}

int MainThread(PVOID pModule) {
    Console console;
    console.CreateConsole();
    std::cout << "Running\n";

    // Setup EndScene Hook
    Hook.HookEndScene(hWindow, myDetour, myResetDetour);

    // Hook RenderScene
    //0x5DAB10 - RENDERSCENE
    //0x42C120 - OTHER GAME FUNCTION
    //oRenderScene = (tRenderScene)DetourFunction((PBYTE)0x5DAB10, (PBYTE)&newrenderscene);
    //if (!oRenderScene)
    //    return -1;

    /*ClientEndFrame = (_ClientEndFrame)DetourFunction((PBYTE)0x4A4D90, (PBYTE)&newClientEndFrame);*/

    // Hack loop
    while (true) {
        if (GetAsyncKeyState(VK_END) & 0x01) {
            std::cout << "Exiting...\n";
            break;
        }
        // [ INFINITE AMMO ]
        // Get our weapon id
        //int weaponId = *(int*)(0x78C474 + 0xE8);
        //if (weaponId) {
        //    // Gets weapon struct?
        //    int* pWeaponStructID = (int*)(0x78C474 + 0xEC);
        //    // Get the clip ammo for our weapon
        //    int* pClipAmmo = (int*)(0x131D5A8 + (weaponId * 4) + 0x35C);

        //    *pClipAmmo = 69;
        //}

        Hack();
    }

    // Release Engine Hooks
    //DetourRemove((PBYTE)&ClientEndFrame, (PBYTE)&newClientEndFrame);
    //Sleep(100);

    // Clean up and exit
    console.CloseConsole();
    FreeLibraryAndExitThread((HMODULE)pModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, (PVOID)hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

