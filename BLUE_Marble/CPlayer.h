#pragma once
#include "CLand.h"
class CLand;
class CPlayer
{
	friend CLand;	// CLand�� private ������� �����ϱ� ���ؼ�
private:
	int iPlayer_Money;
	char *cPlayer_Name;
public:
	CPlayer();
	~CPlayer();
};

