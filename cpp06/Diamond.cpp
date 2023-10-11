#include <iostream>

using namespace std;

int main(){
    int n, star = 1;
    cout << "input height: ";
    cin >> n;
    for(int i = 1; i < n / 2.0; i++){
        for(int j = 0; j < n / 2.0 - i; j++){
            cout << " ";
        }
        for(int j = 0; j < star; j++){
            cout << "*";
        }
        star+=2;
        cout << endl;
    }
    if(n%2 == 1){
        for(int i = 0; i < star; i++) cout << "*";
        cout << endl;
    }
    else{
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < star; j++) cout << "*";
            cout << endl;
        }
    }
    star-=2;
    for(float i = n / 2.0 - 1; i > 0; i--){
        for(int j = 0; j < n / 2.0 - i; j++){
            cout << " ";
        }
        for(int j = 0; j < star; j++){
            cout << "*";
        }
        star-=2;
        cout << endl;
    }
}