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
    shared_ptr<Graphic> graphic = Graphic::GetInstance();
    if (!pApplication->Initialize(hInstance, "Ping pong game", "PingPongGame", 630, 450))
    {
        // Init failed
        return 0;
    }
    shared_ptr<CustomScene> scene = shared_ptr<CustomScene>(new CustomScene());
    scene->Initialize();
    pApplication->AddScene(scene);
    while (pApplication->ProcessMessage())
    {
        pApplication->Update();
        pApplication->Render();
    }

    return 0;
}
