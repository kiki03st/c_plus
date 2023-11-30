#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	int index;
	
	node(int d, node *n, int i): data(d), next(n), index(i) {}
};

class my_list{
	private:
		node *head, *current, *start;
		int index;
	public:
		my_list(): head(0), current(0), index(0) {}
		my_list& append(const int d){
			head = new node(d, head, index++);
			if(!current){
				start = head;
				current = head;
			}
			return *this;
		}
		my_list& next(){
			if(index){
				if(!current){
					current = start;
				}
				current = current -> next;
			}
			else cout << "list out of range" << endl;
			return *this;
		}
		void rewind(){
			current = start;
		}
		int get(){
			if(!head){
				cout << "EMPTY : ";
				return NULL;
			}
			else if(!current) current = head;
			return current -> data;
		}
		void info(){
			cout << "length: " << index << ", current: " << current -> index << endl;
		}
/*
		int operator[](int i){
			node* s;
			for(s = head; s -> index != i; s = s -> next);
			return s -> data;
		}
*/
};

int main(){
	my_list l;
	l.append(10).append(20).append(30).append(40);

	l.next().next().next();
	cout << l.get() << endl;

	l.info();
	l.rewind();
	cout << l.get() << endl;
	return 0;
}
