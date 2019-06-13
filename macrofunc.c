#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
//제곱이 되도록
#define square(x) ((x)*(x))
//x값을 출력
#define PR(x) printf("%d\n",x)
//절대값을 출력해주는 매크로
#define ABS(x) x>0?x:x*(-1)
//최댓값
#define THREE_MAX(a,b,c) a>(b>c?b:c)?a:(b>c?b:c)
//swap
#define SWAP(x,y)do{int tmp = x; x = y; y = tmp;}while(0)
int main(int argc, char** argv)
{
	int a = 123, b = 111, c = 321;
	printf("%d\n", 25 / square(5));
	PR(b);
	printf("%d\n", ABS(-2));
	printf("%d\n", THREE_MAX(a, b, c));
	if (a > b)
		SWAP(a, b);
	else
		SWAP(b, c);
	PR(a);
	PR(b);
	PR(c);
	return 0;
}
