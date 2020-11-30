#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void mapprint(int(*map)[4]) {         //폭탄피하기 판 출력
    printf("   0 1 2 3\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", i);
        for (int j = 0; j <4; j++)
        {
            if (map[i][j] == 0)
            {
                printf("□");
            }
            else if (map[i][j] == 7)
            {
                printf("★");
            }
            else if (map[i][j] == 8)
            {
                printf(" .");
            }
        }
        printf("\n");
    }
}
int mini_game1(void)
{
    int x = 0, y = 0;
    int win = 0;
    int rx = 0, ry = 0;
    int map[4][4] = { 0 };
    printf("폭탄 피하기 게임!!\n");
    printf("폭탄이 있는 좌표를 입력하는 사람이 지는 게임 입니다.\n");
    mapprint(map);
    while (1) {   //A==1  B==0
        srand(time(NULL));
        rx = rand() % 4;
        ry = rand() % 4;
       
        printf("\nA의 차례입니다.\n");
        printf("x좌표와 y좌표를 입력하시오:  ");
        reA:
        scanf_s("%d%d", &x, &y);
        if (x == rx && y == ry) {
            map[ry][rx] = 7;
            mapprint(map);
            win = 0; //B승리
            break;
        }
        else if (map[x][y] == 8)
        {
            printf("이미 입력된 좌표입니다. 다시 입력하시오: ");
            goto reA;
        }
        else if (x < 0 || x>4 || y < 0 || y>4)
        {
            printf("범위에 벗어난 좌표 입니다. 다시 입력하시오: ");
            goto reA;
        }
        else {
            map[y][x] = 8;
            mapprint(map);
        }
        printf("\nB의 차례입니다.\n");
        printf("x좌표와 y좌표를 입력하시오:  ");
        reB:
        scanf_s("%d%d", &x, &y);
        if (x == rx && y == ry) {
            map[ry][rx] = 7;
            mapprint(map);
            win = 1; //A승리
            break;
        }
        else if (map[x][y] == 8)
        {
            printf("이미 입력된 좌표입니다. 다시 입력하시오: ");
            goto reB;
        }
        else if (x < 0 || x>4 || y < 0 || y>4)
        {
            printf("범위에 벗어난 좌표 입니다. 다시 입력하시오: ");
            goto reB;
        }
        else {
            map[y][x] = 8;
            mapprint(map);
        }
    }

    if (win == 1) {
        printf("\n펑~~!!  ");
        printf("A의 승리!\n");
    }
    if (win == 0) {
        printf("\n펑~~!!  ");
        printf("B의 승리!\n");
    }

    

	return win;
}

int main(void)
{

    mini_game1();
   
    return 0;
}