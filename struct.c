#include <stdio.h>
#pragma warning(disable:4996)
typedef struct num Num;
struct num
{
	int fir;
	int sec;
};
void func1(int fir, int second)
{
	printf("%d\n", fir + second);
}
void func2(Num *n)
{
	printf("%d\n", n->fir*n->sec);
}
void func3(Num *n)
{
	int sum = 0;
	sum += n->fir + n->sec+(n+1)->fir+(n+1)->sec;
	printf("%d\n", sum);
}
int main(int argc, char** argv)
{
	struct num a = { 1,2 }, b = { 3,4 }, c[2] = { 5,6,7,8 };

	//구조체 멤버 각각 던져서 합
	func1(a.fir, a.sec);
	//구조체 변수주소 던져서 곱
	func2(&b);
	//구조체 배열주소 던져서 합
	func3(c);
	return 0;
}
