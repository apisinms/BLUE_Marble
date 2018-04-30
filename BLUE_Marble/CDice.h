#pragma once
class CDice
{
private:
	void TextColor(int foreground, int background);
	void MoveXY(int x, int y);
public:
	CDice();
	~CDice();

	int Throw_Dice();

};

