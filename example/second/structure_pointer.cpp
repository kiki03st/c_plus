#include <iostream>

using namespace std;

struct Big{
	int a;
	int b;
	int *c;
};

int main(){
	// Big 구조 변수 선언
	Big mystruct;
	int num = 939;
	// 구조체 속 a와 b는 일반 정수형 값이 들어옴
	mystruct.a = 100;
	mystruct.b = 200;
	// 구조체 변수의 값 call by reference로 불러오기
	mystruct.c = &num;
	Big *ptr = &mystruct;
	cout << (*ptr).a << endl;
	cout << ptr -> b << endl;
	cout << ptr -> c << endl;
	// = cout <<*(ptr -> c) << endl;
	cout << *ptr -> c << endl;
	return 0;
}
