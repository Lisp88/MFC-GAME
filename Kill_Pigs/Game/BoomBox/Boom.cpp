#include"Boom.h"

CBoom::CBoom(){
	m_backboom =NULL;
	m_boommap = NULL;
	m_x = 0;
	m_y = 0;
	m_boomingmap = NULL;
	m_backbooming = NULL;
	m_boomhit1 = 0;
	m_boomhit2 = 0;
	m_boomhit3 = 0;
	m_boomhit4 = 0;
}
CBoom::~CBoom(){
	::DeleteObject(m_boommap);
	::DeleteObject(m_backboom);
	m_backboom = NULL;
	m_boommap = NULL;
	m_x = 0;
	m_y = 0;
	::DeleteObject(m_boomingmap);
	::DeleteObject(m_backbooming);
	m_boomingmap = NULL;
	m_backbooming = NULL;
	m_boomhit1 = 0;
	m_boomhit2 = 0;
	m_boomhit3 = 0;
	m_boomhit4 = 0;
}

void CBoom::InitBoom(HINSTANCE hIns,int x,int y){
	m_boommap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BOOM));
	m_backboom = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKBOOM));
	m_x = x;
	m_y = y;
	m_boomingmap = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BOOMING));
	m_backbooming = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKBOOMING));
}

void CBoom::ShowBoom(HDC hdc,HDC compdc){
	::SelectObject(compdc,m_backboom);
	BitBlt(hdc,m_x,m_y,SIZE_PIG_WIDTH,SIZE_PIG_HIGTH,compdc,0,0,SRCAND);
	::SelectObject(compdc,m_boommap);
	BitBlt(hdc,m_x,m_y,SIZE_PIG_WIDTH,SIZE_PIG_HIGTH,compdc,0,0,SRCPAINT);
}

void CBoom::ShowBooming(HDC hdc,HDC compdc){
	::SelectObject(compdc,m_backbooming);
	BitBlt(hdc,m_x,m_y,SIZE_PIG_WIDTH,SIZE_PIG_HIGTH,compdc,0,0,SRCAND);
	::SelectObject(compdc,m_boomingmap);
	BitBlt(hdc,m_x,m_y,SIZE_PIG_WIDTH,SIZE_PIG_HIGTH,compdc,0,0,SRCPAINT);
}

void CBoom::MoveBoom(int direct ,int step ){
	switch(direct){
	case 3:
		{
			if(m_boomhit3 == 3){
				
			}else{
				m_x-=step;
			}	
		}
		break;
	case 4:
		{
			if(m_boomhit4 == 4){
				
			}else{
				m_x+=step;
			}
		
		}
		break;
	case 1:
		{
			if(m_boomhit1 == 1){
				
			}else{
				m_y-=step;
			}
		
		}
		break;
	case 2:
		{
			if(m_boomhit2 == 2){
				
			}else{
				m_y+=step;
			}
		
		}
		break;
	}
}

int CBoom::IsHitBrid(CBrid & brid){
	//---------------------判断上下左右四个点 四个点被撞每个点对应一个方向
	//------------上方中央-----------炸弹被向上撞------------
	if(brid.m_y >= m_y && brid.m_y <= m_y+SIZE_BRID_HIGTH && brid.m_x+(SIZE_BRID_HIGTH/2) <= m_x+SIZE_BRID_HIGTH && brid.m_x+(SIZE_BRID_HIGTH/2)>= m_x)
	{
		return 1;//上
	}
	//------------下方中央----------炸弹被向下撞------------
	if(brid.m_x+(SIZE_BRID_HIGTH/2)>=m_x && brid.m_x+(SIZE_BRID_HIGTH/2)<=m_x+SIZE_BRID_HIGTH &&brid.m_y+SIZE_BRID_HIGTH >= m_y &&brid.m_y+SIZE_BRID_HIGTH <= m_y+SIZE_BRID_HIGTH){
		return 2;//下
	}
	//------------左面中间-----------炸弹被向左撞-----------
	if(brid.m_x >= m_x && brid.m_x <= m_x +SIZE_BRID_HIGTH && brid.m_y+(SIZE_BRID_HIGTH/2)>= m_y && brid.m_y+(SIZE_BRID_HIGTH/2)<= m_y+SIZE_BRID_HIGTH){
		return 3; //左
	}
	//------------右---------------------------------------
	if(brid.m_x+SIZE_BRID_HIGTH>= m_x &&brid.m_x+SIZE_BRID_HIGTH<=m_x+SIZE_BRID_HIGTH && brid.m_y+(SIZE_BRID_HIGTH/2) >= m_y && brid.m_y+(SIZE_BRID_HIGTH/2)<= m_y+SIZE_BRID_HIGTH){
		return 4; //右
	}
	return 0;
}

bool CBoom::IsHitPig(CPig *ppig){
	if(m_x+(SIZE_BOOM_WIDTH/2) >= ppig->m_x && m_x+(SIZE_BOOM_WIDTH/2) <= ppig->m_x+SIZE_BOOM_WIDTH && m_y+(SIZE_BOOM_WIDTH/2) >= ppig->m_y &&m_y+(SIZE_BOOM_WIDTH/2) <= ppig->m_y+SIZE_BOOM_WIDTH){
		return true;
	}
	return false;
}