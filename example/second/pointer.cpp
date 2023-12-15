#include <iostream>

using namespace std;

// 포인터들을 선언했을 때, 각각의 크기를 반환하는 함수
void size(){
	short *s;
	int *i;
	long *l;
	float *f;
	double *d;

	cout << sizeof(s) << endl;
	cout << sizeof(i) << endl;
	cout << sizeof(l) << endl;
	cout << sizeof(f) << endl;
	cout << sizeof(d) << endl;
}

int main(){
	short s;
	int i;
	long l;
	float f;
	double d;
	
	// 자료형과 관계없이 주소값의 범위는 정해져 있으므로 전부 동일한 크기를 나타냄
	cout << &s << endl;
	cout << &i << endl;
	cout << &l << endl;
	cout << &f << endl;
	cout << &d << endl;
	
	// 컴퓨터 프로세서에 따라 4 또는 8 출력
	cout << sizeof(&s) << endl;
	cout << sizeof(&i) << endl;
	cout << sizeof(&l) << endl;
	cout << sizeof(&f) << endl;
	cout << sizeof(&d) << endl;

	// 위의 출력값과 동일하게 출력됨
	size();

	// 포인터는 주소를 나타내는 변수, 그러므로 &i를 통해 i의 주소값을 대입시켜줌
	// int *ptr = &i;는
	// int *ptr;
	// ptr = &i;로 이해하면 됨
	// *ptr = value;의 형태는 포인터 변수의 값을 지정하는 것으로, value의 자료형으로 int 등이 들어갈 수 있음
	// ptr = value; 형태는 포인터 변수의 주소를 지정하는 것으로, value의 자료형으로 int*와 같은 포인터형이 들어가야 함
	int *ptr = &i;
	// i의 값을 바꾸면 i와 동일한 주소를 사용하고 있는 변수 ptr의 값도 바뀜
	i = 10;
	cout << ptr << endl;
	// i의 값으로 지정했던 10이 *ptr을 출력했을 때에도 동일하게 출력됨
	cout << *ptr << endl;

	int *qtr;
	// 포인터의 주소는 type casting을 이용하여 직접 지정해줄 수도 있음
	qtr = (int*)100;
	// 0x64 출력 (10진수 표기 시 100)
	cout << qtr << endl;
	// qtr 주소의 메모리를 사용하기 위해 new를 이용하여 값으로 사용할 자료형을 나타내주어야 함
	// 만약 qtr = new int; 구문을 뺄 경우, 메모리에 접근할 수 없는 상태가 되기에 Segmentation fault 발생
	qtr = new int;
	*qtr = 200;
	cout << *qtr << endl;
	return 0;
}
