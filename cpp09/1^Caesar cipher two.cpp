#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	cout << "Input string: ";
	getline(cin, line);
	int key;
	cout << "Input key: ";
	cin >> key;
	for(int i = 0; i < line.length(); i++){
		if(line[i] >= 'A' && line[i] <= 'Z'){
			line[i]+=key;
			if(line[i] > 'Z'){
				line[i]-=26;
			}
			else if(line[i] < 'A'){
				line[i]+=26;
			}
		}
	}
	cout << "Cipher string: " << line << endl;
	return 0;
}
