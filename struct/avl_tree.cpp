#include <iostream>

using namespace std;

struct avl{
	int h, data;
	avl *left, *right, *parent;
};

avl *create(avl *parent, int data){
	avl *p = new avl;
	p -> parent = parent;
	p -> data = data;
	p -> left = NULL;
	p -> right = NULL;
	p -> h = parent -> h + 1;
	return p;
}

void sort(avl *t){
	int b = t -> left -> h - t -> right -> h;
	if(

void insert(avl *t, int data){
	avl *node = t;
	avl *save;
	while(node != NULL){
		if(data > node -> data){
			if(node -> right == NULL){
				node = node -> right = create(node, data);
				break;
			}
		}
		else{
			if(node -> left == NULL){
				node = node -> left = create(node, data);
				break;
			}
		}
	}
	sort(node);
}



int main(){
	avl *root, *leaf;
	root = new avl;
	root -> left = NULL;
	root -> right = NULL;
	root -> parent = NULL;
	root -> h = 1;

	return 0;
}
