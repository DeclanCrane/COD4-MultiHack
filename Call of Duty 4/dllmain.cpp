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
#include "NullHooks.h"
#include "TriggerBot.h"
#include "Menu.h"
#include "D3D9Hook.h"

#include "NullSystem.h"

#include <iomanip>

#define ANGLE2SHORT(x)          ((int)((x) * 65536 / 360) & 65535)

unsigned short jBone = RegisterTag("j_head", 1, 7);

void __cdecl CL_WritePacketHook() {
    /* SILENT AIM */
    if (hack.bSilentAim && GetAsyncKeyState(VK_RBUTTON)) {
        usercmd_s* cmd = nullptr;

        // Get the current cmd
        cmd = GetCmd((pInput->currentCmdNum & 0x7F));

        // Advance the time
        cmd->serverTime += 1;

        // Set angles
        cmd->Pitch += ANGLE2SHORT(hack.vSilentAngles.x);
        cmd->Yaw += ANGLE2SHORT(hack.vSilentAngles.y);
        cmd->Roll = 0;
    }
    CL_WritePacket();
}

void __cdecl EngineHook() {
    /* AIMBOT */
    if (GetAsyncKeyState(VK_RBUTTON)) {
        int bestTarget = GetBestTarget();
        if (bestTarget >= 0) // If there's a valid target
            DoAimbot(bestTarget);
        //Sleep(1); // Prevents jitter?
    }
    //TriggerBot();
    if (GetAsyncKeyState('U') & 0x01) {
        CG_FireWeaponEasy(game.players[0].playerState, 1);
    }

    Engine();
}

bool bShowDemoMenu = true;
void ImGuiMenu() {
    ImGui::ShowDemoWindow(&bShowDemoMenu);
    ImGui::Begin("COD4 Multi-Hack");
    ImGui::Checkbox("Rage", &hack.bRage);
    ImGui::Checkbox("Silent Aim", &hack.bSilentAim);
    ImGui::Checkbox("Knife Aimbot", &hack.bKnifeAimbot);
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("Uses knife instead of gun for aimbot");
    ImGui::Spacing();
    ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), "Settings");
    ImGui::ColorEdit4("ESP Enemy Color", (float*)&hack.enemyESPColor, ImGuiColorEditFlags_Uint8);
    if (ImGui::TreeNode("Aimbot Settings"))
    {
        ImGui::Text("W.I.P");
        ImGui::TreePop();
    }
    if (ImGui::TreeNode("ESP Settings"))
    {
        ImGui::Text("W.I.P");
        ImGui::TreePop();
    }

    ImGui::End();
}

//static D3D9Hook Hook;
static Menu& menu = Menu::Get();
static HWND hWindow = FindWindowA(0, "Call of Duty 4");

