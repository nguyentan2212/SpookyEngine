#pragma once
#include <windows.h>
#include <memory>
#include <string>
#include "Timer.h"
#include "SpookyWindow.h"
#include "../Keyboard/KeyboardClass.h"
#include "../Graphic/Graphic.h"

class SpookyWindow;
class SpookyApp
{
public:
	SpookyApp(SpookyApp&) = delete;
	void operator=(SpookyApp&) = delete;
	static shared_ptr<SpookyApp> GetInstance();

	bool Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
	bool ProcessMessage();
	void Update();
	void Render();

	void SetGraphic(shared_ptr<Graphic> graphic);

	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	Timer timer;
	shared_ptr<SpookyWindow> pWindow;
	shared_ptr<Graphic> graphic;
	SpookyApp();
	static shared_ptr<SpookyApp> instance;
};

