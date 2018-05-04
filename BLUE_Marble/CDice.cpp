#include "stdafx.h"
#include "CDice.h"
#include <time.h>
#include <conio.h>
#include "CGame.h"

CDice::CDice()
{
	srand((unsigned)time(NULL));
}
CDice::~CDice()
{
}

int CDice::Throw_Dice(int x, int y, BOOL *bIsDouble)
{
	pos.X = x;
	pos.Y = y;
	//iDice1 = rand() % 6 + 1;
	//iDice2 = rand() % 6 + 1;
	iDice1 = 2;
	iDice2 = 4;
	if (iDice1 == iDice2)
		*bIsDouble = TRUE;
	iDice_result = iDice1 + iDice2;
	return iDice_result;
}
void CDice::Print_Diceinfo()
{
	int iNext_Line = 0;   // 棻擠 還
	
	pos.X = DICE_POS_X;
	pos.Y = DICE_POS_Y;

	g_DBBF.TextColor(RED, BLACK);

	switch (iDice1)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;

	default:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒≒≒≒≒≒≒≒≒≒≒≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛              ≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛              ≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛        ≒≒≒≒≒≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛     ≒≒≒     弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;


	default:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛    ≒≒≒≒    弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛                弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"弛≒≒≒    ≒≒≒弛");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
		break;
	}

	// だ塭嘐攪 BOOL高擊 switchж罹 Idle Time 陽縑朝 楠渾戲煎 葆掘 轎溘и棻.

}
void CDice::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void CDice::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CDice::Dice_Proc(CGame &Game)
{
	if (Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_SOUND)
	{
		Game.PlayFX(FX_WORLDTRIP_WANT);
		Game.m_Player[Game.eCurPlayer].iWorldTrip = WORLDTRIP_MOVE;
	}
	Print_Diceinfo();
	Print_DiceGage(Game);
}

