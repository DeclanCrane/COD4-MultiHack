#include "Menu.h"

Menu::Menu()
{
	hWnd = nullptr;
	pD3DDevice = nullptr;
	// Has menu been setup
	bSetup = false;
	// Should menu be shown
	bShowMenu = false;
}

Menu::~Menu()
{
	SetWindowLongPtr(this->hWnd, GWL_WNDPROC, (LONG)g_pWndProc);
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
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	
	ImGui::StyleColorsDark();

	SetupImGuiBackend();
	SetupImGuiInput();

	bSetup = true;
}

void Menu::SetupImGuiInput()
{
	// Hook main applications WndProc
	g_pWndProc = (WNDPROC)SetWindowLongPtr(this->hWnd, GWL_WNDPROC, (LONG)WndProc);
}

void Menu::Draw()
{
	ImGui::GetIO().MouseDrawCursor = true;

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow(&bShowMenu);

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

	return CallWindowProc(g_pWndProc, hWnd, uMsg, wParam, lParam);
}