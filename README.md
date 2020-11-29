# two-team-fire-extinguisher-
 저희 소화기 팀은 이차원 배열을 응용하여 2인용 오목 게임을 만들기로 하였습니다.\
  단순해보일수도 있는 오목게임에 다양한 미니게임을 조합하여 변수를 두어, 더욱 재미있는 게임을 만들고자 합니다.\
  미니게임은 게임을 시작할 때 흑백을 정할때와, 무르기를 실행할 때 실행되며, 흥미로운 변수로서 작용할 수 있을 것입니다.
 
 오목의 전체 보드는 다음과 같이 구성되어 있습니다. 
 
 ## board[19][19]
 board[i][j]에는 보드의 (j, i) 좌표에 해당하는 칸의 상태가 적혀있습니다.
 
 board[i][j] =  0: 비어있는 칸입니다.\
 board[i][j] =  1: 흑돌을 둔 칸입니다.\
 board[i][j] = -1: 백돌을 둔 칸입니다.
 
 ## 메인함수 (main.c)
 
```C
#include <stdio.h>
#include <Windows.h>

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };

void LetterColor(int color) { // 오목돌 색 변경함수
	if (color == WHITE)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	else if (color == BLACK)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
}

void Board(void)
{
	printf("ⓞ①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮ⓐⓑⓒ -- x좌표\n");
	if (board[0][0] == 0)	//첫번째줄
	{
		printf("┌ ");
	}
	else if (board[0][0] == 1)
	{
		LetterColor(BLACK);
		printf("●");
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
			printf("┬ ");
		}
		else if (board[0][i] == 1)
		{
			LetterColor(BLACK);
			printf("●");
		}
		else if (board[0][i] == -1)
		{
			LetterColor(WHITE);
			printf("●");
		}
	}
	if (board[0][18] == 0)
	{
		printf("┐ 0\n");
	}
	else if (board[0][18] == 1)
	{
		LetterColor(BLACK);
		printf("●");
	}
	else if (board[0][18] == -1)
	{
		LetterColor(WHITE);
		printf("●");
	}									//여기까지가 첫번째줄

	for (int i = 1; i < 18; i++)		//두번째줄부터 18번째줄까지
	{
		if (board[i][0] == 0)
		{
			printf("├ ");
		}
		else if (board[i][0] == 1)
		{
			LetterColor(BLACK);
			printf("●");
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
				printf("┼ ");
			}
			else if (board[i][j] == 1)
			{
				LetterColor(BLACK);
				printf("●");
			}
			else if (board[i][j] == -1)
			{
				LetterColor(WHITE);
				printf("●");
			}
		}
		if (board[i][18] == 0)
		{
			printf("┤ %d\n", i);
		}
		else if (board[i][18] == 1)
		{
			LetterColor(BLACK);
			printf("●");
		}
		else if (board[i][18] == -1)
		{
			LetterColor(WHITE);
			printf("●");
		}
	}									//여기까지가 두번째줄

	if (board[18][0] == 0)	//마지막번째줄
	{
		printf("└ ");
	}
	else if (board[18][0] == 1)
	{
		LetterColor(BLACK);
		printf("●");
	}
	else if (board[18][0] == -1)
	{
		LetterColor(WHITE);
		printf("●");
	}
	for (int i = 1; i < 18; i++)
	{
		if (board[18][i] == 0)
		{
			printf("┴ ");
		}
	}
	if (board[18][18] == 0)	
	{
		printf("┘ 18 -- y좌표\n");
	}
	else if (board[18][18] == 1)
	{
		LetterColor(BLACK);
		printf("●");
	}
	else if (board[18][18] == -1)
	{
		LetterColor(WHITE);
		printf("●");
	}								//여기까지가 마지막번째줄
}
int main(void) {
	Board();

	return 0;
}
```
