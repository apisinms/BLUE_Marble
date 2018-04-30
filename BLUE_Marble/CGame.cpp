//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit�� ����ϱ� ���ؼ�
CGame::CGame()
{
	m_DBBF.CreatBuffer();	// ������۸��� ���� ���۸� ������.

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
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��ũ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"�� �� ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Bottom ����
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 8, 3, 30, 0, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 11, 5, 33, 0, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"��    ��", 15, 7, 35, 0, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}
}

CGame::~CGame()
{
	m_DBBF.DeleteBuffer();	// ���� ���۸��� ��� ��������� �ڿ��� �ݳ���.
	delete[] m_Player;
}

// ��ü���� ���� ����
void CGame::PlayGame()
{
	PrintIntro();
	Input_PlayerNum();	// �÷��̾��� ���� �Է¹޴´�.
	Print_Game_Board();	// ���� �� ���
}

// ����� �÷��� �� ������ �Է¹���
void CGame::Input_PlayerNum()	// �÷��̾��� ���� �Է¹޴´�
{
	int num = 0;
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));	// ���� ��ũ������ ����(������۸� x)

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
			m_Player = new CPlayer[num];	// �÷��̾ �����Ҵ���
			//CGame::iPlayerNum = num;	// �÷��̾� ���� �����ص�.
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

// ó�� ȭ�� ���
void CGame::PrintIntro()
{
	int color = BLUE;
	while (true)
	{
		if (_kbhit())
		{
			_getch();	// ���ۿ� ����(��� ���� �ƹ�Ű) Ű�� ������.
			break;
		}

		// �η縶�� ��� ��
		m_DBBF.TextColor(color++, BLACK);
		color = (color >= 16) ? BLUE : color;
		m_DBBF.WriteBuffer(0, 0, IntroMessage);

		// �ȳ����� ��� ��
		m_DBBF.TextColor(WHITE, BLACK);
		m_DBBF.WriteBuffer(50, 30, (TCHAR *)"������ �����Ϸ��� �ƹ� Ű�� ��������");

		// ���� ��ȯ �� Ŭ����
		m_DBBF.FlippingBuffer();
		m_DBBF.ClearBuffer();

		Sleep(100);
	}

}

// ��ü ���� Ÿ�� ��� ���
void CGame::Print_Game_Board()
{
	system("mode con cols=200 lines=50");	// ȭ�� ũ�� �ٽ� �ø�
	int i, j;
	i = j = 0;

	while (true)
	{
		m_DBBF.ClearBuffer();	// ���� ������ ������ ��� �����ش�.

		/// �ʺ�� ���̿� �°� ����Ͽ� Ÿ���� ����Ѵ�.
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

		// �� ������ ����Ѵ�.
		m_DBBF.TextColor(WHITE, BLACK);
		for (int i = 0; i < 20; i++)
		{
			m_Lands[i].Print_LandInfo(m_DBBF);
		}

		m_DBBF.FlippingBuffer();	// ���۸� �ٲ��ش�(������۸�)
		Sleep(200);
	}
}

void CGame::Print_Tile(int x, int y) //���� Ÿ�� ���  �׸� 1��.
{
	int iNext_Line = 0;	// ���� ��

	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"������������������������������������");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"��                ��");
	m_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"������������������������������������");
}

void CGame::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}