#include <stdio.h>

#pragma warning(disable:4996)

void put_s(char* p) //'f'문자가 나오기 전까지 출력
{
	int idx = 0;
	while (*p!='f') {
		printf("%c", *p++);
	}
}
int main()
{
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	put_s(arr);

	return 0;
}
