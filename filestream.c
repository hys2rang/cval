#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 19
typedef struct item Item;
struct item {
	char item[100];
	int price;
	int cnt;
	int total_price;
};
Item items[MAX];
int getitemidx(char* str);
int main(int argc, char** argv)
{
	FILE *fp_item, *fp_sales;
	fp_item = fopen("item.txt", "r");
	char buf[100];
	
	int idx = 0;
	int num;
	while (fscanf(fp_item, "%s %d", buf, &num) != EOF) {
		strcpy(items[idx].item, buf);
		items[idx++].price = num;
	}
	fp_sales = fopen("sales.txt", "r");
	while (fscanf(fp_sales, "%s %d", buf, &num) != EOF) {
		int i = getitemidx(buf);
		items[i].cnt = num;
		items[i].total_price = items[i].cnt * items[i].price;
	}

	printf("===========================================================\n");
	printf("\t상품명\t\t단가\t개수\t\t금액\n");
	printf("===========================================================\n");
	for (int i = 0; i < MAX; i++) {
		printf("%d\t%13s\t%d\t%d\t%d\n", i + 1, items[i].item, items[i].price, items[i].cnt, items[i].total_price);
	}
	printf("===========================================================\n");
	return 0;
}
int getitemidx(char* str)
{
	for (int i = 0; i < MAX; i++) {
		if (!strcmp(str, items[i].item)) {
			return i;
		}
	}
	return -1;
}
