//CGame.cpp
#pragma once
#include "stdafx.h"
#include "CGame.h"
#include <conio.h>	//_kbhit擊 餌辨ж晦 嬪п憮
#include <ctime>


CDoubleBuffering g_DBBF;	// 檜薯 霞瞼煎 薑曖蒂 и棻(偌羹陛 й渡脹棻)
FMOD_SYSTEM *g_System;	// FMOD System 薑曖
FMOD_SOUND *g_FX_Sound[MAX_FX];	// �膩�擠擊 瞪羲戲煎
CGame::CGame()
{
	srand((unsigned int)time(NULL));	// 陪熱 褕擠
	g_DBBF.CreatBuffer();	// 渦綰幗ぷ葭擊 嬪и 幗ぷ蒂 儅撩л.

	/// Land曖 薑爾蒂 蟾晦�倆挬�.
	{
		// Left階菟
		m_Lands[0].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"寞    囂", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 6));
		m_Lands[1].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"漆 檜 癒", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[2].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"顫檜む檜", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[3].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"舒 夥 檜", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[4].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"蘋 檜 煎", BUILD_PRICE_LEFT, LAND_PRICE_LEFT, LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 2) - 4);

		// Top 階菟
		m_Lands[5].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"紫    瓖", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 5) - 1, 1);
		m_Lands[6].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"衛 萄 棲", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 9) - 2, 1);
		m_Lands[7].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"蠡    漱", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 13) - 3, 1);
		m_Lands[8].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"ж 諦 檜", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 17) - 4, 1);
		m_Lands[9].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"鼻だ選煎", BUILD_PRICE_TOP, LAND_PRICE_TOP, (LAND_TEXT_VERTICAL * 21) - 5, 1);

		// Right 階菟
		m_Lands[10].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"Щ 塭 ж", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 2) - 4);
		m_Lands[11].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"漆 蒂 萼", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 3) - 3);
		m_Lands[12].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"賅蝶觼夥", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 4) - 2);
		m_Lands[13].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"薯 啻 夥", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 5) - 1);
		m_Lands[14].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"煎    葆", BUILD_PRICE_RIGHT, LAND_PRICE_RIGHT, (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 6));

		// Bottom 階菟
		m_Lands[15].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"ゎ    曄", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 21) - 5, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[16].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"楛    湍", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 17) - 4, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[17].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"だ    葬", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 13) - 3, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[18].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"景    踹", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 9) - 2, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_Lands[19].Set_LandInfo(0, (TCHAR *)"", (TCHAR *)"憮    選", BUILD_PRICE_BOTTOM, LAND_PRICE_BOTTOM, (LAND_TEXT_VERTICAL * 5) - 1, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}

	///ExtranLands縑 渠и 薑爾蒂 蟾晦�� и棻.
	{
		m_ExtranLands[0].Set_LandInfo((TCHAR *)"轎    嫦", LAND_TEXT_VERTICAL, (LAND_TEXT_HORIZONTAL * 7) + 1);
		m_ExtranLands[1].Set_LandInfo((TCHAR *)"鼠 檣 紫", LAND_TEXT_VERTICAL, 1);
		m_ExtranLands[2].Set_LandInfo((TCHAR *)"撮啗罹ч", (LAND_TEXT_VERTICAL * 25) - 6, 1);
		m_ExtranLands[3].Set_LandInfo((TCHAR *)"�盛暆乘�", (LAND_TEXT_VERTICAL * 25) - 6, (LAND_TEXT_HORIZONTAL * 7) + 1);
	}
	

	/// 餌遴萄縑 婦и 薑爾蒂 蟾晦�� и棻.
	{
		// 餌遴萄 衛蝶蠱 蟾晦��
		FMOD_System_Create(&g_System);	// 偌羹 儅撩
		FMOD_System_Init(g_System, 32, FMOD_INIT_NORMAL, NULL);	//蟾晦��

		/// 餌遴萄 撢た BGM
		FMOD_System_CreateSound(g_System, "Sounds\\BGM\\BGM_Intro.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INTRO]);
		FMOD_System_CreateSound(g_System, "Sounds\\BGM\\BGM_InputPlayer.mp3", FMOD_LOOP_NORMAL, 0, &BGM_Music[INPUTPLAYER]);
		
		char location[100];
		for (int i = 0; i < 4; i++)
		{
			wsprintf(location, TEXT("Sounds\\BGM\\BGM_GamePlay%d.mp3"), i + 1);
			FMOD_System_CreateSound(g_System, location, FMOD_DEFAULT, 0, &BGM_Music[BGM1 + i]);
		}


		/// 餌遴萄 撢た �膩�擠
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_MonthPay.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_MONTH_PAY]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_IslandArrive.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_ISLAND_ARRIVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_WorldTripArrive.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WORLDTRIP_ARRIVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_GoldKeyArrive.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_GOLDKEY_ARRIVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_PlayerMove.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_PLAYER_MOVE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_Build.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_BUILD]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_ThrowDice.wav", FMOD_DEFAULT, 0, &g_FX_Sound[FX_THROW_DICE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_Win.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WIN]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_Double.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_DICE_DOUBLE]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_WorldTripWant.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WORLDTRIP_WANT]);
		FMOD_System_CreateSound(g_System, "Sounds\\FX\\FX_WorldTripFly.mp3", FMOD_DEFAULT, 0, &g_FX_Sound[FX_WORLDTRIP_FLY]);

		for (int i = 0; i < 12; i++)
		{
			wsprintf(location, TEXT("Sounds\\FX\\FX_DiceNum_%d.mp3"), i + 1);
			FMOD_System_CreateSound(g_System, location, FMOD_DEFAULT, 0, &g_FX_Sound[FX_DICENUM1 + i]);
		}

	}
}

