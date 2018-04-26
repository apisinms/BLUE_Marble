#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit�� ����ϱ� ���ؼ�
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
		{
			m_DBBF.FlippingBuffer();
			m_DBBF.DeleteBuffer();
			break;
		}

		Sleep(100);
	}
}

// ��ü ���� ����
void CGame::PlayGame()
{
	Print_Game_Board();
}

// ��ü ���� Ÿ�� ��� ���
void CGame::Print_Game_Board()
{
	int i, j;
	i = j = 0;

	for (i = 0; i < 4; LTRB = (_LTRB)++i)
	{
		for (j = 0; j < LAND_LINE_LEN; j++)
		{
			switch (LTRB)
			{
			case TOP:
				Print_Tile(j * (TILE_HORIZONTAL_LEN + 3), 0);
				break;

			case BOTTOM:
				Print_Tile((j * (TILE_HORIZONTAL_LEN + 3)) + 10, (TILE_HORIZONTAL_LEN + ( (LAND_LINE_LEN-1) * 5)));
				break;

			case LEFT:
				Print_Tile(0, j * (TILE_VERTICAL_LEN + 3));
				break;

			case RIGHT:
				Print_Tile((TILE_HORIZONTAL_LEN * (LAND_LINE_LEN + 1)) + 3, j * (TILE_VERTICAL_LEN + 3));
				break;
			}
		}

	}

}

void CGame::gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CGame::Print_Tile(int x, int y) //���� Ÿ�� ���  �׸� 1��.
{
	int iNext_Line = 1;
	gotoxy(x, y);
	//�� �� �� ���
	TextColor(WHITE, 0); 
	cout << "��";
	for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
	{
		cout << "��";
	}
	cout << "��" << endl;
	gotoxy(x, y + iNext_Line++); //�� �ٲ�
	for (int l = 0; l < TILE_VERTICAL_LEN; l++) // ���� �� ���
	{
		TextColor(WHITE, 0); cout << "��";
		for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
		{
			cout << " ";
		}

		cout << "��" << endl;
		gotoxy(x, y + iNext_Line++);
	}
	TextColor(WHITE, 0); 
	printf("��"); //�� �� ���
	for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
	{
		cout << "��";
	}
	cout << "��" << endl;
}



