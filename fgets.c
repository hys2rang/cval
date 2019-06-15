#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	char buf[100];
	FILE *fp;
	int idx = 1;
	fp = fopen("a.txt", "r");
	while (fgets(buf,100,fp)!= NULL) {
		printf("%d. %s", idx++, buf);
	}
	return 0;
}
