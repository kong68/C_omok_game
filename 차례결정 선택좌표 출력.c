#include <stdio.h>

int board[19][19] = { 0 };
int change = 0;
int win = 0;

void printboard(int(*board)[19])
{
	printf("  ⓩ①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮ⓐⓑⓒ -- x좌표\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0)
			{
				printf("□");
			}
			else if (board[i][j] == 1)
			{
				printf("○");
			}
			else if (board[i][j] == -1)
			{
				printf("●");
			}
		}
		printf("\n");
	}

	for (int i = 10; i < 19; i++)
	{
		printf("%d", i);
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0)
			{
				printf("□");
			}
			else if (board[i][j] == 1)
			{
				printf("○");
			}
			else if (board[i][j] == -1)
			{
				printf("●");
			}
		}
		printf("\n");
	}
	printf("|\ny\n좌\n표\n\n");
}

void turnprint(int (*board)[19])
{
	int select = 0;
	int x = 0;
	int y = 0;
	//미니게임 승리자== 검은돌("-1") 
	//A ==1  B==0
	if (win == 1)  //선공 승리자가 A일 때
	{
		if (change == 1)
		{
			printf("A의 차례입니다.\n");
			printf("좌표를 입력하시오. ex) (1,2)---> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = -1;
			change = 0;
		}
		else if (change == 0)
		{
			printf("B의 차례입니다.\n");
			printf("좌표를 입력하시오. ex) (1,2)---> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = 1;
			change = 1;
		}
	}
	else if (win == 0)  //선공 승리자가 B일 때
	{
		if (change == 0)
		{
			printf("B의 차례입니다.\n");
			printf("좌표를 입력하시오. ex) (1,2)-> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = -1;
			change = 1;
		}
		else if (change == 1)
		{
			printf("A의 차례입니다.\n");
			printf("좌표를 입력하시오. ex) (1,2)-> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = 1;
			change = 0;
		}
	}
}


int main(void) {

	printboard(board);
	turnprint(board);
	printboard(board);
	turnprint(board);
	printboard(board);
	turnprint(board);
	printboard(board);
	turnprint(board);
	printboard(board);
}