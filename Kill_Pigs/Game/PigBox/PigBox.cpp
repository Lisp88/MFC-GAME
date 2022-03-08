#include"PigBox.h"

#define BEGIN_RANGE_PIG\
	list<CPig*>::iterator ite = m_lstpig.begin();\
	while(ite != m_lstpig.end()){


#define END_RANGE_PIG\
		ite++;\
	}

#define SET_PIG(SHUZI,X,Y)\
	CPig * ppig##SHUZI = new CPig;\
	ppig##SHUZI->InitPig(hIns,X*SIZE_PIG_WIDTH,Y*SIZE_PIG_WIDTH);\
	m_lstpig.push_back(ppig##SHUZI);


CPigBox::CPigBox(){
	m_lstpig.clear();
}

CPigBox::~CPigBox(){
	BEGIN_RANGE_PIG
		delete (*ite);
		(*ite) = NULL;
	END_RANGE_PIG
		m_lstpig.clear();
}


void CPigBox::InitAllPig(HINSTANCE hIns){
	SET_PIG(1,6,1);
	SET_PIG(2,1,5);
	SET_PIG(3,2,6);
	SET_PIG(4,6,14);
	SET_PIG(5,7,14);
	SET_PIG(6,8,14);
	SET_PIG(7,9,14);
	SET_PIG(8,3,5);
	SET_PIG(9,6,9);
	SET_PIG(10,14,1);
	SET_PIG(11,14,3);
	SET_PIG(12,14,5);
}

void CPigBox::ShowAllPig(HDC hdc, HDC compdc){
	BEGIN_RANGE_PIG
		(*ite)->ShowPig(hdc,compdc);
	END_RANGE_PIG
}