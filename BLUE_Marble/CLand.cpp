//CLand.cpp
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>

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

void CLand::Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Build_Price,
	int iLand_Price, int x, int y)
{
	this->iLand_Building = iLand_Building;

	this->cLand_Owner = new TCHAR[lstrlen(cLand_Owner) + 20];
	lstrcpy(this->cLand_Owner, cLand_Owner);

	this->cLand_Name = new TCHAR[lstrlen(cLand_Name) + 20];
	lstrcpy(this->cLand_Name, cLand_Name);

	this->iLand_Build_Price = iLand_Build_Price;
	this->iLand_Price = iLand_Price;
	this->iLand_Pass_Money = 0;
	this->iTotal_LandPrice = 0;

	pos.X = x;
	pos.Y = y;
}
void CLand::Print_LandInfo()
{
	if(lstrcmp((TCHAR*)"��", cLand_Owner) == 0)
		g_DBBF.TextColor(P1_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"��", cLand_Owner) == 0)
		g_DBBF.TextColor(P2_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"��", cLand_Owner) == 0)
		g_DBBF.TextColor(P3_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"��", cLand_Owner) == 0)
		g_DBBF.TextColor(P4_COLOR, BLACK);

	else
		g_DBBF.TextColor(WHITE, BLACK);

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

void CLand::Print_Information(ALL_LANDS iLand_ID)
{
	int iNext_Line = 0;
	g_DBBF.TextColor(WHITE, BLACK);

	switch (iLand_ID)
	{
	case ISLAND_LAND: //���ε�
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���ε��� �����̽��ϴ�.                   ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ �����ð��� ��ٸ�����.            ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ƴϸ� ���� ����� ������^^              ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� (�ֻ��� ���� �� Ż���մϴ�.)             ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� (Ȥ�� 3���� ����մϴ�.    )             ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		break;
	case WORLDTRIP_LAND: //���迩��
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ����ſ� ���� �����Դϴ�.��              ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ����� ���� �Ǽ���~                      ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� (���ϴ� Ÿ���� �����ϼ���.)              ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� (���� �Ͽ� �̵��մϴ�.)                  ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		break;
	case START_LAND: //�����
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ����� �Դϴ�.                           ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� ������ �� ������ ������ �޽��ϴ�.��++ ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������������������������������������������������");
#endif
		break;
	case GOLDKEY_LAND: //Ȳ�ݿ���
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �αٵα�, Ȳ�� ���迡 �����߽��ϴ�.     ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ����� ���� �����ϼ���~                 ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case BANGKOK_LAND: //���� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �±��� ����. �ų� 1,600�� ����          ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ã�� �������� ����.                     ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��Ÿ� ������ õ���̱⵵ �� ������      ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �±��� ��丮�� Ŀ��, �ػ깰�� �����ϴ�.��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case BEIJING_LAND: //����¡ 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �߱��� ����. �� �ձð� �� �߱��� ���縦 ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��� �� �� �ִ� ����¡��                ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �����强���� �ڱݼ�, õ�ȹ��������     ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �߱��� �������� ���� �� �ִ�.           ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif

		break;
	case TAIPEI_LAND: //Ÿ������ 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �븸�� ����. �߱��� �Ϻ��� ��ȭ��       ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���յ� ����.   �ִϸ��̼�               ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� '���� ġ����'�� ����� �������� �ִ�.   ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif

		break;

	case DUBAI_LAND: //�ι���
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �縷 ���� �̱����� ����.�ƶ����̸�Ʈ    ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ 7���� �� �ϳ��̴�. ���󿡼� ���� ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��  ���� ������ �θ��� Į���İ� �ִ�.      ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif

		break;
	case KAIRO_LAND: //ī�̷� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ����Ʈ�� ����. ������ ��ȭ ������       ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ����. ���� ��ü�� UNESCO         ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �������꿡 1979�� ���� �Ǿ���.          ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif

		break;
	case TOKYO_LAND: //���� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �Ϻ��� ����. �Ϻ��� ���ź��� �������   ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��� �� �� �ִ�, �Ϻ��� �����س��� ���� ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif

		break;
	case SIDNEY_LAND: //�õ�� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ȣ���� ����. ����� �Ͽ콺�� ��ǥ�Ǵ�   ��,");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��������, �縷�� �ٴٸ� ��� ������ ��  ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��  �־� ������ ��Ʈ�������� ��ġ�ϰ� �ִ�.��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case QUEBEC_LAND: //���� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���׽��� ���蹮ȭ�������� ������ ������ ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� �Ϲ� ������ ���������̴�. ���� ��Ʈ����");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� �뼺��� ������ ���๰���� ���� �ִ�.��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case HAWAII_LAND: //�Ͽ��� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �̱� 50 �� �� �� ���� ���ܿ� ��ġ�ϸ�,  ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �۰Դ� 8��, ũ�Դ� 6���� ������ �����Ǿ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ִ� �Ͽ��̴� �� ������ �Ƹ��ٿ�        ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ڿ�ȯ���� �ڶ��Ѵ�.                    ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case SANGPAWOOLO_LAND: //���Ŀ�� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���쵥�ڳ��̷� ������-������뿡        ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��ġ�� �ִ� ���Ƹ޸�ī �ִ��� ����.     ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������� ����, ��ȭ �߽����μ�          ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �Ƹ��ٿ� ���� ��ҵ��� ��ġ�� �ִ�.     ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case PRAHA_LAND: //������
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �߽ɰ��� ���׽��� ��ȭ������ �����ϴ�,  �� ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���� �߾��� ���������� ��Ÿ�� ���� �߰� ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� �����ϰ�, ���迡�� ���� ū ����      ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ���� ��ġ�� �ִ�.                ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case BERLIN_LAND: //������ 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���� ����� ��ȭ�� �߽��� ��������,     ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ���� ��ȭ���� ���ϸ�� ���ɽ�Ʈ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� ������ �����̴�.                     ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case MOSCOW_LAND: //��ũ�� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���� ���þ� �ߺ�, ��ũ�ٰ� ������     �� ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ڸ����� ���� ��ũ�ٴ� �ܿ�� ��︮�¦�");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �����̴�. ���þ� ����ȸ ������ �Ƹ��ٿ� ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��买��� �����ϴ�.                    ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case GENEVA_LAND: //���׹�
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �������̸鼭 ���� ��������� ��ġ�� ���æ�");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ó��� ��ġ�� ���ð������� �߼��� �����⦢");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �� ���� �� �ִ�.                        ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case ROME_LAND: //�θ� 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� 2500������ ���縦 �ڶ��ϴ� ��Ż������ ����");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��.�ݷμ���, ��Ƽĭ �ñ�, ��κ��� ���� ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ��ҵ��� ������ �������� ���� �ֿ�ȴ�. ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case PYEONGYANG_LAND: //���
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ �������� ������ ������ �����    ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ��ġ������������,��ȭ �߽����̴�.��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case LONDON_LAND: //����
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ��ġ����������ȭ �׸��� ������ �ߦ�");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �߽����� ������, ���������� �߽ɵ��ô�. ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� 2�� ������ ���մ����� ��ǥ�ǰ� �Ѵ�.    ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case PARIS_LAND: //�ĸ�
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ��ȭ �߽�����, ������ ���á���� ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �Ҹ��� �ĸ���, ����ž, ������, ��Ʈ���� ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �뼺��� ���� ��买�� ������ǰ�� �ִ�. ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case NEWYORK_LAND: //����
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �̱� �ִ��� ������ ������, �̱��� ���, ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ �߽�������, ��ȭ�� �߽����̴�.   ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������ ���Ż�, �����̾� ������Ʈ ������ ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �������� ���帶ũ���� �����Ѵ�.         ��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	case SEOUL_LAND: //����
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ѹݵ� �߾ӿ� ��ġ�� ���ѹα��� ������  ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ������, ������ ��ȭ�� �߽��� ��Ȱ��     ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� �ϰ��ִ�. ���ʹ�, ��������, â���õ�,   ��");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"�� ���� �ô��� ��ȭ ������� �����ǰ� �ִ�.��");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
		break;
	}

}

