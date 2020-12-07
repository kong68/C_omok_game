#include <stdio.h>
#include <Windows.h>

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };
int change = 0;
int win = 0;

// 열린4를 만드는 함수. checkOpen4와 양식 같음
int makeOpen4(int locX, int locY, int dir) {
	int numVoid = 0;
	int swit;
	switch (dir) {
	case 0:
		for (swit = 0; swit < 4; swit++) {
			if (board[locY][locX + swit] == 0) {
				if (numVoid < 2) {
					board[locY][locX + swit] == 1 - 2 * change;
					numVoid++;
				}
				else
					return -1;
			}
		}
		break;
	case 1:
		for (int ii = 0; ii < 4; ii++) {
			if (board[locY + swit][locX] == 0) {
				if (numVoid < 2) {
					board[locY + swit][locX] == 1 - 2 * change;
					numVoid++;
				}
				else
					return -1;
			}

		}
		break;
	case 2:
		for (int ii = 0; ii < 4; ii++) {
			if (board[locY + swit][locX + swit] == 0) {
				if (numVoid < 2) {
					board[locY + swit][locX + swit] == 1 - 2 * change;
					numVoid++;
				}
				else
					return -1;
			}
		}
		break;
	case 3:
		for (int ii = 0; ii < 4; ii++) {
			if (board[locY - swit][locX + swit] == 0) {
				if (numVoid < 2) {
					board[locY][locX + swit] == 1 - 2 * change;
					numVoid++;
				}
				else
					return -1;
			}
		}
		break;
	default:
		break;
	}
	return 1;
}

