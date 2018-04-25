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
