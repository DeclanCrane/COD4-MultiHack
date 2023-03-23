#include "D3D9Hook.h"

D3D9HookNew::_EndScene D3D9HookNew::pEndScene;
D3D9HookNew::_Reset D3D9HookNew::pReset;

D3D9HookNew::_EndSceneCallback D3D9HookNew::EndSceneCallback;
D3D9HookNew::_ResetCallback D3D9HookNew::ResetCallback;

IDirect3DDevice9* D3D9HookNew::pDevice;

HRESULT __stdcall D3D9HookNew::EndSceneDetour(IDirect3DDevice9* pDevice)
{
	// Update pDevice
	D3D9HookNew::pDevice = pDevice;

	EndSceneCallback(pDevice);
	return pEndScene(pDevice);
}

HRESULT __stdcall D3D9HookNew::ResetDetour(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	ResetCallback(pDevice, pPresentationParameters);
	return pReset(pDevice, pPresentationParameters);
}

D3D9HookNew::D3D9HookNew(HWND hWindow) : d3dParams(), vTable(nullptr), hWindow(hWindow)
{
	pDirect3D9 = Direct3DCreate9(D3D_SDK_VERSION);
}

D3D9HookNew::~D3D9HookNew()
{
	Uninstall();
}

void D3D9HookNew::Install(void(*EndSceneCallback)(IDirect3DDevice9* pDevice), void(*ResetCallback)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters))
{
	bool bFullscreen = false;

	// Set callbacks
	this->EndSceneCallback = (_EndSceneCallback)EndSceneCallback;
	this->ResetCallback = (_ResetCallback)ResetCallback;

	// If a window wasn't passed in constructor
	if(!this->hWindow)
		this->hWindow = GetCurrentProcessWindow();

	IsWindowFullscreen(hWindow, bFullscreen);

	// Create D3D Params
	d3dParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dParams.hDeviceWindow = hWindow;
	d3dParams.Windowed = !bFullscreen; // bFullscreen is true if in fullscreen

	// Create temporary D3D9 Device
	pDirect3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &this->pDevice);
	if (!pDevice) {
		pDirect3D9->Release();
		return;
	}

	// Get the vTable
	this->vTable = *reinterpret_cast<void***>(this->pDevice);

	// Create Detours
	pEndScene = (_EndScene)DetourFunction((PBYTE)vTable[42], (PBYTE)EndSceneDetour);
	pReset = (_Reset)DetourFunction((PBYTE)vTable[16], (PBYTE)ResetDetour);

	// Release our temporary D3D9 interfaces
	pDevice->Release();
	pDirect3D9->Release();

	/* 
		" The Magic Sleep "
		Makes sure pDevice is updated in the other thread?
		Don't know why, but it works.

		The new version of MS-Detours probably solves this issue with Detour Transactions.
		It's probably a good idea to update...
	*/
	Sleep(100);
}

void D3D9HookNew::Uninstall()
{
	DetourRemove((PBYTE)pEndScene, (PBYTE)EndSceneDetour);
	DetourRemove((PBYTE)pReset, (PBYTE)ResetDetour);
}
