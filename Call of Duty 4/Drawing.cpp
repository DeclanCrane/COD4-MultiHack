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

void Drawing_t::DrawEspBox2D(vec2_t top, vec2_t bottom, int thickness, D3DCOLOR color)
{
	int height = ABS(top.y - bottom.y);
	vec2_t topLeft, topRight;
	topLeft.x = top.x - height / 4;
	topRight.x = top.x + height / 4;
	topLeft.y = topRight.y = top.y;

	vec2_t bottomLeft, bottomRight;
	bottomLeft.x = bottom.x - height / 4;
	bottomRight.x = bottom.x + height / 4;
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

bool Drawing_t::WorldToScreen(vec3_t world, vec2_t& screen, RefDef* refdef)
{
	vec3_t Position;
	Position = world - refdef->vCameraPos;
	vec3_t Transform;

	// Get our dot products from viewMatrix
	Transform.x = Position.DotProduct(refdef->mViewMatrix[1]);
	Transform.y = Position.DotProduct(refdef->mViewMatrix[2]);
	Transform.z = Position.DotProduct(refdef->mViewMatrix[0]);


	// Make sure it is in front of us
	if (Transform.z < 0.01f)
		return false;

	// Get the center of the screen
	vec2_t CenterScreen;
	CenterScreen.x = refdef->width / 2.f;
	CenterScreen.y = refdef->height / 2.f;

	screen.x = CenterScreen.x * (1 - (Transform.x / refdef->tanHalfFovX / Transform.z));
	screen.y = CenterScreen.y * (1 - (Transform.y / refdef->tanHalfFovY / Transform.z));
	return true;
}
