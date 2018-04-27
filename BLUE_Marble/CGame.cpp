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
	while (true)
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

	for (eBoardLTRB = LEFT, i = 0; i < 4;)
	{
		for (j = 0; j < LAND_LINE_LEN; j++)
		{
			switch (eBoardLTRB)
			{
			case LEFT: // L
				Print_Tile(0, j * (TILE_VERTICAL_LEN + TILE_DISTANCE));
				break;

			case TOP: // ��
				Print_Tile((j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE)) + (TILE_HORIZONTAL_LEN + TILE_DISTANCE), 0);
				break;

			case RIGHT: // ��
				Print_Tile((TILE_HORIZONTAL_LEN * (LAND_LINE_LEN + 1)) + (TILE_DISTANCE - 1), (j * (TILE_VERTICAL_LEN + TILE_DISTANCE)) + (TILE_VERTICAL_LEN + TILE_DISTANCE));
				break;

			case BOTTOM: // B
				Print_Tile(j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE), (TILE_VERTICAL_LEN + TILE_DISTANCE) * LAND_LINE_LEN);
				break;
			}
		}
		eBoardLTRB = (BOARD_LTRB)++i;
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
void CGame::Buy_Land()
{

	iTotal_LandPrice = iLand_Price + (iLand_Building*iLand_Build_Price); //���� �� ������ = �� ���� + �ǹ���*�ǹ�����
	if (iPlayer_Money >= iTotal_LandPrice)
	{
		iPlayer_Money -= iTotal_LandPrice;
		strcpy((CHAR*)cLand_Owner, (CHAR*)cPlayer_Name); //�����ְ� �ٲ��.
														 //���������� �Ѿ��.
	}
	else if (iPlayer_Money < iTotal_LandPrice)
	{
		cout << "���� �����մϴ�." << endl;
		//���������� �Ѿ��
	}
}

void CGame::Build_Building()
{
	char cPlayer_Choice;
	if (iLand_Building == EMPTY_BUILD)
	{
		cout << "�ǹ��� �����ϴ�." << endl;
		cout << "�ǹ��� �����ðڽ��ϱ�? (y �Ǵ� n)" << endl;
		cin >> cPlayer_Choice;
	}
	if ((CHAR *)cPlayer_Choice == "y") //�ǹ� �Ǽ� ���� ��
	{
		if (iLand_Building < MAX_BUILD&&iPlayer_Money>iLand_Build_Price)
		{
			iLand_Building++;
		}
	}
	else if ((CHAR *)cPlayer_Choice == "n")
	{
		//���������� �Ѿ��.
	}
}
void CGame::Sell_Land()
{
	while (iPlayer_Money < iLand_Pass_Money) //���� ����Ẹ�� Ŀ�� ������ �ݺ�
	{
		cout << "������ �� ���" << endl;
		//������� �����ְ�
		//�� ���� ����


		//if��  ���ȾƵ� ����Ẹ�� �����ϸ�
		//�Ļ�
	}
}
void CGame::Arrive_Land()
{
	char cPlayer_Choice;
	if (cLand_Owner == NULL) //�����ߴµ� �� ���̸�
	{
		cout << "�� ���Դϴ�." << endl;
		cout << "���� �����Ͻðڽ��ϱ�?" << endl;
		cin >> cPlayer_Choice;
		if ((CHAR*)cPlayer_Choice == "y") // �� ���� ���� ��
		{
			Buy_Land();
		}
		else if ((CHAR *)cPlayer_Choice == "n")
		{
			//���������� �Ѿ��.
		}
	}
	else if (cLand_Owner == "")//�����ߴµ� �����̸�
	{
		//�ǹ��� ���ų�,���� ������ �Ѿ��
	}
	else if (cLand_Owner == "")//�����ߴµ� ���� ���̸�
	{

		if (iPlayer_Money >= iLand_Pass_Money) //����Ḧ �����Ѵ�.
		{
			iPlayer_Money -= iLand_Pass_Money;
			cout << "���� �����Ͻðڽ��ϱ�?" << endl; //���� �� �� ���� ����
			cin >> cPlayer_Choice;
			if ((CHAR*)cPlayer_Choice == "y") // �� ���� ���� ��
			{
				Buy_Land();
			}
			else if ((CHAR *)cPlayer_Choice == "n")
			{
				//���������� �Ѿ��.
			}
		}
		else if (iPlayer_Money < iLand_Pass_Money) //����ᰡ �����ϸ�
		{
			Sell_Land();//���� �Ǵ�.
		}
	}

}
