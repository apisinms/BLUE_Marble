#include "stdafx.h"
#include "CDoubleBuffering.h"


CDoubleBuffering::CDoubleBuffering() // 생성자에서 버퍼를 생성한다.
{
	CreatBuffer();
}

CDoubleBuffering::~CDoubleBuffering() // 소멸자에서 버퍼를 없앤다.
{
	DeleteBuffer();
}

void CDoubleBuffering::CreatBuffer() // 버퍼생성용 메서드
{
	COORD size = { MAP_X_MAX, MAP_Y_MAX };
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect;
	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = MAP_X_MAX - 1;;
	rect.Top = MAP_Y_MAX - 1;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);
}

void CDoubleBuffering::WriteBuffer(int x, int y, char str[]) // 버퍼에 내용을 쓰는 메서드
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);
	WriteFile(hBuffer[nScreenIndex], str, strlen(str), &dw, NULL);
}

void CDoubleBuffering::FlippingBuffer() // 버퍼를 0번과 1번으로 번갈아 가면서 보여주는 메서드
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
}

void CDoubleBuffering::ClearBuffer() // 버퍼에 그려진 모든 내용을 공백으로 없애주는 메서드
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', MAP_X_MAX * MAP_Y_MAX, Coor, &dw);
}

void CDoubleBuffering::DeleteBuffer() // 버퍼를 없애주는 메서드
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

void CDoubleBuffering::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(hBuffer[nScreenIndex], color);
}
