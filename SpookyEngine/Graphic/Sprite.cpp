#include "Sprite.h"

Sprite::Sprite(LPD3DXSPRITE spriteHandler, shared_ptr<SpriteInfo> info, Vector scaleVec)
{
	this->spriteHandler = spriteHandler;
	this->info = info;
	this->scaleVec = scaleVec;
}

Sprite::Sprite(LPD3DXSPRITE spriteHandler, shared_ptr<SpriteInfo> info, double scaleX, double scaleY)
{
	this->spriteHandler = spriteHandler;
	this->info = info;
	this->scaleVec = Vector(scaleX, scaleY);
}

void Sprite::Render(Matrix transMat)
{
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, scaleVec.GetValueX(), scaleVec.GetValueY(), .0f);
	matScale._43 = zIndex;
	transMat = Matrix::Scaling(scaleVec) * transMat;

	spriteHandler->SetTransform(&matScale);

	Vector temp = transMat * transform.GetLocalPosition();
	D3DXVECTOR3 pos = temp.ToDirectXVector();
	D3DXVECTOR3 center = GetCenter().ToDirectXVector();

	OutputDebugStringW((L"[Sprite]: " + to_wstring(pos.x) + L", " + to_wstring(zIndex) + L"\n").c_str());
	RECT rect = GetSrcRect();
	spriteHandler->Draw(info->texture->GetTexture(), &rect, &center, &pos, D3DCOLOR_XRGB(255, 255, 255));
}

void Sprite::SetZIndex(float zIndex)
{
	this->zIndex = zIndex;
}
