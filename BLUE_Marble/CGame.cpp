#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit�� ����ϱ� ���ؼ�
// �������ɹ���
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

// ��ü ���� ����
void CGame::PlayGame()
{
	Print_Game_Board();
}

// ��ü ���� Ÿ�� ��� ���
void CGame::Print_Game_Board()
{
	{
		//TextColor(RED, 0); printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������"); printf("          "); TextColor(CYAN, 0); printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		//TextColor(RED, 0); printf("��                                                                             ��"); printf("          "); TextColor(CYAN, 0); printf("��                                                                             ��\n");
		//TextColor(RED, 0); printf("��                                                                             ��"); printf("          "); TextColor(CYAN, 0); printf("��                                                                             ��\n");
		//TextColor(RED, 0); printf("��                                                                             ��"); printf("          "); TextColor(CYAN, 0); printf("��                                                                             ��\n");
		//TextColor(RED, 0); printf("��                                                                             ��"); printf("          "); TextColor(CYAN, 0); printf("��                                                                             ��\n");
		//TextColor(RED, 0); printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������"); printf("          "); TextColor(CYAN, 0); printf("��������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
		//printf("\n");
		//// Ÿ�� ��� ���� ������
		//{
		//	gotoxy(0, 7);
		//	for (int i = 0; i < 7; i++) // Ÿ��ĭ ��
		//	{
		//		TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf("��"); } printf("��"); //j�� ���κ��� ����
		//	}printf("\n");
		//	for (int l = 0; l < 10; l++) // ���� ���� ����
		//	{
		//		for (int i = 0; i < 7; i++)
		//		{
		//			TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf(" "); } printf("��"); //j ���� ����ĭ ��
		//		}printf("\n");
		//	}
		//	for (int i = 0; i < 7; i++) // Ÿ�� ĭ ��
		//	{
		//		TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf("��"); } printf("��"); // ���� ���� ����
		//	}printf("\n");
		//}
		////���� ������ 6ĭ

		//{
		//	for (int l = 0; l < 7; l++)
		//	{
		//		gotoxy(0, 7 + (l * 12));
		//		for (int i = 0; i < 1; i++)
		//		{
		//			TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf("��"); } printf("��"); //j�� ���κ��� ����
		//		}printf("\n");
		//		for (int l = 0; l < 10; l++) // ���� ���� ����
		//		{
		//			for (int i = 0; i < 1; i++)
		//			{
		//				TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf(" "); } printf("��"); //j ���� ����ĭ ��
		//			}printf("\n");
		//		}
		//		for (int i = 0; i < 1; i++) // Ÿ�� ĭ ��
		//		{
		//			TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf("��"); } printf("��"); // ���� ���� ����
		//		}printf("\n");
		//	}

		//}

		////������ ������
		//{
		//	for (int l = 0; l < 7; l++)
		//	{
		//		gotoxy(230, 7 + (l * 12));
		//		for (int i = 0; i < 1; i++)
		//		{
		//			TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf("��"); } printf("��"); //j�� ���κ��� ����
		//		}printf("\n");
		//		for (int l = 0; l < 10; l++) // ���� ���� ����
		//		{
		//			for (int i = 0; i < 1; i++)
		//			{
		//				TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf(" "); } printf("��"); //j ���� ����ĭ ��
		//			}printf("\n");
		//		}
		//		for (int i = 0; i < 1; i++) // Ÿ�� ĭ ��
		//		{
		//			TextColor(WHITE, 0); printf("��"); for (int j = 0; j < 30; j++) { printf("��"); } printf("��"); // ���� ���� ����
		//		}printf("\n");
		//	}

		//}
	}

	// Top ����ϱ�
	for (int i = 0; i < LAND_LINE_LEN; i++)
	{
		Print_Tile(i * 18, 0);
	}
	gotoxy(4, 2);
	cout << "���ѹα�" << endl;

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

void CGame::Print_Tile(int x, int y) //���� Ÿ�� ���  �׸� 1��.
{
	int iNext_Line = 1;
	gotoxy(x, y);
	//�� �� �� ���
	TextColor(WHITE, 0); cout << "��";
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
	TextColor(WHITE, 0); printf("��"); //�� �� ���
	for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
	{
		cout << "��";
	}
	cout << "��" << endl;
}



