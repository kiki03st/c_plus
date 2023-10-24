#include <iostream>

using namespace std;

void func(){
	static int cnt = 0;
	if(cnt == 10) return;
	cout << cnt++ << "-th func" << endl;
	func();
	cout << cnt-- << "-th return" << endl;
	return;
}

int main(){
	func();
	return 0;
}