void CLand::Arrive_Land(CGame &Game)
{
	char cPlayer_Choice;
	int iNext_Line = 0;
	while (true)
	{
		if ( !(lstrcmp(cLand_Owner, "")) ) //�����ߴµ� �� ���̸�
		{
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ���Դϴ�. ���� �μ��� �� �־��!      ��");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �μ��Ͻðڽ��ϱ�? (y �Ǵ� n �Է� )      ��");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
				if (_kbhit())
				{
					int iKey = _getch();
					if (iKey == 'y' || iKey == 'Y') // �� ���� ���� ��
					{
						Buy_Land(Game);
						return;
					}
					else if (iKey == 'n' || iKey == 'N')
					{
						g_DBBF.ClearBuffer();
						Game.Print_All_Tile();
						Game.Print_All_Land();
						Game.Print_All_ExtraLand();
						Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
						Game.Print_All_Character();
						Game.m_Dice.Print_Diceinfo();
						Game.Print_Player_Infor();
						Game.Print_Player_Turn();
						g_DBBF.FlippingBuffer();
						return;
					}
						
				}
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();

				g_DBBF.FlippingBuffer();
			}
		}

		// ���� ���� �������� ��
		else if ( (lstrcmp(cLand_Owner, "")) && (lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape) ) )
		{
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ����� ���� �ƴմϴ�... ��������        ��");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ���ؼ� ����Ḧ �����ؾ� �մϴ�.        ��");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif


				// if(����� �����ϰ�, �μ� ������ ����ϴٸ� ����� �Ѵ�.
				{
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ����Ḧ ���� �߽��ϴ�! (�Ʊ�� ����)   ��");
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ������ Ȯ �����???(���� �μ��ұ��?)   ��");
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� (y �Ǵ� n���� ����)                     ��");
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
					if (_kbhit())
					{
						int iKey = _getch();
						if (iKey == 'y' || iKey == 'Y')
						{
							// ���� ���� ���� �μ��Ѵ�.
							Buy_Land(Game);
							return;
						}
						else if (iKey == 'n' || iKey == 'N')
						{
							// �ٽ� �׸��� ����������.
							g_DBBF.ClearBuffer();
							Game.Print_All_Tile();
							Game.Print_All_Land();
							Game.Print_All_ExtraLand();
							Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
							Game.Print_All_Character();
							Game.m_Dice.Print_Diceinfo();
							Game.Print_Player_Infor();
							g_DBBF.FlippingBuffer();
							return;
						}
					}
				}
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
		}
		else if ( !lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape) )
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������������");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �� ������ ���̴�.                        ��");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ����Ḧ �÷��ް� ������...(�ǹ��� ���׷���");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �̵� �մϴ�)(y �Ǵ� n���� ����)          ��");
			Game.MoveXY(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++);
			cin >> cPlayer_Choice;

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"����������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������������");
#endif
			if (cPlayer_Choice == 'y')
			{
				Build_Building(Game);
				Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);//���������� �Ѿ��.
				cPlayer_Choice = NULL;
			}
			else
			{
				Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);//���������� �Ѿ��.
				cPlayer_Choice = NULL;
			}
		}
	}
}
void CLand::Buy_Land(CGame &Game)
{
	int iNext_Line = 0;
	Game.m_Lands[Game.eCurPlayer].iTotal_LandPrice =
		Game.m_Lands[Game.eCurPlayer].iLand_Price + (Game.m_Lands[Game.eCurPlayer].iLand_Building *Game.m_Lands[Game.eCurPlayer].iLand_Build_Price);
	
	BOOL bBuy = FALSE;
	for (int i = 0; i < 2; i++)
	{
		g_DBBF.ClearBuffer();
		g_DBBF.TextColor(WHITE, BLACK);
		if (Game.m_Player[Game.eCurPlayer].iPlayer_Money > Game.m_Lands[Game.eCurPlayer].iTotal_LandPrice)
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �μ� ����Ƥ���!!!(���� �μ��մϴ�)     ��");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �ŸŷḦ ���� �߽��ϴ�! (�Ʊ�� ����)   ��");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
			bBuy = TRUE;
		}
		else
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �����鼭 ���� ����� �ϴٴ�....Ǳ       ��");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �� �� ���� ã�ƿ�����???                ��");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������");
#endif
		}

		if (bBuy == TRUE)
		{
			lstrcpy(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape);
			// �� ����
		}

		Game.Print_All_Tile();
		Game.Print_All_Land();
		Game.Print_All_ExtraLand();
		Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
		Game.Print_All_Character();
		Game.m_Dice.Print_Diceinfo();
		Game.Print_Player_Infor();
		g_DBBF.FlippingBuffer();

		Sleep(500);
	}
}