CGame::~CGame()
{
	g_DBBF.DeleteBuffer();	// 渦綰 幗ぷ葭擊 賅舒 餌辨ц戲棲 濠錳擊 奩陶л.
	
	/// 餌遴萄 п薯
	for (int i = 0; i < MAX_BGM; i++)
		FMOD_Sound_Release(BGM_Music[i]);
	for (int i = 0; i < MAX_FX; i++)
		FMOD_Sound_Release(g_FX_Sound[i]);

	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);

	delete[] m_Player;
}

// 瞪羹瞳檣 啪歜 婦濰
void CGame::PlayGame()
{
	PrintIntro();
	Input_PlayerNum();	// Ы溯檜橫曖 熱蒂 殮溘嫡朝棻.
	Print_Game_Board();	// 啪歜 っ 轎溘
}
// 籀擠 �飛� 轎溘
void CGame::PrintIntro()
{
	FMOD_System_PlaySound(g_System, BGM_Music[INTRO], NULL, FALSE, &BGM_Channel[INTRO]);	// 粽旎 營儅
	FMOD_Channel_SetVolume(BGM_Channel[INTRO], 0.5f);

	int x, y;
	x = 50;
	y = 0;
	int color = BLUE;
	while (true)
	{
		if (_kbhit())
		{
			_getch();	// 幗ぷ縑 陴擎(寞旎 援艇 嬴鼠酈) 酈蒂 薯剪л.
			break;
		}

		// 睡瑞葆綰 轎溘 睡
		g_DBBF.TextColor(color++, BLACK);
		color = (color >= 16) ? BLUE : color;
		g_DBBF.WriteBuffer(0, 0, IntroMessage);


		// 寰頂僥掘 轎溘 睡
		g_DBBF.TextColor(WHITE, BLACK);
		g_DBBF.WriteBuffer(80, 35, (TCHAR *)"啪歜擊 衛濛ж溥賊 嬴鼠 酈釭 援腦撮蹂");

		// 幗ぷ 瞪�� 塽 贗葬橫
		g_DBBF.FlippingBuffer();
		g_DBBF.ClearBuffer();

		Sleep(150);
	}

}
// 賃貲檜 Ы溯檜 й 匙檣雖 殮溘嫡擠
void CGame::Input_PlayerNum()	// Ы溯檜橫曖 熱蒂 殮溘嫡朝棻
{
	int num = 0;
	FMOD_Channel_Stop(BGM_Channel[INTRO]);
	FMOD_System_PlaySound(g_System, BGM_Music[INPUTPLAYER], NULL, FALSE, &BGM_Channel[INPUTPLAYER]);	// 粽旎 營儅
	FMOD_Channel_SetVolume(BGM_Channel[INPUTPLAYER], 0.5f);
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));	// ⑷營 蝶觼萼戲煎 瞳辨(渦綰幗ぷ葭 x)
	TextColor(WHITE, BLACK);
	while (true)
	{
		MoveXY(75, 15);	// 渦綰 幗ぷ葭擊 餌辨ж雖 彊擊 陽 醴憮 謝ル 衡晦晦
		cout << "Ы溯檜橫曖 熱蒂 殮溘ж撮蹂(2~4檣) : ";
		cin >> num;	// Ы溯檜橫 熱蒂 殮溘嫡擠
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');	// 幗ぷ寰縑 陴嬴氈朝 賅萇 鎬疏晦 雖遺
		}
		system("cls");	// 雖盪碟и �飛� 雖辦晦
		if (num >= 2 && num <= 4)
		{
			iPlayerNum = num;
			m_Player = new CPlayer[num];	// Ы溯檜橫蒂 翕瞳й渡л
			/// Player曖 蟾晦 薑爾蒂 撢たи棻.
			{
				if (num >= 2)
				{
					m_Player[0].Set_PlayerInfo((TCHAR *)"Ⅳ", (LAND_TEXT_VERTICAL + P1_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
					m_Player[1].Set_PlayerInfo((TCHAR *)"﹣", (LAND_TEXT_VERTICAL + P2_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
				}

				if (num >= 3)
					m_Player[2].Set_PlayerInfo((TCHAR *)"Ⅵ", (LAND_TEXT_VERTICAL + P3_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);

				if (num >= 4)
					m_Player[3].Set_PlayerInfo((TCHAR *)"Ⅷ", (LAND_TEXT_VERTICAL + P4_POS) - 2, (LAND_TEXT_HORIZONTAL * 7) + 3, PLAYER_START_MONEY);
			}
			
			while (true)
			{
				iCurBGM = rand() % (BGM4 + 1);
				if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
					break;
			}
			FMOD_Channel_Stop(BGM_Channel[INPUTPLAYER]);
			FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// 粽旎 營儅
			FMOD_Channel_SetVolume(BGM_Channel[iCurBGM], 0.5f);
			break;
		}
	}
}

// 渦綰 幗ぷ葭擊 餌辨ж雖 彊擊 陽曖 旋濠 儀鼻 撲薑
void CGame::TextColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 瞪羹 啪歜 顫橾 賅舒 轎溘
void CGame::Print_Game_Board()
{
	system("mode con cols=190 lines=50");	// �飛� 觼晦 棻衛 棺葡
	BOOL bPlayerTurn_FirstPrint = FALSE;

	while (true)
	{

		g_DBBF.ClearBuffer();	// 檜瞪 幗ぷ曖 頂辨擊 賅舒 雖錶遽棻.
		if(bPlayerTurn_FirstPrint == FALSE)
			Print_Player_Turn();

		/// 傘綠諦 堪檜縑 蜃啪 啗骯ж罹 顫橾擊 轎溘и棻.
		Print_All_Tile();
		/// 階 + か熱 階 薑爾 轎溘
		Print_All_Land();
		Print_All_ExtraLand();
		
		m_Lands->Print_Information(eLandPrint_Idx);
		/// 輿餌嬪 轎溘 塽 輿餌嬪 掉葬晦
 		m_Dice.Dice_Proc(*this);
		/// 議葛攪 薑爾 轎溘(輿餌嬪 湍雖雖雖 彊懊擊 陽虜, 輿餌嬪 湍韓 陽朝 Dice縑憮 憲嬴憮 籀葬ж棲梱)
		Print_All_Character();
		Print_Player_Infor();	// Ы溯檜橫 薑爾 轎溘
		/// 餌遴萄 機等檜お
		Check_BGM();
		FMOD_System_Update(g_System);	// 檜 л熱蒂 啗樓瞳戲煎 ��轎п醜撿 餌遴萄陛 壅�鷙� 彊朝棻.

		g_DBBF.FlippingBuffer();	// 幗ぷ蒂 夥脯遽棻(渦綰幗ぷ葭)
		Sleep(1);
	}
}

void CGame::Print_Indivisual_Tile(int x, int y) //啪歜 顫橾 轎溘  啻賅 1偃.
{
	int iNext_Line = 0;	// 棻擠 還
#if OS_VER == 7
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"忙式式式式式式式式忖");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
#endif
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"弛                弛");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"弛                弛");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"弛                弛");
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"弛                弛");
#if OS_VER == 7
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"戌式式式式式式式式戎");
#elif OS_VER == 10
	g_DBBF.WriteBuffer(x, y + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
#endif
	//顫橾 觼晦 褻薑 , 孺 7 ,孺 10

}

