#include "stdafx.h"
#include "CDice.h"
#include <conio.h>

CDice::CDice()
{
}
CDice::~CDice()
{
}
int CDice::Throw_Dice()
{
	int iResult; // �ֻ��� ����
	int iPower = -1; //�ֻ��� ��
	bool bUpdown = false; //�ִ�ġ���� �ִ�ġ�� �ƴ��� �ִ�ġ =1 �ּ�ġ =0

	iResult = (rand() % 6) + 1;

	_getch();

	Sleep(50);
	while (_kbhit())
	{
		_getch();
		if (bUpdown == 0 && iPower < 9) //�Ŀ��� ��� �͸����� 1����9
		{
			iPower++;
			if (iPower == 9) //9���Ǹ�
				bUpdown = true; //�ִ�ġ�̴�
		}
		else if (bUpdown == true && iPower > 0)
		{
			iPower--;
			if (iPower == 0)  //�Ŀ��� 0�̸�
				bUpdown = false;  //�ּ�ġ�̴�.
		}


		if (bUpdown == false)
		{
			TextColor(4, 4);
			MoveXY(50 + (iPower * 2), 30);
			printf("  ");
		}
		else
		{
			TextColor(0, 15);
			MoveXY(50 + (iPower * 2), 30);
			printf("  ");
		}
		TextColor(0, 15);
		Sleep(60);
	}
	iResult += iPower * 100; //������ 100�� ���� ���� �־��ش�.
	iResult = (iResult % 6) + 1; // 6���� ������ 1�� �����ش�. �� 1����6���̷� ���´�.
	MoveXY(50, 30);
	cout << "                " << endl; // ������ �� ����
	if (iResult <= 0)
	{
		iResult = rand() % 6 + 1;
		//print dice
	}
	else
	{
		//print dice
	}


	return iResult;
}
void CDice::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void CDice::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}