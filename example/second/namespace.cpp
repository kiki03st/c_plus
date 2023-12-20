#include <iostream>

namespace mystd{
	class myc{
		public:
			myc& operator<<(char *n){
				std::cout << n << std::endl;
				return *this;
			}
			myc& operator<<(int n){
				std::cout << n << std::endl;
				return *this;
			}
			myc& operator<<(double n){
				std::cout << n << std::endl;
				return *this;
			}
			myc& operator<<(myc& (*f)(myc&)){
				return f(*this);
			}
			myc& endl(myc& p){
				std::cout << std::endl;
				return p;
			}
	};
	myc cout;
}

//using namespace mystd;

int main(){
	mystd::cout << "hello" << mystd::endl;
	mystd::cout << 123 << mystd::endl;
	mystd::cout << 1.23 << mystd::endl;
	mystd::cout << "hello" << 123 << 1.23 << mystd::endl;
	return 0;
}
