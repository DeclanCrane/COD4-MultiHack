#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#include "EndScene.h"
//#include "Structs.h"
#include "COD4Structs.h"
#include "Offsets.h"

class D3D9Drawing {
private:
	IDirect3DDevice9* pDevice;

	ID3DXLine* line;

	ID3DXFont* font;

	// True if instance has D3D9 device pointer
	bool bSetup;
public:
	D3D9Drawing() : pDevice(nullptr), line(nullptr), font(nullptr), bSetup(false) {};

	~D3D9Drawing();

	bool IsSetup() { return bSetup ? true : false; }

	void Setup(IDirect3DDevice9* pDevice) { this->pDevice = pDevice; bSetup = true; }

	void DrawFilledRect(int screenX, int screenY, int rectWidth, int rectHeight, D3DCOLOR color);

	void DrawLine(int x1, int y1, int x2, int y2, int thickness, const D3DCOLOR &color);

	void DrawLine(const vec2_t &src, const vec2_t &dst, int thickness, const D3DCOLOR &color);

	void DrawEspBox2D(const vec2_t &top, const vec2_t &bottom, int thickness, const D3DCOLOR &color);

	void DrawFont(const char* text, float x, float y, D3DCOLOR color);
};

extern D3D9Drawing drawing;
