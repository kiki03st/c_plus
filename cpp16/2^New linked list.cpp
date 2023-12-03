#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
	int index;

	node(int d, node *n, int i): data(d), next(n), index(i) {}
};

class slist{
	private:
		node *head;
		node *current;
		int index;
	public:
		slist(): head(0), current(0), index(0) {}
		void push_front(const int &d){ head = new node(d, head, index++); }
		void push_back(const int &d){
			node *loop, *tmp;
			for(loop = head; loop != NULL; loop = loop -> next){
				loop -> index++;
				if(loop -> next == NULL) tmp = loop;
			}
			node *p = new node(d, NULL, 0);
			tmp -> next = p;
			this -> index++;
		}
		slist& next(){
			if(!current) current = head;
			else current = current -> next;
			
			return *this;
		}
		int get(){
			return current -> data;
		}

		int operator[](int i){
			node *s;
			for(s = head; s -> index != i; s = s -> next);
			return s -> data;
		}
};

int main(){
	slist s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);
	s.push_back(100);
	s.push_back(200);
	s.push_back(300);
	s.push_back(400);
	s.push_back(500);

	
	int i = 0;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;
	cout << s[i++] << endl;

	return 0;
}
