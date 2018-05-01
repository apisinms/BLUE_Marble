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
//	iTotal_LandPrice = iLand_Price + (iLand_Building*iLand_Build_Price); //���� �� ������ = �� ���� + �ǹ���*�ǹ�����
//	if (Player.iPlayer_Money >= iTotal_LandPrice)
//	{
//		Player.iPlayer_Money -= iTotal_LandPrice;
//		lstrcpy((TCHAR *)cLand_Owner, (TCHAR *)Player.cPlayer_Name); //�����ְ� �ٲ��.
//														 //���������� �Ѿ��.
//	}
//	else if (Player.iPlayer_Money < iTotal_LandPrice)
//	{
//		cout << "���� �����մϴ�." << endl;
//		//���������� �Ѿ��
//	}
//}
//void CLand::Build_Building(CPlayer &Player)
//{
//	char cPlayer_Choice;
//	if (iLand_Building == EMPTY_BUILD)
//	{
//		cout << "�ǹ��� �����ϴ�." << endl;
//		cout << "�ǹ��� �����ðڽ��ϱ�? (y �Ǵ� n)" << endl;
//		cin >> cPlayer_Choice;
//	}
//	if ((TCHAR *)cPlayer_Choice == "y") //�ǹ� �Ǽ� ���� ��
//	{
//		if (iLand_Building < MAX_BUILD && Player.iPlayer_Money > iLand_Build_Price)
//		{
//			iLand_Building++;
//		}
//	}
//	else if ((TCHAR *)cPlayer_Choice == "n")
//	{
//		//���������� �Ѿ��.
//	}
//}
//void CLand::Sell_Land(CPlayer &Player)
//{
//	while (Player.iPlayer_Money < iLand_Pass_Money) //���� ����Ẹ�� Ŀ�� ������ �ݺ�
//	{
//		cout << "������ �� ���" << endl;
//		//������� �����ְ�
//		//�� ���� ����
//
//
//		//if��  ���ȾƵ� ����Ẹ�� �����ϸ�
//		//�Ļ�
//	}
//}
//void CLand::Arrive_Land(CPlayer &Player)
//{
//	char cPlayer_Choice;
//	if (cLand_Owner == NULL) //�����ߴµ� �� ���̸�
//	{
//		cout << "�� ���Դϴ�." << endl;
//		cout << "���� �����Ͻðڽ��ϱ�?" << endl;
//		cin >> cPlayer_Choice;
//		if ((TCHAR *)cPlayer_Choice == "y") // �� ���� ���� ��
//		{
//			Buy_Land(Player);
//		}
//		else if ((TCHAR *)cPlayer_Choice == "n")
//		{
//			//���������� �Ѿ��.
//		}
//	}
//	//else if (cLand_Owner == "")//�����ߴµ� �����̸�
//	//{
//	//	//�ǹ��� ���ų�,���� ������ �Ѿ��
//	//}
//	//else if (cLand_Owner == "")//�����ߴµ� ���� ���̸�
//	//{
//
//	//	if (Player.iPlayer_Money >= iLand_Pass_Money) //����Ḧ �����Ѵ�.
//	//	{
//	//		Player.iPlayer_Money -= iLand_Pass_Money;
//	//		cout << "���� �����Ͻðڽ��ϱ�?" << endl; //���� �� �� ���� ����
//	//		cin >> cPlayer_Choice;
//	//		if ((TCHAR *)cPlayer_Choice == "y") // �� ���� ���� ��
//	//		{
//	//			Buy_Land(Player);
//	//		}
//	//		else if ((TCHAR *)cPlayer_Choice == "n")
//	//		{
//	//			//���������� �Ѿ��.
//	//		}
//	//	}
//	else if (Player.iPlayer_Money < iLand_Pass_Money) //����ᰡ �����ϸ�
//	{
//		Sell_Land(Player);//���� �Ǵ�.
//	}
//}