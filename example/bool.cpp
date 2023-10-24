#include <iostream>

using namespace std;

int main(){
	bool boo = true;	// true일 경우, 1을 의미
	bool ool = false;	// false일 경우, 0을 의미
	bool a = -1;	// bool 자료형에서는 0을 제외한 모든 수가 1로 표현됨
	bool b = 1;
	bool c = 0;

	cout << "sizeof : " << sizeof(bool) << endl;
	cout << "boo : " << boo << endl;	// true는 1 출력
	cout << "ool : " << ool << endl;	// false는 0 출력
	cout << a << endl;	// 출력: 0이 아니므로 1 출력
	cout << b << endl;	// 출력: 0이 아니므로 1 출력
	cout << c << endl;	// 출력: 0이므로 0 출력
	return 0;
}
