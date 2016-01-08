//win main
//win proc

//start game

#include <windows.h>
#include "game.h"
//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
HINSTANCE               hInst = NULL;
HWND                    hWnd = NULL;
Game*                   game = NULL;
HRESULT InitWindow (HINSTANCE hInstance, int nCmdShow);

int WINAPI wWinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    UNREFERENCED_PARAMETER (hPrevInstance);
    UNREFERENCED_PARAMETER (lpCmdLine);

    if (FAILED (InitWindow (hInstance, nCmdShow)))
        return 0;


    //Create game
    game = new Game;

    // Main message loop
    MSG msg = {0};
    while (WM_QUIT != msg.message) {
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage (&msg);
            DispatchMessage (&msg);
        } else {
            //Render();
        }
    }
}

LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
        case WM_PAINT:
            hdc = BeginPaint (hWnd, &ps);
            EndPaint (hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage (0);
            break;

        default:
            return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}

HRESULT InitWindow (HINSTANCE hInstance, int nCmdShow) {
    // Register class
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof (WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    //wcex.hIcon = LoadIcon( hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor (NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "Game";
    //wcex.hIconSm = LoadIcon( wcex.hInstance, ( LPCTSTR )IDI_TUTORIAL1 );
    wcex.hIconSm = NULL;
    if (!RegisterClassEx (&wcex))
        return E_FAIL;

    // Create window
    hInst = hInstance;
    RECT rc = { 0, 0, 640, 480 };
    AdjustWindowRect (&rc, WS_OVERLAPPEDWINDOW, FALSE);
    hWnd = CreateWindow ("Game", "Direct3D 11 Game", WS_OVERLAPPEDWINDOW,
                         CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
                         NULL);
    if (!hWnd)
        return E_FAIL;

    ShowWindow (hWnd, nCmdShow);

    return S_OK;
}