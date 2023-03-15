#include "NullHooks.h"

Patch::Patch(void* src, std::vector<byte> bytes)
{
	this->src = src;

	patch.resize(bytes.size());
	original.resize(bytes.size());

	this->patch = bytes;
	this->size = bytes.size();

	// Copy the original bytes for later
	memcpy(&original[0], src, size);
}

void Patch::Set()
{
	// Install our patch
	DWORD oldProtect = 0;
	VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
	memcpy(src, &patch[0], size);
	VirtualProtect(src, size, oldProtect, &oldProtect);
}

void Patch::Restore()
{
	// Restore our patch
	DWORD oldProtect = 0;
	VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
	memcpy(src, &original[0], size);
	VirtualProtect(src, size, oldProtect, &oldProtect);
}

Nop::Nop(void* src, size_t size)
{
	this->src = src;
	this->size = size;

	original.resize(size);

	// Save the original bytes for later
	memcpy(&original[0], src, size);
}

void Nop::Set()
{
	DWORD origProtection = 0;
	std::vector<byte> patch{};
	// Sets patch to the size, and initializes with 0x90 (NOP)
	patch.resize(size, 0x90);

	// Set the patch
	VirtualProtect(src, size, PAGE_READWRITE, &origProtection);
	memcpy(src, &patch[0], size);
	VirtualProtect(src, size, origProtection, &origProtection); // Save oldProtect again just to avoid warning
}

void Nop::Restore()
{
	DWORD origProtection = 0;
	// Restore the patch
	VirtualProtect(src, size, PAGE_READWRITE, &origProtection);
	memcpy(src, &original[0], size);
	VirtualProtect(src, size, origProtection, &origProtection); // Save oldProtect again just to avoid warning
}

void PrintMemory(void* src, size_t size, bool bNewLine)
{
	std::vector<byte> bytes{};
	bytes.resize(size);

	memcpy(&bytes[bytes.size() - size], src, size);

	for (int i = 0; i < size; i++) {
		std::cout << "0x" << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << (int)bytes.at(i) << " ";
	}

	if(bNewLine)
		std::cout << "\n";
}
