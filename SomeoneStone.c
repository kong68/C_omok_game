#include <stdio.h>

void SomeoneStone(int Stone)
{
	int X = 0, Y = 0, Value;

	printf("빼고싶은 상대 수의 좌표를 입력하세요. : ");
	scanf_s("%d %d", &X, &Y);
	Value = board[X][Y];

	while (1)
	{
		if (Value != Stone)			//상대방의 돌과 색이 다르면 상대방의 수를 뺄 수 있습니다.
		{
			board[X][Y] = 0;
			Board();
			break;
		}
		else if ((Value == Stone) || (Value == 0))			//상대방의 돌과 색이 같으면 좌표를 다시 선택할 수 있습니다.
		{
			printf("자신의 돌을 선택하거나 빈 공간입니다. 다시 입력해주세요. : ");
			scanf_s("%d %d", &X, &Y);
			Value = board[X][Y];
		}
	}
}

int main(void) 
{
	SomeoneStone(StoneColor);		//자신의 돌색을 입력시켜줍니다.
	return 0;
}