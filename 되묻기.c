#include <stdio.h>

int board[19][19] = { 0 };
int change = 0;


// 해당 위치의 값을 반환하는 함수
int checkloc(int _x, int _y) {
	int bcheck = 0;

	// (_x, _y) 위치에 다른 돌이 있는 경우
	if (board[_y][_x] != 0) {
		if (board[_y][_x] == 1) {
			printf("해당 위치에 흑돌이 있습니다.\n");
			bcheck = 1;
		} else if (board[_y][_x] == -1) {
			printf("해당 위치에 백돌이 있습니다.\n");
			bcheck = -1;
		} else {
			printf("알수없는 자료값입니다. (%d, %d)의 값: %d", _x, _y, board[_y][_x]);
		}
	}
	return bcheck;
}


void turnprint(int(*board)[19])   // 차례결정 & 선택 좌표에 출력하는 함수.
{
	int selectX = 0, selectY = 0;

	//미니게임 승리자 == 검은돌(1) 
	//A ==1  B==0
	if (win == 1)  //선공 승리자가 A일 때
	{
		if (change == 1)
		{
			printf("A의 차례입니다.\n");
			// 되물음 함수 삽입
			do {
				printf("X좌표와 Y좌표를 입력하시오:  ");
				scanf_s("%d%d", &selectX, &selectY);
			} while (checkloc(selectX, selectY) != 0);
			board[selectY][selectX] = 1;
			change = 0;
		}
		else if (change == 0)
		{
			printf("B의 차례입니다.\n");
			// 되물음 함수 삽입
			do {
				printf("X좌표와 Y좌표를 입력하시오:  ");
				scanf_s("%d%d", &selectX, &selectY);
			} while (checkloc(selectX, selectY) != 0);
			board[selectY][selectX] = -1;
			change = 1;
		}
	}
	else if (win == 0)  //선공 승리자가 B일 때
	{
		if (change == 0)
		{
			printf("B의 차례입니다.\n");
			// 되물음 함수 삽입
			do {
				printf("X좌표와 Y좌표를 입력하시오:  ");
				scanf_s("%d%d", &selectX, &selectY);
			} while (checkloc(selectX, selectY) != 0);
			board[selectY][selectX] = 1;
			change = 1;
		}
		else if (change == 1)
		{
			printf("A의 차례입니다.\n");
			// 되물음 함수 삽입
			do {
				printf("X좌표와 Y좌표를 입력하시오:  ");
				scanf_s("%d%d", &selectX, &selectY);
			} while (checkloc(selectX, selectY) != 0);
			board[selectY][selectX] = -1;
			change = 0;
		}
	}
}
