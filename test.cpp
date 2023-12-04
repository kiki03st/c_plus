#include <iostream>

using namespace std;
class Stack{
	int stack[16];
	int sp;
	void push(int value) { stack[sp++] = value; }
	int pop() { return stack[--sp]; }
};
int main(){
	Stack s1;
	s1.push(10);
	cout << s1.pop() << endl;
	return 0;
}
