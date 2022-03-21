#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, RECT srcRect, bool isFlipped) : texture(texture),
	srcRect(srcRect), spriteHandler(spriteHandler), isFlipped(isFlipped), Transform2D()
{
}

Sprite::Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, double width, double height, double x, double y, bool isFlipped) :
	texture(texture), spriteHandler(spriteHandler), isFlipped(isFlipped), Transform2D()
{
	srcRect.left = x;
	srcRect.top = y;
	srcRect.right = x + width;
	srcRect.bottom = y + height;
}

void Sprite::Render(Matrix3D transMat, Vector3D camPos)
{
	Vector3D temp = transMat * GetLocalPosition();
	temp = temp - camPos;
	D3DXVECTOR3 pos = D3DXVECTOR3(temp.GetValueX(), temp.GetValueY(), temp.GetValueZ());
	OutputDebugStringW((L"[Sprite]: " + to_wstring(pos.x) + L", " + to_wstring(pos.y) + L"\n").c_str());

	spriteHandler->Draw(texture->GetTexture(), &srcRect, NULL, &pos, D3DCOLOR_XRGB(255, 255, 255));
}
