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

//cgs_t* pCGs = (cgs_t*)0x0742908;
//clientActive_t* clientActive = (clientActive_t*)0xC57930;
dvar_s* svCheats = (dvar_s*)0xCBA3808;

// RenderScene
typedef void(__cdecl* tRenderScene)(RefDef* rd);
tRenderScene oRenderScene;

typedef void(__cdecl* _ClientEndFrame)(int unknown);
_ClientEndFrame ClientEndFrame;

bool IsTargetVisible(unsigned short tag, int* cEnt) {
    bool bVisible = false;
    DWORD dwFunc = 0x403470;
    __asm {
        movzx esi, tag;
        mov edi, 0x08474B4;
        push edi;
        mov eax, esi;
        call dwFunc;
        add esp, 4;
        mov bVisible, al;
    }
    return bVisible;
}

bool IsTargetValid(int* cEnt) {
    DWORD dwFunc = 0x403360;
    DWORD cg_s = 0x746338;
    bool bValid = false;

    __asm {
        mov eax, cEnt;
        mov ecx, cg_s;
        call dwFunc;
        mov bValid, al;
    }
    return bValid;
}

// Unfinished, doesn't return string
// Works though
void GetPlayerNameByClientNum() {
    char name[40];
    DWORD dwFunc = 0x471550;
    __asm {
        mov esi, 0;
        lea edx, name;
        push edx;
        call dwFunc;
        add esp, 4;
    }
    std::cout << name << std::endl;
}

int GetTagPos_0(unsigned short TagName, int* Entity, vec3_t* Origin)
{
    _asm push Origin
    _asm movzx esi, TagName
    _asm mov ecx, Entity
    _asm movzx eax, byte ptr[ecx + 4]
        _asm mov edi, 0x403180
    _asm call edi
    _asm add esp, 0x4
}

