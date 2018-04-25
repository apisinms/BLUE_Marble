#pragma once
#define MAP_X_MAX 400
#define MAP_Y_MAX 400

class CDoubleBuffering
{
private:
	HANDLE hBuffer[2];	// ȭ�� ���� �ڵ�
	int nScreenIndex = 0;	// ȭ�� ��ȣ(0��, 1�� �� ��)

public:
	CDoubleBuffering();
	~CDoubleBuffering();

	// �ܼ� ������۸��� ���� ���� �޼���
	void TextColor(int foreground, int background);

	/*
		�ܼ� ������۸��� ���� �޼����
	*/
	void CreatBuffer();	// ���� ������ �޼���(���� 1ȸ)
	void WriteBuffer(int x, int y, char str[]);	// ���ۿ� ���ο� ������ ���� �� ��(���)
	void FlippingBuffer();	// ���۸� �����ư��鼭 0�� 1������ �ٲ� ��(���)
	void ClearBuffer();	// ������ ������ ��� ���� ��(���)
	void DeleteBuffer();	// ���۸� ���� �� (���� 1ȸ)
};

