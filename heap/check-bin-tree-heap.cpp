//Check whether given binary tree is heap or not.
//2conditions-1)all except last levels should be complete, 2)parent
//value should be greater than childrens.

#include <iostream>
using namespace std;

struct node{
	node(int _data): data(_data),left(NULL),right(NULL){}

	int data;
	node* left;
	node* right;
};

bool checkHeap (node *curr, node *parent){
	if(parent){
		if(curr->data < parent->data){
			if(curr->left && curr->right){
				checkHeap(curr->left,curr);
				checkHeap(curr->right,curr);
			}else if(!curr->left && !curr->right)
				return true;
			else
				return false;
		}else
			return false;
	}else{
		if(curr->left && curr->right){
			checkHeap(curr->left,curr);
			checkHeap(curr->right,curr);
		}else if(!curr->left && !curr->right)
			return true;
		else
			return false;
	}
}

int main() {
	node *root = new node(30);
	//root->left = new node(20);	
	//root->right = new node(25);
	
	cout << "binary tree is heap "<< checkHeap(root, NULL)<<endl;
	return 0;
} 
