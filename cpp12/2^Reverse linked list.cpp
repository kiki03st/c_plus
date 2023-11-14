#include <iostream>

using namespace std;

typedef struct linked_list{
	int data;
	struct linked_list *prev, *next;
}SLL;

void append(linked_list *p, int num){
	for(p; p -> next != NULL; p = p -> next){}
	p -> next = new SLL;
	p -> next -> prev = p;
	p -> next -> data = num;
}

void show(linked_list *p){
	for(p; p != NULL; p = p -> next){
		cout << p -> data << endl;
	}
}

void reverse(linked_list *p){
	int *backup;
	int cnt = 0;
	while(p != NULL){
		cnt++;
		backup = new int[cnt];
		backup[cnt - 1] = p -> data;
		if(p -> next == NULL) break;
		p = p -> next;
	}
	for(int i = 0; i < cnt; i++){
		p -> data = backup[i];
		if(p -> prev == NULL) break;
		p = p -> prev;
	}
//코드 결과, 40 0 0 0만 나옴 -> backup의 크기가 갱신될 때, 내부 내용물을 없애는 것으로 추정
}

int main(){
	SLL *head = new SLL;
	SLL *p = new SLL;
	head -> data = 10;
	p = head;
	
	append(p, 20);
	append(p, 30);
	append(p, 40);
	
	show(head);
	
	reverse(head);

	show(head);

	return 0;
}
