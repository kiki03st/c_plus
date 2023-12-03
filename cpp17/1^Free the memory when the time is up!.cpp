#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

template <typename T>
class timer_smartptr{
	private:
		T *ptr;
		thread t;
	public:
		void timer(int time){
			clock_t start = clock();
			while(((double)clock() - start) / CLOCKS_PER_SEC < time);
			delete this;
		}
		
		timer_smartptr(T *p = 0, int time = 10): ptr(p){
			t = thread(&timer_smartptr::timer, this, time);
		}
		~timer_smartptr(){}
		
		T& operator *(){ return *ptr; }
		T* operator ->(){ return ptr; }
		
		void join(){
			t.join();
		}
};

int main(){
	timer_smartptr<int> p1(new int, 3);

	p1.join();

	cout << "Wow!" << endl;

	return 0;
}
