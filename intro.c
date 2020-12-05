#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define WHITE 7
#define BLACK 0

void gotoxy(int x, int y)

{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int board[19][19] = { 0 };

void LetterColor(int color) { // 오목돌 색 변경
	if (color == WHITE)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
	else if (color == BLACK)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
}
void Board(void)				//오목판 함수
{
	printf("\n\n");
	if (board[0][0] == 0)	//첫번째줄
	{
		LetterColor(BLACK);
		printf("┌ ");
		LetterColor(WHITE);
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
			LetterColor(BLACK);
			printf("┬ ");
			LetterColor(WHITE);
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
		LetterColor(BLACK);
		printf("┐ \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	else if (board[0][18] == 1)
	{
		LetterColor(BLACK);
		printf("●\n");
		LetterColor(WHITE);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	else if (board[0][18] == -1)
	{
		LetterColor(WHITE);
		printf("●\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}									//여기까지가 첫번째줄
	for (int i = 1; i < 18; i++)		//두번째줄부터 18번째줄까지
	{
		if (board[i][0] == 0)
		{
			LetterColor(BLACK);
			printf("├ ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
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
				LetterColor(BLACK);
				printf("┼ ");
				LetterColor(WHITE);
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
			LetterColor(BLACK);
			printf("┤ \n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else if (board[i][18] == 1)
		{
			LetterColor(BLACK);
			printf("●\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else if (board[i][18] == -1)
		{
			LetterColor(WHITE);
			printf("●\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
	}									//여기까지가 두번째줄

	if (board[18][0] == 0)	//마지막번째줄
	{
		LetterColor(BLACK);
		printf("└ ");
		LetterColor(WHITE);
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
			LetterColor(BLACK);
			printf("┴ ");
			LetterColor(WHITE);
		}
		else if (board[18][i] == 1)
		{
			LetterColor(BLACK);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else if (board[18][i] == -1)
		{
			LetterColor(WHITE);
			printf("●");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
	}
	if (board[18][18] == 0)
	{
		LetterColor(BLACK);
		printf("┘ \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	else if (board[18][18] == 1)
	{
		LetterColor(BLACK);
		printf("●\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
	else if (board[18][18] == -1)
	{
		LetterColor(WHITE);
		printf("●\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}								//여기까지가 마지막번째줄
}

void intro(void)
{
	int i = 0;
	int key;
	while (1)
	{
		gotoxy(0, 0);
		printf("");
		Board();
		gotoxy(0, 24);
		printf("   Enter을 누르면 게임을 시작합니다.\n");
		Sleep(500);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}

		gotoxy(18, 11);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
		Sleep(500);
		gotoxy(20, 11);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		Sleep(500);

		gotoxy(16, 10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
		Sleep(500);
		gotoxy(18, 12);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		Sleep(500);

		gotoxy(20, 12);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
		Sleep(500);
		gotoxy(14, 9);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		Sleep(500);

		gotoxy(22, 13);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
		Sleep(500);
		gotoxy(18, 10);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		Sleep(500);

		gotoxy(24, 14);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
		printf("●");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}

		gotoxy(0, 24);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		
		if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
	}
}
int main(void) {
	
	intro();
	return 0;
}