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
	int iNext_Line = 0;   // ���� ��
	
	pos.X = DICE_POS_X;
	pos.Y = DICE_POS_Y;

	g_DBBF.TextColor(RED, BLACK);

	switch (iDice1)
	{
	case 1:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 2:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;

	case 3:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 4:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 5:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��      �ܡ�      ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��      �ܡ�      ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 6:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;

	default:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��  �ܡ�    �ܡ�  ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡ�        �ܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"���ܡ�        �ܡܦ�");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��        �ܡܡ�  ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��       ��       ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��       ��       ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	}
	iNext_Line = 0;
	switch (iDice2)
	{
	case 1:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 2:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;

	case 3:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 4:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 5:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��      �ܡ�      ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��    �ܡܡܡ�    ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��      �ܡ�      ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	case 6:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��                ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡܡ�    �ܡܡܦ�");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;

	default:
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��  �ܡ�    �ܡ�  ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡ�        �ܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"���ܡ�        �ܡܦ�");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��        �ܡܡ�  ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��       ��       ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��       ��       ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��     �ܡܡ�     ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"��������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(pos.X + 20, pos.Y + iNext_Line++, (TCHAR *)"������������������������������������");
#endif
		break;
	}

	// �Ķ���� BOOL���� switch�Ͽ� Idle Time ������ �������� ���� ����Ѵ�.

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
			// ������ ������
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
	//int iKey;	// Ű �Է�
	static int iCnt = 0;	// 1�� ����, 2�� ���� �� �� ���� ȭ������ ����ȭ�Ϸ��� 2���� �����ؾ� �Ѵ�.


	// �����̽��� Ű�� ������ �ִ� ������ ��
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		iDice1 = iDice2 = -222;	// ����Ʈ �ֻ��� '?'
		Print_Diceinfo();
		// ȭ�� 2���̴� 2�� ������ ����ȭ �����ش�
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

			if (bUpdown == FALSE && iPower < MAX_GAGE) //�Ŀ��� ��� �͸����� 1����9
			{
				iCnt++;
				if (iCnt == 2)
				{
					iCnt = 0;
					iPower++;
				}

				if (iPower == MAX_GAGE) //9���Ǹ�
					bUpdown = true; //�ִ�ġ�̴�
			}
			else if (bUpdown == TRUE && iPower > 0)
			{
				iCnt++;
				if (iCnt == 2)
				{
					iCnt = 0;
					iPower--;
				}

				if (iPower == 0)  //�Ŀ��� 0�̸�
					bUpdown = false;  //�ּ�ġ�̴�.
			}
		}

  		Roll_A_Dice = TRUE;
		//_getch();
	}

	// �����̽� Ű�� ���� ��
	else
	{
 		if (Roll_A_Dice == TRUE)
		{
			bUpdown = iCnt = iPower = 0;	// �������� �ٽ� �ʱ�ȭ���ְ�
			Game.PlayFX(FX_THROW_DICE);	// ȿ����

			Sleep(600);	// ȿ���� ���� ��� ���
			Print_Dice_Result(Game);	// �ֻ��� ����

			Roll_A_Dice = FALSE;	// �������� �� else�� ������ �ֻ����� �ٽ� �ȱ���
		}

		else
		{
			// ���������� ������ �ٸ� ä���ش�.
			g_DBBF.TextColor(BLACK, BLACK);
			for (int i = 0; i <= MAX_GAGE; i++)
				g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

			iDice1 = rand() % 6 + 1;
			iDice2 = rand() % 6 + 1;	// �ֻ����� ��� ���ư��ٰ� �����̽� Ű ������ '?'����� �ֻ����� �ٲ��
			Print_Diceinfo();
			Sleep(100);
		}
	}
}
void CDice::Print_Dice_Result(CGame &Game)
{
	BOOL bIsDouble = FALSE;	// �����̳�?
	BOOL bDoubleSound_Played = FALSE;	// ���� ������ ��� �Ǿ���?
	BOOL bDiceSound_Played = FALSE;	// �ֻ��� ������ ��� �Ǿ���?
	COORD cLandPos;	// �÷��̾ �������� �� ���� ������
	ALL_LANDS ePlayerStand_Idx;	// ���� �÷��̾ ��� �ִ� �ε���(Land + ExtraLand)
	int iDice_Result;	// �ֻ��� ���
	int AddPos;	// �� �÷��̾�� ������� �� ��ǥ��
	int iHaveToGo_Idx = 0;	// ���ߵǴ� �ε���

	iDice_Result = Throw_Dice(DICE_POS_X, DICE_POS_Y, &bIsDouble);	// �ֻ��� ���� ����� ����
	Game.iPlayer_Dice_Result = iDice_Result;	// Game�� �÷��̾� ������� �־���� ��.
	ePlayerStand_Idx = Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex();	// �÷��̾ ����ִ� �� �ε���
	

	// ���ε� �ɷȴµ� �����̸� ���� ���� 0���� ������ش�. ��, ���� �����δ�.
	if (Game.m_Player[Game.eCurPlayer].iLeftTurn > 0 && bIsDouble == TRUE)
		Game.m_Player[Game.eCurPlayer].iLeftTurn = 0;

	// ���ε��� �����µ� ���� �ֻ����� ������ �ƴϸ� �׳� �Ѿ��.
	else if (Game.m_Player[Game.eCurPlayer].iLeftTurn > 0 && bIsDouble == FALSE)
	{
		Sleep(PLAYER_MOVE_SPEED);
		Game.PlayFX(iDice_Result);	// �Ҹ��� ������ ��
		Game.m_Player[Game.eCurPlayer].iLeftTurn--;	// 1�� ����


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

		// ���� �÷��̾��
		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// ���� �÷��̾��

		// ���� �÷��̾ ���迩�࿡ ������ �Ҹ��� ���ÿ� ���� ������
		if (Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex() == WORLDTRIP_LAND)
			Sleep(500);
		return;
	}

	// ���� �ִ�Ƚ���ε� ���࿡ ���� �� ������
	if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt >= MAX_DOUBLE && bIsDouble == TRUE) 
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// ���� Ƚ�� 0����

		/// ���ε� �������� �Ҹ� ���
		// �ؽ�Ʈ�� "���� 3ȸ �ϼ̽��ϴ�." ���
		Game.PlayFX(FX_DICE_DOUBLE);
		Sleep(PLAYER_MOVE_SPEED + 50);
		Game.PlayFX(iDice_Result);
		Sleep(200);
		Game.PlayFX(FX_ISLAND_ARRIVE);

		/// ���ε� ��ġ�� ���ͼ� ���� �÷��̾ ���ε��� ��������
		cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
		AddPos = P1_POS * (Game.eCurPlayer + 1);
		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;
		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
		Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(ISLAND_LAND);
		Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;	// ���� �� �� 3ȸ
		Game.RePaint(FALSE);
		Game.RePaint(FALSE);	// �� ȭ�� ��� ���ŵ� ��ġ��

		Game.iPlayer_Dice_Result = FALSE;

		/// ���� �÷��̾��
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

	int Land_Diff = 0;	// ExtraLand�� Land�� ���̸� ���ַ���
	iHaveToGo_Idx = (ALL_LANDS)(iDice_Result + ePlayerStand_Idx);	// ������ �� = ���� ���� �� + �ֻ��� �� ���� ��

	// �����ϴ� ������ �� ĭ�� �̵� ��Ų��.
	for (int i = ePlayerStand_Idx + 1; i <= iHaveToGo_Idx; i++)
	{
		// �ε����� ���� ���� ��ġ�� �����ؼ� ExtraLand�� Land�� ���̸� ���ش�.
		if (i > START_LAND)
			Land_Diff = 1;

		if (i > ISLAND_LAND)
			Land_Diff = 2;

		if (i > WORLDTRIP_LAND)
			Land_Diff = 3;

		if (i > GOLDKEY_LAND)
			Land_Diff = 4;

		// ���� ���� ��ġ������ ���´�.
		switch (i)
		{
		case START_LAND:	// �����
			cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
			break;

		case ISLAND_LAND:	// ���ε�
			cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
			break;

		case WORLDTRIP_LAND:	// ���迩��
			cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
			break;

		case GOLDKEY_LAND:	// Ȳ�ݿ���
			cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
			break;

		default:
			cLandPos = Game.m_Lands[i - Land_Diff].Get_LandPosition();	// ���� �÷��̾ ��� �ִ� ���� ��ǥ���� ���´�.
			break;
		}

		AddPos = P1_POS * (Game.eCurPlayer + 1);	// �÷��̾ �����Ǿ�� �ϴ� ��ġ�� �°� ��ǥ�� �������ֱ� ���ؼ�

		cLandPos.X = (cLandPos.X + AddPos) - 2;
		cLandPos.Y += 2;


		Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);

		/// �ֻ��� ���� ���
		if (bDiceSound_Played == FALSE)
		{
			/// ���� ���� ���
			if (bDoubleSound_Played == FALSE)
			{
				bDoubleSound_Played = TRUE;

				// ���� �Ҹ� ���
				if (bIsDouble == TRUE)
				{
					Game.PlayFX(FX_DICE_DOUBLE);
					Sleep(PLAYER_MOVE_SPEED + 50);	// ����~ ���� ������
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
		Game.Print_Dice_Result_Text(); //�ֻ��� ����� ���
		Game.Print_All_Character();
		Game.m_Dice.Print_Diceinfo();
		Game.Print_Player_Infor();

		Sleep(PLAYER_MOVE_SPEED);

		g_DBBF.FlippingBuffer();

		/// �簢 Ÿ�� + �� + Ư�� �� + ĳ���� ���
		//Game.RePaint();

		// �÷��̾� �����϶� ���� �Ҹ� ���(�������� ���� �Ҹ��� �������� ����)
			Game.PlayFX(FX_PLAYER_MOVE);
		

		// ���� �Ҹ� ���
			if (i == START_LAND)
			{
				Game.PlayFX(FX_MONTH_PAY);
				// ���� �߰��ϰ� ���� ���
				Game.m_Player[Game.eCurPlayer].iPlayer_Money += Game.m_Lands[Game.eCurPlayer].iTotal_LandPrice;
			}

		if (i == SEOUL_LAND)	// �ε����� �� �������� �����ϸ� ���ش�.
		{
			iHaveToGo_Idx -= SEOUL_LAND + 1;
			i = START_LAND - 1;
		}
	}// End For State

	// �������� ȭ���� Clear�� �ȵǱ� ������ �ѹ� �� �׷���� �Ѵ�.
	Game.RePaint(TRUE);

	switch (iHaveToGo_Idx)
	{
	case START_LAND:
		break;

	case ISLAND_LAND:
		Game.PlayFX(FX_ISLAND_ARRIVE);	// �Ҹ� ����
		Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;	// 3�ϰ� ����
		bIsDouble = FALSE;	// ���� ȿ������ ������ ���� �÷��̾��
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

	Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex((ALL_LANDS)iHaveToGo_Idx);	// ���� �÷��̾ �� ���� ��ġ�� �����Ŵ
	Game.m_Lands[iHaveToGo_Idx].Print_Information((ALL_LANDS)iHaveToGo_Idx);
	Game.eLandPrint_Idx = (ALL_LANDS)iHaveToGo_Idx;

	if (bIsDouble == FALSE || Game.m_Player[Game.eCurPlayer].iWorldTrip == WORLDTRIP_SOUND)	// ���� �ȳ��԰ų� ���迩�� �ɷ��� ��
	{
		Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt = 0;	// ������ �ȳ������� ������ 0���� ����������Ѵ�.
		Game.iPlayer_Dice_Result = FALSE;

		if (Game.eCurPlayer == (Game.iPlayerNum - 1))
			Game.eCurPlayer = P1;

		else
			Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// ���� �÷��̾��
	}

	else // �����̸�
	{
		if (Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt < MAX_DOUBLE)	// �ִ� ���� Ƚ�������� ����
		{
			Game.m_Player[Game.eCurPlayer].iDiceDoubleCnt++;	// ���� Ƚ���� 1ȸ�� 
			Game.eCurPlayer = Game.eCurPlayer;	// �� �� ��!
		}
	}
}

void CDice::Input_WorldTrip(CGame &Game)
{
	// ������ ��ġ�� ���迩�ุ �ƴϸ� �̵������ش�.
	// ���迩�� �ε������� �۴ٸ� ������ ���޹޾ƾ� �Ѵ�.
	// ���迩�� �ε������� ũ�ٸ� ��ĭ �� �̵��ϴ� �� ���������� ������ �ȹ޴´�.
	//Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex;
	ALL_LANDS Select_Land_Idx = WORLDTRIP_LAND;	// �ʱ� ��ġ�� �翬�� ���迩��
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
			Game.Print_Dice_Result_Text(); //�ֻ��� ����� ���
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();

			Game.iPlayer_Dice_Result = 0;

			// ��� ������ �� ������ ���ε��� ������ Ƚ���� �׷��� ����� ��� ��.
			if (Game.m_Player[Game.eCurPlayer].Get_PlayerStandIndex() == ISLAND_LAND)
				Game.m_Player[Game.eCurPlayer].iLeftTurn = LEFT_TURN;

			if (Game.eCurPlayer == (Game.iPlayerNum - 1))
				Game.eCurPlayer = P1;

			else
				Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);	// ���� �÷��̾��


			Game.PlayFX(FX_WORLDTRIP_FLY);	// ���ư��� ȿ���� ����
			break;
		}
			

		if (KEY_DOWN(VK_LEFT))
		{
			// ���� -> ���
			if (Select_Land_Idx == SEOUL_LAND)	// ���� ū ~ ���� ���� Ư���� ���
				Select_Land_Idx = START_LAND;

			// ���迩�� ~ ���ε�
			else if (Select_Land_Idx > ISLAND_LAND && Select_Land_Idx <= WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// Ȳ�ݿ��� ~ ����
			else if (Select_Land_Idx < SEOUL_LAND && Select_Land_Idx >= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;

		}

		if (KEY_DOWN(VK_RIGHT))
		{
			// ��� -> ����
			if (Select_Land_Idx == START_LAND)	// ���� ���� ~ ���� ū Ư���� ���
				Select_Land_Idx = SEOUL_LAND;

			// ���� ~ Ȳ�ݿ���
			else if (Select_Land_Idx <= SEOUL_LAND && Select_Land_Idx > GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// ���ε� ~ ���迩��
			else if (Select_Land_Idx >= ISLAND_LAND && Select_Land_Idx < WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_UP))
		{
			// ��� ~ ���ε�
			if (Select_Land_Idx >= START_LAND && Select_Land_Idx < ISLAND_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			// Ȳ�ݿ��� ~ ���迩��
			else if (Select_Land_Idx > WORLDTRIP_LAND && Select_Land_Idx <= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_DOWN))
		{
			// ���ε� ~ ���
			if (Select_Land_Idx <= ISLAND_LAND && Select_Land_Idx > START_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// ���迩�� ~ Ȳ�ݿ���
			else if (Select_Land_Idx >= WORLDTRIP_LAND && Select_Land_Idx < GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}
		

		if (bKeyDown == TRUE)
		{
			// �ε����� ���� ���� ��ġ�� �����ؼ� ExtraLand�� Land�� ���̸� ���ش�.
			if (Select_Land_Idx > START_LAND)
				Land_Diff = 1;

			if (Select_Land_Idx > ISLAND_LAND)
				Land_Diff = 2;

			if (Select_Land_Idx > WORLDTRIP_LAND)
				Land_Diff = 3;

			if (Select_Land_Idx > GOLDKEY_LAND)
				Land_Diff = 4;

			// ���� ���� ��ġ������ ���´�.
			switch (Select_Land_Idx)
			{
			case START_LAND:	// �����
				cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
				break;

			case ISLAND_LAND:	// ���ε�
				cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
				break;

			case WORLDTRIP_LAND:	// ���迩��
				cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
				break;

			case GOLDKEY_LAND:	// Ȳ�ݿ���
				cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
				break;

			default:
				cLandPos = Game.m_Lands[Select_Land_Idx - Land_Diff].Get_LandPosition();	// ���� �÷��̾ ��� �ִ� ���� ��ǥ���� ���´�.
				break;
			}

			int AddPos = P1_POS * (Game.eCurPlayer + 1);	// �÷��̾ �����Ǿ�� �ϴ� ��ġ�� �°� ��ǥ�� �������ֱ� ���ؼ�

			cLandPos.X = (cLandPos.X + AddPos) - 2;
			cLandPos.Y += 2;


			Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
			Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(Select_Land_Idx);	// ���� �÷��̾ �� ���� ��ġ�� �����Ŵ
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
