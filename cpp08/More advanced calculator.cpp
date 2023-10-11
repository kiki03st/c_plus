#include <iostream>

using namespace std;

void solution(char k){
    if(k == 'Q')
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
        solution();
    }
}