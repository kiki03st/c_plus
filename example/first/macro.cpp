#include <iostream>

using namespace std;

#define ADD(X, Y) X = X + Y
#define SUB(X, Y) X = X - Y
#define PRT(X) cout << "Result: " << X << endl;
// 매크로 함수를 선언할 때에는 #define (함수) (수행 코드) 형태로 선언

#define PRTNUM(X, Y) \
	for(int i = X; i <= Y; i++){\
		cout << i << " ";\
	}\
	cout << endl;
// 여러 줄로 구성된 매크로를 선언하고 싶을 때에는 줄바꿈이 이루어질 때마다 \(백슬래시)를 붙여줘야 함

int main(){
	int a = 10;
	int b = 5;

	ADD(a, b);
	PRT(a);

	SUB(a, b);
	PRT(a);
	PRTNUM(1, 10);
	return 0;
}
