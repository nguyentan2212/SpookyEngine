#include "Texture.h"

Texture::Texture(LPDIRECT3DDEVICE9 d3ddev, LPCWSTR filePath, D3DCOLOR transparentColor) : transparentColor(transparentColor)
{
	HRESULT hr;

	hr = D3DXGetImageInfoFromFile(filePath, &info);

	if (hr != D3D_OK)
	{
		_com_error err(hr);
		LPCTSTR errMsg = err.ErrorMessage();
		MessageBox(NULL, L"Failed to get information from image file", L"Error", MB_OK);
		return;
	}

	hr = D3DXCreateTextureFromFileEx(
		d3ddev,                   // device liên kết với texture 
		filePath,		      // đường dẫn của sprite
		info.Width,			      // chiều dài của sprite
		info.Height,		      // chiều rộng của sprite
		1,
		D3DPOOL_DEFAULT,	      // kiểu surface
		D3DFMT_UNKNOWN,	          // định dạng surface
		D3DPOOL_DEFAULT,	      // lớp bộ nhớ cho texture
		D3DX_DEFAULT,		      // bộ lọc ảnh
		D3DX_DEFAULT,		      // bộ lọc mip
		transparentColor,   // chỉ ra màu trong suốt
		&info,			          // thông tin của sprite
		NULL,			          // đổ màu
		&texture			      // texture sẽ chứa sprite
	);

	if (hr != D3D_OK)
	{
		MessageBox(NULL, L"Failed to create texture from file", L"Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}
}
