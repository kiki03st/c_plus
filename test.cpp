#include <iostream>
#include <ctime>

using namespace std;

int main(){
	char a[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00};
	char *c = (char *)a;
	int *i = (int *)a;
	long *l = (long *)a;

	cout << hex;
	cout << c << endl;
	cout << *c << endl;
	cout << (int)*c << endl;
	cout << i << endl;
	cout << *i << endl;
	cout << l << endl;
	cout << *l << endl;
	return 0;
}
