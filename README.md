# two-team-fire-extinguisher-
 저희 소화기 팀은 이차원 배열을 응용하여 2인용 오목 게임을 만들기로 하였습니다.
  단순해보일수도 있는 오목게임에 다양한 미니게임을 조합하여 변수를 두어, 더욱 재미있는 게임을 만들고자 합니다.
  미니게임은 게임을 시작할 때 흑백을 정할때와, 무르기를 실행할 때 실행되며, 흥미로운 변수로서 작용할 수 있을 것입니다.
 
 오목의 전체 보드는 다음과 같이 구성되어 있습니다. 
 
 ## board[19][19]
 board[i][j]에는 보드의 (j, i) 좌표에 해당하는 칸의 상태가 적혀있습니다.
 
 board[i][j] =  0: 비어있는 칸입니다.
 board[i][j] =  1: 백돌을 둔 칸입니다.
 board[i][j] = -1: 흑돌을 둔 칸입니다.
 
 ## 메인함수 (main.c)
 
```C
#include <stdio.h>

int board[19][19] = { 0 };

int main(void) {
	printf("  ⓩ①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮ⓐⓑⓒ -- x좌표\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 19; j++)
		{
			if (board[i][j] == 0)
			{
				printf("□");
			}
			else if (board[i][j] == 1)
			{
				printf("○");
			}
			else if (board[i][j] == -1)
			{
				printf("●");
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
				printf("□");
			}
			else if (board[i][j] == 1)
			{
				printf("○");
			}
			else if (board[i][j] == -1)
			{
				printf("●");
			}
		}
		printf("\n");
	}
	printf("|\ny\n좌\n표\n\n");
}
```
