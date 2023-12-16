#include <iostream>

using namespace std;

class Test{
	private:
		int x, y;
	public:
		int result(){
			return x + y;
		}
		int show_x(){
			return x;
		}
		int show_y(){
			return y;
		}
		Test(){
			this -> x = -1;
			this -> y = -1;
			cout << "Create Test!" << endl;
		}
		Test(int x, int y){
			this -> x = x;
			this -> y = y;
			cout << "Create Test!" << endl;
			cout << "x is " << x << endl;
			cout << "y is " << y << endl;
		}
		~Test(){
			cout << "Distroy Test" << endl;
		}
};

int main(){
	// new는 메모리가 할당되면서 클래스의 생성자 함수가 호출됨
	Test *a = new Test;
	// 상황에 따라 인자를 받는 식의 생성자 함수도 사용 가능
	Test *b = new Test(10, 20);
	// a의 함수 호출(포인터이므로 -> 사용)
	cout << a -> show_x() << endl;
	cout << a -> show_y() << endl;
	cout << a -> result() << endl;

	// b의 함수 호출(포인터이므로 -> 사용)
	cout << b -> show_x() << endl;
	cout << b -> show_y() << endl;
	cout << b -> result() << endl;

	// a의 메모리를 해제하면서 클래스의 파괴자 함수 호출
	delete a;
	// b의 메모리를 해제하면서 클래스의 파괴자 함수 호출
	delete b;

	// malloc을 이용하여 메모리 할당, 생성자 함수는 호출되지 않음
	Test *m = (Test*)malloc(sizeof(Test));
	// 생성자 함수가 호출되지 않았기에 x, y의 값이 0으로 출력됨
	cout << m -> show_x() << endl;
	cout << m -> show_y() << endl;
	cout << m -> result() << endl;
	// free로 m에 할당된 메모리가 해제되지만, 파괴자 함수는 호출하지 않음
	free(m);
	return 0;
}
