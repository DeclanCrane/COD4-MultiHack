#include "NullSystem.h"

bool GetMonitorSize(HMONITOR hMonitor, Box &res)
{
	MONITORINFO monInfo = {};

	// Get the monitor's information
	monInfo.cbSize = sizeof(MONITORINFO);

	if (!GetMonitorInfo(hMonitor, &monInfo))
		return false;

	// Calculate the monitors actual resolution
	res.width = monInfo.rcMonitor.right - monInfo.rcMonitor.left;
	res.height = monInfo.rcMonitor.bottom - monInfo.rcMonitor.top;

	return true;
}

bool GetWindowSize(HWND hWindow, Box &res)
{
	RECT rcWindow = {};

	// Get the window's coordinates
	if (!GetWindowRect(hWindow, &rcWindow))
		return false;

	// Calculate the window's actual size
	res.width = rcWindow.right - rcWindow.left;
	res.height = rcWindow.bottom - rcWindow.top;

	return true;
}

bool IsWindowFullscreen(HWND hWindow, bool &bFullscreen)
{
	HMONITOR hMonitor = NULL;
	Box monitorSize = {};
	Box windowSize = {};

	// Get the monitor that the window is active on
	// ( in-case there are more than one )
	hMonitor = MonitorFromWindow(hWindow, MONITOR_DEFAULTTONEAREST);
	if (!hMonitor)
		return false;

	// Get the monitor's resolution
	if (!GetMonitorSize(hMonitor, monitorSize))
		return false;

	// Get the target window's resolution
	if (!GetWindowSize(hWindow, windowSize))
		return false;

	if (monitorSize.width == windowSize.width && monitorSize.height == windowSize.height)
	{
		bFullscreen = true;
		return true;
	}

	bFullscreen = false;
	return true;
}

HWND GetCurrentProcessWindow()
{
	WindowData wd{};

	// Get our processes' current window
	wd.processID = GetCurrentProcessId();

	EnumWindows(&EnumWindowsForProcessID, (LPARAM)&wd);

	return wd.hWindow;
}

BOOL CALLBACK EnumWindowsForProcessID(HWND hWindow, LPARAM lParam)
{
	// The process ID belonging to the current window
	DWORD currentWindowProcID = 0;
	GetWindowThreadProcessId(hWindow, &currentWindowProcID);

	if (currentWindowProcID == ((WindowData *)lParam)->processID)
	{
		((WindowData *)lParam)->hWindow = hWindow; // Save the found window
		return FALSE;							   // Found the window!
	}

	return TRUE; // Continue looking...
}
