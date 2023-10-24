#include <iostream>

using namespace std;

int main(){
	int num[] = {1, 2, 3, 4};

	for(int i = 0; i < 4; i++){
		cout << &num[i] << endl;
		// 리스트 요소들의 자료형인 int의 크기 4 byte에 따라 4 byte 간격으로 값들이 저장된 것을 볼 수 있음
	}

	for(int i = 0; i < 20; i++) cout << "-";
	cout << endl;
	cout << num << endl;
	// 배열 num의 주소 반환
	cout << &num[0] << endl;
	// 앞에서 num의 주소와 같은 주소가 반환됨
	// 배열의 주소는 배열의 첫 번쨰 요소를 기준으로 반환됨을 알 수 있음
	return 0;
}
