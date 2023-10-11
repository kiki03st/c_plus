#include <iostream>

using namespace std;

int main(){
	cout << "--------------" << endl;
	cout << "+ : add" << endl;
	cout << "- : subtract" << endl;
	cout << "* : multiply" << endl;
	cout << "/ : divide" << endl;
	cout << "Q : quit" << endl;
	cout << "--------------" << endl;
	cout << "Select an operator: ";
	char k;
	cin >> k;
	if(k == 'Q') return 0;
	int n, m, result;
	cout << "Input two number: ";
	cin >> n >> m;
	switch(k){
		case '+':
			cout << "Answer: " << n + m << endl;
			break;
		case '-':
			cout << "Answer: " << n - m << endl;
			break;
		case '*':
			cout << "Answer: " << n * m << endl;
			break;
		case '/':
			if(m == 0){
				cout << "Answer: Cannot divide by 0." << endl;
			}
			else{
				cout << "Answer: " << n / (float)m << endl;
			}
			break;
		default:
			cout << "Wrong Answer." << endl;
			break;
	}
	return 0;
}
