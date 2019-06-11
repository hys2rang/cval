#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

int main()
{
	//int arr[5] = {3,4,1,5,2}; 배열 a를 보는 포인터 변수 p를 선언하고 p를 사용하여 a내ㅜ의 요소들을 출력하시오
	int arr[5] = { 3,4,1,5,2 };
	int *p = arr;
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		printf("%d ", *(p + i));
    //*(p + i) == p[i] == arr[i] == *(arr+i)
	}
	return 0;
}
