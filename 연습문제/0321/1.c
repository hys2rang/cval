#include <stdio.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int won;
	double usd;
	printf("환율(원/달러) : ");
	scanf("%lf", &usd);
	printf("환전할 금액(원) : ");
	scanf("%d", &won);
	printf("%d원을 환전한 금액은 %.1lf 달러입니다.",won,won/usd);

	return 0;
}
