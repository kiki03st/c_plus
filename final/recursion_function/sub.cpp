#include <iostream>

using namespace std;

int sub(int n, int k){
	return n - k;
}

int sub_new(int n, int k){
	if(k == 0) return n;
	return sub_new(n, k - 1) - 1;
}

int main(){
	cout << "sub : " << sub(10, 5) << endl;
	cout << "sub_new : " << sub_new(10, 5) << endl;
	return 0;
}
