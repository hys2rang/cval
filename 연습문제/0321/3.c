#include <stdio.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	double a, b, c;

	printf("친구 3명의 키(cm) : ");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("평균 키(cm) : %.1f", (a + b + c) / 3);
	return 0;
}
