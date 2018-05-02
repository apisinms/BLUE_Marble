#ifndef __CDICE__
#define __CDICE__
class CGame;
class CDice
{
private:
	void TextColor(int foreground, int background);
	void MoveXY(int x, int y);
	int iDice1, iDice2;
	int iDice_result;
	COORD pos; //주사위 출력 위치.
	void Print_DiceGage(CGame &Game);
public:
	CDice();
	~CDice();

	int Throw_Dice(int x, int y, BOOL *bIsDouble);
	void Print_Diceinfo();
	void Print_Dice_Result(CGame &Game);
	void Dice_Proc(CGame &Game);
};
#endif