#include <iostream>
#include <ctime>

using namespace std;

#define SUM(a, b) a + b;
// inline 함수는 일반적인 함수와는 달리 함수의 코드를 그대로 가져오는 것이기 떄문에 #define에 가까움
// 실행 속도는 define < inline < default
// 단, inline 함수는 다른 함수에 비해 저장 공간을 많이 차지한다는 단점 존재
inline int add(int a, int b){
	return a + b;
}

int sum(int a, int b){
	return a + b;
}

int main(){
	clock_t start;
	start = clock();
	int c = SUM(10, 20);
	cout << c << endl;
	cout << "SUM running time : " << ((double)(clock() - start) / CLOCKS_PER_SEC) << endl;
	start = clock();
	cout << add(10, 20) << endl;
	cout << "add running time : " << ((double)(clock() - start) / CLOCKS_PER_SEC) << endl;
	start = clock();
	cout << sum(10, 20) << endl;
	cout << "sum running time : " << ((double)(clock() - start) / CLOCKS_PER_SEC) << endl;
	return 0;
}
