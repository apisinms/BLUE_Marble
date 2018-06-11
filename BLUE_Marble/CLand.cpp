//CLand.cpp
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>

CLand::CLand()
{
}
CLand::~CLand()
{
	if (cLand_Owner != NULL)
	{
		delete[]cLand_Owner;
		cLand_Owner = nullptr;
	}

	if (cLand_Name != NULL)
	{
		delete[]cLand_Name;
		cLand_Name = nullptr;
	}

	if (cBuilding_Grade != NULL)
	{
		delete[]cBuilding_Grade;
		cBuilding_Grade = nullptr;
	}
}

void CLand::Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Build_Price,
	int iLand_Price, int x, int y)
{
	this->iLand_Building = iLand_Building;

	this->cLand_Owner = new TCHAR[lstrlen(cLand_Owner) + 20];
	lstrcpy(this->cLand_Owner, cLand_Owner);

	this->cLand_Name = new TCHAR[lstrlen(cLand_Name) + 20];
	lstrcpy(this->cLand_Name, cLand_Name);

	this->cBuilding_Grade = new TCHAR[5];
	lstrcpy(this->cBuilding_Grade, "");

	this->iLand_Build_Price = iLand_Build_Price;
	this->iLand_Price = iLand_Price;
	this->iLand_Pass_Money = 0;
	this->iTotal_LandPrice = 0;

	pos.X = x;
	pos.Y = y;
}
void CLand::Print_LandInfo()
{
	if(lstrcmp((TCHAR*)"♠", cLand_Owner) == 0)
		g_DBBF.TextColor(P1_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"◆", cLand_Owner) == 0)
		g_DBBF.TextColor(P2_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"♥", cLand_Owner) == 0)
		g_DBBF.TextColor(P3_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"♣", cLand_Owner) == 0)
		g_DBBF.TextColor(P4_COLOR, BLACK);

	else
		g_DBBF.TextColor(WHITE, BLACK);

	g_DBBF.WriteBuffer(pos.X, pos.Y, cLand_Name);
	g_DBBF.WriteBuffer(pos.X + 10, pos.Y, cBuilding_Grade);
}
COORD CLand::Get_LandPosition()
{
	return pos;
}

