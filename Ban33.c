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

    if (count > 1) {
        printf("(%d, %d)는 33규칙에 위반되는 자리입니다.\n", x, y);
        return 1;
    }
    else return 0;
}


int main(void)
{
	// 33예제 1
	// ============================================================
	board[11][2] = 1;
	board[12][4] = 1;
	board[12][5] = 1;
	board[14][2] = 1;

	Board();

    // (2, 12) 확인
	if (check_33(2,12) == 1) {
		printf("2, 12는 33규칙에 위반되는 자리입니다.\n");
	}
	else {
		printf("2, 12는 33규칙에 위반되지 않습니다.\n");
	}
	board[11][2] = 0;
	board[12][4] = 0;
	board[12][5] = 0;
	board[14][2] = 0;
	// ============================================================


    // 33예제 2
    // ============================================================
    board[4][2] = 1;
    board[5][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;

    Board();

    if (check_33(2,2) == 1) {
        printf("2, 2는 33규칙에 위반되는 자리입니다.\n");
    }
    else {
        printf("2, 2는 33규칙에 위반되지 않습니다.\n");
    }
    board[4][2] = 0;
    board[5][2] = 0;
    board[3][3] = 0;
    board[4][4] = 0;
    // ============================================================


	// 33예제 3
	// ============================================================
	board[13][13] = 1;
	board[14][14] = 1;
	board[14][18] = 1;
	board[15][17] = 1;

	Board();

    if (check_33(16, 16) == 1) {
		printf("16, 16는 33규칙에 위반되는 자리입니다.\n");
	}
	else {
		printf("16, 16는 33규칙에 위반되지 않습니다.\n");
	}
	// ============================================================

}
