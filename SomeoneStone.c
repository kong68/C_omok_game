#include <stdio.h>

void SomeoneStone(int Stone)
{
	int X = 0, Y = 0, Value;

	printf("������� ��� ���� ��ǥ�� �Է��ϼ���. : ");
	scanf_s("%d %d", &X, &Y);
	Value = board[X][Y];

	while (1)
	{
		if (Value != Stone)			//������ ���� ���� �ٸ��� ������ ���� �� �� �ֽ��ϴ�.
		{
			board[X][Y] = 0;
			Board();
			break;
		}
		else if ((Value == Stone) || (Value == 0))			//������ ���� ���� ������ ��ǥ�� �ٽ� ������ �� �ֽ��ϴ�.
		{
			printf("�ڽ��� ���� �����ϰų� �� �����Դϴ�. �ٽ� �Է����ּ���. : ");
			scanf_s("%d %d", &X, &Y);
			Value = board[X][Y];
		}
	}
}

int main(void) 
{
	SomeoneStone(StoneColor);		//�ڽ��� ������ �Է½����ݴϴ�.
	return 0;
}