/*
Engine클래스는 마력(horsepower)을 표시한다.
마력은 120에서 290마력을 값을 가질수 있다.
가지고 있는 마력을 출력하는 const함수가 있다.
해당 const함수에서는 마력에 직접적으로 접근할수 없는 상황이다.

intercoolerEngine클래스는 engine를 상속한다.
내부적으로 cooler를 가지고 있다.
cooler의종류는 *형태로 //"오일" 또는 "물" 형태가 입력된다.
해당 마력과 쿨러를 출력하는 함수가 있다.
intercoolerEngine클래스의 객체는 자신과 같은 객체를 그대로
복사하는 능력이 있다.

turboEngine클래스는 intercoolerEngine클래스를 상속한다.
내부적으로 turborchager를 가지고 있으며
차저의 종류는 A, B, C type의 문자가 입력된다.

1.engine클래스의 객체, 150마력에 해당하는eng1객체를 만들고 출력
2. intercoolerEngine클래스 객체, 270마력에  "물"을 사용하는 eng2를
만들고 출력
3. intercoolerEngine eng3를 eng2로 부터 복사 후 eng3출력
4. turboEngine클래스의 객체 eng4 는 290마력에 "오일" 그리고 차저는 'B'
   타입을 사용하는 객체이다.
   출력방법은 마력, 마력+ 오일, 마력+오일+차저 3가지형태로 출력된다.

해당 객체에 소멸자에 필요하다면 delete 를 구현하시오
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Engine {
	int horsepower;
public:
	Engine(int horsepower) {
		if (horsepower >= 120 && horsepower <= 290) {
			this->horsepower = horsepower;
		}
		else {
			this->horsepower = 0;
		}
	}
	int getHorsepower()const {
		return this->horsepower;
	}
	void setHorsepower(int horsepower) {
		this->horsepower = horsepower;
	}
	virtual void print() {
		cout << "Horsepower : " << horsepower << endl;
	}
	~Engine() {
		cout << "engine is destructed" << endl;
	}
};
class intercoolerEngine :public Engine {
	char* cooler;
public:
	intercoolerEngine(int horsepower, const char* cooler):Engine(horsepower) {
		setcoolerEngine(cooler);
	}
	void print() {
		cout << "Horsepower : " << getHorsepower() << endl;
		cout << "cooler : " << cooler << endl;
	}
	void setcoolerEngine(const char* cooler) {
		this->cooler = new char[strlen(cooler) + 1];
		strcpy(this->cooler, cooler);
	}
	char* getcoolerEngine()const {
		return cooler;
	}
};
class turboEngine :public intercoolerEngine {
	char turbocharger;
public:
	turboEngine(int horsepower, const char* cooler, char turbocharger):intercoolerEngine(horsepower,cooler) {
		this->turbocharger = turbocharger;
	}
	void print() {
		cout << "Horsepower : " << getHorsepower() << endl;
		cout << "cooler : " << getcoolerEngine() << endl;
		cout << "charger : " << turbocharger << endl;
	}
};
int main()
{
	Engine* eng1 = new Engine(150);
	eng1->print();
	cout <<"------------------------"<< endl;
	Engine* eng2 = new intercoolerEngine(270, "물");
	eng2->print();
	cout <<"------------------------"<< endl;

	Engine* eng3 = eng2;
	eng3->print();
	cout <<"------------------------"<< endl;
	Engine* eng4 = new turboEngine(270, "오일", 'B');
	eng4->print();
	return 0;
}
