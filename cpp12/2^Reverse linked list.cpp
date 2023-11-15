#include <iostream>

using namespace std;

template <typename T>
struct list{
	T value;
	list<T>* next;
};

template <typename T>
list<T>* append(T data){
	list<T>* p = new(list<T>);
	p -> value = data;
	p -> next = NULL;
	return p;
}

template <typename T>
list<T>* append(list<T>* node, T data){
	list<T>* p = new(list<T>);
	p -> value = data;
	p -> next = NULL;
	node = node -> next = p;
	return node;
}

template <typename T>
list<T>* reverse(list<T>* head){
	list<T>* loop = new(list<T>);
	int cnt = 0, num = 0;
	for(loop = head; loop != NULL; loop = loop -> next) cnt++;
	int* arr = new int[cnt]();
	for(loop = head; loop != NULL; loop = loop -> next) arr[num++] = loop -> value;
	for(loop = head; loop != NULL; loop = loop -> next) loop -> value = arr[--cnt];
	delete[] arr;
	return head;
}
	

int main(){
	list<int> *head;
	list<int> *loop;
	list<int> *tail;

	list<int>* r_head;

	tail = head = append(10);
	tail = append(tail, 20);
	tail = append(tail, 30);
	tail = append(tail, 40);
	for(loop = head; loop != NULL; loop = loop -> next) cout << loop -> value << endl;

	r_head = reverse(head);

	cout << "Reversed " << endl;
	for(loop = r_head; loop != NULL; loop = loop -> next) cout << loop -> value << endl;
	return 0;
}
