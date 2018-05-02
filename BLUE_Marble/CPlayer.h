#ifndef __CPLAYER__
#define __CPLAYER__
//#include "stdafx.h"
//#include "CLand.h"
//#include "CDoubleBuffering.h"

class CLand;
class CPlayer
{
	friend CLand;	// CLand의 private 멤버들을 접근하기 위해서
private:
	int iPlayer_Money;
	TCHAR *cPlayer_Shape;
	COORD pos;
	ALL_LANDS eStand_idx = START_LAND;	// 밟고 있는 땅(시작부터)

public:
	CPlayer();
	~CPlayer();
	void Set_PlayerInfo(TCHAR *cPlayer_Shape, int x, int y);
	void Print_PlayerInfo();
	void Move_PlayerPos(COORD pos);
	ALL_LANDS Get_PlayerStandIndex();
	void Set_PlayerStandIndex(ALL_LANDS eStand_idx);

	int iDiceDoubleCnt = 0;	// 더블 횟수
};
#endif
