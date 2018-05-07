#ifndef __CPLAYER__
#define __CPLAYER__
#define PLAYER_START_MONEY 200000

class CLand;
class CDice;
class CPlayer
{
	friend CDice;
	friend CLand;
private:
	int iPlayer_Money;
	TCHAR *cPlayer_Shape;
	COORD pos;
	ALL_LANDS eStand_idx = START_LAND;	// 밟고 있는 땅(시작부터)

public:
	CPlayer();
	~CPlayer();
	void Set_PlayerInfo(TCHAR *cPlayer_Shape, int x, int y, int money);
	void Print_PlayerInfo();
	void Move_PlayerPos(COORD pos);
	ALL_LANDS Get_PlayerStandIndex();
	void Set_PlayerStandIndex(ALL_LANDS eStand_idx);

	int iDiceDoubleCnt = 0;	// 더블 횟수
	int iLeftTurn = 0;	// 무인도 갇혔을 때 남은 턴 수
	int iWorldTrip = WORLDTRIP_NONE;	// 세계여행 걸렸는지
	BOOL bPlayer_Dice_Double = FALSE;
};
#endif
