#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void my_strrev(char *str);
int main(int argc, char** argv)
{
	char arr[] = "hello world";
	my_strrev(arr);
	puts(arr);
	return 0;
}
void my_strrev(char *str)
{
	char buf[20] = "";
	int idx=0;
	while (str[idx++] != NULL);
	for (int i = idx - 2; i >= 0; i--) {
		buf[idx - i - 2] = str[i];
	}
	strcpy(str, buf);
}
