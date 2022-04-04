#include "StringConverter.h"

std::wstring StringConverter::StringToWide(std::string str)
{
	std::wstring stemp = std::wstring(str.begin(), str.end());
	return stemp;
}