// BLUE_Marble.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>

int main()
{
	CGame Game;
	Game.PrintIntro();
	Game.PlayGame();

    return 0;
}


