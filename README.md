# two-team-fire-extinguisher-
 저희 소화기 팀은 이차원 배열을 응용하여 2인용 오목 게임을 만들기로 하였습니다.\
  단순해보일수도 있는 오목게임에 다양한 미니게임을 조합하여 변수를 두어, 더욱 재미있는 게임을 만들고자 합니다.\
  미니게임은 게임을 시작할 때 흑백을 정할때와, 무르기를 실행할 때 실행되며, 흥미로운 변수로서 작용할 수 있을 것입니다.
 
 오목의 전체 보드는 다음과 같이 구성되어 있습니다. 
 ```
 오목에서 일어나는 이벤트 (선공/후공 정하기, 자신돌/상대돌 바꾸기)
 오목을 두고, 출력하는 함수
 오목 규칙에 어긋나는지 확인하기 위한 함수
 ```
 
 ## 오목에서 일어나는 이벤트
 오목을 둘 때, 저희는 어떤 방식으로 선공/후공을 정할지에 대해서 생각을 해보았습니다.
 단순한 오목으로 끝나지 않고, 이를 또 하나의 게임으로 만들자는 아이디어를 얻어서
 이를 미니게임으로 정하기로 하였습니다.
 
 ## zokbo
 
 ## game
 
 ## zokbo_print
 
 ## fight
 
 ## mapprint
 ## mini_game
 
 ## BaskinRobbins
 
 ## 오목두기&출력함수
 오목의 메인게임을 실행하고, 보드판을 출력하면서, 보드판이 계속해서 출력되어 화면에 알맞게 출력되지 않는 오류가 있었습니다.
 이를 수정하고자 <windows.h>의 cls 명령어를 사용하여 텍스트를 지워, 깔끔하게 출력할 수 있었습니다.
  또한 텍스트의 색을 바꾸어, 더욱 오목판처럼 보일 수 있도록 변경하여, 오목을 두는데 더 집중할 수 있도록 하였습니다.
 
 
  ## LetterColor
  입력받는 color 값에 따라서 출력하는 오목판의 색을 변경하는 함수입니다.
 
  ## Board
 board의 내용을 오목판 위에 출력하는 함수입니다.
 
  ## game_end
 board의 내용을 읽어서, 흑/백의 승패여부를 확인하여 값을 반환하는 함수입니다.
 
  ## turnprint
 change 변수의 값에 따라서 플레이어의 순서를 결정하고, 좌표를 입력받아서 돌을 두는 함수입니다.
 
  ## ReturnStone
  
  ## SomeoneStone
 
 
 
 ## 오목규칙 확인함수
  오목에는 여러 규칙이 있지만, 저희는 일단 33규칙만을 적용하여 보았습니다.
  33규칙 뿐만 아니라, 이미 입력한 좌표에 다시 돌을 두는 것을 방지하는 함수 등도 구현하였습니다.
 
 
 ## board[19][19]
 board[i][j]에는 보드의 (j, i) 좌표에 해당하는 칸의 상태가 적혀있습니다.
 
 board[i][j] =  0: 비어있는 칸입니다.\
 board[i][j] =  1: 흑돌을 둔 칸입니다.\
 board[i][j] = -1: 백돌을 둔 칸입니다.
 

 ## checkloc
 board의 내용을 읽어서, 해당 좌표의 값을 반환하는 함수입니다.
 
 ## check33
 
 ## 메인함수 (5mok.c)
 
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define Time3 3000
#define Time1 2000

int cash1 = 0;
int cash2 = 0;
int count = 0;
int game();
void zokbo_print(result_card);
void fight(user1_card_result, user2_card_result);

