#include "stdafx.h"
#include "CDice.h"
#include <time.h>
#include <conio.h>
#include "CGame.h"

CDice::CDice()
{
	srand((unsigned)time(NULL));
}
CDice::~CDice()
{
}

int CDice::Throw_Dice(int x, int y, BOOL *bIsDouble)
{
	pos.X = x;
	pos.Y = y;
	//iDice1 = rand() % 6 + 1;
	//iDice2 = rand() % 6 + 1;
	iDice1 = 4;
	iDice2 = 1;
	if (iDice1 == iDice2)
		*bIsDouble = TRUE;
	iDice_result = iDice1 + iDice2;
	return iDice_result;
}
void CDice::Print_Diceinfo()
{
	int iNext_Line = 0;   // 다음 줄
	
	pos.X = DICE_POS_X;
	pos.Y = DICE_POS_Y;

	g_DBBF.TextColor(RED, BLACK);

	switch (iDice1)
	{
	case 1:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 2:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;

	case 3:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 4:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 5:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│      ●●      │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│      ●●      │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 6:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;

	default:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│  ●●    ●●  │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●        ●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│●●        ●●│");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│        ●●●  │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│       ●       │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│       ●       │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 2:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;

	case 3:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 4:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 5:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│      ●●      │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│    ●●●●    │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│      ●●      │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	case 6:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│                │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●●    ●●●│");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;

	default:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────┐");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"┌────────────────┐");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│  ●●    ●●  │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●        ●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│●●        ●●│");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│        ●●●  │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│       ●       │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│       ●       │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"│     ●●●     │");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────┘");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"└────────────────┘");
