#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

constexpr char _0__ = 0x30;
constexpr char CHEK = 0x2E;
constexpr char BLNK = ' ';

//constexpr char WIDTH = 20;
//constexpr char HEIGHT = 20;

constexpr char WIDTH = 18;
constexpr char HEIGHT = 9;

#define	MoveLeft(x, y)	x - 1, y
#define MoveRight(x, y)	x + 1, y
#define MoveUp(x, y)	x, y - 1
#define MoveDown(x, y)	x, y + 1

#define PaintLeft(arrToPaint, width, height, x, y)	PaintRecursive(arrToPaint, width, height, MoveLeft(x, y))
#define PaintRight(arrToPaint, width, height, x, y)	PaintRecursive(arrToPaint, width, height, MoveRight(x, y))
#define PaintUp(arrToPaint, width, height, x, y)	PaintRecursive(arrToPaint, width, height, MoveUp(x, y))
#define PaintDown(arrToPaint, width, height, x, y)	PaintRecursive(arrToPaint, width, height, MoveDown(x, y))

void PaintRecursive(char (*arrToPaint)[WIDTH], char width, char height, char x, char y);
void PrintArray(char (*arrToPaint)[WIDTH], char width, char height, int duration);

//char arrToPaint[HEIGHT][WIDTH] = {
//	_0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, BLNK, _0__, _0__, _0__, _0__, BLNK, BLNK, _0__, _0__, BLNK, BLNK, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, BLNK, _0__, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, BLNK, _0__, _0__, _0__, BLNK, BLNK, BLNK, _0__, _0__, _0__, BLNK, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, BLNK, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, BLNK, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, BLNK, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, BLNK, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, BLNK, _0__, BLNK, _0__, _0__, _0__, BLNK, _0__, BLNK, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, BLNK, _0__, BLNK, BLNK, BLNK, _0__, BLNK, _0__, BLNK, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, BLNK, _0__, _0__, _0__, BLNK, _0__, BLNK, _0__, _0__, _0__, BLNK, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, _0__, _0__, _0__, BLNK, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, BLNK, _0__, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, _0__, BLNK, _0__, _0__, _0__, BLNK, BLNK, BLNK, _0__, _0__, _0__, BLNK, _0__, _0__, _0__, _0__, _0__,
//	_0__, _0__, _0__, BLNK, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, BLNK, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__
//};

char arrToPaint[HEIGHT][WIDTH] = {
	BLNK, _0__, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, _0__, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, _0__,
	BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, BLNK, BLNK, _0__, _0__, _0__,
	_0__, _0__, _0__, _0__, _0__, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
	_0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
	_0__, _0__, _0__, BLNK, _0__, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__,
	_0__, _0__, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, BLNK,
	_0__, _0__, BLNK, _0__, _0__, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, BLNK, BLNK, BLNK,
	BLNK, _0__, BLNK, BLNK, _0__, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, BLNK,
	BLNK, BLNK, BLNK, BLNK, BLNK, BLNK, _0__, _0__, _0__, _0__, _0__, _0__, BLNK, BLNK, BLNK, BLNK, BLNK, BLNK
};

void initArrToPaint(char (*arr)[WIDTH])
{
	memcpy_s(arr, sizeof(char) * WIDTH * HEIGHT, arrToPaint, sizeof(char) * WIDTH * HEIGHT);
	PrintArray(arr, WIDTH, HEIGHT, 1500);
}

void PaintRecursive(char (*arrToPaint)[WIDTH], char width, char height, char x, char y)
{  
	if (x < 0 || x == width || y < 0 || y == height)
	{
		return;
	}

	if (arrToPaint[y][x] == CHEK || arrToPaint[y][x] == BLNK)
	{
		return;
	}
	//LOGIC
	arrToPaint[y][x] = CHEK;
	//DRAW UI
	PrintArray(arrToPaint, WIDTH, HEIGHT, 10);
	//MOVE NEXT
	PaintLeft(arrToPaint, width, height, x, y);
	PaintRight(arrToPaint, width, height, x, y);
	PaintUp(arrToPaint, width, height, x, y);
	PaintDown(arrToPaint, width, height, x, y);
}

void PrintArray(char (*arrToPaint)[WIDTH], char width, char height, int duration)
{
	COORD pos;

	system("cls");
	for (int y = 0; y < height; ++y)
	{
		pos.X = 10;
		pos.Y = (y * -1) - 1; 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		for (int x = 0; x < width; ++x)
		{
			pos.X = x + 1;
			pos.Y = y + 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			printf("%c", arrToPaint[y][x]);
		}
		printf("\n");
	}
	Sleep(duration);
}

int main(void)
{
	char _arrToPaint[HEIGHT][WIDTH] = { 0, };
	while (1)
	{
		initArrToPaint(_arrToPaint);
		PaintRecursive(_arrToPaint, WIDTH, HEIGHT, 9, 4);
		Sleep(1500);
	}

	return 0;
}