// 족보게임
int game() {
    int user1_card[2] = { 0,0 };
    int user2_card[2] = { 0,0 };
    int user1_card_result;
    int user2_card_result;
    system("cls");
    srand((unsigned int)time(NULL));
    int menu;
    int c, d;
    if (count == 0) {
        printf("게임머니가 10만원씩 지급됩니다");
        cash1 = 100000;
        cash2 = 100000;
        fflush(stdin);

    }

    while (1) {
        count++;
        user1_card[0] = rand() % 20 + 1;
        user2_card[0] = rand() % 20 + 1;
        while (1) {
            if (user1_card[0] != user1_card[1] != user2_card[0] != user2_card[1]) {
                user1_card[1] = rand() % 20 + 1;
                user2_card[1] = rand() % 20 + 1;
            }
            else
                break;

        }

        user1_card_result = zokbo(user1_card[0], user1_card[1]);
        user2_card_result = zokbo(user2_card[0], user2_card[1]);
        printf("\n1을 누르면 3초간 user1의 패를 보여주겠습니다\n");
        scanf_s("%d", &c);
        if (c == 1) {
            printf("user1의 카드는\n");
            zokbo_print(user1_card_result);
            Sleep(3000);
            system("cls");
            printf("\n");
        }
        printf("1을 누르면 3초간 user2의 패를 보여주겠습니다\n");
        scanf_s("%d", &d);
        if (d == 1) {
            printf("user2의 카드는\n");
            zokbo_print(user2_card_result);
            Sleep(3000);
            system("cls");
            printf("\n");
        }
        int a, b;
        printf("user1 베팅 하시겠습니까?\n");
        printf("1.베팅\n");
        printf("2.다이\n");
        scanf_s("%d", &a);
        if (a == 1) {
            printf("user2 베팅 하시겠습니까?\n");
            printf("1.베팅\n");
            printf("2.다이\n");
            scanf_s("%d", &b);

            switch (b) {
            case 1:
                fight(user1_card_result, user2_card_result);
                break;
            case 2:
                while (1) {
                    printf("user2 다이 기본참가금 5000원이 차감됩니다\n");

                    cash2 -= 5000;
                    fflush(stdin);
                    break;
                }
            }
        }
        else if (a == 2) {
            while (1) {
                printf("user1 다이 기본참가금 5000원이 차감됩니다\n");
                cash1 -= 5000;
                printf("게임을 계속 진행하시려면 1을 눌러주세요\n");
                fflush(stdin);
                scanf_s("%d", &menu);
                if (menu == 1)
                    break;
            }

        }
        if (cash1 <= 0) {
            printf("user1 파산 당신의 패배입니다\n");
            printf("user2가 선공(1)할지 후공(2)할지 골라주세요\n");
            int n;
            scanf_s("%d", &n);
            if (n == 1) {
                system("cls");
                printf("user2 선공!(B)입니다.\n");
                return 1;

            }
            else if (n == 2) {
                system("cls");
                printf("user1 선공!(B)입니다.\n");
                return 1;
            }





        }
        else if (cash2 <= 0) {
            printf("user2 파산 당신의 패배입니다\n");
            printf("user1이 선공(1)할지 후공(2)할지 골라주세요\n");
            int m;
            scanf_s("%d", &m);
            if (m == 1) {
                system("cls");
                printf("user1 선공!(B)입니다.\n");
                return 1;
            }
            else if (m == 2) {
                system("cls");
                printf("user2 선공!(B)입니다.\n");
                return 1;
            }


        }
    }
}
int zokbo(card0, card1) {
    if (card0 == 3 && card1 == 8 || card0 == 8 && card1 == 3)
        return 1;
    else if (card0 == 1 && card1 == 8 || card0 == 8 && card1 == 1)
        return 2;
    else if (card0 == 1 && card1 == 3 || card0 == 3 && card1 == 1)
        return 3;
    else if (card0 == 10 && card1 == 20 || card0 == 20 && card1 == 10)
        return 4;
    else if (card0 == 9 && card1 == 19 || card0 == 19 && card1 == 9)
        return 5;
    else if (card0 == 8 && card1 == 18 || card0 == 18 && card1 == 8)
        return 6;
    else if (card0 == 7 && card1 == 17 || card0 == 17 && card1 == 7)
        return 7;
    else if (card0 == 6 && card1 == 16 || card0 == 16 && card1 == 6)
        return 8;
    else if (card0 == 5 && card1 == 15 || card0 == 15 && card1 == 5)
        return 9;
    else if (card0 == 4 && card1 == 14 || card0 == 14 && card1 == 4)
        return 10;
    else if (card0 == 3 && card1 == 13 || card0 == 13 && card1 == 3)
        return 11;
    else if (card0 == 2 && card1 == 12 || card0 == 12 && card1 == 2)
        return 12;
    else if (card0 == 1 && card1 == 11 || card0 == 11 && card1 == 1)
        return 13;


    else {
        if (card0 + card1 == 9 || card0 + card1 == 19 || card0 + card1 == 29 || card0 + card1 == 39)
            return 14;
        else if (card0 + card1 == 8 || card0 + card1 == 18 || card0 + card1 == 28 || card0 + card1 == 38)
            return 15;
        else if (card0 + card1 == 7 || card0 + card1 == 17 || card0 + card1 == 27 || card0 + card1 == 37)
            return 16;
        else if (card0 + card1 == 6 || card0 + card1 == 16 || card0 + card1 == 26 || card0 + card1 == 36)
            return 17;
        else if (card0 + card1 == 5 || card0 + card1 == 15 || card0 + card1 == 25 || card0 + card1 == 35)
            return 18;
        else if (card0 + card1 == 4 || card0 + card1 == 14 || card0 + card1 == 24 || card0 + card1 == 34)
            return 19;
        else if (card0 + card1 == 3 || card0 + card1 == 13 || card0 + card1 == 23 || card0 + card1 == 33)
            return 20;
        else if (card0 + card1 == 2 || card0 + card1 == 12 || card0 + card1 == 22 || card0 + card1 == 32)
            return 21;
        else if (card0 + card1 == 1 || card0 + card1 == 11 || card0 + card1 == 21 || card0 + card1 == 31)
            return 22;
    }


}
void zokbo_print(result_card) {
    switch (result_card) {
    case 1:
        printf("38 광땡입니다\n");
        break;
    case 2:
        printf("18 광땡입니다\n");
        break;
    case 3:
        printf("13 광땡입니다\n");
        break;
    case 4:
        printf("장땡입니다\n");
        break;
    case 5:
        printf("9땡입니다\n");
        break;
    case 6:
        printf("8땡입니다\n");
        break;
    case 7:
        printf("7땡입니다\n");
        break;
    case 8:
        printf("6땡입니다\n");
        break;
    case 9:
        printf("5땡입니다\n");
        break;
    case 10:
        printf("4땡입니다\n");
        break;
    case 11:
        printf("3땡입니다\n");
        break;
    case 12:
        printf("2땡입니다\n");
        break;
    case 13:
        printf("1땡입니다\n");
        break;
    case 14:
        printf("9끗입니다\n");
        break;

    case 15:
        printf("9끗입니다\n");
        break;

    case 16:
        printf("8끗입니다\n");
        break;

    case 17:
        printf("7끗입니다\n");
        break;
    case 18:
        printf("6끗입니다\n");
        break;
    case 19:
        printf("5끗입니다\n");
        break;
    case 20:
        printf("4끗입니다\n");
        break;
    case 21:
        printf("3끗입니다\n");
        break;
    case 22:
        printf("2끗입니다\n");
        break;
    case 23:
        printf("1끗입니다\n");
        break;
    }
}
void fight(user1_card_result, user2_card_result) {
    int bet_money1;
    int bet_money2;
    while (1) {
        system("cls");
        printf("user1 얼마를 베팅하시겠습니까?\n");
        printf("user1 당신의 보유 금액은%d 입니다\n", cash1);
        printf("베팅금액:\n");
        scanf_s("%d", &bet_money1);



        printf("user2 얼마를 베팅하시겠습니까?\n");
        printf("user2 당신의 보유 금액은%d 입니다\n", cash2);
        printf("베팅금액:\n");
        scanf_s("%d", &bet_money2);

        break;


    }
    printf("user1의 카드는\n");
    zokbo_print(user1_card_result);
    Sleep(3000);
    printf("user2의 카드는\n");
    zokbo_print(user2_card_result);

    if (user1_card_result < user2_card_result) {
        printf("user1이 user2가 베팅한 금액과 자신의 베팅한 금액을 가지게 됩니다\n");
        cash1 += bet_money2;
        cash2 -= bet_money2;
        printf("user1의 현재 보유 금액은: %d\n", cash1);
        printf("user2의 현재 보유 금액은: %d\n", cash2);
    }

    else if (user1_card_result > user2_card_result) {
        printf("user2가 user1이 베팅한 금액과 자신의 베팅한 금액을 가지게 됩니다\n");
        cash2 += bet_money1;
        cash1 -= bet_money1;
        printf("user1의 현재 보유 금액은: %d\n", cash1);
        printf("user2의 현재 보유 금액은: %d\n", cash2);
    }

    else if (user1_card_result == user2_card_result) {
        printf("동일 족보 재경기합니다\n");
        count--;
    }



}

