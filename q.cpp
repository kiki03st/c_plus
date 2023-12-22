#include <iostream>
#include <string>
using namespace std;

string* split(string line, char w){
  int start = 0, end = 0;
  int cnt = 0;
  string *arr = new string[line.length() + 1];
  for(int i = 0; i < line.length(); i++){
    if(line[i] == w){
      if(i == 0){
        start = 1;
        continue;
      }
      else{
      	string s = "";
        end = i;
        for(int j = start; j < end; j++){
          s += line[j];
        }
        start = i + 1;
		arr[cnt++] = s;
      }
    }
  }
  arr[cnt] = "\0";
  return arr;
}

int main(){
	string n = "Hello World";
	string *arr = split(n, ' ');
	int cnt = 0;
	while(arr[cnt] == "\0"){
		cout << arr[cnt++] << endl;
	}
	return 0;
}
