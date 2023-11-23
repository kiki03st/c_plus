#include <iostream>

using namespace std;

int size = 0;
int *heap;

void sort(int index){
	int i = index + 1;
	int prev = i / 2;
	int tmp;
	if(i == 1) return;
	else if(heap[i - 1] > heap[prev - 1]){
		tmp = heap[i - 1];
		heap[i - 1] = heap[prev - 1];
		heap[prev - 1] = tmp;
		sort(prev - 1);
	}
}

void append(int data){
	int* backup = new int[++size];
	for(int i = 0; i < size - 1; i++) backup[i] = heap[i];
	backup[size - 1] = data;
	heap = backup;
	delete[] backup;
	sort(size - 1);
}

int pow(int num){
	int sum = 1;
	for(int i = 0; i < num; i++) sum *= 2;
	return sum;
}

void print(){
	int cnt = 0, num = 0;
	for(int i = 0; i < size; i++){
		cout << heap[i] << " ";
		num++;
		if(num == pow(cnt)){
			cout << endl;
			cnt++;
			num = 0;
		}
	}
}

int main(){
	append(16);
	append(14);
	append(10);
	append(8);
	append(7);
	append(9);
	append(3);
	append(2);
	append(4);
	append(1);
	append(15);
	print();
	return 0;
}
