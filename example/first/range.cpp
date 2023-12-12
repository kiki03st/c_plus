#include <iostream>

using namespace std;

int main(){
	int a = -1;
	if(-2 < a <= 0){
		cout << "pass" << endl;
	}
	// 출력 안됨
	// 조건상 -1은 -2 초과 0 이하가 맞음
	// C++에서는 두 조건을 쓸 떄, && 연산자를 통해 묶어야함
	// 위의 조건은 -2 < a가 true이므로 1을 반환
	// 1 <= 0은 false이므로 0을 반환하여 전체 조건을 false, 즉 0으로 인식
	return 0;
}
