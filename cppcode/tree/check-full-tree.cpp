//Check whether all but last level is full or not

#include <iostream>
#include <queue>

#include "tree.h"

using namespace std;
struct tnode{
	tnode(const int& _data, const int& _actPos, const int& _expPos):
		data(_data), left(NULL), right(NULL), actPos(_actPos), expPos(_expPos){}
	int data;
	tnode *left, *right;
	int actPos, expPos;
};

bool bredthFirstTraversal(tnode* root){
	queue<tnode*> qTree;
	qTree.push(root);
	while(!qTree.empty()){
		tnode* curr = qTree.front();
			if(curr->left && curr->right){
				if(curr->actPos == curr->expPos){
					qTree.push(curr->left);
					qTree.push(curr->right);
					qTree.pop();

				}else{
					cout<<"failed at node value "<<curr->data<<endl;
					return false;
				} 
			}
			else if(curr->left && !curr->right){
				return false;
			}
			else if(!curr->left && curr->right){
				return false;
			}
			else if(!curr->left && !curr->right){
				if(curr->actPos == curr->expPos){
					qTree.pop();
				}else{
					cout<<"failed at node value "<<curr->data<<endl;
					return false;
				} 
			}
	}
	return true;
}

int main() {
	int actPos=1,expPos=1;
	tnode* root = new tnode(40, actPos, expPos);	
	actPos *= 2;
	root->left = new tnode(30, actPos, ++expPos);	
	root->right = new tnode(35, actPos+1, ++expPos);	
	actPos *= 2;
	root->left->left = new tnode(20, actPos, ++expPos);	
	root->left->right = new tnode(25, actPos+1, ++expPos);
	actPos *= 2;
	root->left->left->left = new tnode(10, actPos, ++expPos);	
	root->left->left->right = new tnode(15, actPos+1, ++expPos);
	
	if(bredthFirstTraversal(root))
		cout <<"given tree is full \n";
	else
		cout <<"given tree is not full \n";

	return 0;
} 
