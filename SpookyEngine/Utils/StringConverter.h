#pragma once
#include <string>
#include <d3d9.h>
class StringConverter
{
public:
	static std::wstring StringToWide(std::string str);
};

