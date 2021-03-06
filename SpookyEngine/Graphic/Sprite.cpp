#include "Sprite.h"

Sprite::Sprite(shared_ptr<SpriteInfo> info, Vector scale)
{
	this->info = info;
	this->scale = scale;
}

void Sprite::Render(Matrix transMat)
{
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, scale.GetValueX() * SCALE, scale.GetValueY() * SCALE, .0f);
	matScale._43 = zIndex;

	transMat = Matrix::Scaling(scale / SCALE) * transMat;
	Vector position = transMat * transform.GetPosition();
	Vector center = GetCenter();
	RECT rect = GetSrcRect();

	// OutputDebugStringW((L"[Sprite]: " + to_wstring(position.GetValueX()) + L", " + to_wstring(zIndex) + L"\n").c_str());
	
	shared_ptr<Graphic> graphic = Graphic::GetInstance();
	graphic->Draw(info, rect, center, position, matScale);
}

void Sprite::SetZIndex(float zIndex)
{
	this->zIndex = zIndex;
}
