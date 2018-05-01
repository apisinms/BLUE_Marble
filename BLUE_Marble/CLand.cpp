//CLand.cpp
#include "stdafx.h"
#include "CLand.h"
#include "CPlayer.h"
#include "CDoubleBuffering.h"

CLand::CLand()
{
}
CLand::~CLand()
{
	if (cLand_Owner != NULL)
	{
		delete[]cLand_Owner;
		cLand_Owner = nullptr;
	}

	if (cLand_Name != NULL)
	{
		delete[]cLand_Name;
		cLand_Name = nullptr;
	}
}

void CLand::Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Pass_Money, int iLand_Build_Price,
	int iLand_Price, int iTotal_LandPrice, int x, int y)
{
	this->iLand_Building = iLand_Building;

	this->cLand_Owner = new TCHAR[lstrlen(cLand_Owner)];
	lstrcpy(this->cLand_Owner, cLand_Owner);

	this->cLand_Name = new TCHAR[lstrlen(cLand_Name)];
	lstrcpy(this->cLand_Name, cLand_Name);

	this->iLand_Pass_Money = iLand_Pass_Money;
	this->iLand_Build_Price = iLand_Build_Price;
	this->iLand_Price = iLand_Price;
	this->iTotal_LandPrice = iTotal_LandPrice;
	pos.X = x;
	pos.Y = y;
}
void CLand::Print_LandInfo()
{
	g_DBBF.WriteBuffer(pos.X, pos.Y, cLand_Name);
}
COORD CLand::Get_LandPosition()
{
	return pos;
}

//void CLand::Buy_Land(CPlayer &Player)
//{
//	iTotal_LandPrice = iLand_Price + (iLand_Building*iLand_Build_Price); //땅의 총 가격은 = 땅 가격 + 건물수*건물가격
//	if (Player.iPlayer_Money >= iTotal_LandPrice)
//	{
//		Player.iPlayer_Money -= iTotal_LandPrice;
//		lstrcpy((TCHAR *)cLand_Owner, (TCHAR *)Player.cPlayer_Name); //소유주가 바뀐다.
//														 //다음턴으로 넘어간다.
//	}
//	else if (Player.iPlayer_Money < iTotal_LandPrice)
//	{
//		cout << "돈이 부족합니다." << endl;
//		//다음턴으로 넘어간다
//	}
//}
//void CLand::Build_Building(CPlayer &Player)
//{
//	char cPlayer_Choice;
//	if (iLand_Building == EMPTY_BUILD)
//	{
//		cout << "건물이 없습니다." << endl;
//		cout << "건물을 지으시겠습니까? (y 또는 n)" << endl;
//		cin >> cPlayer_Choice;
//	}
//	if ((TCHAR *)cPlayer_Choice == "y") //건물 건설 선택 시
//	{
//		if (iLand_Building < MAX_BUILD && Player.iPlayer_Money > iLand_Build_Price)
//		{
//			iLand_Building++;
//		}
//	}
//	else if ((TCHAR *)cPlayer_Choice == "n")
//	{
//		//다음턴으로 넘어간다.
//	}
//}
//void CLand::Sell_Land(CPlayer &Player)
//{
//	while (Player.iPlayer_Money < iLand_Pass_Money) //돈이 통행료보다 커질 때까지 반복
//	{
//		cout << "보유한 땅 목록" << endl;
//		//땅목록을 보여주고
//		//팔 땅을 선택
//
//
//		//if문  다팔아도 통행료보다 부족하면
//		//파산
//	}
//}
//void CLand::Arrive_Land(CPlayer &Player)
//{
//	char cPlayer_Choice;
//	if (cLand_Owner == NULL) //도착했는데 빈 땅이면
//	{
//		cout << "빈 땅입니다." << endl;
//		cout << "땅을 구입하시겠습니까?" << endl;
//		cin >> cPlayer_Choice;
//		if ((TCHAR *)cPlayer_Choice == "y") // 땅 구입 선택 시
//		{
//			Buy_Land(Player);
//		}
//		else if ((TCHAR *)cPlayer_Choice == "n")
//		{
//			//다음턴으로 넘어간다.
//		}
//	}
//	//else if (cLand_Owner == "")//도착했는데 내땅이면
//	//{
//	//	//건물을 짓거나,다음 턴으로 넘어간다
//	//}
//	//else if (cLand_Owner == "")//도착했는데 남의 땅이면
//	//{
//
//	//	if (Player.iPlayer_Money >= iLand_Pass_Money) //통행료를 지불한다.
//	//	{
//	//		Player.iPlayer_Money -= iLand_Pass_Money;
//	//		cout << "땅을 구입하시겠습니까?" << endl; //지불 후 땅 구입 선택
//	//		cin >> cPlayer_Choice;
//	//		if ((TCHAR *)cPlayer_Choice == "y") // 땅 구입 선택 시
//	//		{
//	//			Buy_Land(Player);
//	//		}
//	//		else if ((TCHAR *)cPlayer_Choice == "n")
//	//		{
//	//			//다음턴으로 넘어간다.
//	//		}
//	//	}
//	else if (Player.iPlayer_Money < iLand_Pass_Money) //통행료가 부족하면
//	{
//		Sell_Land(Player);//땅을 판다.
//	}
//}