#include <iostream>

using namespace std;

int* tmp;

int *func(){
	// num에게 메모리 할당이 실행되지 않은 상태
	int num[] = {10, 20, 30, 40};
	// tmp에 num 변수의 주소를 저장해두면 함수를 탈출한 이후에도 num 변수 속 값 확인 가능
	tmp = num;
	// num은 func 함수 내부에서 선언된 지역변수
	// 그러므로 함수의 호출이 끝나면 num 변수에 할당된 메모리가 해제됨
	// num은 함수 내에서 선언된 지역변수이고, 메모리가 할당되지 않았으므로 반환 시 num 삭제
	return num;
}

void gunc(){
	// 함수는 동일한 주소를 공유함
	// 그러므로 mum의 값이 저장된 주소는 num의 값이 저장된 주소와 동일함
	// 그러므로 num 속에 저장된 값이 mum 속 요소들로 교체됨
	// tmp 속 값을 확인하면 알 수 있음
	int mum[] = {123, 456, 789, 400};
}
int main(){
	int *ptr;
	ptr = func();
	cout << *tmp << endl;
	//cout << *ptr << endl;
	gunc();
	cout << *tmp << endl;
	//cout << *ptr << endl;
	return 0;
}
