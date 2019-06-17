#define _CRT_SECURE_NO_WARNINGS
#define STACK_SIZE 5
#include<stdio.h>
#include<string.h>
#define QUEUE_SIZE 5
int queue[QUEUE_SIZE];
int front, rear;
void init_queue()
{
	front = rear = 0;
}
void put(int data)
{
	queue[rear++] = data;
	rear = ++rear % QUEUE_SIZE;
}
int get(void)
{
	int save = queue[front];
	front = ++front % QUEUE_SIZE;
	return save;
}
/*
queue는 push, pop 둘 다 빨라야된다
queue는 circular로
*/
main()
{
	init_queue();
	put(3);
	put(2);
	put(1);
	put(1);
	put(1);
	put(1);

	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
	printf("%d \n", get());
}