void CGame::MoveXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CGame::Print_All_Tile()
{
	int i, j;
	i = j = 0;
	for (eBoardLTRB = LEFT, i = 0; i < 4;)
	{
		for (j = 0; j < LAND_LINE_LEN; j++)
		{
			switch (eBoardLTRB)
			{
			case LEFT:	// o
				g_DBBF.TextColor(LIGHTGREEN, BLACK);

				if (j == 0)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile(0, j * (TILE_VERTICAL_LEN + TILE_DISTANCE));
				break;

			case TOP:
				g_DBBF.TextColor(LIGHTBLUE, BLACK);

				if (j == LAND_LINE_LEN - 1)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile((j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE)) + (TILE_HORIZONTAL_LEN + TILE_DISTANCE), 0);
				break;

			case RIGHT:
				g_DBBF.TextColor(LIGHTMAGENTA, BLACK);

				if (j == LAND_LINE_LEN - 1)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile((TILE_HORIZONTAL_LEN * (LAND_LINE_LEN + 1)) + (TILE_DISTANCE - 1), (j * (TILE_VERTICAL_LEN + TILE_DISTANCE)) + (TILE_VERTICAL_LEN + TILE_DISTANCE));
				break;

			case BOTTOM:
				g_DBBF.TextColor(LIGHTRED, BLACK);

				if (j == 0)
					g_DBBF.TextColor(YELLOW, BLACK);

				Print_Indivisual_Tile(j * (TILE_HORIZONTAL_LEN + TILE_DISTANCE), (TILE_VERTICAL_LEN + TILE_DISTANCE) * LAND_LINE_LEN);
				break;
			}
		}
		eBoardLTRB = (BOARD_LTRB)++i;
	}
}

