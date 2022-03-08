#include"BoomBox.h"

#define BEGIN_RANGE_BOOM\
	list<CBoom*>::iterator ite = m_lstboom.begin();\
	while(ite != m_lstboom.end()){


#define END_RANGE_BOOM\
		ite++;\
	}

#define BEGIN_RANGE_BOOMING\
	list<CBoom*>::iterator ite = m_lstbooming.begin();\
	while(ite != m_lstbooming.end()){


#define END_RANGE_BOOMING\
		ite++;\
	}

#define SET_BOOM(SHUZI,X,Y)\
	CBoom * pboom##SHUZI = new CBoom;\
	pboom##SHUZI->InitBoom(hIns,X*SIZE_BOOM_WIDTH,Y*SIZE_BOOM_WIDTH);\
	m_lstboom.push_back(pboom##SHUZI);


CBoomBox::CBoomBox(){
	m_lstboom.clear();
}

CBoomBox::~CBoomBox(){
	BEGIN_RANGE_BOOM
		delete (*ite);
		(*ite) = NULL;
	END_RANGE_BOOM
		m_lstboom.clear();
}


void CBoomBox::InitAllBoom(HINSTANCE hIns){
	SET_BOOM(1,6,12);
	SET_BOOM(2,7,12);
	SET_BOOM(3,8,12);
	SET_BOOM(4,9,12);
	SET_BOOM(5,2,9);
	SET_BOOM(6,3,7);
	SET_BOOM(7,7,5);
	SET_BOOM(8,2,2);
	SET_BOOM(9,6,8);
	SET_BOOM(10,13,8);
	SET_BOOM(11,11,7);
	SET_BOOM(12,9,1);
}

void CBoomBox::ShowAllBoom(HDC hdc, HDC compdc){
	BEGIN_RANGE_BOOM
		(*ite)->ShowBoom(hdc,compdc);
	END_RANGE_BOOM
}

void CBoomBox::ShowAllBooming(HDC hdc, HDC compdc){
	BEGIN_RANGE_BOOMING
		(*ite)->ShowBooming(hdc,compdc);
	END_RANGE_BOOMING
}