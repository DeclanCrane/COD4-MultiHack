#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "NullSystem.h"

class D3D9HookNew {
	//D3D9 Device
	static IDirect3DDevice9* pDevice;
	//D3D9 Interface
	IDirect3D9* pDirect3D9;
	//D3D9 Present Params
	D3DPRESENT_PARAMETERS d3dParams;
	//D3D9 vTable
	void** vTable;
	
	// Application window
	HWND hWindow;

	typedef HRESULT(__stdcall* _EndScene)(IDirect3DDevice9* pDevice);
	static _EndScene pEndScene; // EndScene Trampoline

	typedef HRESULT(__stdcall* _Reset)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
	static _Reset pReset; // EndScene Trampoline

	typedef void(*_EndSceneCallback)(IDirect3DDevice9* pDevice);
	static _EndSceneCallback EndSceneCallback;

	typedef void(*_ResetCallback)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
	static _ResetCallback ResetCallback;

	// EndScene Detour
	static HRESULT __stdcall EndSceneDetour(IDirect3DDevice9* pDevice);
	// Reset Detour
	static HRESULT __stdcall ResetDetour(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
public:
	D3D9HookNew(HWND hWindow = nullptr);
	~D3D9HookNew();
	void Install(void(*EndSceneCallback)(IDirect3DDevice9* pDevice), void(*ResetCallback)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters));
	void Uninstall();
	IDirect3DDevice9* GetDevice() { return this->pDevice; }
};