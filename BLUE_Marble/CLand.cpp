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

	if (cBuilding_Grade != NULL)
	{
		delete[]cBuilding_Grade;
		cBuilding_Grade = nullptr;
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

	this->cBuilding_Grade = new TCHAR[5];
	lstrcpy(this->cBuilding_Grade, "");

	this->iLand_Build_Price = iLand_Build_Price;
	this->iLand_Price = iLand_Price;
	this->iLand_Pass_Money = 0;
	this->iTotal_LandPrice = 0;

	pos.X = x;
	pos.Y = y;
}
void CLand::Print_LandInfo()
{
	if(lstrcmp((TCHAR*)"Ⅳ", cLand_Owner) == 0)
		g_DBBF.TextColor(P1_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"﹣", cLand_Owner) == 0)
		g_DBBF.TextColor(P2_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"Ⅵ", cLand_Owner) == 0)
		g_DBBF.TextColor(P3_COLOR, BLACK);

	else if (lstrcmp((TCHAR*)"Ⅷ", cLand_Owner) == 0)
		g_DBBF.TextColor(P4_COLOR, BLACK);

	else
		g_DBBF.TextColor(WHITE, BLACK);

	g_DBBF.WriteBuffer(pos.X, pos.Y, cLand_Name);
	g_DBBF.WriteBuffer(pos.X + 10, pos.Y, cBuilding_Grade);
}
COORD CLand::Get_LandPosition()
{
	return pos;
}

