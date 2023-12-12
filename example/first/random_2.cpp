#include <iostream>
#include <random>

using namespace std;

// 서로 다른 수 6개를 뽑아서 리스트 a에 저장하는 코드
int main(){
	srand(time(NULL));
	int a[6];
	int cnt = 0;
	// for문 속 if문이 작동했는지 판별하기 위한 변수
	bool tf;
	while(cnt < sizeof(a) / sizeof(int)){
		a[cnt] = rand() % 45 + 1;
		// for문이 시작하기 전에 tf의 값을 false로 초기화
		tf = false;
		for(int i = 0; i < cnt; i++){
			// a[i]가 새로 뽑은 값과 같다면
			if(a[i] == a[cnt]){
				// tf의 값을 true로 바꾼 후, for문 탈출
				tf = true;
				break;
			}
		}
		// if문을 통과해야만 tf의 값이 true로 바뀌므로 a 속에 a[cnt]와 겹치는 값이 존재한다는 것을 알 수 있음
		if(tf) continue;
		cnt++;
	}
	for(int i = 0; i < cnt; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
