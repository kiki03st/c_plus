#include <iostream>

using namespace std;

struct Tree{
	int parentID;
	char key;
	struct Tree *left, *right;
};

struct Tree node;

struct Tree* root(char key){
	if(node == NULL){
		node = (Tree*)malloc(sizeof(node));
		node -> right = node -> left = NULL;
		node -> key = key;
		return node;
	}
	else{
		if(parentID < node ->

void root(char key){
	while

int main(){
	
	return 0;
}
