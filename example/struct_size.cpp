#include <iostream>

using namespace std;

typedef struct{
	short a;
	short b;
	int c;
}ssi;

typedef struct{
	short a;
	int b;
	short c;
}sis;

typedef struct{
	short a;
	short b;
	long long c;
}ssl;

typedef struct{
	short a;
	int b;
	long long c;
}sil;

typedef struct{
	short a;
	int b;
	short c;
	short d;
	short e;
}sisss;

int main(){
	cout << "short-short-int : " << sizeof(ssi) << endl;
	// output : 8
	cout << "short-int-short : " << sizeof(sis) << endl;
	// output : 12
	cout << "short-short-long long : " << sizeof(ssl) << endl;
	cout << "short-int-long long : " << sizeof(sil) << endl;
	cout << "short-int-short-short-short : " << sizeof(sisss) << endl;

	// 구조체의 크기는 구조체 속 변수의 선언 순서에 따라 달라지기도 함
	// 자료형이 제일 큰 변수의 크기의 배수임 
	return 0;
}
