#include <iostream>

using namespace std;

int div_old(int n, int k){
	return n / k;
}

int div_new(int n, int k){
	if(n < k) return 0;
	return div_new(n - k, k) + 1;
}

int main(){
	cout << "div : " << div_old(10, 5) << endl;
	cout << "div_new : " << div_new(10, 5) << endl;
	return 0;
}
