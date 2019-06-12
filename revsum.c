#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int a, b,cnt;
	char* num = argv[1];
	cnt = atoi(argv[2]);

	for (int i = 0; i < cnt; i++) {
		a = atoi(num);
		b = atoi(strrev(num));
		printf("  %d\n", a);
		printf("+ %d\n", b);
		printf("------\n");
		printf("  %d\n\n", a + b);
		itoa(a + b, num, 10);
	}
	return 0;
}
