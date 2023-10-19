#include <iostream>
#include <cmath>


using namespace std;

void dist_2d(){
	int x1, x2, y1, y2;
	cout << "input x1, y1:";
	cin >> x1 >> y1;
	cout << "input x2, y2:";
	cin >> x2 >> y2;
	cout << "Distance: " << sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) << endl;
}

int main(){
	dist_2d();
	return 0;
}
