#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int add(int a, int b) {
	return a + b;
}
int main(int argc, char** argv)
{

	/*
	void* voidptr;
int (*fptr)(int);
fptr = (int (*)(int))voidptr;
	*/
	void *p;
	p = add;
	//p로 10과 5를 더하는 add함수를 호출하시오
	//int(*p)(int,int)에서 p만 빼고 표현
	printf("%d\n", ((int(*)(int))p)(10, 5));
	return 0;
}
