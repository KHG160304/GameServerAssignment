#include <stdio.h>
#include <conio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

#define CNT	9

int g_Timming[CNT] = { 5 * 1000, 10 * 1000, 14 * 1000, 17 * 1000, 20 * 1000, 25 * 1000, 29 * 1000, 31 * 1000, 33 * 1000 };
int g_TimmingResult[CNT] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
const char* g_TimmingResultGrade[CNT] = { "", "", "", "", "", "", "", "", "", };

void TimmingGame()
{//Å×½ºÆ®
	constexpr int GREATE = 1000 / 4;
	constexpr int GOOD = 1000 / 3;
	constexpr int NO_GOOD = 1000 / 2;
	constexpr int BAD = 1000;

	const char* strGREATE = "GREATE";
	const char* strGOOD = "GOOD";
	const char* strNO_GOOD = "NO_GOOD";
	const char* strBAD = "BAD";
	const char* strFAIL = "FAIL";

	DWORD startTime = timeGetTime();
	DWORD elapsedTime = 0;
	int idx = 0;

	while (idx < CNT)
	{
		//logic
		elapsedTime = timeGetTime() - startTime;
		if (_kbhit())
		{
			g_TimmingResult[idx] = abs((int)elapsedTime - g_Timming[idx]);
			if (GREATE > g_TimmingResult[idx])
			{
				g_TimmingResultGrade[idx] = strGREATE;
			}
			else if (GOOD > g_TimmingResult[idx])
			{
				g_TimmingResultGrade[idx] = strGOOD;
			}
			else if (NO_GOOD > g_TimmingResult[idx])
			{
				g_TimmingResultGrade[idx] = strNO_GOOD;
			}
			else if (BAD > g_TimmingResult[idx])
			{
				g_TimmingResultGrade[idx] = strBAD;
			}
			else
			{
				g_TimmingResultGrade[idx] = strFAIL;
			}
			idx += 1;
			_getch();
		}
		else if ((int)elapsedTime - g_Timming[idx] > 1000 && g_TimmingResult[idx] == -1)
		{
			g_TimmingResultGrade[idx] = strFAIL;
			idx += 1;
		}

		//render
		system("cls");
		printf("%02d:%03d Sec", elapsedTime / 1000, elapsedTime % 1000); \
			printf("\n\n");
		for (int i = 0; i < CNT; ++i)
		{
			printf("%d Sec: %s\n", g_Timming[i], g_TimmingResultGrade[i]);
		}
	}
}

int main(void)
{
	timeBeginPeriod(1);
	TimmingGame();
	timeEndPeriod(1);
}