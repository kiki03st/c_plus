#include <iostream>

using namespace std;

struct in{
	short a;
	int b;
};
// in : 8 byte
struct out{
	short n;
	struct in m;
	int k;
};
// out : in(struct) = 8 -> 8 * 3 = 24

struct case_in{
	double a;
	int b;
};

struct case_out{
	float a;
	struct case_in b;
	double c;
};

struct two_short{
	short a;
	short b;
};

struct short_int{
	short a;
	int b;
};

struct two_int{
	int a;
	int b;
};

int main(){
	cout << sizeof(char) << endl;
	// cout << sizeof(two_short) << endl;
	// cout << sizeof(short_int) << endl;
	// cout << sizeof(two_int) << endl;
	// cout << "float : " << sizeof(float) << endl;
	// cout << "double : " << sizeof(double) << endl;
	// cout << "case_in : " << sizeof(case_in) << endl;
	// cout << "case_out : " << sizeof(case_out) << endl;
	// cout << sizeof(in) << endl;
	// cout << sizeof(out) << endl;
	return 0;
}
