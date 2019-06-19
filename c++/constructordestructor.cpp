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

	//소멸자 추가하고 동적할당한 p를 delete하시오
	~A() {
		delete p;
		cout << "destructor" << endl;
	}
};
class pos {
private :
	int xpos;
	int ypos;
public:
	pos(int xpos, int ypos) {
		this->xpos = xpos;
		this->ypos = ypos;
	}
	void showposition() {
		cout << xpos << " " << ypos << endl;
	}
	int get_xpos() {
		return xpos;
	}
	int get_ypos() {
		return ypos;
	}
};
//두 위치의 차를 함수내부에서 힙공간을 만들어 구하고 
//5와 -2를 가진 힙영역을 리턴한다.
pos& distance_pos(pos& ra, pos& rb) {

	pos* p= new pos(abs(ra.get_xpos()-rb.get_xpos()),abs(ra.get_ypos()-rb.get_ypos()));
	return *p;
}

class History {
	pos a;
	pos b;
public:
	History() :a(0, 0), b(0, 0) {}
	History(pos& a, pos& b) :a(a), b(b) {}
	void add_pos(pos& a, pos& b) {
		this->a = a;
		this->b = b;
	}
	void show_history() {
		cout << a.get_xpos() << ' ' << a.get_ypos() << endl;
		cout << b.get_xpos() << ' ' << b.get_ypos() << endl;
	}
	//소멸자를 명시하면 객체 안의 heap들을 삭제하게 되는 것
};

int main()
{
	A ob1(1, "서울시 서초구");
	A ob2 = ob1;

	ob1.showAinfo();
	ob2.showAinfo();

	pos a(0, 3);
	pos b(5, 1);

	pos& rf = distance_pos(a, b);
	//rf를 사용해서 showposition //5 -2출력
	rf.showposition();
	
	

	cout << "-----------------" << endl;
	//인스턴스 a,b를 함께 저장할 수 있는 history 클래스를 선언하고
	//history 클래스 형태의 배열 10개 중 0번째에 a, b를 저장하시오
	History* history = new History[10];
	history[0].add_pos(a, b);
	history[1].add_pos(b, a);
	history[0].show_history();
	history[1].show_history();
	
	//rf를 사용하여 만들어진 heap 영역을 delete한다.
	delete& rf;
	delete[] history;
	return 0;
}
