#include <iostream>

using namespace std;

// func 함수를 호출할 시, 재귀를 멈추는 시점이 존재하지 않으므로 crash 발생
void func(){
	static int cnt = 0;
	cout << "count : " << ++cnt << endl;
	func();
}

int main(){
	func();
	return 0;
}
