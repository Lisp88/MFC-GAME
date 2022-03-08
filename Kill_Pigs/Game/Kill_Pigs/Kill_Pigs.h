#pragma once
#include"../GameFrame/GameApp.h"
#include"../BackGround/Background.h"
#include"../Brid/Brid.h"
#include"../WallBox/WallBox.h"
#include"../PigBox/PigBox.h"
#include"../BoomBox/BoomBox.h"
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")
class CKill_Pigs:public CGameApp{
public:
	CBackGround m_back;
	CBrid m_brid;
	CWallBox m_wallbox;
	CPigBox m_pigbox;
	CBoomBox m_boombox;

public:
	CKill_Pigs();
	~CKill_Pigs();
public:
	virtual void OnCreate();
	virtual void OnDraw();
	virtual void OnKeyDown(WPARAM);
	virtual void OnRun(WPARAM);
	void GameOver();
	void SetTimer();


};