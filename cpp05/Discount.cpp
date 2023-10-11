#include <iostream>

using namespace std;

int main(){
	int count;
	cout << "number of items? ";
	cin >> count;
	if(count >= 10){
		cout << "original price: " << 1000 * count << " KRW" << endl;
        cout << "discounted price: " << 900 * count << " KRW" << endl;
    }
    else{
        cout << "price: " << 1000 * count << " KRW" << endl;
    }
    return 0;
}