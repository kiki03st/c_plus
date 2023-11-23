#include <iostream>

using namespace std;

template <typename T>
class my_queue{
	private:
		int size = 0;
		T *arr;
	public:
		void Enqueue(T data){
			T *backup = new T[size];
			for(int i = 0; i < size; i++) backup[i] = arr[i];
			arr = new T[++size];
			for(int i = 0; i < size - 1; i++) arr[i] = backup[i];
			arr[size - 1] = data;
			delete[] backup;
		}
		void Dequeue(){
			if(size == 0){
				cout << "Queue size is Zero." << endl;
				return;
			}
			T *backup = new T[size -1];
			for(int i = 0; i < size - 1; i++) backup[i] = arr[i + 1];
			arr = new T[--size];
			for(int i = 0; i < size; i++) arr[i] = backup[i];
			delete[] backup;
		}
		T Peek(){
			if(size == 0){
				cout << "Queue is NULL : ";
				return NULL;
			}
			return arr[0];
		}
};

int main(){
	my_queue<int> q;

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
