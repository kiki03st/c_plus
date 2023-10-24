#include <iostream>
#include <ctime>

using namespace std;

int main(){
	char credit = 'q';
	clock_t start, end;

	start = clock();
	for(int i = 0; i < 100000000; i++){
		if(credit == 'a'){}
		else if(credit == 'b'){}
		else if(credit == 'c'){}
		else if(credit == 'd'){}
		else {}
	}
	end = clock();
	cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
	// if문을 활용한 시간은 약 1.1초 가량 소요
	start = clock();
	for (int i = 0; i < 100000000; i++){
		switch(credit){
			case 'a': break;
			case 'b': break;
			case 'c': break;
			case 'd': break;
			default: break;
		}
	}
	end = clock();
	cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
	// switch문을 활용한 시간은 약 2.4초 가량 소요
	return 0;
}
