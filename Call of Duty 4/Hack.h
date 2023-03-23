#pragma once

#include "Game.h"
#include "Entity.h"
#include "Aimbot.h"

// Temps
#include <iostream>

struct Color4 {
	int r;
	int g;
	int b;
	int a;
};

struct Color3 {
	int r;
	int g;
	int b;
};

// Main hack function
void Hack();

class HackSettings {
public:
	HackSettings() : bRage(false), bKnifeAimbot(false), 
					 bSilentAim(false), vSilentAngles(),
					 enemyESPColor() {}
	bool bRage;
	bool bKnifeAimbot;
	bool bSilentAim;
	vec2_t vSilentAngles;
	Color4 enemyESPColor;
};

extern HackSettings hack;