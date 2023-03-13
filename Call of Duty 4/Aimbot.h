#pragma once
#include "math.h";
#include "Structs.h"
#include "COD4Structs.h"
#include "COD4Functions.h"
#include "Offsets.h"
#include "Vec.h"
#include "Game.h"
#include "Hack.h"

#include <iostream>

#define M_PI 3.14

void DoAimbot(int target);

// Rewrite this when you get more knowledge
void GetAngleToTarget(vec3_t& vTargetPos, vec3_t& vCameraPos, vec3_t& vAngles);

// Rewrite this when you get more knowledge
void VectorAngles(const vec3_t& forward, vec3_t& angles);

// Finds the best target
int GetBestTarget();