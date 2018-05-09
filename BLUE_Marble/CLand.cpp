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
}
COORD CLand::Get_LandPosition()
{
	return pos;
}
//void CLand::Buy_Land(CPlayer &Player)
//{
//	iTotal_LandPrice = iLand_Price + (iLand_Building*iLand_Build_Price); //階曖 識 陛問擎 = 階 陛問 + 勒僭熱*勒僭陛問
//	if (Player.iPlayer_Money >= iTotal_LandPrice)
//	{
//		Player.iPlayer_Money -= iTotal_LandPrice;
//		lstrcpy((TCHAR *)cLand_Owner, (TCHAR *)Player.cPlayer_Name); //模嶸輿陛 夥莎棻.
//														 //棻擠欐戲煎 剩橫除棻.
//	}
//	else if (Player.iPlayer_Money < iTotal_LandPrice)
//	{
//		cout << "絲檜 睡褶м棲棻." << endl;
//		//棻擠欐戲煎 剩橫除棻
//	}
//}
//void CLand::Build_Building(CPlayer &Player)
//{
//	char cPlayer_Choice;
//	if (iLand_Building == EMPTY_BUILD)
//	{
//		cout << "勒僭檜 橈蝗棲棻." << endl;
//		cout << "勒僭擊 雖戲衛啊蝗棲梱? (y 傳朝 n)" << endl;
//		cin >> cPlayer_Choice;
//	}
//	if ((TCHAR *)cPlayer_Choice == "y") //勒僭 勒撲 摹鷗 衛
//	{
//		if (iLand_Building < MAX_BUILD && Player.iPlayer_Money > iLand_Build_Price)
//		{
//			iLand_Building++;
//		}
//	}
//	else if ((TCHAR *)cPlayer_Choice == "n")
//	{
//		//棻擠欐戲煎 剩橫除棻.
//	}
//}
//void CLand::Sell_Land(CPlayer &Player)
//{
//	while (Player.iPlayer_Money < iLand_Pass_Money) //絲檜 鱔ч猿爾棻 醴韓 陽梱雖 奩犒
//	{
//		cout << "爾嶸и 階 跡煙" << endl;
//		//階跡煙擊 爾罹輿堅
//		//つ 階擊 摹鷗
//
//
//		//if僥  棻つ嬴紫 鱔ч猿爾棻 睡褶ж賊
//		//だ骯
//	}
//}
//void CLand::Arrive_Land(CPlayer &Player)
//{
//	char cPlayer_Choice;
//	if (cLand_Owner == NULL) //紫雜ц朝等 綴 階檜賊
//	{
//		cout << "綴 階殮棲棻." << endl;
//		cout << "階擊 掘殮ж衛啊蝗棲梱?" << endl;
//		cin >> cPlayer_Choice;
//		if ((TCHAR *)cPlayer_Choice == "y") // 階 掘殮 摹鷗 衛
//		{
//			Buy_Land(Player);
//		}
//		else if ((TCHAR *)cPlayer_Choice == "n")
//		{
//			//棻擠欐戲煎 剩橫除棻.
//		}
//	}
//	//else if (cLand_Owner == "")//紫雜ц朝等 頂階檜賊
//	//{
//	//	//勒僭擊 騁剪釭,棻擠 欐戲煎 剩橫除棻
//	//}
//	//else if (cLand_Owner == "")//紫雜ц朝等 陴曖 階檜賊
//	//{
//
//	//	if (Player.iPlayer_Money >= iLand_Pass_Money) //鱔ч猿蒂 雖碳и棻.
//	//	{
//	//		Player.iPlayer_Money -= iLand_Pass_Money;
//	//		cout << "階擊 掘殮ж衛啊蝗棲梱?" << endl; //雖碳 �� 階 掘殮 摹鷗
//	//		cin >> cPlayer_Choice;
//	//		if ((TCHAR *)cPlayer_Choice == "y") // 階 掘殮 摹鷗 衛
//	//		{
//	//			Buy_Land(Player);
//	//		}
//	//		else if ((TCHAR *)cPlayer_Choice == "n")
//	//		{
//	//			//棻擠欐戲煎 剩橫除棻.
//	//		}
//	//	}
//	else if (Player.iPlayer_Money < iLand_Pass_Money) //鱔ч猿陛 睡褶ж賊
//	{
//		Sell_Land(Player);//階擊 っ棻.
//	}
//}

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
		if ( !(lstrcmp(cLand_Owner, "")) ) //紫雜ц朝等 綴 階檜賊
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

		// 鼻渠寞 階縑 紫雜ц擊 陽
		else if ( (lstrcmp(cLand_Owner, "")) && (lstrcmp(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape) ) )
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
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 渡褐曖 階檜 嬴椎棲棻... 雖釭陛晦        弛");
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 嬪п憮 鱔ч猿蒂 雖碳п撿 м棲棻.        弛");

#if OS_VER == 7
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
				g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif


				// if(鱔ч猿 雖碳ж堅, 檣熱 綠辨梱雖 醱碟ж棻賊 僭橫撿 и棻.
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
							// 絲擊 頂堅 階擊 檣熱и棻.
							Buy_Land(Game);
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
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 頂 貲曖曖 階檜棻.                        弛");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 鱔ч猿蒂 螢溥嫡堅 談擎等...(勒僭擊 機斜溯弛");
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 檜萄 м棲棻)(y 傳朝 n戲煎 摹鷗)          弛");
			Game.MoveXY(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++);
			cin >> cPlayer_Choice;

#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
			if (cPlayer_Choice == 'y')
			{
				Build_Building(Game);
				Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);//棻擠欐戲煎 剩橫除棻.
				cPlayer_Choice = NULL;
			}
			else
			{
				Game.eCurPlayer = (eCURPLAYER)(Game.eCurPlayer + 1);//棻擠欐戲煎 剩橫除棻.
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

		if (bBuy == TRUE)
		{
			lstrcpy(cLand_Owner, Game.m_Player[Game.eCurPlayer].cPlayer_Shape);
			// 絲 馬模
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
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 勒僭擊 騁蝗棲棻.(譆渠 3偃梱雖 陛棟)     弛");
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 楠萄葆觼朝 橈橫蹂!(y 傳朝 n)            弛");
	Game.MoveXY(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++);
	cin >> cPlayer_Choice;
#if OS_VER == 7
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	if (cPlayer_Choice == 'y')
	{
		if (Game.m_Lands[Game.eCurPlayer].iLand_Building < MAX_BUILD)
		{
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
			Game.m_Player[Game.eCurPlayer].iPlayer_Money -= Game.m_Lands[Game.eCurPlayer].iLand_Build_Price;
			Game.m_Lands[Game.eCurPlayer].iLand_Building++;
		}
		else if (Game.m_Lands[Game.eCurPlayer].iLand_Building > MAX_BUILD)
		{
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"弛 勒僭擊 渦 雖擊 熱 橈蝗棲棻!!!           弛");
#if OS_VER == 7
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
			g_DBBF.WriteBuffer(LAND_SIGN_XPOS, LAND_SIGN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		}
		else if (Game.m_Player[Game.eCurPlayer].iPlayer_Money<Game.m_Lands[Game.eCurPlayer].iLand_Build_Price)
		{
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
		}

	}
	else
		return;
}