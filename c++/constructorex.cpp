#include <iostream>

using namespace std;

class Car {
private:
	int engine;
	int pipe;
	int piston;
public:
	Car(int engine = 10, int pipe = 10, int piston=10) {
		this->engine = engine;
		this->pipe = pipe;
		this->piston = piston;
	}
	void print() {
		cout << "engine : " << engine << endl;
		cout << "pipe : " << pipe << endl;
		cout << "piston : " << piston << endl;
	}
};

int main()
{
	Car ob0;
	ob0.print();
	cout << endl;
	Car ob1(200);
	ob1.print();
	cout << endl;
	Car ob2(200, 30);
	ob2.print();
	cout << endl;
	Car ob3(200, 30, 40);
	ob3.print();
	return 0;
}
