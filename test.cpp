#include <iostream>
#include <string>
using namespace std;

int result(int n){
  int num = 1;
  for(int i = 0; i < n; i++){
    num*=2;
  }
  return num;
}
int main()
{
  int sum = 0;
  for(int i = 0; i <= 22; i++){
    sum+=result(i);
  }
  cout<<sum<<endl;
  return 0;
}
