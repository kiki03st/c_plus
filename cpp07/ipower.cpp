#include <iostream>

using namespace std;

int ipower(int n, int k){
    int res = 1;
    for(int i = 0; i < k; i++){
        res*=n;
    }
    return res;
}

int main(){
    cout << "input number: ";
    int n;
    cin >> n;
    for(int i = 0; i <= 10; i++){
        cout << n << "^" << i << " = " << ipower(n, i) << endl;
    }
    return 0;
}