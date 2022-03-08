#pragma once
#include<list>
#include"Boom.h"
using namespace std;

class CBoomBox{
public:
	list<CBoom *> m_lstboom;
	list<CBoom *> m_lstbooming;
public:
	CBoomBox();
	~CBoomBox();
public:
	void InitAllBoom(HINSTANCE hIns);
	void ShowAllBoom(HDC hdc,HDC compdc);
	void InitAllBooming(HINSTANCE hIns);
	void ShowAllBooming(HDC hdc,HDC compdc);
};