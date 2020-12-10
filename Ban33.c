#include <stdio.h>
#include <Windows.h>

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };
int change = 0;
int win = 0;

// x, y를 중심으로 하는 7*7 좌표를 받아서 33인지 확인하는 함수
int check_33(int x, int y)
{
    // 가로, 세로, 상향대각선, 하향대각선 방향으로 33이 존재하는지 확인하고, 총합이 2를 넘으면 33규칙에 어긋남을 알림.
    // 정상시 0을, 33규칙 위반시 1을 반환

    int count = 0;
    // 가로체크. 
    if ((board[y][x - 4] == 0 && board[y][x - 3] == 1 && board[y][x - 2] == 0 && board[y][x - 1] == 1 && board[y][x + 1] == 0) ||
        (board[y][x - 4] == 0 && board[y][x - 3] == 1 && board[y][x - 2] == 1 && board[y][x - 1] == 0 && board[y][x + 1] == 0) ||
        (board[y][x - 4] == 0 && board[y][x - 3] == 0 && board[y][x - 2] == 1 && board[y][x - 1] == 1 && board[y][x + 1] == 0) ||

        (board[y][x - 3] == 0 && board[y][x - 2] == 1 && board[y][x - 1] == 0 && board[y][x + 1] == 1 && board[y][x + 2] == 0) ||
        (board[y][x - 3] == 0 && board[y][x - 2] == 1 && board[y][x - 1] == 1 && board[y][x + 1] == 0 && board[y][x + 2] == 0) ||
        (board[y][x - 3] == 0 && board[y][x - 2] == 0 && board[y][x - 1] == 1 && board[y][x + 1] == 1 && board[y][x + 2] == 0) ||

        (board[y][x - 2] == 0 && board[y][x - 1] == 1 && board[y][x + 1] == 0 && board[y][x + 2] == 1 && board[y][x + 1] == 0) ||
        (board[y][x - 2] == 0 && board[y][x - 1] == 1 && board[y][x + 1] == 1 && board[y][x + 2] == 0 && board[y][x + 1] == 0) ||
        (board[y][x - 2] == 0 && board[y][x - 1] == 0 && board[y][x + 1] == 1 && board[y][x + 2] == 1 && board[y][x + 1] == 0) ||

        (board[y][x - 1] == 0 && board[y][x + 1] == 1 && board[y][x + 2] == 0 && board[y][x + 3] == 1 && board[y][x + 4] == 0) ||
        (board[y][x - 1] == 0 && board[y][x + 1] == 1 && board[y][x + 2] == 1 && board[y][x + 3] == 0 && board[y][x + 4] == 0) ||
        (board[y][x - 1] == 0 && board[y][x + 1] == 0 && board[y][x + 2] == 1 && board[y][x + 3] == 1 && board[y][x + 4] == 0))



        count++;
    // 세로체크. 
    if ((board[y - 4][x] == 0 && board[y - 3][x] == 1 && board[y - 2][x] == 0 && board[y - 1][x] == 1 && board[y + 1][x] == 0) ||
        (board[y - 4][x] == 0 && board[y - 3][x] == 1 && board[y - 2][x] == 1 && board[y - 1][x] == 0 && board[y + 1][x] == 0) ||
        (board[y - 4][x] == 0 && board[y - 3][x] == 0 && board[y - 2][x] == 1 && board[y - 1][x] == 1 && board[y + 1][x] == 0) ||

        (board[y - 3][x] == 0 && board[y - 2][x] == 1 && board[y - 1][x] == 0 && board[y + 1][x] == 1 && board[y + 2][x] == 0) ||
        (board[y - 3][x] == 0 && board[y - 2][x] == 1 && board[y - 1][x] == 1 && board[y + 1][x] == 0 && board[y + 2][x] == 0) ||
        (board[y - 3][x] == 0 && board[y - 2][x] == 0 && board[y - 1][x] == 1 && board[y + 1][x] == 1 && board[y + 2][x] == 0) ||

        (board[y - 2][x] == 0 && board[y - 1][x] == 1 && board[y + 1][x] == 0 && board[y + 2][x] == 1 && board[y + 3][x] == 0) ||
        (board[y - 2][x] == 0 && board[y - 1][x] == 1 && board[y + 1][x] == 1 && board[y + 2][x] == 0 && board[y + 3][x] == 0) ||
        (board[y - 2][x] == 0 && board[y - 1][x] == 0 && board[y + 1][x] == 1 && board[y + 2][x] == 1 && board[y + 3][x] == 0) ||

        (board[y - 1][x] == 0 && board[y + 1][x] == 1 && board[y + 2][x] == 0 && board[y + 3][x] == 1 && board[y + 4][x] == 0) ||
        (board[y - 1][x] == 0 && board[y + 1][x] == 1 && board[y + 2][x] == 1 && board[y + 3][x] == 0 && board[y + 4][x] == 0) ||
        (board[y - 1][x] == 0 && board[y + 1][x] == 0 && board[y + 2][x] == 1 && board[y + 3][x] == 1 && board[y + 4][x] == 0))

        count++;
    // 대각선체크. (++)
    if ((board[y - 4][x - 4] == 0 && board[y - 3][x - 3] == 1 && board[y - 2][x - 2] == 0 && board[y - 1][x - 1] == 1 && board[y + 1][x + 1] == 0) ||
        (board[y - 4][x - 4] == 0 && board[y - 3][x - 3] == 1 && board[y - 2][x - 2] == 1 && board[y - 1][x - 1] == 0 && board[y + 1][x + 1] == 0) ||
        (board[y - 4][x - 4] == 0 && board[y - 3][x - 3] == 0 && board[y - 2][x - 2] == 1 && board[y - 1][x - 1] == 1 && board[y + 1][x + 1] == 0) ||

        (board[y - 3][x - 3] == 0 && board[y - 2][x - 2] == 1 && board[y - 1][x - 1] == 0 && board[y + 1][x + 1] == 1 && board[y + 2][x + 2] == 0) ||
        (board[y - 3][x - 3] == 0 && board[y - 2][x - 2] == 1 && board[y - 1][x - 1] == 1 && board[y + 1][x + 1] == 0 && board[y + 2][x + 2] == 0) ||
        (board[y - 3][x - 3] == 0 && board[y - 2][x - 2] == 0 && board[y - 1][x - 1] == 1 && board[y + 1][x + 1] == 1 && board[y + 2][x + 2] == 0) ||

        (board[y - 2][x - 2] == 0 && board[y - 1][x - 1] == 1 && board[y + 1][x + 1] == 0 && board[y + 2][x + 2] == 1 && board[y + 3][x + 3] == 0) ||
        (board[y - 2][x - 2] == 0 && board[y - 1][x - 1] == 1 && board[y + 1][x + 1] == 1 && board[y + 2][x + 2] == 0 && board[y + 3][x + 3] == 0) ||
        (board[y - 2][x - 2] == 0 && board[y - 1][x - 1] == 0 && board[y + 1][x + 1] == 1 && board[y + 2][x + 2] == 1 && board[y + 3][x + 3] == 0) ||

        (board[y - 1][x - 1] == 0 && board[y + 1][x + 1] == 1 && board[y + 2][x + 2] == 0 && board[y + 3][x + 3] == 1 && board[y + 4][x + 4] == 0) ||
        (board[y - 1][x - 1] == 0 && board[y + 1][x + 1] == 1 && board[y + 2][x + 2] == 1 && board[y + 3][x + 3] == 0 && board[y + 4][x + 4] == 0) ||
        (board[y - 1][x - 1] == 0 && board[y + 1][x + 1] == 0 && board[y + 2][x + 2] == 1 && board[y + 3][x + 3] == 1 && board[y + 4][x + 4] == 0))

        count++;
    // 반대 대각선체크. (+-)

    if ((board[y + 4][x - 4] == 0 && board[y + 3][x - 3] == 1 && board[y + 2][x - 2] == 0 && board[y + 1][x - 1] == 1 && board[y - 1][x + 1] == 0) ||
        (board[y + 4][x - 4] == 0 && board[y + 3][x - 3] == 1 && board[y + 2][x - 2] == 1 && board[y + 1][x - 1] == 0 && board[y - 1][x + 1] == 0) ||
        (board[y + 4][x - 4] == 0 && board[y + 3][x - 3] == 0 && board[y + 2][x - 2] == 1 && board[y + 1][x - 1] == 1 && board[y - 1][x + 1] == 0) ||

        (board[y + 3][x - 3] == 0 && board[y + 2][x - 2] == 1 && board[y + 1][x - 1] == 0 && board[y - 1][x + 1] == 1 && board[y - 2][x + 2] == 0) ||
        (board[y + 3][x - 3] == 0 && board[y + 2][x - 2] == 1 && board[y + 1][x - 1] == 1 && board[y - 1][x + 1] == 0 && board[y - 2][x + 2] == 0) ||
        (board[y + 3][x - 3] == 0 && board[y + 2][x - 2] == 0 && board[y + 1][x - 1] == 1 && board[y - 1][x + 1] == 1 && board[y - 2][x + 2] == 0) ||

        (board[y + 2][x - 2] == 0 && board[y + 1][x - 1] == 1 && board[y - 1][x + 1] == 0 && board[y - 2][x + 2] == 1 && board[y - 3][x + 3] == 0) ||
        (board[y + 2][x - 2] == 0 && board[y + 1][x - 1] == 1 && board[y - 1][x + 1] == 1 && board[y - 2][x + 2] == 0 && board[y - 3][x + 3] == 0) ||
        (board[y + 2][x - 2] == 0 && board[y + 1][x - 1] == 0 && board[y - 1][x + 1] == 1 && board[y - 2][x + 2] == 1 && board[y - 3][x + 3] == 0) ||

        (board[y + 1][x - 1] == 0 && board[y - 1][x + 1] == 1 && board[y - 2][x + 2] == 0 && board[y - 3][x + 3] == 1 && board[y - 4][x + 4] == 0) ||
        (board[y + 1][x - 1] == 0 && board[y - 1][x + 1] == 1 && board[y - 2][x + 2] == 1 && board[y - 3][x + 3] == 0 && board[y - 4][x + 4] == 0) ||
        (board[y + 1][x - 1] == 0 && board[y - 1][x + 1] == 0 && board[y - 2][x + 2] == 1 && board[y - 3][x + 3] == 1 && board[y - 4][x + 4] == 0))
        count++;

    if (count > 1)
        return 1;
    else return 0;
}


int main(void) {
	while (1)
	{
		Board();
		printf("\n\n");
		turnprint(board);
		if (game_end(board) == 1)
			break;
		system("Cls");
	}
	system("Cls");
	Board();
	}
