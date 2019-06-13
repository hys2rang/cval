#include <stdio.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int a, b;
	printf("2개의 정수를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	printf("%d + (%d) = %d\n",a,b,a+b);
	printf("%d - (%d) = %d\n",a,b,a-b);
	printf("%d * (%d) = %d\n",a,b,a*b);
	printf("%d / (%d) = %d\n",a,b,a/b);
	printf("%d %% (%d) = %d\n",a,b,a%b);
	return 0;
}
