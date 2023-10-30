#include <iostream>

using namespace std;

int mul(int n, int k){
	return n * k;
}

int mul_new(int n, int k){
	if(k == 0) return n;
	return mul(n, k - 1) + n;
}

int main(){
	cout << "mul : " << mul(10, 5) << endl;
	cout << "mul_new : " << mul_new(10, 5) << endl;
	return 0;
}
