#include <iostream>
#include <string>

using namespace std;

struct test{
	int a = 10;
	int b = 20;
};

int main(){
	struct test id;
	cout << id.a << endl;
	cout << id.b << endl;
	return 0;
}
