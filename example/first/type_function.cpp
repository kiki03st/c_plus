#include <iostream>

using namespace std;

int add(int a, int b){
	return a + b;
}

double add(double a, double b){
	return a + b;
}

float add(float a, float b){
	return a + b;
}

float add(float a, float b, float c){
	return a + b + c;
}

int main(){
	cout << add(10, 20) << endl;
	// 부동소수점 형태로 인자를 작성했을 때는 기본 자료형이 double이므로 add(10.5, 20.5)가 불러오는 함수는 double add(double a, double b)임
	cout << add(10.5, 20.5) << endl;
	// 부동소수점 형태로 매개변수를 작성하고 뒤에 f를 붙여주면 자료형이 float라는 것을 명시해주는 것임
	cout << add(0.1f, 0.2f) << endl;
	// 함수의 자료형만을 다르게 하여 작성하는 것 뿐만 아니라 같은 자료형에 다른 매개변수 개수를 가진 함수도 작성 가능
	cout << add(0.1f, 0.2f, 0.3f) << endl;
	return 0;
}
