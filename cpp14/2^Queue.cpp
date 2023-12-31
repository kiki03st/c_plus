#include <iostream>

using namespace std;

class my_queue{
	private:
		int size = 0;
		int *arr;
	public:
		void Enqueue(int data){
			int *backup = new int[size];
			for(int i = 0; i < size; i++) backup[i] = arr[i];
			arr = new int[++size];
			for(int i = 0; i < size - 1; i++) arr[i] = backup[i];
			arr[size - 1] = data;
			delete[] backup;
		}
		void Dequeue(){
			if(size == 0){
				cout << "Queue size is Zero." << endl;
				return;
			}
			int *backup = new int[size -1];
			for(int i = 0; i < size - 1; i++) backup[i] = arr[i + 1];
			arr = new int[--size];
			for(int i = 0; i < size; i++) arr[i] = backup[i];
			delete[] backup;
		}
		int Peek(){
			if(size == 0){
				cout << "Queue is NULL : ";
				return NULL;
			}
			return arr[0];
		}
};

int main(){
	my_queue q;

	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	cout << q.Peek() << endl;
	q.Dequeue();
	cout << q.Peek() << endl;
	q.Dequeue();
	cout << q.Peek() << endl;
	q.Dequeue();
	cout << q.Peek() << endl;
	return 0;
}
