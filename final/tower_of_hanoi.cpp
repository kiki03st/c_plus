#include <iostream>

using namespace std;

void hanoi(int n, char from, char tmp, char to){
	if(n == 1){
		cout << n << " : " << from << " -> " << to << endl;
	}
	else{
		hanoi(n - 1, from, to, tmp);
		cout << n << " : " << from << " -> " << to << endl;
		hanoi(n - 1, tmp, from, to);
	}
}
/*
void hanoi(int n, char a, char b, char c){
	if(n == 1){
		cout << "Moved the disk " << n << " from " << a << " to " << b << " via " << c << "." << endl;
	}
	else{
		hanoi(n - 1, a, c, b);
		cout << "Moved the disk " << n << " from " << a << " to " << b << " via " << c << "." << endl;
		hanoi(n - 1, c, b, a);
	}
}
*/

int main(){
	int n;
	cout << "Enter the nuimber of disks : ";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
