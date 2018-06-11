//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit�� ����ϱ� ���ؼ�
#include <ctime>


CDoubleBuffering g_DBBF;	// ���� ��¥�� ���Ǹ� �Ѵ�(��ü�� �Ҵ�ȴ�)
FMOD_SYSTEM *g_System;	// FMOD System ����
FMOD_SOUND *g_FX_Sound[MAX_FX];	// ȿ������ ��������
CGame::CGame()
{
	srand((unsigned int)time(NULL));	// ���� ����
	g_DBBF.CreatBuffer();	// ������۸��� ���� ���۸� ������.

	/// Land�� ������ �ʱ�ȭ�Ѵ�.
	{
		// Left����
		m_Lands[0].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[1].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ¡", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[2].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"Ÿ������", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[3].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[4].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"ī �� ��", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Top ����
		m_Lands[5].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 5) - 1, 1);
		m_Lands[6].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 9) - 2, 1);
		m_Lands[7].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 13) - 3, 1);
		m_Lands[8].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 17) - 4, 1);
		m_Lands[9].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"���Ŀ��", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 21) - 5, 1);

		// Right ����
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��ũ��", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));

		// Bottom ����
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}

	///ExtranLands�� ���� ������ �ʱ�ȭ �Ѵ�.
	{
		m_ExtranLands[0].Set_LandInfo((TCHAR *)"��    ��", LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_ExtranLands[1].Set_LandInfo((TCHAR *)"�� �� ��", LAND_TEXT_VERTICAL, 1);
		m_ExtranLands[2].Set_LandInfo((TCHAR *)"���迩��", (LAND_TEXT_VERTICAL * 25) - 6, 1);
		m_ExtranLands[3].Set_LandInfo((TCHAR *)"Ȳ�ݿ���", (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}
	

	/// ���忡 ���� ������ �ʱ�ȭ �Ѵ�.
	{
		// ���� �ý��� �ʱ�ȭ
		FMOD_System_Create(&g_System);	// ��ü ����
		FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);	//�ʱ�ȭ

		/// ���� ���� BGM
		FMOD_System_CreateSound(g_System, "Sounds\\BGM\\BGM_Intro.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INTRO]);
		FMOD_System_CreateSound(g_System, "Sounds\\BGM\\BGM_InputPlayer.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INPUTPLAYER]);
		
		char location[100];
		for (int i = 0; i < 4; i++)
		{
			wsprintf(location, TEXT("Sounds\\BGM\\BGM_GamePlay%d.mp3"), i + 1);
			FMOD_System_CreateSound(g_System, location, FMOD_DEFAULT, 0, &BGM_Music[BGM1 + i]);
		}


		/// ���� ���� ȿ����
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_MonthPay.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_MONTH_PAY]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_IslandArrive.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_ISLAND_ARRIVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_WorldTripArrive.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WORLDTRIP_ARRIVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_GoldKeyArrive.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_GOLDKEY_ARRIVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_PlayerMove.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_PLAYER_MOVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_Build.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_BUILD]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_ThrowDice.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_THROW_DICE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_Win.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WIN]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_Double.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_DICE_DOUBLE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_WorldTripWant.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WORLDTRIP_WANT]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_WorldTripFly.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WORLDTRIP_FLY]);

		for (int i = 0; i < 12; i++)
		{
			wsprintf(location, TEXT("Sounds\\FX\\FX_DiceNum_%d.mp3"), i + 1);
			FMOD_System_CreateSound(g_System, location, FMOD_DEFAULT, 0, &g_FX_Sound[FX_DICENUM1 + i]);
		}

	}
}

CGame::~CGame()
{
	g_DBBF.DeleteBuffer();	// ���� ���۸��� ��� ��������� �ڿ��� �ݳ���.
	
	/// ���� ����
	for (int i = 0; i < MAX_BGM; i++)
		FMOD_Sound_Release(BGM_Music[i]);
	for (int i = 0; i < MAX_FX; i++)
		FMOD_Sound_Release(g_FX_Sound[i]);

	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);

	delete[] m_Player;
}

