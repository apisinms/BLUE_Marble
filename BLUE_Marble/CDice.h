#pragma once
//#include "CGame.h"
class CDice
{
private:
	void TextColor(int foreground, int background);
	void MoveXY(int x, int y);
	int iDice1, iDice2;
	int iDice_result;
	COORD pos; //주사위 출력 위치.
public:
	CDice();
	~CDice();

	int Throw_Dice(int x, int y, BOOL *bIsDouble);
	void Print_Diceinfo();
};