
#include <iostream>
#include <string>

using namespace std;

void three_dot(string line){
	for(int i = 0; i < line.length() % 3; i++){
		cout << line[i];
	}
	for(int i = line.length() % 3; i < line.length(); i+=3){
		cout << ",";
		for(int j = i; j < i + 3; j++){
			cout << line[j];
		}
	}
	cout << endl;
}

int main(){
	cout << "input number: ";
	string line;
	cin >> line;
	three_dot(line);
	return 0;
}
