#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a;
  string b;

  a = "This is a string sample!";

  cout << a << endl;

  cout << "Input your string: ";
  cin >> b;

  cout << "Your string is -- " << b << " --" << endl;
  return 0;
}
