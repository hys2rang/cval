#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}
int main()
{
	//a=10, pa가 a 주소를 갖는다.
	//b=5, pb가 b의 주소를 갖는다.

	int a = 10, b = 5;
	int tmp;
	int *pa, *pb;
	pa = &a;
	pb = &b;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;

	printf("pa : %d pb : %d\n", *pa, *pb);
	swap(&a, &b);
	printf("pa : %d pb : %d", *pa, *pb);
	
	return 0;
}
