#include "stdafx.h"
#include "CDoubleBuffering.h"


CDoubleBuffering::CDoubleBuffering() // �����ڿ��� ���۸� �����Ѵ�.
{
	CreatBuffer();
}

CDoubleBuffering::~CDoubleBuffering() // �Ҹ��ڿ��� ���۸� ���ش�.
{
	DeleteBuffer();
}

void CDoubleBuffering::CreatBuffer() // ���ۻ����� �޼���
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

void CDoubleBuffering::WriteBuffer(int x, int y, char str[]) // ���ۿ� ������ ���� �޼���
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);
	WriteFile(hBuffer[nScreenIndex], str, strlen(str), &dw, NULL);
}

void CDoubleBuffering::FlippingBuffer() // ���۸� 0���� 1������ ������ ���鼭 �����ִ� �޼���
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
}

void CDoubleBuffering::ClearBuffer() // ���ۿ� �׷��� ��� ������ �������� �����ִ� �޼���
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', MAP_X_MAX * MAP_Y_MAX, Coor, &dw);
}

void CDoubleBuffering::DeleteBuffer() // ���۸� �����ִ� �޼���
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}

void CDoubleBuffering::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(hBuffer[nScreenIndex], color);
}
