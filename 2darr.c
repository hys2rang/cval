#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
#define MAX -400000;
int main()
{
	int a[2][3] = { 1,2,3,4,5,6 };
	//2챠원 배열을 출력하시오 행의 합과 열의 합을 출력하시오

	for (int i = 0; i < 2; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
			sum += a[i][j];
		}
		printf("| %d\n", sum);
	}
	puts("----------");

	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 2; j++) {
			sum += a[j][i];
		}
		printf("%d ", sum);
	}
	printf("|");
	return 0;
}
