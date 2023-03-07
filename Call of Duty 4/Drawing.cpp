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
	DrawLine(src[0], src[1], dst[0], dst[1], thickness, color);
}

void Drawing_t::DrawEspBox2D(vec2_t top, vec2_t bottom, int thickness, D3DCOLOR color)
{
	int height = ABS(top[1] - bottom[1]);
	vec2_t topLeft, topRight;
	topLeft[0] = top[0] - height / 4;
	topRight[0] = top[0] + height / 4;
	topLeft[1] = topRight[1] = top[1];

	vec2_t bottomLeft, bottomRight;
	bottomLeft[0] = bottom[0] - height / 4;
	bottomRight[0] = bottom[0] + height / 4;
	bottomLeft[1] = bottomRight[1] = bottom[1];

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

bool Drawing_t::WorldToScreen(vec3_t world, vec2_t& screen, RefDef* refdef)
{
	vec3_t Position = {};
	VectorSubtract(world, refdef->vCameraPos, Position);
	vec3_t Transform = {};

	// Get our dot products from viewMatrix
	Transform[0] = DotProduct(Position, refdef->mViewMatrix[1]);
	Transform[1] = DotProduct(Position, refdef->mViewMatrix[2]);
	Transform[2] = DotProduct(Position, refdef->mViewMatrix[0]);


	// Make sure it is in front of us
	if (Transform[2] < 0.01f)
		return false;

	// Get the center of the screen
	vec2_t CenterScreen = {};
	CenterScreen[0] = refdef->width / 2.f;
	CenterScreen[1] = refdef->height / 2.f;

	screen[0] = CenterScreen[0] * (1 - (Transform[0] / refdef->tanHalfFovX / Transform[2]));
	screen[1] = CenterScreen[1] * (1 - (Transform[1] / refdef->tanHalfFovY / Transform[2]));
	return true;
}
