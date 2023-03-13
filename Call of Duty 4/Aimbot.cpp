#include "Aimbot.h"

unsigned short headBone = RegisterTag("j_head", 1, 7);

void DoAimbot(int target)
{

	// Check if visible and valid
	if(/*!IsTargetVisible(headBone, game.players[target].cEntity) || */!IsTargetValid(game.players[target].cEntity))
		return;

	// Get the bone we want
	vec3_t vAimPos;
	AimTarget_GetTagPos(headBone, game.players[target].cEntity, &vAimPos);

	vec3_t vAngles;
	GetAngleToTarget(vAimPos, pRefDef->vCameraPos, vAngles);

	// Get Delta Angles
	vec2_t delta;
	delta.x = vAngles.y - pPlayerState->vViewAngles.x;
	delta.y = vAngles.x - pPlayerState->vViewAngles.y;

	pViewAngles->vViewAngles.x += delta.x;
	pViewAngles->vViewAngles.y += delta.y;

	// Fire gun
	if (hack.bKnifeAimbot) {
		FireWeaponMelee((int*)0x1280500, game.GetServerTime() + 1);
	}
	else {
		FireWeapon((gentity_s*)0x1280500, game.GetServerTime() + 1); // Change this to local player
	}
}

void GetAngleToTarget(vec3_t& vTargetPos, vec3_t& vCameraPos, vec3_t& vAngles)
{
	vec3_t vDelta;
	vDelta = vTargetPos - vCameraPos;
	VectorAngles(vDelta, vAngles);
}

void VectorAngles(const vec3_t& forward, vec3_t& angles)
{
	float tmp, yaw, pitch;

	if (forward.y == 0.f && forward.x == 0.f)
	{
		yaw = 0.f;
		if (forward.z > 0.f)
			pitch = 270.f;
		else
			pitch = 90.f;
	}
	else
	{
		yaw = (atan2f(forward.y, forward.x) * 180.f / M_PI);
		if (yaw < 0.f)
			yaw += 360.f;

		tmp = sqrtf(forward.x * forward.x + forward.y * forward.y);
		pitch = (atan2f(-forward.z, tmp) * 180.f / M_PI);
		if (pitch < 0.f)
			pitch += 360.f;
	}

	angles.x = yaw;
	angles.y = pitch;
	angles.z = 0.f; // roll
}

int GetBestTarget()
{
	float closestPlayer = 0.f;
	int bestIndex = -1;

	for (int i = 0; i < game.players.size(); i++) {
		// Make sure they're not the local player ( us )
		if (game.players[i].clientNum == game.GetLocalClientNum())
			continue;

		// Make sure they're alive and valid
		if (!game.players[i].IsAlive() || !IsTargetValid(game.players[i].cEntity))
			continue;

		// Make sure they're visible
		if (!hack.bRage) {
			if (!IsTargetVisible(headBone, game.players[i].cEntity))
				continue;
		}

		// Check how close they are to local player ( us )
		float distance;
		distance = game.players[game.GetLocalClientNum()].vOrigin->GetDistance(*game.players[i].vOrigin);

		// If the closest player isn't set, set the first distance
		if (closestPlayer == 0.f) {
			closestPlayer = distance;
			bestIndex = i;
			continue;
		}

		if (distance < closestPlayer) {
			closestPlayer = distance;
			bestIndex = i;
		}
	}

	return bestIndex;
}
