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
	int iNext_Line = 0;   // 다음 줄
	
	pos.X = DICE_POS_X;
	pos.Y = DICE_POS_Y;

	g_DBBF.TextColor(RED, BLACK);

	switch (iDice1)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;

	default:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;


	default:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
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
	int iKey;	// 키 입력
	int iCnt = 0;	// 1번 버퍼, 2번 버퍼 둘 다 같은 화면으로 동기화하려면 2번을 진행해야 한다.

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
						// 효과음
						Game.PlayFX(FX_THROW_DICE);
						/// 출력 도중 스페이스바가 눌리면 또 동기화를 해줘야 한다.(더럽지만 어쩔 수 없어, 메서드 만드는 게 더 더러움)
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

				if (bUpdown == FALSE && iPower < MAX_GAGE) //파워가 계속 와리가리 1부터9
				{
					iCnt++;
					if (iCnt == 2)
					{
						iCnt = 0;
						iPower++;
					}

					if (iPower == MAX_GAGE) //9가되면
						bUpdown = true; //최대치이다
				}
				else if (bUpdown == TRUE && iPower > 0)
				{
					iCnt++;
					if (iCnt == 2)
					{
						iCnt = 0;
						iPower--;
					}

					if (iPower == 0)  //파워가 0이면
						bUpdown = false;  //최소치이다.
				}

			}
		}
	}

	else // 키 입력이 없을 시에는 그냥 다 검정으로 채움.
	{
		g_DBBF.TextColor(BLACK, BLACK);
		for (int i = 0; i <= MAX_GAGE; i++)
			g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

		//m_Dice.Throw_Dice();
	}
}
void CDice::Print_Dice_Result(CGame &Game)
{

	BOOL bIsDouble;	// 더블이냐?
	BOOL bSoundPlayed = FALSE;	// 음성을 재생했냐?
	COORD cLandPos;	// 플레이어가 움직여야 할 땅의 포지션
	ALL_LANDS ePlayerStand_Idx;	// 현재 플레이어가 밟고 있는 인덱스(Land + ExtraLand)
	int iDice_Result;	// 주사위 결과
	int AddPos;	// 각 플레이어마다 더해줘야 할 좌표값
	int iHaveToGo_Idx = 0;	// 가야되는 인덱스


	bIsDouble = FALSE;
	iDice_Result = Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// 주사위 굴린 결과를 얻어옴
	ePlayerStand_Idx = Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex();	// 플레이어가 밟고있는 땅 인덱스


	if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE) // 최대 더블 횟수 넘어가면
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// 더블 횟수 0으로
		/// 무인도 위치를 얻어와서 지금 플레이어를 무인도로 보내버림
		cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
		AddPos = P1_POS * (Game.eCurPlayer + 1);
		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;
		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
		Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
		Game.RePaint();

		/// 무인도 떨어지는 소리 재생
		// 텍스트로 "더블 3회 하셨습니다." 출력
		Game.PlayFX(FX_ISLAND_ARRIVE);
		/// 다음 플레이어로
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);

		return;
	}

	int Land_Diff = 0;	// ExtraLand랑 Land의 차이를 빼주려고
	iHaveToGo_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// 가야할 땅 = 현재 밟은 땅 + 주사위 눈 더한 값


	for (int i = ePlayerStand_Idx + 1; i <= iHaveToGo_Idx; i++)
	{
		g_DBBF.ClearBuffer();

		// 인덱스로 현재 땅의 위치를 조사해서 ExtraLand와 Land의 차이를 빼준다.
		if (i > START_LAND)
			Land_Diff = 1;

		if (i > ISLAND_LAND)
			Land_Diff = 2;

		if (i > WORLDTRIP_LAND)
			Land_Diff = 3;

		if (i > GOLDKEY_LAND)
			Land_Diff = 4;

		// 밟은 땅의 위치정보를 얻어온다.
		switch (i)
		{
		case START_LAND:	// 출발점
			cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
			break;

		case ISLAND_LAND:	// 무인도
			cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
			break;

		case WORLDTRIP_LAND:	// 세계여행
			cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
			break;

		case GOLDKEY_LAND:	// 황금열쇠
			cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
			break;

		default:
			cLandPos = Game.m_Lands[i - Land_Diff].Get_LandPosition();	// 현재 플레이어가 밟고 있는 땅의 좌표값을 얻어온다.
			break;
		}

		AddPos = P1_POS * (Game.eCurPlayer + 1);	// 플레이어가 지정되어야 하는 위치에 맞게 좌표를 수정해주기 위해서

		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;

		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);

		/// 사각 타일 + 땅 + 특수 땅 + 캐릭터 출력
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.Print_All_Character();
		Print_Diceinfo();
		Sleep(PLAYER_MOVE_SPEED);
		g_DBBF.FlippingBuffer();
		// 플레이어 움직일때 마다 소리 재생
		Game.PlayFX(FX_PLAYER_MOVE);

		/// 주사위 음성 출력
		if (bSoundPlayed == FALSE)
		{
			// 더블 소리 재생
			if (bIsDouble == TRUE)
			{
				Game.PlayFX(FX_DICE_DOUBLE);
				Sleep(PLAYER_MOVE_SPEED);
			}
			Game.PlayFX(iDice_Result);

			bSoundPlayed = TRUE;
		}


		if (i == SEOUL_LAND)	// 인덱스가 맵 끝지점에 도달하면 빼준다.
		{
			Game.PlayFX(FX_MONTH_PAY);	// 월급 소리 재생
			iHaveToGo_Idx -= SEOUL_LAND;
			i = START_LAND - 1;
		}
	}	// End For State

		// 마지막엔 화면이 Clear가 안되기 때문에 한번 더 그려줘야 한다.
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

	Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// 최종 플레이어가 간 땅의 위치를 저장시킴


	if (bIsDouble == FALSE)
	{
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 다음 플레이어로
	}

	else // 더블이면
	{
		if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// 최대 더블 횟수까지는 가능
		{
			Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt++;
			Game.eCurPlayer = Game.eCurPlayer;	// 한 번 더!
		}
	}
}
