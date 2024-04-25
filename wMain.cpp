#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = (HICON)LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _T("firstWindow");
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);

 if(!RegisterApp(_T("firstWindow", DefWindowProcA)) return 0;

	hWnd = CreateWindowEx(0, _T("firstWindow), _T("lol"), WS_OVERLAPPEDWINDOW, 0, 0, 530, 230, NULL, NULL, hInstance, NULL);

	if(hWnd == NULL) return 0;

	ShowWindow(hWnd, SW_SHOW);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0) == 1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

	LRESULT CALLBACK WindowProc(HWND hWnd, UNIT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch( uMsg )
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}