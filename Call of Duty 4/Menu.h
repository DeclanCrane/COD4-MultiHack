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
	inline static bool bShowMenu = false;
	// Set when menu setup is complete
	inline static bool bSetup = false;
public:
	Menu(const Menu&) = delete; // Don't implement
	void operator=(Menu const&) = delete; // Don't implement

	// Return instance of Menu
	static Menu& Get() { static Menu instance; return instance; }

	void SetupImGui(HWND hWnd, LPDIRECT3DDEVICE9 pD3DDevice);
	// Pass in your own ImGui menu code to be drawn
	void Draw(void(*myMenu)());
	inline WNDPROC GetWndProc() { return pWndProc; }
	static bool ToggleMenu() { bShowMenu = !bShowMenu; return bShowMenu; }
	static bool IsOpen() { return bShowMenu ? true : false; }
	void Destroy();
private:
	Menu() :hWnd(nullptr), pD3DDevice(nullptr), pWndProc(nullptr) {}
	~Menu();
	void SetupImGuiInput();
	void SetupImGuiBackend();
};