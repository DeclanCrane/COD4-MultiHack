#include "Aimbot.h"

unsigned short headBone = RegisterTag("j_head", 1, 7);

void DoAimbot(Entity* pBestTarget)
{

	// Check if visible and valid
	if(!IsTargetVisible(headBone, (centity_t*)0x08474B4) || !IsTargetValid((int*)0x08474B4))
		return;

	// Get the bone we want
	vec3_t vAimPos;
	AimTarget_GetTagPos(headBone, (centity_t*)0x08474B4, &vAimPos);

	vec3_t vAngles;
	GetAngleToTarget(vAimPos, pRefDef->vCameraPos, vAngles);

	// Get Delta Angles
	vec3_t delta = vAngles - pPlayerState->vViewAngles;

	pViewAngles->vViewAngles.x += (delta.x * 0.4);
	pViewAngles->vViewAngles.y += (delta.y * 0.4);

	// Fire gun
	FireWeapon((gentity_s*)0x1280500, game.GetServerTime() + 1);
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
	int bestIndex = -1;
	int secondBest = -1;

	for (int i = 0; i < game.players.size(); i++) {

	}

	return 0;
}