void CLand::Print_Information(ALL_LANDS iLand_ID)
{
	int iNext_Line = 0;
	g_DBBF.TextColor(WHITE, BLACK);

	switch (iLand_ID)
	{
	case ISLAND_LAND: //무인도
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 무인도에 갇히셨습니다.                   │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 얌전히 구조시간을 기다리세요.            │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 아니면 운이 억수로 좋던가^^              │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ (주사위 더블 시 탈출합니다.)             │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ (혹은 3턴을 대기합니다.    )             │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────┘");
#endif
		break;
	case WORLDTRIP_LAND: //세계여행
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ ★즐거운 세계 여행입니다.★              │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 편안한 여행 되세요~                      │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ (원하는 타일을 선택하세요.)              │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ (다음 턴에 이동합니다.)                  │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────┘");
#endif
		break;
	case START_LAND: //출발점
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 출발지 입니다.                           │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 한 바퀴를 돌 때마다 월급을 받습니다.＄++ │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────┘");
#endif
		break;
	case GOLDKEY_LAND: //황금열쇠
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 두근두근, 황금 열쇠에 도착했습니다.     │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 당신의 운을 시험하세요~                 │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case BANGKOK_LAND: //방콕 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 태국의 수도. 매년 1,600만 명이          │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 찾는 관광도시 방콕.                     │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 길거리 음식의 천국이기도 한 방콕은      │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 태국식 면요리와 커리, 해산물이 유명하다.│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case BEIJING_LAND: //베이징 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 중국의 수도. 옛 왕궁과 현 중국의 역사를 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 모두 볼 수 있는 베이징은                │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 만리장성부터 자금성, 천안문광장까지     │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 중국의 웅장함을 느낄 수 있다.           │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

		break;
	case TAIPEI_LAND: //타이페이 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 대만의 수도. 중국과 일본의 문화가       │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 융합된 도시.   애니메이션               │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ '센과 치히로'의 배경인 지우펀이 있다.   │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

		break;

	case DUBAI_LAND: //두바이
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 사막 위의 이국적인 도시.아랍에미리트    │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 연방의 7개국 중 하나이다. 세상에서 가장 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│  높은 빌딩인 부르즈 칼리파가 있다.      │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

		break;
	case KAIRO_LAND: //카이로 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 이집트의 수도. 수많은 문화 유산을       │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 보유한 도시. 도시 자체가 UNESCO         │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 세계유산에 1979년 등재 되었다.          │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

		break;
	case TOKYO_LAND: //도쿄 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 일본의 수도. 일본의 과거부터 현재까지   │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 모두 볼 수 있는, 일본을 압축해놓은 도시 │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

		break;
	case SIDNEY_LAND: //시드니 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 호주의 수도. 오페라 하우스로 대표되는   │,");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 도시이자, 사막과 바다를 모두 감상할 수  │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│  있어 유명한 포트스테판이 위치하고 있다.│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case QUEBEC_LAND: //퀘벡 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 유네스코 세계문화유산으로 지정된 퀘벡시 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 는 북미 유일의 성곽도시이다. 퀘백 노트르│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 담 대성당등 역사적 건축물들이 많이 있다.│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case HAWAII_LAND: //하와이 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 미국 50 개 주 중 가장 남단에 위치하며,  │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 작게는 8개, 크게는 6개의 섬으로 구성되어│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 있는 하와이는 각 섬마다 아름다운        │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 자연환경을 자랑한다.                    │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case SANGPAWOOLO_LAND: //상파울로 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 리우데자네이루 남서쪽-고원지대에        │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 위치해 있는 남아메리카 최대의 도시.     │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 브라질의 경제, 문화 중심지로서          │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 아름다운 관광 명소들이 위치해 있다.     │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case PRAHA_LAND: //프라하
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 중심가가 유네스코 문화유산인 프라하는,  │ ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 도시 중앙을 가로지르는 볼타바 강의 야경 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 이 유명하고, 세계에서 가장 큰 성인      │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 프라하 성이 위치해 있다.                │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case BERLIN_LAND: //베를린 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 독일 역사와 문화의 중심지 베를린은,     │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 베를린 국제 영화제와 필하모닉 오케스트라│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 로 유명한 도시이다.                     │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case MOSCOW_LAND: //모스크바 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 유럽 러시아 중부, 모스크바강 유역에     │ ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 자리잡은 도시 모스크바는 겨울과 어울리는│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 도시이다. 러시아 정교회 예술의 아름다운 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 기념물들로 유명하다.                    │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case GENEVA_LAND: //제네바
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 관광지이면서 각종 국제기관이 위치한 도시│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 시내에 위치한 구시가지에서 중세의 분위기│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 를 느낄 수 있다.                        │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case ROME_LAND: //로마 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 2500여년의 역사를 자랑하는 이탈리아의 수│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 도.콜로세움, 바티칸 시국, 대부분의 관광 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 명소들이 밀집해 여행지로 많이 애용된다. │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case PYEONGYANG_LAND: //평양
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 북한의 수도이자 제일의 도시인 평양은    │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 북한의 정치·행정·경제,문화 중심지이다.│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case LONDON_LAND: //런던
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 영국의 정치·경제·문화 그리고 교통의 중│");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 중심지인 런던은, 영국연방의 중심도시다. │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 2층 버스와 여왕님으로 대표되곤 한다.    │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case PARIS_LAND: //파리
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 세계의 문화 중심지로, ‘꽃의 도시’라고 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 불리는 파리는, 에펠탑, 개선문, 노트르담 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 대성당등 많은 기념물과 예술작품이 있다. │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case NEWYORK_LAND: //뉴욕
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 미국 최대의 도시인 뉴욕은, 미국의 상업, │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 금융의 중심지이자, 문화의 중심지이다.   │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 자유의 여신상, 엠파이어 스테이트 빌딩등 │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 현대적인 랜드마크들이 존재한다.         │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	case SEOUL_LAND: //서울
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 한반도 중앙에 위치한 대한민국의 수도인  │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 서울은, 교육과 문화의 중심지 역활을     │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 하고있다. 숭례문, 흥인지문, 창덕궁등,   │");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 조선 시대의 문화 유산들이 보존되고 있다.│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		break;
	}

}