void CDice::Print_DiceGage(CGame &Game)
{
	static int iPower = 0;
	static BOOL bUpdown = FALSE;
	static BOOL bKeyDown = FALSE;
	static BOOL Roll_A_Dice = FALSE;
	//int iKey;	// 酈 殮溘
	static int iCnt = 0;	// 1廓 幗ぷ, 2廓 幗ぷ 萃 棻 偽擎 �飛橉虞� 翕晦�倆牁襄� 2廓擊 霞чп撿 и棻.


	// 蝶む檜蝶夥 酈蒂 援腦堅 氈朝 鼻鷓橾 陽
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		// �飛� 2偃檜棲 2廓 給溥憮 翕晦�� 衛麵遽棻
		for (int i = 0; i < 2; i++)
		{
			g_DBBF.ClearBuffer();
			if (bUpdown == FALSE)
			{
				int i = 0;

				g_DBBF.TextColor(RED, RED);
				for (i = 0; i <= iPower; i++)
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + iPower, DICE_POS_Y + 15, (TCHAR *)"  ");


				g_DBBF.TextColor(BLACK, WHITE);
				for (; i <= abs(MAX_GAGE - iPower); i++)
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

			}

			else
			{
				g_DBBF.TextColor(BLACK, WHITE);

				for (int i = 0; i <= iPower; i++)
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + iPower, DICE_POS_Y + 15, (TCHAR *)"  ");
			}

			//Sleep(1);

			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.Print_All_Character();
			Print_Diceinfo();

			g_DBBF.FlippingBuffer();

			if (bUpdown == FALSE && iPower < MAX_GAGE) //だ錶陛 啗樓 諦葬陛葬 1睡攪9
			{
				iCnt++;
				if (iCnt == 2)
				{
					iCnt = 0;
					iPower++;
				}

				if (iPower == MAX_GAGE) //9陛腎賊
					bUpdown = true; //譆渠纂檜棻
			}
			else if (bUpdown == TRUE && iPower > 0)
			{
				iCnt++;
				if (iCnt == 2)
				{
					iCnt = 0;
					iPower--;
				}

				if (iPower == 0)  //だ錶陛 0檜賊
					bUpdown = false;  //譆模纂檜棻.
			}
		}

  		Roll_A_Dice = TRUE;
	}

	// 蝶む檜蝶 酈蒂 亂擊 陽
	else
	{
		if (Roll_A_Dice == TRUE)
		{
			bUpdown = iCnt = iPower = 0;	// 滲熱菟擊 棻衛 蟾晦�倆媮眥�
			Game.PlayFX(FX_THROW_DICE);	// �膩�擠

			Sleep(600);	// �膩�擠 頂堅 濡衛 渠晦
			Print_Dice_Result(Game);	// 輿餌嬪 掉葡

			Roll_A_Dice = FALSE;	// 棻擠廓縑 檜 else僥 菟橫螃賊 輿餌嬪朝 棻衛 寰掉葡
		}

		else
		{
			// 匐擎儀戲煎 啪檜雖 夥蒂 瓣錶遽棻.
			g_DBBF.TextColor(BLACK, BLACK);
			for (int i = 0; i <= MAX_GAGE; i++)
				g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

			iDice1 = rand() % 6 + 1;
			iDice2 = rand() % 6 + 1;	// 輿餌嬪陛 啗樓 給嬴陛棻陛 蝶む檜蝶 酈 揚葬賊 '?'賅曄曖 輿餌嬪煎 夥莎棻
			Print_Diceinfo();
			Sleep(100);
		}
	}
}
void CDice::Print_Dice_Result(CGame &Game)
{
	BOOL bIsDouble = FALSE;	// 渦綰檜傍?
	BOOL bDoubleSound_Played = FALSE;	// 渦綰 擠撩檜 轎溘 腎歷傍?
	BOOL bDiceSound_Played = FALSE;	// 輿餌嬪 擠撩檜 轎溘 腎歷傍?
	COORD cLandPos;	// Ы溯檜橫陛 遺霜罹撿 й 階曖 ん雖暮
	ALL_LANDS ePlayerStand_Idx;	// ⑷營 Ы溯檜橫陛 嫖堅 氈朝 檣策蝶(Land + ExtraLand)
	int iDice_Result;	// 輿餌嬪 唸婁
	int AddPos;	// 陝 Ы溯檜橫葆棻 渦п醜撿 й 謝ル高
	int iHaveToGo_Idx = 0;	// 陛撿腎朝 檣策蝶

	iDice_Result = Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// 輿餌嬪 掉萼 唸婁蒂 橢橫褥
	ePlayerStand_Idx = Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex();	// Ы溯檜橫陛 嫖堅氈朝 階 檣策蝶

	if (Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
	{
		//Input_WorldTrip(Game);
	}
	

	// 鼠檣紫 勘溜朝等 渦綰檜賊 陴擎 欐擊 0戲煎 虜菟橫遽棻. 闊, 檜薯 遺霜檣棻.
	if (Game.m_Player[Game.eCurPlayer].iLeftTurn > 0 && bIsDouble == TRUE)
		Game.m_Player[Game.eCurPlayer].iLeftTurn = 0;

	// 鼠檣紫縑 陘⑼朝等 湍霞 輿餌嬪陛 渦綰檜 嬴棲賊 斜傖 剩橫除棻.
	else if (Game.m_Player[Game.eCurPlayer].iLeftTurn > 0 && bIsDouble == FALSE)
	{
		Sleep(PLAYER_MOVE_SPEED);
		Game.PlayFX(iDice_Result);	// 模葬虜 釭螃堅 雄
		Game.m_Player[Game.eCurPlayer].iLeftTurn--;	// 1欐 雖陴

		// 棻擠 Ы溯檜橫煎
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 棻擠 Ы溯檜橫煎
		return;
	}


	// 渦綰 譆渠�蝦鶺庰� 虜擒縑 渦綰 傳 釭螃賊
	if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE && bIsDouble == TRUE) 
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// 渦綰 �蝦� 0戲煎

		/// 鼠檣紫 雲橫雖朝 模葬 營儅
		// 臢蝶お煎 "渦綰 3�� ж樟蝗棲棻." 轎溘
		Game.PlayFX(FX_DICE_DOUBLE);
		Sleep(PLAYER_MOVE_SPEED + 50);
		Game.PlayFX(iDice_Result);
		Sleep(200);
		Game.PlayFX(FX_ISLAND_ARRIVE);

		/// 鼠檣紫 嬪纂蒂 橢橫諦憮 雖旎 Ы溯檜橫蒂 鼠檣紫煎 爾頂幗葡
		cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
		AddPos = P1_POS * (Game.eCurPlayer + 1);
		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;
		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
		Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
		Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;	// 陴擎 欐 熱 3��
		Game.RePaint(FALSE);
		Game.RePaint(FALSE);	// 舒 �飛� 賅舒 偵褐脹 嬪纂煎

		/// 棻擠 Ы溯檜橫煎
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);

		return;
	}

	int Land_Diff = 0;	// ExtraLand嫌 Land曖 離檜蒂 貍輿溥堅
	iHaveToGo_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// 陛撿й 階 = ⑷營 嫖擎 階 + 輿餌嬪 換 渦и 高

	// 陛撿ж朝 階梱雖 и 蘊噶 檜翕 衛鑑棻.
	for (int i = ePlayerStand_Idx + 1; i <= iHaveToGo_Idx; i++)
	{
		// 檣策蝶煎 ⑷營 階曖 嬪纂蒂 褻餌п憮 ExtraLand諦 Land曖 離檜蒂 貍遽棻.
		if (i > START_LAND)
			Land_Diff = 1;

		if (i > ISLAND_LAND)
			Land_Diff = 2;

		if (i > WORLDTRIP_LAND)
			Land_Diff = 3;

		if (i > GOLDKEY_LAND)
			Land_Diff = 4;

		// 嫖擎 階曖 嬪纂薑爾蒂 橢橫螞棻.
		switch (i)
		{
		case START_LAND:	// 轎嫦薄
			cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
			break;

		case ISLAND_LAND:	// 鼠檣紫
			cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
			break;

		case WORLDTRIP_LAND:	// 撮啗罹ч
			cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
			break;

		case GOLDKEY_LAND:	// �盛暆乘�
			cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
			break;

		default:
			cLandPos = Game.m_Lands[i - Land_Diff].Get_LandPosition();	// ⑷營 Ы溯檜橫陛 嫖堅 氈朝 階曖 謝ル高擊 橢橫螞棻.
			break;
		}

		AddPos = P1_POS * (Game.eCurPlayer + 1);	// Ы溯檜橫陛 雖薑腎橫撿 ж朝 嬪纂縑 蜃啪 謝ル蒂 熱薑п輿晦 嬪п憮

		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;


		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);

		/// 輿餌嬪 擠撩 轎溘
		if (bDiceSound_Played == FALSE)
		{
			/// 渦綰 擠撩 轎溘
			if (bDoubleSound_Played == FALSE)
			{
				bDoubleSound_Played = TRUE;

				// 渦綰 模葬 營儅
				if (bIsDouble == TRUE)
				{
					Game.PlayFX(FX_DICE_DOUBLE);
					Sleep(PLAYER_MOVE_SPEED + 50);	// 渦綰~ 擠撩 裁溯檜
				}

			}
			bDiceSound_Played = TRUE;
			Game.PlayFX(iDice_Result);
		}

		g_DBBF.ClearBuffer();
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.Print_All_Character();
		Game.m_Dice.Print_Diceinfo();

		Sleep(PLAYER_MOVE_SPEED);

		g_DBBF.FlippingBuffer();

		/// 餌陝 顫橾 + 階 + か熱 階 + 議葛攪 轎溘
		//Game.RePaint();

		// Ы溯檜橫 遺霜橾陽 葆棻 模葬 營儅(渦綰縑憮朝 偽檜 模葬蒂 頂鍍戲棲 薯諼)
			Game.PlayFX(FX_PLAYER_MOVE);
		

		// 錯晝 模葬 營儅
		if(i == START_LAND)
			Game.PlayFX(FX_MONTH_PAY);

		if (i == SEOUL_LAND)	// 檣策蝶陛 裘 部雖薄縑 紫殖ж賊 貍遽棻.
		{
			iHaveToGo_Idx -= SEOUL_LAND + 1;
			i = START_LAND - 1;
		}
	}// End For State

	// 葆雖虞縛 �飛橉� Clear陛 寰腎晦 陽僥縑 и廓 渦 斜溥醜撿 и棻.
	Game.RePaint(TRUE);

	switch (iHaveToGo_Idx)
	{
	case ISLAND_LAND:
		Game.PlayFX(FX_ISLAND_ARRIVE);	// 模葬 頂堅
		Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;	// 3欐除 薑雖
		bIsDouble = FALSE;	// 渦綰 �膩�評孺 橈戲棲 棻擠 Ы溯檜橫煎
		break;

	case WORLDTRIP_LAND:
		Game.PlayFX(FX_WORLDTRIP_ARRIVE);
		Game.m_Player[Game.eCurPlayer].iWorldTrip = WORLDTRIP_SOUND;
		break;

	case GOLDKEY_LAND:
		Game.PlayFX(FX_GOLDKEY_ARRIVE);
		break;
	}

	Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// 譆謙 Ы溯檜橫陛 除 階曖 嬪纂蒂 盪濰衛霽


	if (bIsDouble == FALSE || Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_SOUND)	// 渦綰 寰釭諮剪釭 撮啗罹ч 勘溜擊 衛
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// 渦綰檜 寰釭諮戲賊 渦綰擊 0戲煎 撢たп醜撿и棻.

		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 棻擠 Ы溯檜橫煎
	}

	else // 渦綰檜賊
	{
		if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// 譆渠 渦綰 �蝦鰡轀鶼� 陛棟
		{
			Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt++;	// 渦綰 �蝦鷏� 1�蜀� 
			Game.eCurPlayer = Game.eCurPlayer;	// и 廓 渦!
		}
	}
}

void CDice::Input_WorldTrip(CGame &Game)
{
	
}
