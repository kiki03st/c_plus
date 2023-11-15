#include <iostream>

using namespace std;

template <typename T>
struct heap{
	T value;
	heap<T> *left, *right;
};


template <typename T>
heap<T>* append(heap<T>* node, T data){
	heap<T>** arr;
	int cnt = 0;
	while(true){
		if(node -> left == NULL){
			node -> left = new(heap<T>);
			node -> left -> value = data;
			node -> left -> left = NULL;
			node -> left -> right = NULL;
			return 
		else if(node -> right == NULL

int main(){
	heap<int> *head;
	
	return 0;
}
