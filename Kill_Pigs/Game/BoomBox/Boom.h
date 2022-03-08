#pragma once
#include<Windows.h>
#include"../GameConfig/GameConfig.h"
#include"../Brid/Brid.h"
#include"../res/resource.h"
#include"../PigBox/Pig.h"
#include"../WallBox/WallBox.h"

class CBoom{
public:
	HBITMAP m_boommap;
	HBITMAP m_backboom;
	int		m_x;
	int		m_y;
	HBITMAP m_boomingmap;
	HBITMAP m_backbooming;
	int		m_boomhit1;
	int		m_boomhit2;
	int		m_boomhit3;
	int		m_boomhit4;
public:
	CBoom();
	~CBoom();
public:
	void InitBoom(HINSTANCE hIns,int x,int y);
	void ShowBoom(HDC hdc,HDC compdc);
	void MoveBoom(int direct ,int step);
	int IsHitBrid(CBrid & brid);
	bool IsHitPig(CPig * ppig);

	void InitBooming(HINSTANCE hIns,int x,int y);
	void CBoom::ShowBooming(HDC hdc,HDC compdc);
};