#include <iostream>

using namespace std;
class node{
	public:
		int data;
		node *next;
};
	
class my_list{
	private:
		node *stat, *head, *tail;
	public:
		my_list(){
			head = NULL;
			stat = tail = head;
		}
		my_list& append(int value){
			if(head == NULL){
				head = new node;
				stat = tail = head;
				tail -> data = value;
				tail -> next = NULL;
			}
			else{
				node *p = new node;
				p -> data = value;
				p -> next = NULL;
				tail = tail -> next = p;
			}
			return *this;
		}
		my_list& next(){
			if(stat -> next == NULL){
				cout << "더이상 이동할 수 없습니다." << endl;
			}
			else{
				stat = stat -> next;
			}
			return *this;
		}
		int get(){
			return stat -> data;
		}
		void rewind(){
			stat = head;
			}
		void info(){
			node* loop = new node;
			int len = 0;
			int index = 0;
			for(loop = head; loop != NULL; loop = loop -> next){
				if(loop == stat) index = len;
				len++;
			}
			cout << "length of list : " << len << endl << "index : " << index << endl;
		}

		my_list& operator +(int n){
			return append(n);
		}
		my_list& operator +(my_list &ref){
			this -> tail -> next = ref.head;
			this -> tail = ref.tail;
			return *this;
		}
		my_list& operator -(int n){
			int i = 0;
			node *loop = this -> head;
			for(i; i < n; i++) loop = loop -> next;
			while(loop -> next != NULL){
				loop -> data = loop -> next -> data;
				if(loop -> next -> next == NULL) tail = loop;
			}
			loop = NULL;
			return *this;
		}
		void printall(){
			node *loop;
			for(loop = this -> head; loop != NULL; loop = loop -> next) cout << loop -> data << " ";
			cout << endl;
		}
};

int main(){
	my_list l;
	my_list ll;
	l.append(10).append(20).append(30).append(40);
	l.next().next();
	cout << l.get() << endl;
	ll = ll + 100 + 200 + 300;
	ll.next();
	cout << ll.get() << endl;
	ll = ll + l;
	ll.printall();
	ll = ll - 5;
	ll.next();
	cout << ll.get() << endl;
	ll.printall();
	return 0;
}
