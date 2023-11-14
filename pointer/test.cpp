#include <iostream>

using namespace std;

int* func(){
	int num[] = {10, 20, 30, 40};
	return num;
}

void gunc(){
	int mum[] = {123, 456, 789, 400};
}

int main(){
	int *ptr;
	ptr = func();
	cout << *ptr << endl;
	gunc();
	cout << *ptr << endl;
	return 0;
}
