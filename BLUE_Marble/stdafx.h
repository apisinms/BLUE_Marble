// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

#include "CDoubleBuffering.h"


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

#define DICE_POS_X 150
#define DICE_POS_Y 20

#define ENTER 13

typedef enum
{
	START_LAND, BANGKOK_LAND, BEIJING_LAND, TAIPEI_LAND, DUBAI_LAND, KAIRO_LAND,
	ISLAND_LAND, TOKYO_LAND, SIDNEY_LAND, QUEBEC_LAND, HAWAII_LAND, SANGPAWOOLO_LAND,
	WORLDTRIP_LAND, PRAHA_LAND, BERLIN_LAND, MOSCOW_LAND, GENEVA_LAND, ROME_LAND,
	GOLDKEY_LAND, PYEONGYANG_LAND, LONDON_LAND, PARIS_LAND, NEWYORK_LAND, SEOUL_LAND
}ALL_LANDS;

using namespace std;

//extern FMOD_SYSTEM *g_System;	// FMOD System 변수 선언
extern CDoubleBuffering g_DBBF;	// 화면 더블버퍼링을 위한 객체를 선언한다(정의가 아니다)


