#include <iostream>
#include <string>

using namespace std;
/*
int main(){
    string str;
    int key;
    cout << "Input string: ";
    cin >> str;
    cout << "Input key: ";
    cin >> key;
    for(int i = 0; i < str.length(); i++){
        str[i] = str[i] + key;
    }
    cout << "Cipher string: " << str << endl;
    return 0;
}
*/
/*
int main(){
    string str;
    int key;
    cout << "Input string: ";
    cin >> str;
    cout << "Input key: ";
    cin >> key;
    for(int i = 0; i < str.length(); i++){
        str[i] = str[i] - key;
    }
    cout << "Decrypted string: " << str << endl;
    return 0;
}
*/
/*
int main(){
    int x, y;
    cout << "Input x: ";
    cin >> x;
    cout << "Input y: ";
    cin >> y;
    string result = (x > 0) ? ((y > 0) ? "1st" : "4th") : ((y > 0) ? "2nd" : "3rd");
    cout << "It is located in the " << result << " quadrant." << endl;
    return 0;
}
*/
/*
int main(){
    long long world, KOR;
    cout << "Enter the world's population: ";
    cin >> world;
    cout << "Enter the population of KOR: ";
    cin >> KOR;
    cout.precision(3);
    cout << "The population of KOR is " << (float)KOR / world << "% of the world population. " << endl;
    return 0;
}
*/

int main(){
    int height;
    cout << "Input your height: ";
    cin >> height;
    int feet = (int)(height / 2.54) / 12;
    float inch = height / 2.54 - feet * 12;
    cout << height << "cm is " << feet / 12 << "feet " << inch << "inch. " << endl;
    return 0;
}