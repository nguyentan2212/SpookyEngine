#include "Sprite.h"

Sprite::Sprite(shared_ptr<SpriteInfo> info, Vector scaleVec)
{
	this->info = info;
	this->scaleVec = scaleVec;
}

Sprite::Sprite(shared_ptr<SpriteInfo> info, double scaleX, double scaleY)
{
	this->info = info;
	this->scaleVec = Vector(scaleX, scaleY);
}

void Sprite::Render(Matrix transMat)
{
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, scaleVec.GetValueX(), scaleVec.GetValueY(), .0f);
	matScale._43 = zIndex;

	transMat = Matrix::Scaling(scaleVec) * transMat;
	Vector position = transMat * transform.GetLocalPosition();
	Vector center = GetCenter();
	RECT rect = GetSrcRect();

	OutputDebugStringW((L"[Sprite]: " + to_wstring(position.GetValueX()) + L", " + to_wstring(zIndex) + L"\n").c_str());
	
	shared_ptr<Graphic> graphic = Graphic::GetInstance();
	graphic->Draw(info, rect, center, position, matScale);
}

void Sprite::SetZIndex(float zIndex)
{
	this->zIndex = zIndex;
}
