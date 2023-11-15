#include <iostream>

using namespace std;

typedef struct list{
	int value;
	list *next;
}list;

void print(list *n){
	while(n != NULL){
		cout << n -> value << endl;
		n = n -> next;
	}
}

list* append(int value){
	list *n = new(list);
	n -> value = value;
	n -> next = NULL;
	return n;
}

int main(){
	list *head = NULL;
	list *loop = NULL;
	head = append(10);
	head -> next = append(20);
	head -> next -> next = append(30);
	print(head);
	for(loop = head; loop != NULL; loop = loop -> next){
		cout << loop -> value << endl;
	}
	/*
	head -> value = 10;
	head -> next = new(list);
	
	head -> next -> value = 20;
	head -> next -> next = new(list);
	head -> next -> next -> value = 30;
	head -> next -> next -> next = NULL;
	*/
	return 0;
}
