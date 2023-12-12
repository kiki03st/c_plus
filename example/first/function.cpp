#include <iostream>

using namespace std;

int f(int x);
int g(int y);

int main(){
	int answer = 1 + 2 + f(3);
	cout << answer << endl;
	return 0;
}

int f(int x){
	return g(x);
}
int g(int y){
	return f(y);
}
