#include <iostream>

using namespace std;

void push(int* arr, int len){
    int index = 0;
    for(int i = index; i < len - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[len - 1] = 0;
}

void pull(int value, int* arr, int len){
    int index = 0;
    for(int i = index; i < len - 1; i++){
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

void hanoi(int* A, int* B, int* C, int n){
    bool tf = true;
    for(int i = 0; i < n; i++){
        if(B[i] == i + 1){
            tf = false;
            break;
        }
    }
    if(tf){
        return;
    }
    else if(!C[0]){
        pull(A[0], C, n);
        push(A, n);
    }
    else if(!B[0]){
        pull(A[0], B, n);
        push(A, n);
    }
    else if
}

int main(){
    int n;
    cout << "Enter the number of disks : ";
    cin >> n;
    int A[n];
    int B[n] = {0, };
    int C[n] = {0, };
    for(int i = 0; i < n; i++) A[i] = i + 1;
    hanoi(A, B, C);
    return 0;
}