#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int a, b;
	double res;
	char ch = argv[2][0];
	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if (ch == '/' && !b) {
		printf("0은 나눌 수 없습니다.");
		return 0;
	}
	printf("%d %c %d = ", a, ch, b);

	switch (ch)
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = a / (float)b;
		break;
	}
	printf("%.2f\n", res);
	return 0;
}
