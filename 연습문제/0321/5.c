#include <stdio.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int a, b;
	int res;

	printf("과자 판매액(만원) : ");
	scanf("%d", &a);
	printf("음료수 판매액(만원) : ");
	scanf("%d", &b);
	res = a * 0.15 + b * 0.1;
	printf("오늘의 수익(만원) : %d", res);
	return 0;
}