void CGame::Print_All_Land()
{
	// 階 薑爾蒂 轎溘и棻.
	for (int i = 0; i < 20; i++)
	{
		m_Lands[i].Print_LandInfo();
	}
}

void CGame::Print_All_ExtraLand()
{
	// か熱 階 薑爾蒂 轎溘и棻
	g_DBBF.TextColor(BROWN, BLACK);
	for (int i = 0; i < 4; i++)
		m_ExtranLands[i].Print_LandInfo();
}

void CGame::Print_All_Character()
{
	/// Ы溯檜橫 議葛攪 轎溘
	for (int i = 0; i < iPlayerNum; i++)
	{
		switch (i)
		{
		case P1:
			g_DBBF.TextColor(P1_COLOR, BLACK);
			break;

		case P2:
			g_DBBF.TextColor(P2_COLOR, BLACK);
			break;

		case P3:
			g_DBBF.TextColor(P3_COLOR, BLACK);
			break;

		case P4:
			g_DBBF.TextColor(P4_COLOR, BLACK);
			break;
		}
		m_Player[i].Print_PlayerInfo();

	}

}

void CGame::Check_BGM()
{
	FMOD_BOOL bSoundPlaying = TRUE;
	/// 喻楚 營儅 部陬戲賊 棻艇 擠學戲煎 營儅
	FMOD_Channel_IsPlaying(BGM_Channel[iCurBGM], &bSoundPlaying);
	if (bSoundPlaying == FALSE)
	{
		while (true)
		{
			iCurBGM = rand() % (BGM4 + 1);
			if (iCurBGM != INTRO && iCurBGM != INPUTPLAYER)
				break;
		}
		FMOD_System_PlaySound(g_System, BGM_Music[iCurBGM], NULL, FALSE, &BGM_Channel[iCurBGM]);	// 粽旎 營儅
		FMOD_Channel_SetVolume(BGM_Channel[iCurBGM], 0.5f);
	}
}

