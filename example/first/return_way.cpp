#include <iostream>

using namespace std;

int func1(){
	return 0;
}

int func2(){
	return(0);
}
int func3(){
	return (0);
}

int main(){
	cout << "func1 : " << func1() << endl;
	cout << "func2 : " << func2() << endl;
	cout << "func3 : " << func3() << endl;
	return 0;
}
