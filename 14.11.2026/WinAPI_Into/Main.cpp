#include <windows.h>

#define ID_EDIT 1
#define ID_BUTTON 2

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"IntoinWinAPIClass";
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, L"Failed to register window class", L"Error", MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME, L"Перший віконний застосунок", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    {
        HINSTANCE hInstance = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);

        CreateWindowEx(
            WS_EX_CLIENTEDGE,
            L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            50, 30,
            300, 30,
            hwnd, (HMENU)ID_EDIT, hInstance, NULL);

        CreateWindowEx(
            0,
            L"BUTTON", L"Натисни!",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 70,
            300, 30,
            hwnd, (HMENU)ID_BUTTON, hInstance, NULL);

        return 0;
    }
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        if (wmId == ID_BUTTON) {
            wchar_t buffer[256];
            GetDlgItemText(hwnd, ID_EDIT, buffer, 256);
            MessageBox(hwnd, buffer, L"Ви ввели наступне: ", MB_OK | MB_ICONINFORMATION);
        }
        return 0;
    }

    case WM_KEYDOWN:
    {
        if (wParam == VK_SPACE) {
            HWND hButton = GetDlgItem(hwnd, ID_BUTTON);

            if (hButton) {
                SetWindowPos(hButton, NULL, 50, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
            }
        }
        return 0;
    }

    case WM_LBUTTONDOWN:
        MessageBox(hwnd, L"Ви натиснули ліву кнопку миші!", L"Повідомлення", MB_ICONINFORMATION);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}