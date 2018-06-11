//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit을 사용하기 위해서
#include <ctime>


CDoubleBuffering g_DBBF;	// 이제 진짜로 정의를 한다(객체가 할당된다)
FMOD_SYSTEM *g_System;	// FMOD System 정의
FMOD_SOUND *g_FX_Sound[MAX_FX];	// 효과음을 전역으로
CGame::CGame()
{
	srand((unsigned int)time(NULL));	// 난수 심음
	g_DBBF.CreatBuffer();	// 더블버퍼링을 위한 버퍼를 생성함.

	/// Land의 정보를 초기화한다.
	{
		// Left땅들
		m_Lands[0].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"방    콕", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[1].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"베 이 징", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[2].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"타이페이", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[3].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"두 바 이", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[4].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"카 이 로", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Top 땅들
		m_Lands[5].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"도    쿄", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 5) - 1, 1);
		m_Lands[6].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"시 드 니", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 9) - 2, 1);
		m_Lands[7].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"퀘    벡", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 13) - 3, 1);
		m_Lands[8].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"하 와 이", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 17) - 4, 1);
		m_Lands[9].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"상파울로", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 21) - 5, 1);

		// Right 땅들
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"프 라 하", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"베 를 린", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"모스크바", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"제 네 바", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"로    마", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));

		// Bottom 땅들
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"평    양", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"런    던", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"파    리", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"뉴    욕", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"서    울", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
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

		/// 사운드 셋팅 BGM
		FMOD_System_CreateSound(g_System, "Sounds\\BGM\\BGM_Intro.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INTRO]);
		FMOD_System_CreateSound(g_System, "Sounds\\BGM\\BGM_InputPlayer.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INPUTPLAYER]);
		
		char location[100];
		for (int i = 0; i < 4; i++)
		{
			wsprintf(location, TEXT("Sounds\\BGM\\BGM_GamePlay%d.mp3"), i + 1);
			FMOD_System_CreateSound(g_System, location, FMOD_DEFAULT, 0, &BGM_Music[BGM1 + i]);
		}


		/// 사운드 셋팅 효과음
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
	g_DBBF.DeleteBuffer();	// 더블 버퍼링을 모두 사용했으니 자원을 반납함.
	
	/// 사운드 해제
	for (int i = 0; i < MAX_BGM; i++)
		FMOD_Sound_Release(BGM_Music[i]);
	for (int i = 0; i < MAX_FX; i++)
		FMOD_Sound_Release(g_FX_Sound[i]);

	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);

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
					m_Player[0].Set_PlayerInfo((TCHAR *)"♠", (LAND_TEXT_VERTICAL + P1_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
					m_Player[1].Set_PlayerInfo((TCHAR *)"◆", (LAND_TEXT_VERTICAL + P2_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
				}

				if (num >= 3)
					m_Player[2].Set_PlayerInfo((TCHAR *)"♥", (LAND_TEXT_VERTICAL + P3_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);

				if (num >= 4)
					m_Player[3].Set_PlayerInfo((TCHAR *)"♣", (LAND_TEXT_VERTICAL + P4_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
			}
			
			while (true)
			{
				iCurBGM = rand() % (BGM4 + 1);
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
	BOOL bPlayerTurn_FirstPrint = FALSE;

	while (true)
	{

		g_DBBF.ClearBuffer();	// 이전 버퍼의 내용을 모두 지워준다.
		if(bPlayerTurn_FirstPrint == FALSE)
			Print_Player_Turn();

		/// 너비와 높이에 맞게 계산하여 타일을 출력한다.
		Print_All_Tile();
		/// 땅 + 특수 땅 정보 출력
		Print_All_Land();
		Print_All_ExtraLand();
		
		m_Lands->Print_Information(eLandPrint_Idx);
		/// 주사위 출력 및 주사위 굴리기
 		m_Dice.Dice_Proc(*this);
		/// 캐릭터 정보 출력(주사위 던지지지 않았을 때만, 주사위 던질 때는 Dice에서 알아서 처리하니까)
		Print_All_Character();
		Print_Player_Infor();	// 플레이어 정보 출력
		/// 사운드 업데이트
		Check_BGM();
		FMOD_System_Update(g_System);	// 이 함수를 계속적으로 호출해줘야 사운드가 씹히지 않는다.

		g_DBBF.FlippingBuffer();	// 버퍼를 바꿔준다(더블버퍼링)
		Sleep(1);
	}
}

void CGame::Print_Indivisual_Tile(int x, int y) //게임 타일 출력  네모 1개.
{
	int iNext_Line = 0;	// 다음 줄
#if OS_VER == 7
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
#if OS_VER == 7
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
	//타일 크기 조정 , 윈 7 ,윈 10

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
	for (int i = 0; i < 20; i++)
	{
		m_Lands[i].Print_LandInfo();
	}
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

void CGame::Check_BGM()
{
	FMOD_BOOL bSoundPlaying = TRUE;
	/// 노래 재생 끝났으면 다른 음악으로 재생
	FMOD_Channel_IsPlaying(BGM_Channel[iCurBGM], &bSoundPlaying);
	if (bSoundPlaying == FALSE)
	{
		while (true)
		{
			iCurBGM = rand() % (BGM4 + 1);
			if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
				break;
		}
		FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// 브금 재생
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
	Print_Dice_Result_Text(); //주사위 결과값 출력

	if(bSleep == TRUE)
		Sleep(PLAYER_MOVE_SPEED);

	g_DBBF.FlippingBuffer();
}

void CGame::Print_Dice_Gage()
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
						/// 출력 도중 스페이스바가 눌리면 또 동기화를 해줘야 한다.(더럽지만 어쩔 수 없어, 메서드 만드는 게 더 더러움)
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

void CGame::PlayFX(int idx)
{
	FMOD_CHANNEL *tmp_Channel;	// 임시 채널
	FMOD_System_PlaySound(g_System, g_FX_Sound[idx], NULL, FALSE, &tmp_Channel);	// 주사위 음성 재생
	FMOD_Channel_SetVolume(tmp_Channel, 0.5f);	// 소리좀 줄이자
}

void CGame::Print_Player_Turn()
{
	char cPlayer_TurnPrint[100];
	char cGoldKey_Print[100];  // 황금열쇠 출력 문자열
	int iNext_Line = 0;
	int iTurn_Print = NULL;
	iTurn_Print = (int)eCurPlayer + 1;
	g_DBBF.TextColor(WHITE, BLACK);
	if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────────────┐");
#endif
		wsprintf(cPlayer_TurnPrint, "│ 플레이어 %d의 차례입니다. 원하는 지역을 선택하세요│", iTurn_Print);
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)cPlayer_TurnPrint);
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────────────┘");
#endif
}

	else if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_NONE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────┐");
#endif
		wsprintf(cPlayer_TurnPrint, "│ 플레이어 %d의 차례입니다. 주사위를 굴려욧!│", iTurn_Print);
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)cPlayer_TurnPrint);
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────┘");
#endif
   }
	iNext_Line = 0;
	if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_NONE)
	{

	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_WORLDTRIP)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────────────┐");
#endif
		wsprintf(cGoldKey_Print, "│ 황금열쇠 : 세계여행에 당첨되셨습니다! 축하합니다!│");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────────────┘");
#endif
	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_ISLAND)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────────────┐");
#endif
		wsprintf(cGoldKey_Print, "│ 황금열쇠 : 무인도에 당첨되셨습니다!! 풉ㅋ풉ㅋ    │");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────────────┘");
#endif
	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_START)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────────────┐");
