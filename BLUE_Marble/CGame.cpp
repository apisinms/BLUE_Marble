//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit�� ����ϱ� ���ؼ�
#include <ctime>


CDoubleBuffering g_DBBF;	// ���� ��¥�� ���Ǹ� �Ѵ�(��ü�� �Ҵ�ȴ�)
CGame::CGame()
{
	srand((unsigned int)time(NULL));	// ���� ����
	g_DBBF.CreatBuffer();	// ������۸��� ���� ���۸� ������.

	/// Land�� ������ �ʱ�ȭ�Ѵ�.
	{
		// Left����
		m_Lands[0].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 8, 3, 30, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[1].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ¡", 11, 5, 33, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[2].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"Ÿ������", 15, 7, 35, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[3].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 15, 7, 35, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[4].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"ī �� ��", 15, 7, 35, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Top ����
		m_Lands[5].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 5) - 1, 1);
		m_Lands[6].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 9) - 2, 1);
		m_Lands[7].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 13) - 3, 1);
		m_Lands[8].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 17) - 4, 1);
		m_Lands[9].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"���Ŀ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 21) - 5, 1);

		// Right ����
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��ũ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));

		// Bottom ����
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
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

		// ���� ����
		FMOD_System_CreateSound(g_System, "Sounds\\Intro.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INTRO]);
		FMOD_System_CreateSound(g_System, "Sounds\\InputPlayer.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INPUTPLAYER]);
		char location[30];
		for (int i = 0; i < 4; i++)
		{
			wsprintf(location, "Sounds\\GamePlay%d.mp3", i + 1);
			FMOD_System_CreateSound(g_System, location, FMOD_DEFAULT, 0, &BGM_Music[BGM1 + i]);
		}
	}
}

CGame::~CGame()
{
	g_DBBF.DeleteBuffer();	// ���� ���۸��� ��� ��������� �ڿ��� �ݳ���.
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
					m_Player[0].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P1_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);
					m_Player[1].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P2_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);
				}

				if (num >= 3)
					m_Player[2].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P3_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);

				if (num >= 4)
					m_Player[3].Set_PlayerInfo((TCHAR *)"��", (LAND_TEXT_VERTICAL + P4_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);
			}
			
			while (true)
			{
				iCurBGM = rand() % BGM4;
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


	while (true)
	{
		BOOL bPrintCharacter = TRUE;
		g_DBBF.ClearBuffer();	// ���� ������ ������ ��� �����ش�.

		/// �ʺ�� ���̿� �°� ����Ͽ� Ÿ���� ����Ѵ�.
		Print_All_Tile();

		/// �� + Ư�� �� ���� ���
		Print_All_Land();
		Print_All_ExtraLand();

		/// �ֻ��� ��� �� �ֻ��� ������
		Print_Dice_Result(&bPrintCharacter);

		/// ĳ���� ���� ���(�ֻ��� �������� �ʾ��� ����, �ֻ��� ���� ���� Dice���� �˾Ƽ� ó���ϴϱ�)
		if (bPrintCharacter == TRUE)
			Print_All_Character();

		else
			RePaint();

		Check_BGM();
		g_DBBF.FlippingBuffer();	// ���۸� �ٲ��ش�(������۸�)
		Sleep(200);

	}
}

void CGame::Print_Indivisual_Tile(int x, int y) //���� Ÿ�� ���  �׸� 1��.
{
	int iNext_Line = 0;	// ���� ��

	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"������������������������������������");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"������������������������������������");
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
	g_DBBF.TextColor(WHITE, BLACK);
	for (int i = 0; i < 20; i++)
		m_Lands[i].Print_LandInfo();
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

