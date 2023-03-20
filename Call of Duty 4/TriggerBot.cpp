#include "TriggerBot.h"

void TriggerBot()
{
	if (pCG->predictedPlayerState.weapFlags == 16)
		FireWeapon(game.players[game.GetLocalClientNum()].gEntity, game.GetServerTime());
}
