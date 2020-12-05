#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define Turn 31

int BaskinRobbins(void)
{
	srand((unsigned) time(NULL));
	//a는 순서를 정해주는 난수를 저장하는 변수입니다. MaxCnt는 1~3까지의 입력받은 값을 저장합니다. Value는 1~31까지 증가시키면서 출력해줍니다.
	int a, MaxCnt, Value; 
	char AB[2] = { 'A', 'B' };
	
	Value = 1;
	a = rand() % 2;		//a가 0이면 A의 턴, 1이면 B의 턴이다.

	printf("게임은 베스킨라빈스31입니다.\n");
	printf("\n\t\t<--Baskin_Rabins_31-->\n\n"
		" ====================[How To Play]====================\n"
		" [1] 1부터 시작해서 31까지 번갈아가며 숫자를 부른다.\n"
		" [2] 한번에 최대 3번까지 연속된 숫자를 말할 수 있다.\n"
		" [3] 31을 말하는 플레이어가 게임에서 패배한다.\n"
		" =====================================================\n\n");
	printf("	[선공은 랜덤으로 %c가 먼저 입니다.]\n", AB[a]);
	printf("     숫자 입력은 1~3까지 입력할 수 있습니다.\n\n");

	
	

	while (1)
	{
		puts("");
		printf("%c의 턴입니다.\n", AB[a]);		
		switch (a)		//순서를 바꿔주는 코드
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
		
		if (MaxCnt > 3 || MaxCnt < 0)					//입력한 값이 0보다 작고 3보다 크면 다시 입력하도록 합니다.
		{
			while (MaxCnt > 3 || MaxCnt < 0)
			{
				printf("1 ~ 3까지 다시 입력해주세요. : ");
				scanf_s("%d", &MaxCnt);
			}
		}
			
		printf("입력받은 숫자 : ");

		for (int i = 0; i < MaxCnt; i++)		//MaxCnt만큼 반복시켜 줍니다. 반복시키면서 Value(1부터)를 1씩증가시켜 출력시켜줍니다.
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
			break;
		}
	}

	if (AB[a] == 'A')
	{
		return 1;
	}
	else if (AB[a] == 'B')
	{
		return 0;
	}

}

int main(void)
{
	printf("%d", BaskinRobbins());
	return 0;
}
