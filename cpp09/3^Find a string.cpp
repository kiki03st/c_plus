#include <iostream>
#include <string>

using namespace std;

int main(){
	string line1;
	string line2;
	cout << "string1: ";
	getline(cin, line1);
	cout << "string2: ";
	getline(cin, line2);
	bool tf;
	for(int i = 0; i < line1.length() - line2.length() + 1; i++){
		tf = true;
		for(int j = 0; j < line2.length(); j++){
			if(line1[i + j] != line2[j]){
				tf = false;
				break;
			}
		}
		if(tf){
			cout << i << endl;
			return 0;
		}
	}
	cout << "Not found" << endl;
	return 0;
}
