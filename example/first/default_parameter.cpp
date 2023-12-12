#include <iostream>

using namespace std;

//함수에 매개변수의 값을 입력하지 않았을 떄, 사용할 값을 미리 정할 수 있음(default parameter)
void countdown(int a = 10){
	cout << "Countdown! " << endl;
	for(int i = a; i > 0; i--){
		cout << i << "...";
	}
	cout << "\n launch!" << endl;
}

int main(){
	countdown(3);
	cout << endl;
	countdown(5);
	cout << endl;
	countdown();
	return 0;
}
