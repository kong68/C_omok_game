#include <stdio.h>
#include <Windows.h>

void ReturnStone(int Win, int Stone)
{
	int X = 0, Y = 0, Value;

	printf("�����⸦ ����� ��ǥ�� �Է��ϼ���. : ");
	scanf_s("%d %d", &X, &Y);
	Value = board[X][Y];
	system("Cls");

	while (1)
	{
		if (Stone == Value)		//�����ѵ��� ������� ������ ������ �� ���� ���ְ� �ٽ� �� �� �ֽ��ϴ�.
		{
			board[X][Y] = 0;
			Board();

			
			printf("���� �ٽ� ���� ��ǥ�� �Է��Ͻÿ�. : ");
			scanf("%d %d", &X, &Y);
			board[X][Y] = Value;

			system("Cls");
			Board();
			break;
		}
		else if (Stone != Value)
		{
			printf("������ ���� �ڽ��� �� ���� �ٸ��ϴ�. �ٽ� �Է����ּ���. : ");
			scanf_s("%d %d", &X, &Y);
			Value = board[X][Y];
		}
	}
}

int main(void)
{
	ReturnStone(MiniGame, StoneColor);		//�̴ϰ��ӿ��� ��ȯ�� 1 �Ǵ� 0�� �Է��� �޽��ϴ�. StoneColor�� �����⸦ ����ϴ� ������� �����Դϴ�. �����⸦ �Ҷ� ������ ���� �������� �ʰ� �����ϱ� �����Դϴ�.
	return 0;
}