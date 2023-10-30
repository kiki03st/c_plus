#include <iostream>

using namespace std;

int add(int n, int k){
	return n + k;
}

int add_new(int n, int k){
	if(n == 0) return k;
	return add(n - 1, k) + 1;
}

int main(){
	cout << "add : " << add(10, 5) << endl;
	cout << "add_new : " << add_new(10, 5) << endl;
	return 0;
}
