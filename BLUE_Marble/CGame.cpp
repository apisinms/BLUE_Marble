#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit을 사용하기 위해서
// 프믄음능믄으
CGame::CGame()
{
	m_DBBF.CreatBuffer();
}


CGame::~CGame()
{
	m_DBBF.DeleteBuffer();
}


void CGame::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CGame::PrintIntro()
{
	int color = BLUE;
	while(true)
	{
		m_DBBF.TextColor(color++, BLACK);
		color = (color >= 16) ? BLUE : color;

		m_DBBF.WriteBuffer(0, 0, IntroMessage);
		m_DBBF.FlippingBuffer();
		m_DBBF.ClearBuffer();

		if (_kbhit() == TRUE)
			break;

		Sleep(100);
	}
}

// 전체 게임 관장
void CGame::PlayGame()
{
	Print_Game_Board();
}

// 전체 게임 타일 모두 출력
void CGame::Print_Game_Board()
{
	{
		//TextColor(RED, 0); printf("┌─────────────────────────────────────────────────────────────────────────────┐"); printf("          "); TextColor(CYAN, 0); printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
		//TextColor(RED, 0); printf("│                                                                             │"); printf("          "); TextColor(CYAN, 0); printf("│                                                                             │\n");
		//TextColor(RED, 0); printf("│                                                                             │"); printf("          "); TextColor(CYAN, 0); printf("│                                                                             │\n");
		//TextColor(RED, 0); printf("│                                                                             │"); printf("          "); TextColor(CYAN, 0); printf("│                                                                             │\n");
		//TextColor(RED, 0); printf("│                                                                             │"); printf("          "); TextColor(CYAN, 0); printf("│                                                                             │\n");
		//TextColor(RED, 0); printf("└─────────────────────────────────────────────────────────────────────────────┘"); printf("          "); TextColor(CYAN, 0); printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
		//printf("\n");
		//// 타일 출력 맨위 가로줄
		//{
		//	gotoxy(0, 7);
		//	for (int i = 0; i < 7; i++) // 타일칸 수
		//	{
		//		TextColor(WHITE, 0); printf("┌"); for (int j = 0; j < 30; j++) { printf("─"); } printf("┐"); //j는 가로변의 길이
		//	}printf("\n");
		//	for (int l = 0; l < 10; l++) // 세로 변의 길이
		//	{
		//		for (int i = 0; i < 7; i++)
		//		{
		//			TextColor(WHITE, 0); printf("│"); for (int j = 0; j < 30; j++) { printf(" "); } printf("│"); //j 가로 공백칸 수
		//		}printf("\n");
		//	}
		//	for (int i = 0; i < 7; i++) // 타일 칸 수
		//	{
		//		TextColor(WHITE, 0); printf("└"); for (int j = 0; j < 30; j++) { printf("─"); } printf("┘"); // 가로 변의 길이
		//	}printf("\n");
		//}
		////왼쪽 세로줄 6칸

		//{
		//	for (int l = 0; l < 7; l++)
		//	{
		//		gotoxy(0, 7 + (l * 12));
		//		for (int i = 0; i < 1; i++)
		//		{
		//			TextColor(WHITE, 0); printf("┌"); for (int j = 0; j < 30; j++) { printf("─"); } printf("┐"); //j는 가로변의 길이
		//		}printf("\n");
		//		for (int l = 0; l < 10; l++) // 세로 변의 길이
		//		{
		//			for (int i = 0; i < 1; i++)
		//			{
		//				TextColor(WHITE, 0); printf("│"); for (int j = 0; j < 30; j++) { printf(" "); } printf("│"); //j 가로 공백칸 수
		//			}printf("\n");
		//		}
		//		for (int i = 0; i < 1; i++) // 타일 칸 수
		//		{
		//			TextColor(WHITE, 0); printf("└"); for (int j = 0; j < 30; j++) { printf("─"); } printf("┘"); // 가로 변의 길이
		//		}printf("\n");
		//	}

		//}

		////오른쪽 세로줄
		//{
		//	for (int l = 0; l < 7; l++)
		//	{
		//		gotoxy(230, 7 + (l * 12));
		//		for (int i = 0; i < 1; i++)
		//		{
		//			TextColor(WHITE, 0); printf("┌"); for (int j = 0; j < 30; j++) { printf("─"); } printf("┐"); //j는 가로변의 길이
		//		}printf("\n");
		//		for (int l = 0; l < 10; l++) // 세로 변의 길이
		//		{
		//			for (int i = 0; i < 1; i++)
		//			{
		//				TextColor(WHITE, 0); printf("│"); for (int j = 0; j < 30; j++) { printf(" "); } printf("│"); //j 가로 공백칸 수
		//			}printf("\n");
		//		}
		//		for (int i = 0; i < 1; i++) // 타일 칸 수
		//		{
		//			TextColor(WHITE, 0); printf("└"); for (int j = 0; j < 30; j++) { printf("─"); } printf("┘"); // 가로 변의 길이
		//		}printf("\n");
		//	}

		//}
	}

	// Top 출력하기
	for (int i = 0; i < LAND_LINE_LEN; i++)
	{
		Print_Tile(i * 18, 0);
	}
	gotoxy(4, 2);
	cout << "대한민국" << endl;

	//for (int i = 0; i < LAND_LINE_LEN; i++)
	//{
	//	Print_Tile(0, i * 8);
	//}

}

void CGame::gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CGame::Print_Tile(int x, int y) //게임 타일 출력  네모 1개.
{
	int iNext_Line = 1;
	gotoxy(x, y);
	//맨 윗 줄 출력
	TextColor(WHITE, 0); cout << "┌";
	for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
	{
		cout << "─";
	}
	cout << "┐" << endl;
	gotoxy(x, y + iNext_Line++); //줄 바꿈
	for (int l = 0; l < TILE_VERTICAL_LEN; l++) // 세로 변 출력
	{
		TextColor(WHITE, 0); cout << "│";
		for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
		{
			cout << " ";
		}

		cout << "│" << endl;
		gotoxy(x, y + iNext_Line++);
	}
	TextColor(WHITE, 0); printf("└"); //밑 변 출력
	for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
	{
		cout << "─";
	}
	cout << "┘" << endl;
}



