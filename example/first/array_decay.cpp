#include <iostream>

using namespace std;
// 함수에 인자로 전달된 배열은 배열의 크기가 무용지물이므로 생략 가능
// void print(int arr[])
void print(int arr[4]){
	// 인자로 받은 arr 변수는 내용물은 파악 불가능하고 int형이라는 것만 알 수 있음
	// int형의 크기는 4 byte (32bit 기준)이므로 배열의 0번째 인덱스만 반환
	for(int i = 0; i < sizeof(arr) / 4; i++){
		cout << arr[i] << endl;
	}
}

int main(){
	int num[] = {1, 2, 3, 4};
	cout << "Loop 1. Main" << endl;
	for(int i = 0; i < 20; i++) cout << "-";
	cout << endl;
	// 배열을 선언한 구간에서는 배열의 총 크기를 알기 때문에 sizeof(num)이 배열의 길이인 4와 자료형인 int의 크기 4 byte를 곱한 4 * 4 = 16을 반환하게 된다. 
	for(int i = 0; i < sizeof(num) / 4; i++){
		cout << num[i] << endl;
	}
	for(int i = 0; i < 20; i++) cout << "-";
	cout << endl;
	cout << "Loop 2. print" << endl;
	for(int i = 0; i < 20; i++) cout << "-";
	cout << endl;
	print(num);
	return 0;
}
