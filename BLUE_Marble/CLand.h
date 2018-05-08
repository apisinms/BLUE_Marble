#ifndef __CLAND__
#define __CLAND__
#pragma warning(disable : 4996)
#define EMPTY_BUILD  0 // �ǹ�����
#define MAX_BUILD 3 // �ִ� �ǹ� ��
#define LAND_INFOR_XPOS 25  //���� ���� ��� x��ǥ
#define LAND_INFOR_YPOS 6 // ���� ���� ��� y��ǥ
#define LAND_SIGN_XPOS 50 //���� ����(��, ������)
#define LAND_SIGN_YPOS 20 // ���� ���� (�� , ������)
class CGame;
class CDice;
class CLand
{
	friend CDice;
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
	
	void Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Build_Price,
		int iLand_Price, int x, int y);

	void Buy_Land(CGame &Game); // �� ����
	void Build_Building(CGame &Game);	// �ǹ� �Ǽ�
	void Arrive_Land(CGame &Game); // ���� ���� ��.
	void Sell_Land(CGame &Game);	// �� �ȱ�
	void Print_LandInfo();	// �� ���� ���
	COORD Get_LandPosition();	// �� ��ġ �������ִ� �޼���void CLand::Print_Information(ALL_LANDS iLand_ID)
	static void Print_Information(ALL_LANDS iLand_ID);
};
#endif