void CLand::Arrive_Land(CGame &Game)
{
	char cPlayer_Choice;
	int iNext_Line = 0;
	while (true)
	{
		if (!(lstrcmp(cLand_Owner, ""))) //도착했는데 빈 땅이면
		{
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 빈땅입니다. 땅을 인수할 수 있어요!      │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 인수하시겠습니까? (y 또는 n 입력 )      │");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
				if (_kbhit())
				{
					int iKey = _getch();
					if (iKey == 'y' || iKey == 'Y') // 땅 구입 선택 시
					{
						Buy_Land(Game, TRUE);
						return;
					}
					else if (iKey == 'n' || iKey == 'N')
					{
						g_DBBF.ClearBuffer();
						Game.Print_All_Tile();
						Game.Print_All_Land();
						Game.Print_All_ExtraLand();
						Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
						Game.Print_All_Character();
						Game.m_Dice.Print_Diceinfo();
						Game.Print_Player_Infor();
						Game.Print_Player_Turn();

						g_DBBF.FlippingBuffer();
						return;
					}

				}
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();

				g_DBBF.FlippingBuffer();
			}
		}

		// 상대방 땅에 도착했을 때
		else if ((lstrcmp(cLand_Owner, "")) && (lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape)))
		{
			if (lstrcmp((TCHAR*)"♠", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[0].iPlayer_Money += iLand_Pass_Money;
			}

			else if (lstrcmp((TCHAR*)"◆", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[1].iPlayer_Money += iLand_Pass_Money;
			}

			else if (lstrcmp((TCHAR*)"♥", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[2].iPlayer_Money += iLand_Pass_Money;
			}

			else if (lstrcmp((TCHAR*)"♣", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[3].iPlayer_Money += iLand_Pass_Money;
			}
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 당신의 땅이 아닙니다... 지나가기        │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 위해서 통행료를 지불해야 합니다.        │");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

				if (Game.m_Player[Game.eCurPlayer].iPlayer_Money > 0)
				{
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 통행료를 지불 했습니다! (아까운 내돈)   │");
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 이참에 확 사버려???(땅을 인수할까요?)   │");
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ (y 또는 n으로 선택)                     │");
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
					if (_kbhit())
					{
						int iKey = _getch();
						if (iKey == 'y' || iKey == 'Y')
						{
							// 돈을 내고 땅을 인수한다. 땅 가격 2배
							if (lstrcmp((TCHAR*)"♠", cLand_Owner) == 0)
								Game.m_Player[0].iPlayer_Money += (iTotal_LandPrice * 2);

							else if (lstrcmp((TCHAR*)"◆", cLand_Owner) == 0)
								Game.m_Player[1].iPlayer_Money += (iTotal_LandPrice * 2);

							else if (lstrcmp((TCHAR*)"♥", cLand_Owner) == 0)
								Game.m_Player[2].iPlayer_Money += (iTotal_LandPrice * 2);

							else if (lstrcmp((TCHAR*)"♣", cLand_Owner) == 0)
								Game.m_Player[3].iPlayer_Money += (iTotal_LandPrice * 2);
							Buy_Land(Game, FALSE);	// 남의 소유 땅을 산다

							return;
						}
						else if (iKey == 'n' || iKey == 'N')
						{
							// 다시 그리고 빠져나간다.
							g_DBBF.ClearBuffer();
							Game.Print_All_Tile();
							Game.Print_All_Land();
							Game.Print_All_ExtraLand();
							Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
							Game.Print_All_Character();
							Game.m_Dice.Print_Diceinfo();
							Game.Print_Player_Infor();
							g_DBBF.FlippingBuffer();
							return;
						}
					}
				}

				// 금액 0보다 적어지면
				else if (Game.m_Player[Game.eCurPlayer].iPlayer_Money < 0)
				{
					//금액으로 패배
					// 함수 호출
					Game.Print_WinPlayer(Game.eCurPlayer, 0);

#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 통행료를 지불 했습니다! (아까운 내돈)   │");
					g_DBBF.TextColor(RED, BLACK);
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 돈이 없어서 파산하셨네요...             │");
					g_DBBF.TextColor(WHITE, BLACK);
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
				}

				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
		}

		// 내 땅에 도착 했을 때
		else if (!lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape))
		{
			iNext_Line = 0;
			g_DBBF.TextColor(WHITE, BLACK);
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌───────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 내 명의의 땅이다.                         │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 통행료를 올려받고 싶은데...(건물을 업그레 │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 이드 합니다)(y 또는 n으로 선택)           │");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└───────────────────────────────────────────┘");
#endif
				if (_kbhit())
				{
					int iKey = _getch();
					if (iKey == 'y' || iKey == 'Y')
					{
						// 건물을 업그레이드 한다.
						Build_Building(Game);
						return;
					}
					else if (iKey == 'n' || iKey == 'N')
					{
						// 다시 그리고 빠져나간다.
						g_DBBF.ClearBuffer();
						Game.Print_All_Tile();
						Game.Print_All_Land();
						Game.Print_All_ExtraLand();
						Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
						Game.Print_All_Character();
						Game.m_Dice.Print_Diceinfo();
						Game.Print_Player_Infor();
						g_DBBF.FlippingBuffer();
						return;
					}
				}
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
		}
	}
}
void CLand::Buy_Land(CGame &Game, BOOL EMPTY)
{
	int iNext_Line = 0;

	BOOL bBuy = FALSE;
	for (int i = 0; i < 2; i++)
	{
		g_DBBF.ClearBuffer();
		g_DBBF.TextColor(WHITE, BLACK);
		// 땅의 총 가격을 설정   (땅값 + (건물수 * 건물 짓기비용) )
		iTotal_LandPrice = iLand_Price + (iLand_Building * iLand_Build_Price);

		if (Game.m_Player[Game.eCurPlayer].iPlayer_Money > iTotal_LandPrice)
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 인수 가즈아ㅏㅏ!!!(땅을 인수합니다)     │");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 매매료를 지불 했습니다! (아까운 내돈)   │");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
			bBuy = TRUE;
		}
		else
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 거지면서 땅을 사려고 하다니....풉       │");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 돈 더 벌면 찾아오시죠???                │");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────────────────────────┘");
#endif
		}
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
		Game.Print_All_Character();
		Game.m_Dice.Print_Diceinfo();
		Game.Print_Player_Infor();
		g_DBBF.FlippingBuffer();
	}


	if (bBuy == TRUE)
	{
		lstrcpy(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape);

		if (EMPTY == TRUE)
		{
			// 건물을 처음 짓는거면 건물을 1개는 올려줘야 함.
			Build_Building(Game);
		}

		// 땅의 통행료를 설정   (땅의 총 가격의 절반)
		iLand_Pass_Money = iTotal_LandPrice * 0.5;

		// 돈 감소
		if (EMPTY == TRUE)
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iTotal_LandPrice;

		// 남의 땅 인수는 2배 감소
		else if (EMPTY == FALSE)
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= (iTotal_LandPrice * 2);
	}
	// 라인독점 검사
	int Inc = 0;
	for (int i = 0; i < 4; i++, Inc += 5)
	{
		TCHAR LandOwner[5];
		BOOL bLine = TRUE;
		for (int j = 0; j < 5; j++)
		{
			// 라인 첫번째 땅이면 그 땅 주인을 얻어옴
			if (j == 0)
			{
				lstrcpy(LandOwner, Game.m_Lands[j + Inc].cLand_Owner);

				// 근데 빈 땅이면 걍 빠져 나옴
				if (lstrcmp(LandOwner, "") == 0)
				{
					bLine = FALSE;
					break;
				}
			}

			// 라인의 첫번째 땅 아니면
			else
			{
				// 첫 번째 땅 주인이랑 비교해서 같지 않으면 라인독점의 조건이 충족되지 않으니 빠져나옴
				if (lstrcmp(LandOwner, Game.m_Lands[j + Inc].cLand_Owner) != 0)
				{
					bLine = FALSE;
					break;
				}
			}
		}

		// 한 땅을 라인독점 했으면
		if (bLine == TRUE)
		{
			//이긴 처리 함수
			Game.Print_WinPlayer(Game.eCurPlayer, 1);
			return;
		}

		Sleep(500);
   }
}

