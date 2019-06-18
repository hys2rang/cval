#include <iostream>

using namespace std;

void swap1(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap2(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 10;
	int& ra = a;
	int* pa = &a;
	int*(&rpa) = pa;
	int& ra2 = ra;

	cout << a << endl;
	cout << ra << endl;
	cout << *pa << endl;

	int c = 10, b = 5;

	swap1(&c, &b); //포인터로 두 변수 바꾸기
	cout << c << " " << b << endl;
	swap2(c, b); //c++에서는 참조변수를 이용하여 바꾼다.
	cout << c << " " << b << endl;
	return 0;
}
