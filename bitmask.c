#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	int a = 0xA5;

	if (a & (1 << 6)) {
		puts("true");
	}
	else {
		puts("false");
	}
	//a = a | (5 << 1);
	a |= (1<<3) + (1<<1);
	printf("%x\n", a);

	//a = a & (~6);
	a &= !((1<<1)+(1<<2));
	printf("%x\n", a);
	printf("%x\n", a&(7 << 5));

	return 0;
}
