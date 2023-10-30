#include <iostream>
#include <string>
using namespace std;

struct member{
	int id;
	string name;
	union{
		string test;
	} contact;
};

int main(){
	member m = {1, "kk", "kkk"};
	return 0;
}
