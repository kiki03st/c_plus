#include <iostream>

using namespace std;

int* func(){
	int num[] = {10, 20, 30, 40};
	// num 변수는 func 함수에만 존재하는 지역 변수
	// 그러므로 num을 반환할 경우, 지역 변수를 반환하는 것이므로 쓰레기값을 반환하는 것과 동일
	// 실제 실행 시 Segmentation 오류 발생
	return num;
}

int main(){
	// 정수형 포인터 ptr 선언
	int *ptr;
	// ptr의 주소를 func의 반환값으로 설정
	ptr = func();
	cout << *ptr << endl;
	return 0;
}