void CLand::Build_Building(CGame &Game)
{
	int iNext_Line = 0;


	while (true)
	{
		//돈 부족 문구
		if (Game.m_Player[Game.eCurPlayer].iPlayer_Money < (iLand_Build_Price * (iLand_Building + 1)))
		{

			for (int i = 0; i < 2; i++, iNext_Line = 0)
			{

				g_DBBF.TextColor(WHITE, BLACK);
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 당신은 거지에요.. 돈이 모자라           │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 시군요?ㅋㅋㅋㅋㅋ 더 벌고 오세요        │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 건물을 지을 수 없네요~                  │");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────────────────────────┘");
#endif
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
			Sleep(300);
			return;
	}

		else if (Game.m_Player[Game.eCurPlayer].iPlayer_Money >(iLand_Build_Price * (iLand_Building + 1)) && (iLand_Building < MAX_BUILD))
		{

			// 건물 올라가는거는 1회만
			iLand_Building++;
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= (iLand_Build_Price + (iLand_Build_Price * iLand_Building));


			// 빌딩 수에 따라 출력 다르게
			switch (iLand_Building)
			{
			case 1:
				lstrcpy(cBuilding_Grade, (TCHAR*)"①");
				break;
			case 2:
				lstrcpy(cBuilding_Grade, (TCHAR*)"②");
				break;
			case 3:
				lstrcpy(cBuilding_Grade, (TCHAR*)"③");
				break;
			}
			for (int i = 0; i < 2; i++, iNext_Line = 0)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 건물을 짓습니다.(최대 3개까지 가능)     │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 랜드마크는 없어요!                      │");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────────────────────────┘");
#endif
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 건물을 더 짓습니다!!!♩♪               │");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────────────────────────┘");
#endif
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
			Sleep(300);
			return;
		}

		else if (iLand_Building >= MAX_BUILD)
		{
			for (int i = 0; i < 2; i++, iNext_Line = 0)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 건물을 더 지을 수 없습니다!!!           │");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 최대치인 3개를 다 채웠습니다.           │");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────────────────────────┘");
