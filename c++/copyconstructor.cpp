#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class A {
private:
	int num;
	char* p;
public:
	//default constructor
	A(int num, const char* p):num(num) {
		this->p = new char[strlen(p) + 1];
		strcpy(this->p, p);
	}
	//copy constructor
	A(const A& a) :num(a.num) {
		p = new char[strlen(a.p) + 1];
		strcpy(p, a.p);
	}
	void showAinfo()
	{
		cout << "num : " << num << endl;
		cout << "p : " << p << endl;
	}
};
int main()
{
	A ob1(1, "서울시 서초구");
	A ob2 = ob1;

	ob1.showAinfo();
	ob2.showAinfo();
	return 0;
}
