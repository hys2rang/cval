#include <iostream>

using namespace std;

int& func1(int& rev)
{
	rev = 10;
	return rev;
}
int func2(int& rev)
{
	rev = 20;
	return rev;
}
int func3(int& rev)
{
	rev = 30;
	return rev;
}
int& func4(int rev)
{
	rev = 40;
	return rev;	//rev는 지역 변수의 참조를 return
}

void swap3(int* (&a), int* (&b))
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap4(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main()
{
	int c = 10, d = 5;
	int* pc = &c;
	int* pd = &d;
	swap3(pc, pd);//함수꼴은 그대로 두고 swap3에서 a, b를 바꾸시오
	cout << c << " " << d << endl;

	swap4(pc, pd);
	cout << c << " " << d << endl;
	
	int b = 10;
	int* p = &b;
	int* (&rp) = p;
	int** pp = &p;
	int** (&rpp) = pp;

	int a = 20; //a==rlt
	int& rlt = func1(a); //참조자(레퍼런스)변수는 여러개로 처리가능
	cout << rlt << endl;

	a = 30;
	const int& rlt2 = func2(a); //=> 20이란 숫자에 메모리가 없다..............,참조로 받고싶으면 const를 붙여줘야함
	cout << rlt2 << endl;

	int rlt3 = func3(a); //상수는 일반 변수로 가능
	cout << rlt3 << endl;

	a = 20;
	int& rlt4 = func4(a); //reference는 받았지만 func4의 지역변수가 사라지기 때문에 쓰레기 값이 들어간다.
	cout << rlt4 << endl;
	return 0;
}
