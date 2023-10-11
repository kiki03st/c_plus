#include <iostream>

using namespace std;

int main(){
    cout << "input numbers: ";
    int a, b, c;
    cin >> a >> b >> c;
    int min = a<b?(b<c?a:(a<c?a:c)):(b<c?b:c);
    cout << "minimum number: " << min << endl;
	return 0;
}