void CGame::Print_Dice_Result(BOOL *bPrintCharacter)
{
	BOOL bIsDouble;	// �����̳�?
	COORD cLandPos;	// �÷��̾ �������� �� ���� ������
	ALL_LANDS ePlayerStand_Idx;	// ���� �÷��̾ ��� �ִ� �ε���(Land + ExtraLand)
	int iKey;	// Ű �Է�
	int iDice_Result;	// �ֻ��� ���
	int AddPos;	// �� �÷��̾�� ������� �� ��ǥ��
	int iHaveToGo_Idx = 0;	// ���ߵǴ� �ε���


	//int iPower = -1;
	//bool bUpdown = false;
	//int iKey;	// Ű �Է�

	//if (_kbhit())
	//{
	//	iKey = _getch();
	//	if (iKey == ' ')
	//	{
	//		while (true)
	//		{
	//			if (_kbhit())
	//			{
	//				iKey = _getch();
	//				if (iKey == ENTER)
	//				{
	//					RePaint();
	//					return;
	//				}
	//			}
	//			g_DBBF.ClearBuffer();
	//			if (bUpdown == 0 && iPower < 9) //�Ŀ��� ��� �͸����� 1����9
	//			{
	//				iPower++;
	//				if (iPower == 9) //9���Ǹ�
	//					bUpdown = true; //�ִ�ġ�̴�
	//			}
	//			else if (bUpdown == true && iPower > 0)
	//			{
	//				iPower--;
	//				if (iPower == 0)  //�Ŀ��� 0�̸�
	//					bUpdown = false;  //�ּ�ġ�̴�.
	//			}



	//			Print_All_Tile();
	//			Print_All_Land();
	//			Print_All_ExtraLand();
	//			Print_All_Character();


	//			if (bUpdown == false)
	//			{
	//				TextColor(RED, RED);
	//				g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR *)"���");
	//			}
	//			else
	//			{
	//				TextColor(BLACK, WHITE);
	//				g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR *)"���");
	//			}
	//			TextColor(BLACK, WHITE);
	//			Sleep(60);
	//			g_DBBF.WriteBuffer(50, 30, (TCHAR *)"         ");

	//			g_DBBF.FlippingBuffer();
	//		}
	//	}
	//}


	if (_kbhit())
	{
		iKey = _getch();
		if (iKey == ' ')
		{
			bIsDouble = FALSE;
			iDice_Result = m_Dice.Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// �ֻ��� ���� ����� ����
			ePlayerStand_Idx = m_Player[eCurPlayer].Get_PlayerStandIndex();	// �÷��̾ ����ִ� �� �ε���

			m_Dice.Print_Diceinfo();

		if(m_Player[eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE) // �ִ� ���� Ƚ�� �Ѿ��
		{
			m_Player[eCurPlayer].iDiceDoubleCnt = 0;	// ���� Ƚ�� 0����
			/// ���ε� ��ġ�� ���ͼ� ���� �÷��̾ ���ε��� ��������
			cLandPos = m_ExtranLands[1].Get_LandPosition();
			AddPos = P1_POS * (eCurPlayer + 1);
			cLandPos.X = (cLandPos.X + AddPos) - 2;
			cLandPos.Y += 2;
			m_Player[eCurPlayer].Move_PlayerPos(cLandPos);
			m_Player[eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
			RePaint();

			/// ���� �÷��̾��
			if (eCurPlayer == (iPlayerNum - 1))
				eCurPlayer = P1;

			else
				eCurPlayer = (eCURPLAYER)(eCurPlayer + 1);

			*bPrintCharacter = FALSE;	// ĳ���͸� �ٽ� �׸��� �ʰ� �Ѵ�.
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
					cLandPos = m_ExtranLands[0].Get_LandPosition();
					break;

				case ISLAND_LAND:	// ���ε�
					cLandPos = m_ExtranLands[1].Get_LandPosition();
					break;

				case WORLDTRIP_LAND:	// ���迩��
					cLandPos = m_ExtranLands[2].Get_LandPosition();
					break;

				case GOLDKEY_LAND:	// Ȳ�ݿ���
					cLandPos = m_ExtranLands[3].Get_LandPosition();
					break;

				default:
					cLandPos = m_Lands[i - Land_Diff].Get_LandPosition();	// ���� �÷��̾ ��� �ִ� ���� ��ǥ���� ���´�.
					break;
				}

				AddPos = P1_POS * (eCurPlayer + 1);	// �÷��̾ �����Ǿ�� �ϴ� ��ġ�� �°� ��ǥ�� �������ֱ� ���ؼ�

				cLandPos.X = (cLandPos.X + AddPos) - 2;
				cLandPos.Y += 2;

				m_Player[eCurPlayer].Move_PlayerPos(cLandPos);

				/// �簢 Ÿ�� + �� + Ư�� �� + ĳ���� ���
				Print_All_Tile();
				Print_All_Land();
				Print_All_ExtraLand();
				Print_All_Character();

				Sleep(200);
				g_DBBF.FlippingBuffer();


				if (i == SEOUL_LAND)	// �ε����� �� �������� �����ϸ� ���ش�.
				{
					iHaveToGo_Idx -= SEOUL_LAND;
					i = START_LAND - 1;
				}
			}	// End For State
			
			// �������� ȭ���� Clear�� �ȵǱ� ������ �ѹ� �� �׷���� �Ѵ�.
			RePaint();
			
			m_Player[eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// ���� �÷��̾ �� ���� ��ġ�� �����Ŵ


			if (bIsDouble == FALSE)
			{
				if (eCurPlayer == (iPlayerNum - 1))
					eCurPlayer = P1;

				else
					eCurPlayer = (eCURPLAYER)(eCurPlayer + 1);	// ���� �÷��̾��
			}

			else // �����̸�
			{
				if (m_Player[eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// �ִ� ���� Ƚ�������� ����
				{
					m_Player[eCurPlayer].iDiceDoubleCnt++;
					eCurPlayer = eCurPlayer;	// �� �� ��!
				}
			}
		}
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
			iCurBGM = rand() % BGM4;
			if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
				break;
		}
		FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// ��� ���
		FMOD_Channel_SetVolume(BGM_Channel[iCurBGM], 0.5f);
	}
}

void CGame::RePaint()
{
	g_DBBF.ClearBuffer();
	Print_All_Tile();
	Print_All_Land();
	Print_All_ExtraLand();
	Print_All_Character();
	Sleep(300);
	g_DBBF.FlippingBuffer();
}