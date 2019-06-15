#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct engine Engine;
typedef struct car Car;
struct engine {
	int piston;
	int fan;
	int pipe;
};
struct car {
	Engine *seden, *sport;
};
void hyundai(Car *man) //체이닝 제거
{
	Engine *p = man->seden; //계속 타고 들어가는 것의 주소를 미리 알려줌
	p->piston = 50;
	p->fan = 30;
	p->pipe = 20;
}
int main(int argc, char** argv)
{
	Car hi;
	hi.seden = (Engine *)malloc(sizeof(Engine)); //seden, sport는 구조체 포인터 변수이므로 struct size의 메모리를 할당 받은 것이 아님
	hyundai(&hi);
	printf("%d %d %d \n", hi.seden->piston, hi.seden->fan, hi.seden->pipe);
	return 0;
}
