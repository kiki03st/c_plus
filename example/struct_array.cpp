#include <iostream>

using namespace std;

// 배열이 요소로 들어간 구조체 array 선언
typedef struct{
	int x[10];
}array;

array func(){
	array arr = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} };
	return arr;
}

int main(){
	// array형 변수 arr, arr2 선언
	array arr;
	array arr2;
	// arr 속 x의 값을 1부터 10으로 채움
	for(int i = 0; i < 10; i++){
		arr.x[i] = i + 1;
	}
	// arr2를 arr와 동일 요소로 복사
	arr2 = arr;
	// arr의 x 요소 출력(1 ~ 10)
	cout << "arr : ";
	for(int i = 0; i < 10; i++){
		cout << arr.x[i] << " ";
	}
	cout << endl;
	// arr2의 x 요소 출력(arr를 복사했으므로 동일하게 1 ~ 10 출력)
	cout << "arr2 : ";
	for(int i = 0; i < 10; i++){
		cout << arr2.x[i] << " ";
	}
	cout << endl;
	array f = func();
	cout << "func : ";
	for(int i = 0; i < 10; i++){
		cout << f.x[i] << " ";
	}
	cout << endl;
	return 0;
}
