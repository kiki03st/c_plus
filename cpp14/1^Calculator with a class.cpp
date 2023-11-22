#include <iostream>

using namespace std;

class my_calc{
	private:
		int a, b;
	public:
		my_calc(int a, int b){
			this -> a = a;
			this -> b = b;
		}
		int add(){
			return a + b;
		}
		int sub(){
			return a - b;
		}
		int mul(){
			return a * b;
		}
		float div(){
			if(b == 0){
				cout << "Can't Divide by Zero : ";
				return NULL;
			}
			return (float)a / b;
		}
};

int main(){
	my_calc c(10, 0);

	cout << c.add() << endl;
	cout << c.sub() << endl;
	cout << c.mul() << endl;
	cout << c.div() << endl;
	return 0;
}
