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
		my_list& push_back(const int d){
			if(!start){
				head = new node(d, index++);
				head -> next = NULL;
				start = head;
			}
			else{
				node *p = new node(d, index++);
				head = head -> next = p;
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
			else return current -> data;
		}
		void info(){
			cout << "length: " << index << ", current: " << current -> index << endl;
		}
};

int main(){
	// 저번 클래스 2 과제에서 이미 구현했어서 append 함수 이름을 push_back으로 바꿔서 제출합니다...
	my_list l;

	l.push_back(10).push_back(20).push_back(30).push_back(40);


	l.next().next();

	cout << l.get() << endl;



	l.info();

	l.rewind();

	cout << l.get() << endl;

	return 0;

}
