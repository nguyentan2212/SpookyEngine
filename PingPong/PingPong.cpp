// PingPong.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "PingPong.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
    shared_ptr<SpookyApp> pApplication = SpookyApp::GetInstance();

    shared_ptr<CustomGraphic> graphic = CustomGraphic::GetInstance();
    pApplication->SetGraphic(graphic);
    
    if (!pApplication->Initialize(hInstance, "Ping pong game", "PingPongGame", 600, 400))
    {
        // Init failed
        return 0;
    }

    while (pApplication->ProcessMessage())
    {
        pApplication->Update();
        pApplication->Render();
    }

    return 0;
}
