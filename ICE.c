#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define Turn 31

int BaskinRobbins(void)
{
	srand((unsigned) time(NULL));
	//a�� ������ �����ִ� ������ �����ϴ� �����Դϴ�. MaxCnt�� 1~3������ �Է¹��� ���� �����մϴ�. Value�� 1~31���� ������Ű�鼭 ������ݴϴ�.
	int a, MaxCnt, Value; 
	char AB[2] = { 'A', 'B' };
	
	Value = 1;
	a = rand() % 2;		//a�� 0�̸� A�� ��, 1�̸� B�� ���̴�.

	printf("������ ����Ų���31�Դϴ�.\n");
	printf("\n\t\t<--Baskin_Rabins_31-->\n\n"
		" ====================[How To Play]====================\n"
		" [1] 1���� �����ؼ� 31���� �����ư��� ���ڸ� �θ���.\n"
		" [2] �ѹ��� �ִ� 3������ ���ӵ� ���ڸ� ���� �� �ִ�.\n"
		" [3] 31�� ���ϴ� �÷��̾ ���ӿ��� �й��Ѵ�.\n"
		" =====================================================\n\n");
	printf("	[������ �������� %c�� ���� �Դϴ�.]\n", AB[a]);
	printf("     ���� �Է��� 1~3���� �Է��� �� �ֽ��ϴ�.\n\n");

	puts("");

	printf("	Enter�� ������ ������ ���۵˴ϴ�.");
	
	while (1)
	{
		int key;
		if (_kbhit()) // ����Ű�� �Է¹޾��� �� ���ѷ��� Ż��
		{
			key = _getch();
			if (key == 13)
			{
				system("cls");
				break;
			}
		}
	}

	while (1)
	{
		puts("");
		printf("%c�� ���Դϴ�.\n", AB[a]);		
		switch (a)		//������ �ٲ��ִ� �ڵ�
		{
			case 0: {
				++a;
				break;
			}
			case 1: {
				--a;
				break;
			}
		}

		puts("======================================");

		printf("���� ��� �Է��Ͻðڽ��ϱ�? : ");
		scanf_s("%d", &MaxCnt);
		
		if (MaxCnt > 3 || MaxCnt < 0)					//�Է��� ���� 0���� �۰� 3���� ũ�� �ٽ� �Է��ϵ��� �մϴ�.
		{
			while (MaxCnt > 3 || MaxCnt < 0)
			{
				printf("1 ~ 3���� �ٽ� �Է����ּ���. : ");
				scanf_s("%d", &MaxCnt);
			}
		}
			
		printf("�Է¹��� ���� : ");

		for (int i = 0; i < MaxCnt; i++)
		{
			printf("%d ", Value);
			Value++;
			if (Value == Turn + 1)
			{
				break;
			}
		}

		puts("");
		puts("======================================");

		

		if (Value == Turn + 1)
		{
			printf("%c�� �¸��Դϴ�.", AB[a]);
			break;
		}
	}

	if (AB[a] == 'A')
	{
		return 1;
	}
	else if (AB[a] == 'B')
	{
		return 0;
	}

}

int main(void)
{
	printf("%d", BaskinRobbins());
	return 0;
}