#include <iostream>

using namespace std;
class Car {
private:
	int engine;
	int pipe;
	int piston;
public:
	Car() :engine(0), pipe(0), piston(0) {}
	/*
	Car(int engine, int pipe, int piston) {
		this->engine = engine;
		this ->pipe = pipe;
		this->piston = piston;
	}*/

	//init
	Car(int eg, int pp, int ps) :engine(eg), pipe(pp), piston(ps) {}

	//private 멤버의 접근 함수 access function
	int get_engine() const{ //얘는 private한 engine을 접근해야 하는데, 내가가진 클래스 객체의 멤버 변수를 이 함수 안에서 변형시키지 않겠다는 의미
		return engine;
	}
	int get_pipe() const {
		return pipe;
	}
	int get_piston() const {
		return piston;
	}
	void set_engine(int eg) {
		this->engine = eg; //this는 호출한 객체
	}
	void print() { //->inline function 
		cout << "engine : " << engine << endl;
		cout << "pipe : " << pipe << endl;
		cout << "piston : " << piston << endl;
	}
};

//Car::Car(int eg, int pp, int ps) :engine(eg), pipe(pp), piston(ps) {} //외부에서도 init이 가능하다.

int add(const int &a, const int &b) {
	return a + b;
}
/*
int main()
{
	printf("%d\n", add(10, 20));;
	Car bus; //default 생성자 호출
	Car bus2(400, 100, 8); //stack 영역에 생기는것
	Car* bus3 = new Car(800, 200, 16); //heap영역에 car가 생기고 stack 영역에 있는 bus3가 heap영역에 생긴 car를 가르키고 있는것
	//new로 동적 생성을 할 때는 pointer가 항상 필요함
	bus2.print();
	//cout << bus.get_engine() << endl;
	
	delete bus3;
}*/
