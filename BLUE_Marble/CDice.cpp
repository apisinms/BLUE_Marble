#include "stdafx.h"
#include "CDice.h"
#include <time.h>
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
	srand((unsigned)time(NULL));
	iDice1 = rand() % 6 + 1;
	iDice2 = rand() % 6 + 1;
	//iDice1 = 5;
	//iDice2 = 5;
	if (iDice1 == iDice2)
		*bIsDouble = TRUE;
	iDice_result = iDice1 + iDice2;
	return iDice_result;
}
void CDice::Print_Diceinfo()
{
	int iNext_Line = 0;   // 다음 줄


	switch (iDice1)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 2:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;

	case 3:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 4:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 5:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;
	case 6:
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
		break;

	}

}
//int CDice::Throw_Dice()
//{
//   int iResult; // 주사위 눈금
//   int iPower = -1; //주사위 힘
//   bool bUpdown = false; //최대치인지 최대치가 아닌지 최대치 =1 최소치 =0
//
//   iResult = (rand() % 6) + 1;
//
//   _getch();
//
//   Sleep(50);
//   while (_kbhit())
//   {
//      _getch();
//      if (bUpdown == 0 && iPower < 9) //파워가 계속 와리가리 1부터9
//      {
//         iPower++;
//         if (iPower == 9) //9가되면
//            bUpdown = true; //최대치이다
//      }
//      else if (bUpdown == true && iPower > 0)
//      {
//         iPower--;
//         if (iPower == 0)  //파워가 0이면
//            bUpdown = false;  //최소치이다.
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
//   iResult += iPower * 100; //힘에다 100을 곱한 값을 넣어준다.
//   iResult = (iResult % 6) + 1; // 6으로 나누고 1로 더해준다. 즉 1부터6사이로 나온다.
//   MoveXY(50, 30);
//   //cout << "                "<<endl; // 게이지 총 길이
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