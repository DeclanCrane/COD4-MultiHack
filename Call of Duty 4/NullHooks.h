#pragma once
#include <string.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Windows.h"

class Patch {
public:
	std::vector<byte> original;
	std::vector<byte> patch;
	void* src;
	size_t size;
public:
	Patch(void* src, std::vector<byte> bytes);
	void Set();
	void Restore();
};

class Nop {
public:
	std::vector<byte> original;
	void* src;
	size_t size;
public:
	Nop(void* src, size_t size);
	// Write the NOP patch
	void Set();
	// Restore original instruction
	void Restore();
};

void PrintMemory(void* src, size_t size, bool bNewLine = true);