// ��ü���� ���� ����
void CGame::PlayGame()
{
	PrintIntro();
	Input_PlayerNum();	// �÷��̾��� ���� �Է¹޴´�.
	Print_Game_Board();	// ���� �� ���
}
// ó�� ȭ�� ���
void CGame::PrintIntro()
{
	FMOD_System_PlaySound(g_System, BGM_Music[INTRO], NULL, FALSE, &BGM_Channel[INTRO]);	// ��� ���
	FMOD_Channel_SetVolume(BGM_Channel[INTRO], 0.5f);

	int x, y;
	x = 50;
	y = 0;
	int color = BLUE;
	while (true)
	{
		if (_kbhit())
		{
			_getch();	// ���ۿ� ����(��� ���� �ƹ�Ű) Ű�� ������.
			break;
		}

		// �η縶�� ��� ��
		g_DBBF.TextColor(color++, BLACK);
		color = (color >= 16) ? BLUE : color;
		g_DBBF.WriteBuffer(0, 0, IntroMessage);


		// �ȳ����� ��� ��
		g_DBBF.TextColor(WHITE, BLACK);
		g_DBBF.WriteBuffer(80, 35, (TCHAR *)"������ �����Ϸ��� �ƹ� Ű�� ��������");

		// ���� ��ȯ �� Ŭ����
		g_DBBF.FlippingBuffer();
		g_DBBF.ClearBuffer();

		Sleep(150);
	}

}
// ����� �÷��� �� ������ �Է¹���
void CGame::Input_PlayerNum()	// �÷��̾��� ���� �Է¹޴´�
{
	int num = 0;
	FMOD_Channel_Stop(BGM_Channel[INTRO]);
	FMOD_System_PlaySound(g_System, BGM_Music[INPUTPLAYER], NULL, FALSE, &BGM_Channel[INPUTPLAYER]);	// ��� ���
	FMOD_Channel_SetVolume(BGM_Channel[INPUTPLAYER], 0.5f);
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));	// ���� ��ũ������ ����(������۸� x)
	TextColor(WHITE, BLACK);
	while (true)
	{
		MoveXY(75, 15);	// ���� ���۸��� ������� ���� �� Ŀ�� ��ǥ �ű��
		cout << "�÷��̾��� ���� �Է��ϼ���(2~4��) : ";
		cin >> num;	// �÷��̾� ���� �Է¹���
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');	// ���۾ȿ� �����ִ� ��� ��� ����
		}
		system("cls");	// �������� ȭ�� �����
		if (num >= 2 && num <= 4)
		{
			iPlayerNum = num;
			m_Player = new CPlayer[num];	// �÷��̾ �����Ҵ���
			/// Player�� �ʱ� ������ �����Ѵ�.
			{
				if (num >= 2)
				{
					m_Player[0].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P1_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
					m_Player[1].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P2_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
				}

				if (num >= 3)
					m_Player[2].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P3_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);

				if (num >= 4)
					m_Player[3].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P4_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
			}
			
			while (true)
			{
				iCurBGM = rand() % (BGM4 + 1);
				if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
					break;
			}
			FMOD_Channel_Stop(BGM_Channel[INPUTPLAYER]);
			FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// ��� ���
			FMOD_Channel_SetVolume(BGM_Channel[iCurBGM], 0.5f);
			break;
		}
	}
}

// ���� ���۸��� ������� ���� ���� ���� ���� ����
void CGame::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ��ü ���� Ÿ�� ��� ���
void CGame::Print_Game_Board()
{
	system("mode con cols=190 lines=50");	// ȭ�� ũ�� �ٽ� �ø�
	BOOL bPlayerTurn_FirstPrint = FALSE;

	while (true)
	{

		g_DBBF.ClearBuffer();	// ���� ������ ������ ��� �����ش�.
		if(bPlayerTurn_FirstPrint == FALSE)
			Print_Player_Turn();

		/// �ʺ�� ���̿� �°� ����Ͽ� Ÿ���� ����Ѵ�.
		Print_All_Tile();
		/// �� + Ư�� �� ���� ���
		Print_All_Land();
		Print_All_ExtraLand();
		
		m_Lands->Print_Information(eLandPrint_Idx);
		/// �ֻ��� ��� �� �ֻ��� ������
 		m_Dice.Dice_Proc(*this);
		/// ĳ���� ���� ���(�ֻ��� �������� �ʾ��� ����, �ֻ��� ���� ���� Dice���� �˾Ƽ� ó���ϴϱ�)
		Print_All_Character();
		Print_Player_Infor();	// �÷��̾� ���� ���
		/// ���� ������Ʈ
		Check_BGM();
		FMOD_System_Update(g_System);	// �� �Լ��� ��������� ȣ������� ���尡 ������ �ʴ´�.

		g_DBBF.FlippingBuffer();	// ���۸� �ٲ��ش�(������۸�)
		Sleep(1);
	}
}