// (_x, _y)를 시작점으로 하는 _dir 방향의 열린4의 존재여부를 0/1로 반환하는 함수
// 0, 1, 2, 3 순으로 각각 가로, 세로, 상향, 하향이다.
int checkOpen4(int _x, int _y, int _dir)
{
	int result, Col;
	int blankXl, blankYl, blankXh, blankYh;				// 왼쪽/위쪽/오른쪽/아래쪽 벽과의 거리 확인변수
	int blankDul, blankDuh, blankDdl, blankDdh;			// 우하단, 우상단 방향으로의 대각선 거리 확인변수

	result = 0;

	if (change == 1) {
		Col = -1;
	}
	if (change == 0) {
		Col = 1;
	}

	switch (_x) {
	case 0:
		blankXl = 0;
		blankXh = 2;
		break;
	case 1:
		blankXl = 1;
		blankXh = 2;
		break;
	case 12:
		blankXl = 2;
		blankXh = 1;
		break;
	case 13:
		blankXl = 2;
		blankXh = 0;
		break;
	default:
		blankXl = 2;
		blankXh = 2;
		break;
	};

	switch (_y) {
	case 0:
		blankYl = 0;
		blankYh = 2;
		break;
	case 1:
		blankYl = 1;
		blankYh = 2;
		break;
	case 12:
		blankYl = 2;
		blankYh = 1;
		break;
	case 13:
		blankYl = 2;
		blankYh = 0;
		break;
	default:
		blankYl = 2;
		blankYh = 2;
		break;
	};

	// Dl(Dh)는 Xl,Yl(Xh,Yh) 중 작은 쪽을 따른다
	blankDdl = (blankXl > blankYh) ? blankYh : blankXl;
	blankDdh = (blankXh > blankYl) ? blankYl : blankXh;
	blankDul = (blankXl > blankYl) ? blankYl : blankXl;
	blankDuh = (blankXh > blankYh) ? blankYh : blankXh;

	// l, h 값에 따라 판독은 다음과 같이 일어난다.
	//		0: 판독할 값이 없으므로 판독하지 않는다
	//		1: [1]거리의 돌이 Color과 다른 값일 경우 열린4다.
	//		2: [1]거리의 돌이 공백이면, [2]거리의 돌이 Color이 아닌경우 열린4다. [1]거리의 돌이 Color의 역인 경우, 열린4다.

	switch (_dir) {
		// 1. 가로 판독 (시작점 _y = 0~ 13)
	case 0:
		printf("가로 판독 시작...\n");
		printf("(%d, %d) ~ (%d, %d)를 탐색합니다.\n", _x, _y, _x + 5, _y);
		if (_x <= 13) {
			if (board[_y][_x] == 0 && board[_y][_x + 1] == Col && board[_y][_x + 2] == Col && board[_y][_x + 3] == Col && board[_y][_x + 4] == Col && board[_y][_x + 5] == 0) {
				if (blankXl == 2 && blankXh != 2) {
					if (blankXh == 0) {
						if (board[_y][_x - 1] == -Color || (board[_y][_x - 1] == 0 && board[_y][_x - 2] != Color)) {
							result++;
						}
					}
					else if (blankXh == 1) {
						if (board[_y][_x + 6] != Color) {
							if (board[_y][_x - 1] == -Color || (board[_y][_x - 1] == 0 && board[_y][_x - 2] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankXh == 2 && blankXl != 2) {
					if (blankXl == 0) {
						if (board[_y][_x + 6] == -Color || (board[_y][_x + 6] == 0 && board[_y][_x + 7] != Color)) {
							result++;
						}
					}
					else if (blankXl == 1) {
						if (board[_y][_x - 1] != Color) {
							if (board[_y][_x + 6] == -Color || (board[_y][_x + 6] == 0 && board[_y][_x + 7] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankXl == 2 && blankXh == 2) {
					if (board[_y][_x + 6] == -Color || (board[_y][_x + 6] == 0 && board[_y][_x + 7] != Color)) {
						if (board[_y][_x - 1] == -Color || (board[_y][_x - 1] == 0 && board[_y][_x - 2] != Color)) {
							result++;
						}
					}
				}
			}
		}
		if (result > 0)
			printf("가로방향 열린4 찾음(%d%d)\n", blankXl, blankXh);
		break;

		// 2. 세로 판독 (시작점 _x = 0 ~ 13)
	case 1:
		printf("세로 판독 시작...\n");
		printf("(%d, %d) ~ (%d, %d)를 탐색합니다.\n", _x, _y, _x, _y+5);
		if (_y <= 13) {
			if (board[_y][_x] == 0 && board[_y + 1][_x] == Col && board[_y + 2][_x] == Col && board[_y + 3][_x] == Col && board[_y + 4][_x] == Col && board[_y + 5][_x] == 0) {
				if (blankYl == 2 && blankYh != 2) {
					if (blankYh == 0) {
						if (board[_y - 1][_x] == -Color || (board[_y - 2][_x] == 0 && board[_y - 2][_x] != Color)) {
							result++;
						}
					}
					else if (blankYh == 1) {
						if (board[_y + 6][_x] != Color) {
							if (board[_y - 1][_x] == -Color || (board[_y - 1][_x] == 0 && board[_y - 2][_x] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankYh == 2 && blankYl != 2) {
					if (blankYl == 0) {
						if (board[_y + 6][_x] == -Color || (board[_y + 6][_x] == 0 && board[_y + 7][_x] != Color)) {
							result++;
						}
					}
					else if (blankYl == 1) {
						if (board[_y - 1][_x] != Color) {
							if (board[_y + 6][_x] == -Color || (board[_y + 6][_x] == 0 && board[_y + 7][_x] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankYl == 2 && blankYh == 2) {
					if (board[_y + 6][_x] == -Color || (board[_y + 6][_x] == 0 && board[_y + 7][_x] != Color)) {
						if (board[_y - 1][_x] == -Color || (board[_y - 1][_x] == 0 && board[_y - 2][_x] != Color)) {
							result++;
						}
					}
				}
			}
		}
		if (result > 0)
			printf("세로방향 열린4 찾음(%d%d)\n", blankYl, blankYh);
		break;

		// 3. 상향대각선 판독 (시작점 (_x, _y)에 대해서 _x = 0 ~ 12, _y = 0 ~ 12)
	case 2:
		printf("상향 대각선 판독 시작...\n");
		printf("(%d, %d) ~ (%d, %d)를 탐색합니다.\n", _x, _y, _x + 5, _y + 5);
		if (_x <= 13) {
			if (board[_y][_x] == 0 && board[_y + 1][_x + 1] == Col && board[_y + 2][_x + 2] == Col && board[_y + 3][_x + 3] == Col && board[_y + 4][_x + 4] == Col && board[_y + 5][_x + 5] == 0) {
				if (blankDul == 2 && blankDuh != 2) {
					if (blankDuh == 0) {
						if (board[_y - 1][_x - 1] == -Color || (board[_y - 1][_x - 1] == 0 && board[_y - 2][_x - 2] != Color)) {
							result++;
						}
					}
					else if (blankDuh == 1) {
						if (board[_y + 6][_x + 6] != Color) {
							if (board[_y - 1][_x - 1] == -Color || (board[_y - 1][_x - 1] == 0 && board[_y - 2][_x - 2] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankDuh == 2 && blankDul != 2) {
					if (blankDul == 0) {
						if (board[_y + 6][_x + 6] == -Color || (board[_y + 6][_x + 6] == 0 && board[_y + 7][_x + 7] != Color)) {
							result++;
						}
					}
					else if (blankDul == 1) {
						if (board[_y - 1][_x - 1] != Color) {
							if (board[_y + 6][_x + 6] == -Color || (board[_y + 6][_x + 6] == 0 && board[_y + 7][_x + 7] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankDul == 2 && blankDuh == 2) {
					if (board[_y + 6][_x + 6] == -Color || (board[_y + 6][_x + 6] == 0 && board[_y + 7][_x + 7] != Color)) {
						if (board[_y - 1][_x - 1] == -Color || (board[_y - 1][_x - 1] == 0 && board[_y - 2][_x - 2] != Color)) {
							result++;
						}
					}
				}
			}
		}
		if (result > 0)
			printf("상향 대각선 방향 열린4 찾음(%d%d)\n", blankDul, blankDuh);
		break;

		// 4. 하향대각선 판독 (시작점 (_x, _y)에 대해서 _x = 0 ~ 12, _y = 0 ~ 12)
	case 3:
		printf("하향 대각선 판독 시작...\n");
		printf("(%d, %d) ~ (%d, %d)를 탐색합니다.\n", _x, _y, _x + 5, _y + 5);
		if (_x <= 13) {
			if (board[_y][_x] == 0 && board[_y - 1][_x + 1] == Col && board[_y - 2][_x + 2] == Col && board[_y - 3][_x + 3] == Col && board[_y - 4][_x + 4] == Col && board[_y - 5][_x + 5] == 0) {
				if (blankDdl == 2 && blankDdh != 2) {
					if (blankDdh == 0) {
						if (board[_y + 1][_x - 1] == -Color || (board[_y + 1][_x - 1] == 0 && board[_y + 2][_x - 2] != Color)) {
							result++;
						}
					}
					else if (blankDdh == 1) {
						if (board[_y - 6][_x + 6] != Color) {
							if (board[_y + 1][_x - 1] == -Color || (board[_y + 1][_x - 1] == 0 && board[_y + 2][_x - 2] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankDdh == 2 && blankDdl != 2) {
					if (blankDul == 0) {
						if (board[_y - 6][_x + 6] == -Color || (board[_y - 6][_x + 6] == 0 && board[_y - 7][_x + 7] != Color)) {
							result++;
						}
					}
					else if (blankXl == 1) {
						if (board[_y + 1][_x - 1] != Color) {
							if (board[_y - 6][_x + 6] == -Color || (board[_y - 6][_x + 6] == 0 && board[_y - 7][_x + 7] != Color)) {
								result++;
							}
						}
					}
				}
				if (blankXl == 2 && blankXh == 2) {
					if (board[_y - 6][_x + 6] == -Color || (board[_y - 6][_x + 6] == 0 && board[_y - 7][_x + 7] != Color)) {
						if (board[_y + 1][_x - 1] == -Color || (board[_y + 1][_x - 1] == 0 && board[_y + 2][_x - 2] != Color)) {
							result++;
						}
					}
				}
			}
		}
		if (result > 0)
			printf("하향 대각선 방향 열린4 찾음(%d%d)\n", blankDdl, blankDdh);
		break;

	default:
		printf("올바르지 않은 판독 지시입니다.\n");
		result--;
	}
	return result;
}

// 좌표와 사용자의 색을 받아서 33규칙에 어긋나면 금지하는 함수
int ban33 (int _x, int _y) {
    int num3 = 0;  // 열린 3의 개수를 받는 변수
	int temp = board[_y][_x];		// (_x, _y)의 자료값을 임시 저장하는 변수
	int Xl, Yl, Xh, Yh;				// 왼쪽/위쪽/오른쪽/아래쪽 벽과의 거리 확인변수
	int Dul, Duh, Ddl, Ddh;			// 우하단, 우상단 방향으로의 대각선 거리 확인변수
	int temploc[6] = { 0 };			// 6개 좌표의 값을 임시 저장하는 변수

	// (_x, _y)의 값을 현재 플레이어의 값으로 변경
	if (change == 0)
		board[_y][_x] = 1;	
	if (change == 1)
		board[_y][_x] = -1;

	/*
    // 열린3: 한 수를 더 두어서 열린4를 만들 수 있다.
    // 열린4: 네 돌이 연속으로 있고, [다른돌/벽/빈칸+같은색돌]과 1칸 이상의 공백을 가진다. 따라서 열린4는 [공/돌/돌/돌/돌/공]으로 6의 크기를 가진다.
	// _x, _y에 수를 둘 때 열린3이 완성 된다면, 하나의 수를 더 두어서 [돌돌돌돌]이 완성되어야 한다.
	// _x, _y를 기준으로 총 4칸 이전까지 체크하여 공x돌돌, 공돌x돌, 공돌돌x, x공돌돌, 돌공x돌, 돌공돌x, x돌공돌, 돌x공돌, 돌돌공x, x돌돌공, 돌x돌공, 돌돌x공 중 하나인지 확인해야한다.
	// 위의 12 케이스 중 하나에 해당하면, "공"에 해당하는 부분을 돌로 임시 변경하여 checkOpen4를 호출한다. 호출 뒤에는 원래값으로 초기화

    // 각 방향별로 확인법

    // 1. 방향별로 (X-4 또는 벽(0)) ~ (X-1 또는 벽-5(13))동안 checkOpen4(i, j, loc) 실행. 큰쪽을 따른다.
	*/
	Xl = (_x - 4 > 0) ? _x - 4 : 0;
	Xh = (_x - 1 > 13) ? _x - 1 : 13;
	Yl = (_y - 4 > 0) ? _y - 4 : 0;
	Yh = (_y - 1 > 13) ? _y - 1 : 13;

	// Dl(Dh)는 Xl,Yl(Xh,Yh) 중 작은 쪽을 따른다
	Dul = (Xl > Yl) ? Yl : Xl;
	Duh = (Xh > Yh) ? Yh : Xh;

	Ddl = (Xl > Yh) ? Yh : Xl;
	Ddh = (Xh > Yl) ? Yl : Xh;

	if ((_x >= 0 && _x <= 18) && (_y >= 0 && _y <= 18)) {
		// 1. 하향 대각선 방향 열린3 확인 (+, -)
		for (int i = 0; i < Ddl + Ddh; i++) {
			// 열린 4를 만들기 위해서 값을 임시저장
			for (int j = 0; j < 6; j++) {
				temploc[j] = board[_y + Dul - i - j][_x + Dul - i + j];
			}

			// 열린 4로 만들 수 있으면, 열린4인지 판정
			if (makeOpen4(_x - Dul + i, _y + Dul - i, 0) > 0)
				if (checkOpen4(_x - Dul + i, _y + Dul - i, 0) > 0)
					num3++;
			// 원상복귀
			for (int j = 0; j < 6; j++) {
				board[_y + Dul - i - j][_x + Dul - i + j] = temploc[j];
			}
		}

		// 2. 상향 대각선 방향 열린3 확인 (+, +)
		for (int i = 0; i < Dul + Duh; i++) {
			// 열린 4를 만들기 위해서 값을 임시저장
			for (int j = 0; j < 6; j++) {
				temploc[j] = board[_y + Dul - i - j][_x + Dul + i + j];
			}

			// 열린 4로 만들 수 있으면, 열린4인지 판정
			if (makeOpen4(_x - Dul + i, _y - Dul + i, 0) > 0)
				if (checkOpen4(_x - Dul + i, _y - Dul + i, 0) > 0)
					num3++;
			// 원상복귀
			for (int j = 0; j < 6; j++) {
				board[_y + Dul - i - j][_x + Dul + i + j] = temploc[j];
			}
			
		}

		// 3. 가로방향 열린3 확인
		for (int i = 0; i < Xl + Xh; i++) {
			for (int j = 0; j < 6; j++) {
				temploc[j] = board[_y][_x - Xl + i + j];
			}

			// 열린 4로 만들 수 있으면, 열린4인지 판정
			if (makeOpen4(_x - Xl + i, _y, 0) > 0)
				if (checkOpen4(_x - i, _y, 0) > 0)
					num3++;
			// 원상복귀
			for (int j = 0; j < 6; j++) {
				board[_y][_x + Xl + i + j] = temploc[j];
			}
		}

		// 4. 세로방향 열린3 확인
		for (int i = 0; i < Yl + Yh; i++) {
			for (int j = 0; j < 6; j++) {
				temploc[j] = board[_y - Yl + i + j][_x];
			}

			// 열린 4로 만들 수 있으면, 열린4인지 판정
			if (makeOpen4(_x, _y - Yl + i, 0) > 0)
				if (checkOpen4(_x, _y - i, 0) > 0)
					num3++;
			// 원상복귀
			for (int j = 0; j < 6; j++) {
				board[_y - Yl + i + j][_x] = temploc[j];
			}
		}
	}

	// num3이 2 이상일 경우 원상복귀 시키고 -1 반환
    if (num3 > 1) {
		board[_y][_x] = temp;
        return -1;
    } else {
        return 0;
    }
    
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