void CGame::RePaint(BOOL bSleep)
{
	g_DBBF.ClearBuffer();
	Print_All_Tile();
	Print_All_Land();
	Print_All_ExtraLand();
	m_Lands->Print_Information(eLandPrint_Idx);
	Print_All_Character();
	m_Dice.Print_Diceinfo();
	Print_Player_Infor();
	Print_Dice_Result_Text(); //輿餌嬪 唸婁高 轎溘

	if(bSleep == TRUE)
		Sleep(PLAYER_MOVE_SPEED);

	g_DBBF.FlippingBuffer();
}

void CGame::Print_Dice_Gage()
{
	int iPower = 0;
	bool bUpdown = false;
	int iKey;	// 酈 殮溘
	int iCnt = 0;	// 1廓 幗ぷ, 2廓 幗ぷ 萃 棻 偽擎 �飛橉虞� 翕晦�倆牁襄� 2廓擊 霞чп撿 и棻.

	if (_kbhit())
	{
		iKey = _getch();
		if (iKey == ' ')
		{
			while (true)
			{

				if (_kbhit())
				{
					iKey = _getch();
					if (iKey == ' ')
					{
						/// 轎溘 紫醞 蝶む檜蝶夥陛 揚葬賊 傳 翕晦�飛� п醜撿 и棻.(渦毀雖虜 橫聶 熱 橈橫, 詭憮萄 虜萄朝 啪 渦 渦楝遺)
						Sleep(600);

						g_DBBF.TextColor(BLACK, BLACK);
						for (int i = 0; i <= MAX_GAGE; i++)
							g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

						return;
					}
				}


				g_DBBF.ClearBuffer();


				if (bUpdown == FALSE)
				{
					int i = 0;

					g_DBBF.TextColor(RED, RED);
					for (i = 0; i <= iPower; i++)
						g_DBBF.WriteBuffer(DICE_POS_X + 8 + iPower, DICE_POS_Y + 15, (TCHAR *)"  ");
					

					g_DBBF.TextColor(BLACK, WHITE);
					for (; i <= abs(MAX_GAGE - iPower); i++)
						g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

				}


				else
				{
					g_DBBF.TextColor(BLACK, WHITE);

					for (int i = 0; i <= iPower; i++)
						g_DBBF.WriteBuffer(DICE_POS_X + 8 + iPower, DICE_POS_Y + 15, (TCHAR *)"  ");
				}

				Sleep(1);

				Print_All_Tile();
				Print_All_Land();
				Print_All_ExtraLand();
				Print_All_Character();
				m_Dice.Print_Diceinfo();

				g_DBBF.FlippingBuffer();


				if (bUpdown == FALSE && iPower < MAX_GAGE) //だ錶陛 啗樓 諦葬陛葬 1睡攪9
				{
					iCnt++;
					if (iCnt == 2)
					{
						iCnt = 0;
						iPower++;
					}

					if (iPower == MAX_GAGE) //9陛腎賊
						bUpdown = true; //譆渠纂檜棻
				}
				else if (bUpdown == TRUE && iPower > 0)
				{
					iCnt++;
					if (iCnt == 2)
					{
						iCnt = 0;
						iPower--;
					}

					if (iPower == 0)  //だ錶陛 0檜賊
						bUpdown = false;  //譆模纂檜棻.
				}

			}
		}
	}

	else // 酈 殮溘檜 橈擊 衛縑朝 斜傖 棻 匐薑戲煎 瓣遺.
	{
		g_DBBF.TextColor(BLACK, BLACK);
		for (int i = 0; i <= MAX_GAGE; i++)
			g_DBBF.WriteBuffer(DICE_POS_X + 8 + i, DICE_POS_Y + 15, (TCHAR *)"  ");

		//m_Dice.Throw_Dice();
	}
}

void CGame::PlayFX(int idx)
{
	FMOD_CHANNEL *tmp_Channel;	// 歜衛 瓣割
	FMOD_System_PlaySound(g_System, g_FX_Sound[idx], NULL, FALSE, &tmp_Channel);	// 輿餌嬪 擠撩 營儅
	FMOD_Channel_SetVolume(tmp_Channel, 0.5f);	// 模葬覬 還檜濠
}