void CGame::Print_Indivisual_Tile(int x, int y) //���� Ÿ�� ���  �׸� 1��.
{
	int iNext_Line = 0;	// ���� ��
#if OS_VER == 7
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
#if OS_VER == 7
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
	//Ÿ�� ũ�� ���� , �� 7 ,�� 10

}

void CGame::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CGame::Print_All_Tile()
{
	int i, j;
	i = j = 0;
	for (eBoardLTRB = LEFT, i = 0; i < 4;)
	{
		for (j = 0; j < LAND_LINE_LEN; j++)
		{
			switch (eBoardLTRB)
			{
			case LEFT:	// o
				g_DBBF.TextColor(LIGHTGREEN, BLACK);

				if (j == 0)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile(0, j * (TILE_VERTICAL_LEN + TILE_DISTANCE));
				break;

			case TOP:
				g_DBBF.TextColor(LIGHTBLUE, BLACK);

				if (j == LAND_LINE_LEN - 1)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile((j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE)) + (TILE_HORIZONTAL_LEN + TILE_DISTANCE), 0);
				break;

			case RIGHT:
				g_DBBF.TextColor(LIGHTMAGENTA, BLACK);

				if (j == LAND_LINE_LEN - 1)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile((TILE_HORIZONTAL_LEN * (LAND_LINE_LEN + 1)) + (TILE_DISTANCE - 1), (j * (TILE_VERTICAL_LEN + TILE_DISTANCE)) + (TILE_VERTICAL_LEN + TILE_DISTANCE));
				break;

			case BOTTOM:
				g_DBBF.TextColor(LIGHTRED, BLACK);

				if (j == 0)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile(j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE), (TILE_VERTICAL_LEN + TILE_DISTANCE) * LAND_LINE_LEN);
				break;
			}
		}
		eBoardLTRB = (BOARD_LTRB)++i;
	}
}

void CGame::Print_All_Land()
{
	// �� ������ ����Ѵ�.
	for (int i = 0; i < 20; i++)
	{
		m_Lands[i].Print_LandInfo();
	}
}

void CGame::Print_All_ExtraLand()
{
	// Ư�� �� ������ ����Ѵ�
	g_DBBF.TextColor(BROWN, BLACK);
	for (int i = 0; i < 4; i++)
		m_ExtranLands[i].Print_LandInfo();
}

void CGame::Print_All_Character()
{
	/// �÷��̾� ĳ���� ���
	for (int i = 0; i < iPlayerNum; i++)
	{
		switch (i)
		{
		case P1:
			g_DBBF.TextColor(P1_COLOR, BLACK);
			break;

		case P2:
			g_DBBF.TextColor(P2_COLOR, BLACK);
			break;

		case P3:
			g_DBBF.TextColor(P3_COLOR, BLACK);
			break;

		case P4:
			g_DBBF.TextColor(P4_COLOR, BLACK);
			break;
		}
		m_Player[i].Print_PlayerInfo();

	}

}

void CGame::Check_BGM()
{
	FMOD_BOOL bSoundPlaying = TRUE;
	/// �뷡 ��� �������� �ٸ� �������� ���
	FMOD_Channel_IsPlaying(BGM_Channel[iCurBGM], &bSoundPlaying);
	if (bSoundPlaying == FALSE)
	{
		while (true)
		{
			iCurBGM = rand() % (BGM4 + 1);
			if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
				break;
		}
		FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// ��� ���
		FMOD_Channel_SetVolume(BGM_Channel[iCurBGM], 0.5f);
	}
}

