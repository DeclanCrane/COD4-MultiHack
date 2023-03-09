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
    unsigned int GetWeaponID();
    WeaponDef* GetWeaponDef();
    unsigned short GetTeam();
    bool IsOnGround();
    bool IsOnLadder();
    bool IsAlive();
    bool IsValid();
};