#pragma once
#include "Structs.h"
#include "Offsets.h"
#include "COD4Structs.h"
#include "Vec.h"
#include <vector>

// Gets all the player entities
//bool GetPlayers(std::vector<Entity*> &Players, bool bIncludeClient = false);

// Gets all player entities
int GetPlayers(std::vector<Entity*>& Players);

// Makes sure the player is valid
// Returns true if they're alive and not spectating
bool IsPlayerValid(Entity* Player);

// Gets all the dynamic entities (e.g. Weapons, Explosives, Cars, etc.)
bool GetDynamicEntities(std::vector<DynamicEntity*>& Entities);

// 255 - In Air
// 254 - On Ground
// Returns weither player is on ground or not
bool IsPlayerOnGround(Entity* Player);

// Gets the player's current weapon
bool GetPlayersWeapon(Entity* Player);

bool GetPlayerWeaponDef(int weaponId, WeaponDef* &weaponDef);

class Player {
public:
    int clientNum;
    vec3_t* vOrigin;
    centity_t* cEntity;
    gentity_s* gEntity;
    playerState_s* playerState;
    clientSession_t* clientSession;

public:
    Player(int clientNum);
    inline unsigned int GetWeaponID() { return gEntity->entityState.weapon; }
    inline WeaponDef* GetWeaponDef() { return *(WeaponDef**)((GetWeaponID() * 4) + pWeaponInfoBase); }
    unsigned short GetTeam();
    bool IsOnGround();
    bool IsOnLadder();
    inline bool IsAlive() { return gEntity->client->clientSession.sessionState_t == SESS_STATE_PLAYING ? true : false; }
    inline bool IsValidPlayer() { return gEntity->entityState.eType == PLAYER ? true : false; }
    // Modify player's perks
    void SetPerk(perkFlags_t perk, bool state = false);
    // Take away all player's perks
    void RemovePerks();
    // Give player all perks
    void GiveAllPerks();
};