#include "Wall.h"

void ESP(Player target)
{
    if (!target.IsAlive())
        return;

    vec2_t enemyScreenPos;
    vec2_t enemyHead2D;

    if (Drawing.WorldToScreen(*target.vOrigin, enemyScreenPos, pRefDef)) {
        // Top of box
        vec3_t vHeadOrigin;
        vHeadOrigin = *target.vOrigin;
        vHeadOrigin.z += 65.f; // Added height for head

        if (Drawing.WorldToScreen(vHeadOrigin, enemyHead2D, pRefDef)) {
            Drawing.DrawEspBox2D(enemyScreenPos, enemyHead2D, 1, D3DCOLOR_ARGB(255, int(1 * 255), int(0 * 255), int(0 * 255)));
        }
    }
}