#include <iostream>
#include <climits>

using namespace std;

int main(){
	const int a = INT_MAX;
	cout << a << endl;
	// const는 변수의 값이 더이상 바뀌지 않을 것이라는 것을 명시함
	// 그러므로 변수의 값을 이후에 바꾸지 않는 상황에서만 사용
	//a = INT_MAX - 1;
	//cout << a << endl;
	return 0;
}
