/*#include <stdio.h>

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
}*/

#include <stdio.h>
#include <Windows.h>

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };

void LetterColor(int color) { // ������ �������� �۾��� ����
	if (color == WHITE)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	else if (color == BLACK)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
}

void Board(void)
{
	printf("�ۨ�����������������ͨΨ� -- x��ǥ\n");
	if (board[0][0] == 0)	//ù��°��
	{
		printf("�� ");
	}
	else if (board[0][0] == 1)
	{
		LetterColor(BLACK);
		printf("��");
	}
	else if (board[0][0] == -1)
	{
		LetterColor(WHITE);
		printf("��");
	}
	for (int i = 1; i < 18; i++)
	{
		if (board[0][i] == 0)
		{
			printf("�� ");
		}
		else if (board[0][i] == 1)
		{
			LetterColor(BLACK);
			printf("��");
		}
		else if (board[0][i] == -1)
		{
			LetterColor(WHITE);
			printf("��");
		}
	}
	if (board[0][18] == 0)
	{
		printf("�� 0\n");
	}
	else if (board[0][18] == 1)
	{
		LetterColor(BLACK);
		printf("��");
	}
	else if (board[0][18] == -1)
	{
		LetterColor(WHITE);
		printf("��");
	}									//��������� ù��°��

	for (int i = 1; i < 18; i++)		//�ι�°�ٺ��� 18��°�ٱ���
	{
		if (board[i][0] == 0)
		{
			printf("�� ");
		}
		else if (board[i][0] == 1)
		{
			LetterColor(BLACK);
			printf("��");
		}
		else if (board[i][0] == -1)
		{
			LetterColor(WHITE);
			printf("��");
		}
		for (int j = 1; j < 18; j++)
		{
			if (board[i][j] == 0)
			{
				printf("�� ");
			}
			else if (board[i][j] == 1)
			{
				LetterColor(BLACK);
				printf("��");
			}
			else if (board[i][j] == -1)
			{
				LetterColor(WHITE);
				printf("��");
			}
		}
		if (board[i][18] == 0)
		{
			printf("�� %d\n", i);
		}
		else if (board[i][18] == 1)
		{
			LetterColor(BLACK);
			printf("��");
		}
		else if (board[i][18] == -1)
		{
			LetterColor(WHITE);
			printf("��");
		}
	}									//��������� �ι�°��

	if (board[18][0] == 0)	//��������°��
	{
		printf("�� ");
	}
	else if (board[18][0] == 1)
	{
		LetterColor(BLACK);
		printf("��");
	}
	else if (board[18][0] == -1)
	{
		LetterColor(WHITE);
		printf("��");
	}
	for (int i = 1; i < 18; i++)
	{
		if (board[18][i] == 0)
		{
			printf("�� ");
		}
	}
	if (board[18][18] == 0)	
	{
		printf("�� 18 -- y��ǥ\n");
	}
	else if (board[18][18] == 1)
	{
		LetterColor(BLACK);
		printf("��");
	}
	else if (board[18][18] == -1)
	{
		LetterColor(WHITE);
		printf("��");
	}								//��������� ��������°��
}
int main(void) {
	Board();

	return 0;
}