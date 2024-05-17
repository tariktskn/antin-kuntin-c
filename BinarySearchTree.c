#include <stdio.h>
#include <stdlib.h>

// balance islemlerini kendin yaz bakalim

struct NODE{
	int value;
	struct NODE* left;
	struct NODE* right;
};

struct NODE* createNode(int value);
struct NODE* insert(struct NODE* root, int value);
struct NODE* deleteNode(struct NODE* root, int value);
void printTree(struct NODE* root);

int main(){
	struct NODE* root = NULL;
	root = insert(root,7);
	insert(root,3);
	insert(root,10);
	insert(root,9);
	insert(root,11);
	insert(root,1);
	insert(root,5);
	insert(root,0);
	insert(root,2);
	insert(root,4);
	insert(root,6);
	
	
	deleteNode(root,3);
	printTree(root);
	return 0;
}

struct NODE* createNode(int value){
	struct NODE* newNode = (struct NODE*) malloc(sizeof(struct NODE));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

struct NODE* deleteNode(struct NODE* root, int value){
	if(root == NULL){
		return root;
	}
	
	if(root->value > value){
		root->left = deleteNode(root->left, value);
		return root;
	}else if(root->value < value){
		root->right = deleteNode(root->right, value);
		return root;
	}
	
	if(root->left == NULL){
		struct NODE* temp = root->right;
		free(root);
		return temp;
	}else if(root->right == NULL){
		struct NODE* temp = root->left;
		free(root);
		return temp;
	}
	
	struct NODE* succParent = root;
	struct NODE* succ = root->right;
	while(succ->left != NULL){
		succParent = succ;
		succ = succ->left;
	}
	
	if(succParent == root){
		succParent->right = succ->right;
	}else{
		succParent->left = succ->right;
	}
	
	root->value = succ->value;
	free(succ);
	return root;
}

struct NODE* insert(struct NODE* root, int value){
	if(root == NULL){
		return createNode(value);
	}
	
	if(root->value > value){
		root->left = insert(root->left, value);
	}else{
		root->right = insert(root->right, value);
	}
	
	return root;
}

void printTree(struct NODE* root){
	if(root == NULL){
		return;
	}
	
	printf("%d ", root->value);
	printTree(root->left);
	printTree(root->right);
}

