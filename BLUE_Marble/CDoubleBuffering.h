#ifndef __CDOUBLEBUFFERING__
#define __CDOUBLEBUFFERING__
#define MAP_X_MAX 250
#define MAP_Y_MAX 100

class CDoubleBuffering
{
private:
	HANDLE hBuffer[2];	// 화면 버퍼 핸들
	int nScreenIndex = 0;	// 화면 번호(0번, 1번 두 개)
	CHAR_INFO Tile[256];

public:
	CDoubleBuffering();
	~CDoubleBuffering();

	// 콘솔 더블버퍼링용 색상 변경 메서드
	void TextColor(int foreground, int background);

	/*
		콘솔 더블버퍼링을 위한 메서드들
	*/
	void CreatBuffer();	// 버퍼 생성용 메서드(최초 1회)
	void WriteBuffer(int x, int y, TCHAR str[]);	// 버퍼에 새로운 내용을 덮어 쓸 때(계속)
	void FlippingBuffer();	// 버퍼를 번갈아가면서 0번 1번으로 바꿀 때(계속)
	void ClearBuffer();	// 버퍼의 내용을 모두 지울 때(계속)
	void DeleteBuffer();	// 버퍼를 없앨 때 (최후 1회)
	void gotoxy(int x, int y);
};
#endif
