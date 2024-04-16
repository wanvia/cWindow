#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	LPCTSTR firstWindow;
	WNDCLASSEX wc;

	ZeroMemory((LPVOID)&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = null;
	wc.lpszClassName = firstWindow;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);

	hWnd = CreateWindow(firstWindow, lol, WS_OVERLAPPEDWINDOW, 0, 0, 530, 230, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOW);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0) == 1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
