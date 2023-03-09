#include "Hack.h"

void Hack()
{
	// Don't do anything if you're not in-game
	if (!game.IsInGame())
		return;

	// Check and updates player list
	if (game.HasPlayerListUpdated())
		game.GetPlayerList();

	if (GetAsyncKeyState(VK_RIGHT) & 0x01) {
		if (game.players.size() < 2)
			return;
		int distance = game.players[0].vOrigin->GetDistance(*game.players[1].vOrigin);
		std::cout << "Distance: " << distance << "\n";
	}
}
