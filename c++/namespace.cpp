#include <iostream>

using namespace std;

namespace AAA {
	int aaa = 10;
	namespace BBB {
		int bbb = 20;
	}
}
int ccc = 30;
static int fff = 50;
int main()
{
	int ddd = 40;

	cout << AAA::aaa << endl;
	cout << AAA::BBB::bbb << endl;
	cout << ::ccc << endl;
	cout << ddd << endl;
	cout << ::fff << endl;
	namespace AB = AAA::BBB;
	cout << AB::bbb << endl;
	return 0;
}
