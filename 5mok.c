#include <stdio.h>

int board[19][19] = { 0 };

int main(void) {
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