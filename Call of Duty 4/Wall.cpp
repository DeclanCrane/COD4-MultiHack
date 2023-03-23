#include "Wall.h"

unsigned short headBoneWall = RegisterTag("j_head", 1, 7);

void PlayerESP(int playerIndex)
{
	vec2_t feetScreenPos;
	vec2_t enemyHead2D;

	// Make sure they're alive
    if (!game.players[playerIndex].IsAlive())
        return;

    if (WorldToScreen(*game.players[playerIndex].vOrigin, feetScreenPos)) {
        // Top of box
        vec3_t vHeadOrigin;
        vHeadOrigin = *game.players[playerIndex].vOrigin;
        vHeadOrigin.z += 65.f; // Added height for head

        if (WorldToScreen(vHeadOrigin, enemyHead2D)) {
			// Are they on our team?
			if (!CG_OnSameTeam(game.players[game.GetLocalClientNum()].gEntity, game.players[playerIndex].gEntity)) {
				// Are the visible?
				if (IsTargetVisible(headBoneWall, game.players[playerIndex].cEntity)) {
					// Enemy visible color
					drawing.DrawEspBox2D(feetScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(0 * 255), int(1 * 255), int(0 * 255)));
				}
				else {
					// Enemy invisible color
					drawing.DrawEspBox2D(feetScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(1 * 255), int(0 * 255), int(0 * 255)));
				}
			}
			else {
				// Team color
				drawing.DrawEspBox2D(feetScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(0 * 255), int(0 * 255), int(1 * 255)));
			}
        }
    }
}

void PlayerESPNew(int playerIndex) {
	vec3_t playerWorldPos;
	vec3_t playerHeadPos;
	vec2_t screenFeetPos;
	vec2_t screenHeadPos;

	// Get the player's world position (feet)
	playerWorldPos = *game.players[playerIndex].vOrigin;
	// Calculate player's head position
	playerHeadPos = playerWorldPos;
	playerHeadPos.z += 65.f; // Just adding 65.f, for a rough height of a player

	// Make sure they're visible on screen
	// And get their screen coords
	if (WorldToScreen(playerWorldPos, screenFeetPos)) {
		WorldToScreen(playerHeadPos, screenHeadPos);
		drawing.DrawEspBox2D(screenFeetPos, screenHeadPos, 1, D3DCOLOR_ARGB(hack.enemyESPColor.a, hack.enemyESPColor.r, hack.enemyESPColor.g, hack.enemyESPColor.b));
	}
}

bool WorldToScreen(vec3_t &world, vec2_t& screen)
{
	vec3_t Position;
	vec3_t Transform;
	vec2_t CenterScreen;

	Position = world - pRefDef->vOrigin;

	// Get our dot products from viewMatrix
	Transform.x = Position.DotProduct(pRefDef->mViewMatrix[1]);
	Transform.y = Position.DotProduct(pRefDef->mViewMatrix[2]);
	Transform.z = Position.DotProduct(pRefDef->mViewMatrix[0]);


	// Make sure it is in front of us
	if (Transform.z < 0.01f)
		return false;

	// Get the center of the screen
	CenterScreen.x = pRefDef->width * 0.5;
	CenterScreen.y = pRefDef->height * 0.5;

	screen.x = CenterScreen.x * (1 - (Transform.x / pRefDef->tanHalfFovX / Transform.z));
	screen.y = CenterScreen.y * (1 - (Transform.y / pRefDef->tanHalfFovY / Transform.z));
	return true;
}