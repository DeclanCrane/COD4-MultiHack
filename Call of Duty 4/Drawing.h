#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#include "EndScene.h"
//#include "Structs.h"
#include "COD4Structs.h"
#include "Offsets.h"

class Drawing_t {
public:
	IDirect3DDevice9 * pDevice;

	ID3DXLine* lineL;

	ID3DXFont* font;

	Drawing_t();

	~Drawing_t();

	void DrawFilledRect(int screenX, int screenY, int rectWidth, int rectHeight, D3DCOLOR color);

	void DrawLine(int x1, int y1, int x2, int y2, int thickness, const D3DCOLOR &color);

	void DrawLine(const vec2_t &src, const vec2_t &dst, int thickness, const D3DCOLOR &color);

	void DrawEspBox2D(const vec2_t &top, const vec2_t &bottom, int thickness, const D3DCOLOR &color);

	void DrawFont(const char* text, float x, float y, D3DCOLOR color);
};

extern Drawing_t Drawing;
