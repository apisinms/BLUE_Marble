#pragma once
#include "stdafx.h"
#include "CGame.h"


CGame::CGame()
{
}


CGame::~CGame()
{
}


void CGame::textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void CGame::PrintIntro()
{
	cout << "�ϴ� �̰� ��Ʈ�� ȭ���̶�� ġ��!" << endl;
}
