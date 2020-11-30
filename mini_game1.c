#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void mapprint(int(*map)[4]) {         //��ź���ϱ� �� ���
    printf("   0 1 2 3\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", i);
        for (int j = 0; j <4; j++)
        {
            if (map[i][j] == 0)
            {
                printf("��");
            }
            else if (map[i][j] == 7)
            {
                printf("��");
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
    printf("��ź ���ϱ� ����!!\n");
    printf("��ź�� �ִ� ��ǥ�� �Է��ϴ� ����� ���� ���� �Դϴ�.\n");
    mapprint(map);
    while (1) {   //A==1  B==0
        srand(time(NULL));
        rx = rand() % 4;
        ry = rand() % 4;
       
        printf("\nA�� �����Դϴ�.\n");
        printf("x��ǥ�� y��ǥ�� �Է��Ͻÿ�:  ");
        reA:
        scanf_s("%d%d", &x, &y);
        if (x == rx && y == ry) {
            map[ry][rx] = 7;
            mapprint(map);
            win = 0; //B�¸�
            break;
        }
        else if (map[x][y] == 8)
        {
            printf("�̹� �Էµ� ��ǥ�Դϴ�. �ٽ� �Է��Ͻÿ�: ");
            goto reA;
        }
        else if (x < 0 || x>4 || y < 0 || y>4)
        {
            printf("������ ��� ��ǥ �Դϴ�. �ٽ� �Է��Ͻÿ�: ");
            goto reA;
        }
        else {
            map[y][x] = 8;
            mapprint(map);
        }
        printf("\nB�� �����Դϴ�.\n");
        printf("x��ǥ�� y��ǥ�� �Է��Ͻÿ�:  ");
        reB:
        scanf_s("%d%d", &x, &y);
        if (x == rx && y == ry) {
            map[ry][rx] = 7;
            mapprint(map);
            win = 1; //A�¸�
            break;
        }
        else if (map[x][y] == 8)
        {
            printf("�̹� �Էµ� ��ǥ�Դϴ�. �ٽ� �Է��Ͻÿ�: ");
            goto reB;
        }
        else if (x < 0 || x>4 || y < 0 || y>4)
        {
            printf("������ ��� ��ǥ �Դϴ�. �ٽ� �Է��Ͻÿ�: ");
            goto reB;
        }
        else {
            map[y][x] = 8;
            mapprint(map);
        }
    }

    if (win == 1) {
        printf("\n��~~!!  ");
        printf("A�� �¸�!\n");
    }
    if (win == 0) {
        printf("\n��~~!!  ");
        printf("B�� �¸�!\n");
    }

    

	return win;
}

int main(void)
{

    mini_game1();
   
    return 0;
}