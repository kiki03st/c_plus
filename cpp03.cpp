//practice 1. Box
#include <iostream>

using namespace std;

int main(){
    int length, width, height;
    cout<<"Input length: ";
    cin>>length;
    cout<<"Input width: ";
    cin>>width;
    cout<<"Input height: ";
    cin>>height;
    cout<<"Box volume: "<<length * width * height<<endl;
    return 0;
}


//practice 2. Timer
#include <iostream>

using namespace std;

int main(){
    cout<<"Enter the number of seconds: ";
    int number, day, hour, minute, second;
    cin>>number;
    day = number / (60*60*24);
    number-=60*60*24*day;
    hour = number / (60*60);
    number-=hour*60*60;
    minute = number / 60;
    number-=minute*60;
    second = number;
    cout<<number<<" seconds = "<<day<<" days, "<<hour<<" hours, "<<minute<<" minutes, "<<second<<" seconds"<<endl;
    return 0;
}


//practice 3. Digits
#include <iostream>

using namespace std;

int main(){
    int number;
    cout<<"Input your number: ";
    cin>>number;
    cout<<"thousands: "<<number / 1000<<endl<<"hundreds: "<<number % 1000 / 100<<endl<<"tens: "<<number % 100 / 10<<endl<<"ones: "<<number % 10<<endl;
    return 0;
}
