#include <iostream>

using namespace std;
//template를 활용하여 매개변수의 자료형을 인식하고 활용할 수 있게 함
template <typename T>
T add(T a, T b){
	return a + b;
}
//template의 typename 부분에 아무것도 넣지 않음으로써 특정 자료형에 한정하여 다른 함수를 실행하도록 할 수 있음
template<>
char add(char a, char b){
	return a + 0x20;
}
//template 속 typename은 여러 개 생성 가능
template <typename T, typename Y>
T add(T a, Y b){
	return a + b;
}

int main(){
	cout << add(10, 20) << endl;
	//함수의 이름 뒤에 <자료형>을 붙여줌으로써 typename을 명시적으로 지정 가능함
	cout << add<int>(10, 20) << endl;
	cout << add(10.5, 20.5) << endl;
	cout << add('F', 'F') << endl;
	cout << add((int)10, (short)20) << endl;
	return 0;
}
