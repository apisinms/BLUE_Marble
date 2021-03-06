// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//
#ifndef __STDAFX__
#define __STDAFX__

#include "targetver.h"

//#include <stdio.h>
//#include <tchar.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <fmod.h>

#include "CDoubleBuffering.h"

#define OS_VER 10

#define PLAYER_MOVE_SPEED 450	// 4~500이 적당할 듯


#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#define P1_COLOR LIGHTGREEN
#define P2_COLOR LIGHTBLUE
#define P3_COLOR LIGHTMAGENTA
#define P4_COLOR LIGHTRED

#define P1_POS 2
#define P2_POS 4
#define P3_POS 6
#define P4_POS 8

#define MAX_BGM 6

#define MAX_FX 24

#define DICE_POS_X 145
#define DICE_POS_Y 2

#define ENTER 13

#define MAX_GAGE 20

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)	// 키 눌렸을 때
#define KEY_UP(vk_code)       ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)	// 키 떼 졌을 때

#define PLAYER_PAY 5
#define PLAYER_START_MONEY 500

#define MAX_LANDS 20


#define BUILD_PRICE_LEFT 2
#define BUILD_PRICE_RIGHT 4
#define BUILD_PRICE_TOP 3
#define BUILD_PRICE_BOTTOM 6

#define LAND_PRICE_TOP 8
#define LAND_PRICE_RIGHT 10
#define LAND_PRICE_LEFT 5
#define LAND_PRICE_BOTTOM 15


#define PLAYER_INFOR_XPOS 145 //플레이어 정보창 위치
#define PLAYER_INFOR_YPOS 20 //플레이어 정보창 위치

#define GOLDKEY_XPOS 25 //플레이어 턴 출력 x좌표
#define GOLDKEY_YPOS 22 // 플레이어 턴 출력 y좌표

#define PLAYER_WIN_XPOS 44 //승리창 출력
#define PLAYER_WIN_YPOS 25 //승리창 출력


enum { GOLDKEY_WORLDTRIP, GOLDKEY_ISLAND, GOLDKEY_START, GOLDKEY_NONE = -1};


typedef enum
{
	START_LAND, BANGKOK_LAND, BEIJING_LAND, TAIPEI_LAND, DUBAI_LAND, KAIRO_LAND,
	ISLAND_LAND, TOKYO_LAND, SIDNEY_LAND, QUEBEC_LAND, HAWAII_LAND, SANGPAWOOLO_LAND,
	WORLDTRIP_LAND, PRAHA_LAND, BERLIN_LAND, MOSCOW_LAND, GENEVA_LAND, ROME_LAND,
	GOLDKEY_LAND, PYEONGYANG_LAND, LONDON_LAND, PARIS_LAND, NEWYORK_LAND, SEOUL_LAND
}ALL_LANDS;

enum
{
	INTRO, INPUTPLAYER, BGM1, BGM2, BGM3, BGM4
};

enum
{
	FX_DICENUM1 = 1, FX_DICENUM2, FX_DICENUM3, FX_DICENUM4, FX_DICENUM5, FX_DICENUM6,
	FX_DICENUM7, FX_DICENUM8, FX_DICENUM9, FX_DICENUM10, FX_DICENUM11, FX_DICENUM12,
	FX_MONTH_PAY, FX_ISLAND_ARRIVE, FX_WORLDTRIP_ARRIVE, FX_GOLDKEY_ARRIVE,
	FX_PLAYER_MOVE, FX_BUILD, FX_THROW_DICE, FX_WIN, FX_DICE_DOUBLE, FX_WORLDTRIP_WANT,
	FX_WORLDTRIP_FLY
};

enum
{
	WORLDTRIP_NONE ,WORLDTRIP_SOUND, WORLDTRIP_MOVE
};

using namespace std;

extern FMOD_SYSTEM *g_System;	// FMOD System 변수 선언
extern FMOD_SOUND *g_FX_Sound[MAX_FX];	// 효과음 전역으로
extern CDoubleBuffering g_DBBF;	// 화면 더블버퍼링을 위한 객체를 선언한다(정의가 아니다)


#endif

