#include <iostream>

using namespace std;

template <typename T>
void solution(char k, int a, T b){
	if(k == '+'){
		cout <<  a + b;
	}
	else if(k == '-'){
		cout << a - b;
	}
	else if(k == '*'){
		cout << a * b;
	}
	else if(k == '/'){
		if (sizeof(b) == 4){
			solution(k, a, (double)b);
		}
		else{
			cout << a / b;
		}
	}
}

int main(){
    cout << "--------------" << endl;
    cout << "+ : add" << endl;
    cout << "- : subtract" << endl;
    cout << "* : multiply" << endl;
    cout << "/ : divide" << endl;
    cout << "Q : quit" << endl;
    cout << "--------------" << endl << endl;
    cout << "Select an operator: ";
    char k;
    cin >> k;
    if(k == 'Q') return 0;
    else{
        int a, b;
        cout << "Input two number: ";
        cin >> a >> b;
        cout << "Answer: ";
	solution(k, a, b);
	cout << endl;
    }
}
