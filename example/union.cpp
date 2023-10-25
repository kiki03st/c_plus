#include <iostream>

using namespace std;

// union 속 변수들은 저장 공간을 모두 공유함
// 하나의 변수값만을 바꿔도 다른 변수의 값이 초기화됨
union one4all{
	int in;
	long lo;
	double dou;
};


int main(){
	one4all uni;
	uni.in = 10;
	uni.lo = 20;
	uni.dou = 30;
	cout << "한꺼번에 저장 : " << endl;
	cout << "uni.in : " << uni.in << endl;
	cout << "uni.lo : " << uni.lo << endl;
	cout << "uni.dou : " << uni.dou << endl;

	cout << endl;

	cout << "한번에 하나씩 저장 : " << endl;
	uni.in = 10;
	cout << "uni.in : " << uni.in << endl;
	uni.lo = 20;
	cout << "uni.lo : " << uni.lo << endl;
	uni.dou = 30;
	cout << "uni.dou : " << uni.dou << endl;
	
	return 0;
}
