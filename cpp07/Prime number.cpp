#include <iostream>

using namespace std;

bool solution(int num){
    if(num == 1){
        return false;
    }
    else if(num == 2){
        return true;
    }
    else{
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}

int main(){
    int n;
    while(true){
        cout << "input number: ";
        cin >> n;
        if(n == -1){
            cout << "Done. " << endl;
            return 0;
        }
        cout << n << " is ";
        if(solution(n)){
            cout << "a prime number. " << endl;
        }
        else{
            cout << "not a prime number. "<< endl;
        }
    }
    return 0;
 }