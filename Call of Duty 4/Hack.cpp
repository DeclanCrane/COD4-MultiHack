#include "Hack.h"

HackSettings hack;

void Hack()
{
	// Don't do anything if you're not in-game
	if (!game.IsInGame()) {
		return;
	}

	// Get player list
	if (game.HasPlayerListUpdated()) {
		game.GetPlayerList();
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

	// Toggle rage
	if (GetAsyncKeyState(VK_NUMPAD0) & 0x01) {
		hack.bRage = !hack.bRage;
		std::cout << "Rage Toggled\n";
	}

	if (GetAsyncKeyState('K') & 0x01) {
		hack.bKnifeAimbot = !hack.bKnifeAimbot;
		if(hack.bKnifeAimbot)
			*(float*)(0xCBB3A9C + 0xC) = 3000.f;
		if(!hack.bKnifeAimbot)
			*(float*)(0xCBB3A9C + 0xC) = 64.f;
		std::cout << "Knife Aimbot Toggled\n";
	}
}

HackSettings::HackSettings()
{
	bRage = false;
	bKnifeAimbot = false;
}