// EndScene Detour
//HRESULT __stdcall EndSceneHook(IDirect3DDevice9* pDevice)
//{
//    // Pass the pDevice pointer to Drawing for drawing on screen
//    if (!drawing.IsSetup()) {
//        drawing.Setup(pDevice);
//        menu.SetupImGui(hWindow, pDevice);
//    }
//
//
//    /* Player ESP */
//    for (int i = 0; i < game.players.size(); i++) {
//        // Only draws living players who aren't us
//        if (!game.players[i].IsAlive() || i == game.GetLocalClientNum())
//            continue;
//        PlayerESPNew(i);
//    }
//
//    if (GetAsyncKeyState(VK_INSERT) & 0x01) {
//        Menu::ToggleMenu();
//    }
//
//    if (Menu::IsOpen()) {
//        menu.Draw(&ImGuiMenu);
//    }
//
//    if (GetAsyncKeyState(VK_LEFT) & 0x01) {
//        //headBone = fnRegisterTag("j_head", 1, 7);
//        //if (IsTargetVisible(headBone, (int*)(0x08474B4))) {
//        //    std::cout << "Visible\n";
//        //}
//        //else {
//        //    std::cout << "Not Visible\n";
//        //}
//        //if (IsTargetValid((int*)(0x08474B4))) {
//        //    std::cout << "Valid\n";
//        //}
//        //else {
//        //    std::cout << "Invalid\n";
//        //}
//
//        //GetPlayerNameByClientNum();
//
//        //const char* rankName = CG_GetRank(47);
//        //std::cout << rankName << "\n";
//
//        //if (CG_OnSameTeam((int*)0x1280500, (int*)0x1280774)) {
//        //    std::cout << "Same team!\n";
//        //}
//        //else {
//        //    std::cout << "Enemy!\n";
//        //}
//
//        //std::cout << "MaxClients: " << pCGs->maxClients;
//        /*std::cout << "Team: " << ((gentity_s*)0x1280500)->client->clientSession.clientState.team_t;*/
//        //gentity_s* pLocal = (gentity_s*)0x1280774;
//        //vec3_t newAngles = { (pLocal->client->viewAngles[0] + 28.f), (pLocal->client->viewAngles[1] + 28.f), 0.f};
//        //SetClientViewAngle((int*)0x1280774, newAngles);
//
//        //for (int i = 0; i < 1; i++) {
//        //    Player tempPlayer(i);
//        //    players.push_back(tempPlayer);
//        //}
//
//        //std::cout << players[0].GetWeaponID() << "\n";
//        //WeaponDef* weapon = players[0].GetWeaponDef();
//        //weapon->fireType = WEAPON_FIRETYPE_FULLAUTO;
//        //std::cout << players[0].GetTeam() << "\n";
//        //std::cout << players[0].IsOnLadder() << "\n";
//
//        if (CG_OnSameTeam((gentity_s*)0x1280500, (gentity_s*)0x1280774)) {
//            std::cout << "Friendly!\n";
//        }
//        else {
//            std::cout << "Enemy!\n";
//        }
//
//        unsigned short head = RegisterTag("j_head", 1, 7);
//        if (IsTargetVisible(head, (centity_t*)0x08474B4)) {
//            std::cout << "Visible!\n";
//        }
//        else {
//            std::cout << "Invisible!\n";
//        }
//
//        FireWeapon((gentity_s*)0x1280500, game.GetServerTime());
//    }
//
//    if (GetAsyncKeyState(VK_F1) & 0x01) {
//        std::cout << "Weapon: " << pPlayerState->weapon << "\n";
//        WeaponDef* currentWeapon = nullptr;
//        GetPlayerWeaponDef(pPlayerState->weapon, currentWeapon);
//        if (currentWeapon) {
//            std::cout << currentWeapon->fireType << "\n";
//            // Damage and Penetration
//            currentWeapon->penetrateType = PENETRATE_TYPE_LARGE;
//            currentWeapon->impactType = IMPACT_TYPE_BULLET_AP;
//            currentWeapon->fireType = WEAPON_FIRETYPE_FULLAUTO;
//            currentWeapon->bRifleBullet = 1;
//            currentWeapon->armorPiercing = 1;
//            currentWeapon->damage = 1000;
//            currentWeapon->playerDamage = 300;
//            currentWeapon->iFireTime = 50;
//
//            // Spread and Recoil
//            // ADS View Kick
//            currentWeapon->fAdsViewKickPitchMin = 0.f;
//            currentWeapon->fAdsViewKickPitchMax = 0.f;
//            currentWeapon->fAdsViewKickYawMin = 0.f;
//            currentWeapon->fAdsViewKickYawMax = 0.f;
//            // ADS Gun Kick
//            currentWeapon->fAdsGunKickPitchMin = 0.f;
//            currentWeapon->fAdsGunKickPitchMax = 0.f;
//            currentWeapon->fAdsGunKickYawMin = 0.f;
//            currentWeapon->fAdsGunKickYawMax = 0.f;
//
//            // Hip View Kick
//            currentWeapon->fHipViewKickPitchMin = 0.f;
//            currentWeapon->fHipViewKickPitchMax = 0.f;
//            currentWeapon->fHipViewKickYawMin = 0.f;
//            currentWeapon->fHipViewKickYawMax = 0.f;
//        }
//    }
//
//    if (GetAsyncKeyState(VK_NUMPAD2) & 0x01) {
//        //WeaponDef* weapDef = game.players[0].GetWeaponDef();
//        //WeaponParms parms;
//        //vec3_t zero;
//        //parms.forward = zero;
//        //parms.right = zero;
//        //parms.up = zero;
//        //parms.muzzleTrace = zero;
//        //parms.gunForward = zero;
//        //parms.weaponDef = weapDef;
//        //Weapon_Melee((gentity_s*)0x1280500, &parms, 2000.f, 2000.f, 2000.f, game.GetServerTime() + 1);
//
//        vec3_t forward;
//        vec3_t mins;
//        vec3_t maxs;
//        //G_GetPlayerViewOrigin((int*)0x131D5A8, &forward);
//        //WeaponDef* def = game.players[0].GetWeaponDef();
//        //char* name = nullptr;
//        //NameFromNum(0, name);
//        //std::cout << "Name: " << name << "\n";
//        //std::cout << "X: " << maxs.x << " " << "Y: " << maxs.y << " " << "Z: " << maxs.z << "\n";
//
//        //CG_CalcEyePoint(0, &mins);
//        //std::cout << "X: " << mins.x << " " << "Y: " << mins.y << " " << "Z: " << mins.z << "\n";
//        // 
//        //const char* name = "HelloWorld";
//        //CreateProfile(name);
//
//        WeaponParms weapParms = {};
//
//        weapParms.weaponDef = game.players[0].GetWeaponDef();
//        CalcMuzzlePointsASM(&weapParms, game.players[0].gEntity, game.players[0].GetWeaponDef());
//        std::cout << "X: " << weapParms.forward.x << " " << "Y: " << weapParms.forward.y << " " << "Z: " << weapParms.forward.z << "\n";
//        //WeaponMelee(game.GetServerTime() + 1, &weapParms, game.players[0].gEntity, 5000.f, 5000.f, 5000.f);
//        //CG_FireWeapon(0, game.players[0].cEntity, 0x1A, (unsigned short)0x13FEF22, pPlayerState);
//        //CG_FireWeapon(0, game.players[0].cEntity, 0x1A, (unsigned short)0x2F0, pPlayerState);
//        /*Weapon_Throw_Grenade(&weapParms, game.players[0].gEntity, game.players[0].gEntity->entityState.weapon, game.players[0].gEntity->entityState.weaponModel);*/
//
//        vec3_t vZero(0.f, 0.f, 0.f);
//        BulletFireParams bulletParams = {};
//        bulletParams.dir = weapParms.muzzleTrace;
//        bulletParams.origStart = vZero;
//        bulletParams.start = pRefDef->vCameraPos;
//        bulletParams.end = *game.players[1].vOrigin;
//        //bulletParams.damageMultiplier = 1.f;
//        bulletParams.weaponEntIndex = game.players[0].GetWeaponID();
//        bulletParams.ignoreEntindex = 0;
//        BulletTraceResults btr = {};
//
//        if (Bullet_Trace(&btr, game.players[0].GetWeaponDef(), &bulletParams, game.players[0].gEntity, 0)) {
//            std::cout << "Result: " << btr.trace.Fraction << "\n";
//            std::cout << "Damage Multiplier: " << bulletParams.damageMultiplier << "\n";
//        }
//
//        if (Bullet_Trace(&btr, game.players[0].GetWeaponDef(), &bulletParams, game.players[0].gEntity, btr.trace.surfaceFlags)) {
//            std::cout << "Result: " << btr.trace.Fraction << "\n";
//            std::cout << "Damage Multiplier: " << bulletParams.damageMultiplier << "\n";
//        }
//
//        /*int damage = GetBulletDamage(game.players[0].GetWeaponDef(), &bulletParams, &btr);*/
//        //int damage = BulletGetDamage(game.players[0].GetWeaponDef(), &bulletParams, &btr);
//        /*std::cout << "Damage: " << damage << "\n";*/
//
//        if (BG_AdvanceTrace(&bulletParams, &btr, 0.009999999776482582f)) {
//            std::cout << "Ayyyyy\n";
//            std::cout << "Damage: " << bulletParams.damageMultiplier << "\n";
//            std::cout << "Damage: " << btr.trace.Fraction << "\n";
//        }
//    }
//
//    if (GetAsyncKeyState(VK_NUMPAD3) & 0x01) {
//        //PrintMemory((void*)0x4162B2, 2);
//        /*reserveAmmoPatch.Set();*/
//        //int ammo = BG_WeaponAmmo(game.players[0].GetWeaponID(), game.players[0].playerState);
//        //std::cout << "Ammo: " << ammo << "\n";
//        //G_GivePlayerWeapon(6, game.players[0].gEntity->client, 0);
//        //Add_Ammo(game.players[0].gEntity, game.players[0].GetWeaponID(), 0, 150, 1);
//        //std::cout << &pCG->predictedPlayerEntity.entityState.eventParam << "\n";
//        //CG_EntityEvent(0, EV_STANCE_FORCE_PRONE, &pCG->predictedPlayerEntity);
//
//        int weap = CurrentPrimaryWeapon(game.players[0].playerState);
//        std::cout << "Current Weapon: " << weap << "\n";
//
//        gentity_s* result = Drop_Weapon(weap, game.players[0].gEntity, *game.players[0].playerState->weaponsOld[weap + 8], 0);
//        std::cout << "Drop Weapon Result: " << result << "\n";
//    }
//
//    if (GetAsyncKeyState(VK_NUMPAD4) & 0x01) {
//        /*int result = TakeAwayClipAmmo(2, CurrentPrimaryWeapon(game.players[0].playerState), game.players[0].playerState);*/
//        
//        //int result = IsClipEmpty(game.players[0].playerState);
//     
//        //bool result = IsPlayerFiring(game.players[0].GetWeaponDef(), game.players[0].playerState);
//        //std::cout << "FireType: " << result << "\n";
//        // 
//        //CG_FireWeaponEasy(game.players[0].playerState, 0);
//
//        /*CG_FireMeleeEasy(game.players[0].playerState);*/
//
//        /*Play_RaiseFromGrenadeThrow(game.players[0].playerState);*/
//
//        //bool result = IsMantling(game.players[0].gEntity->client);
//        //std::cout << "Mantling: " << result << "\n";
//
//        //bool result = IsHoldingWeapon(4, game.players[0].playerState);
//        //std::cout << "Holding: " << result << "\n";
//
//        //bool result = PlayerHasSpecificWeapon(0xB, game.players[0].playerState);
//        //std::cout << "Unknown2: " << result << "\n";
//
//        //float result = BG_GetBobCycle(game.players[0].playerState);
//        //std::cout << "Result: " << result << "\n";
//
//        /*FillClip(game.players[0].gEntity->client, game.players[0].GetWeaponID());*/
//
//        game.players[0].RemovePerks();
//    }
//
//    if (GetAsyncKeyState(VK_NUMPAD5) & 0x01) {
//        game.players[0].GiveAllPerks();
//    }
//
//    return Hook.pEndScene(pDevice);
//}

