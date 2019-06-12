#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int ispalindrome(char *str);
int main(int argc, char** argv)
{
	char arr[] = "abba";
	if (ispalindrome(arr)) {
		printf("회문입니다.\n");
	}
	else {
		printf("회문이 아닙니다.\n");
	}
	return 0;
}
int ispalindrome(char *str)
{
	int i=0,j=0;
	while (str[i++]);

	while (j <= i - 2) {
		if (str[j++] != str[i-- - 2]) {
			return 0;
		}
	}
	return 1;
}
