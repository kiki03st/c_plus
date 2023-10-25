#include <iostream>

using namespace std;

#define NUM PI
#define a 10

int main(){
	// a -= 1;
	// define의 지칭을 상수 값으로 지정할 경우, 연산 불가능
	// 변수 이름을 지칭하도록 코드 작성 시 변수 취급되어 define 값 변경 가능
	double PI = 3.141592;
	PI -= 1;
	cout << NUM << endl;
	NUM -= 1;
	cout << NUM << endl;
	return 0;
}
