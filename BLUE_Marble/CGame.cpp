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
	static FMOD_BOOL bSoundPlaying = TRUE;
	system("mode con cols=200 lines=50");	// 화면 크기 다시 늘림
	int i, j;
	i = j = 0;

	while (true)
	{
		g_DBBF.ClearBuffer();	// 이전 버퍼의 내용을 모두 지워준다.

		/// 너비와 높이에 맞게 계산하여 타일을 출력한다.
		{
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

						Print_Tile(0, j * (TILE_VERTICAL_LEN + TILE_DISTANCE));
						break;

					case TOP:
						g_DBBF.TextColor(LIGHTBLUE, BLACK);

						if (j == LAND_LINE_LEN - 1)
							g_DBBF.TextColor(YELLOW, BLACK);

						Print_Tile((j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE)) + (TILE_HORIZONTAL_LEN + TILE_DISTANCE), 0);
						break;

					case RIGHT:
						g_DBBF.TextColor(LIGHTMAGENTA, BLACK);

						if (j == LAND_LINE_LEN - 1)
							g_DBBF.TextColor(YELLOW, BLACK);

						Print_Tile((TILE_HORIZONTAL_LEN * (LAND_LINE_LEN + 1)) + (TILE_DISTANCE - 1), (j * (TILE_VERTICAL_LEN + TILE_DISTANCE)) + (TILE_VERTICAL_LEN + TILE_DISTANCE));
						break;

					case BOTTOM:
						g_DBBF.TextColor(LIGHTRED, BLACK);

						if (j == 0)
							g_DBBF.TextColor(YELLOW, BLACK);

						Print_Tile(j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE), (TILE_VERTICAL_LEN + TILE_DISTANCE) * LAND_LINE_LEN);
						break;
					}
				}
				eBoardLTRB = (BOARD_LTRB)++i;
			}
		}

		/// 땅 + 특수 땅 정보 출력
		{
			// 땅 정보를 출력한다.
			g_DBBF.TextColor(WHITE, BLACK);
			for (int i = 0; i < 20; i++)
				m_Lands[i].Print_LandInfo();

			// 특수 땅 정보를 출력한다
			g_DBBF.TextColor(BROWN, BLACK);
			for (int i = 0; i < 4; i++)
				m_ExtranLands[i].Print_LandInfo();
		}

		/// 주사위 출력 및 주사위 굴리기
		{
			while (true)
			{
				if (_kbhit())
				{
					int iKey = _getch();
					if (iKey == ' ')
					{
						BOOL bIsDouble = FALSE;	// 더블이냐?
						int iDice_Result = m_Dice.Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// 주사위 굴린 결과를 얻어옴
						ALL_LANDS ePlayerStand_Idx = m_Player[eCurPlayer].Get_PlayerStandIndex();	// 주사위 굴린 결과 값 + 플레이어가 밟고있는 땅 인덱스

						ePlayerStand_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// 현재 밟은 땅 + 주사위 눈 더한 값

						if (iDice_Result + ePlayerStand_Idx > SEOUL_LAND)	// 더한 결과값이 땅의 마지막인 Seoul을 넘어간다면
							ePlayerStand_Idx = (ALL_LANDS)(ePlayerStand_Idx - SEOUL_LAND);	// 23을 넘어가지 않게 조정해준다.

						COORD cLandPos = m_Lands[ePlayerStand_Idx].Get_LandPosition();
						int AddPos = 0;
						switch (eCurPlayer)
						{
						case P1:
							AddPos = P1_POS;
							break;

						case P2:
							AddPos = P2_POS;
							break;

						case P3:
							AddPos = P3_POS;
							break;

						case P4:
							AddPos = P4_POS;
							break;
						}
						cLandPos.X = (cLandPos.X + AddPos) - 2;
						cLandPos.Y += 3;

						m_Player[eCurPlayer].Move_PlayerPos(cLandPos, ePlayerStand_Idx);

						if (bIsDouble == FALSE)
						{
							if (eCurPlayer == (iPlayerNum - 1))
								eCurPlayer = P1;

							else
								eCurPlayer = (eCURPLAYER)(eCurPlayer + 1);	// 다음 플레이어로
						}

						else // 더블이면
						{
							eCurPlayer = eCurPlayer;	// 한 번 더!
						}

						m_Dice.Print_Diceinfo();
						break;
					}
				}
			}
		}

		/// 플레이어 캐릭터 출력
		{
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

		g_DBBF.FlippingBuffer();	// 버퍼를 바꿔준다(더블버퍼링)
		Sleep(200);
	}
}

void CGame::Print_Tile(int x, int y) //게임 타일 출력  네모 1개.
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