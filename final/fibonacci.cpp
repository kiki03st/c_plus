#include <iostream>

using namespace std;

int mem[100] = {0, 1};

int fibo(int n){
	if(n == 0) return 0;
	else if(mem[n] == 0){
		mem[n] = fibo(n - 1) + fibo(n - 2);
	}
	return mem[n];
}

int main(){
	cout << "fibonacci : ";
	int n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
