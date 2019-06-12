#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

//main에 위치한 a,b 변수의 주소를 전달 받아 a,b값을 교환하는 함수
void swap1(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//ap, bp 변수의 주소를 전달 받아 a, b 값을 교환하는 함수
void swap2(int **ap, int **bp)
{
	int tmp = **ap;
	**ap = **bp;
	**bp = tmp;
}
//app, bpp 변수의 주소를 전달 받아 a, b 값을 교환하는 함수
void swap3(int ***app, int ***bpp)
{
	int tmp = ***app;
	***app = ***bpp;
	***bpp = tmp;
}
//ap, bp 변수의 주소를 전달 받아 ap, bp 값을 교환하는 함수
void swap4(int **ap, int **bp)
{
	int *tmp = *ap;
	*ap = *bp;
	*bp = tmp;
}
//app, bpp 변수의 주소를 전달 받아 ap, bp 값을 교환하는 함수
void swap5(int ***app, int ***bpp)
{
	int *tmp = **app;
	**app = **bpp;
	**bpp = tmp;
}
//app, bpp 변수의 주소를 전달 받아 app, bpp 값을 교환하는 함수
void swap6(int ***app, int ***bpp)
{
	int *tmp = *app;
	*app = *bpp;
	*bpp = tmp;
}
int main(int argc, char** argv)
{
	int a = 10, b = 20;
	int *ap = &a, *bp = &b;
	int **app = &ap;
	int **bpp = &bp;
	
	swap1(&a, &b);
	printf("a : %d b : %d\n", a, b);
	swap2(&ap, &bp);
	printf("a : %d b : %d\n", a, b);
	swap3(&app, &bpp);
	printf("a : %d b : %d\n", a, b);
	swap4(&ap, &bp);
	printf("a : %d b : %d\n", *ap, *bp);
	swap5(&app, &bpp);
	printf("a : %d b : %d\n", *ap, *bp);
	swap6(&a, &b);
	printf("a : %d b : %d\n", **app, **bpp);

	return 0;
}
