
#include <stdio.h>

int change = 0;
int win = 0;


void turnprint(int(*board)[19])   // ���ʰ��� & ���� ��ǥ�� ����ϴ� �Լ�.
{
	int selectX = 0, selectY = 0;
	int x = 0;
	int y = 0;
	//�̴ϰ��� �¸��� == ������(1) 
	//A ==1  B==0
	if (win == 1)  //���� �¸��ڰ� A�� ��
	{
		if (change == 1)
		{
			printf("A�� �����Դϴ�.\n");
			printf("X��ǥ�� Y��ǥ�� �Է��Ͻÿ�:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = 1;
			change = 0;
		}
		else if (change == 0)
		{
			printf("B�� �����Դϴ�.\n");
			printf("X��ǥ�� Y��ǥ�� �Է��Ͻÿ�:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = -1;
			change = 1;
		}
	}
	else if (win == 0)  //���� �¸��ڰ� B�� ��
	{
		if (change == 0)
		{
			printf("B�� �����Դϴ�.\n");
			printf("X��ǥ�� Y��ǥ�� �Է��Ͻÿ�:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = 1;
			change = 1;
		}
		else if (change == 1)
		{
			printf("A�� �����Դϴ�.\n");
			printf("X��ǥ�� Y��ǥ�� �Է��Ͻÿ�:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = -1;
			change = 0;
		}
	}
}


