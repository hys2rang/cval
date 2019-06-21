#include <iostream>

using namespace std;
class pos {
	int x;
	int y;
public:
	pos(int x=10, int y=20):x(x),y(y){}
	pos operator+(const pos& rf) {
		pos tmp;
		tmp.x = x + rf.x;
		tmp.y = y + rf.y;
		return tmp;
	}
	pos operator-(const pos& rf) {
		pos tmp;
		tmp.x = x - rf.x;
		tmp.y = y - rf.y;
		return tmp;
	}
	const pos& operator++() {//전위연산
		x++;
		y++;
		return *this;
	}
	const pos& operator++(int) {//후위연산
		pos tmp;
		tmp.x = x;
		tmp.y = y;
		x++;
		y++;
		return tmp;
	}
	friend ostream& operator<<(ostream& os, pos& ps);
	friend pos& operator-(const pos& ps1, const pos& ps);
	friend pos& operator+(int a, const pos& ps);
	void showinfo() {
		cout << x << " " << y << endl;
	}
};
//객체.operator<<(객체2)의 형태로의 호출은 불가
//전역변수로 만든이유는 객체1(cout)이 객체2를 모른다.
ostream& operator<<(ostream& os, pos& ps) {
	os << ps.x << " " << ps.y << endl;
	return os;
}
pos& operator-(const pos& ps1, const pos& ps) {
	pos tmp;
	tmp.x = ps1.x - ps.x;
	tmp.y = ps1.y - ps.y;
	return tmp;
}
//두객체의 차를 해주는 operator-함수를 만드시오
//멤버 함수버전, friend 전역함수 버전
pos& operator+(int a, const pos& ps) {
	pos tmp;
	tmp.x = ps.x + a;
	tmp.y = ps.y + a;
	return tmp;
}
class pos_array {
	pos parr[10];
	int cnt;
public:
	pos_array(int n) :cnt(n) {}
	pos& operator[](int n) {
		return parr[n];
	}
	pos operator[](int n)const {
		return parr[n];
	}
	void print() {
		for (int i = 0; i < cnt; i++) {
			parr[i].showinfo();
		}
	}
};
int main()
{
	pos ob1(1, 2);
	pos ob2;
	pos ob3 = ob1 - ob2;
	pos ob4 = operator-(ob1, ob2);
	ob3.showinfo();	
	cout <<ob4 << endl;
	//5+ob4를 위한 operator+함수를 오버로딩하시오
	pos ob5 = 5 + ob4;
	++ob5;
	cout << ob5 << endl;
	pos op6 = ob5++;
	cout << op6 << endl;
	cout << ob5 << endl;

	pos_array pa(2); //배열 클래스형 객체 => 배열에 대한 처리를 할때는 이방법을 사용하는게 좋다.

	pa[0] = pos(1, 1);
	pa[1] = pos(2, 2);
	cout << pa[0] << endl;
	cout << pa[1] << endl;

	pa.print();

	return 0;
}
