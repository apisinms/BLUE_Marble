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
	int iNext_Line = 0;   // ���� ��
	
	pos.X = DICE_POS_X;
	pos.Y = DICE_POS_Y;

	g_DBBF.TextColor(RED, BLACK);

	switch (iDice1)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	default:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;


	default:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
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
	int iKey;	// Ű �Է�
	int iCnt = 0;	// 1�� ����, 2�� ���� �� �� ���� ȭ������ ����ȭ�Ϸ��� 2���� �����ؾ� �Ѵ�.

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
						// ȿ����
						Game.PlayFX(FX_THROW_DICE);
						/// ��� ���� �����̽��ٰ� ������ �� ����ȭ�� ����� �Ѵ�.(�������� ��¿ �� ����, �޼��� ����� �� �� ������)
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

				if (bUpdown == FALSE && iPower < MAX_GAGE) //�Ŀ��� ��� �͸����� 1����9
				{
					iCnt++;
					if (iCnt == 2)
					{
						iCnt = 0;
						iPower++;
					}

					if (iPower == MAX_GAGE) //9���Ǹ�
						bUpdown = true; //�ִ�ġ�̴�
				}
				else if (bUpdown == TRUE && iPower > 0)
				{
					iCnt++;
					if (iCnt == 2)
					{
						iCnt = 0;
						iPower--;
					}

					if (iPower == 0)  //�Ŀ��� 0�̸�
						bUpdown = false;  //�ּ�ġ�̴�.
				}

			}
		}
	}

	else // Ű �Է��� ���� �ÿ��� �׳� �� �������� ä��.
	{
		g_DBBF.TextColor(BLACK, BLACK);
		for (int i = 0; i <= MAX_GAGE; i++)
			g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

		//m_Dice.Throw_Dice();
	}
}
void CDice::Print_Dice_Result(CGame &Game)
{

	BOOL bIsDouble;	// �����̳�?
	BOOL bSoundPlayed = FALSE;	// ������ ����߳�?
	COORD cLandPos;	// �÷��̾ �������� �� ���� ������
	ALL_LANDS ePlayerStand_Idx;	// ���� �÷��̾ ��� �ִ� �ε���(Land + ExtraLand)
	int iDice_Result;	// �ֻ��� ���
	int AddPos;	// �� �÷��̾�� ������� �� ��ǥ��
	int iHaveToGo_Idx = 0;	// ���ߵǴ� �ε���


	bIsDouble = FALSE;
	iDice_Result = Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// �ֻ��� ���� ����� ����
	ePlayerStand_Idx = Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex();	// �÷��̾ ����ִ� �� �ε���


	if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE) // �ִ� ���� Ƚ�� �Ѿ��
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// ���� Ƚ�� 0����
		/// ���ε� ��ġ�� ���ͼ� ���� �÷��̾ ���ε��� ��������
		cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
		AddPos = P1_POS * (Game.eCurPlayer + 1);
		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;
		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
		Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
		Game.RePaint();

		/// ���ε� �������� �Ҹ� ���
		// �ؽ�Ʈ�� "���� 3ȸ �ϼ̽��ϴ�." ���
		Game.PlayFX(FX_ISLAND_ARRIVE);
		/// ���� �÷��̾��
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);

		return;
	}

	int Land_Diff = 0;	// ExtraLand�� Land�� ���̸� ���ַ���
	iHaveToGo_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// ������ �� = ���� ���� �� + �ֻ��� �� ���� ��


	for (int i = ePlayerStand_Idx + 1; i <= iHaveToGo_Idx; i++)
	{
		g_DBBF.ClearBuffer();

		// �ε����� ���� ���� ��ġ�� �����ؼ� ExtraLand�� Land�� ���̸� ���ش�.
		if (i > START_LAND)
			Land_Diff = 1;

		if (i > ISLAND_LAND)
			Land_Diff = 2;

		if (i > WORLDTRIP_LAND)
			Land_Diff = 3;

		if (i > GOLDKEY_LAND)
			Land_Diff = 4;

		// ���� ���� ��ġ������ ���´�.
		switch (i)
		{
		case START_LAND:	// �����
			cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
			break;

		case ISLAND_LAND:	// ���ε�
			cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
			break;

		case WORLDTRIP_LAND:	// ���迩��
			cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
			break;

		case GOLDKEY_LAND:	// Ȳ�ݿ���
			cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
			break;

		default:
			cLandPos = Game.m_Lands[i - Land_Diff].Get_LandPosition();	// ���� �÷��̾ ��� �ִ� ���� ��ǥ���� ���´�.
			break;
		}

		AddPos = P1_POS * (Game.eCurPlayer + 1);	// �÷��̾ �����Ǿ�� �ϴ� ��ġ�� �°� ��ǥ�� �������ֱ� ���ؼ�

		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;

		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);

		/// �簢 Ÿ�� + �� + Ư�� �� + ĳ���� ���
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.Print_All_Character();
		Print_Diceinfo();
		Sleep(PLAYER_MOVE_SPEED);
		g_DBBF.FlippingBuffer();
		// �÷��̾� �����϶� ���� �Ҹ� ���
		Game.PlayFX(FX_PLAYER_MOVE);

		/// �ֻ��� ���� ���
		if (bSoundPlayed == FALSE)
		{
			// ���� �Ҹ� ���
			if (bIsDouble == TRUE)
			{
				Game.PlayFX(FX_DICE_DOUBLE);
				Sleep(PLAYER_MOVE_SPEED);
			}
			Game.PlayFX(iDice_Result);

			bSoundPlayed = TRUE;
		}


		if (i == SEOUL_LAND)	// �ε����� �� �������� �����ϸ� ���ش�.
		{
			Game.PlayFX(FX_MONTH_PAY);	// ���� �Ҹ� ���
			iHaveToGo_Idx -= SEOUL_LAND;
			i = START_LAND - 1;
		}
	}	// End For State

		// �������� ȭ���� Clear�� �ȵǱ� ������ �ѹ� �� �׷���� �Ѵ�.
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

	Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// ���� �÷��̾ �� ���� ��ġ�� �����Ŵ


	if (bIsDouble == FALSE)
	{
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// ���� �÷��̾��
	}

	else // �����̸�
	{
		if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// �ִ� ���� Ƚ�������� ����
		{
			Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt++;
			Game.eCurPlayer = Game.eCurPlayer;	// �� �� ��!
		}
	}
}
