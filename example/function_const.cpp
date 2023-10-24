#include <iostream>

using namespace std;

// const를 이용하여 매개 변수 arr[]를 인자로 받았으므로 arr 속 요소들의 변조 불가능
void print(const int arr[], int size){
	for(int i = 0; i < size / 4; i++){
		cout << arr[i] << endl;
		// arr[i]의 값을 arr[i] * 10으로 변조하려 하기 때문에 옳지 않은 방식이다. 
		arr[i] *= 10;
	}
}

int main(){
	int num[] = {1, 2, 3, 4};

	print(num, sizeof(num));
	for(int i = 0; i < sizeof(num) / 4; i++){
		cout << num[i] << endl;
	}
	return 0;
}
