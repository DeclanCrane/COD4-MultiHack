#include "NullHooks.h"

Patch::Patch(void* src, std::vector<byte> bytes)
{
	this->src = src;

	patchBytes.resize(bytes.size());
	oldBytes.resize(bytes.size());

	this->patchBytes = bytes;
	this->size = bytes.size();

	// Copy the original bytes for later
	memcpy(&oldBytes[bytes.size() - size], src, size);
}

void Patch::Set()
{
	DWORD oldProtect = 0;
	// Install our patch
	VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
	memcpy(src, &patchBytes[patchBytes.size() - size], size);
	VirtualProtect(src, size, oldProtect, NULL);
}

void Patch::Restore()
{
	DWORD oldProtect = 0;
	// Restore our patch
	VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
	memcpy(src, &oldBytes[oldBytes.size() - size], size);
	VirtualProtect(src, size, oldProtect, NULL);
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
	DWORD oldProtect = 0;
	std::vector<byte> patch{};
	// Sets patch to the size, and initializes with 0x90 (NOP)
	patch.resize(size, 0x90);

	// Set the patch
	VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
	memcpy(src, &patch[0], size);
	VirtualProtect(src, size, oldProtect, &oldProtect); // Save oldProtect again just to avoid warning
}

void Nop::Restore()
{
	DWORD oldProtect = 0;
	// Restore the patch
	VirtualProtect(src, size, PAGE_READWRITE, &oldProtect);
	memcpy(src, &original[0], size);
	VirtualProtect(src, size, oldProtect, &oldProtect); // Save oldProtect again just to avoid warning
}
