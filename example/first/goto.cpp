#include <iostream>

using namespace std;

int main(){
	cout << "Hello?" << endl;
	goto bye;
	cout << "How are you?" <<endl;
	bye:
		cout << "Bye!" << endl;
	return 0;
}
