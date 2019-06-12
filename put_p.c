#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void put_p(char **p)
{
	//abcd의 abcd를 출력하는 여러가지 구문
	printf("%s\n", p[0]);
	printf("%s\n", *p);
	//insert의 sert를 출력하는 여러가지 구문
	printf("%s\n", p[1] + 2);
	printf("%s\n", *(p + 1) + 2);
	printf("%s\n", &p[1][2]);
	printf("%s\n", &(*(p+1))[2]);	
	//home의 m을 출력하는 여러가지 구문
	printf("%c\n", p[2][2]);
	printf("%c\n", *(*(p+2)+2));
	printf("%c\n", (*(p+2))[2]);
	printf("%c\n", *(p[2]+2));
}
int main(int argc, char** argv)
{
	char*p[3] = { "abcd","insert","home" };

	put_p(p);
	return 0;
}
