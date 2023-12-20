#include <iostream>

using namespace std;

int main(){
	char a[] = "Hello World";
	const char* ptr = a;
	char *arr = const_cast<char*>(ptr);
	arr[0] = 'A';
	cout << arr << endl;
	return 0;
}
