#include <iostream>

using namespace std;

class test{
	private:
		int target;
		const int n;
		int &ref;
	public:
		/*
		test(){
			target = 0;
			n = 0;
			ref = target;
		}
		test(int a, int b){
			n = a;
			ref = b;
		}
		*/
		test(): target(0), n(0), ref(target){}
		test(int a, int b): target(b), n(a), ref(target){}
		void print(){
			cout << target << endl;
			cout << n << endl;
			cout << ref << endl;
		}
};

int main(){
	test *a = new test(10, 20);
	test *b = new test;
	a -> print();
	b -> print();
	return 0;
}
