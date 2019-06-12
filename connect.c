#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
void connect(int **p, int *v) {
	*p = v;
}
int main()
{
	int a;
	int b = 7;
	int *p;
	int **k;

	//p를 사용하여 a에 10을 넣고 출력
	p = &a;
	*p = 10;
	printf("%d\n", a);
	//k를 사용하여 a에 20을 넣고 출력
	k = &p;
	**k = 20;
	printf("%d\n", a);

	connect(&p, &b);

	printf("%d\n", *p);
	return 0;
}
