#include <iostream>

using namespace std;

int main(){
	cout << "This is 'unsigned'! " << 1234u << endl;
	// 1234 뒤에 u를 붙임으로써 1234를 unsigned 형태로 출력함
	cout << "This is 'long'! " << 1234l << endl;
	// 1234 뒤에 l을 붙임으로써 1234를 long 형태로 출력
	cout << "This is 'long long'! " << 1234ll << endl;
	// 1234 뒤에 ll을 붙임으로써 1234를 long long 형태로 출력
	cout << "This is 'unsigned long long'! " << 1234ull << endl;
	// 1234 뒤에 ull을 붙임으로써 1234를 unsigned long long 형태로 출력
	return 0;
}