// Head Bone
WORD headBone = 0;
void __cdecl newClientEndFrame(int unknown) {
    if (GetAsyncKeyState(VK_NUMPAD1) & 0x01) {
        headBone = fnRegisterTag("j_head", 1, 7);
        //if (AimTarget_IsTargetVisible(headBone, (int*)(0x08474B4))) {
        //    std::cout << "Visible\n";
        //}
        //else {
        //    std::cout << "Invisible\n";
        //}
        vec3_t bonePos = {};
        GetTagPos_0(headBone, (int*)(0x08474B4), &bonePos);
        std::cout << "X: " << bonePos[0] << std::endl;
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

bool CG_OnSameTeam(int* gEnt, int* gEnt2) {
    int bSameTeam = 0;
    DWORD dwFunc = 0x4DB990;
    __asm {
        mov ecx, gEnt2;
        mov eax, gEnt;
        call dwFunc;
        mov bSameTeam, eax;
    }
    return (bSameTeam == 1);
}

void FillClip(int* playerState, int weapon) {
    DWORD dwFunc = 0x4B65B0;
    __asm {
        mov edx, playerState;
        mov ecx, weapon;
        call dwFunc;
    }
}

bool IsVisible(vec3_t v3EndPos, float nHeight)
{
    CTrace mTrace;
    v3EndPos[2] += nHeight;
    vec3_t v3Zero = { 0.0f, 0.0f, 0.0f };
    hCG_FastTrace(&mTrace, pRefDef->vCameraPos, v3EndPos, v3Zero, v3Zero, 0, 0x2803001);
    return(mTrace.Fraction == 1.0f);
}

void Wall(Entity* pEntity, RefDef* refdef)
{
    if (!IsVisible(pEntity->CameraPos, 0.f))
        return;

    if (pEntity->bAlive) { // If enemy is alive

        vec2_t enemyScreenPos = { 0.f };
        vec2_t enemyHead2D = { 0.f };

        if (Drawing.WorldToScreen(pEntity->vOrigin, enemyScreenPos, refdef)) {
            // Top of box
            vec3_t vHeadOrigin = { 0.f };
            vHeadOrigin[0] = pEntity->vOrigin[0];
            vHeadOrigin[1] = pEntity->vOrigin[1];
            vHeadOrigin[2] = pEntity->vOrigin[2] + 65.f; // Height of Zombie / Bot

            if (Drawing.WorldToScreen(vHeadOrigin, enemyHead2D, refdef)) {
                    Drawing.DrawEspBox2D(enemyScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(1 * 255), int(0 * 255), int(0 * 255)));
            }
        }
    }
}

void Wall(DynamicEntity* pEntity, RefDef* refdef)
{

        vec2_t enemyScreenPos = { 0.f };
        vec2_t enemyHead2D = { 0.f };

        if (Drawing.WorldToScreen(pEntity->vOrigin, enemyScreenPos, refdef)) {

            // Line ESP
            if (true)
            {
                Drawing.DrawLine(enemyScreenPos[0], enemyScreenPos[1], refdef->width / 2, refdef->height, 1,
                    D3DCOLOR_ARGB(255, int(0 * 255), int(1 * 255), int(0 * 255)));
            }

            // Top of box
            vec3_t vHeadOrigin = { 0.f };
            vHeadOrigin[0] = pEntity->vOrigin[0];
            vHeadOrigin[1] = pEntity->vOrigin[1];
            vHeadOrigin[2] = pEntity->vOrigin[2] + 15.f; // Height of Zombie / Bot

            if (Drawing.WorldToScreen(vHeadOrigin, enemyHead2D, refdef)) {
                Drawing.DrawEspBox2D(enemyScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(1 * 255), int(0 * 255), int(0 * 255)));
            }
        }
}

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
    GetPlayers(Entities);
    for (int i = 1; i < Entities.size(); i++) { // Set i to 1, skips our own player
        Wall(Entities[i], pRefDef);
    }

    GetDynamicEntities(DynEntities);
    for (int i = 0; i < DynEntities.size(); i++) {
        Wall(DynEntities[i], pRefDef);
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x01) {
        bool bCheckForVisible = false;
        if (Entities[1] != nullptr) {
            if (IsVisible(Entities[1]->CameraPos, 0.f) || !bCheckForVisible) {
                DoAimbot(Entities[1]);
            }
        }
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
        
        gentity_s* pLocal = (gentity_s*)0x1280500;

        //CG_OutOfAmmoChange(0); // Changes players' weapons
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x01) {
        //FireWeaponMelee((int*)0x1280500, (pCLSnapshot->serverTime + 1));
        //FireWeapon((int*)0x1280500, (pCLSnapshot->serverTime + 1));

        // NOT WORKING
        //vec3_t bonePos = {};
        //void* magic = 0;
        //headBone = fnRegisterTag("j_head", 1, 7);
        //int clientNum = *(int*)(0x08474B4 + 0xCC); // Get the players client number
        //GetTagPos((void*)0x08474B4, headBone, bonePos);
        //std::cout << "X: " << bonePos[0] << " " << "Y: " << bonePos[1] << " " << "Z: " << bonePos[2] << "\n";

        //std::cout << "Bone: " << *(unsigned short*)0x13FEE98 << std::endl;
    }

    if (GetAsyncKeyState(VK_NUMPAD0) & 0x01) {
        vec3_t newAngles = { Entities[0]->vAngles[0], Entities[0]->vAngles[1], 0.f};
        newAngles[1] = 70.f;

        SetPlayerViewAngles(Entities[0], newAngles);
    }

    if (GetAsyncKeyState(VK_UP) & 0x01) {
        //int result = Com_PrintWarning(17, "Warning: Hello, World!", 0);
        //std::cout << result << std::endl;
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

        std::cout << "Mapname: " << pCGs->mapname << "\n";

        svCheats->current.integer = 1;
    }

    //headBone = fnRegisterTag("j_head", 1, 7);
    //vec3_t bonePos = {};
    //GetTagPos_0(headBone, (int*)(0x08474B4), &bonePos);
    //std::cout << "X: " << bonePos[0] << " " << "Y: " << bonePos[1] << " " << "Z: " << bonePos[2] << "\n";

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

    // Reserve entity size to avoid memory reallocation
    Entities.reserve(32);

    headBone = fnRegisterTag("j_head", 1, 7);

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

        if (GetAsyncKeyState(VK_F3) & 0x01) {
            GetPlayers(Entities);
            std::cout << Entities[0] << "\n";
            std::cout << Entities[1] << "\n";
            std::cout << "Number of Players: " << pCGame->NumOfPlayers << "\n";
            int health = ((Entity*)pGEntities)->Health;
            std::cout << &((Entity*)pGEntities)->Health << ": " << health << "\n";
            std::cout << &((Entity*)pGEntities)->vOrigin[0] << ": " << ((Entity*)pGEntities)->vOrigin[0] << "\n";
            std::cout << &((Entity*)pGEntities)->vOrigin[1] << ": " << ((Entity*)pGEntities)->vOrigin[1] << "\n";
            std::cout << &((Entity*)pGEntities)->vOrigin[2] << ": " << ((Entity*)pGEntities)->vOrigin[2] << "\n";
            std::cout << "Equipment Pointer: " << ((Entity*)pGEntities)->pEquipment << "\n";
            std::cout << &((Entity*)pGEntities)->bAlive << ": " << ((Entity*)pGEntities)->bAlive << "\n";
        }

        if (GetAsyncKeyState(VK_F2) & 0x01) {
            std::cout << "FoV: " << pRefDef->tanHalfFovX << " " << pRefDef->tanHalfFovY << "\n";
            std::cout << "Screen Resolution : " << pRefDef->width << "x" << pRefDef->height << "\n";
            std::cout << "================================================\n";
            std::cout << "View Matrix\n";
            std::cout << pRefDef->mViewMatrix[0][0] << " " << pRefDef->mViewMatrix[0][1] << " " << pRefDef->mViewMatrix[0][2] << "\n";
            std::cout << pRefDef->mViewMatrix[1][0] << " " << pRefDef->mViewMatrix[1][1] << " " << pRefDef->mViewMatrix[1][2] << "\n";
            std::cout << pRefDef->mViewMatrix[2][0] << " " << pRefDef->mViewMatrix[2][1] << " " << pRefDef->mViewMatrix[2][2] << "\n";
        }

        if (GetAsyncKeyState(VK_F4) & 0x01) {
            std::vector<DynamicEntity*>Entities = {};
            GetDynamicEntities(Entities);
            
            std::cout << "DynEnt List Address: " << pDynamicEntList << "\n";
            std::cout << "First Entity Offset: " << (pDynamicEntList + 1) << "\n";

            if (Entities.size() > 0) {
                for (int i = 0; i < Entities.size(); i++) {
                    std::cout << "=================ENTITY: " << i << "=================\n";
                    std::cout << "Entity Address: " << Entities[i] << "\n";
                    std::cout << Entities[i]->EntityType << "\n";
                    std::cout << "Entities Origin: " << "\n";
                    std::cout << Entities[i]->vOrigin[0] << " " << Entities[i]->vOrigin[1] << " " << Entities[i]->vOrigin[2] << "\n";
                    std::cout << "=====================================================\n";
                }
            }
        }

        if (GetAsyncKeyState(VK_F5) & 0x01) {
            pViewAngles->vViewAngles[0] += 0.22f;
            pViewAngles->vViewAngles[1] += 0.22f;
        }

        if (GetAsyncKeyState(VK_F10) & 0x01) {
            int value = BG_GetWeaponIndexForName("m4_gl_mp");
            std::cout << "Returned value: " << value << "\n";
        }

        if (GetAsyncKeyState(VK_F9) & 0x01) {
            int value = fnSendServerCommand(0, "map_restart");
            std::cout << "Returned value: " << value << "\n";
        }
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

