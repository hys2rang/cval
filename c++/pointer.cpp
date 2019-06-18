#include <iostream>

using namespace std;


int main()
{
	char** a; //더블포인터
	char* b[2]; //포인터 배열
	char c[2][3]; //배열
	char* d[2][3] = { "aa","bb","cc","dd","ee","ff" };
	char(*e)[2][3];
	char(*f[2])[3];//3개짜리를 보는 포인터 배열 2개

	char*** ap = &a;
	char**bp = b;
	char(*cp)[3] = c;
	char* (*dp)[3] = d;
	char(**ep)[2][3] = &e; //e가 single pointer여서 주소를 줌
	char(**fp)[3] = f; //char(*f)[3] 을 위한 포인터
	return 0;
}

////////그림그려서 이해하기
