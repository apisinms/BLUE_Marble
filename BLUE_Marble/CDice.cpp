#include "stdafx.h"
#include "CDice.h"
#include<time.h>
#include <conio.h>

CDice::CDice()
{
}
CDice::~CDice()
{
}
int CDice::Throw_Dice(int x, int y, BOOL *bIsDouble)
{
	pos.X = x;
	pos.Y = y;
	this->iDice1 = iDice1;
	this->iDice2 = iDice2;
	this->iDice_result = iDice_result;
	srand((unsigned)time(NULL));
	iDice1 = rand() % 6 + 1;
	iDice2 = rand() % 6 + 1;
	if (iDice1 == iDice2)
		*bIsDouble = TRUE;
	iDice_result = iDice1 + iDice1;
	return iDice_result;
}
void CDice::Print_Diceinfo()
{
	int iNext_Line = 0;   // ���� ��
	switch (iDice1)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
		break;

	}
}
//int CDice::Throw_Dice()
//{
//   int iResult; // �ֻ��� ����
//   int iPower = -1; //�ֻ��� ��
//   bool bUpdown = false; //�ִ�ġ���� �ִ�ġ�� �ƴ��� �ִ�ġ =1 �ּ�ġ =0
//
//   iResult = (rand() % 6) + 1;
//
//   _getch();
//
//   Sleep(50);
//   while (_kbhit())
//   {
//      _getch();
//      if (bUpdown == 0 && iPower < 9) //�Ŀ��� ��� �͸����� 1����9
//      {
//         iPower++;
//         if (iPower == 9) //9���Ǹ�
//            bUpdown = true; //�ִ�ġ�̴�
//      }
//      else if (bUpdown == true && iPower > 0)
//      {
//         iPower--;
//         if (iPower == 0)  //�Ŀ��� 0�̸�
//            bUpdown = false;  //�ּ�ġ�̴�.
//      }
//
//
//      if (bUpdown == false)
//      {
//         g_DBBF.TextColor(4, 4);
//         MoveXY(50 + (iPower * 2), 30);
//         g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR*)"  ");
//
//      }
//      else
//      {
//         g_DBBF.TextColor(0, 15);
//         g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR*)"  ");
//      }
//      g_DBBF.TextColor(0, 15);
//      Sleep(60);
//   }
//   iResult += iPower * 100; //������ 100�� ���� ���� �־��ش�.
//   iResult = (iResult % 6) + 1; // 6���� ������ 1�� �����ش�. �� 1����6���̷� ���´�.
//   MoveXY(50, 30);
//   //cout << "                "<<endl; // ������ �� ����
//   g_DBBF.WriteBuffer(50 + (iPower * 2), 30, (TCHAR*)"                ");
//   if (iResult <= 0)
//   {
//      iResult = rand() % 6 + 1;
//      Print_Dice(iResult, g_DBBF);
//   }
//   else
//   {
//      Print_Dice(iResult, g_DBBF);
//   }
//
//
//   return iResult;
//}
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