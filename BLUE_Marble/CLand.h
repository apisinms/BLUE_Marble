#ifndef __CLAND__
#define __CLAND__
#pragma warning(disable : 4996)
#define EMPTY_BUILD  0 // 건물개수
#define MAX_BUILD 3 // 최대 건물 수
#define LAND_INFOR_XPOS 25  //지역 정보 출력 x좌표
#define LAND_INFOR_YPOS 6 // 지역 정보 출력 y좌표
#define LAND_SIGN_XPOS 50 //지역 정보(돈, 소유주)
#define LAND_SIGN_YPOS 20 // 지역 정보 (돈 , 소유주)
class CGame;
class CDice;
class CLand
{
	friend CDice;
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
	
	void Set_LandInfo(int iLand_Building, TCHAR *cLand_Owner, TCHAR *cLand_Name, int iLand_Build_Price,
		int iLand_Price, int x, int y);

	void Buy_Land(CGame &Game); // 땅 구입
	void Build_Building(CGame &Game);	// 건물 건설
	void Arrive_Land(CGame &Game); // 땅에 도착 시.
	void Sell_Land(CGame &Game);	// 땅 팔기
	void Print_LandInfo();	// 땅 정보 출력
	COORD Get_LandPosition();	// 땅 위치 리턴해주는 메서드void CLand::Print_Information(ALL_LANDS iLand_ID)
	static void Print_Information(ALL_LANDS iLand_ID);
};
#endif