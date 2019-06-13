#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));
	int arr[45];
	for (int i = 0; i < 45; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0, n = 45; i < 6; i++,n--) {
		int randnum = (rand() % 45) + 1;
		printf("randnum = :%d\n", randnum);
		arr[randnum] = n;
	}
	for (int i = 0; i < 45; i++) {
		printf("%2d ", arr[i]);
		if ((i+1) % 9 == 0) {
			puts("");
		}
	}
	return 0;
}
