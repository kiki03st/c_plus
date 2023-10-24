#include <iostream>

using namespace std;

// PI를 NUM 변수와 하드링크 하는 것과 유사
// NUM 변수, PI 둘 중 하나의 값만을 바꿔도 두 값이 동시에 바뀜
#define PI NUM

int main(){
	int NUM = 10;
	cout << PI << endl;
	NUM -= 5;
	cout << NUM << endl;
	cout << PI << endl;
	PI -= 5;
	cout << NUM << endl;
	cout << PI << endl;
	return 0;
}
