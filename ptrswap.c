#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
void swap1(int *a, int *b) { //main에 위치한 a, b 변수의 주소를 전달 받아 a,b 값을 교환하는 함수
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap2(int **ap, int **bp) {//ap, bp 변수의 주소를 전달 받아 a, b값을 교환하는 함수
	int tmp = **ap;
	**ap = **bp;
	**bp = tmp;
}
void swap3(int ***app, int ***bpp) {//app, bpp 변수의 주소를 받아 a, b의 값을 교환하는 함수
	int tmp = ***app;
	***app = ***bpp;
	***bpp = tmp;
}
void swap4(int **ap, int **bp) {//ap, bp 변수의 주소를 전달 받아 ap, bp 값을 교환하는 함수
	int* tmp= *ap;
	*ap = *bp;
	*bp = tmp;
}
void swap5(int ***app, int ***bpp) {//app, bpp 변수의 주소를 전달 받아, ap, bp 값을 교환하는 함수
	int *tmp = **app;
	**app = **bpp;
	**bpp = tmp;
}
void swap6(int ***app, int ***bpp) {//app, bpp 변수의 주소를 받아, app, bpp 값을 교환하는 함수
	int tmp = ***app;
	***app = ***bpp;
	***bpp = tmp;
}
int main()
{
	int a = 10, b = 20;
	int *ap = &a, *bp = &b;
	int **app = &ap;
	int **bpp = &bp;

	swap1(&a, &b);
	printf("a : %d a : %d\n",a, b);
	swap2(&ap, &bp);
	printf("a : %d a : %d\n",a, b);
	swap3(&app, &bpp);
	printf("a : %d a : %d\n",a, b);
	swap4(&ap, &bp);
	printf("ap : %d bp : %d\n", *ap, *bp);
	swap5(&app, &bpp);
	printf("ap : %d bp : %d\n", *ap, *bp);
	swap6(&app, &bpp);
	printf("app : %d bpp : %d\n", **app, **bpp);
	return 0;
}
