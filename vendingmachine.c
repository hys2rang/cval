#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
void show_menu(int money); //금액에 맞춰 메뉴를 보여줌 (메뉴 or 잔액부족)
int insert(int money);
char** drinks[6][2] = {	{"물","800"},{"콜라","1000"},{"환타","1100"},{"사이다","1200"},{"비타민","1500"},{"울트라","2000"}};
int main()
{
	int money;
	int sum = 0;

	do {
		printf("동전을 넣으시오(1000, 500, 100만 가능) : ");
		scanf("%d", &money);
	} while (!(sum=insert(money)));

	printf("총금액 : %d\n", sum);
	while (1) {
		int choice = -1;
		show_menu(sum);
		printf("음료선택 또는 금액추가 :");
		scanf("%d", &choice);
		if (choice == -1) {
			break;
		}
		if (choice <= 6) {
			show_menu(choice);
			sum -= atoi(drinks[choice - 1][1]);
		}
		else {
			if (insert(choice)) {
				sum += insert(choice);
			}
			else {
				printf("올바르지 않은 동전입니다...\n");
			}
		}
		printf("총금액 : %d\n", sum);
	}
	return 0;
}
void show_menu(int money)
{
	if (money <= 6) {
		printf("%d. %s %s원 선택\n", money,drinks[money-1][0],drinks[money-1][1]);
	}
	else {
		if (money >= 800) {
			for (int i = 0, cnt = 1; i < 6; i++, cnt++) {
				if (atoi(drinks[i][1]) <= money) {
					printf("%d. %s %s원\n", cnt, drinks[i][0], drinks[i][1]);
				}
			}
		}
		else {
			printf("잔액 부족\n");
		}		
	}
}
int insert(int money)
{
	if (money != 500 && money != 1000 && money != 100) {
		return 0;
	}
	return money;
}
