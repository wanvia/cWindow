#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;
	MSG msg;
	// TCHAR szWindowClass[] = TEXT("Sample02");

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("Sample02");
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&wc);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("レジスタークラス"), TEXT(""), MB_OK);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_ACCEPTFILES, TEXT("Sample02"), TEXT("lol"), WS_OVERLAPPEDWINDOW, 0, 0, 530, 230, NULL, NULL, hInst, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, TEXT("cre"), TEXT(""), MB_OK);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}