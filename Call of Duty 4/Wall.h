#pragma once
#include "COD4Structs.h"
#include "COD4Functions.h"
#include "Entity.h"
#include "Drawing.h"
#include "Game.h"

void PlayerESP(int targetIndex);

void PlayerESPNew(int playerIndex);

bool WorldToScreen(vec3_t &world, vec2_t& screen);