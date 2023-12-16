#include <iostream>

using namespace std;

int main(){
	// ptr에 메모리 할당
	int *ptr = new int;
	// ptr의 주소값 반환
	cout << ptr << endl;
	// ptr 속 값을 10으로 지정
	*ptr = 10;
	// ptr 속 값 출력
	cout << *ptr << endl;
	
	// ptr의 메모리를 해제함
	delete ptr;
	// delete를 수행한 이후에도 ptr의 값은 존재함(메모리 삭제 x)
	cout << *ptr << endl;
	// ptr 속 값을 바꿔도 그대로 적용됨
	*ptr = 9999;
	cout << *ptr << endl;
	return 0;
}