#endif
		wsprintf(cGoldKey_Print, "│ 황금열쇠 : 출발지로 가즈아! 당첨되셨습니다!!!    │");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────────────┘");
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
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"│ 세계여행 지역은 선택할 수 없습니다! │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"└────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────┘");
#endif
		return;
	}

	if (iPlayer_Dice_Result == 0)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────┐");
#endif
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"│ 아직 주사위를 돌리지 않았습니다. 돌려요!!│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────┘");
#endif
	}

	else
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"┌──────────────────────────────────────────┐");
#endif
		if (m_Player[eCurPlayer].bPlayer_Dice_Double == TRUE)
			g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"│ 더블! 한 번 더 돌릴 수 있어요~ 움직입시다│");

		if (iPlayer_Dice_Result >= 10)	// 10 자리 이상이면 스페이스 한칸, 1의 자리면 스페이스 두 칸
			wsprintf(cDice_ResultPrint, "│ 핑그르르~ 주사위를 굴려 %d가 나왔습니다. │", iPlayer_Dice_Result);

		else
			wsprintf(cDice_ResultPrint, "│ 핑그르르~ 주사위를 굴려 %d가 나왔습니다.  │", iPlayer_Dice_Result);

		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)cDice_ResultPrint);

#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"└──────────────────────────────────────────┘");
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
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 플레이어1 : ♠ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 보유 돈  :     ");
		wsprintf(cPlayer_Money1, TEXT("│ %d 만원        "), m_Player[0].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Money1);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 총 자산 :      ");
		wsprintf(cPlayer_Total_Money1, TEXT("│ %d 만원        "), m_Player[0].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Total_Money1);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────");
