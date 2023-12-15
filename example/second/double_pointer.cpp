#include <iostream>

using namespace std;

int main(){
	int i = 10;
	int j = 20;
	int k = 30;
	int *ptr = &i;
	int **qtr = &ptr;

	cout << ptr << endl;
	cout << *ptr << endl;

	cout << &ptr << endl;
	cout << qtr << endl;

	// *qtr == ptr
	// qtr = &ptr이므로 *qtr = ptr
	// *는 +, &는 -로 생각하면 편함
	// ex) &(*ptr)은 ptr과 동일함
	// 그러므로 **qtr = *ptr = i = 10, *qtr = ptr = &i, qtr = &ptr
	// &ptr은 ptr 변수 자체 주소를 의미

	// *ptr, ptr, &ptr을 나눠서 설명하자면
	// *ptr : 일반적인 자료형(ex. int, float)을 가진 값
	// ptr : *ptr의 값을 저장한 주소
	// &ptr : ptr 주소값이 저장된 주소, 포인터 변수 자체의 주소
	
	cout << &(*ptr) << endl;

	cout << *qtr << endl;
	cout << **qtr << endl;
	return 0;
}
