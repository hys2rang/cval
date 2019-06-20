#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Engine
{
private:
	int horsepower;
public:
	Engine(int power)
	{
		if (120 > power || power > 290)
		{
			cout << "불가능한 파워입니다" << endl;
			horsepower = 0;
		}
		else
			horsepower = power;

	}
	Engine(Engine& copy) :horsepower(copy.horsepower)
	{
	}
	int getHorsepower(void) const
	{
		return horsepower;
	}
	void showEngineInfo() const
	{
		int power = getHorsepower();
		if (power != 0)
			cout << power << endl;
	}

	~Engine()
	{
		cout << "base" << endl;
	}

};

class intercoolerEngine : public Engine
{
private:
	char* cooler;
public:
	intercoolerEngine(int hp, const char* col) :Engine(hp)
	{
		cooler = new char[strlen(col) + 1];
		strcpy(cooler, col);
	}

	intercoolerEngine(const intercoolerEngine& copy) :Engine(copy.getHorsepower())
	{
		cooler = new char[strlen(copy.cooler) + 1];
		strcpy(cooler, copy.cooler);

	}
	friend void viewcooler(intercoolerEngine& view);
	void showerICEngine()
	{
		showEngineInfo();
		viewcooler(*this);
	}


	~intercoolerEngine()
	{
		delete[]cooler;

		cout << "deconstructor" << endl;
	}

};
void viewcooler(intercoolerEngine& view)
{
	cout << view.cooler << endl;
}

class turboEngine :public intercoolerEngine {
private:
	char charger;
public:
	turboEngine(int eg, char* col, char type) :intercoolerEngine(eg, col), charger(type){}


	void showTEngineInfo()
	{
		showerICEngine();
		cout << charger << endl;
	}

	~turboEngine() {
		cout << "destruct turbo" << endl;
	}


};

int main()
{
	Engine eng1(150);
	eng1.showEngineInfo();
	intercoolerEngine eng2(270, "물");
	eng2.showerICEngine();

	intercoolerEngine eng3 = eng2;
	eng3.showerICEngine();

	return 0;
}
