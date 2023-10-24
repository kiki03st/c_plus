#include <iostream>

using namespace std;

// 2차원 배열을 선언할 떄에는 row의 크기는 주어지지 않아도 되지만, col의 크기는 명명해주어야한다. 
// 함수에 매개 변수로 2차원 배열을 쓸 떄에도 동일
void print(int arr[][3], int size){
	for(int i = 0; i < size / (sizeof(int) * 3); i++){
		for(int j = 0; j < 3; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
	int num[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	print(num, sizeof(num));
	return 0;
}
