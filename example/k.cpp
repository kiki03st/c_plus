#include <iostream>

using namespace std;

class Car{
	private:
		int speed;
		int gear;

		const int cons;
		int &ref;
	public:
		Car(){
			speed = 0;
		}
		Car(int p){
			cons = 10;
			ref = p;
		}
};



int main(){
	return 0;
}