void CLand::Build_Building(CGame &Game)
{
	char cPlayer_Choice;
	int iNext_Line = 0;
#if OS_VER == 7
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �ǹ��� �����ϴ�.(�ִ� 3������ ����)     ��");
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ���帶ũ�� �����!(y �Ǵ� n)            ��");
	Game.MoveXY(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++);
	cin >> cPlayer_Choice;
#if OS_VER == 7
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������");
#endif
	if (cPlayer_Choice == 'y')
	{
		if (Game.m_Lands[Game.eCurPlayer].iLand_Building < MAX_BUILD)
		{
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �ǹ��� �� �����ϴ�!!!�ۢ�               ��");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������");
#endif
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= Game.m_Lands[Game.eCurPlayer].iLand_Build_Price;
			Game.m_Lands[Game.eCurPlayer].iLand_Building++;
		}
		else if (Game.m_Lands[Game.eCurPlayer].iLand_Building > MAX_BUILD)
		{
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �ǹ��� �� ���� �� �����ϴ�!!!           ��");
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������");
#endif
		}
		else if (Game.m_Player[Game.eCurPlayer].iPlayer_Money<Game.m_Lands[Game.eCurPlayer].iLand_Build_Price)
		{
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������������������������������������������������");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� ����� ��������.. ���� ���ڶ�           ��");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �ñ���?���������� �� ���� ������        ��");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"�� �ǹ��� ���� �� ���׿�~                  ��");
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"��������������������������������������������");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"������������������������������������������������������������������������������������");
#endif
		}

	}
	else
		return;
}