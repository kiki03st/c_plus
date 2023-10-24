#include <iostream>

using namespace std;

// stack의 기본 시스템은 FILO(First Input Last Output)임
// 함수의 요소가 스택에 저장되는 순서는 다음과 같음
// 1. 함수에 매개변수가 존재한다면 우측부터 순서대로 스택에 저장
// 2. 함수의 스택 프레임 저장(function's stack frame)
// 3. 함수 속에서 선언된 지역변수들을 좌측부터 순서대로 스택에 저장

void gunc(int i, int j){
	int k;
}
// 스택 저장 순서:
// 1. j, i
// 2. gunc stack frame
// 3. k

void func(void){
	int x, y, z;
	gunc(x, y);
}
// 스택 저장 순서:
// 1. func stack frame
// 2. x, y, z

int main(void){
	int a, b, c;
	func();
	return 0;
}
// 스택 저장 순서:
// 1. main stack frame
// 2. a, b, c
