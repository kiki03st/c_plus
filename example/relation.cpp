#include <iostream>

using namespace std;

int main(){
	int a = 10;
	if(a = 0){
		cout << "Can you see me?" << endl;
	}
	// if문에서 조건을 검사할 때에는 조건 속 연산자가 다 실행된 이후에 검사하므로 a에 0이 대입된 후, a의 값을 검사함
	cout << a << endl;
	int b = 0;
	if(b = 1){
		cout << "B" << endl;
	}
	return 0;
}
