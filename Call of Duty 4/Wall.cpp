#include "Wall.h"

void ESP(Player target)
{
    if (!target.IsAlive())
        return;

    vec2_t enemyScreenPos;
    vec2_t enemyHead2D;

    if (WorldToScreen(*target.vOrigin, enemyScreenPos)) {
        // Top of box
        vec3_t vHeadOrigin;
        vHeadOrigin = *target.vOrigin;
        vHeadOrigin.z += 65.f; // Added height for head

        if (WorldToScreen(vHeadOrigin, enemyHead2D)) {
            Drawing.DrawEspBox2D(enemyScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(1 * 255), int(0 * 255), int(0 * 255)));
        }
    }
}

bool WorldToScreen(vec3_t world, vec2_t& screen)
{
	vec3_t Position;
	Position = world - pRefDef->vCameraPos;
	vec3_t Transform;

	// Get our dot products from viewMatrix
	Transform.x = Position.DotProduct(pRefDef->mViewMatrix[1]);
	Transform.y = Position.DotProduct(pRefDef->mViewMatrix[2]);
	Transform.z = Position.DotProduct(pRefDef->mViewMatrix[0]);


	// Make sure it is in front of us
	if (Transform.z < 0.01f)
		return false;

	// Get the center of the screen
	vec2_t CenterScreen;
	CenterScreen.x = pRefDef->width / 2.f;
	CenterScreen.y = pRefDef->height / 2.f;

	screen.x = CenterScreen.x * (1 - (Transform.x / pRefDef->tanHalfFovX / Transform.z));
	screen.y = CenterScreen.y * (1 - (Transform.y / pRefDef->tanHalfFovY / Transform.z));
	return true;
}