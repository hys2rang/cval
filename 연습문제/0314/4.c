#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int width, height;
	printf("== 사각형의 면적계산프로그램 ==\n");
	printf("사각형의 가로 길이 : ");
	scanf("%d", &width);
	printf("사각형의 세로 길이 : ");
	scanf("%d", &height);
	printf("사각형의 면적은 %d입니다.", width*height);
	return 0;
}
