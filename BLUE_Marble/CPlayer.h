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
	ALL_LANDS eStand_idx = START_LAND;	// ��� �ִ� ��(���ۺ���)

public:
	CPlayer();
	~CPlayer();
	void Set_PlayerInfo(TCHAR *cPlayer_Shape, int x, int y, int money);
	void Print_PlayerInfo();
	void Move_PlayerPos(COORD pos);
	ALL_LANDS Get_PlayerStandIndex();
	void Set_PlayerStandIndex(ALL_LANDS eStand_idx);

	int iDiceDoubleCnt = 0;	// ���� Ƚ��
	int iLeftTurn = 0;	// ���ε� ������ �� ���� �� ��
	int iWorldTrip = WORLDTRIP_NONE;	// ���迩�� �ɷȴ���
	BOOL bPlayer_Dice_Double = FALSE;
};
#endif
