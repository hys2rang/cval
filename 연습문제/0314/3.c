#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int age;
	printf("나이를 입력하세요 : ");
	scanf("%d", &age);

	printf("여러분은 10년 후에 %d살입니다.", age + 10);
	return 0;
}
