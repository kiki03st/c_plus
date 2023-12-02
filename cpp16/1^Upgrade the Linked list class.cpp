#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	int index;
	
	node(int d, int i): data(d), index(i) {}
};

class my_list{
	private:
		node *head, *current, *start;
		int index;
	public:
		my_list(): head(0), start(0), current(0), index(0) {}
		my_list& append(const int d){
			if(!start){
				head = new node(d, index++);
				head -> next = NULL;
				start = head;
			}
			else{
				node *p = new node(d, index++);
				head = head -> next = p;
				head -> next = NULL;
			}
			return *this;
		}
		my_list& next(){
			if(index){
				if(!current) current = start;
				else if(index - 1 == current -> index){
					cout << "list out of range" << endl;
					return *this;
				}
				current = current -> next;
			}
			else cout << "EMPTY" << endl;
			return *this;
		}
		void rewind(){
			current = start;
		}
		int get(){
			if(!current){
				if(start){
					current = start;
					return current -> data;
				}
				cout << "EMPTY : ";
				return 0;
			}
			else{
				if(current -> index >= this -> index){
					cout << "current is placed in " << current -> index << ". but my_list's last index is " << this -> index - 1 << ". " << endl;
					cout << "change current's index to " << this -> index - 1 << endl;
					current = head;
				}
				return current -> data;
			}
		}
		void info(){
			cout << "length: " << index << ", current: " << current -> index << endl;
		}
		my_list& operator +(int n){
			this -> append(n);
			return *this;
		}
		my_list& operator +(my_list p){
			for(node *loop = p.start; loop != NULL; loop = loop -> next){
				this -> append(loop -> data);
			}
			return *this;
		}
		my_list& operator -(int n){
			if(n >= index) cout << "list out of range" << endl;
			else if(n == 0) head = start = start -> next;
			else{
				node *loop;
				for(loop = start; loop -> next -> index != n; loop = loop -> next){}
				if(current -> index >= n) current = current ->  next;
				loop -> next = loop -> next -> next;
				if(loop != NULL){
					for(loop = loop -> next; loop != NULL; loop = loop -> next) loop -> index--;
				}
				this -> index--;
			}
			return *this;
		}
		void printall(){
			node *loop;
			for(loop = start; loop != NULL; loop = loop -> next){
				cout << loop -> data << " ";
			}
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

	ll.next().next().next();
	cout << ll.get() << endl;

	ll = ll - 5;
	ll.next();
	cout << ll.get() << endl;
	ll.printall();
	
	return 0;
}
