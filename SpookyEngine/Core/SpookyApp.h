#pragma once
#include <windows.h>
#include <memory>
#include <string>
#include "Timer.h"
#include "SpookyWindow.h"
#include "ResourceLocator.h"
#include "../Keyboard/KeyboardClass.h"
#include "../Graphic/Graphic.h"
#include "Camera2D.h"
#include "Scene.h"

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

	void AddScene(shared_ptr<Scene> scene);
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	Timer timer;
	Matrix coordinateMatrix;
	shared_ptr<SpookyWindow> pWindow;
	vector<shared_ptr<Scene>> scenes;
	int currentScene = 0;
	SpookyApp();
	double lag = 0;
	double const MS_PER_UPDATE = 1000.0 / 30.0;
	static shared_ptr<SpookyApp> instance;
};

