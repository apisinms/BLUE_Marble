//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit을 사용하기 위해서
CGame::CGame()
{
	m_DBBF.CreatBuffer();	// 더블버퍼링을 위한 버퍼를 생성함.

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
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"로    마", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"제 네 바", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"모스크바", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"베 를 린", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"프 라 하", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Bottom 땅들
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"서    울", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"뉴    욕", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"파    리", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"런    던", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"평    양", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}
}

CGame::~CGame()
{
	m_DBBF.DeleteBuffer();	// 더블 버퍼링을 모두 사용했으니 자원을 반납함.
	delete[] m_Player;
}

// 전체적인 게임 관장
void CGame::PlayGame()
{
	PrintIntro();
	Input_PlayerNum();	// 플레이어의 수를 입력받는다.
	Print_Game_Board();	// 게임 판 출력
}

// 몇명이 플레이 할 것인지 입력받음
void CGame::Input_PlayerNum()	// 플레이어의 수를 입력받는다
{
	int num = 0;
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
			m_Player = new CPlayer[num];	// 플레이어를 동적할당함
			//CGame::iPlayerNum = num;	// 플레이어 수를 저장해둠.
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

// 처음 화면 출력
void CGame::PrintIntro()
{
	int color = BLUE;
	while (true)
	{
		if (_kbhit())
		{
			_getch();	// 버퍼에 남은(방금 누른 아무키) 키를 제거함.
			break;
		}

		// 부루마블 출력 부
		m_DBBF.TextColor(color++, BLACK);
		color = (color >= 16) ? BLUE : color;
		m_DBBF.WriteBuffer(0, 0, IntroMessage);

		// 안내문구 출력 부
		m_DBBF.TextColor(WHITE, BLACK);
		m_DBBF.WriteBuffer(50, 30, (TCHAR *)"게임을 시작하려면 아무 키나 누르세요");

		// 버퍼 전환 및 클리어
		m_DBBF.FlippingBuffer();
		m_DBBF.ClearBuffer();

		Sleep(100);
	}

}

// 전체 게임 타일 모두 출력
void CGame::Print_Game_Board()
{
	system("mode con cols=200 lines=50");	// 화면 크기 다시 늘림
	int i, j;
	i = j = 0;

	while (true)
	{
		m_DBBF.ClearBuffer();	// 이전 버퍼의 내용을 모두 지워준다.

		/// 너비와 높이에 맞게 계산하여 타일을 출력한다.
		for (eBoardLTRB = LEFT, i = 0; i < 4;)
		{
			for (j = 0; j < LAND_LINE_LEN; j++)
			{
				switch (eBoardLTRB)
				{
				case LEFT:	// o
					m_DBBF.TextColor(LIGHTGREEN, BLACK);

					if (j == 0)
						m_DBBF.TextColor(YELLOW, BLACK);

					Print_Tile(0, j * (TILE_VERTICAL_LEN + TILE_DISTANCE));
					break;

				case TOP:
					m_DBBF.TextColor(LIGHTBLUE, BLACK);

					if (j == LAND_LINE_LEN - 1)
						m_DBBF.TextColor(YELLOW, BLACK);

					Print_Tile((j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE)) + (TILE_HORIZONTAL_LEN + TILE_DISTANCE), 0);
					break;

				case RIGHT:
					m_DBBF.TextColor(LIGHTMAGENTA, BLACK);

					if (j == LAND_LINE_LEN - 1)
						m_DBBF.TextColor(YELLOW, BLACK);

					Print_Tile((TILE_HORIZONTAL_LEN * (LAND_LINE_LEN + 1)) + (TILE_DISTANCE - 1), (j * (TILE_VERTICAL_LEN + TILE_DISTANCE)) + (TILE_VERTICAL_LEN + TILE_DISTANCE));
					break;

				case BOTTOM:
					m_DBBF.TextColor(LIGHTRED, BLACK);

					if (j == 0)
						m_DBBF.TextColor(YELLOW, BLACK);

					Print_Tile(j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE), (TILE_VERTICAL_LEN + TILE_DISTANCE) * LAND_LINE_LEN);
					break;
				}
			}
			eBoardLTRB = (BOARD_LTRB)++i;
		}

		// 땅 정보를 출력한다.
		m_DBBF.TextColor(WHITE, BLACK);
		for (int i = 0; i < 20; i++)
		{
			m_Lands[i].Print_LandInfo(m_DBBF);
		}

		m_DBBF.FlippingBuffer();	// 버퍼를 바꿔준다(더블버퍼링)
		Sleep(200);
	}
}

void CGame::Print_Tile(int x, int y) //게임 타일 출력  네모 1개.
{
	int iNext_Line = 0;	// 다음 줄

	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"┌────────────────┐");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"│                │");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"└────────────────┘");
}

void CGame::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}