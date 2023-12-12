#include <iostream>
#include <climits>

using namespace std;

int main(){
	float tree = 3;
	int guess = 3.9832;
	short debt = 0x00010001;
	// 처음에 초기값을 선언할 때에는 각 자료형의 범위에 맞는 값으로만 지정해야 함
	// 만약 그렇지 않다면 오버플로우 warning 발생
	// int test = INT_MAX; -> test += 1의 경우, test + 1의 값이 자료형의 범위를 벗어나지만 초기값을 INT_MAX + 1로 설정하는 것과 달리 warning이 발생하지 않음

	cout << "tree : " << tree << endl;
	cout << "guess : " << guess << endl;
	cout << "debt : " << debt << endl;
	return 0;
}
