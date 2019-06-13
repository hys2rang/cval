#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	float dist;
	float fuel;
	printf("총주행거리(km) : ");
	scanf("%f", &dist);
	printf("총연료소모량(L) : ");
	scanf("%f", &fuel);
	printf("당신 차량의 연비는 %.4f (km/L)입니다.", dist / fuel);
	return 0;
}
