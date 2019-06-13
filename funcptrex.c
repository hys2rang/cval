#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int add(int a, int b)
{
	return a + b;
}

int temp(int(*p_func)(int,int),int a, int b) {
	return p_func(a,b);
}
int main(int argc, char** argv)
{
	int a = 10, b = 5;
	
	printf("%d", temp(add, a, b));
	return 0;
}
