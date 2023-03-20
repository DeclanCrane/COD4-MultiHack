#pragma once
#include <Windows.h>
#include <d3d9.h>

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx9.h"

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static WNDPROC g_pWndProc;

class Menu {
	HWND hWnd;
	LPDIRECT3DDEVICE9 pD3DDevice;
public:
	bool bSetup;
	bool bShowMenu;
public:
	Menu();
	~Menu();
	void SetupImGui(HWND hWnd, LPDIRECT3DDEVICE9 pD3DDevice);
	// Change this to take a callback
	void Draw();
private:
	void SetupImGuiInput();
	void SetupImGuiBackend();
};