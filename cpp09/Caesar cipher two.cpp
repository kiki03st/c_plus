#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    int key;
    cout << "Input string: ";
    getline(cin, line);
    cout << "Input key: ";
    cin >> key;
    for(int i = 0; i < line.length(); i++){
        if(line[i] <= 'Z' && line[i] >= 'A'){
            if(line[i] + key > 'Z'){
                line[i]+=key;
            }
            else{
                line[i]+=key-26;
            }
        }
    }
    cout << "Cipher string: ";
    for(int i = 0; i < line.length(); i++){
        cout << line[i];
    }
    return 0;
}