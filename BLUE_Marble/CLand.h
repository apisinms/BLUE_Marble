#ifndef __CLAND__
#define __CLAND__
#pragma warning(disable : 4996)
#define EMPTY_BUILD  0 // 건물개수
#define MAX_BUILD 3 // 최대 건물 수
//#include"CPlayer.h"
//#include "CDoubleBuffering.h"
class CPlayer;
class CLand
{
private:
	int iLand_Building; //건물
	TCHAR *cLand_Owner = nullptr; // 땅 소유주
	TCHAR *cLand_Name = nullptr;	// 땅의 이름
	int iLand_Pass_Money; // 통행료
	int iLand_Build_Price; // 건물가격
	int iLand_Price; // 땅 가격
	int iTotal_LandPrice;// 땅의 총 가격(땅매매시사용)
	COORD pos;
public:

	CLand();
	~CLand();
	
	void Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Pass_Money, int iLand_Build_Price,
		int iLand_Price, int iTotal_LandPrice, int x, int y);

	void Buy_Land(CPlayer &Player); // 땅 구입
	void Build_Building(CPlayer &Player);	// 건물 건설
	void Arrive_Land(CPlayer &Player); // 땅에 도착 시.
	void Sell_Land(CPlayer &Player);	// 땅 팔기
	void Print_LandInfo();	// 땅 정보 출력
	COORD Get_LandPosition();	// 땅 위치 리턴해주는 메서드
};
#endif