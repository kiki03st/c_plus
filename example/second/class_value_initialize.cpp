#include <iostream>

using namespace std;

class Car{
	public:
		int a;
		int b;
};

int main(){
	// 클래스의 멤버 변수가 public일 경우, 구조체와 동일하게 순서대로 멤버 변수의 초기값 설정 가능
	Car myCar = {10, 20};
	cout << myCar.a << endl;
	cout << myCar.b << endl;
	return 0;
}
