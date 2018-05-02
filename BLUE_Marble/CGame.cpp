//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit을 사용하기 위해서
#include <ctime>


CDoubleBuffering g_DBBF;	// 이제 진짜로 정의를 한다(객체가 할당된다)
CGame::CGame()
{
	srand((unsigned int)time(NULL));	// 난수 심음
	g_DBBF.CreatBuffer();	// 더블버퍼링을 위한 버퍼를 생성함.

	/// Land의 정보를 초기화한다.
	{
		// Left땅들
		m_Lands[0].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"방    콕", 8, 3, 30, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[1].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"베 이 징", 11, 5, 33, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[2].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"타이페이", 15, 7, 35, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[3].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"두 바 이", 15, 7, 35, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[4].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"카 이 로", 15, 7, 35, 0, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Top 땅들
		m_Lands[5].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"도    쿄", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 5) - 1, 1);
		m_Lands[6].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"시 드 니", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 9) - 2, 1);
		m_Lands[7].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"퀘    벡", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 13) - 3, 1);
		m_Lands[8].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"하 와 이", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 17) - 4, 1);
		m_Lands[9].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"상파울로", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 21) - 5, 1);

		// Right 땅들
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"프 라 하", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"베 를 린", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"모스크바", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"제 네 바", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"로    마", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));

		// Bottom 땅들
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"평    양", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"런    던", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"파    리", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"뉴    욕", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"서    울", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}

	///ExtranLands에 대한 정보를 초기화 한다.
	{
		m_ExtranLands[0].Set_LandInfo((TCHAR *)"출    발", LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_ExtranLands[1].Set_LandInfo((TCHAR *)"무 인 도", LAND_TEXT_VERTICAL, 1);
		m_ExtranLands[2].Set_LandInfo((TCHAR *)"세계여행", (LAND_TEXT_VERTICAL * 25) - 6, 1);
		m_ExtranLands[3].Set_LandInfo((TCHAR *)"황금열쇠", (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}
	

	/// 사운드에 관한 정보를 초기화 한다.
	{
		// 사운드 시스템 초기화
		FMOD_System_Create(&g_System);	// 객체 생성
		FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);	//초기화

		// 사운드 셋팅
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
	g_DBBF.DeleteBuffer();	// 더블 버퍼링을 모두 사용했으니 자원을 반납함.
	delete[] m_Player;
}

// 전체적인 게임 관장
void CGame::PlayGame()
{
	PrintIntro();
	Input_PlayerNum();	// 플레이어의 수를 입력받는다.
	Print_Game_Board();	// 게임 판 출력
}
// 처음 화면 출력
void CGame::PrintIntro()
{
	FMOD_System_PlaySound(g_System, BGM_Music[INTRO], NULL, FALSE, &BGM_Channel[INTRO]);	// 브금 재생
	FMOD_Channel_SetVolume(BGM_Channel[INTRO], 0.5f);

	int x, y;
	x = 50;
	y = 0;
	int color = BLUE;
	while (true)
	{
		if (_kbhit())
		{
			_getch();	// 버퍼에 남은(방금 누른 아무키) 키를 제거함.
			break;
		}

		// 부루마블 출력 부
		g_DBBF.TextColor(color++, BLACK);
		color = (color >= 16) ? BLUE : color;
		g_DBBF.WriteBuffer(0, 0, IntroMessage);


		// 안내문구 출력 부
		g_DBBF.TextColor(WHITE, BLACK);
		g_DBBF.WriteBuffer(80, 35, (TCHAR *)"게임을 시작하려면 아무 키나 누르세요");

		// 버퍼 전환 및 클리어
		g_DBBF.FlippingBuffer();
		g_DBBF.ClearBuffer();

		Sleep(150);
	}

}
// 몇명이 플레이 할 것인지 입력받음
void CGame::Input_PlayerNum()	// 플레이어의 수를 입력받는다
{
	int num = 0;
	FMOD_Channel_Stop(BGM_Channel[INTRO]);
	FMOD_System_PlaySound(g_System, BGM_Music[INPUTPLAYER], NULL, FALSE, &BGM_Channel[INPUTPLAYER]);	// 브금 재생
	FMOD_Channel_SetVolume(BGM_Channel[INPUTPLAYER], 0.5f);
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));	// 현재 스크린으로 적용(더블버퍼링 x)
	TextColor(WHITE, BLACK);
	while (true)
	{
		MoveXY(75, 15);	// 더블 버퍼링을 사용하지 않을 때 커서 좌표 옮기기
		cout << "플레이어의 수를 입력하세요(2~4인) : ";
		cin >> num;	// 플레이어 수를 입력받음
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');	// 버퍼안에 남아있는 모든 찌꺼기 지움
		}
		system("cls");	// 지저분한 화면 지우기
		if (num >= 2 && num <= 4)
		{
			iPlayerNum = num;
			m_Player = new CPlayer[num];	// 플레이어를 동적할당함
			/// Player의 초기 정보를 셋팅한다.
			{
				if (num >= 2)
				{
					m_Player[0].Set_PlayerInfo((TCHAR *)"♠", (LAND_TEXT_VERTICAL + P1_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);
					m_Player[1].Set_PlayerInfo((TCHAR *)"◆", (LAND_TEXT_VERTICAL + P2_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);
				}

				if (num >= 3)
					m_Player[2].Set_PlayerInfo((TCHAR *)"♥", (LAND_TEXT_VERTICAL + P3_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);

				if (num >= 4)
					m_Player[3].Set_PlayerInfo((TCHAR *)"♣", (LAND_TEXT_VERTICAL + P4_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3);
			}
			
			while (true)
			{
				iCurBGM = rand() % BGM4;
				if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
					break;
			}
			FMOD_Channel_Stop(BGM_Channel[INPUTPLAYER]);
			FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// 브금 재생
			FMOD_Channel_SetVolume(BGM_Channel[iCurBGM], 0.5f);
			break;
		}
	}
}

// 더블 버퍼링을 사용하지 않을 때의 글자 색상 설정
void CGame::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 전체 게임 타일 모두 출력
void CGame::Print_Game_Board()
{
	system("mode con cols=190 lines=50");	// 화면 크기 다시 늘림


	while (true)
	{
		BOOL bPrintCharacter = TRUE;
		g_DBBF.ClearBuffer();	// 이전 버퍼의 내용을 모두 지워준다.

		/// 너비와 높이에 맞게 계산하여 타일을 출력한다.
		Print_All_Tile();

		/// 땅 + 특수 땅 정보 출력
		Print_All_Land();
		Print_All_ExtraLand();

		/// 주사위 출력 및 주사위 굴리기
		Print_Dice_Result(&bPrintCharacter);

		/// 캐릭터 정보 출력(주사위 던지지지 않았을 때만, 주사위 던질 때는 Dice에서 알아서 처리하니까)
		if (bPrintCharacter == TRUE)
			Print_All_Character();

		else
			RePaint();

		Check_BGM();
		g_DBBF.FlippingBuffer();	// 버퍼를 바꿔준다(더블버퍼링)
		Sleep(200);

	}
}

void CGame::Print_Indivisual_Tile(int x, int y) //게임 타일 출력  네모 1개.
{
	int iNext_Line = 0;	// 다음 줄

	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"┌────────────────┐");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"└────────────────┘");
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
	// 땅 정보를 출력한다.
	g_DBBF.TextColor(WHITE, BLACK);
	for (int i = 0; i < 20; i++)
		m_Lands[i].Print_LandInfo();
}

void CGame::Print_All_ExtraLand()
{
	// 특수 땅 정보를 출력한다
	g_DBBF.TextColor(BROWN, BLACK);
	for (int i = 0; i < 4; i++)
		m_ExtranLands[i].Print_LandInfo();
}

void CGame::Print_All_Character()
{
	/// 플레이어 캐릭터 출력
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
	BOOL bIsDouble;	// 더블이냐?
	COORD cLandPos;	// 플레이어가 움직여야 할 땅의 포지션
	ALL_LANDS ePlayerStand_Idx;	// 현재 플레이어가 밟고 있는 인덱스(Land + ExtraLand)
	int iKey;	// 키 입력
	int iDice_Result;	// 주사위 결과
	int AddPos;	// 각 플레이어마다 더해줘야 할 좌표값
	int iHaveToGo_Idx = 0;	// 가야되는 인덱스


	//int iPower = -1;
	//bool bUpdown = false;
	//int iKey;	// 키 입력

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
	//			if (bUpdown == 0 && iPower < 9) //파워가 계속 와리가리 1부터9
	//			{
	//				iPower++;
	//				if (iPower == 9) //9가되면
	//					bUpdown = true; //최대치이다
	//			}
	//			else if (bUpdown == true && iPower > 0)
	//			{
	//				iPower--;
	//				if (iPower == 0)  //파워가 0이면
	//					bUpdown = false;  //최소치이다.
	//			}



	//			Print_All_Tile();
	//			Print_All_Land();
	//			Print_All_ExtraLand();
	//			Print_All_Character();


	//			if (bUpdown == false)
	//			{
	//				TextColor(RED, RED);
	//				g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR *)"■■");
	//			}
	//			else
	//			{
	//				TextColor(BLACK, WHITE);
	//				g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR *)"■■");
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
			iDice_Result = m_Dice.Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// 주사위 굴린 결과를 얻어옴
			ePlayerStand_Idx = m_Player[eCurPlayer].Get_PlayerStandIndex();	// 플레이어가 밟고있는 땅 인덱스

			m_Dice.Print_Diceinfo();

		if(m_Player[eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE) // 최대 더블 횟수 넘어가면
		{
			m_Player[eCurPlayer].iDiceDoubleCnt = 0;	// 더블 횟수 0으로
			/// 무인도 위치를 얻어와서 지금 플레이어를 무인도로 보내버림
			cLandPos = m_ExtranLands[1].Get_LandPosition();
			AddPos = P1_POS * (eCurPlayer + 1);
			cLandPos.X = (cLandPos.X + AddPos) - 2;
			cLandPos.Y += 2;
			m_Player[eCurPlayer].Move_PlayerPos(cLandPos);
			m_Player[eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
			RePaint();

			/// 다음 플레이어로
			if (eCurPlayer == (iPlayerNum - 1))
				eCurPlayer = P1;

			else
				eCurPlayer = (eCURPLAYER)(eCurPlayer + 1);

			*bPrintCharacter = FALSE;	// 캐릭터를 다시 그리지 않게 한다.
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
					cLandPos = m_ExtranLands[0].Get_LandPosition();
					break;

				case ISLAND_LAND:	// 무인도
					cLandPos = m_ExtranLands[1].Get_LandPosition();
					break;

				case WORLDTRIP_LAND:	// 세계여행
					cLandPos = m_ExtranLands[2].Get_LandPosition();
					break;

				case GOLDKEY_LAND:	// 황금열쇠
					cLandPos = m_ExtranLands[3].Get_LandPosition();
					break;

				default:
					cLandPos = m_Lands[i - Land_Diff].Get_LandPosition();	// 현재 플레이어가 밟고 있는 땅의 좌표값을 얻어온다.
					break;
				}

				AddPos = P1_POS * (eCurPlayer + 1);	// 플레이어가 지정되어야 하는 위치에 맞게 좌표를 수정해주기 위해서

				cLandPos.X = (cLandPos.X + AddPos) - 2;
				cLandPos.Y += 2;

				m_Player[eCurPlayer].Move_PlayerPos(cLandPos);

				/// 사각 타일 + 땅 + 특수 땅 + 캐릭터 출력
				Print_All_Tile();
				Print_All_Land();
				Print_All_ExtraLand();
				Print_All_Character();

				Sleep(200);
				g_DBBF.FlippingBuffer();


				if (i == SEOUL_LAND)	// 인덱스가 맵 끝지점에 도달하면 빼준다.
				{
					iHaveToGo_Idx -= SEOUL_LAND;
					i = START_LAND - 1;
				}
			}	// End For State
			
			// 마지막엔 화면이 Clear가 안되기 때문에 한번 더 그려줘야 한다.
			RePaint();
			
			m_Player[eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// 최종 플레이어가 간 땅의 위치를 저장시킴


			if (bIsDouble == FALSE)
			{
				if (eCurPlayer == (iPlayerNum - 1))
					eCurPlayer = P1;

				else
					eCurPlayer = (eCURPLAYER)(eCurPlayer + 1);	// 다음 플레이어로
			}

			else // 더블이면
			{
				if (m_Player[eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// 최대 더블 횟수까지는 가능
				{
					m_Player[eCurPlayer].iDiceDoubleCnt++;
					eCurPlayer = eCurPlayer;	// 한 번 더!
				}
			}
		}
	}
}

void CGame::Check_BGM()
{
	FMOD_BOOL bSoundPlaying = TRUE;
	/// 노래 재생 끝났으면 다른 음악으로 재생
	FMOD_Channel_IsPlaying(BGM_Channel[iCurBGM], &bSoundPlaying);
	if (bSoundPlaying == FALSE)
	{
		while (true)
		{
			iCurBGM = rand() % BGM4;
			if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
				break;
		}
		FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// 브금 재생
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