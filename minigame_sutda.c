#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int cash1 = 0;
int cash2 = 0;
int count = 0;
int game();
void zokbo_print(result_card);
void fight(user1_card_result, user2_card_result);



int main() {
	while (1) {

		printf("-----------------섯다 GAME--------------\n");

		printf("본 게임은 시작자금 10만원으로 진행하는 섯다 게임입니다\n");
		printf("섯다 룰을 잘 모를 사람들을 위해 특수패는 삭제했습니다\n");
		printf("n끗, n땡에서 n이 증가할수록 더 좋은 패이며 땡 전체가 끗보다 더 좋은 패입니다\n");
		printf("13광땡,18광땡<38광땡이며 광땡일시 끗과 땡보다 더 좋은 패입니다\n");
		printf("배팅과 다이는 선택이 가능하며 다이를 선택할시에 5000원의 기본요금이 빠져나갑니다\n");
		printf("배팅은 자신의 돈보다 더 높은돈은 지불할 수 없으며 서로 배팅할시 나온 판돈은 승리자가 가져갑니다\n");
		printf("수중에 있는돈이 모두 사라지면 패배하게 됩니다\n");
		printf("내용을 이해하셨다면 1을 눌러주세요");
		int t;
		scanf_s("%d", &t);
		if (t == 1) {
			system("cls");
		}

		printf("-----------------섯다 GAME--------------\n");
		printf("1.---GAME START---\n");
		printf("2.--- NO GAME---\n");

		printf("원하시는 메뉴를 선택해 주세요");
		int a;
		scanf_s("%d", &a);
		if (a == 1) {
			game();
			break;
		}
		else if (a == 2) {
			system("cls");
			break;
		}



	}

}
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
		printf("게임머니가 10만원씩 지급됩니다\n");
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
		printf("1을 누르면 3초간 user1의 패를 보여주겠습니다\n");
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
				printf("게임을 계속 진행하시려면 1을 눌러주세요");
				fflush(stdin);
				scanf_s("%d", &menu);
				if (menu == 1)
					break;
			}

		}
		if (cash1 <= 0) {
			printf("user1 파산 당신의 패배입니다\n");
			printf("user2가 오목 선공하세요\n");
			break;


		}
		else if (cash2 <= 0) {
			printf("user2 파산 당신의 패배입니다\n");
			printf("user1이 오목 선공하세요\n");
			break;
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