#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>

struct tree{
	tree(int _data):left(NULL),right(NULL),data(_data){}
	tree *left, *right;
	int data;
};

void inorderTraversal(tree* root){
	if(root){
		if(root->left)  inorderTraversal(root->left);
		printf("%d\t", root->data);
		if(root->right)  inorderTraversal(root->right);
	}
}

#endif
