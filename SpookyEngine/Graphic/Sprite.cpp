#include "Sprite.h"

Sprite::Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, RECT srcRect) : texture(texture), 
	srcRect(srcRect), spriteHandler(spriteHandler), Transform2D()
{
}

Sprite::Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, double width, double height, double x, double y) : 
	texture(texture), spriteHandler(spriteHandler), Transform2D()
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

	spriteHandler->Draw(texture->GetTexture(), &srcRect, NULL, &pos, D3DCOLOR_XRGB(255, 255, 255));
}
