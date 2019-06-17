#define _CRT_SECURE_NO_WARNINGS
#define STACK_SIZE 5
#include<stdio.h>
#include<string.h>

int stack[STACK_SIZE];
int top;
/*
stack example
1. 컴파일러가 중위를 후위로 바꾼다.
- 왼쪽 괄호는 무조건 push
- 피연산자는 출력(console, array)
- 연산자는 stack에 push(연산자 우선순위가 높으면 push, (stack에 있는 것의 우선순위가 높을경우 이를 먼저 처리))
2. 후위를 계산식
- 피연산자는 push

	*
   / \
  7   8
- 연산자를 만나면 첫번째 pop한게 오른쪽, 두번째 pop한게 왼쪽에 둔 후 계산결과를 stack에 push
*/
void init_stack(void)
{
	top = -1;
}
void push(int data)
{
	if (top >= STACK_SIZE-1) {
		puts("stack full");
		return;
	}
	stack[++top] = data;
}
int pop(void)
{
	if (top == -1) {
		puts("stack empty");
		return -1;
	}
	return stack[top--];
}
main()
{
	//FIFO
	init_stack();
	push(3);
	push(5);
	push(4);
	push(4);
	push(4);
	push(2);
	push(2);
	push(2);

	while (top != -1) {
		printf("%d\n", pop());
	}
}
