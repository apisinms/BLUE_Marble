#include "stdafx.h"
#include "CExtraLand.h"
#include "CPlayer.h"

CExtraLand::CExtraLand()
{
}
CExtraLand::~CExtraLand()
{
	if (cLand_Name != NULL)
	{
		cLand_Name = nullptr;
		delete[]cLand_Name;
	}
}

void CExtraLand::Arrive_Land(CPlayer &Player)
{
	if (lstrcmp(cLand_Name, (TCHAR *)"출    발") == 0)
	{
		// 출발 함수 호출
	}

	else if (lstrcmp(cLand_Name, (TCHAR *)"무 인 도") == 0)
	{

	}
	else if (lstrcmp(cLand_Name, (TCHAR *)"세계여행") == 0)
	{

	}
	else if (lstrcmp(cLand_Name, (TCHAR *)"황금열쇠") == 0)
	{

	}
}

void CExtraLand::Print_LandInfo()
{
	g_DBBF.WriteBuffer(pos.X, pos.Y, cLand_Name);
}

void CExtraLand::Set_LandInfo(TCHAR *cLand_Name, int x, int y)
{
	this->cLand_Name = new TCHAR[lstrlen(cLand_Name)];
	lstrcpy(this->cLand_Name, cLand_Name);
	pos.X = x;
	pos.Y = y;
}