//practice 1. Simple calculator
#include <iostream>

using namespace std;

int main(){
    int n, m;   //int형 변수 n, m 선언
    cout<<"Input1: ";
    cin>>n; //int형 변수 n에 정수형 값 저장
    cout<<"Input2: ";
    cin>>m; //int형 변수 m에 정수형 값 저장
    cout<<endl;
    cout<<"Add: "<<n + m<<endl<<"Sub: "<<n - m<<endl<<"Mul: "<<n * m<<endl<<"Div: "<<n / m<<endl;   //n + m, n - m, n * m, n / m 값 출력
    return 0;
}


//practice 2. ID card(?)
#include <iostream>
#include <string>   //string형을 사용하기 위해 string 라이브러리 불러오기

using namespace std;

int main(){
    cout<<"Your student number: ";
    int number;     //int형 변수 number 선언
    cin>>number;    //int형 변수 number에 정수형 값(학번) 저장
    cout<<"Your name: ";
    string name, name_2;    //string형 변수 name, name_2 선언
    cin>>name;  //string형 변수 name에 문자열(이름) 저장
    cin>>name_2;    //string형 변수 name_2에 문자열(성) 저장
    cout<<endl;
    cout<<"My name is "<<name<<" "<<name_2<<".\nMy student ID is "<<number<<".\nMy name and ID is "<<name<<" "<<name_2<<" and "<<number<<".\n"; //number, name, name_2 변수를 활용하여 학번, 이름 등을 출력
    return 0;
}


//practice 3. Wrong number
#include <iostream>

using namespace std;

int main(){
    int n;  //int형 변수 n 선언
    cout<<n<<endl; //출력 : 정크값
    cin>>n; //int형 변수 n에 정수형 값이 아닌 문자열 입력
    cout<<n<<endl; //출력 : 0 (타입에 부합하지 않는 값을 입력하는 경우, 값이 0으로 초기화되는 것으로 추정)
    return 0;
}


//practice 4. How old are you?
#include <iostream>

using namespace std;

int main(){
    cout<<"Enter yout age: ";
    int age;    //int형 변수 age 선언
    cin>>age;   //int형 변수 age에 정수형 값 입력
    cout<<"Your age in months is "<<age * 12<<".\n";    //나이 * 12를 계산하여 살아온 개월 수로 변환하여 출력
    return 0;
}


//practice 5. Celsius and Fahrenheit
#include <iostream>

using namespace std;

int main(){
    int temp;   //int형 변수 temp 선언
    cout<<"Please enter a Celsius value: ";
    cin>>temp;  //int형 변수 temp에 정수형 값(섭씨 온도) 입력
    cout<<temp<<" degrees Celsius is "<<1.8*temp+32.0<<" degrees Fahrenheit."<<endl;    //temp 자체 값과 1.8 * 섭씨온도 + 32.0을 계산한 화씨 온도 값을 출력
    return 0;
}
