#include <iostream>
#include <random>


using namespace std;

int main(){
	random_device rd;
	mt19937 gen(rd());
	
	for(int i = 0; i < 6; i++){
		cout << (gen() % 45) << endl;
	}
	return 0;
}