void CLand::Print_Information(ALL_LANDS iLand_ID)
{
	int iNext_Line = 0;
	g_DBBF.TextColor(WHITE, BLACK);

	switch (iLand_ID)
	{
	case ISLAND_LAND: //鼠檣紫
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 鼠檣紫縑 陘�鷐抻懂炴�.                   弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 曆瞪�� 掘褻衛除擊 晦棻葬撮蹂.            弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嬴棲賊 遴檜 橘熱煎 謠湍陛^^              弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 (輿餌嬪 渦綰 衛 驍轎м棲棻.)             弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 (�分� 3欐擊 渠晦м棲棻.    )             弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case WORLDTRIP_LAND: //撮啗罹ч
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 ≠闌剪遴 撮啗 罹ч殮棲棻.≠              弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 ら寰и 罹ч 腎撮蹂~                      弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 (錳ж朝 顫橾擊 摹鷗ж撮蹂.)              弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 (棻擠 欐縑 檜翕м棲棻.)                  弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case START_LAND: //轎嫦薄
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 轎嫦雖 殮棲棻.                           弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 и 夥襪蒂 給 陽葆棻 錯晝擊 嫡蝗棲棻.ㄓ++ 弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case GOLDKEY_LAND: //�盛暆乘�
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 舒斬舒斬, �盛� 翮潸縑 紫雜ц蝗棲棻.     弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 渡褐曖 遴擊 衛яж撮蹂~                 弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case BANGKOK_LAND: //寞囂 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 鷓措曖 熱紫. 衙喇 1,600虜 貲檜          弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 瓊朝 婦惜紫衛 寞囂.                     弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 望剪葬 擠衝曖 繭措檜晦紫 и 寞囂擎      弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 鷓措衝 賊蹂葬諦 醴葬, п骯僭檜 嶸貲ж棻.弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case BEIJING_LAND: //漆檜癒 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 醞措曖 熱紫. 蕪 諾掙婁 ⑷ 醞措曖 羲餌蒂 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 賅舒 獐 熱 氈朝 漆檜癒擎                弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 虜葬濰撩睡攪 濠旎撩, 繭寰僥惜濰梱雖     弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 醞措曖 錠濰л擊 替野 熱 氈棻.           弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

		break;
	case TAIPEI_LAND: //顫檜む檜 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 渠虜曖 熱紫. 醞措婁 橾獄曖 僥�降�       弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 懦м脹 紫衛.   擁棲詭檜暮               弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 '撫婁 纂�鷛�'曖 寡唳檣 雖辦べ檜 氈棻.   弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

		break;

	case DUBAI_LAND: //舒夥檜
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 餌虞 嬪曖 檜措瞳檣 紫衛.嬴奧縑嘐葬お    弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 翱寞曖 7偃措 醞 ж釭檜棻. 撮鼻縑憮 陛濰 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛  堪擎 網註檣 睡腦鍔 蠔葬だ陛 氈棻.      弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

		break;
	case KAIRO_LAND: //蘋檜煎 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 檜餵お曖 熱紫. 熱號擎 僥�� 嶸骯擊       弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 爾嶸и 紫衛. 紫衛 濠羹陛 UNESCO         弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 撮啗嶸骯縑 1979喇 蛔營 腎歷棻.          弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

		break;
	case TOKYO_LAND: //紫瓖 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 橾獄曖 熱紫. 橾獄曖 婁剪睡攪 ⑷營梱雖   弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 賅舒 獐 熱 氈朝, 橾獄擊 憶蹴п場擎 紫衛 弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

		break;
	case SIDNEY_LAND: //衛萄棲 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 ��輿曖 熱紫. 螃む塭 ж辦蝶煎 渠ル腎朝   弛,");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 紫衛檜濠, 餌虞婁 夥棻蒂 賅舒 馬鼻й 熱  弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛  氈橫 嶸貲и んお蝶纔っ檜 嬪纂ж堅 氈棻.弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case QUEBEC_LAND: //蠡漱 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嶸啻蝶囀 撮啗僥�倣粉篔虞� 雖薑脹 蠡漱衛 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 朝 磁嘐 嶸橾曖 撩婉紫衛檜棻. 蠡寥 喻お腦弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 氬 渠撩渡蛔 羲餌瞳 勒蹴僭菟檜 號檜 氈棻.弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case HAWAII_LAND: //ж諦檜 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嘐措 50 偃 輿 醞 陛濰 陴欽縑 嬪纂ж貊,  弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 濛啪朝 8偃, 觼啪朝 6偃曖 撰戲煎 掘撩腎橫弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 氈朝 ж諦檜朝 陝 撰葆棻 嬴葷棻遴        弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 濠翱�秣磍� 濠嫌и棻.                    弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case SANGPAWOOLO_LAND: //鼻だ選煎 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 葬辦等濠啻檜瑞 陴憮薹-堅錳雖渠縑        弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嬪纂п 氈朝 陴嬴詭葬蘋 譆渠曖 紫衛.     弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 粽塭韓曖 唳薯, 僥�� 醞褕雖煎憮          弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嬴葷棻遴 婦惜 貲模菟檜 嬪纂п 氈棻.     弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case PRAHA_LAND: //Щ塭ж
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 醞褕陛陛 嶸啻蝶囀 僥�倣粉篔� Щ塭ж朝,  弛 ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 紫衛 醞懈擊 陛煎雖腦朝 獐顫夥 鬼曖 撿唳 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 檜 嶸貲ж堅, 撮啗縑憮 陛濰 贖 撩檣      弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 Щ塭ж 撩檜 嬪纂п 氈棻.                弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case BERLIN_LAND: //漆蒂萼 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 絮橾 羲餌諦 僥�倣� 醞褕雖 漆蒂萼擎,     弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 漆蒂萼 措薯 艙�俯江� вж賅棣 螃馨蝶お塭弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 煎 嶸貲и 紫衛檜棻.                     弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case MOSCOW_LAND: //賅蝶觼夥 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嶸毀 楝衛嬴 醞睡, 賅蝶觼夥鬼 嶸羲縑     弛 ");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 濠葬濩擎 紫衛 賅蝶觼夥朝 啖選婁 橫選葬朝弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 紫衛檜棻. 楝衛嬴 薑掖�� 蕨獎曖 嬴葷棻遴 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 晦喃僭菟煎 嶸貲ж棻.                    弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case GENEVA_LAND: //薯啻夥
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 婦惜雖檜賊憮 陝謙 措薯晦婦檜 嬪纂и 紫衛弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 衛頂縑 嬪纂и 掘衛陛雖縑憮 醞撮曖 碟嬪晦弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 蒂 替野 熱 氈棻.                        弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case ROME_LAND: //煎葆 
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 2500罹喇曖 羲餌蒂 濠嫌ж朝 檜驍葬嬴曖 熱弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 紫.屬煎撮遺, 夥じ蘊 衛措, 渠睡碟曖 婦惜 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 貲模菟檜 塵餵п 罹ч雖煎 號檜 擁辨脹棻. 弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case PYEONGYANG_LAND: //ゎ曄
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 磁и曖 熱紫檜濠 薯橾曖 紫衛檣 ゎ曄擎    弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 磁и曖 薑纂﹞ч薑﹞唳薯,僥�� 醞褕雖檜棻.弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case LONDON_LAND: //楛湍
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 艙措曖 薑纂﹞唳薯﹞僥�� 斜葬堅 掖鱔曖 醞弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 醞褕雖檣 楛湍擎, 艙措翱寞曖 醞褕紫衛棻. 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 2類 幗蝶諦 罹諾椒戲煎 渠ル腎堆 и棻.    弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case PARIS_LAND: //だ葬
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 撮啗曖 僥�� 醞褕雖煎, ＆粒曖 紫衛＊塭堅 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 碳葬朝 だ葬朝, 縑ゃ鱉, 偃摹僥, 喻お腦氬 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 渠撩渡蛔 號擎 晦喃僭婁 蕨獎濛ヶ檜 氈棻. 弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case NEWYORK_LAND: //景踹
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 嘐措 譆渠曖 紫衛檣 景踹擎, 嘐措曖 鼻機, 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 旎懦曖 醞褕雖檜濠, 僥�倣� 醞褕雖檜棻.   弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 濠嶸曖 罹褐鼻, 縞だ檜橫 蝶纔檜お 網註蛔 弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 ⑷渠瞳檣 楠萄葆觼菟檜 襄營и棻.         弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		break;
	case SEOUL_LAND: //憮選
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 и奩紫 醞懈縑 嬪纂и 渠и團措曖 熱紫檣  弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 憮選擎, 掖幫婁 僥�倣� 醞褕雖 羲�偯�     弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 ж堅氈棻. 璃滔僥, �奰恔鶾�, 璽湯掙蛔,   弛");
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 褻摹 衛渠曖 僥�� 嶸骯菟檜 爾襄腎堅 氈棻.弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_INFOR_XPOS, LAND_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
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
		if (!(lstrcmp(cLand_Owner, ""))) //紫雜ц朝等 綴 階檜賊
		{
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 綴階殮棲棻. 階擊 檣熱й 熱 氈橫蹂!      弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 檣熱ж衛啊蝗棲梱? (y 傳朝 n 殮溘 )      弛");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
				if (_kbhit())
				{
					int iKey = _getch();
					if (iKey == 'y' || iKey == 'Y') // 階 掘殮 摹鷗 衛
					{
						Buy_Land(Game, TRUE);
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

		// 鼻渠寞 階縑 紫雜ц擊 陽
		else if ((lstrcmp(cLand_Owner, "")) && (lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape)))
		{
			if (lstrcmp((TCHAR*)"Ⅳ", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[0].iPlayer_Money += iLand_Pass_Money;
			}

			else if (lstrcmp((TCHAR*)"﹣", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[1].iPlayer_Money += iLand_Pass_Money;
			}

			else if (lstrcmp((TCHAR*)"Ⅵ", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[2].iPlayer_Money += iLand_Pass_Money;
			}

			else if (lstrcmp((TCHAR*)"Ⅷ", cLand_Owner) == 0)
			{
				Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iLand_Pass_Money;
				Game.m_Player[3].iPlayer_Money += iLand_Pass_Money;
			}
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 渡褐曖 階檜 嬴椎棲棻... 雖釭陛晦        弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 嬪п憮 鱔ч猿蒂 雖碳п撿 м棲棻.        弛");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

				if (Game.m_Player[Game.eCurPlayer].iPlayer_Money > 0)
				{
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 鱔ч猿蒂 雖碳 ц蝗棲棻! (嬴梱遴 頂絲)   弛");
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 檜霤縑 �� 餌幗溥???(階擊 檣熱й梱蹂?)   弛");
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 (y 傳朝 n戲煎 摹鷗)                     弛");
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
					if (_kbhit())
					{
						int iKey = _getch();
						if (iKey == 'y' || iKey == 'Y')
						{
							// 絲擊 頂堅 階擊 檣熱и棻. 階 陛問 2寡
							if (lstrcmp((TCHAR*)"Ⅳ", cLand_Owner) == 0)
								Game.m_Player[0].iPlayer_Money += (iTotal_LandPrice * 2);

							else if (lstrcmp((TCHAR*)"﹣", cLand_Owner) == 0)
								Game.m_Player[1].iPlayer_Money += (iTotal_LandPrice * 2);

							else if (lstrcmp((TCHAR*)"Ⅵ", cLand_Owner) == 0)
								Game.m_Player[2].iPlayer_Money += (iTotal_LandPrice * 2);

							else if (lstrcmp((TCHAR*)"Ⅷ", cLand_Owner) == 0)
								Game.m_Player[3].iPlayer_Money += (iTotal_LandPrice * 2);
							Buy_Land(Game, FALSE);	// 陴曖 模嶸 階擊 骯棻

							return;
						}
						else if (iKey == 'n' || iKey == 'N')
						{
							// 棻衛 斜葬堅 緒螳釭除棻.
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

				// 旎擋 0爾棻 瞳橫雖賊
				else if (Game.m_Player[Game.eCurPlayer].iPlayer_Money < 0)
				{
					//旎擋戲煎 ぬ寡
					// л熱 ��轎
					Game.Print_WinPlayer(Game.eCurPlayer, 0);

#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 鱔ч猿蒂 雖碳 ц蝗棲棻! (嬴梱遴 頂絲)   弛");
					g_DBBF.TextColor(RED, BLACK);
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 絲檜 橈橫憮 だ骯ж樟啻蹂...             弛");
					g_DBBF.TextColor(WHITE, BLACK);
#if OS_VER == 7
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
					g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
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

		// 頂 階縑 紫雜 ц擊 陽
		else if (!lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape))
		{
			iNext_Line = 0;
			g_DBBF.TextColor(WHITE, BLACK);
			while (true)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				iNext_Line = 0;
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 頂 貲曖曖 階檜棻.                         弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 鱔ч猿蒂 螢溥嫡堅 談擎等...(勒僭擊 機斜溯 弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 檜萄 м棲棻)(y 傳朝 n戲煎 摹鷗)           弛");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
				if (_kbhit())
				{
					int iKey = _getch();
					if (iKey == 'y' || iKey == 'Y')
					{
						// 勒僭擊 機斜溯檜萄 и棻.
						Build_Building(Game);
						return;
					}
					else if (iKey == 'n' || iKey == 'N')
					{
						// 棻衛 斜葬堅 緒螳釭除棻.
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
	}
}
void CLand::Buy_Land(CGame &Game, BOOL EMPTY)
{
	int iNext_Line = 0;

	BOOL bBuy = FALSE;
	for (int i = 0; i < 2; i++)
	{
		g_DBBF.ClearBuffer();
		g_DBBF.TextColor(WHITE, BLACK);
		// 階曖 識 陛問擊 撲薑   (階高 + (勒僭熱 * 勒僭 騁晦綠辨) )
		iTotal_LandPrice = iLand_Price + (iLand_Building * iLand_Build_Price);

		if (Game.m_Player[Game.eCurPlayer].iPlayer_Money > iTotal_LandPrice)
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 檣熱 陛鍔嬴凶凶!!!(階擊 檣熱м棲棻)     弛");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 衙衙猿蒂 雖碳 ц蝗棲棻! (嬴梱遴 頂絲)   弛");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
			bBuy = TRUE;
		}
		else
		{
			iNext_Line = 0;
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 剪雖賊憮 階擊 餌溥堅 ж棻棲....Д       弛");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 絲 渦 弊賊 瓊嬴螃衛轄???                弛");

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
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


	if (bBuy == TRUE)
	{
		lstrcpy(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape);

		if (EMPTY == TRUE)
		{
			// 勒僭擊 籀擠 騁朝剪賊 勒僭擊 1偃朝 螢溥醜撿 л.
			Build_Building(Game);
		}

		// 階曖 鱔ч猿蒂 撲薑   (階曖 識 陛問曖 瞰奩)
		iLand_Pass_Money = iTotal_LandPrice * 0.5;

		// 絲 馬模
		if (EMPTY == TRUE)
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= iTotal_LandPrice;

		// 陴曖 階 檣熱朝 2寡 馬模
		else if (EMPTY == FALSE)
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= (iTotal_LandPrice * 2);
	}
	// 塭檣絮薄 匐餌
	int Inc = 0;
	for (int i = 0; i < 4; i++, Inc += 5)
	{
		TCHAR LandOwner[5];
		BOOL bLine = TRUE;
		for (int j = 0; j < 5; j++)
		{
			// 塭檣 羅廓簞 階檜賊 斜 階 輿檣擊 橢橫褥
			if (j == 0)
			{
				lstrcpy(LandOwner, Game.m_Lands[j + Inc].cLand_Owner);

				// 斬等 綴 階檜賊 偭 緒螳 釭褥
				if (lstrcmp(LandOwner, "") == 0)
				{
					bLine = FALSE;
					break;
				}
			}

			// 塭檣曖 羅廓簞 階 嬴棲賊
			else
			{
				// 羅 廓簞 階 輿檣檜嫌 綠掖п憮 偽雖 彊戲賊 塭檣絮薄曖 褻勒檜 醱褶腎雖 彊戲棲 緒螳釭褥
				if (lstrcmp(LandOwner, Game.m_Lands[j + Inc].cLand_Owner) != 0)
				{
					bLine = FALSE;
					break;
				}
			}
		}

		// и 階擊 塭檣絮薄 ц戲賊
		if (bLine == TRUE)
		{
			//檜曹 籀葬 л熱
			Game.Print_WinPlayer(Game.eCurPlayer, 1);
			return;
		}

		Sleep(500);
   }
}

void CLand::Build_Building(CGame &Game)
{
	int iNext_Line = 0;


	while (true)
	{
		//絲 睡褶 僥掘
		if (Game.m_Player[Game.eCurPlayer].iPlayer_Money < (iLand_Build_Price * (iLand_Building + 1)))
		{

			for (int i = 0; i < 2; i++, iNext_Line = 0)
			{

				g_DBBF.TextColor(WHITE, BLACK);
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 渡褐擎 剪雖縑蹂.. 絲檜 賅濠塭           弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 衛捱蹂?六六六六六 渦 弊堅 螃撮蹂        弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 勒僭擊 雖擊 熱 橈啻蹂~                  弛");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
			Sleep(300);
			return;
	}

		else if (Game.m_Player[Game.eCurPlayer].iPlayer_Money >(iLand_Build_Price * (iLand_Building + 1)) && (iLand_Building < MAX_BUILD))
		{

			// 勒僭 螢塭陛朝剪朝 1�虜�
			iLand_Building++;
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= (iLand_Build_Price + (iLand_Build_Price * iLand_Building));


			// 網註 熱縑 評塭 轎溘 棻腦啪
			switch (iLand_Building)
			{
			case 1:
				lstrcpy(cBuilding_Grade, (TCHAR*)"函");
				break;
			case 2:
				lstrcpy(cBuilding_Grade, (TCHAR*)"刻");
				break;
			case 3:
				lstrcpy(cBuilding_Grade, (TCHAR*)"券");
				break;
			}
			for (int i = 0; i < 2; i++, iNext_Line = 0)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 勒僭擊 騁蝗棲棻.(譆渠 3偃梱雖 陛棟)     弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 楠萄葆觼朝 橈橫蹂!                      弛");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 勒僭擊 渦 騁蝗棲棻!!!ＭＮ               弛");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
			Sleep(300);
			return;
		}

		else if (iLand_Building >= MAX_BUILD)
		{
			for (int i = 0; i < 2; i++, iNext_Line = 0)
			{
				g_DBBF.TextColor(WHITE, BLACK);
				g_DBBF.ClearBuffer();
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 勒僭擊 渦 雖擊 熱 橈蝗棲棻!!!           弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 譆渠纂檣 3偃蒂 棻 瓣錫蝗棲棻.           弛");
#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
				Game.Print_All_Tile();
				Game.Print_All_Land();
				Game.Print_All_ExtraLand();
				Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
				Game.Print_All_Character();
				Game.m_Dice.Print_Diceinfo();
				Game.Print_Player_Infor();
				g_DBBF.FlippingBuffer();
			}
			Sleep(300);
			return;
		}

}
}

void CLand::Sell_Land(CGame &Game)
{
	ALL_LANDS Select_Land_Idx = WORLDTRIP_LAND;	// 蟾晦 嬪纂朝 渡翱�� 撮啗罹ч
	int Land_Diff = 1;
	int iHaveToGo_Idx = 0;
	COORD cLandPos;
	int iNext_Line = 0;
	while (true)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 つ 階戲煎 檜翕ж罹 Enter酈蒂 援腦撮蹂.  弛");
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 絲檜 橈橫 階擊 つ嬴撿м棲棻.            弛");

#if OS_VER == 7
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		BOOL bKeyDown = FALSE;

		if (KEY_DOWN(VK_RETURN))
		{
			g_DBBF.ClearBuffer();
			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_Dice_Result_Text(); //輿餌嬪 唸婁高 轎溘
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();
			//濠褐曖 階擊 摹鷗п撿 撚楠萄陛 瞳辨渣棻.
			if (strcmp(Game.m_Lands[Select_Land_Idx].cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape) == 0)
				break;
		}


		if (KEY_DOWN(VK_LEFT))
		{
			// 憮選 -> 轎嫦
			if (Select_Land_Idx == SEOUL_LAND)	// 薯橾 贖 ~ 薯橾 濛擎 か熱и 唳辦
				Select_Land_Idx = START_LAND;

			// 撮啗罹ч ~ 鼠檣紫
			else if (Select_Land_Idx > ISLAND_LAND && Select_Land_Idx <= WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// �盛暆乘� ~ 憮選
			else if (Select_Land_Idx < SEOUL_LAND && Select_Land_Idx >= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;

		}

		if (KEY_DOWN(VK_RIGHT))
		{
			// 轎嫦 -> 憮選
			if (Select_Land_Idx == START_LAND)	// 薯橾 濛擎 ~ 薯橾 贖 か熱и 唳辦
				Select_Land_Idx = SEOUL_LAND;

			// 憮選 ~ �盛暆乘�
			else if (Select_Land_Idx <= SEOUL_LAND && Select_Land_Idx > GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 鼠檣紫 ~ 撮啗罹ч
			else if (Select_Land_Idx >= ISLAND_LAND && Select_Land_Idx < WORLDTRIP_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_UP))
		{
			// 轎嫦 ~ 鼠檣紫
			if (Select_Land_Idx >= START_LAND && Select_Land_Idx < ISLAND_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			// �盛暆乘� ~ 撮啗罹ч
			else if (Select_Land_Idx > WORLDTRIP_LAND && Select_Land_Idx <= GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			bKeyDown = TRUE;
		}

		if (KEY_DOWN(VK_DOWN))
		{
			// 鼠檣紫 ~ 轎嫦
			if (Select_Land_Idx <= ISLAND_LAND && Select_Land_Idx > START_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx - 1);

			// 撮啗罹ч ~ �盛暆乘�
			else if (Select_Land_Idx >= WORLDTRIP_LAND && Select_Land_Idx < GOLDKEY_LAND)
				Select_Land_Idx = (ALL_LANDS)(Select_Land_Idx + 1);

			bKeyDown = TRUE;
		}


		if (bKeyDown == TRUE)
		{
			// 檣策蝶煎 ⑷營 階曖 嬪纂蒂 褻餌п憮 ExtraLand諦 Land曖 離檜蒂 貍遽棻.
			if (Select_Land_Idx > START_LAND)
				Land_Diff = 1;

			if (Select_Land_Idx > ISLAND_LAND)
				Land_Diff = 2;

			if (Select_Land_Idx > WORLDTRIP_LAND)
				Land_Diff = 3;

			if (Select_Land_Idx > GOLDKEY_LAND)
				Land_Diff = 4;

			// 嫖擎 階曖 嬪纂薑爾蒂 橢橫螞棻.
			switch (Select_Land_Idx)
			{
			case START_LAND:	// 轎嫦薄
				cLandPos = Game.m_ExtranLands[0].Get_LandPosition();
				break;

			case ISLAND_LAND:	// 鼠檣紫
				cLandPos = Game.m_ExtranLands[1].Get_LandPosition();
				break;

			case WORLDTRIP_LAND:	// 撮啗罹ч
				cLandPos = Game.m_ExtranLands[2].Get_LandPosition();
				break;

			case GOLDKEY_LAND:	// �盛暆乘�
				cLandPos = Game.m_ExtranLands[3].Get_LandPosition();
				break;

			default:
				cLandPos = Game.m_Lands[Select_Land_Idx - Land_Diff].Get_LandPosition();	// ⑷營 Ы溯檜橫陛 嫖堅 氈朝 階曖 謝ル高擊 橢橫螞棻.
				break;
			}

			int AddPos = P1_POS * (Game.eCurPlayer + 1);	// Ы溯檜橫陛 雖薑腎橫撿 ж朝 嬪纂縑 蜃啪 謝ル蒂 熱薑п輿晦 嬪п憮

			cLandPos.X = (cLandPos.X + AddPos) - 2;
			cLandPos.Y += 2;


			Game.m_Player[Game.eCurPlayer].Move_PlayerPos(cLandPos);
			Game.m_Player[Game.eCurPlayer].Set_PlayerStandIndex(Select_Land_Idx);	// 譆謙 Ы溯檜橫陛 除 階曖 嬪纂蒂 盪濰衛霽
			Game.m_Lands[Select_Land_Idx].Print_Information(Select_Land_Idx);
			Game.eLandPrint_Idx = Select_Land_Idx;

			g_DBBF.ClearBuffer();
			Game.Print_All_Tile();
			Game.Print_All_Land();
			Game.Print_All_ExtraLand();
			Game.m_Lands->Print_Information(Game.eLandPrint_Idx);
			Game.Print_Player_Turn();
			Game.Print_Dice_Result_Text(); //輿餌嬪 唸婁高 轎溘
			Game.Print_All_Character();
			Game.m_Dice.Print_Diceinfo();
			Game.Print_Player_Infor();
			g_DBBF.FlippingBuffer();
		}

		Sleep(80);
	}
	Game.m_Player[Game.eCurPlayer].iPlayer_Money += Game.m_Lands[Game.eLandPrint_Idx].iTotal_LandPrice; //階擊っ 絲擊 嫡堅
	lstrcpy(Game.m_Lands[Game.eLandPrint_Idx].cLand_Owner, (TCHAR*)""); // 階曖 輿檣擊 橈擁幗萼棻.

}