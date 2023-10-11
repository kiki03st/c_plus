#include <iostream>
#include <string>

using namespace std;

int main(){
	cout << "Input your number: ";
	int n;
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	cin >> n;
	cout << "thousands: " << arr[n / 1000] << endl;
	cout << "hundreds: " << arr[n / 100 % 10] << endl;
	cout << "tens: " << arr[n / 10 % 10] << endl;
	cout << "ones: " << arr[n % 10] << endl;
	return 0;
}
