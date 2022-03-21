#pragma once
#include <string>
#include "Core/Camera2D.h"
#include "Keyboard/KeyboardClass.h"
#include "Utils/StringConverter.h"

using namespace::std;

class CustomCamera :public Camera2D
{
public:
	CustomCamera(double top, double left, double width, double height, double _near, double _far) : Camera2D(top, left, width, height, _near, _far) {}

	void Update(double delta);
};

