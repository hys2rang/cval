#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printInt(int* arr, int size);
void printDbl(double* arr, int size);
void printstr(char(*arr)[7], int size);

int comp_i(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

//라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
int comp_d(const void* a, const void* b) {
	if (*(double*)a > * (double*)b) {
		return 1;
	}
	else if (*(double*)a < *(double*)b) {
		return -1;
	}
	else {
		return 0;
	}
}

//라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
int comp_s(const void* a, const void* b) {
	return (strcmp((char*)a, (char*)b));
}

int main(void) {
	int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
	double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5 };
	char arrs[][7] = { "권순준","권철희","김진우","김희원","성준호","이상수","이지혜","정민호","조남수","임지윤",
   "윤기석","이민규","유호준","이규석","정우섭","지혜승","조은성","이규헌","전현수","정기홍" };

	//int형 배열 정렬
	qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(int), comp_i);
	printInt(arri, sizeof(arri) / sizeof(arri[0]));

	//double형 배열 정렬
	qsort(arrd, sizeof(arrd) / sizeof(arrd[0]), sizeof(double), comp_d);
	printDbl(arrd, sizeof(arrd) / sizeof(arrd[0]));

	//라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.

	qsort(arrs, sizeof(arrs) / sizeof(arrs[0]), sizeof(arrs[0]), comp_s);
	printstr(arrs, sizeof(arrs) / sizeof(arrs[0]));

	return 0;
}
void printInt(int* arr, int size) {
	int dx = 0;
	for (dx = 0; dx < size; ++dx) {
		printf("%d ", arr[dx]);
	}
	printf("\n");
}

void printDbl(double* arr, int size) {
	int dx = 0;
	for (dx = 0; dx < size; ++dx) {
		printf("%.1f  ", arr[dx]);
	}
	printf("\n");
}

void printstr(char(*arr)[7], int size) {
	int dx = 0;
	for (dx = 0; dx < size; ++dx) {
		printf("%s ", arr[dx]);
	}
	printf("\n");
}
