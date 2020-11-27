#include <stdio.h>

int board[19][19] = { 0 };
int change = 0;
int win = 0;

void printboard(int(*board)[19])
{
	printf("  �������������������ͨΨ� -- x��ǥ\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0)
			{
				printf("��");
			}
			else if (board[i][j] == 1)
			{
				printf("��");
			}
			else if (board[i][j] == -1)
			{
				printf("��");
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
				printf("��");
			}
			else if (board[i][j] == 1)
			{
				printf("��");
			}
			else if (board[i][j] == -1)
			{
				printf("��");
			}
		}
		printf("\n");
	}
	printf("|\ny\n��\nǥ\n\n");
}

void turnprint(int (*board)[19])
{
	int select = 0;
	int x = 0;
	int y = 0;
	//�̴ϰ��� �¸���== ������("-1") 
	//A ==1  B==0
	if (win == 1)  //���� �¸��ڰ� A�� ��
	{
		if (change == 1)
		{
			printf("A�� �����Դϴ�.\n");
			printf("��ǥ�� �Է��Ͻÿ�. ex) (1,2)---> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = -1;
			change = 0;
		}
		else if (change == 0)
		{
			printf("B�� �����Դϴ�.\n");
			printf("��ǥ�� �Է��Ͻÿ�. ex) (1,2)---> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = 1;
			change = 1;
		}
	}
	else if (win == 0)  //���� �¸��ڰ� B�� ��
	{
		if (change == 0)
		{
			printf("B�� �����Դϴ�.\n");
			printf("��ǥ�� �Է��Ͻÿ�. ex) (1,2)-> 12  : ");
			scanf_s("%d", &select);
			x = select / 10;
			y = select % 10;
			board[y][x] = -1;
			change = 1;
		}
		else if (change == 1)
		{
			printf("A�� �����Դϴ�.\n");
			printf("��ǥ�� �Է��Ͻÿ�. ex) (1,2)-> 12  : ");
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