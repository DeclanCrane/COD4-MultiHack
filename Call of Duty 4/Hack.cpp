#include "Hack.h"

void Hack()
{
	// Don't do anything if you're not in-game
	if (!game.IsInGame()) {
		return;
	}

	// Get player list
	// This bugs out if a player leaves the game
	if (game.HasPlayerListUpdated()) {
		game.GetPlayerList();
		Sleep(10);
		std::cout << "Num Clients: " << game.GetNumClients() << "\n";
		std::cout << "Num Players List: " << game.players.size() << "\n";
		std::cout << "Updating players\n";
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x01) {
		if (game.players.size() < 2)
			return;
		int distance = game.players[0].vOrigin->GetDistance(*game.players[1].vOrigin);
		std::cout << "Distance: " << distance << "\n";
	}

	if (GetAsyncKeyState(VK_NUMPAD0) & 0x01) {
		//int best = GetBestTarget();
		//std::cout << "BestTarget: " << best << "\n";
		std::cout << "CEntity: " << std::hex << game.players[1].cEntity << "\n";
	}
}
