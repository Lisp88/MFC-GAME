#include"WallBox.h"

#define RANGE_LIST_BEGIN\
	list<CWall*>::iterator ite = m_lstwall.begin();\
	while(ite != m_lstwall.end()){


#define RANGE_LIST_END\
		ite++;\
	}




#define MAKE_WALL(SHUZI,X,Y)\
	CWall * pwall##SHUZI = new CWall;\
	m_lstwall.push_back(pwall##SHUZI);\
	pwall##SHUZI->Initwall(hIns,X*SIZE_WALL_WIDTH,Y*SIZE_WALL_WIDTH);

CWallBox::CWallBox(){
	m_lstwall.clear();
}
CWallBox::~CWallBox(){
	RANGE_LIST_BEGIN
		delete (*ite);
		(*ite) = NULL;
	RANGE_LIST_END
	
		m_lstwall.clear();
}

void CWallBox::InitAllWall(HINSTANCE hIns){
	//------------------制作墙--------------
	//----------定边框--------
	int hengshang = 16;
	int hengxia = 16;
	int x1 = 0,y1 = 0;
	while(hengshang--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,x1,y1);
		x1+=SIZE_WALL_WIDTH;
	}
	x1 = 0;
	y1 = 0;
	while(hengxia--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,x1,y1);
		y1+=SIZE_WALL_WIDTH;
	}


	int x2 = 0, y2 = 0;
	int shushang = 16;
	int shuxia = 16;
	x2 = SIZE_BACKGROUND_WIDTH-SIZE_WALL_WIDTH;
	while(shuxia--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,x2,y2);
		y2+=SIZE_WALL_WIDTH;
	}
	x2 = 0;
	y2 = 0;
	y2 = SIZE_BACKGROUND_WIDTH-SIZE_WALL_WIDTH;
	while(shushang--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,x2,y2);
		x2+=SIZE_WALL_WIDTH;
	}
	//----------细节部分-----------
	//------左下部分------
	//--横--
	int zuoxia_length1 = 6;
	int zuoxia_x1 = 0;
	int zuoxia_y1 = 0;
	while(zuoxia_length1--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,zuoxia_x1,SIZE_BACKGROUND_WIDTH-(4*SIZE_WALL_WIDTH));
		zuoxia_x1+=SIZE_WALL_WIDTH;
	}
	//---竖---
	int zuoxia_length2 = 4;
	int zuoxia_y2 = SIZE_BACKGROUND_WIDTH-(4*SIZE_WALL_WIDTH);
	int zuoxia_x2 = 5*SIZE_WALL_WIDTH;
	while(zuoxia_length2--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,zuoxia_x2,zuoxia_y2);
		zuoxia_y2+=SIZE_WALL_WIDTH;
	}
		MAKE_WALL(1,4,13);
		MAKE_WALL(2,4,14);
	//--------右下部分---
	//----横----
	int youxia_length1 = 6;
	int youxia_x1 = SIZE_BACKGROUND_WIDTH-SIZE_WALL_WIDTH;
	int youxia_y1 = 0;
	while(youxia_length1--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,youxia_x1,SIZE_BACKGROUND_WIDTH-(4*SIZE_WALL_WIDTH));
		youxia_x1-=SIZE_WALL_WIDTH;
	}
	//---竖---
	MAKE_WALL(3,10,14);
	MAKE_WALL(4,10,13);
	MAKE_WALL(5,11,14);
	MAKE_WALL(6,11,13);
	//----------------左上---------------
	//--横--
	int zuoshang_length1 = 6;
	int zuoshang_x1 = SIZE_WALL_WIDTH;
	int zuoshang_y1 = 4*SIZE_WALL_WIDTH;
	while(zuoshang_length1--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,zuoshang_x1,zuoshang_y1);
		zuoshang_x1+=SIZE_WALL_WIDTH;
	}
	MAKE_WALL(7,5,2);
	MAKE_WALL(8,6,2);
	MAKE_WALL(9,8,8);
	//----竖----
	int zuoshang_length2 = 2;
	int zuoshang_x2 = 3*SIZE_WALL_WIDTH;
	int zuoshang_y2 = SIZE_WALL_WIDTH;
	while(zuoshang_length2--){
		CWall * pwall = new CWall;
		m_lstwall.push_back(pwall);
		pwall->Initwall(hIns,zuoshang_x2,zuoshang_y2);
		zuoshang_y2+=SIZE_WALL_WIDTH;
	}
	//点缀
	MAKE_WALL(10,7,8);
	MAKE_WALL(11,9,8);
	MAKE_WALL(12,9,7);
	MAKE_WALL(13,9,6);
	MAKE_WALL(14,8,6);
	MAKE_WALL(15,7,6);
	MAKE_WALL(16,6,6);
	MAKE_WALL(17,5,6);
	MAKE_WALL(18,5,7);
	MAKE_WALL(19,5,8);
	MAKE_WALL(20,5,9);
	MAKE_WALL(21,5,10);
	MAKE_WALL(22,6,10);
	MAKE_WALL(23,7,10);
	MAKE_WALL(24,8,10);
	MAKE_WALL(25,9,10);
	MAKE_WALL(26,2,5);
	MAKE_WALL(27,3,6);

	MAKE_WALL(28,2,10);

	MAKE_WALL(29,3,8);
	MAKE_WALL(30,14,2);
	MAKE_WALL(31,13,2);
	MAKE_WALL(32,12,2);
	MAKE_WALL(33,11,2);
	MAKE_WALL(34,10,2);
	MAKE_WALL(35,9,2);
	MAKE_WALL(36,14,4);
	MAKE_WALL(37,13,4);
	MAKE_WALL(38,12,4);
	MAKE_WALL(39,11,4);
	MAKE_WALL(40,14,6);
	MAKE_WALL(41,13,6);
	MAKE_WALL(42,13,9);
	MAKE_WALL(43,11,8);
}
void CWallBox::ShowAllWall(HDC hdc, HDC compdc){
	RANGE_LIST_BEGIN
		(*ite)->Showwall(hdc,compdc);
	RANGE_LIST_END
}

