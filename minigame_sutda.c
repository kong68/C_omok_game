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

		printf("-----------------���� GAME--------------\n");

		printf("�� ������ �����ڱ� 10�������� �����ϴ� ���� �����Դϴ�\n");
		printf("���� ���� �� �� ������� ���� Ư���д� �����߽��ϴ�\n");
		printf("n��, n������ n�� �����Ҽ��� �� ���� ���̸� �� ��ü�� ������ �� ���� ���Դϴ�\n");
		printf("13����,18����<38�����̸� �����Ͻ� ���� ������ �� ���� ���Դϴ�\n");
		printf("���ð� ���̴� ������ �����ϸ� ���̸� �����ҽÿ� 5000���� �⺻����� ���������ϴ�\n");
		printf("������ �ڽ��� ������ �� �������� ������ �� ������ ���� �����ҽ� ���� �ǵ��� �¸��ڰ� �������ϴ�\n");
		printf("���߿� �ִµ��� ��� ������� �й��ϰ� �˴ϴ�\n");
		printf("������ �����ϼ̴ٸ� 1�� �����ּ���");
		int t;
		scanf_s("%d", &t);
		if (t == 1) {
			system("cls");
		}

		printf("-----------------���� GAME--------------\n");
		printf("1.---GAME START---\n");
		printf("2.--- NO GAME---\n");

		printf("���Ͻô� �޴��� ������ �ּ���");
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
		printf("���ӸӴϰ� 10������ ���޵˴ϴ�\n");
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
		printf("1�� ������ 3�ʰ� user1�� �и� �����ְڽ��ϴ�\n");
		scanf_s("%d", &c);
		if (c == 1) {
			printf("user1�� ī���\n");
			zokbo_print(user1_card_result);
			Sleep(3000);
			system("cls");
			printf("\n");
		}
		printf("1�� ������ 3�ʰ� user2�� �и� �����ְڽ��ϴ�\n");
		scanf_s("%d", &d);
		if (d == 1) {
			printf("user2�� ī���\n");
			zokbo_print(user2_card_result);
			Sleep(3000);
			system("cls");
			printf("\n");
		}
		int a, b;
		printf("user1 ���� �Ͻðڽ��ϱ�?\n");
		printf("1.����\n");
		printf("2.����\n");
		scanf_s("%d", &a);
		if (a == 1) {
			printf("user2 ���� �Ͻðڽ��ϱ�?\n");
			printf("1.����\n");
			printf("2.����\n");
			scanf_s("%d", &b);

			switch (b) {
			case 1:
				fight(user1_card_result, user2_card_result);
				break;
			case 2:
				while (1) {
					printf("user2 ���� �⺻������ 5000���� �����˴ϴ�\n");

					cash2 -= 5000;
					fflush(stdin);
					break;
				}
			}
		}
		else if (a == 2) {
			while (1) {
				printf("user1 ���� �⺻������ 5000���� �����˴ϴ�\n");
				cash1 -= 5000;
				printf("������ ��� �����Ͻ÷��� 1�� �����ּ���");
				fflush(stdin);
				scanf_s("%d", &menu);
				if (menu == 1)
					break;
			}

		}
		if (cash1 <= 0) {
			printf("user1 �Ļ� ����� �й��Դϴ�\n");
			printf("user2�� ���� �����ϼ���\n");
			break;


		}
		else if (cash2 <= 0) {
			printf("user2 �Ļ� ����� �й��Դϴ�\n");
			printf("user1�� ���� �����ϼ���\n");
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
		printf("38 �����Դϴ�\n");
		break;
	case 2:
		printf("18 �����Դϴ�\n");
		break;
	case 3:
		printf("13 �����Դϴ�\n");
		break;
	case 4:
		printf("�嶯�Դϴ�\n");
		break;
	case 5:
		printf("9���Դϴ�\n");
		break;
	case 6:
		printf("8���Դϴ�\n");
		break;
	case 7:
		printf("7���Դϴ�\n");
		break;
	case 8:
		printf("6���Դϴ�\n");
		break;
	case 9:
		printf("5���Դϴ�\n");
		break;
	case 10:
		printf("4���Դϴ�\n");
		break;
	case 11:
		printf("3���Դϴ�\n");
		break;
	case 12:
		printf("2���Դϴ�\n");
		break;
	case 13:
		printf("1���Դϴ�\n");
		break;
	case 14:
		printf("9���Դϴ�\n");
		break;

	case 15:
		printf("9���Դϴ�\n");
		break;

	case 16:
		printf("8���Դϴ�\n");
		break;

	case 17:
		printf("7���Դϴ�\n");
		break;
	case 18:
		printf("6���Դϴ�\n");
		break;
	case 19:
		printf("5���Դϴ�\n");
		break;
	case 20:
		printf("4���Դϴ�\n");
		break;
	case 21:
		printf("3���Դϴ�\n");
		break;
	case 22:
		printf("2���Դϴ�\n");
		break;
	case 23:
		printf("1���Դϴ�\n");
		break;
	}
}
void fight(user1_card_result, user2_card_result) {
	int bet_money1;
	int bet_money2;
	while (1) {
		system("cls");
		printf("user1 �󸶸� �����Ͻðڽ��ϱ�?\n");
		printf("user1 ����� ���� �ݾ���%d �Դϴ�\n", cash1);
		printf("���ñݾ�:\n");
		scanf_s("%d", &bet_money1);



		printf("user2 �󸶸� �����Ͻðڽ��ϱ�?\n");
		printf("user2 ����� ���� �ݾ���%d �Դϴ�\n", cash2);
		printf("���ñݾ�:\n");
		scanf_s("%d", &bet_money2);

		break;


	}
	printf("user1�� ī���\n");
	zokbo_print(user1_card_result);
	printf("user2�� ī���\n");
	zokbo_print(user2_card_result);

	if (user1_card_result < user2_card_result) {
		printf("user1�� user2�� ������ �ݾװ� �ڽ��� ������ �ݾ��� ������ �˴ϴ�\n");
		cash1 += bet_money2;
		cash2 -= bet_money2;
		printf("user1�� ���� ���� �ݾ���: %d\n", cash1);
		printf("user2�� ���� ���� �ݾ���: %d\n", cash2);
	}

	else if (user1_card_result > user2_card_result) {
		printf("user2�� user1�� ������ �ݾװ� �ڽ��� ������ �ݾ��� ������ �˴ϴ�\n");
		cash2 += bet_money1;
		cash1 -= bet_money1;
		printf("user1�� ���� ���� �ݾ���: %d\n", cash1);
		printf("user2�� ���� ���� �ݾ���: %d\n", cash2);
	}

	else if (user1_card_result == user2_card_result) {
		printf("���� ���� �����մϴ�\n");
		count--;
	}



}