#endif
		break;
	}

	// 파라미터 BOOL값을 switch하여 Idle Time 때에는 랜덤으로 마구 출력한다.

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
void CDice::Dice_Proc(CGame &Game)
{
	if (Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_SOUND)
	{
		Game.PlayFX(FX_WORLDTRIP_WANT);
		Game.m_Player[Game.eCurPlayer].iWorldTrip = WORLDTRIP_MOVE;

		if (Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
		{
			// 게이지 없애줌
			g_DBBF.TextColor(BLACK, BLACK);
			for (int i = 0; i < 2; i++)
			{
				g_DBBF.ClearBuffer();
				for (int i = 0; i <= MAX_GAGE; i++)
				{
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");
					Game.Print_All_Tile();
					Game.Print_All_Land();
					Game.Print_All_ExtraLand();
					Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
					Game.Print_All_Character();
					Game.Print_Player_Turn();
					Game.Print_Player_Infor();
					Game.m_Dice.Print_Diceinfo();
				}
				g_DBBF.FlippingBuffer();
			}

			Input_WorldTrip(Game);
		}
	}
	Print_Diceinfo();
	Print_DiceGage(Game);
}

void CDice::Print_DiceGage(CGame &Game)
{
	static int iPower = 0;
	static BOOL bUpdown = FALSE;
	static BOOL bKeyDown = FALSE;
	static BOOL Roll_A_Dice = FALSE;
	//int iKey;	// 키 입력
	static int iCnt = 0;	// 1번 버퍼, 2번 버퍼 둘 다 같은 화면으로 동기화하려면 2번을 진행해야 한다.


	// 스페이스바 키를 누르고 있는 상태일 때
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		iDice1 = iDice2 = -222;	// 디폴트 주사위 '?'
		Print_Diceinfo();
		// 화면 2개이니 2번 돌려서 동기화 시켜준다
		for (int i = 0; i < 2; i++)
		{
			g_DBBF.ClearBuffer();
			if (bUpdown == FALSE)
			{
				int i = 0;

				g_DBBF.TextColor(RED, RED);
				for (i = 0; i <= iPower; i++)
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + iPower, DICE_POS_Y + 15, (TCHAR *)"  ");


				g_DBBF.TextColor(BLACK, WHITE);
				for (; i <= abs(MAX_GAGE - iPower); i++)
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

			}

			else
			{
				g_DBBF.TextColor(BLACK, WHITE);

				for (int i = 0; i <= iPower; i++)
					g_DBBF.WriteBuffer(DICE_POS_X + 8 + iPower, DICE_POS_Y + 15, (TCHAR *)"  ");
			}

			//Sleep(1);

			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_All_Character();
			Print_Diceinfo();
			Game.Print_Player_Infor();

			g_DBBF.FlippingBuffer();

			if (bUpdown == FALSE && iPower < MAX_GAGE) //파워가 계속 와리가리 1부터9
			{
				iCnt++;
				if (iCnt == 2)
				{
					iCnt = 0;
					iPower++;
				}

				if (iPower == MAX_GAGE) //9가되면
					bUpdown = true; //최대치이다
			}
			else if (bUpdown == TRUE && iPower > 0)
			{
				iCnt++;
				if (iCnt == 2)
				{
					iCnt = 0;
					iPower--;
				}

				if (iPower == 0)  //파워가 0이면
					bUpdown = false;  //최소치이다.
			}
		}

  		Roll_A_Dice = TRUE;
		//_getch();
	}

	// 스페이스 키를 뗐을 때
	else
	{
 		if (Roll_A_Dice == TRUE)
		{
			bUpdown = iCnt = iPower = 0;	// 변수들을 다시 초기화해주고
			Game.PlayFX(FX_THROW_DICE);	// 효과음

			Sleep(600);	// 효과음 내고 잠시 대기
			Print_Dice_Result(Game);	// 주사위 굴림

			Roll_A_Dice = FALSE;	// 다음번에 이 else문 들어오면 주사위는 다시 안굴림
		}

		else
		{
			// 검은색으로 게이지 바를 채워준다.
			g_DBBF.TextColor(BLACK, BLACK);
			for (int i = 0; i <= MAX_GAGE; i++)
				g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

			iDice1 = rand() % 6 + 1;
			iDice2 = rand() % 6 + 1;	// 주사위가 계속 돌아가다가 스페이스 키 눌리면 '?'모양의 주사위로 바뀐다
			Print_Diceinfo();
			Sleep(100);
		}
	}
}
void CDice::Print_Dice_Result(CGame &Game)
{
	BOOL bIsDouble = FALSE;	// 더블이냐?
	BOOL bDoubleSound_Played = FALSE;	// 더블 음성이 출력 되었냐?
	BOOL bDiceSound_Played = FALSE;	// 주사위 음성이 출력 되었냐?
	COORD cLandPos;	// 플레이어가 움직여야 할 땅의 포지션
	ALL_LANDS ePlayerStand_Idx;	// 현재 플레이어가 밟고 있는 인덱스(Land + ExtraLand)
	int iDice_Result;	// 주사위 결과
	int AddPos;	// 각 플레이어마다 더해줘야 할 좌표값
	int iHaveToGo_Idx = 0;	// 가야되는 인덱스

	iDice_Result = Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// 주사위 굴린 결과를 얻어옴
	Game.iPlayer_Dice_Result = iDice_Result;	// Game의 플레이어 결과에도 넣어줘야 함.
	ePlayerStand_Idx = Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex();	// 플레이어가 밟고있는 땅 인덱스
	

	// 무인도 걸렸는데 더블이면 남은 턴을 0으로 만들어준다. 즉, 이제 움직인다.
	if (Game.m_Player[Game.eCurPlayer].iLeftTurn > 0 && bIsDouble == TRUE)
		Game.m_Player[Game.eCurPlayer].iLeftTurn = 0;

	// 무인도에 갇혔는데 던진 주사위가 더블이 아니면 그냥 넘어간다.
	else if (Game.m_Player[Game.eCurPlayer].iLeftTurn > 0 && bIsDouble == FALSE)
	{
		Sleep(PLAYER_MOVE_SPEED);
		Game.PlayFX(iDice_Result);	// 소리만 나오고 땡
		Game.m_Player[Game.eCurPlayer].iLeftTurn--;	// 1턴 지남


		g_DBBF.ClearBuffer();
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
		Game.Print_Player_Turn();
		Game.Print_All_Character();
		Game.m_Dice.Print_Diceinfo();
		Game.Print_Player_Infor();
		g_DBBF.FlippingBuffer();

		// 다음 플레이어로
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 다음 플레이어로

		// 다음 플레이어가 세계여행에 있으면 소리가 동시에 나기 때문에
		if (Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex() == WORLDTRIP_LAND)
			Sleep(500);
		return;
	}

	// 더블 최대횟수인데 만약에 더블 또 나오면
	if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE && bIsDouble == TRUE) 
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// 더블 횟수 0으로

		/// 무인도 떨어지는 소리 재생
		// 텍스트로 "더블 3회 하셨습니다." 출력
		Game.PlayFX(FX_DICE_DOUBLE);
		Sleep(PLAYER_MOVE_SPEED + 50);
		Game.PlayFX(iDice_Result);
		Sleep(200);
		Game.PlayFX(FX_ISLAND_ARRIVE);

		/// 무인도 위치를 얻어와서 지금 플레이어를 무인도로 보내버림
		cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
		AddPos = P1_POS * (Game.eCurPlayer + 1);
		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;
		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
		Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
		Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;	// 남은 턴 수 3회
		Game.RePaint(FALSE);
		Game.RePaint(FALSE);	// 두 화면 모두 갱신된 위치로

		Game.iPlayer_Dice_Result = FALSE;

		/// 다음 플레이어로
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);

		Game.eLandPrint_Idx = (ALL_LANDS)ISLAND_LAND;
		return;
	}

	if (bIsDouble == TRUE)
		Game.m_Player[Game.eCurPlayer].bPlayer_Dice_Double = TRUE;

	else
		Game.m_Player[Game.eCurPlayer].bPlayer_Dice_Double = FALSE;

	int Land_Diff = 0;	// ExtraLand랑 Land의 차이를 빼주려고
	iHaveToGo_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// 가야할 땅 = 현재 밟은 땅 + 주사위 눈 더한 값

	// 가야하는 땅까지 한 칸씩 이동 시킨다.
	for (int i = ePlayerStand_Idx + 1; i <= iHaveToGo_Idx; i++)
	{
		// 인덱스로 현재 땅의 위치를 조사해서 ExtraLand와 Land의 차이를 빼준다.
		if (i > START_LAND)
			Land_Diff = 1;

		if (i > ISLAND_LAND)
			Land_Diff = 2;

		if (i > WORLDTRIP_LAND)
			Land_Diff = 3;

		if (i > GOLDKEY_LAND)
			Land_Diff = 4;

		// 밟은 땅의 위치정보를 얻어온다.
		switch (i)
		{
		case START_LAND:	// 출발점
			cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
			break;

		case ISLAND_LAND:	// 무인도
			cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
			break;

		case WORLDTRIP_LAND:	// 세계여행
			cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
			break;

		case GOLDKEY_LAND:	// 황금열쇠
			cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
			break;

		default:
			cLandPos = Game.m_Lands[i - Land_Diff].Get_LandPosition();	// 현재 플레이어가 밟고 있는 땅의 좌표값을 얻어온다.
			break;
		}

		AddPos = P1_POS * (Game.eCurPlayer + 1);	// 플레이어가 지정되어야 하는 위치에 맞게 좌표를 수정해주기 위해서

		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;


		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);

		/// 주사위 음성 출력
		if (bDiceSound_Played == FALSE)
		{
			/// 더블 음성 출력
			if (bDoubleSound_Played == FALSE)
			{
				bDoubleSound_Played = TRUE;

				// 더블 소리 재생
				if (bIsDouble == TRUE)
				{
					Game.PlayFX(FX_DICE_DOUBLE);
					Sleep(PLAYER_MOVE_SPEED + 50);	// 더블~ 음성 딜레이
				}

			}
			bDiceSound_Played = TRUE;
			Game.PlayFX(iDice_Result);
		}

		g_DBBF.ClearBuffer();
		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
		Game.Print_Player_Turn();
		Game.Print_Dice_Result_Text(); //주사위 결과값 출력
		Game.Print_All_Character();
		Game.m_Dice.Print_Diceinfo();
		Game.Print_Player_Infor();

		Sleep(PLAYER_MOVE_SPEED);

		g_DBBF.FlippingBuffer();

		/// 사각 타일 + 땅 + 특수 땅 + 캐릭터 출력
		//Game.RePaint();

		// 플레이어 움직일때 마다 소리 재생(더블에서는 같이 소리를 내줬으니 제외)
			Game.PlayFX(FX_PLAYER_MOVE);
		

		// 월급 소리 재생
			if (i == START_LAND)
			{
				Game.PlayFX(FX_MONTH_PAY);
				// 월급 추가하고 문구 띄움
				Game.m_Player[Game.eCurPlayer].iPlayer_Money += Game.m_Lands[Game.eCurPlayer].iTotal_LandPrice;
			}

		if (i == SEOUL_LAND)	// 인덱스가 맵 끝지점에 도달하면 빼준다.
		{
			iHaveToGo_Idx -= SEOUL_LAND + 1;
			i = START_LAND - 1;
		}
	}// End For State

	// 마지막엔 화면이 Clear가 안되기 때문에 한번 더 그려줘야 한다.
	Game.RePaint(TRUE);

	switch (iHaveToGo_Idx)
	{
	case START_LAND:
		break;

	case ISLAND_LAND:
		Game.PlayFX(FX_ISLAND_ARRIVE);	// 소리 내고
		Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;	// 3턴간 정지
		bIsDouble = FALSE;	// 더블 효과따윈 없으니 다음 플레이어로
		break;

	case WORLDTRIP_LAND:
		Game.PlayFX(FX_WORLDTRIP_ARRIVE);
		Game.m_Player[Game.eCurPlayer].iWorldTrip = WORLDTRIP_SOUND;
		break;

	case GOLDKEY_LAND:
		Game.PlayFX(FX_GOLDKEY_ARRIVE);
		break;


	default:
		Game.m_Lands[iHaveToGo_Idx - Land_Diff].Arrive_Land(Game);
		break;
	}

	Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// 최종 플레이어가 간 땅의 위치를 저장시킴
	Game.m_Lands[iHaveToGo_Idx].Print_Information((ALL_LANDS)iHaveToGo_Idx);
	Game.eLandPrint_Idx = (ALL_LANDS)iHaveToGo_Idx;

	if (bIsDouble == FALSE || Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_SOUND)	// 더블 안나왔거나 세계여행 걸렸을 시
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// 더블이 안나왔으면 더블을 0으로 셋팅해줘야한다.
		Game.iPlayer_Dice_Result = FALSE;

		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 다음 플레이어로
	}

	else // 더블이면
	{
		if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// 최대 더블 횟수까지는 가능
		{
			Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt++;	// 더블 횟수를 1회씩 
			Game.eCurPlayer = Game.eCurPlayer;	// 한 번 더!
		}
	}
}