#endif
		g_DBBF.TextColor(P2_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"┌────────────────");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 플레이어2 : ◆ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 보유 돈  :     ");
		wsprintf(cPlayer_Money2, "│ %d 만원        ", m_Player[1].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Money2);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│ 총 자산 :      ");
		wsprintf(cPlayer_Total_Money2, "│ %d 만원        ", m_Player[1].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Total_Money2);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"│                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"└────────────────");
#endif
	}
	if (iPlayerNum >= 3)
	{
		g_DBBF.TextColor(P3_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"┌────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"┌────────────────");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│ 플레이어3 : ♥ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│ 보유 돈  :     ");
		wsprintf(cPlayer_Money3, "│ %d 만원        ", m_Player[2].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Money3);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│ 총 자산 :      ");
		wsprintf(cPlayer_Total_Money3, "│ %d 만원        ", m_Player[2].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Total_Money3);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"└────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"└────────────────");
#endif
	}
	if (iPlayerNum >= 4)
	{
		g_DBBF.TextColor(P4_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"┌────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"┌────────────────");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│ 플레이어4 : ♣ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│ 보유 돈  :     ");
		wsprintf(cPlayer_Money4, "│ %d 만원        ", m_Player[3].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Money4);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│ 총 자산 :      ");
		wsprintf(cPlayer_Total_Money4, "│ %d 만원        ", m_Player[3].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Total_Money4);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"│                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"└────────");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"└────────────────");
#endif
	}
}

void CGame::Print_WinPlayer(int win, int win_way)
{
	int iWin_Player = win;
	int iWin_way = win_way;
	int iNext_Line = 0;
	int iWin_TextColor = win; // 우승 텍스트 출력 색
	char cWin_Player_Print[100];
	//우승한 플레이어에따라서 해당 플레이어의 색으로 텍스트 출력
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

	if (iWin_way == 0) //돈으로 우승 시
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		wsprintf(cWin_Player_Print, "│ 플레이어 %d가 다른 플레이어들이 파산    │", iWin_Player);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)cWin_Player_Print);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"│ 하는 가운데 끝까지 견뎌냈습니다!!!      │");
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"│ 축하드립니다! 이겼습니다!!              │");

#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif
	}
	//라인독점
	else
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"┌────────────────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"┌─────────────────────────────────────────┐");
#endif
		wsprintf(cWin_Player_Print, "│ 플레이어 %d가 라인을 모두 매수했습니다! │", iWin_Player);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)cWin_Player_Print);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"│ 라인독점!!으로 우승했습니다!!!          │");
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"│ 축하드립니다! 이겼습니다!!              │");

#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"└────────────────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"└─────────────────────────────────────────┘");
#endif

		exit(0);
	}
}
