#ifndef __CLAND__
#define __CLAND__
#pragma warning(disable : 4996)
#define EMPTY_BUILD  0 // �ǹ�����
#define MAX_BUILD 3 // �ִ� �ǹ� ��
//#include"CPlayer.h"
//#include "CDoubleBuffering.h"
class CPlayer;
class CLand
{
private:
	int iLand_Building; //�ǹ�
	TCHAR *cLand_Owner = nullptr; // �� ������
	TCHAR *cLand_Name = nullptr;	// ���� �̸�
	int iLand_Pass_Money; // �����
	int iLand_Build_Price; // �ǹ�����
	int iLand_Price; // �� ����
	int iTotal_LandPrice;// ���� �� ����(���ŸŽû��)
	COORD pos;
public:

	CLand();
	~CLand();
	
	void Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Pass_Money, int iLand_Build_Price,
		int iLand_Price, int iTotal_LandPrice, int x, int y);

	void Buy_Land(CPlayer &Player); // �� ����
	void Build_Building(CPlayer &Player);	// �ǹ� �Ǽ�
	void Arrive_Land(CPlayer &Player); // ���� ���� ��.
	void Sell_Land(CPlayer &Player);	// �� �ȱ�
	void Print_LandInfo();	// �� ���� ���
	COORD Get_LandPosition();	// �� ��ġ �������ִ� �޼���
};
#endif