#include <iostream>

using namespace std;

#define PI 3.141592

int main(){
	cout << PI << endl;
	// define을 통해 생성한 PI 또한 const와 같은 상수의 특성을 띠고 있음
	// 그러므로 이후에 값을 변경하는 등의 행위가 불가능함
	// int PI = 3;
	// cout << PI << endl;
	return 0;
}
