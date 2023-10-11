//2등 조건 : 5개 일치 + 보너스볼 번호 일치
#include <iostream>
#include <random>

using namespace std;

void solution(int* num, int* lotto){
    int cnt = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(num[i] == lotto[j]){
                cnt++;
                break;
            }
        }
    }
    
    cout << "You match " << cnt << " numbers! ";
    if(cnt == 6){
        cout << "You are 1st place!" << endl;
    }
    else if(cnt == 5){
        cout << "Bonus Number: " << lotto[6] << endl;
        bool tf = true;
        for(int i = 0; i < 6; i++){
            if(num[i] == lotto[6]){
                tf = false;
                cout << "You are 2nd place!" << endl;
                break;
            }
        }
        if(tf){
            cout << "You are 3rd place!" << endl;
        }
    }
    else if(cnt >= 3){
        cout << "You are " << cnt + 2 << "th place!" << endl;
    }
}

int main(){
    cout << "Guess lottery numbers:" << endl;
    int num[6], lotto[7], randint;
    bool tf;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 45);
    for(int i = 0; i < 7;){
        tf = true;
        randint = dist(gen);
        for(int j = 0; j < i; j++){
            if(lotto[j] == randint){
                tf = false;
                break;
            }
        }
        if(tf){
            lotto[i] = randint;
            i++;
        }
    }
    for(int i = 0; i < 6; i++){
        cin >> num[i];
    }
    cout << "Number: ";
    for(int i = 0; i < 6; i++){
        cout << lotto[i] << " ";
    }
    cout << endl;
    solution(num, lotto);
}