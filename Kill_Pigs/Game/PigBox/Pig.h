#pragma once
#include<Windows.h>
#include"../GameConfig/GameConfig.h"
#include"../res/resource.h"

class CPig{
public:
	HBITMAP m_pigmap;
	HBITMAP m_backpig;
	int		m_x;
	int		m_y;
public:
	CPig();
	~CPig();
public:
	void InitPig(HINSTANCE hIns,int x,int y);
	void ShowPig(HDC hdc,HDC compdc);
};