void CGame::RePaint(BOOL bSleep)
{
	g_DBBF.ClearBuffer();
	Print_All_Tile();
	Print_All_Land();
	Print_All_ExtraLand();
	m_Lands->Print_Information(eLandPrint_Idx);
	Print_All_Character();
	m_Dice.Print_Diceinfo();
	Print_Player_Infor();
	Print_Dice_Result_Text(); //�ֻ��� ����� ���

	if(bSleep == TRUE)
		Sleep(PLAYER_MOVE_SPEED);

	g_DBBF.FlippingBuffer();
}

void CGame::Print_Dice_Gage()
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
						/// ��� ���� �����̽��ٰ� ������ �� ����ȭ�� ����� �Ѵ�.(�������� ��¿ �� ����, �޼��� ����� �� �� ������)
						Sleep(600);

						g_DBBF.TextColor(BLACK, BLACK);
						for (int i = 0; i <= MAX_GAGE; i++)
							g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

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

				Print_All_Tile();
				Print_All_Land();
				Print_All_ExtraLand();
				Print_All_Character();
				m_Dice.Print_Diceinfo();

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

void CGame::PlayFX(int idx)
{
	FMOD_CHANNEL *tmp_Channel;	// �ӽ� ä��
	FMOD_System_PlaySound(g_System, g_FX_Sound[idx], NULL, FALSE, &tmp_Channel);	// �ֻ��� ���� ���
	FMOD_Channel_SetVolume(tmp_Channel, 0.5f);	// �Ҹ��� ������
}

void CGame::Print_Player_Turn()
{
	char cPlayer_TurnPrint[100];
	char cGoldKey_Print[100];  // Ȳ�ݿ��� ��� ���ڿ�
	int iNext_Line = 0;
	int iTurn_Print = NULL;
	iTurn_Print = (int)eCurPlayer + 1;
	g_DBBF.TextColor(WHITE, BLACK);
	if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
		wsprintf(cPlayer_TurnPrint, "�� �÷��̾� %d�� �����Դϴ�. ���ϴ� ������ �����ϼ��䦢", iTurn_Print);
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)cPlayer_TurnPrint);
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
}

	else if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_NONE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		wsprintf(cPlayer_TurnPrint, "�� �÷��̾� %d�� �����Դϴ�. �ֻ����� ������!��", iTurn_Print);
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)cPlayer_TurnPrint);
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
   }
	iNext_Line = 0;
	if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_NONE)
	{

	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_WORLDTRIP)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
		wsprintf(cGoldKey_Print, "�� Ȳ�ݿ��� : ���迩�࿡ ��÷�Ǽ̽��ϴ�! �����մϴ�!��");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_ISLAND)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
		wsprintf(cGoldKey_Print, "�� Ȳ�ݿ��� : ���ε��� ��÷�Ǽ̽��ϴ�!! Ǳ��Ǳ��    ��");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_START)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
		wsprintf(cGoldKey_Print, "�� Ȳ�ݿ��� : ������� �����! ��÷�Ǽ̽��ϴ�!!!    ��");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������������������������");
#endif
	}

}
void CGame::Print_Dice_Result_Text()
{
	char cDice_ResultPrint[50];
	int iNext_Line = 0;
	g_DBBF.TextColor(WHITE, BLACK);

	if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"�� ���迩�� ������ ������ �� �����ϴ�! ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������");
#endif
		return;
	}

	if (iPlayer_Dice_Result == 0)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"�� ���� �ֻ����� ������ �ʾҽ��ϴ�. ������!!��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
	}

	else
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		if (m_Player[eCurPlayer].bPlayer_Dice_Double == TRUE)
			g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"�� ����! �� �� �� ���� �� �־��~ �����Խô٦�");

		if (iPlayer_Dice_Result >= 10)	// 10 �ڸ� �̻��̸� �����̽� ��ĭ, 1�� �ڸ��� �����̽� �� ĭ
			wsprintf(cDice_ResultPrint, "�� �α׸���~ �ֻ����� ���� %d�� ���Խ��ϴ�. ��", iPlayer_Dice_Result);

		else
			wsprintf(cDice_ResultPrint, "�� �α׸���~ �ֻ����� ���� %d�� ���Խ��ϴ�.  ��", iPlayer_Dice_Result);

		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)cDice_ResultPrint);

