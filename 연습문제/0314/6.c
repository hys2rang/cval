#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	float width;
	float height;

	printf("== 삼각형의 면적계산 프로그램 ==\n");
	printf("삼각형의 가로길이 : ");
	scanf("%f", &width);
	printf("삼각형의 세로길이 : ");
	scanf("%f", &height);
	printf("삼각형의 면적은 %.2f 입니다.", width*height*0.5);
	return 0;
}
