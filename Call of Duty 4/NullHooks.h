#pragma once
#include <string.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Windows.h"
//void ReadMem() {
//	DWORD oldProtect = 0;
//	const char code[] = { 0x90, 0x90 };
//	void* src = (void*)0x4162B2;
//	VirtualProtect(src, 2, PAGE_EXECUTE_READWRITE, &oldProtect);
//	memcpy(src, code, 2);
//	VirtualProtect(src, 2, oldProtect, 0);
//}
//
//void PrintMemory(void* src, size_t size, bool bNewLine = true) {
//	std::vector<byte> bytes{};
//	bytes.resize(size);
//
//	memcpy(&bytes[bytes.size() - size], src, size);
//
//	for (int i = 0; i < size; i++) {
//		std::cout << "0x" << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << (int)bytes.at(i) << " ";
//	}
//
//	if(bNewLine)
//		std::cout << "\n";
//}
//
//void ReadMemory(void* src, size_t size) {
//	std::vector<byte> bytes{};
//	bytes.resize(size);
//
//	memcpy(&bytes[bytes.size() - size], src, size);
//}

class Patch {
public:
	std::vector<byte> oldBytes;
	std::vector<byte> patchBytes;
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