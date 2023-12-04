#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<char> v{'a', 'b', 'b', 'a', 'e', 'd', 'd', 'b'};
	for(auto i: v) cout << i << " " ;
	cout << endl;
	//write your code here
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(auto i: v) cout << i << " ";
	cout << endl;
	return 0;
}
