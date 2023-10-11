#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Select a menue (1~4)" << endl;
    int n;
    int menu[3] = {0, };
    string menu_name[3] = {"Bugger", "Fries", "Coke"};
    while(true){
        cout << "1) Bugger, 2) Fries, 3) Coke, 4) Finish" << endl;
        cin >> n;
        if(n == 4){
            cout << "Your order has been received!" << endl << endl;
            break;
        }
        menu[n - 1]++;
        cout << "You've ordered a " << menu_name[n - 1] << endl;
    }
    cout << "Your orders" << endl;
    for(int i = 0; i < 3; i++){
        if(menu[i] != 0){
            cout << i + 1 << ") " << menu_name[i] << " * " << menu[i] << endl;
        }
    }
    return 0;
}