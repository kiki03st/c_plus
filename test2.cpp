#include <iostream>

using namespace std;

int main(){
	int *ptr = new int;
	int *tmp;
	*ptr = 10;
	tmp = ptr;
	cout << *ptr << endl;
	ptr = new int;
	*ptr = 1234;
	cout << *ptr << endl;
	cout << ptr << endl;
	cout << tmp << endl;
	cout << *tmp << endl;
	delete ptr;
	return 0;
}
