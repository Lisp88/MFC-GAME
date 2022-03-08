#pragma once
#include<Windows.h>
#include"../GameConfig/GameConfig.h"
#include"../res/resource.h"


class CWall{
public:
	HBITMAP m_wallmap;
	int m_x;
	int m_y;
public:
	CWall();
	~CWall();
public:
	void Initwall(HINSTANCE hIns, int x, int y);
	void Showwall(HDC hdc,HDC compDC);
};