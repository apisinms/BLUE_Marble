#include "stdafx.h"
#include "CPlayer.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	if (cPlayer_Shape != NULL)
	{
		cPlayer_Shape = nullptr;
		delete[]cPlayer_Shape;
	}
}


void CPlayer::Set_PlayerInfo(TCHAR *cPlayer_Shape, int x, int y, int money)
{
	this->cPlayer_Shape = new TCHAR[lstrlen(cPlayer_Shape)];
	lstrcpy(this->cPlayer_Shape, cPlayer_Shape);
	pos.X = x;
	pos.Y = y;
	iPlayer_Money = money;
	iPlayer_Total_Money = 0;
}

void CPlayer::Print_PlayerInfo()
{
	g_DBBF.WriteBuffer(pos.X, pos.Y, cPlayer_Shape);
}

ALL_LANDS CPlayer::Get_PlayerStandIndex()
{
	return eStand_idx;
}

void CPlayer::Move_PlayerPos(COORD pos)
{
	this->pos = pos;
}

void CPlayer::Set_PlayerStandIndex(ALL_LANDS eStand_idx)
{
	this->eStand_idx = eStand_idx;
}


