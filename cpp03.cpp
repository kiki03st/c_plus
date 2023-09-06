//practice 1. Box
#include <iostream>

using namespace std;

int main(){
    int length, width, height;  //int형 변수 length, width, height 선언
    cout<<"Input length: ";
    cin>>length;    //int형 변수 length에 박스의 한 변의 길이 입력
    cout<<"Input width: ";
    cin>>width;     //int형 변수 width에 박스의 한 변의 길이 입력
    cout<<"Input height: ";
    cin>>height;    //int형 변수 height에 박스의 한 변의 길이 입력
    cout<<"Box volume: "<<length * width * height<<endl;    //length * width * height를 계산한 값인 박스의 부피 출력 
    return 0;
}


//practice 2. Timer
#include <iostream>

using namespace std;

int main(){
    cout<<"Enter the number of seconds: ";
    int number, day, hour, minute, second;  //int형 변수 number, day, hour, minute, second 선언
    cin>>number;    //int형 변수 number에 전체 시간을 초 단위로 입력
    day = number / (60*60*24);  //day 변수의 값을 number 변수를 60 * 60 * 24로 나누어 일 단위로 변환
    number-=60*60*24*day;   //number의 값에서 day의 값을 구할 때, 사용한 시간만큼을 뺴줌
    hour = number / (60*60);    //hour 변수의 값을 number 변수를 60 * 60으로 나누어 시간 단위로 변환
    number-=hour*60*60; //number의 값에서 hour의 값을 구할 때, 사용한 시간만큼을 뺴줌
    minute = number / 60;   //minute 변수의 값을 number 변수를 60으로 나누어 시간 단위로 변환
    number-=minute*60;  //number의 값에서 minute의 값을 구할 때, 사용한 시간만큼을 뺴줌
    second = number;    //number에 남은 잔여 시간(초)을 second 변수의 값으로 지정
    cout<<number<<" seconds = "<<day<<" days, "<<hour<<" hours, "<<minute<<" minutes, "<<second<<" seconds"<<endl;  //전체 시간(초)을 일, 시간, 분, 초 값으로 나누어 출력
    return 0;
}


//practice 3. Digits
#include <iostream>

using namespace std;

int main(){
    int number; //int형 변수 number 선언
    cout<<"Input your number: ";
    cin>>number;    //int형 변수 number에 정수형 값(4자리) 입력
    cout<<"thousands: "<<number / 1000<<endl<<"hundreds: "<<number % 1000 / 100<<endl<<"tens: "<<number % 100 / 10<<endl<<"ones: "<<number % 10<<endl;  //number / 1000, number % 1000 / 100, number % 100 / 10, number % 10 등의 연산을 활용하여 number의 천의 자리, 백의 자리, 십의 자리, 일의 자리를 구해서 각각 출력
    return 0;
}
