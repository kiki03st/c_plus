#include <iostream>

using namespace std;

struct Big{
	double a;
	int b[1000];
	long c;
};

// call by value : 모든 데이터를 call 스택에 복사, 많은 시간과 메모리 소요
void func(Big value){
	cout << sizeof(value) << endl;
	cout << value.a << endl;
}

// call by reference : 포인터를 이용하여 인자를 직접적으로 전달
void func(Big *value){
	cout << sizeof(value) << endl;
	cout << value -> a << endl;
}

int main(){
	Big mystruct;
	mystruct.a = 100;
	cout << sizeof(mystruct) << endl;
	// BIg 구조체를 매개인자로 받는 함수 fuc 호출
	func(mystruct);
	// Big 구조체의 포인터를 매개인자로 받는 함수 func 호출
	func(&mystruct);
	
	return 0;
}
