#include <iostream>

using namespace std;

int main(){
	double pi = 3.14;
	// pi의 주소는 double* 형태, ptr의 자료형인 int*와 맞지 않음, 강제 형변환
	int *ptr = (int*)&pi;
	cout << *ptr << endl;
	// 서로 형이 다른 변수에 대해 타입 캐스팅 실행
	ptr = reinterpret_cast<int*>(&pi);
	cout << *ptr << endl;
	return 0;
}
