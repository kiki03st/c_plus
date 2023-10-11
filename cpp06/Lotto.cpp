#include <iostream>
#include <random>

using namespace std;

int main(){
    int index = 0, randint;
    int num[6] = {0, };
    bool tf;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 45);
    while(index < 6){
        randint = dist(gen);
        if(index == 0){
            cout << randint << endl;
            num[0] = randint;
            index++;
            continue;
        }
        tf = true;
        for(int i = 0; i < index; i++){
            if(randint == num[i]){
                tf = false;
                break;
            }
        }
        if(tf){
            cout << randint << endl;
            num[index++] = randint;
        }
    }

    return 0;
}