#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable:4996)

int my_atoi(char* str);
int main(int argc, char** argv)
{
	printf("%d", my_atoi("123456"));

	return 0;
}
int my_atoi(char* str)
{
	int ans = 0;
	for (int i = strlen(str)-1; i >= 0; i--) {
		ans += (str[i] - '0')*pow(10,strlen(str)-i-1);
	}
	return ans;
}
