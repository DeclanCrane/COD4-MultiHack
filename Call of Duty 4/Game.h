#pragma once
#include <vector>
#include "Offsets.h"
#include "COD4Structs.h"
#include "COD4Constants.h"
#include "Entity.h"

class Game {
private:
	clSnapshot_t* clSnapshot;
	CGs_t* CGs;
	CG_s* CG;
public:
	char* gameType;
	char* mapName;
	std::vector<Player> players;
	vec2_t silentAngles;
	bool updateSilent; // Used for updating silentAim packets
	bool bSilentAim; // Used for toggling silent aim
public:
	Game();
	bool IsInGame();
	int GetNumEntities();
	int GetNumClients();
	void GetPlayerList();
	bool HasPlayerListUpdated();
	int GetServerTime();
	int GetLocalClientNum();
};

extern Game game;