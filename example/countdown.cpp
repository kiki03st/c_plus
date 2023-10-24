#include <iostream>
#include <ctime>

using namespace std;

int main(){
	int a = 10;
	clock_t start;
	while(a){
		cout << "Countdown : " << a << endl;
		a--;
		start = clock();
		while(clock() - start < CLOCKS_PER_SEC);
	}
	cout << "Launch!" <<endl;
	return 0;
}