// Reset Detour
//HRESULT __stdcall ResetHook(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
//{
//    return Hook.pReset(pDevice, pPresentationParameters);
//}

bool bTestRun = false;
void endSceneCallback(IDirect3DDevice9* pDevice) {
    if (!bTestRun) {
        std::cout << "Hooked!\n";
        bTestRun = true;
    }

    /* Player ESP */
    for (int i = 0; i < game.players.size(); i++) {
        // Only draws living players who aren't us
        if (!game.players[i].IsAlive() || i == game.GetLocalClientNum())
            continue;
        PlayerESPNew(i);
    }

    if (GetAsyncKeyState(VK_INSERT) & 0x01) {
        menu.ToggleMenu();
    }

    if (menu.IsOpen()) {
        menu.Draw(ImGuiMenu);
    }
}

void resetCallback(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters) {
    std::cout << "Reset!\n";
}

// Main Thread
int MainThread(PVOID pModule) {
    // Create console ( Console class needs rewrite )
    Console console;
    console.CreateConsole();

    // Setup D3D9 Hook
    D3D9HookNew Hook;
    Hook.Install(endSceneCallback, resetCallback);

    // Setup ImGui Menu
    menu.SetupImGui(hWindow, Hook.GetDevice());
    drawing.Setup(Hook.GetDevice());

    /* Setup Engine Hooks */
    Engine = (_Engine)DetourFunction((PBYTE)0x42DD20, (PBYTE)&EngineHook);
    CL_WritePacket = (_CL_WritePacket)DetourFunction((PBYTE)0x460270, (PBYTE)&CL_WritePacketHook);
    
    while (true) {
        // Eject
        if (GetAsyncKeyState(VK_END) & 0x01) {
            break;
        }
        Hack();
    }

    // Cleanup and exit

    //Release Engine Hooks
    Hook.Uninstall();
    menu.Destroy();
    DetourRemove((PBYTE)CL_WritePacket, (PBYTE)CL_WritePacketHook);
    DetourRemove((PBYTE)Engine, (PBYTE)EngineHook);
    Sleep(100);

    //Free console
    console.CloseConsole();

    FreeLibraryAndExitThread((HMODULE)pModule, 0);
    return 0;
}

// Entry Point
BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
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
