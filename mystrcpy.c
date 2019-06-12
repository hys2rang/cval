#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
void my_strcpy(char *a, char *b)
{
	while (*b) {
		*a++ = *b++;
	}
	*a = NULL;
}
int main()
{
	char buf[10], src[10] = "abcd";
	
	my_strcpy(buf, src);
	puts(buf);
	return 0;
}
