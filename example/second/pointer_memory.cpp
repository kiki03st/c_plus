#include <iostream>

using namespace std;

int main(){
	// 길이 16의 char형 배열 생성
	char a[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00};

	// 배열은 포인터이므로 포인터를 이용한 연산도 가능
	// 64bit 기준, char은 1, int는 4, long은 8 byte이므로 *l의 출력값으로 8877665544332211이 나와야함
	// 32bit 기준, long이 4 byte이므로 *l의 출력값으로 44332211이 나옴

	// 포인터 c를 char형 변수의 주소값으로 지정
	// char은 1 byte이므로 a[0]값만을 가짐
	char *c = (char*)a;

	// 포인터 i를 int형 변수의 주소값으로 지정
	// int는 4 byte이므로 a[0] ~ a[3]까지의 값을 가짐
	// 뒤쪽 인덱스부터 앞으로 이동하면서 값을 붙여나감
	// i 기준, a[0], a[1], a[2], a[3]은 각각 11, 22, 33, 44이므로 a[3]부터 순서대로 44332211을 붙여나감(16진수 기준)
	int *i = (int*)a;
	long *l = (long*)a;

	// 16진수 기준으로 출력
	cout << hex;
	cout << (int)*c << endl;
	cout << *i << endl;
	cout << *l << endl;

	// 기본적으로 배열 arr에 대해 *arr를 출력하면, arr[0]의 값을 출력
	// 그러므로 *i, *l은 각각 i[0], l[0]의 값을 출력하고 있던 것과 동일
	// i[1], i[2]를 출력 시 i[0]을 출력했던 방법과 동일하게 88776655, ccbbaa99가 출력됨
	cout << i[1] << endl;
	cout << i[2] << endl;

	// 이런식으로도 출력 가능
	cout << *(i + 1) << endl;
	cout << *(i + 2) << endl;


	// n의 값은 뒤에 존재하는 값부터 주소값이 줄어드는 방향으로 저장된다.
	// ex) 주소값이 a일 때, a = 0xff, a + 1 = 0xee, a + 2 = 0xdd ...
	long n = 0x8899AABBCCDDEEFF;
	// 포인터 변수 ptr의 값을 n의 주소값으로 지정한다. 단, 지정되는 주소값은 주소 대상 변수의 자료형이 char라고 가정한다. 
	char *ptr = (char*)&n;

	// void*로 타입 캐스팅 하는 이유는 ptr을 문자 또는 문자열로 생각하지 않게 하기 위해서임
	cout << (void*)ptr << endl;
	cout << (void*)(ptr + 4) << endl;

	// ptr[3]의 값을 int형의 크기인 4 byte만큼 불러온다. ptr[3]은 0xCC이므로 99AABBCC가 반환되어야 한다. 
	cout << *((int*)(ptr + 3)) << endl;
	return 0;
}
