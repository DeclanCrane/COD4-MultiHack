#include "Game.h"

Game game;

Game::Game()
{
	this->clSnapshot = (clSnapshot_t*)pCLSnapshot;
	this->CGs = pCGs;
	this->CG = pCG;
	this->gameType = CGs->gameType;
	this->mapName = CGs->mapname;
	this->players.reserve(MAX_PLAYERS);
	this->bSilentAim = false;
}

void Game::GetPlayerList()
{
	players.clear();

	int numClients = game.GetNumClients();

	for (int i = 0; i < MAX_PLAYERS; i++) {
		Player currentPlayer(i);
		if (currentPlayer.IsValidPlayer())
			this->players.push_back(currentPlayer);

		// If we found them all
		if (players.size() == numClients)
			break;
	}
}

bool Game::HasPlayerListUpdated()
{
	int numClients = clSnapshot->numClients;
	int playerListSize = players.size();

	if (playerListSize < numClients || playerListSize > numClients)
		return true;
	return false;
}

//void Game::GetGameType(char* gameType)
//{
//	/* 
//		Should return the real gametype name.
//		e.g. War == Team Deathmatch
//	*/
//}
