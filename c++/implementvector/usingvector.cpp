#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;

	v1.push_back(100);
	v1.push_back(200);
	v1.push_back(300);

	cout << v1[0] << " ";
	cout << v1[1] << " ";
	cout << v1[2] << endl;

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	for (int i = 0; i < v2.size(); ++i) {
		cout << v2[i] << " ";
	}
	cout << endl;
}
