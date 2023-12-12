#include <iostream>

using namespace std;

string save(string in){
	static string a;
	if(in != "") a = in;
	return a;
}
int main(){
	save("I want to store this string");
	// static string a = "hahaha";
	// 위 코드를 실행해도 함수 속 변수 static string a의 값은 변하지 않음
	// 함수 속 변수 a의 값을 바꾸기 위해서는 변수의 선언 과정에서 전역 변수로 선언하는 것이 필요
	// using namespace std; 구문 아래와 같은 함수의 바깥에서 변수를 선언할 경우, 함수에 관계없이 모든 곳에서 변수 사용 가능
	string get = save("");
	cout << get << endl;
	return 0;
}

