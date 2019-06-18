#include <iostream>

using namespace std; //std안에 있는 수많은 기능들을 사용하겠당

//두 변수의 덧셈결과를 리턴하는 함수
int add(int a, int b)
{
	return a + b;//1번째 방법
}
/*//add 함수의 주소를 리턴하는 함수를 만들어라 =>add 함수를 위한 포인터가 타입으로 필요하다.
int(*)(int,int) func() //함수 포인터는 직접적으로 만들어서 사용할 수 없으므로 typedef를 하고 이를 이용
{
	return add; //함수의 return 값이 함수의 주소여야 함
}
*/
typedef int i_t;
typedef i_t fi_t(int, int); //int를 리턴하는 함수타입
typedef fi_t* pfi_t; //pfi == func_t
/*
	||
	||
	||
	||
   \  /
    \/
*/
typedef int(*func_t)(int, int); 
///////////////////////////////////////////////////////////////////////////////////////////////////////////
pfi_t func() // => int(*func())(int,int)
{
	return add;
}
func_t funcc()
{
	return add; 
}
fi_t add; //typedef를 이용한 prototype 선언 (함수의 prototype을 숨길 수 있다.)

typedef char* c_t;	//char *
typedef c_t c_ta[10]; //char*	[10]
typedef c_ta* pc_ta;	//char*(*	)[10]
typedef pc_ta fpc_ta();	//char *(*	())[10]
typedef fpc_ta* pfpac;	//char *(*(*	)())[10]

int main()
{
	cout << funcc()(10, 5) << endl;
	return 0;
}
