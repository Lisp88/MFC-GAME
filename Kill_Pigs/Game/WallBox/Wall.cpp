#include"Wall.h"

CWall::CWall(){
	m_x = 0;
	m_y = 0;
	m_wallmap = NULL;
}

CWall::~CWall(){
	::DeleteObject(m_wallmap);
	m_x = 0;
	m_y = 0;
	m_wallmap = NULL;
}

void CWall::Initwall(HINSTANCE hIns, int x, int y){
	m_wallmap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_WALL));
	m_x = x;
	m_y = y;
}

void CWall::Showwall(HDC hdc,HDC compDC){
	::SelectObject(compDC,m_wallmap);
	::BitBlt(hdc,m_x,m_y,SIZE_WALL_WIDTH,SIZE_WALL_HIGTH,compDC,0,0,SRCCOPY);
}


