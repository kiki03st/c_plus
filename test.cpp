#include <iostream>

using namespace std;

int main(){
	int height, feet;
	float inch;
	cout << "Input your height: ";
	cin >> height;
	inch = height / 2.54;
	feet = inch / 12;
	inch -= feet * 12;
	cout << height << "cm is " << feet << " feet " << inch << " inch. " << endl;
	return 0;
}