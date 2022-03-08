#include"Brid.h"
#include"../res/resource.h"
#include"../GameConfig/GameConfig.h"

CBrid::CBrid(){
	m_bridmap = NULL;
	m_bridbackmap = NULL;
	m_x = 0;
	m_y = 0;
}

CBrid::~CBrid(){
	::DeleteObject(m_bridmap);
	::DeleteObject(m_bridbackmap);
	m_bridmap = NULL;
	m_bridbackmap = NULL;
	m_x = 0;
	m_y = 0;
}
void CBrid::InitBrid(HINSTANCE hIns){
	m_bridmap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BRID));
	m_bridbackmap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKBRID));
	m_x = (SIZE_BACKGROUND_WIDTH-SIZE_BRID_WIDTH)/2;
	m_y = (SIZE_BACKGROUND_HEIGH-SIZE_BRID_HIGTH)/2 -(SIZE_BRID_HIGTH/2);
}

void CBrid::ShowBrid(HDC hdc, HDC compdc){
	::SelectObject(compdc,m_bridbackmap);
	::BitBlt(hdc,m_x,m_y,SIZE_BRID_WIDTH,SIZE_BRID_HIGTH,compdc,0,0,SRCAND);
	::SelectObject(compdc,m_bridmap);
	::BitBlt(hdc,m_x,m_y,SIZE_BRID_WIDTH,SIZE_BRID_HIGTH,compdc,0,0,SRCPAINT);
}

void CBrid::MoveBrid(int direct , int step){
	switch(direct){
	case VK_LEFT:
		{
			if(m_x - step<=0){
				m_x = 0;
			}else{
				m_x-=step;
			}

		
		}
		break;
	case VK_RIGHT:
		{
			if(m_x + step>=SIZE_BACKGROUND_WIDTH-SIZE_BRID_WIDTH){
				m_x = SIZE_BACKGROUND_WIDTH-SIZE_BRID_WIDTH;
			}else{
				m_x+=step;
			}
		
		}
		break;
	case VK_UP:
		{
			if(m_y-step<=0){
				m_y =0;
			}else{
				m_y-=step;
			}
		
		}
		break;
	case VK_DOWN:
		{
			if(m_y+step>=SIZE_BACKGROUND_HEIGH-SIZE_BRID_HIGTH){
				m_y =SIZE_BACKGROUND_HEIGH-SIZE_BRID_HIGTH;
			}else{
				m_y+=step;
			}
		
		}
		break;
	}

}

bool CBrid::DeathBrid(CPig * ppig){
	if(m_x + (SIZE_BRID_WIDTH/2)<=ppig->m_x+SIZE_BRID_WIDTH && m_x + (SIZE_BRID_WIDTH/2)>= ppig->m_x && m_y +(SIZE_BRID_WIDTH/2)<=ppig->m_y +SIZE_BRID_WIDTH && m_y +(SIZE_BRID_WIDTH/2) >= ppig->m_y)	
		return true;
	return false;
}