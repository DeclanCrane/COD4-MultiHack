#pragma once

#include "Game.h"
#include "Entity.h"
#include "Aimbot.h"

// Temps
#include <iostream>

// Main hack function
void Hack();

class HackSettings {
public:
	HackSettings();
	bool bRage;
	bool bKnifeAimbot;
};

extern HackSettings hack;