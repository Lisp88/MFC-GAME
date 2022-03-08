#pragma once
#include"Wall.h"
#include<list>
#include<windows.h>


using namespace std;

class CWallBox{
public:
	list<CWall *> m_lstwall;
public:
	CWallBox();
	~CWallBox();
public:
	void InitAllWall(HINSTANCE hIns);
	void ShowAllWall(HDC hdc, HDC compdc);
};