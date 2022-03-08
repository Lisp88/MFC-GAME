#include"Background.h"
#include"../res/resource.h"
#include"../GameConfig/GameConfig.h"


CBackGround::CBackGround(){
	m_hMap = NULL;
	m_x=0;
	m_y=0;

}

CBackGround::~CBackGround(){
	::DeleteObject(m_hMap);
	m_hMap = NULL;
	m_x=0;
	m_y=0;
}

void CBackGround::InitBackGround(HINSTANCE hIns, int x, int y){
	m_hMap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKGROUND));
	m_x=x;
	m_y=y;

}

void CBackGround::ShowBackGround(HDC hdc, HDC compDC){
	::SelectObject(compDC,m_hMap);
	::BitBlt(hdc,m_x,m_y,SIZE_BACKGROUND_WIDTH,SIZE_BACKGROUND_HEIGH,
		compDC,0,0,SRCCOPY);
}
