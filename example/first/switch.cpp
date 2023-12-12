#include <iostream>

using namespace std;

int main(){
	// switch 구문 속 매개변수로는 정수형태가 될 수 있는 int, char 등만 사용 가능
	/*
	float fredit;
	switch(fredit){
		case 'a':
			cout << "Your grade is 90 >=." << endl;
			break;
		default:
			cout << "default" << endl;
			break;
	}
	*/
	// switch문 속 case의 조건으로는 변수가 아닌 상수만 들어갈 수 있음
	// 그렇기에 1, 'a'와 같은 값 또는 const로 선언된 정수형 변수만 사용가능
	/*
	int num = 3;
	const int orange = 1;
	const int apple = 2;
	const int melon = 3;
	const int grape = 4;
	switch(num){
		case orange:
			cout << "orange" << endl;
			break;
		case apple:
			cout << "apple" << endl;
			break;
		case melon:
			cout << "melon" << endl;
			break;
		case grape:
			cout << "grape" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
	}
	*/
	//case에서는 기본적인 산술 연산을 제외하고는 다른 연산이 불가능하다고 생각하면 됨 
	/*
	char word = 'c';
	switch(word){
		case 'a' || 'A':
			cout << "a" << endl;
			break;
		case 'b' || 'B':
			cout << "b" << endl;
			break;
		case 'c' || 'C':
			cout << "c" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
	}
	*/
	return 0;
}
