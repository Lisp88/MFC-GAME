#include"Pig.h"

CPig::CPig(){
	m_backpig =NULL;
	m_pigmap = NULL;
	m_x = 0;
	m_y = 0;
}
CPig::~CPig(){
	::DeleteObject(m_pigmap);
	::DeleteObject(m_backpig);
	m_backpig = NULL;
	m_pigmap = NULL;
	m_x = 0;
	m_y = 0;
}

void CPig::InitPig(HINSTANCE hIns,int x,int y){
	m_pigmap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_PIG));
	m_backpig = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKPIG));
	m_x = x;
	m_y = y;
}

void CPig::ShowPig(HDC hdc,HDC compdc){
	::SelectObject(compdc,m_backpig);
	BitBlt(hdc,m_x,m_y,SIZE_PIG_WIDTH,SIZE_PIG_HIGTH,compdc,0,0,SRCAND);
	::SelectObject(compdc,m_pigmap);
	BitBlt(hdc,m_x,m_y,SIZE_PIG_WIDTH,SIZE_PIG_HIGTH,compdc,0,0,SRCPAINT);
}