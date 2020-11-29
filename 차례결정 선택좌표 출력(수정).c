
#include <stdio.h>

int change = 0;
int win = 0;


void turnprint(int(*board)[19])   // 차례결정 & 선택 좌표에 출력하는 함수.
{
	int selectX = 0, selectY = 0;
	int x = 0;
	int y = 0;
	//미니게임 승리자 == 검은돌(1) 
	//A ==1  B==0
	if (win == 1)  //선공 승리자가 A일 때
	{
		if (change == 1)
		{
			printf("A의 차례입니다.\n");
			printf("X좌표와 Y좌표를 입력하시오:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = 1;
			change = 0;
		}
		else if (change == 0)
		{
			printf("B의 차례입니다.\n");
			printf("X좌표와 Y좌표를 입력하시오:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = -1;
			change = 1;
		}
	}
	else if (win == 0)  //선공 승리자가 B일 때
	{
		if (change == 0)
		{
			printf("B의 차례입니다.\n");
			printf("X좌표와 Y좌표를 입력하시오:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = 1;
			change = 1;
		}
		else if (change == 1)
		{
			printf("A의 차례입니다.\n");
			printf("X좌표와 Y좌표를 입력하시오:  ");
			scanf_s("%d%d", &selectX, &selectY);
			board[selectY][selectX] = -1;
			change = 0;
		}
	}
}


