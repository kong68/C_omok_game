#include <stdio.h>
#include <Windows.h>

void ReturnStone(int Win, int Stone)
{
	int X = 0, Y = 0, Value;

	printf("무르기를 사용할 좌표를 입력하세요. : ");
	scanf_s("%d %d", &X, &Y);
	Value = board[X][Y];
	system("Cls");

	while (1)
	{
		if (Stone == Value)		//선택한돌과 사용자의 돌색이 같으면 그 돌을 없애고 다시 둘 수 있습니다.
		{
			board[X][Y] = 0;
			Board();

			
			printf("수를 다시 놔둘 좌표를 입력하시오. : ");
			scanf("%d %d", &X, &Y);
			board[X][Y] = Value;

			system("Cls");
			Board();
			break;
		}
		else if (Stone != Value)
		{
			printf("선택한 돌이 자신의 돌 색과 다름니다. 다시 입력해주세요. : ");
			scanf_s("%d %d", &X, &Y);
			Value = board[X][Y];
		}
	}
}

int main(void)
{
	ReturnStone(MiniGame, StoneColor);		//미니게임에서 반환된 1 또는 0을 입력을 받습니다. StoneColor은 무르기를 사용하는 사용자의 돌색입니다. 무르기를 할때 상대방의 돌을 선택하지 않게 방지하기 위함입니다.
	return 0;
}