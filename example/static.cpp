#include <iostream>
#include <string>

using namespace std;

string save(string in){
		static string a;
		// static을 사용할 경우, 프로그램이 끝날 때까지 값을 계속 저장한다. 
		// 그러므로 get = save("")에서 static string a; 구문 속 a의 값은 이전에 실행했던 "I want to store this string" 값을 그대로 유지하고 있다.
		// 보통 함수를 불러올 떄만 쓰는 함수 속 지역변수 등에서 사용
		// main 함수 속 변수는 프로그램이 돌아가는 동안 계속 유지되므로 main 내부에서 사용하는 것은 비추천
		// static 수식어가 붙은 변수의 초기값 선언은 처음만 적용됨
		// 그러므로 static string a = "Hello"라고 해도, a의 값이 변경된 이후 함수를 다시 불러오면 초기값으로 지정되지 않고 변경된 a의 값이 유지됨
		if(in != "") a = in;
		return a;
}

int main(){
	string get = save("I want to store this string");
	get = save("");
	cout << get << endl;
	return 0;
}
