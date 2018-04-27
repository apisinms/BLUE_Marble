#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit을 사용하기 위해서
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

// 전체 게임 관장
void CGame::PlayGame()
{
	Print_Game_Board();
}

// 전체 게임 타일 모두 출력
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

			case TOP: // ㅇ
				Print_Tile((j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE)) + (TILE_HORIZONTAL_LEN + TILE_DISTANCE), 0);
				break;

			case RIGHT: // ㅇ
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

void CGame::Print_Tile(int x, int y) //게임 타일 출력  네모 1개.
{
	int iNext_Line = 1;
	gotoxy(x, y);
	//맨 윗 줄 출력
	TextColor(WHITE, 0);
	cout << "┌";
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
	TextColor(WHITE, 0);
	printf("└"); //밑 변 출력
	for (int j = 0; j < TILE_HORIZONTAL_LEN; j++)
	{
		cout << "─";
	}
	cout << "┘" << endl;
}
void CGame::Buy_Land()
{

	iTotal_LandPrice = iLand_Price + (iLand_Building*iLand_Build_Price); //땅의 총 가격은 = 땅 가격 + 건물수*건물가격
	if (iPlayer_Money >= iTotal_LandPrice)
	{
		iPlayer_Money -= iTotal_LandPrice;
		strcpy((CHAR*)cLand_Owner, (CHAR*)cPlayer_Name); //소유주가 바뀐다.
														 //다음턴으로 넘어간다.
	}
	else if (iPlayer_Money < iTotal_LandPrice)
	{
		cout << "돈이 부족합니다." << endl;
		//다음턴으로 넘어간다
	}
}

void CGame::Build_Building()
{
	char cPlayer_Choice;
	if (iLand_Building == EMPTY_BUILD)
	{
		cout << "건물이 없습니다." << endl;
		cout << "건물을 지으시겠습니까? (y 또는 n)" << endl;
		cin >> cPlayer_Choice;
	}
	if ((CHAR *)cPlayer_Choice == "y") //건물 건설 선택 시
	{
		if (iLand_Building < MAX_BUILD&&iPlayer_Money>iLand_Build_Price)
		{
			iLand_Building++;
		}
	}
	else if ((CHAR *)cPlayer_Choice == "n")
	{
		//다음턴으로 넘어간다.
	}
}
void CGame::Sell_Land()
{
	while (iPlayer_Money < iLand_Pass_Money) //돈이 통행료보다 커질 때까지 반복
	{
		cout << "보유한 땅 목록" << endl;
		//땅목록을 보여주고
		//팔 땅을 선택


		//if문  다팔아도 통행료보다 부족하면
		//파산
	}
}
void CGame::Arrive_Land()
{
	char cPlayer_Choice;
	if (cLand_Owner == NULL) //도착했는데 빈 땅이면
	{
		cout << "빈 땅입니다." << endl;
		cout << "땅을 구입하시겠습니까?" << endl;
		cin >> cPlayer_Choice;
		if ((CHAR*)cPlayer_Choice == "y") // 땅 구입 선택 시
		{
			Buy_Land();
		}
		else if ((CHAR *)cPlayer_Choice == "n")
		{
			//다음턴으로 넘어간다.
		}
	}
	else if (cLand_Owner == "")//도착했는데 내땅이면
	{
		//건물을 짓거나,다음 턴으로 넘어간다
	}
	else if (cLand_Owner == "")//도착했는데 남의 땅이면
	{

		if (iPlayer_Money >= iLand_Pass_Money) //통행료를 지불한다.
		{
			iPlayer_Money -= iLand_Pass_Money;
			cout << "땅을 구입하시겠습니까?" << endl; //지불 후 땅 구입 선택
			cin >> cPlayer_Choice;
			if ((CHAR*)cPlayer_Choice == "y") // 땅 구입 선택 시
			{
				Buy_Land();
			}
			else if ((CHAR *)cPlayer_Choice == "n")
			{
				//다음턴으로 넘어간다.
			}
		}
		else if (iPlayer_Money < iLand_Pass_Money) //통행료가 부족하면
		{
			Sell_Land();//땅을 판다.
		}
	}

}
