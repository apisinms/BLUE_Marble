// BLUE_Marble.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>

int main()
{
	SetConsoleTitle(TEXT("블루마블 게임 ver 0.1"));
	system("mode con cols=190 lines=50");
	CGame Game;
	Game.PlayGame();
    return 0;
}


