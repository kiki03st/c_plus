#include <iostream>

using namespace std;

int res(int n, int k){
	return n % k;
}

int res_new(int n, int k){
	if(n < k) return n;
	return res(n - k, k);
}

int main(){
	cout << "res : " << res(10, 6) << endl;
	cout << "res_new : " << res_new(10, 6) << endl;
	return 0;
}
