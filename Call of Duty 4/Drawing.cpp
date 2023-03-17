#include "Drawing.h"
#include <iostream>

Drawing_t Drawing;

Drawing_t::Drawing_t()
{
	pDevice		= nullptr;
	lineL		= nullptr;
	font		= nullptr;
}

Drawing_t::~Drawing_t()
{
	if(lineL)
		lineL->Release();

	if(font)
		font->Release();
}

void Drawing_t::DrawFilledRect(int screenX, int screenY, int rectWidth, int rectHeight, D3DCOLOR color)
{
	D3DRECT rect = { screenX, screenY, screenX + rectWidth, screenY + rectHeight };
	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
}

void Drawing_t::DrawLine(int x1, int y1, int x2, int y2, int thickness, D3DCOLOR color)
{
	// Only creates line once
	if(!lineL)
		D3DXCreateLine(pDevice, &lineL);

	D3DXVECTOR2 Line[2];

	Line[0] = D3DXVECTOR2(x1, y1);
	Line[1] = D3DXVECTOR2(x2, y2);

	lineL->SetWidth(thickness);
	lineL->Draw(Line, 2, color);
}

void Drawing_t::DrawLine(vec2_t src, vec2_t dst, int thickness, D3DCOLOR color)
{
	DrawLine(src.x, src.y, dst.x, dst.y, thickness, color);
}

void Drawing_t::DrawEspBox2D(const vec2_t &top, const vec2_t &bottom, int thickness, D3DCOLOR color)
{
	int height = ABS(top.y - bottom.y);
	vec2_t topLeft, topRight;
	topLeft.x = top.x - height * 0.25;
	topRight.x = top.x + height * 0.25;
	topLeft.y = topRight.y = top.y;

	vec2_t bottomLeft, bottomRight;
	bottomLeft.x = bottom.x - height * 0.25;
	bottomRight.x = bottom.x + height * 0.25;
	bottomLeft.y = bottomRight.y = bottom.y;

	DrawLine(topLeft, topRight, thickness, color);
	DrawLine(bottomLeft, bottomRight, thickness, color);
	DrawLine(topLeft, bottomLeft, thickness, color);
	DrawLine(topRight, bottomRight, thickness, color);
}

void Drawing_t::DrawFont(const char* text, float x, float y, D3DCOLOR color)
{
	// Only creates font once
	if(!font)
		D3DXCreateFont(pDevice, 14, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, 
			OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial", &font);

	RECT rect;

	// Draw shadow behind text
	SetRect(&rect, x + 1, y + 1, x + 1, y + 1);
	font->DrawTextA(NULL, text, -1, &rect, DT_CENTER | DT_NOCLIP, D3DCOLOR_ARGB(255, 0, 0, 0));

	SetRect(&rect, x, y, x, y);
	font->DrawTextA(NULL, text, -1, &rect, DT_CENTER | DT_NOCLIP, color);
}
