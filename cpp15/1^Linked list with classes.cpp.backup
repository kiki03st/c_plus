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
};

int main(){
	my_list l;
	l.append(10).append(20).append(30).append(40);
	l.next().next();
	cout << l.get() << endl; // print out 30
	l.info(); // print out 'length: 4, current: 2 (or 3 depending on your start index)'
	l.rewind();
	cout << l.get() << endl;
	return 0;
}
