#pragma once

// D3D9 Includes
#include <d3d9.h>
#include <d3dx9.h>
// D3D9 Libraries
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "WindowFinder.lib")

// Detours
#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "WindowFinder.h";

class D3D9Hook
{
public:
	//D3D9 Device
	IDirect3DDevice9*		pDevice;

	//D3D9 Interface
	IDirect3D9*				pDirect3D9;

	//D3D9 Parameters
	D3DPRESENT_PARAMETERS	d3dparams;

	//D3D9 vTable
	void**					vTable;

	// EndScene
	typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);
	endScene				pEndScene; // Original D3D9 EndScene
	endScene				EndSceneDetour; // Detour D3D9 EndScene

	// D3D9 Reset
	typedef HRESULT(__stdcall* Reset)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
	Reset					pReset;	// Original D3D9 Reset
	Reset					ResetDetour; // Detour D3D9 Resetf

public:

	D3D9Hook();
	~D3D9Hook();

	// Setup D3D9 Parameters
	void SetupD3D9Params(HWND window, BOOL isWindowed);

	// Create D3D9 Device
	void CreateD3D9Device(HWND hWindow);

	// Grabs vTable and creates a detour to EndScene and Reset
	void HookEndScene(HWND hWindow, endScene detourFunction, Reset resetFunction);

	// Cleanup
	void CleanD3D9();
};