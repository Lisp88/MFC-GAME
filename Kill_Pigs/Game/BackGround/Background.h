#pragma once
#include<windows.h>


class CBackGround{
public:
	HBITMAP m_hMap;
	int     m_x;
	int     m_y;
public:
	CBackGround();
	~CBackGround();
public:
	void InitBackGround(HINSTANCE hIns, int x, int y);
	void ShowBackGround(HDC hdc, HDC compDC);
};