//WinMain.cpp
// window 应用程序，多字符集
#include<windows.h>
#include<Windowsx.h>
#include"GameApp.h"
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hIns = 0;  //全局变量，程序实例句柄

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//-----------------------------------------------------
	HWND hwnd = 0;
	MSG msg;       //  装消息的结构体
	WNDCLASSEX wndclass;
	//-----------------------------------------------------

	hIns = hInstance;
	LPCSTR lClassName = "yue"; //窗口类名

	extern int nx;                  //窗口位置X
	extern int ny;                  //窗口位置Y
	extern int nwidth;              //窗口宽度
	extern int nheigh;              //窗口高度
	extern const CHAR * strTitle;     //窗口标题名

	int pos_x=nx;
	if(pos_x<0){
		pos_x=0;
	}
	int pos_y=ny;
	if(pos_y<0){
		pos_y=0;
	}
	int nWidth=nwidth;
	if(nWidth<=0){
		nWidth = 500;
	}
	int nHeight=nheigh;
	if(nHeight<=0){
		nHeight = 500;
	}

	//----------------------创建窗口过程-----------------------------------
	//  1. 设计
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.lpszClassName = lClassName;
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	// 2.  注册
	if (RegisterClassEx(&wndclass) == FALSE)
	{
		MessageBox(0, "注册失败", "提示", MB_OK);
		return 0;
	}
	//  3.  创建
	hwnd = CreateWindow(lClassName, strTitle, WS_OVERLAPPEDWINDOW, pos_x, pos_y, nWidth, nHeight, 0, 0, hInstance, 0);
	if (hwnd == 0)
	{
		MessageBox(0, "创建失败", "提示", MB_OK);
		return 0;
	}
	//  4.  显示窗口
	ShowWindow(hwnd, SW_SHOW);
	//---------------------------创建窗口过程------------------------------------------------

	//----------------------------消息循环-------------------------------------------
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------消息循环-------------------------------------------

	return 0;
}

CGameApp *pGameApp=NULL;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_CREATE: //窗口创建消息
	{
		if(pGameApp==NULL){
			pGameApp = CGameApp::GetChildObject();

			pGameApp->SetHandle(hIns,hwnd);
			
			pGameApp->OnCreate();
		}
		
	}
	break;
	case WM_PAINT:  //重绘消息
	{
		if(pGameApp){
			pGameApp->OnDraw();
		}
		
	}
	break;
	case WM_TIMER:   //定时器，需要我们在子类中手动添加定时器并设置触发间隔
	{
		if(pGameApp){
			pGameApp->OnRun(wParam);
		}
	}
	break;
	case WM_KEYDOWN:  //键盘按下触发消息
	{
		if(pGameApp){
			pGameApp->OnKeyDown(wParam);
		}
		
	}
	break;
	case WM_KEYUP:  //键盘抬起触发消息
	{
		if(pGameApp){
			pGameApp->OnKeyUp(wParam);
		}
	}
	break;
	case WM_LBUTTONDOWN: //鼠标左键按下触发消息
	{
		if(pGameApp){

			POINT po={0};
			po.x = GET_X_LPARAM(lParam); 
			po.y = GET_Y_LPARAM(lParam);



			pGameApp->OnLButtonDown(po);
		}
	}
	break;
	case WM_LBUTTONUP: //鼠标左键抬起触发消息
	{
		if(pGameApp){

			POINT po={0};
			po.x = GET_X_LPARAM(lParam); 
			po.y = GET_Y_LPARAM(lParam);



			pGameApp->OnLButtonUp(po);
		}
	}
	break;
	case WM_MOUSEMOVE:  //鼠标移动
	{
		if(pGameApp){

			POINT po={0};
			po.x = GET_X_LPARAM(lParam); 
			po.y = GET_Y_LPARAM(lParam);



			pGameApp->OnMouseMove(po);
		}
	}
	break;
	case WM_CLOSE:
		{
			int res = ::MessageBox(NULL, "是否确定退出", "提示", MB_OKCANCEL);//[WM_CLOSE] 
			if (res ==IDOK){ //点击 【确定】按钮
			
			}else if (res ==IDCANCEL){//点击【取消】按钮，不调用默认的消息处理 DefWindowProc 
			
				return 0;
			}else{
				return 0;
			}
		}
		break;
	case WM_DESTROY: 
		{
			//::MessageBox(NULL, "WM_DESTROY", "提示", MB_OK);
			//释放游戏资源
			PostQuitMessage(0);
		}
		break;
	case WM_QUIT:
		{
			::MessageBox(NULL, "WM_QUIT", "提示", MB_OK);
		}
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
	
}