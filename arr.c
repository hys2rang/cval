#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
#define MAX -400000;
int main()
{
	//int형 배열 5개짜리 임의의 값을 넣는다. 배열 모든 요소 출력, 모든 요소의합, 가장 큰값
	int arr[5];
	int max = MAX;
	int sum = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
		if (max < arr[i]) {
			max = arr[i];
		}
		sum += arr[i];
	}
	puts("");
	printf("sum : %d\n", sum);
	printf("max : %d", max);
  
  
	return 0;
}
