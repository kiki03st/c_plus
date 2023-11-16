#include <iostream>

using namespace std;

struct heap{
	int value;
	heap *left, *right;
};

heap* append(heap* node, int data){
	heap* p = new(heap);
	int size = 1;
	heap** arr = new heap*[size];
	arr[0] = node;
	while(true){
		for(

int main(){
	heap* head;
	head -> value = 16;
	return 0;
}