#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
	}
};
void CGame::Print_Player_Infor()
{
	int iNext_Line;

	char cPlayer_Money1[30] = { "" };
	char cPlayer_Money2[30] = { "" };
	char cPlayer_Money3[30] = { "" };
	char cPlayer_Money4[30] = { "" };

	char cPlayer_Total_Money1[30] = { "" };
	char cPlayer_Total_Money2[30] = { "" };
	char cPlayer_Total_Money3[30] = { "" };
	char cPlayer_Total_Money4[30] = { "" };

	/*for (int i = 0; i < 3; i++)
	{
	m_Player[i].Set_PlayerTotalMoney();
	}*/
	if (iPlayerNum >= 2)
	{
		g_DBBF.TextColor(P1_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �÷��̾�1 : �� ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���� ��  :     ");
		wsprintf(cPlayer_Money1, TEXT("�� %d ����        "), m_Player[0].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Money1);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� �ڻ� :      ");
		wsprintf(cPlayer_Total_Money1, TEXT("�� %d ����        "), m_Player[0].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Total_Money1);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"��                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
		g_DBBF.TextColor(P2_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �÷��̾�2 : �� ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���� ��  :     ");
		wsprintf(cPlayer_Money2, "�� %d ����        ", m_Player[1].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Money2);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� �ڻ� :      ");
		wsprintf(cPlayer_Total_Money2, "�� %d ����        ", m_Player[1].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Total_Money2);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"��                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
	}
	if (iPlayerNum >= 3)
	{
		g_DBBF.TextColor(P3_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"�� �÷��̾�3 : �� ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"�� ���� ��  :     ");
		wsprintf(cPlayer_Money3, "�� %d ����        ", m_Player[2].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Money3);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"�� �� �ڻ� :      ");
		wsprintf(cPlayer_Total_Money3, "�� %d ����        ", m_Player[2].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Total_Money3);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"��                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
	}
	if (iPlayerNum >= 4)
	{
		g_DBBF.TextColor(P4_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"�� �÷��̾�4 : �� ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"�� ���� ��  :     ");
		wsprintf(cPlayer_Money4, "�� %d ����        ", m_Player[3].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Money4);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"�� �� �ڻ� :      ");
		wsprintf(cPlayer_Total_Money4, "�� %d ����        ", m_Player[3].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Total_Money4);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"��                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"��                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"����������������������������������");
#endif
	}
}

void CGame::Print_WinPlayer(int win, int win_way)
{
	int iWin_Player = win;
	int iWin_way = win_way;
	int iNext_Line = 0;
	int iWin_TextColor = win; // ��� �ؽ�Ʈ ��� ��
	char cWin_Player_Print[100];
	//����� �÷��̾���� �ش� �÷��̾��� ������ �ؽ�Ʈ ���
	{
		if (iWin_TextColor == 1)
			g_DBBF.TextColor(P1_COLOR, BLACK);

		else if (iWin_TextColor == 2)
			g_DBBF.TextColor(P2_COLOR, BLACK);


		else if (iWin_TextColor == 3)
			g_DBBF.TextColor(P3_COLOR, BLACK);


		else if (iWin_TextColor == 4)
			g_DBBF.TextColor(P4_COLOR, BLACK);
	}

	if (iWin_way == 0) //������ ��� ��
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		wsprintf(cWin_Player_Print, "�� �÷��̾� %d�� �ٸ� �÷��̾���� �Ļ�    ��", iWin_Player);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)cWin_Player_Print);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"�� �ϴ� ��� ������ �ߵ��½��ϴ�!!!      ��");
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"�� ���ϵ帳�ϴ�! �̰���ϴ�!!              ��");

#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
	}
	//���ε���
	else
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		wsprintf(cWin_Player_Print, "�� �÷��̾� %d�� ������ ��� �ż��߽��ϴ�! ��", iWin_Player);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)cWin_Player_Print);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"�� ���ε���!!���� ����߽��ϴ�!!!          ��");
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"�� ���ϵ帳�ϴ�! �̰���ϴ�!!              ��");

#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif

		exit(0);
	}
}
