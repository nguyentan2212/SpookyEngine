#include "SpookyApp.h"

shared_ptr<SpookyApp> SpookyApp::instance = nullptr;

SpookyApp::SpookyApp() 
{
	pWindow = shared_ptr<SpookyWindow>(new SpookyWindow());
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

    if (graphic == nullptr || !graphic->Initialize(this->pWindow->GetHWND(), width, height))
        return false;

    return true;
}

bool SpookyApp::ProcessMessage()
{
    return pWindow->ProcessMessages();
}

void SpookyApp::Update() 
{
	graphic->UpdateScene(timer.GetMilisecondsDelta());
}

void SpookyApp::Render() 
{
	graphic->Render();
}

void SpookyApp::SetGraphic(shared_ptr<Graphic> graphic)
{
	this->graphic = graphic;
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
