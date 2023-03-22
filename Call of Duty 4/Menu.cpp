#include "Menu.h"

Menu::Menu()
{
	hWnd = nullptr;
	pD3DDevice = nullptr;
	pWndProc = nullptr;
	// Has menu been setup
	bSetup = false;
	// Should menu be shown
	bShowMenu = false;
}

Menu::~Menu()
{
	SetWindowLongPtr(this->hWnd, GWL_WNDPROC, (LONG)pWndProc);
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void Menu::SetupImGui(HWND hWnd, LPDIRECT3DDEVICE9 pD3DDevice)
{
	this->hWnd = hWnd;
	this->pD3DDevice = pD3DDevice;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	// Hardcore config flags for now
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	
	// Hardcode style for now
	ImGui::StyleColorsDark();

	SetupImGuiBackend();
	SetupImGuiInput();

	bSetup = true;
}

void Menu::SetupImGuiInput()
{
	// Hook main application's WndProc
	pWndProc = (WNDPROC)SetWindowLongPtr(this->hWnd, GWL_WNDPROC, (LONG)WndProc);
}

void Menu::Draw(void(*myMenu)())
{
	ImGui::GetIO().MouseDrawCursor = true;

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	myMenu();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void Menu::SetupImGuiBackend()
{
	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX9_Init(pD3DDevice);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	Menu& menu = Menu::Get();
	return CallWindowProc(menu.GetWndProc(), hWnd, uMsg, wParam, lParam);
}