#endif
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
			Sleep(300);
			return;
		}

}
}

void CLand::Sell_Land(CGame &Game)
{
	ALL_LANDS Select_Land_Idx = WORLDTRIP_LAND;	// 초기 위치는 당연히 세계여행
	int Land_Diff = 1;
	int iHaveToGo_Idx = 0;
	COORD cLandPos;
	int iNext_Line = 0;
	while (true)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 팔 땅으로 이동하여 Enter키를 누르세요.  │");
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"│ 돈이 없어 땅을 팔아야합니다.            │");

#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
		BOOL bKeyDown = FALSE;

		if (KEY_DOWN(VK_RETURN))
		{
			g_DBBF.ClearBuffer();
			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_Dice_Result_Text(); //주사위 결과값 출력
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();
			//자신의 땅을 선택해야 셀랜드가 적용댄다.
			if (strcmp(Game.m_Lands[Select_Land_Idx].cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape) == 0)
				break;
		}


		if (KEY_DOWN(VK_LEFT))
		{
			// 서울 -> 출발
			if (Select_Land_Idx == SEOUL_LAND)	// 제일 큰 ~ 제일 작은 특수한 경우
				Select_Land_Idx = START_LAND;

			// 세계여행 ~ 무인도
			else if (Select_Land_Idx > ISLAND_LAND && Select_Land_Idx <= WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 황금열쇠 ~ 서울
			else if (Select_Land_Idx < SEOUL_LAND && Select_Land_Idx >= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;

		}

		if (KEY_DOWN(VK_RIGHT))
		{
			// 출발 -> 서울
			if (Select_Land_Idx == START_LAND)	// 제일 작은 ~ 제일 큰 특수한 경우
				Select_Land_Idx = SEOUL_LAND;

			// 서울 ~ 황금열쇠
			else if (Select_Land_Idx <= SEOUL_LAND && Select_Land_Idx > GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 무인도 ~ 세계여행
			else if (Select_Land_Idx >= ISLAND_LAND && Select_Land_Idx < WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_UP))
		{
			// 출발 ~ 무인도
			if (Select_Land_Idx >= START_LAND && Select_Land_Idx < ISLAND_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			// 황금열쇠 ~ 세계여행
			else if (Select_Land_Idx > WORLDTRIP_LAND && Select_Land_Idx <= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_DOWN))
		{
			// 무인도 ~ 출발
			if (Select_Land_Idx <= ISLAND_LAND && Select_Land_Idx > START_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 세계여행 ~ 황금열쇠
			else if (Select_Land_Idx >= WORLDTRIP_LAND && Select_Land_Idx < GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}


		if (bKeyDown == TRUE)
		{
			// 인덱스로 현재 땅의 위치를 조사해서 ExtraLand와 Land의 차이를 빼준다.
			if (Select_Land_Idx > START_LAND)
				Land_Diff = 1;

			if (Select_Land_Idx > ISLAND_LAND)
				Land_Diff = 2;

			if (Select_Land_Idx > WORLDTRIP_LAND)
				Land_Diff = 3;

			if (Select_Land_Idx > GOLDKEY_LAND)
				Land_Diff = 4;

			// 밟은 땅의 위치정보를 얻어온다.
			switch (Select_Land_Idx)
			{
			case START_LAND:	// 출발점
				cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
				break;

			case ISLAND_LAND:	// 무인도
				cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
				break;

			case WORLDTRIP_LAND:	// 세계여행
				cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
				break;

			case GOLDKEY_LAND:	// 황금열쇠
				cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
				break;

			default:
				cLandPos = Game.m_Lands[Select_Land_Idx - Land_Diff].Get_LandPosition();	// 현재 플레이어가 밟고 있는 땅의 좌표값을 얻어온다.
				break;
			}

			int AddPos = P1_POS * (Game.eCurPlayer + 1);	// 플레이어가 지정되어야 하는 위치에 맞게 좌표를 수정해주기 위해서

			cLandPos.X = (cLandPos.X + AddPos) - 2;
			cLandPos.Y += 2;


			Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
			Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(Select_Land_Idx);	// 최종 플레이어가 간 땅의 위치를 저장시킴
			Game.m_Lands[Select_Land_Idx].Print_Information(Select_Land_Idx);
			Game.eLandPrint_Idx = Select_Land_Idx;

			g_DBBF.ClearBuffer();
			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_Dice_Result_Text(); //주사위 결과값 출력
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();
		}

		Sleep(80);
	}
	Game.m_Player[Game.eCurPlayer].iPlayer_Money += Game.m_Lands[Game.eLandPrint_Idx].iTotal_LandPrice; //땅을판 돈을 받고
	lstrcpy(Game.m_Lands[Game.eLandPrint_Idx].cLand_Owner, (TCHAR*)""); // 땅의 주인을 없애버린다.

}