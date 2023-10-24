#include <iostream>

using namespace std;

int stack[16];
int ptr;

void push(int data){
	stack[ptr] = data;
	ptr++;
}
int pop(){
	ptr--;
	return stack[ptr];
}

int main(){
	push(10);
	push(20);
	push(30);

	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;

	return 0;
}
