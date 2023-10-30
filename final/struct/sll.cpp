#include <iostream>

using namespace std;

typedef struct{
	int data;
	int rank;
	Node *Next;
}Node;

void search(Node* target, int n){
	while(true){
		if(target -> data == n){
			cout << n << " is in " << target -> rank << endl;
			return;
		}
		else if(target -> Next == NULL){
			cout << "Not Found " << n;
			return;
		}
		target = target -> Next;
	}
}

void insert(Node* target, int n, int index){
	while(true){
		if(target -> rank == index){
			int tmp = target -> data;
			while(target -> Next == NULL){
				target -> data = n;
				target = target -> Next;
				n = tmp;
			}
			cout << n << " is inserted in " << index << endl;
			return;
		}
		if(target -> Next == NULL){
			cout << "Not Found Index" << endl;
			return;
		}
		target = target -> Next;
	}
}

void delete(Node* target, int index){
	while(target -> rank != index){
		if(target -> Next == NULL){
			cout << "Not Found Index" << endl;
			return;
		}
		target = target -> Next;
	}
	cout << "delete " << target -> data << " in " << target -> rank << endl;
	while(target -> Next == NULL){
		target -> data = target -> Next -> data;
		target = target -> Next;
	}
	target -> data = -1;
}


int main(){
	Node *head, *p, *q;
	head -> rank = 0;
	p -> rank = 1;
	q -> rank = 2;
	head -> data = 8;
	p -> data = 6;
	q -> data = 7;
	search(head, 7);
	insert(head, 10, 1);
	delete(head
	delete

