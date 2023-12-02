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
		my_list& operator +(int n){
			this -> append(n);
			return *this;
		}
		my_list& operator +(my_list* p){
			node *loop;
			for(loop = p -> start; loop != NULL; loop = loop -> next){
				head = new node(loop -> data, head, loop -> index + this -> index++);
			}
			return *this;
		}
		my_list& operator -(int n){
			node* loop;
			for(loop = start; loop != NULL; loop = loop -> next){
				if(loop -> next -> index == n){
					delete loop -> next;
					loop -> next = loop -> next -> next;
					return *this;
				}
			}
			cout << "not found" << endl;
			return *this;
		}
		void printall(){
			cout << "List : " << endl;
			node *loop;
			for(loop = start; loop != NULL; loop = loop -> next){
				cout << loop -> index << " : " << loop -> data << endl;
			}
		}

};

int main(){
	my_list l;
	my_list s;
	l.append(10).append(20).append(30).append(40);
	s.append(20).append(30).append(40).append(100);
	l = l + 50;
	l = l + s;
	l.printall();
	l = l - 5;
	l.printall();
	l.next().next().next();
	cout << l.get() << endl;

	l.info();
	l.rewind();
	cout << l.get() << endl;
	return 0;
}
