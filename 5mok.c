#include <stdio.h>

int board[19][19] = { 0 };

int main(void) {
	printf("  ¨æ¨ç¨è¨é¨ê¨ë¨ì¨í¨î¨ï¨ð¨ñ¨ò¨ó¨ô¨õ¨Í¨Î¨Ï -- xÁÂÇ¥\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0)
			{
				printf("¡à");
			}
			else if (board[i][j] == 1)
			{
				printf("¡Û");
			}
			else if (board[i][j] == -1)
			{
				printf("¡Ü");
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
				printf("¡à");
			}
			else if (board[i][j] == 1)
			{
				printf("¡Û");
			}
			else if (board[i][j] == -1)
			{
				printf("¡Ü");
			}
		}
		printf("\n");
	}
	printf("|\ny\nÁÂ\nÇ¥\n\n");
}