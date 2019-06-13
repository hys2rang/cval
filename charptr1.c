#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int argc, char** argv)
{
	char **p;
	char buf[150] = "\0";
	int cnt;
	printf("원하는 문장의 갯수를 입력하세요? ");
	scanf("%d", &cnt);
	
	p = (char**)malloc(cnt * sizeof(char *));
	getchar(); //입력 버퍼 비우기
	for (int i = 0; i < cnt; i++) {
		printf("%d번째 문장은?\n",i+1);
		gets(buf);
		p[i] = (char *)malloc(sizeof(char)*(strlen(buf) + 1));
		strcpy(p[i], buf);
	}

	for (int i = 0; i < cnt; i++) {
		printf("%d번째 문장은 %s입니다.\n", i + 1, p[i]);
	}
	
	for (int i = 0; i < cnt; i++) {
		free(p[i]);
	}

	free(p);
	return 0;
}