void CGame::Print_Player_Turn()
{
	char cPlayer_TurnPrint[100];
	char cGoldKey_Print[100];  // �盛暆乘� 轎溘 僥濠翮
	int iNext_Line = 0;
	int iTurn_Print = NULL;
	iTurn_Print = (int)eCurPlayer + 1;
	g_DBBF.TextColor(WHITE, BLACK);
	if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cPlayer_TurnPrint, "弛 Ы溯檜橫 %d曖 離滔殮棲棻. 錳ж朝 雖羲擊 摹鷗ж撮蹂弛", iTurn_Print);
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)cPlayer_TurnPrint);
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
}

	else if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_NONE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cPlayer_TurnPrint, "弛 Ы溯檜橫 %d曖 離滔殮棲棻. 輿餌嬪蒂 掉溥輳!弛", iTurn_Print);
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)cPlayer_TurnPrint);
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_TURN_XPOS, PLAYER_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
   }
	iNext_Line = 0;
	if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_NONE)
	{

	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_WORLDTRIP)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cGoldKey_Print, "弛 �盛暆乘� : 撮啗罹ч縑 渡繩腎樟蝗棲棻! 蹴жм棲棻!弛");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_ISLAND)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cGoldKey_Print, "弛 �盛暆乘� : 鼠檣紫縑 渡繩腎樟蝗棲棻!! Д六Д六    弛");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	}
	else if (m_Player[eCurPlayer].iGoldKey == GOLDKEY_START)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cGoldKey_Print, "弛 �盛暆乘� : 轎嫦雖煎 陛鍔嬴! 渡繩腎樟蝗棲棻!!!    弛");
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)cGoldKey_Print);
#if OS_VER == 7
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(GOLDKEY_XPOS, GOLDKEY_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	}

}
void CGame::Print_Dice_Result_Text()
{
	char cDice_ResultPrint[50];
	int iNext_Line = 0;
	g_DBBF.TextColor(WHITE, BLACK);

	if (m_Player[eCurPlayer].iWorldTrip == WORLDTRIP_MOVE)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"弛 撮啗罹ч 雖羲擎 摹鷗й 熱 橈蝗棲棻! 弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
		return;
	}

	if (iPlayer_Dice_Result == 0)
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"弛 嬴霜 輿餌嬪蒂 給葬雖 彊懊蝗棲棻. 給溥蹂!!弛");
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	}

	else
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		if (m_Player[eCurPlayer].bPlayer_Dice_Double == TRUE)
			g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"弛 渦綰! и 廓 渦 給萵 熱 氈橫蹂~ 遺霜殮衛棻弛");

		if (iPlayer_Dice_Result >= 10)	// 10 濠葬 檜鼻檜賊 蝶む檜蝶 и蘊, 1曖 濠葬賊 蝶む檜蝶 舒 蘊
			wsprintf(cDice_ResultPrint, "弛 ё斜腦腦~ 輿餌嬪蒂 掉溥 %d陛 釭諮蝗棲棻. 弛", iPlayer_Dice_Result);

		else
			wsprintf(cDice_ResultPrint, "弛 ё斜腦腦~ 輿餌嬪蒂 掉溥 %d陛 釭諮蝗棲棻.  弛", iPlayer_Dice_Result);

		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)cDice_ResultPrint);

