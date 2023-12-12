#include <iostream>
#include <climits>

using namespace std;

int main(){
	unsigned int a = INT_MAX;	//unsigned가 붙으면 양수만 존재 가능한 자료형으로 변환, 기존에 음수로 나타내던 범위는 양수 범위로 치환

	cout << "1. int max : " << a << endl;
	a += 1;
	cout << "2. int max : " << a << endl;
	a = UINT_MAX;
	cout << "3. int max : " << a << endl;
	signed b = INT_MAX;	//signed는 일반 자료형과 동일, 양수와 음수로 모두 표현 가능한 자료형으로 변환
	cout << "4. int max : " << b << endl;
	b += 1;
	cout << "5. int max : " << b << endl;
	return 0;
}
