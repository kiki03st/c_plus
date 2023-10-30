#include <iostream>

using namespace std;
struct test{
	string city;
	string country;
	int zipcode;
};
int main(){
	cout << sizeof(string) << endl;
	cout << sizeof(test) << endl;
	return 0;
}
