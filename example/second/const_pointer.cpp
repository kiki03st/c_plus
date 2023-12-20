#include <iostream>

using namespace std;

int main(){
	int a = 100;
	int b = 200;
	// datatype* const name의 형태는 가리키는 변수의 값을 바꿀 수 있으나 가리키는 변수의 주소는 바꿀 수 없음
	int* const ptr1 = &a;
	// const datatype* name의 형태는 가리키는 변수의 주소는 바꿀 수 있으나 가리키는 변수의 값을 직접적으로 바꿀 수는 없음
	const int* ptr2 = &a;
	a = 300;
	ptr2 = &b;
	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	int c = 300;
	// 앞뒤에 const를 둘다 붙이면 가리키는 변수의 주소 및 자체 값 둘다 변경 불가능
	const int* const ptr3 = &c;
	cout << *ptr3 << endl;
	return 0;
}
