#include <iostream>
#include <string>

using namespace std;

void func(){ cout << "func" << endl; }
void gunc(){ cout << "gunc" << endl; }
void hunc(){ cout << "hunc" << endl; }
void iunc(){ cout << "iunc" << endl; }

int sum(int a, int b){ return a + b; }
void print(string str){ cout << str << endl; }

double time_measure(void(*ptr)()){
	clock_t start, end;
	start = clock();
	for(int i = 0; i < 100000; i++) ptr();
	end = clock();
	return (double) (end - start) / CLOCKS_PER_SEC;
}

int main(){
	// 함수도 고유한 주소값을 가짐
	// 함수의 주소를 볼 때에는 앞에 (void*) 붙여주기
	cout << (void*) &func << endl;
	cout << (void*) &gunc << endl;
	cout << (void*) &hunc << endl;
	cout << (void*) &iunc << endl;
	
	//포인터 함수를 활용하여 기존 함수의 주소를 불러와 그대로 사용할 수 있음
	int (*ptr_sum)(int a, int b);
	void (*ptr_print)(string str);
	ptr_sum = sum;
	ptr_print = print;
	cout << ptr_sum(10, 20) << endl;
	ptr_print("This is a function pointer!");

	cout << time_measure(&func) << endl;
	cout << time_measure(&gunc) << endl;
	return 0;
}
