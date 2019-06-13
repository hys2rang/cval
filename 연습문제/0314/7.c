#include <stdio.h>
#pragma warning(disable:4996)

int calc(int a, int b,char ch);
int main(int argc, char** argv)
{
	int a, b;

	char ch[3] = { '+','-','*' };
	printf("2개의 정수를 입력하세요 : ");
	scanf("%d %d", &a, &b);
	
	for (int i = 0; i < 3; i++) {
		printf("%d %c %d = %d\n", a, ch[i], b,calc(a,b,ch[i]));
	}
	return 0;
}
int calc(int a, int b, char ch)
{
	int res = 0;
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
	}
	return res;
}
