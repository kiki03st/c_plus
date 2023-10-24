#include <iostream>
#include <climits>

using namespace std;

int main(){
	int intsize = INT_MAX;
	short shortsize = SHRT_MAX;
	long longsize = LONG_MAX;
	long long llongsize = LLONG_MAX;
	cout << "int size : " << intsize <<endl;
	cout << "short size : " << shortsize << endl;
	cout << "long size : " << longsize << endl;
	cout <<"long long size : " << llongsize << endl;
	cout << "int size + 1 : " << intsize + 1 << endl;
	return 0;
}
