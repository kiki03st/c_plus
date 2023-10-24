#include <iostream>

using namespace std;

int main(){
	char str[] = "Hello!";
	int stack[16];

	cout << sizeof(str) << endl;
	cout << sizeof(stack) << endl;
	// 배열을 선언할 경우, 그 크기는 (자료형) * (배열의 길이)
	// 배열은 단순 복합형으로, 배열 자체가 자료형은 아님
	return 0;
}
