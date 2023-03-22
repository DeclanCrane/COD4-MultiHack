#pragma once
#include <Windows.h>
#include <d3d9.h>

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx9.h"

// Forward declared for ImGui input handling
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Menu {
private:
	HWND hWnd;
	LPDIRECT3DDEVICE9 pD3DDevice;
	// Main application's WndProc
	WNDPROC pWndProc;
	// Weither ImGui menu is to be shown
	bool bShowMenu;
	// Set when menu setup is complete
	bool bSetup;
public:
	Menu(const Menu&) = delete; // Don't implement
	void operator=(Menu const&) = delete; // Don't implement

	static Menu& Get() { static Menu instance; return instance; }
	void SetupImGui(HWND hWnd, LPDIRECT3DDEVICE9 pD3DDevice);
	void Draw();
	inline WNDPROC GetWndProc() { return pWndProc; }
	inline bool ToggleMenu() { bShowMenu = !bShowMenu; return bShowMenu; }
	inline bool IsOpen() { return bShowMenu ? true : false; }
private:
	Menu();
	~Menu();
	void SetupImGuiInput();
	void SetupImGuiBackend();
};