#include <iostream>

using namespace std;

class test{
	private:
		int value;
	public:
		test(): value(0){
			cout <<"create" << endl;
		}
		test(int a): value(a){
			cout << "create " << a << endl;
		}
		~test(){
			cout << "delete " << value << endl;
		}
};



int main(){
	// new를 활용한 클래스 객체 생성 시 프로그램 종료할 때 파괴자 함수 호출 안됨
	test* a = new test(10);
	// 일반적인 클래스 객체 생성 시 프로그램 종료할 때 파괴자 함수 호출
	test b;
	return 0;
}
