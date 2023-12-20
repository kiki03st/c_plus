#include <iostream>

using namespace std;

int main(){
	int a = 100;
	// 하드링크와 같음
	// 기존 *를 사용하던 포인터는 소프트 링크
	// *를 사용한 포인터는 가리키는 변수의 값, 가리키는 변수의 주소, 포인터 변수 자체의 주소를 나타낼 수 있음
	// &를 이용한 reference는 가리키는 변수의 주소가 곧 레퍼런스 변수 자체 주소와 동일
	int &b = a;
	int c = 100;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}
