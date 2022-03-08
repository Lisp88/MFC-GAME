#pragma once
#include<list>
#include"Pig.h"
using namespace std;

class CPigBox{
public:
	list<CPig *> m_lstpig;
public:
	CPigBox();
	~CPigBox();
public:
	void InitAllPig(HINSTANCE hIns);
	void ShowAllPig(HDC hdc,HDC compdc);
};