void CDice::Input_WorldTrip(CGame &Game)
{
	// 선택한 위치가 세계여행만 아니면 이동시켜준다.
	// 세계여행 인덱스보다 작다면 월급을 지급받아야 한다.
	// 세계여행 인덱스보다 크다면 한칸 씩 이동하는 건 동일하지만 월급은 안받는다.
	//Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex;
	ALL_LANDS Select_Land_Idx = WORLDTRIP_LAND;	// 초기 위치는 당연히 세계여행
	int Land_Diff = 1;
	int iHaveToGo_Idx = 0;
	COORD cLandPos;
	while (true)
	{
		BOOL bKeyDown = FALSE;

		if (KEY_DOWN(VK_RETURN))
		{
			g_DBBF.ClearBuffer();
			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_Dice_Result_Text(); //주사위 결과값 출력
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();

			Game.iPlayer_Dice_Result = 0;

			// 어느 병신이 지 스스로 무인도에 들어갔으면 횟수도 그렇게 만들어 줘야 함.
			if (Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex() == ISLAND_LAND)
				Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;

			if (Game.eCurPlayer == (Game.iPlayerNum - 1))
				Game.eCurPlayer = P1;

			else
				Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// 다음 플레이어로


			Game.PlayFX(FX_WORLDTRIP_FLY);	// 날아가는 효과음 넣음
			break;
		}
			

		if (KEY_DOWN(VK_LEFT))
		{
			// 서울 -> 출발
			if (Select_Land_Idx == SEOUL_LAND)	// 제일 큰 ~ 제일 작은 특수한 경우
				Select_Land_Idx = START_LAND;

			// 세계여행 ~ 무인도
			else if (Select_Land_Idx > ISLAND_LAND && Select_Land_Idx <= WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 황금열쇠 ~ 서울
			else if (Select_Land_Idx < SEOUL_LAND && Select_Land_Idx >= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;

		}

		if (KEY_DOWN(VK_RIGHT))
		{
			// 출발 -> 서울
			if (Select_Land_Idx == START_LAND)	// 제일 작은 ~ 제일 큰 특수한 경우
				Select_Land_Idx = SEOUL_LAND;

			// 서울 ~ 황금열쇠
			else if (Select_Land_Idx <= SEOUL_LAND && Select_Land_Idx > GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 무인도 ~ 세계여행
			else if (Select_Land_Idx >= ISLAND_LAND && Select_Land_Idx < WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_UP))
		{
			// 출발 ~ 무인도
			if (Select_Land_Idx >= START_LAND && Select_Land_Idx < ISLAND_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			// 황금열쇠 ~ 세계여행
			else if (Select_Land_Idx > WORLDTRIP_LAND && Select_Land_Idx <= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_DOWN))
		{
			// 무인도 ~ 출발
			if (Select_Land_Idx <= ISLAND_LAND && Select_Land_Idx > START_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 세계여행 ~ 황금열쇠
			else if (Select_Land_Idx >= WORLDTRIP_LAND && Select_Land_Idx < GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}
		

		if (bKeyDown == TRUE)
		{
			// 인덱스로 현재 땅의 위치를 조사해서 ExtraLand와 Land의 차이를 빼준다.
			if (Select_Land_Idx > START_LAND)
				Land_Diff = 1;

			if (Select_Land_Idx > ISLAND_LAND)
				Land_Diff = 2;

			if (Select_Land_Idx > WORLDTRIP_LAND)
				Land_Diff = 3;

			if (Select_Land_Idx > GOLDKEY_LAND)
				Land_Diff = 4;

			// 밟은 땅의 위치정보를 얻어온다.
			switch (Select_Land_Idx)
			{
			case START_LAND:	// 출발점
				cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
				break;

			case ISLAND_LAND:	// 무인도
				cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
				break;

			case WORLDTRIP_LAND:	// 세계여행
				cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
				break;

			case GOLDKEY_LAND:	// 황금열쇠
				cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
				break;

			default:
				cLandPos = Game.m_Lands[Select_Land_Idx - Land_Diff].Get_LandPosition();	// 현재 플레이어가 밟고 있는 땅의 좌표값을 얻어온다.
				break;
			}

			int AddPos = P1_POS * (Game.eCurPlayer + 1);	// 플레이어가 지정되어야 하는 위치에 맞게 좌표를 수정해주기 위해서

			cLandPos.X = (cLandPos.X + AddPos) - 2;
			cLandPos.Y += 2;


			Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
			Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(Select_Land_Idx);	// 최종 플레이어가 간 땅의 위치를 저장시킴
			Game.m_Lands[Select_Land_Idx].Print_Information(Select_Land_Idx);
			Game.eLandPrint_Idx = Select_Land_Idx;

			g_DBBF.ClearBuffer();
			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();
		}

		Sleep(80);
	}
}
