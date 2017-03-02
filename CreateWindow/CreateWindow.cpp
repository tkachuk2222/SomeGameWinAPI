// CreateWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "CreateWindow.h"
#include<vector>
using std::vector;
#define MAX_LOADSTRING 100
#define WM_START WM_USER+1
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND cntOfButt;
HWND ParentWindow;
INT radioCheck = 1;
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    CountOfButton(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	hInst = hInstance;
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, About);
	ShowWindow(cntOfButt, SW_SHOW);
//	return 0;
	MSG msg;
	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{


		DispatchMessage(&msg);

	}

	return (int)msg.wParam;
}





INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	ParentWindow = hDlg;
	INT x = 70, y = 10, nWidth = 70, nHeight = 70;
	//static INT radioCheck;
	static HWND hBut1, hBut2, hBut3, hBut4, hBut5, hBut6, hBut7, hBut8, hBut9, hBut10, hBut11, hBut12, hBut13, hBut14, hBut15, hBut16;
	static vector<HWND> hBut;
	UNREFERENCED_PARAMETER(lParam);
    switch (message)
	{
    case WM_INITDIALOG:
	//	radioCheck = 1;

		//CreateWindow()
        return (INT_PTR)TRUE;
	case WM_START:{
		MessageBox(hDlg, L"Yes", L"yees", MB_OK);
		}
	case WM_CLOSE:
	{
		EndDialog(hDlg, LOWORD(wParam));
		
		return (INT_PTR)TRUE;
	}
	case WM_COMMAND: 
	
	{
		if(LOWORD(wParam) == IDC_BUTTON1)
		{

			cntOfButt = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, CountOfButton);
			ShowWindow(cntOfButt, SW_SHOW);
			if (radioCheck == 1) {
				for (int i = 1; i < 10;++i) {
					if (i == 4||) {					//////////тут доробити
						y += 80;
					}
					hBut.push_back((CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL)));
				}
			}
			/*hBut1 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 70, 10, 70, 70, hDlg, NULL, hInst, NULL);
			hBut2 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 150, 10, 70, 70, hDlg, NULL, hInst, NULL);
			hBut3 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 220, 10, 70, 70, hDlg, NULL, hInst, NULL);
			hBut4 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 280, 10, 70, 70, hDlg, NULL, hInst, NULL);
			hBut5 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut6 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut7 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut8 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut9 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut10 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut11 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut12 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut13 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut14 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut15 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);
			hBut16 = CreateWindow(L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_TABSTOP, 10, 10, 50, 50, hDlg, NULL, hInst, NULL);*/

		return (INT_PTR)TRUE;}


		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}

		}
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK    CountOfButton(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG: {
		radioCheck = 1;
		CheckRadioButton(hDlg, IDC_RADIO1, IDC_RADIO3, IDC_RADIO1);
		return (INT_PTR)TRUE;
	}

	case WM_CLOSE:
	{
		DestroyWindow(hDlg);
		cntOfButt = NULL;
		return (INT_PTR)TRUE;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		SendMessage(hDlg, WM_CLOSE, 0, 0);

		return (INT_PTR)TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_RADIO1: {
			::radioCheck = 1;
		}return (INT_PTR)TRUE;
		case IDC_RADIO2: {
			::radioCheck = 2;
		}return (INT_PTR)TRUE;
		case IDC_RADIO3: {
			::radioCheck = 3;
		}return (INT_PTR)TRUE;
		case IDC_BUTTON1: {
			SendMessage(ParentWindow, WM_START, 0, 0);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		}
		/*if (LOWORD(wParam) == IDC_BUTTON1)
		{
		hModeless = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hDlg, Modeless);
		return (INT_PTR)TRUE;
		}*/
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			//EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}