#if OS_VER == 7
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(DICE_TURN_XPOS, DICE_TURN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	}
};
void CGame::Print_Player_Infor()
{
	int iNext_Line;

	char cPlayer_Money1[30] = { "" };
	char cPlayer_Money2[30] = { "" };
	char cPlayer_Money3[30] = { "" };
	char cPlayer_Money4[30] = { "" };

	char cPlayer_Total_Money1[30] = { "" };
	char cPlayer_Total_Money2[30] = { "" };
	char cPlayer_Total_Money3[30] = { "" };
	char cPlayer_Total_Money4[30] = { "" };

	/*for (int i = 0; i < 3; i++)
	{
	m_Player[i].Set_PlayerTotalMoney();
	}*/
	if (iPlayerNum >= 2)
	{
		g_DBBF.TextColor(P1_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 Ы溯檜橫1 : Ⅳ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 爾嶸 絲  :     ");
		wsprintf(cPlayer_Money1, TEXT("弛 %d 虜錳        "), m_Player[0].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Money1);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 識 濠骯 :      ");
		wsprintf(cPlayer_Total_Money1, TEXT("弛 %d 虜錳        "), m_Player[0].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Total_Money1);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式");
#endif
		g_DBBF.TextColor(P2_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 Ы溯檜橫2 : ﹣ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 爾嶸 絲  :     ");
		wsprintf(cPlayer_Money2, "弛 %d 虜錳        ", m_Player[1].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Money2);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛 識 濠骯 :      ");
		wsprintf(cPlayer_Total_Money2, "弛 %d 虜錳        ", m_Player[1].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)cPlayer_Total_Money2);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"弛                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式");
#endif
	}
	if (iPlayerNum >= 3)
	{
		g_DBBF.TextColor(P3_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"忙式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛 Ы溯檜橫3 : Ⅵ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛 爾嶸 絲  :     ");
		wsprintf(cPlayer_Money3, "弛 %d 虜錳        ", m_Player[2].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Money3);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛 識 濠骯 :      ");
		wsprintf(cPlayer_Total_Money3, "弛 %d 虜錳        ", m_Player[2].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Total_Money3);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"戌式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式");
#endif
	}
	if (iPlayerNum >= 4)
	{
		g_DBBF.TextColor(P4_COLOR, BLACK);
		iNext_Line = 0;
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"忙式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式");
#endif
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛 Ы溯檜橫4 : Ⅷ ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛 爾嶸 絲  :     ");
		wsprintf(cPlayer_Money4, "弛 %d 虜錳        ", m_Player[3].iPlayer_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Money4);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛 識 濠骯 :      ");
		wsprintf(cPlayer_Total_Money4, "弛 %d 虜錳        ", m_Player[3].iPlayer_Total_Money);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)cPlayer_Total_Money4);
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛                ");
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"弛                ");
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"戌式式式式式式式式");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_INFOR_XPOS + 20, PLAYER_INFOR_YPOS + 10 + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式");
#endif
	}
}

void CGame::Print_WinPlayer(int win, int win_way)
{
	int iWin_Player = win;
	int iWin_way = win_way;
	int iNext_Line = 0;
	int iWin_TextColor = win; // 辦蝓 臢蝶お 轎溘 儀
	char cWin_Player_Print[100];
	//辦蝓и Ы溯檜橫縑評塭憮 п渡 Ы溯檜橫曖 儀戲煎 臢蝶お 轎溘
	{
		if (iWin_TextColor == 1)
			g_DBBF.TextColor(P1_COLOR, BLACK);

		else if (iWin_TextColor == 2)
			g_DBBF.TextColor(P2_COLOR, BLACK);


		else if (iWin_TextColor == 3)
			g_DBBF.TextColor(P3_COLOR, BLACK);


		else if (iWin_TextColor == 4)
			g_DBBF.TextColor(P4_COLOR, BLACK);
	}

	if (iWin_way == 0) //絲戲煎 辦蝓 衛
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cWin_Player_Print, "弛 Ы溯檜橫 %d陛 棻艇 Ы溯檜橫菟檜 だ骯    弛", iWin_Player);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)cWin_Player_Print);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"弛 ж朝 陛遴等 部梱雖 唯筑麻蝗棲棻!!!      弛");
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"弛 蹴ж萄董棲棻! 檜啣蝗棲棻!!              弛");

#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif
	}
	//塭檣絮薄
	else
	{
#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式忖");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
#endif
		wsprintf(cWin_Player_Print, "弛 Ы溯檜橫 %d陛 塭檣擊 賅舒 衙熱ц蝗棲棻! 弛", iWin_Player);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)cWin_Player_Print);
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"弛 塭檣絮薄!!戲煎 辦蝓ц蝗棲棻!!!          弛");
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"弛 蹴ж萄董棲棻! 檜啣蝗棲棻!!              弛");

#if OS_VER == 7
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式戎");
#elif OS_VER == 10
		g_DBBF.WriteBuffer(PLAYER_WIN_XPOS, PLAYER_WIN_YPOS + iNext_Line++, (TCHAR *)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
#endif

		exit(0);
	}
}
