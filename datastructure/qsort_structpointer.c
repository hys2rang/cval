#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
typedef struct _node node;
struct _node {
	char name[10];
	struct _node* next;
};
//int gg = 0;
int cmp_node(const void* a, const void* b) //pointer 배열의 주소를 넘겨받는것
{
	return strcmp((*(node**)a)->name, (*(node * *)b)->name);
}
node* p, * q;
main()
{
	node* k[4];

	p = (node*)malloc(sizeof(node));
	strcpy(p->name, "ccc");
	p->next = NULL;
	q = (node*)malloc(sizeof(node));
	strcpy(q->name, "aaa");
	q->next = NULL;


	k[0] = p;
	k[1] = q;
	k[2] = (node*)malloc(sizeof(node));
	strcpy(k[2]->name, "bbb");
	qsort(k, 3, sizeof(node*), cmp_node);

	puts("\n-----");
	printf("%s\n", k[0]->name);
	printf("%s\n", k[1]->name);
	printf("%s\n", k[2]->name);

}
