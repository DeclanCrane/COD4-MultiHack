#pragma once
#include "Entity.h"
#include "COD4Enums.h"

bool GetPlayers(std::vector<Entity*> &Players, bool bIncludeClient)
{
    //// MAKE SURE TO ALSO CHECK IF ENTITIES ARE REMOVED!!! ( NOT FINISHED YET )
    //// Save this locally in-case it changes while executing function
    //int numOfPlayers = pCGame->NumOfPlayers;

    //// Check if there are already entities in Entities vector
    //if (Entities.size() > 0) {
    //    // Check if there is new entities
    //    // If not, there's no need to reinitialize
    //    if (Entities.size() == numOfPlayers) {
    //        // Just return because there's no new entities
    //        return true;
    //    }
    //}

    //// If new entities must be added to the list,
    //// only add those ones instead of re-adding all the entities.

    //// Get the difference in entities
    //int newPlayers = numOfPlayers - Entities.size();
    //int* newPlayersEntityList = pEntityList + (0x274 * Entities.size());

    //for (int i = 0; i < newPlayers; i++) {
    //    Entity* newEnt = (Entity*)(newPlayersEntityList + (0x274 * i));
    //    Entities.push_back(newEnt);
    //}


    // Clear the entity list.
    Players.clear();

    // Get the maximum amount of players allowed in-game
    int maxNumPlayers = pCGame->MaxNumPlayers;
    int playerIndex = 1; // Set to 1 by default to skip the client player in the list

    // If bIncludePlayers is true, include the client player
    if (bIncludeClient)
        playerIndex = 0;

    // Add all the potential players to the list
    for (playerIndex; playerIndex < maxNumPlayers; playerIndex++) { // Skip first player ( client )
        Players.push_back((Entity*)(pGEntities + (0x274 * playerIndex)));
    }

    /* 
        Make sure we actually got anything.
        This isn't a great check because it doesn't account
        for the entity list pointing to garbage.
    */
    if (Players.size() > 0)
        return true;

    return false;
}

int GetPlayers(std::vector<Entity*>& Players)
{
    int numClients = 0;

    // Get the amount of clients playing
    numClients = pCG->snapOne.numClients;

    // Clear old player list
    Players.clear();

    // Get all the players
    for (int i = 0; i < numClients; i++) {
        Players.push_back((Entity*)(pGEntities + (0x274 * i)));
    }
    return Players.size();
}

bool IsPlayerValid(Entity* Player)
{
    // If player is a spectator
    if (Player->PlayState != PlayerPlayState::Active) {
        return false;
    }

    // Check if they're alive
    if (!Player->bAlive) {
        return false;
    }

    return true;
}

bool GetDynamicEntities(std::vector<DynamicEntity*>& Entities)
{
    // Store locally in-case it changes while executing
    int entCount = pDynamicEntList->EntityCount;

    // Probably not in-game yet
    if (entCount == 0) {
        return false;
    }

    // Clear the list of old entities ( May not need this )
    Entities.clear();

    /*
        We have to get the first entity manually
        with an offset of 0x8, after that the offset
        is 0xF4
    */

    // Location of the first entity in the list
    int pFirstEnt = (pDynamicEntBase + 0x8);
    // Add the first entity to the list
    Entities.push_back((DynamicEntity*)pFirstEnt);

    // Get the rest
    for (int i = 1; i < entCount; i++) {
        Entities.push_back((DynamicEntity*)(pFirstEnt + (0xF4 * i)));
    }

    if (Entities.size() > 0) {
        return true;
    }

    return false;
}

bool IsPlayerOnGround(Entity* Player)
{
    if(Player->onGround != 254) { // 254 - On Ground
        return false;             // 255 - In Air
    }
    return true;
}

bool GetPlayersWeapon(Entity* Player)
{
    int weaponId = Player->WeaponID;

    return false;
}

bool GetPlayerWeaponDef(int weaponId, WeaponDef* &weaponDef)
{
    weaponDef = *(WeaponDef**)((weaponId * 4) + pWeaponInfoBase);
    if (weaponDef)
        return true;
    return false;
}

Player::Player(int clientNum)
{
    this->clientNum = clientNum;

    // Get all the information related to this player
    this->cEntity = (centity_t*)(pCEntities + 0x1DC * clientNum);
    this->gEntity = (gentity_s*)(pGEntities + 0x274 * clientNum);

    this->playerState = &gEntity->client->playerState;
    this->clientSession = &gEntity->client->clientSession;

    this->vOrigin = &gEntity->entityState.lerpEntityState.trOrigin.trBase;
}

unsigned int Player::GetWeaponID()
{
    return this->gEntity->entityState.weapon;
}

WeaponDef* Player::GetWeaponDef()
{
    return *(WeaponDef**)((GetWeaponID() * 4) + pWeaponInfoBase);
}

unsigned short Player::GetTeam()
{
    return clientSession->clientState.team_t;
}

bool Player::IsOnGround()
{
    if (playerState->groundEntityNum == ON_GROUND)
        return true;
    return false;
}

bool Player::IsOnLadder()
{
    /* 
        This may not be the best way to do this.
        Needs testing
    */

    // 0x8 seems to be a playerMovement flag for going up a ladder
    // 0x28 is for going down
    if (playerState->pm_flags == 0x8 || playerState->pm_flags == 0x28)
        return true;

    return false;
}

bool Player::IsAlive()
{
    if (gEntity->client->clientSession.sessionState_t != SESS_STATE_PLAYING)
        return false;
    return true;
}

bool Player::IsValid()
{
    // Set to 1 if it's a valid player ( HUMAN )
    if (gEntity->entityState.eType)
        return true;
    return false;
}

/* NOTES
    - You can get players current clip ammo and equipment by 
        getting weaponID and accessing that index in the ammo array

    - You can edit a players perks with the bitfield inside gclient
    - You can modify perk multipliers inside their respective dvar
    - Check weapFlags, it's set if player runs out of ammo
*/