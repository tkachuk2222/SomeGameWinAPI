// CreateWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include<stdlib.h>
#include "CreateWindow.h"
#include<time.h>
#include<memory>
#include<set>
#include<array>
#include"commctrl.h"
using std::set;
#define MAX_LOADSTRING 100
#define WM_START WM_USER+1
#define TIMERID    0
#define CONST const

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
INT					randomNumbInStr();
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    CountOfButton(HWND, UINT, WPARAM, LPARAM);
void				searchClkdButton(LPARAM, set<HWND>, HWND);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	srand(time(NULL));
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
	static HWND listOfNumers;
	static HWND ProgBar;
	static INT timer = 0;
	static INT id = 0;
	ParentWindow = hDlg;
	INT x = 70, y = 10, nWidth = 70, nHeight = 70;
	static set<HWND>hButt;

	UNREFERENCED_PARAMETER(lParam);
    switch (message)
	{
		
		case WM_INITDIALOG: {
			listOfNumers = GetDlgItem(hDlg, IDC_LIST1);
															//progress bar
			TCHAR buffOfMin[6];
			INT tmp = _wtoi(buffOfMin);
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT3), buffOfMin, 6);
			SendMessage(ProgBar, PBM_SETRANGE, 0, MAKELPARAM(0, tmp));
			SendMessage(ProgBar, PBM_SETPOS, 0, 0);


			SendMessage(ProgBar, PBM_SETBARCOLOR, 0, RGB(0, 255, 0));
			ProgBar = GetDlgItem(hDlg, IDC_PROGRESS1);
			return (INT_PTR)TRUE; 
		}


		case WM_START:{

			//MessageBox(hDlg, L"Yes", L"yees", MB_OK);
			if (radioCheck == 1) {
				for (int i = 1; i < 10; ++i) {
					INT num = randomNumbInStr();
					TCHAR buf[5];
					_stprintf_s(buf, _T("%d"), num);
					if (i == 1)
						x = 10;
					else if (i == 4 || i == 7) {					
						y += 80;
						x = 10;
					}
					else
						x += 80;
		//			hBut.push_back((CreateWindow(L"BUTTON", buf, WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL)));
					hButt.insert(CreateWindow(L"BUTTON", buf, WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL));
				}
			}


			else if (radioCheck == 2) {
				INT num = randomNumbInStr();
				TCHAR buf[5];
				_stprintf_s(buf, _T("%d"), num);
				nWidth = 50; nHeight = 50;
				for (int i = 1; i < 17; ++i) {
					if (i == 1)
						x = 10;
					else if (i == 5 || i == 9||i==13) {					
						y += 60;
						x = 10;
					}
					else
						x += 60;
					hButt.insert(CreateWindow(L"BUTTON", buf, WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL));

		//			hBut.push_back((CreateWindow(L"BUTTON", buf, WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL)));
				}
			}


			else if (radioCheck == 3) {
				nWidth = 40; nHeight = 40;
				for (int i = 1; i < 26; ++i) {
					INT num = randomNumbInStr();
					TCHAR buf[5];
					_stprintf_s(buf, _T("%d"), num);
					if (i == 1)
						x = 10;
					else if (i == 6 || i == 11 || i == 16 || i == 21) {					
						y += 50;
						x = 10;
					}
					else
						x += 50;
					hButt.insert(CreateWindow(L"BUTTON", buf, WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL));

		//			hBut.push_back((CreateWindow(L"BUTTON", buf, WS_CHILD | WS_VISIBLE | WS_TABSTOP, x, y, nWidth, nHeight, hDlg, NULL, hInst, NULL)));
				
				}
			}
			id = SetTimer(hDlg, TIMERID, 1000, NULL);
			return (INT_PTR)TRUE;
		}


		case WM_TIMER: {
			timer++;
			TCHAR buffOfMin[6], buff[6];
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT3), buffOfMin, 6);		//minutes from edit to TCHAR
			wsprintf(buff, TEXT("%d"), timer);

			SetWindowText(hDlg, buff);										//from timer to window(print)
			INT tmp = _wtoi(buffOfMin);

			if (timer == tmp) {
				KillTimer(hDlg, TIMERID);
				MessageBox(hDlg, L"Game Over", L"Timer is over", MB_OK);
			}
			SendMessage(ProgBar, PBM_STEPIT, 0, 0);
			SendMessage(ProgBar, PBM_SETSTEP, (WPARAM)(tmp / 10), 0);
		
			return (INT_PTR)TRUE;
		}


		case WM_CLOSE:
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}


		case WM_COMMAND: 
		{
			switch ((LOWORD(wParam)))
			{
				case IDC_BUTTON1: {
					cntOfButt = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, CountOfButton);
					ShowWindow(cntOfButt, SW_SHOW);
					return (INT_PTR)TRUE;
				}
							  
			}
			
			searchClkdButton(lParam, hButt, hDlg);
			
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

INT	randomNumbInStr() {
	return{ rand() % 100 + 1 };
}

void searchClkdButton(LPARAM lParam, set<HWND>hButt, HWND hDlg) {
	//search clicked button
	auto it = hButt.find((HWND)(lParam));
	if (it != hButt.end())
		if (*it == (HWND)lParam) {
			//MessageBox(hDlg, L"It's work =)", L"work =)", MB_OK);
			TCHAR buffOfWinText[6];
			GetWindowText(*it, buffOfWinText, 6);
			//and add text to listbox
			SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_ADDSTRING, 0, (LPARAM)buffOfWinText);
			EnableWindow(*it, FALSE);
		}
}
