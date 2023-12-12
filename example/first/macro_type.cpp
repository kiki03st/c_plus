#include <iostream>

using namespace std;

#define MAKE_ADD_F(T) T add(T a, T b) { return a + b; }
// define 과정에서는 타입을 인식하지 못하므로 타입을 의미하는 T를 활용
MAKE_ADD_F(int)
MAKE_ADD_F(double)

int main(){
	cout << add(10, 20) << endl;
	cout << add(10.5, 20.5) << endl;
	return 0;
}
