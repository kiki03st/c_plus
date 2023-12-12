#include <iostream>

using namespace std;

struct out{
	int a;
	short b;
	short c;
};

struct in{
	struct out i;
	int j;
	int k;
};

int main(){
	struct out pre_value;
	struct in value;
	cout << sizeof(pre_value) << endl;
	cout << sizeof(value) << endl;
	return 0;
}
