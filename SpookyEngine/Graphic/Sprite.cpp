#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, RECT srcRect, bool isFlipped) : texture(texture),
	srcRect(srcRect), spriteHandler(spriteHandler), isFlipped(isFlipped), Drawable2D()
{
	
}

Sprite::Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, double width, double height, double x, double y, bool isFlipped) :
	texture(texture), spriteHandler(spriteHandler), isFlipped(isFlipped), Drawable2D()
{
	srcRect.left = x;
	srcRect.top = y;
	srcRect.right = x + width;
	srcRect.bottom = y + height;
}

void Sprite::Render(Matrix transMat)
{
	D3DXMATRIX matScale;
	if (isFlipped)
	{
		D3DXMatrixScaling(&matScale, -1.0f, 1.0f, .0f);
		transMat = Matrix::Scaling(Vector(-1, 1, 0)) * transMat;
	}
	else {
		D3DXMatrixScaling(&matScale, 1.0f, 1.0f, .0f);
	}
	spriteHandler->SetTransform(&matScale);
	Vector temp = transMat * transform.GetLocalPosition();
	D3DXVECTOR3 pos = D3DXVECTOR3(temp.GetValueX(), temp.GetValueY(), 0);
	OutputDebugStringW((L"[Sprite]: " + to_wstring(pos.x) + L", " + to_wstring(pos.y) + L"\n").c_str());

	spriteHandler->Draw(texture->GetTexture(), &srcRect, NULL, &pos, D3DCOLOR_XRGB(255, 255, 255));
}
