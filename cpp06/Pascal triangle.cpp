#include <iostream>

using namespace std;

int main(){
    int h;
    cout << "input height: ";
    cin >> h;
    int arr[h] = {1, 1, };
    int backup[h] = {1, 1, };
    for(int i = 0; i < h; i++){
        for(int j = 0; j < h - i - 1; j++) cout << '\t';
        for(int j = 0; j <= i; j++) cout << arr[j] << "\t\t";
        for(int j = 0; j < i; j++){
            arr[j + 1] = backup[j] + backup[j + 1];
        }
        arr[i + 1] = 1;
        for(int j = 0; j < h; j++){
            backup[j] = arr[j];
        }
        cout << endl;
    }
}