#pragma once
#include<Windows.h>
#include"../PigBox/PigBox.h"

class CBrid{
public:
	HBITMAP m_bridmap;
	HBITMAP m_bridbackmap;
	int		m_x;
	int		m_y;
public:
	CBrid();
	~CBrid();
public:
	void InitBrid(HINSTANCE hIns);
	void ShowBrid(HDC hdc, HDC compdc);
	void MoveBrid(int direct,int step);
	bool DeathBrid(CPig * ppig);
};