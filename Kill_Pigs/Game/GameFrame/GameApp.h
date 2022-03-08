#pragma once
#include<windows.h>


class CGameApp{
public:
	HINSTANCE m_hIns;  //实例句柄
	HWND m_hWnd;       //窗口句柄
public:
	void SetHandle(HINSTANCE hins,HWND hwnd){
		m_hIns =hins;
		m_hWnd = hwnd;
	}

public:
	CGameApp(){
		m_hIns = NULL;
		m_hWnd = NULL;
	}
	virtual ~CGameApp(){}
public:
	//无法解析的外部符号 "public: static class CGameApp * __cdecl CGameApp::GetChildObject(void)"
	static CGameApp* GetChildObject();
public:
	//case WM_CREATE: //窗口创建消息
	virtual void OnCreate(){};


	//case WM_PAINT:  //重绘消息
	virtual void OnDraw(){};


	//case WM_TIMER:   //定时器，需要我们在子类中手动添加定时器并设置触发间隔
	virtual void OnRun(WPARAM){}


	//case WM_KEYDOWN:  //键盘按下触发消息
	virtual void OnKeyDown(WPARAM){}


	//case WM_KEYUP:  //键盘抬起触发消息
	virtual void OnKeyUp(WPARAM){}


	//case WM_LBUTTONDOWN: //鼠标左键按下触发消息
	virtual void OnLButtonDown(POINT &po){}


	//case WM_LBUTTONUP: //鼠标左键抬起触发消息
	virtual void OnLButtonUp(POINT &po){}


	//case WM_MOUSEMOVE:  //鼠标移动
	virtual void OnMouseMove(POINT &po){}


};

#define CREATE_OBJECT(CHILD_CLASS)\
CGameApp* CGameApp::GetChildObject(){\
	return new CHILD_CLASS;\
}

#define WINDOW_PARAM(PARAM_X,PARAM_Y,PARAM_WIDTH,PARAM_HEIGH,PARAM_TITLE)\
	int nx=PARAM_X;\
	int ny=PARAM_Y;\
	int nwidth=PARAM_WIDTH;\
	int nheigh=PARAM_HEIGH;\
	const CHAR * strTitle=PARAM_TITLE;