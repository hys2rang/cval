#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef int(*fp)(int, int);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int main(int argc, char** argv)
{
	void *p[5][2] = { add,"ADDITION",sub,"SUBTRACTION",mul,"MULTIPLY",div,"DIVIDE" };
	int choice = 0;
	for (int i = 0; i < 4; i++) {
		printf("%d. %s\n", i + 1, (char*)p[i][1]);
	}

	printf("번호를 선택하세요 : ");
	scanf("%d", &choice);

	printf("결과는 : %d", ((int(*)(int, int))p[choice - 1][0])(10, 5));
	return 0;
}
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}

