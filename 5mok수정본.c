#include <stdio.h>
#include <Windows.h>

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };

void LetterColor(int color) { // 오목돌 색 변경
	if (color == WHITE)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
	else if (color == BLACK)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
}

void Board(void)				//오목판 함수
{
	printf("ⓞ①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮ⓐⓑⓒ -- x좌표\n");
	if (board[0][0] == 0)	//첫번째줄
	{
		LetterColor(WHITE);
		printf("┌ ");
	}
	else if (board[0][0] == 1)
	{
		LetterColor(BLACK);
		printf("●");
		LetterColor(WHITE);
	}
	else if (board[0][0] == -1)
	{
		LetterColor(WHITE);
		printf("●");
	}
	for (int i = 1; i < 18; i++)
	{
		if (board[0][i] == 0)
		{
			LetterColor(WHITE);
			printf("┬ ");
		}
		else if (board[0][i] == 1)
		{
			LetterColor(BLACK);
			printf("●");
			LetterColor(WHITE);
		}
		else if (board[0][i] == -1)
		{
			LetterColor(WHITE);
			printf("●");
		}
	}
	if (board[0][18] == 0)
	{
		LetterColor(WHITE);
		printf("┐ ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf(" 0\n");
	}
	else if (board[0][18] == 1)
	{
		LetterColor(BLACK);
		printf("●");
		LetterColor(WHITE);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf(" %d\n", 0);
	}
	else if (board[0][18] == -1)
	{
		LetterColor(WHITE);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf(" %d\n", 0);
	}									//여기까지가 첫번째줄

	for (int i = 1; i < 18; i++)		//두번째줄부터 18번째줄까지
	{
		if (board[i][0] == 0)
		{
			LetterColor(WHITE);
			printf("├ ");
		}
		else if (board[i][0] == 1)
		{
			LetterColor(BLACK);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else if (board[i][0] == -1)
		{
			LetterColor(WHITE);
			printf("●");
		}
		for (int j = 1; j < 18; j++)
		{
			if (board[i][j] == 0)
			{
				LetterColor(WHITE);
				printf("┼ ");
			}
			else if (board[i][j] == 1)
			{
				LetterColor(BLACK);
				printf("●");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			}
			else if (board[i][j] == -1)
			{
				LetterColor(WHITE);
				printf("●");
			}
		}
		if (board[i][18] == 0)
		{
			LetterColor(WHITE);
			printf("┤ ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			printf(" %d\n", i);
		}
		else if (board[i][18] == 1)
		{
			LetterColor(BLACK);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			printf(" %d\n", i);
		}
		else if (board[i][18] == -1)
		{
			LetterColor(WHITE);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			printf(" %d\n", i);
		}
	}									//여기까지가 두번째줄

	if (board[18][0] == 0)	//마지막번째줄
	{
		LetterColor(WHITE);
		printf("└ ");
	}
	else if (board[18][0] == 1)
	{
		LetterColor(BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	else if (board[18][0] == -1)
	{
		LetterColor(WHITE);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	for (int i = 1; i < 18; i++)
	{
		if (board[18][i] == 0)
		{
			LetterColor(WHITE);
			printf("┴ ");
		}
		else if (board[18][i] == 1)
		{
			LetterColor(BLACK);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			printf(" %d\n", i);
		}
		else if (board[18][i] == -1)
		{
			LetterColor(WHITE);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			printf(" %d\n", i);
		}
	}
	if (board[18][18] == 0)	
	{
		LetterColor(WHITE);
		printf("┘ ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf(" 18 -- y좌표 \n");
	}
	else if (board[18][18] == 1)
	{
		LetterColor(BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf(" 18\n");
	}
	else if (board[18][18] == -1)
	{
		LetterColor(WHITE);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf(" 18\n");
	}								//여기까지가 마지막번째줄
}
int main(void) {					
	Board();						//오목판 출력함수

	return 0;
}
