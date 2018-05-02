#pragma once
#include "CPlayer.h"
class CExtraLand
{
private:
	TCHAR * cLand_Name = nullptr;
	COORD pos;
public:
	CExtraLand();
	~CExtraLand();
	void Arrive_Land(CPlayer &Player);
	void Print_LandInfo();	// �� ���� ���
	void Set_LandInfo(TCHAR *cLand_Name, int x, int y);
	COORD Get_LandPosition();
};

