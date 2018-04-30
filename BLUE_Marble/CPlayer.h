#pragma once
#include "CLand.h"
#include "CDoubleBuffering.h"
class CLand;
class CPlayer
{
	friend CLand;	// CLand의 private 멤버들을 접근하기 위해서
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

