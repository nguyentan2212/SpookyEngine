#include "SpookyApp.h"

shared_ptr<SpookyApp> SpookyApp::instance = nullptr;

SpookyApp::SpookyApp() 
{
	pWindow = shared_ptr<SpookyWindow>(new SpookyWindow());
	scenes = vector<shared_ptr<Scene>>(0);
}

shared_ptr<SpookyApp> SpookyApp::GetInstance()
{
	if (instance == nullptr) 
	{
		instance = shared_ptr<SpookyApp>(new SpookyApp());
	}
	return instance;
}

bool SpookyApp::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
    timer.Start();

	// init windows
    if (!pWindow->Initialize(hInstance, window_title, window_class, width, height))
        return false;

	shared_ptr<Graphic> graphic = Graphic::GetInstance();
    if (graphic == nullptr || !graphic->Initialize(this->pWindow->GetHWND(), width, height))
        return false;

	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	locator->Initialize();

	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	camera->Initialize(0, 0, width, height);

	coordinateMatrix = Matrix::Translation(Vector(0, height));
	coordinateMatrix.SetValueAt(1, 1, -1);

    return true;
}

bool SpookyApp::ProcessMessage()
{
    return pWindow->ProcessMessages();
}

void SpookyApp::Update() 
{
	if (scenes.size() == 0)
	{
		return;
	}
	double delta = timer.GetMilisecondsDelta();
	lag += delta;
	while (lag >= MS_PER_UPDATE)
	{
		scenes[currentScene]->Update(delta);
		lag -= MS_PER_UPDATE;
	}
	
}

void SpookyApp::Render() 
{
	if (scenes.size() == 0)
	{
		return;
	}
	scenes[currentScene]->Render();
}

void SpookyApp::AddScene(shared_ptr<Scene> scene)
{
	scene->Initialize(coordinateMatrix);
	scenes.push_back(scene);
}

LRESULT SpookyApp::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	shared_ptr<KeyboardClass> keyboard = KeyboardClass::GetInstance();
    switch (uMsg)
    {
	case WM_KEYDOWN:
	{
		unsigned char keycode = static_cast<unsigned char>(wParam);
		if (keyboard->IsKeysAutoRepeat())
		{
			keyboard->OnKeyPressed(keycode);
		}
		else
		{
			const bool wasPressed = lParam & 0x40000000;
			if (!wasPressed)
			{
				keyboard->OnKeyPressed(keycode);
			}
		}
		return 0;
	}
	case WM_KEYUP:
	{
		unsigned char keycode = static_cast<unsigned char>(wParam);
		keyboard->OnKeyReleased(keycode);
		return 0;
	}
	case WM_CHAR:
	{
		unsigned char ch = static_cast<unsigned char>(wParam);
		if (keyboard->IsCharsAutoRepeat())
		{
			keyboard->OnChar(ch);
		}
		else
		{
			const bool wasPressed = lParam & 0x40000000;
			if (!wasPressed)
			{
				keyboard->OnChar(ch);
			}
		}
		return 0;
	}
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
