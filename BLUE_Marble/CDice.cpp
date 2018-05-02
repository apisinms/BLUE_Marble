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
	iDice1 = rand() % 6 + 1;
	iDice2 = rand() % 6 + 1;
	//iDice1 = 6;
	//iDice2 = 3;
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
	Print_Diceinfo();
	Print_DiceGage(Game);
}
void CDice::Print_DiceGage(CGame &Game)
{
	int iPower = 0;
	bool bUpdown = false;
	int iKey;	// 酈 殮溘
	int iCnt = 0;	// 1廓 幗ぷ, 2廓 幗ぷ 萃 棻 偽擎 �飛橉虞� 翕晦�倆牁襄� 2廓擊 霞чп撿 и棻.

	if (_kbhit())
	{
		iKey = _getch();
		if (iKey == ' ')
		{
			while (true)
			{

				if (_kbhit())
				{
					iKey = _getch();
					if (iKey == ' ')
					{
						// �膩�擠
						Game.PlayFX(FX_THROW_DICE);
						/// 轎溘 紫醞 蝶む檜蝶夥陛 揚葬賊 傳 翕晦�飛� п醜撿 и棻.(渦毀雖虜 橫聶 熱 橈橫, 詭憮萄 虜萄朝 啪 渦 渦楝遺)
						Sleep(600);
						
						g_DBBF.TextColor(BLACK, BLACK);
						for (int i = 0; i <= MAX_GAGE; i++)
							g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

						

						g_DBBF.FlippingBuffer();
						g_DBBF.TextColor(BLACK, BLACK);
						for (int i = 0; i <= MAX_GAGE; i++)
							g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");
						Game.Print_All_Tile();
						Game.Print_All_Land();
						Game.Print_All_ExtraLand();
						Game.Print_All_Character();
						Print_Diceinfo();

						Print_Dice_Result(Game);
						return;
					}
				}

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

				Sleep(1);

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
		}
	}

	else // 酈 殮溘檜 橈擊 衛縑朝 斜傖 棻 匐薑戲煎 瓣遺.
	{
		g_DBBF.TextColor(BLACK, BLACK);
		for (int i = 0; i <= MAX_GAGE; i++)
			g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

		//m_Dice.Throw_Dice();
	}
}
void CDice::Print_Dice_Result(CGame &Game)
{

	BOOL bIsDouble;	// 渦綰檜傍?
	BOOL bSoundPlayed = FALSE;	// 擠撩擊 營儅ц傍?
	COORD cLandPos;	// Ы溯檜橫陛 遺霜罹撿 й 階曖 ん雖暮
	ALL_LANDS ePlayerStand_Idx;	// ⑷營 Ы溯檜橫陛 嫖堅 氈朝 檣策蝶(Land + ExtraLand)
	int iDice_Result;	// 輿餌嬪 唸婁
	int AddPos;	// 陝 Ы溯檜橫葆棻 渦п醜撿 й 謝ル高
	int iHaveToGo_Idx = 0;	// 陛撿腎朝 檣策蝶


	bIsDouble = FALSE;
	iDice_Result = Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// 輿餌嬪 掉萼 唸婁蒂 橢橫褥
	ePlayerStand_Idx = Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex();	// Ы溯檜橫陛 嫖堅氈朝 階 檣策蝶


	if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE) // 譆渠 渦綰 �蝦� 剩橫陛賊
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// 渦綰 �蝦� 0戲煎
		/// 鼠檣紫 嬪纂蒂 橢橫諦憮 雖旎 Ы溯檜橫蒂 鼠檣紫煎 爾頂幗葡
		cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
		AddPos = P1_POS * (Game.eCurPlayer + 1);
		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;
		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
		Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
		Game.RePaint();

		/// 鼠檣紫 雲橫雖朝 模葬 營儅
		// 臢蝶お煎 "渦綰 3�� ж樟蝗棲棻." 轎溘
		Game.PlayFX(FX_ISLAND_ARRIVE);
		/// 棻擠 Ы溯檜橫煎
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);

		return;
	}

	int Land_Diff = 0;	// ExtraLand嫌 Land曖 離檜蒂 貍輿溥堅
	iHaveToGo_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// 陛撿й 階 = ⑷營 嫖擎 階 + 輿餌嬪 換 渦и 高


	for (int i = ePlayerStand_Idx + 1; i <= iHaveToGo_Idx; i++)
	{
		g_DBBF.ClearBuffer();

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

		/// 餌陝 顫橾 + 階 + か熱 階 + 議葛攪 轎溘
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.Print_All_Character();
		Print_Diceinfo();
		Sleep(PLAYER_MOVE_SPEED);
		g_DBBF.FlippingBuffer();
		// Ы溯檜橫 遺霜橾陽 葆棻 模葬 營儅
		Game.PlayFX(FX_PLAYER_MOVE);

		/// 輿餌嬪 擠撩 轎溘
		if (bSoundPlayed == FALSE)
		{
			// 渦綰 模葬 營儅
			if (bIsDouble == TRUE)
			{
				Game.PlayFX(FX_DICE_DOUBLE);
				Sleep(PLAYER_MOVE_SPEED);
			}
			Game.PlayFX(iDice_Result);

			bSoundPlayed = TRUE;
		}


		if (i == SEOUL_LAND)	// 檣策蝶陛 裘 部雖薄縑 紫殖ж賊 貍遽棻.
		{
			Game.PlayFX(FX_MONTH_PAY);	// 錯晝 模葬 營儅
			iHaveToGo_Idx -= SEOUL_LAND;
			i = START_LAND - 1;
		}
	}	// End For State

		// 葆雖虞縛 �飛橉� Clear陛 寰腎晦 陽僥縑 и廓 渦 斜溥醜撿 и棻.
	Game.RePaint();

	switch (iHaveToGo_Idx)
	{
	case WORLDTRIP_LAND:
		Game.PlayFX(FX_WORLDTRIP_ARRIVE);
		break;

	case GOLDKEY_LAND:
		Game.PlayFX(FX_GOLDKEY_ARRIVE);
		break;
	}

	Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// 譆謙 Ы溯檜橫陛 除 階曖 嬪纂蒂 盪濰衛霽


	if (bIsDouble == FALSE)
	{
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 棻擠 Ы溯檜橫煎
	}

	else // 渦綰檜賊
	{
		if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// 譆渠 渦綰 �蝦鰡轀鶼� 陛棟
		{
			Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt++;
			Game.eCurPlayer = Game.eCurPlayer;	// и 廓 渦!
		}
	}
}