// 미니게임1. 폭탄 피하기
void mapprint(int(*map)[4]) {         //폭탄피하기 판 출력
    printf("   0 1 2 3\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 4; j++)
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
    srand(time(NULL));
    rx = rand() % 4;
    ry = rand() % 4;
    printf("*****************폭탄 피하기 게임!!*****************\n");
    printf("폭탄이 있는 좌표를 입력하는 사람이 지는 게임 입니다.\n");
    printf("****************************************************\n");
    mapprint(map);
    while (1) {   //B ==1 ,검은돌==1   W==0 ,흰돌==-1

        printf("\nB의 차례입니다.\n");
        printf("x좌표와 y좌표를 입력하시오:  ");
    reB:
        scanf_s("%d%d", &x, &y);
        if (x == rx && y == ry) {
            map[ry][rx] = 7;
            mapprint(map);
            win = 0; //W승리
            break;
        }
        else if (map[y][x] == 8)
        {
            printf("이미 입력된 좌표입니다. 다시 입력하시오: ");
            goto reB;
        }
        else if (x < 0 || x>3 || y < 0 || y>3)
        {
            printf("범위에 벗어난 좌표 입니다. 다시 입력하시오: ");
            goto reB;
        }
        else {
            map[y][x] = 8;
            mapprint(map);

        }
        printf("\nW의 차례입니다.\n");
        printf("x좌표와 y좌표를 입력하시오:  ");
    reW:
        scanf_s("%d%d", &x, &y);
        if (x == rx && y == ry) {
            map[ry][rx] = 7;
            mapprint(map);
            win = 1; //B승리
            break;
        }
        else if (map[y][x] == 8)
        {
            printf("이미 입력된 좌표입니다. 다시 입력하시오: ");
            goto reW;
        }
        else if (x < 0 || x>3 || y < 0 || y>3)
        {
            printf("범위에 벗어난 좌표 입니다. 다시 입력하시오: ");
            goto reW;
        }
        else {
            map[y][x] = 8;
            mapprint(map);

        }

    }

    if (win == 1) {
        printf("\n펑~~!!  ");
        printf("B의 승리!\n");
        Sleep(Time3);
    }
    if (win == 0) {
        printf("\n펑~~!!  ");
        printf("W의 승리!\n");
        Sleep(Time3);
    }



    return win;
}


// 미니게임2. 베스킨라빈스31
#define Turn 31
int BaskinRobbins(void)
{
    srand((unsigned)time(NULL));
    //a는 순서를 정해주는 난수를 저장하는 변수입니다. MaxCnt는 1~3까지의 입력받은 값을 저장합니다. Value는 1~31까지 증가시키면서 출력해줍니다.
    int a, MaxCnt, Value;
    char AB[2] = { 'B', 'W' };    //B ==1 ,검은돌==1   W==0 ,흰돌==-1

    Value = 1;
    a = rand() % 2;      //a가 0이면 A의 턴, 1이면 B의 턴이다.

    printf("게임은 베스킨라빈스31입니다.\n");
    printf("\n\t\t<--Baskin_Rabins_31-->\n\n"
        " ====================[How To Play]====================\n"
        " [1] 1부터 시작해서 31까지 번갈아가며 숫자를 부른다.\n"
        " [2] 한번에 최대 3번까지 연속된 숫자를 말할 수 있다.\n"
        " [3] 31을 말하는 플레이어가 게임에서 패배한다.\n"
        " =====================================================\n\n");
    printf("   [선공은 랜덤으로 %c가 먼저 입니다.]\n", AB[a]);
    printf("      숫자 입력은 1~3까지 입력할 수 있습니다.\n\n");

    printf("         Enter을 누르면 게임을 시작합니다.");
    while (1)
    {
        int key;
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
    }


    while (1)
    {
        puts("");
        printf("%c의 턴입니다.\n", AB[a]);
        switch (a)      //순서를 바꿔주는 코드
        {
        case 0: {
            ++a;
            break;
        }
        case 1: {
            --a;
            break;
        }
        }

        puts("======================================");

        printf("숫자 몇개를 입력하시겠습니까? : ");
        scanf_s("%d", &MaxCnt);

        if (MaxCnt > 3 || MaxCnt < 0)               //입력한 값이 0보다 작고 3보다 크면 다시 입력하도록 합니다.
        {
            while (MaxCnt > 3 || MaxCnt < 0)
            {
                printf("1 ~ 3까지 다시 입력해주세요. : ");
                scanf_s("%d", &MaxCnt);
            }
        }

        printf("입력받은 숫자 : ");

        for (int i = 0; i < MaxCnt; i++)      //MaxCnt만큼 반복시켜 줍니다. 반복시키면서 Value(1부터)를 1씩증가시켜 출력시켜줍니다.
        {
            printf("%d ", Value);
            Value++;
            if (Value == Turn + 1)
            {
                break;
            }
        }

        puts("");
        puts("======================================");



        if (Value == Turn + 1)
        {
            printf("%c의 승리입니다.", AB[a]);
            Sleep(Time3);
            break;
        }
    }

    if (AB[a] == 'B')
    {
        return 1;
    }
    else if (AB[a] == 'W')
    {
        return 0;
    }

}

#define BLACK 0
#define WHITE 7

int board[19][19] = { 0 };

void LetterColor(int color) { // 오목돌 색 변경
    if (color == WHITE)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
    else if (color == BLACK)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
}

void Board(void)            //오목판 함수
{
    printf("ⓞ①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮ⓐⓑⓒ -- x좌표\n");
    if (board[0][0] == 0)   //첫번째줄
    {
        LetterColor(WHITE);
        printf("┌ ");
    }
    else if (board[0][0] == 1)
    {
        LetterColor(BLACK);
        printf("●");
        LetterColor(WHITE);
    }
    else if (board[0][0] == -1)
    {
        LetterColor(WHITE);
        printf("●");
    }
    for (int i = 1; i < 18; i++)
    {
        if (board[0][i] == 0)
        {
            LetterColor(WHITE);
            printf("┬ ");
        }
        else if (board[0][i] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            LetterColor(WHITE);
        }
        else if (board[0][i] == -1)
        {
            LetterColor(WHITE);
            printf("●");
        }
    }
    if (board[0][18] == 0)
    {
        LetterColor(WHITE);
        printf("┐ ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf(" 0\n");
    }
    else if (board[0][18] == 1)
    {
        LetterColor(BLACK);
        printf("●");
        LetterColor(WHITE);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf(" %d\n", 0);
    }
    else if (board[0][18] == -1)
    {
        LetterColor(WHITE);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf(" %d\n", 0);
    }                           //여기까지가 첫번째줄

    for (int i = 1; i < 18; i++)      //두번째줄부터 18번째줄까지
    {
        if (board[i][0] == 0)
        {
            LetterColor(WHITE);
            printf("├ ");
        }
        else if (board[i][0] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[i][0] == -1)
        {
            LetterColor(WHITE);
            printf("●");
        }
        for (int j = 1; j < 18; j++)
        {
            if (board[i][j] == 0)
            {
                LetterColor(WHITE);
                printf("┼ ");
            }
            else if (board[i][j] == 1)
            {
                LetterColor(BLACK);
                printf("●");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            }
            else if (board[i][j] == -1)
            {
                LetterColor(WHITE);
                printf("●");
            }
        }
        if (board[i][18] == 0)
        {
            LetterColor(WHITE);
            printf("┤ ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            printf(" %d\n", i);
        }
        else if (board[i][18] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            printf(" %d\n", i);
        }
        else if (board[i][18] == -1)
        {
            LetterColor(WHITE);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            printf(" %d\n", i);
        }
    }                           //여기까지가 두번째줄

    if (board[18][0] == 0)   //마지막번째줄
    {
        LetterColor(WHITE);
        printf("└ ");
    }
    else if (board[18][0] == 1)
    {
        LetterColor(BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    else if (board[18][0] == -1)
    {
        LetterColor(WHITE);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    for (int i = 1; i < 18; i++)
    {
        if (board[18][i] == 0)
        {
            LetterColor(WHITE);
            printf("┴ ");
        }
        else if (board[18][i] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[18][i] == -1)
        {
            LetterColor(WHITE);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
    }
    if (board[18][18] == 0)
    {
        LetterColor(WHITE);
        printf("┘ ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf(" 18 -- y좌표 \n");
    }
    else if (board[18][18] == 1)
    {
        LetterColor(BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf(" 18\n");
    }
    else if (board[18][18] == -1)
    {
        LetterColor(WHITE);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf(" 18\n");
    }                        //여기까지가 마지막번째줄
}
int change = 1;
int win = 0;


void ReturnStone(int Stone)
{
    system("Cls");
    int X = 0, Y = 0, Value;
    Board();
    printf("무르기를 사용할 좌표를 입력하세요. : ");
    scanf_s("%d %d", &X, &Y);
    Value = board[Y][X];
    system("Cls");

    while (1)
    {
        if (Stone == Value)      //선택한돌과 사용자의 돌색이 같으면 그 돌을 없애고 다시 둘 수 있습니다.
        {
            board[Y][X] = 0;
            Board();


            printf("수를 다시 놔둘 좌표를 입력하시오. : ");
            scanf_s("%d %d", &X, &Y);
            board[Y][X] = Value;

            system("Cls");
            Board();
            break;
        }
        else if (Stone != Value)
        {
            Board();
            printf("선택한 돌이 자신의 돌 색과 다름니다. 다시 입력해주세요. : ");
            scanf_s("%d %d", &X, &Y);
            Value = board[Y][X];
        }
    }
}
void SomeoneStone(int Stone)
{
    system("Cls");
    int X = 0, Y = 0, Value;
    Board();
    printf("빼고싶은 상대 수의 좌표를 입력하세요. : ");
    scanf_s("%d %d", &X, &Y);
    Value = board[Y][X];

    while (1)
    {
        if (Value != Stone && Value != 0)         //상대방의 돌과 색이 다르면 상대방의 수를 뺄 수 있습니다.
        {
            board[Y][X] = 0;
            Board();
            break;
        }
        else if ((Value == Stone) || (Value == 0))         //상대방의 돌과 색이 같으면 좌표를 다시 선택할 수 있습니다.
        {
            Board();
            printf("자신의 돌을 선택하거나 빈 공간입니다. 다시 입력해주세요. : ");
            scanf_s("%d %d", &X, &Y);
            Value = board[Y][X];
        }
    }
}

void turnprint(int(*board)[19], int _turn)   // 차례결정 & 선택 좌표에 출력하는 함수.
{
    srand((unsigned int)time(NULL));
    int selectX = 0, selectY = 0;
    int _order = 0;
    int randnum = rand() % 2;      // randnum애는 0 or 1이 저장됨. 0일때 지뢰, 1일때 31
    //B ==1 ,검은돌==1   W==0 ,흰돌==-1
    if (change == 1)    //검은돌
    {
        printf("B의 차례입니다.\n");
        // 4턴 이상인 경우, 돌두기/상대돌빼기/자신돌바꾸기 중에 선택
        if (_turn > 4) {
            do {
                printf("1: 돌 두기\t2:상대 돌빼기\t3:자신 돌바꾸기");
                scanf_s("%d", &_order);
                if (_order < 0 || _order > 3)
                    printf("올바른 지시를 입력해주십시오.\n");
            } while (_order < 0 || _order > 3);
            switch (_order) {
            case 1:
                // 돌두기 함수
                do {
                    printf("X좌표와 Y좌표를 입력하시오:  ");
                    scanf_s("%d%d", &selectX, &selectY);
                } while (checkloc(selectX, selectY) != 0);
                board[selectY][selectX] = 1;
                change = 0;
                break;
            case 2:
                if (randnum == 1) {
                    if (BaskinRobbins() == 1) {
                        SomeoneStone(1);
                    }
                    change = 0;
                }
                else if (randnum == 0) {
                    if (mini_game1() == 1) {
                        SomeoneStone(1);
                    }
                    change = 0;
                }
                // 상대 돌빼기 함수
                break;
            case 3:
                if (randnum == 0) {
                    if (mini_game1() == 1)
                        ReturnStone(1);
                    change = 0;
                }
                else if (randnum == 1) {
                    if (BaskinRobbins() == 1)
                        ReturnStone(1);
                    change = 0;
                }
                break;
            default:
                change = 0;
                break;
            }
        }
        // 4턴 미만인 경우, 돌두기만 가능
        else {
            do {
                printf("X좌표와 Y좌표를 입력하시오:  ");
                scanf_s("%d%d", &selectX, &selectY);
            } while (checkloc(selectX, selectY) != 0);
            board[selectY][selectX] = 1;
            change = 0;
        }
    }
    else if (change == 0)
    {
        printf("W의 차례입니다.\n");
        // 4턴 이상인 경우, 돌두기/상대돌빼기/자신돌바꾸기 중에 선택
        if (_turn > 4) {
            do {
                printf("1: 돌 두기\t2:상대 돌빼기\t3:자신 돌바꾸기");
                scanf_s("%d", &_order);
                if (_order < 0 || _order > 3)
                    printf("올바른 지시를 입력해주십시오.\n");
            } while (_order < 0 || _order > 3);
            switch (_order) {
            case 1:
                // 돌두기 함수
                do {
                    printf("X좌표와 Y좌표를 입력하시오:  ");
                    scanf_s("%d%d", &selectX, &selectY);
                } while (checkloc(selectX, selectY) != 0);
                board[selectY][selectX] = -1;
                change = 1;
                break;
            case 2:
                if (randnum == 1) {
                    if (BaskinRobbins() == 0) {
                        SomeoneStone(-1);
                    }
                    change = 1;
                }
                else if (randnum == 0) {
                    if (mini_game1() == 0) {
                        SomeoneStone(-1);
                    }
                    change = 1;
                }
                // 상대 돌빼기 함수
                break;
            case 3:
                if (randnum == 0) {
                    if (mini_game1() == 0)
                        ReturnStone(-1);
                    change = 1;
                }
                else if (randnum == 1) {
                    if (BaskinRobbins() == 0)
                        ReturnStone(-1);
                    change = 1;
                }
                break;
            default:
                change = 1;
                break;

            }
        }
        // 4턴 미만인 경우, 돌두기만 가능
        else {
            do {
                printf("X좌표와 Y좌표를 입력하시오:  ");
                scanf_s("%d%d", &selectX, &selectY);
            } while (checkloc(selectX, selectY) != 0);
            board[selectY][selectX] = -1;
            change = 1;
        }
    }
}

int game_end(int(*Board)[19]) {
    int i;
    int j;
    for (i = 2; i < 18; i++) {
        for (j = 0; j < 20; j++) {
            if (Board[j][i - 2] == 1 && Board[j][i - 1] == 1 && Board[j][i] == 1 && Board[j][i + 1] == 1 && Board[j][i + 2] == 1) {
                system("Cls");
                printf("선공 승리\n");

                return 1;
            }
            else if (Board[j][i - 2] == -1 && Board[j][i - 1] == -1 && Board[j][i] == -1 && Board[j][i + 1] == -1 && Board[j][i + 2] == -1) {
                system("Cls");
                printf("후공 승리\n");

                return 1;
            }
        }
    }
    for (i = 2; i < 18; i++) {
        for (j = 0; j < 20; j++) {

            if (Board[i - 2][j] == 1 && Board[i - 1][j] == 1 && Board[i][j] == 1 && Board[i + 1][j] == 1 && Board[i + 2][j] == 1) {
                system("Cls");
                printf("선공 승리\n");

                return 1;
            }
            else if (Board[i - 2][j] == -1 && Board[i - 1][j] == -1 && Board[i][j] == -1 && Board[i + 1][j] == -1 && Board[i + 2][j] == -1) {
                system("Cls");
                printf("후공 승리\n");

                return 1;
            }
        }
    }


    for (i = 2; i < 18; i++) {
        for (j = 2; j < 18; j++) {
            if (Board[j - 2][i - 2] == 1 && Board[j - 1][i - 1] == 1 && Board[j][i] == 1 && Board[j + 1][i + 1] == 1 && Board[j + 2][i + 2] == 1) {
                system("Cls");
                printf("선공 승리\n");

                return 1;
            }
            else if (Board[j - 2][i - 2] == -1 && Board[j - 1][i - 1] == -1 && Board[j][i] == -1 && Board[j + 1][i + 1] == -1 && Board[j + 2][i + 2] == -1) {
                system("Cls");
                printf("후공 승리\n");

                return 1;
            }
        }
    }

    for (i = 2; i < 18; i++) {
        for (j = 2; j < 18; j++) {

            if (Board[j + 2][i - 2] == 1 && Board[j + 1][i - 1] == 1 && Board[j][i] == 1 && Board[j - 1][i + 1] == 1 && Board[j - 2][i + 2] == 1) {
                system("Cls");
                printf("선공 승리\n");

                return 1;
            }
            else if (Board[j + 2][i - 2] == -1 && Board[j + 1][i - 1] == -1 && Board[j][i] == -1 && Board[j - 1][i + 1] == -1 && Board[j - 2][i + 2] == -1) {
                system("Cls");
                printf("후공 승리\n");

                return 1;
            }
        }
    }
    return 0;
}

int checkloc(int _x, int _y) {
    int bcheck = 0;

    // (_x, _y) 위치에 다른 돌이 있는 경우
    if (board[_y][_x] != 0) {
        if (board[_y][_x] == 1) {
            printf("해당 위치에 흑돌이 있습니다.\n");
            bcheck = 1;
        }
        else if (board[_y][_x] == -1) {
            printf("해당 위치에 백돌이 있습니다.\n");
            bcheck = -1;
        }
        else {
            printf("알수없는 자료값입니다. (%d, %d)의 값: %d", _x, _y, board[_y][_x]);
        }
    }
    return bcheck;
}

void introBoard(void)            //오목판 함수
{
    printf("\n\n");
    if (board[0][0] == 0)   //첫번째줄
    {
        LetterColor(BLACK);
        printf("┌ ");
        LetterColor(WHITE);
    }
    else if (board[0][0] == 1)
    {
        LetterColor(BLACK);
        printf("●");
        LetterColor(WHITE);
    }
    else if (board[0][0] == -1)
    {
        LetterColor(WHITE);
        printf("●");
    }
    for (int i = 1; i < 18; i++)
    {
        if (board[0][i] == 0)
        {
            LetterColor(BLACK);
            printf("┬ ");
            LetterColor(WHITE);
        }
        else if (board[0][i] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            LetterColor(WHITE);
        }
        else if (board[0][i] == -1)
        {
            LetterColor(WHITE);
            printf("●");
        }
    }
    if (board[0][18] == 0)
    {
        LetterColor(BLACK);
        printf("┐ \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    else if (board[0][18] == 1)
    {
        LetterColor(BLACK);
        printf("●\n");
        LetterColor(WHITE);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    else if (board[0][18] == -1)
    {
        LetterColor(WHITE);
        printf("●\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }                           //여기까지가 첫번째줄
    for (int i = 1; i < 18; i++)      //두번째줄부터 18번째줄까지
    {
        if (board[i][0] == 0)
        {
            LetterColor(BLACK);
            printf("├ ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[i][0] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[i][0] == -1)
        {
            LetterColor(WHITE);
            printf("●");
        }
        for (int j = 1; j < 18; j++)
        {
            if (board[i][j] == 0)
            {
                LetterColor(BLACK);
                printf("┼ ");
                LetterColor(WHITE);
            }
            else if (board[i][j] == 1)
            {
                LetterColor(BLACK);
                printf("●");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            }
            else if (board[i][j] == -1)
            {
                LetterColor(WHITE);
                printf("●");
            }
        }
        if (board[i][18] == 0)
        {
            LetterColor(BLACK);
            printf("┤ \n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[i][18] == 1)
        {
            LetterColor(BLACK);
            printf("●\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[i][18] == -1)
        {
            LetterColor(WHITE);
            printf("●\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
    }                           //여기까지가 두번째줄

    if (board[18][0] == 0)   //마지막번째줄
    {
        LetterColor(BLACK);
        printf("└ ");
        LetterColor(WHITE);
    }
    else if (board[18][0] == 1)
    {
        LetterColor(BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    else if (board[18][0] == -1)
    {
        LetterColor(WHITE);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    for (int i = 1; i < 18; i++)
    {
        if (board[18][i] == 0)
        {
            LetterColor(BLACK);
            printf("┴ ");
            LetterColor(WHITE);
        }
        else if (board[18][i] == 1)
        {
            LetterColor(BLACK);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
        else if (board[18][i] == -1)
        {
            LetterColor(WHITE);
            printf("●");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        }
    }
    if (board[18][18] == 0)
    {
        LetterColor(BLACK);
        printf("┘ \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    else if (board[18][18] == 1)
    {
        LetterColor(BLACK);
        printf("●\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }
    else if (board[18][18] == -1)
    {
        LetterColor(WHITE);
        printf("●\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    }                        //여기까지가 마지막번째줄
}

void gotoxy(int x, int y)

{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void intro(void)
{
    int i = 0;
    int key;
    while (1)
    {
        gotoxy(0, 0);
        printf("");
        introBoard();
        gotoxy(0, 24);
        printf("   Enter을 누르면 게임을 시작합니다.\n");
        Sleep(500);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }

        gotoxy(18, 11);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
        Sleep(500);
        gotoxy(20, 11);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        Sleep(500);

        gotoxy(16, 10);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
        Sleep(500);
        gotoxy(18, 12);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        Sleep(500);

        gotoxy(20, 12);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
        Sleep(500);
        gotoxy(14, 9);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        Sleep(500);

        gotoxy(22, 13);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
        Sleep(500);
        gotoxy(18, 10);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        Sleep(500);

        gotoxy(24, 14);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + BLACK);
        printf("●");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (6 << 4) + WHITE);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }

        gotoxy(0, 24);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);

        if (_kbhit()) // 엔터키를 입력받았을 때 무한루프 탈출
        {
            key = _getch();
            if (key == 13)
            {
                system("cls");
                break;
            }
        }
    }
}

int main(void) {
    intro();
    int CurrentTurn = 1;   // 현재 턴을 받는 함수. 턴은 플레이어가 두거나 뺀 돌의 총 합과 동일하다.

    printf("\n\n-----------------오목 GAME--------------\n");

    printf("본 게임은 다양한 미니게임들이 종합된 퓨전오목 게임입니다\n");
    printf("섯다 게임을 통해서 선공을 정할 수 있습니다.\n");
    printf("내용을 이해하셨다면 1을 눌러주세요 : ");
    int t;
    scanf_s("%d", &t);
    if (t == 1) {
        system("cls");
    }

    // 섯다 호출
    while (1) {

        printf("\n\n-----------------섯다 GAME--------------\n");
        Sleep(Time1);
        printf("본 게임은 시작자금 10만원으로 진행하는 섯다 게임입니다\n");
        Sleep(Time1);
        printf("섯다 룰을 잘 모를 사람들을 위해 특수패는 삭제했습니다\n");
        Sleep(Time1);
        printf("n끗, n땡에서 n이 증가할수록 더 좋은 패이며 땡 전체가 끗보다 더 좋은 패입니다\n");
        Sleep(Time1);
        printf("13광땡,18광땡<38광땡이며 광땡일시 끗과 땡보다 더 좋은 패입니다\n");
        Sleep(Time1);
        printf("배팅과 다이는 선택이 가능하며 다이를 선택할시에 5000원의 기본요금이 빠져나갑니다\n");
        Sleep(Time1);
        printf("배팅은 자신의 돈보다 더 높은돈은 지불할 수 없으며 서로 배팅할시 나온 판돈은 승리자가 가져갑니다\n");
        Sleep(Time1);
        printf("수중에 있는돈이 모두 사라지면 패배하게 됩니다\n");
        Sleep(Time1);
        printf("내용을 이해하셨다면 1을 눌러주세요 : ");
        scanf_s("%d", &t);
        if (t == 1) {
            system("cls");
        }

        printf("-----------------섯다 GAME--------------\n");
        printf("1.---GAME START---\n");
        printf("2.--- NO GAME---\n");

        printf("원하시는 메뉴를 선택해 주세요 : ");
        int a;
        scanf_s("%d", &a);
        if (a == 1) {
            change = game();
            // game의 반환 값을  turnprint에 넣는다
            break;
        }
        else if (a == 2) {
            system("cls");
            break;
        }
    }

    // 본게임 호출
    while (1)
    {
        Board();
        printf("\n\n");
        turnprint(board, CurrentTurn);

        if (game_end(board) == 1)
        {
            break;
        }
        system("Cls");
        CurrentTurn++;
    }
    Board();
    return 0;
}
