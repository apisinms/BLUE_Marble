#pragma once
#include "CLand.h"
class CLand;
class CPlayer
{
	friend CLand;	// CLand의 private 멤버들을 접근하기 위해서
private:
	int iPlayer_Money;
	char *cPlayer_Name;
public:
	CPlayer();
	~CPlayer();
};

