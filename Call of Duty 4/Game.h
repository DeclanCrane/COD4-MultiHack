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
public:
	Game();
	inline bool IsInGame() { return clSnapshot->valid ? true : false; }
	inline int GetNumEntities() { return clSnapshot->numEntities; }
	inline int GetNumClients() { return clSnapshot->numClients; }
	inline int GetServerTime() { return clSnapshot->serverTime; }
	inline int GetLocalClientNum() { return CG->localClientNum; }
	void GetPlayerList();
	bool HasPlayerListUpdated();
};

extern Game game;