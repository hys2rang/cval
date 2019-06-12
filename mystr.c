#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void my_strcpy(char *a, char *b)
{
	while (*a++ = *b++);
}
void my_strcat(char *dst, char* src) {
	while (*dst) {
		*dst++;//내부로 들어가면 마지막 null문자까지 가고 그다음 지점을 포인터가 가르킴
	}
	while (*dst++ = *src++);
}
int main()
{
	char buf[10], src[10] = "abcd";
	
	my_strcpy(buf, src);
	my_strcat(buf,"xyz");
	puts(buf);
	return 0;
}
