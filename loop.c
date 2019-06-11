#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int sum = 0;
	int a, b;
  //1부터 10까지의 합
	for (int i = 1; i <= 10; i++) {
		sum += i;
	}
	printf("%d\n", sum);

	sum = 0;
  
  //100까지의 짝수의 합
	for (int i = 2; i <= 100; i += 2) {
		sum += i;
	}

	printf("%d\n", sum);

	sum = 0;
  //100까지 3의 배수 출력
	for (int i = 3; i <= 100; i += 3) {
		printf("%d ", i);
	}

	printf("\n");
  //100까지 3과 7의 배수 출력
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0 || i % 7 == 0) {
			printf("%d ", i);
		}
	}

	printf("\n");
  //두 수 사이의 숫자들 작은거부터 큰거대로 출력
	printf("두 수를 입력하세요 : ");
	scanf("%d%d", &a, &b);

	for (int i = (a<b?a:b); i <= (a<b?b:a); i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (j == i) {
				printf("-");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
  //
	for (int i = 1; i <= 9; i++) {
		for (int j = 2; j <= 9; j++) {
			printf("%d * %d = %2d\t", j, i, j*i);
		}
		printf("\n");
	}
	return 0;
}
