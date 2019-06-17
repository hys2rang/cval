#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//양쪽 끝에 더미노드를 만들어서 이해
/*
*/
typedef struct _list List;
struct _list {
	int key;
	struct _list* next;
};
List* head, * tail;
void init_list(void)//초기화
{
	head = (List*)malloc(sizeof(List)); //왼쪽기둥
	tail = (List*)malloc(sizeof(List));//오른쪽 빨래기둥
	head->next = tail;
	tail->next = tail; //tail이 자기 자신을 가르키게 null이 아닌 상태로 null이면 굳이 loop를 돌 필요가 없음
}
void insert_list(int data)
{
	List* node;
	node = (List*)malloc(sizeof(List));
	node->key = data;
	node->next = head->next;
	head->next = node;
}
void print_list() //head오ㅏ tail 사이의 각 노드 데이터 출력
{
	List* node = head->next;//기둥이 아닌 바로 옆 첫번째 노드의 주소
	while (node != tail) { //tail이 아니면
		printf("%d ", node->key);
		node = node->next;
	}
}

void remove_list(int data)
{
	List* node = head; //시작 dummy 노드를 알려줌
	List* delete_node;//for free memory
	while (node->next->key != data && node->next!=node) { ////못찾았으면 옆칸으로 가겠
		node = node->next;
	}
	delete_node = node->next;
	node->next = node->next->next;//찾았으면 
	free(delete_node); //있어야됨
}
void movetofront(int data)
{
	List* node = head; //시작 dummy 노드를 알려줌
	List* delete_node;//for free memory
	while (node->next->key != data && node->next != node) { ////못찾았으면 옆칸으로 가겠
		node = node->next;
	}
	delete_node = node->next;
	node->next = node->next->next;//찾았으면 

	delete_node->next = head->next;
	head->next = delete_node;
}
int main(int argc, char** argv)
{
	init_list(); //리스트 자료구조의 초기화
	insert_list(3);
	insert_list(4);
	insert_list(5);
	print_list();
	puts("");
	remove_list(3);
	print_list();
	puts("");
	insert_list(2);
	print_list();
	puts("");

	movetofront(5);
	print_list();
	puts("");

	insert_list(8);
	print_list();
	puts("");

	return 0;
}
