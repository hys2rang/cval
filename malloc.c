#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//사람마다 살고 있는 주소의 길이
//주소를 받아 주소의 길이만큼 heap에 동적할당하시오
//동적할당된 메모리 주소를 복사하고 출력
//동적영역의 해제
int main(int argc, char** argv)
{
	char* p;
	char buf[1100];
	gets(buf);

	p = (char*)malloc((strlen(buf)+1) *sizeof(char)); //null문자 까지 들어가야 하기 때문에 하나 더 추가

	strcpy(p, buf);
	puts(p);

	free(p);
	return 0;
}
