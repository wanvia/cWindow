#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UNIT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	LPCTSTR firstWindow = "testWindow"
	WNDCLASSEX wc;

	ZeroMemory((LPVOID)&wc, sizeof(WNDCLASSEX));

	wc.cdSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cdClsExtra = 0;
	wc.cdWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = firstWindow;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);


	hWnd = CreateWindow(firstWindow, "mp3chenger", WS_OVERLAPPEDWINDOW,
		0,0
		530,230,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0) == 1)
	{
		TransLateMassage(&msg);
		DispatchMessage(&msg);
	}
}
