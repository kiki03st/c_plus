#include <iostream>
#include <string>

using namespace std;

int main(){
	string str1 = "This is my string.";
	string str2 = "Yes, I know.";

	cout << "01. " << str1 << str2 << endl;
	cout << "02. " << str1 << "\b\b\b\b\b.....?" << endl;
	// \b는 커서를 한칸 앞으로 옮긴다는 의미
	// ex) abc\bd -> abd, abc\b\bd -> adc
	cout << "03. " << str1 << "\n" << str2 << endl;
	cout << "04. " << str1 << "\t" << str2 << endl;
	cout << "05. " << "\"" << str1 << "\"" << endl;
	cout << "06. " << "\'" << str2 << "\'" << endl;
	cout << "07. " << "\\" << str1 << "\\" << endl;
	return 0;
}
