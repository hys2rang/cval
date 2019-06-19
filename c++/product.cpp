#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
class Product {
private:
	char* name;
	int price;
public:
	char* getProductName()const {
		return name;
	}
	int getProductPrice()const {
		return price;
	}
	void setProductInfo(const char* name, int price) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->price = price;
	}
	void showProductinfo()const {
		cout << "--" << this << "--" << endl;
		cout << "상품명 : " << name << endl;
		cout << "상품가 : " << price << endl << endl;
	}
	void deleteProductName() {
		delete[] name;
	}
};
int main()
{
	Product prd1;
	prd1.setProductInfo("공기청정기", 2000);
	prd1.showProductinfo();

	Product prd3;
	prd3.setProductInfo("공기청정기", 2000);
	prd3.showProductinfo();

	Product* prd2 = new Product;
	prd2->setProductInfo("가습기", 3000);
	prd2->showProductinfo();

	delete prd2;
	return 0;
}
//product 객체가 필요하다
//상품명과 상품가에 대한  속성이 필요하다.(정보은닉의 형태로 구현)
//상품명과 상품가에 대한 출력 서비스와 (출력이니 멤버변수 값이 바뀌지 않아야 한다)
//삼품명과 상품가에 대한 입력 서비스가 필요하다.
//해당 클래스를 선언하고 
//main함수에서 
//1. 일반객체 prd1 생성후 해당 상품을 입력(상품명, 상품가)하고 
//                                출력(상품명, 상품가)해보시오.
//2. 동적할당으로 prd2 생성후 입출력 후 마지막에 객체를 할당해제하시오
