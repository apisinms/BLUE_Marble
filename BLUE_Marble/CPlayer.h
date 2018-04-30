#pragma once
#include "CLand.h"
#include "CDoubleBuffering.h"
class CLand;
class CPlayer
{
	friend CLand;	// CLand�� private ������� �����ϱ� ���ؼ�
private:
	int iPlayer_Money;
	TCHAR *cPlayer_Shape;
	COORD pos;
public:
	CPlayer();
	~CPlayer();
	void Set_PlayerInfo(TCHAR *cPlayer_Shape, int x, int y);
	void Print_PlayerInfo();
};

