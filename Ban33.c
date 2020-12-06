#include <stdio.h>
#include <Windows.h>

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };
int change = 0;
int win = 0;

// (_x, _y)를 시작점으로 하는 _dir 방향의 열린4의 존재여부를 0/1로 반환하는 함수
// 0, 1, 2, 3 순으로 각각 가로, 세로, 상향, 하향이다.
// (_x, _y)를 시작점으로 하는 _dir 방향의 열린4의 존재여부를 0/1로 반환하는 함수
// 0, 1, 2, 3 순으로 각각 가로, 세로, 상향, 하향이다.
int checkOpen4(int _x, int _y, int _dir)
{
	int result = 0;
	int blankXl, blankYl, blankXh, blankYh;				// 왼쪽/위쪽/오른쪽/아래쪽 벽과의 거리 확인변수
	int blankDul, blankDuh, blankDdl, blankDdh;			// 우하단, 우상단 방향으로의 대각선 거리 확인변수


	// 벽과의 거리를 0, 1, 2+로 반환하는 함수.
	//		0: Xl = 0, Xh = 2
	//		1: Xl = 1, Xh = 2
	// 2 ~ 11: Xl = 2, Xh = 2
	//	   12: Xl = 2. Xh = 1
	//	   13: Xl = 2, Xh = 0
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
	
	switch (_dir) {
		// 1. 가로 판독 (시작점 _y = 0~ 13)
	case 0:
		if (_x <= 13) {
			if (board[_y][_x] == 0 && board[_y][_x + 1] == change && board[_y][_x + 2] == change && board[_y][_x + 3] == change && board[_y][_x + 4] == change && board[_y][_x + 5] == 0) {
				if (blankXl == 2 && blankXh != 2) {
					if (blankXh == 0) {
						if (board[_y][_x - 1] != change || (board[_y][_x - 1] == 0 && board[_y][_x - 2] == change)) {
							result++;
						}
					}
					else if (blankXh == 1) {
						if (board[_y][_x + 6] != change) {
							if (board[_y][_x - 1] != change || (board[_y][_x - 1] == 0 && board[_y][_x - 2] == change)) {
								result++;
							}
						}
					}
				}
				if (blankXh == 2 && blankXl != 2) {
					if (blankXl == 0) {
						if (board[_y][_x + 6] != change || (board[_y][_x + 6] == 0 && board[_y][_x + 7] == change)) {
							result++;
						}
					}
					else if (blankXl == 1) {
						if (board[_y][_x - 1] != change) {
							if (board[_y][_x + 6] != change || (board[_y][_x + 6] == 0 && board[_y][_x + 7] == change)) {
								result++;
							}
						}
					}
				}
				if (blankXl == 2 && blankXh == 2) {
					if (board[_y][_x + 6] != change || (board[_y][_x + 6] == 0 && board[_y][_x + 7] == change)) {
						if (board[_y][_x - 1] != change || (board[_y][_x - 1] == 0 && board[_y][_x - 2] == change)) {
							result++;
						}
					}
				}
			}
		}
		break;

		// 2. 세로 판독 (시작점 _x = 0 ~ 13)
	case 1:
		if (_y <= 13) {
			if (board[_y][_x] == 0 && board[_y + 1][_x] == change && board[_y + 2][_x] == change && board[_y + 3][_x] == change && board[_y + 4][_x] == change && board[_y + 5][_x] == 0) {
				if (blankYl == 2 && blankYh != 2) {
					if (blankYh == 0) {
						if (board[_y - 1][_x] != change || (board[_y - 1][_x] == 0 && board[_y - 2][_x] == change)) {
							result++;
						}
					}
					else if (blankYh == 1) {
						if (board[_y + 6][_x] != change) {
							if (board[_y - 1][_x] != change || (board[_y - 1][_x] == 0 && board[_y - 2][_x] == change)) {
								result++;
							}
						}
					}
				}
				if (blankYh == 2 && blankYl != 2) {
					if (blankYl == 0) {
						if (board[_y + 6][_x] != change || (board[_y + 6][_x] == 0 && board[_y + 7][_x] == change)) {
							result++;
						}
					}
					else if (blankYl == 1) {
						if (board[_y - 1][_x] != change) {
							if (board[_y + 6][_x] != change || (board[_y + 6][_x] == 0 && board[_y + 7][_x] == change)) {
								result++;
							}
						}
					}
				}
				if (blankYl == 2 && blankYh == 2) {
					if (board[_y + 6][_x] != change || (board[_y + 6][_x] == 0 && board[_y + 7][_x] == change)) {
						if (board[_y - 1][_x] == change || (board[_y - 1][_x] == 0 && board[_y - 2][_x] == change)) {
							result++;
						}
					}
				}
			}
		}
		break;

		// 3. 상향대각선 판독 (시작점 (_x, _y)에 대해서 _x = 0 ~ 12, _y = 0 ~ 12)
	case 2:
		if ((_x >= 0 && _x <= 12) && (_y >= 0 && _y <= 12)) {
			if (board[_y][_x] == 0 && board[_y + 1][_x + 1] == change && board[_y + 2][_x + 2] == change && board[_y + 3][_x + 3] == change && board[_y + 4][_x + 4] == change && board[_y + 5][_x + 5] == 0) {
				if (blankDul == 2 && blankDuh != 2) {
					if (blankDuh == 0) {
						if (board[_y - 1][_x - 1] != change || (board[_y - 1][_x - 1] == 0 && board[_y - 2][_x - 2] == change)) {
							result++;
						}
					}
					else if (blankDuh == 1) {
						if (board[_y + 6][_x + 6] != change) {
							if (board[_y - 1][_x - 1] != change || (board[_y - 1][_x - 1] == 0 && board[_y - 2][_x - 2] == change)) {
								result++;
							}
						}
					}
				}
				if (blankDuh == 2 && blankDul != 2) {
					if (blankDul == 0) {
						if (board[_y + 6][_x + 6] != change || (board[_y + 6][_x + 6] == 0 && board[_y + 7][_x + 7] == change)) {
							result++;
						}
					}
					else if (blankDul == 1) {
						if (board[_y][_x - 1] != change) {
							if (board[_y][_x + 6] != change || (board[_y][_x + 6] == 0 && board[_y][_x + 7] == change)) {
								result++;
							}
						}
					}
				}
				if (blankDul == 2 && blankDuh == 2) {
					if (board[_y + 6][_x + 6] != change || (board[_y + 6][_x + 6] == 0 && board[_y + 7][_x + 7] == change)) {
						if (board[_y - 1][_x - 1] != change || (board[_y - 1][_x - 1] == 0 && board[_y - 2][_x - 2] == change)) {
							result++;
						}
					}
				}
			}
		}
		break;

		// 4. 하향대각선 판독 (시작점 (_x, _y)에 대해서 _x = 0 ~ 12, _y = 0 ~ 12)
	case 3:
		printf("하향 대각선 판독 시작...\n");
		if ((_x >= 0 && _x <= 12) && (_y >= 6 && _y <= 18)) {
			if (board[_y][_x] == 0 && board[_y - 1][_x + 1] == change && board[_y - 2][_x + 2] == change && board[_y - 3][_x + 3] == change && board[_y - 4][_x + 4] == change && board[_y - 5][_x + 5] == 0) {
				if (blankDdl == 2 && blankDdh != 2) {
					if (blankDdh == 0) {
						if (board[_y + 1][_x - 1] != change || (board[_y + 1][_x - 1] == 0 && board[_y + 2][_x - 2] == change)) {
							result++;
						}
					}
					else if (blankDdh == 1) {
						if (board[_y - 6][_x + 6] != change) {
							if (board[_y + 1][_x - 1] != change || (board[_y + 1][_x - 1] == 0 && board[_y + 2][_x - 2] == change)) {
								result++;
							}
						}
					}
				}
				if (blankDdh == 2 && blankDdl != 2) {
					if (blankDdl == 0) {
						if (board[_y - 6][_x + 6] != change || (board[_y - 6][_x + 6] == 0 && board[_y - 7][_x + 7] == change)) {
							result++;
						}
					}
					else if (blankDdl == 1) {
						if (board[_y - 1][_x + 1] != change) {
							if (board[_y - 6][_x + 6] != change || (board[_y - 6][_x + 6] == 0 && board[_y - 7][_x + 7] == change)) {
								result++;
							}
						}
					}
				}
				if (blankDdl == 2 && blankDdh == 2) {
					if (board[_y - 6][_x + 6] != change || (board[_y - 6][_x + 6] == 0 && board[_y - 7][_x + 7] == change)) {
						if (board[_y + 1][_x - 1] =! change || (board[_y + 1][_x - 1] == 0 && board[_y + 2][_x - 2] == change)) {
							result++;
						}
					}
				}
			}
		}
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
	int BlankXl, BlankYl, BlankXh, BlankYh;				// 왼쪽/위쪽/오른쪽/아래쪽 벽과의 거리 확인변수
	int BlankDul, BlankDuh, BlankDdl, BlankDdh;			// 우하단, 우상단 방향으로의 대각선 거리 확인변수
	
	board[_y][_x] = change;			// (_x, _y)의 값을 현재 플레이어의 값으로 변경

	// 벽과의 거리를 1, 2, 3, 4, 15, 16, 17, ect로 반환하는 함수.
	// 벽과의 거리에 따라서 판독법을 변경한다
	switch (_x)  {
	case 1:
		BlankXl = 0;
		BlankXh = 3;
		break;
	case 2:
		BlankXl = 1;
		BlankXh = 3;
		break;
	case 3:
		BlankXl = 2;
		BlankXh = 3;
		break;
	case 4:
		BlankXl = 2;
		BlankXh = 3;
		break;
	case 15:
		BlankXl = 4;
		BlankXh = 2;
		break;
	case 16:
		BlankXl = 4;
		BlankXh = 1;
		break;
	case 17:
		BlankXl = 4;
		BlankXh = 0;
		break;
	default:
		BlankXl = 4;
		BlankXh = 3;
		break;
	};

	switch (_y)  {
	case 1:
		BlankYl = 0;
		BlankYh = 3;
		break;
	case 2:
		BlankYl = 1;
		BlankYh = 3;
		break;
	case 3:
		BlankYl = 2;
		BlankYh = 3;
		break;
	case 4:
		BlankYl = 2;
		BlankYh = 3;
		break;
	case 15:
		BlankYl = 4;
		BlankYh = 2;
		break;
	case 16:
		BlankYl = 4;
		BlankYh = 1;
		break;
	case 17:
		BlankYl = 4;
		BlankYh = 0;
		break;
	default:
		BlankYl = 4;
		BlankYh = 3;
		break;
	};

	// Dl(Dh)는 Xl,Yl(Xh,Yh) 중 작은 쪽을 따른다
	BlankDul = (BlankXl > BlankYl) ? BlankYl : BlankXl;
	BlankDuh = (BlankXh > BlankYh) ? BlankYh : BlankXh;

	BlankDdl = (BlankXl > BlankYh) ? BlankYh : BlankXl;
	BlankDdh = (BlankXh > BlankYl) ? BlankYl : BlankXh;

	if ((_x >= 0 && _x <= 18) && (_y >= 0 && _y <= 18)) {
		// 1. 하향 대각선 방향 열린3 확인
		if (BlankDdl < 5) {			// _대각선 거리가 0 ~ 4일때 경우 시작점을 0 ~ (_x, _y 중 가까운쪽) - 1로 잡아서 확인한다. 
			if (BlankDdl == BlankXl) {
				for (int i = 0; i < _x - 1; i++) {
					if (checkOpen4(i, _x + _y - i, 3) > 0)
						num3++;
				}
			} else if (BlankDul == BlankYh) {
				for (int i = 0; i < _y - 1; i++) {
					if (checkOpen4(i, _x + _y - i, 3) > 0)
						num3++;
				}
			}
		}
		else if (BlankDdh > 14) {	//  _대각선 거리가 15 ~ 17일 경우 시작점을 (_x, _y 중 가까운쪽) - 4 ~ 13으로 잡아서 확인한다
			if (BlankDdh == BlankXl) {
				for (int i = _x - 4; i < 14; i++) {
					if (checkOpen4(i, _x + _y + i, 3) > 0)
						num3++;
				}
			}
			else if (BlankDdh == BlankYh) {
				for (int i = _y - 4; i < 14; i++) {
					if (checkOpen4(i, _x + _y + i, 3) > 0)
						num3++;
				}
			}
		}
		else {					// 대각선거리가 좌표가 5 ~ 14일 경우 시작점을 _x(_y)-4 ~ _x(_y)-1로 잡아서 확인한다
			if (BlankDdh == BlankXl) {
				for (int i = _x - 4; i < _x - 1; i++) {
					if (checkOpen4(i, _x + _y + i, 3) > 0)
						num3++;
				}
			}
			else if (BlankDdh == BlankYh) {
				for (int i = _y - 4; i < _y - 1; i++) {
					if (checkOpen4(i, _x + _y + i, 3) > 0)
						num3++;
				}
			}
		}

		// 2. 상향 대각선 방향 열린3 확인

		if (BlankDul < 5) {			// _대각선 거리가 0 ~ 4일때 경우 시작점을 0 ~ (_x, _y 중 가까운쪽) - 1로 잡아서 확인한다. 
			if (BlankDul == BlankXl) {
				for (int i = 0; i < _x - 1; i++) {
					if (checkOpen4(i, i, 2) > 0)
						num3++;
				}
			}
			else if (BlankDul == BlankYl) {
				for (int i = 0; i < _y - 1; i++) {
					if (checkOpen4(i, i, 2) > 0)
						num3++;
				}
			}
		}
		else if (BlankDuh > 14) {	//  _대각선 거리가 15 ~ 17일 경우 시작점을 (_x, _y 중 가까운쪽) - 4 ~ 13으로 잡아서 확인한다
			if (BlankDuh == BlankXh) {
				for (int i = _x - 4; i < 14; i++) {
					if (checkOpen4(i, i, 2) > 0)
						num3++;
				}
			}
			else if (BlankDuh == BlankYh) {
				for (int i = _y - 4; i < 14; i++) {
					if (checkOpen4(i, i, 2) > 0)
						num3++;
				}
			}
		}
		else {					// 대각선거리가 좌표가 5 ~ 14일 경우 시작점을 _x-4 ~ _x-1로 잡아서 확인한다
			if (BlankDuh == BlankXh) {
				for (int i = _x - 4; i < _x - 1; i++) {
					if (checkOpen4(i, i, 2) > 0)
						num3++;
				}
			}
			else if (BlankDuh == BlankYh) {
				for (int i = _y - 4; i < _y - 1; i++) {
					if (checkOpen4(i, i, 2) > 0)
						num3++;
				}
			}
		}



		// 3. 가로방향 열린3 확인
		if (BlankXl < 5) {			// _x 좌표가 0 ~ 4일경우 시작점을 0 ~ _x-1로 잡아서 확인한다.
			for (int i = 0; i < _x; i++) {
				if (checkOpen4(i, _y, 0) > 0) {
					num3++;
				}
			}
		}
		else if (BlankXh > 14) {	// _x 좌표가 15 ~ 17일 경우 시작점을 _x-4 ~ 13으로 잡아서 확인한다
			for (int i = _x - 4; i < 14; i++) {
				if (checkOpen4(i, _y, 0) > 0)
					num3++;
			}
		}
		else {					// _x 좌표가 5 ~ 14일 경우 시작점을 _x-4 ~ _x-1로 잡아서 확인한다
			for (int i = _x - 4; i < _x; i++) {
				if (checkOpen4(i, _y, 0) > 0) {
					num3++;
				}
			}
		}

		// 4. 세로방향 열린3 확인
		if (BlankYl < 5) {			// _y 좌표가 0 ~ 4일경우 시작점을 0 ~ _y-1로 잡아서 확인한다.
			for (int i = 0; i < _y; i++) {
				if (checkOpen4(_x, i, 1) > 0) {
					num3++;
				}
			}
		}
		else if (BlankYh > 14) {	// _y 좌표가 15 ~ 17일 경우 시작점을 _y-4 ~ 13으로 잡아서 확인한다
			for (int i = _y - 4; i < 14; i++) {
				if (checkOpen4(_x, i, 1) > 0)
					num3++;
			}
		}
		else {					// _y 좌표가 5 ~ 14일 경우 시작점을 _y-4 ~ _y-1로 잡아서 확인한다
			for (int i = _y - 4; i < _y; i++) {
				if (checkOpen4(_x, i, 1) > 0) {
					num3++;
				}
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
