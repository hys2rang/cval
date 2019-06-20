#include <iostream>
#include <typeinfo>
using namespace std;

class AA {
	virtual void x(){}
};
class BB :public AA {
	void x(){}
};
class CC : public BB {
	void x(){} //가상함수가 있어야지만 type을 알 수가 있다.
};
int main()
{
	AA a, * pa;
	BB b, * pb;
	CC c, * pc;

	pa = &a;
	pb = &b;
	cout << typeid(pa).name() << typeid(*pa).name() << endl;
	cout << typeid(pb).name() << typeid(*pb).name() << endl;
	
	pa = &c;// 기초클래스 포인터에게 유도클래스 객체의 주소대입
	cout << typeid(pa).name() << typeid(*pa).name() << endl;
	cout << typeid(pa).raw_name() << typeid(*pa).raw_name() << endl;


	return 0;
}
