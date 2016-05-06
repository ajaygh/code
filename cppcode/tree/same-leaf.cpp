#include <iostream>
#include <stdio.h>
#include "tree.h"
#include <vector>

using namespace std; 

void getLeafInTree(tree* root, vector<int>& vecLeaves){
	if(root->left == NULL && root->right == NULL){
		vecLeaves.push_back(root->data);
		return ;
	}
	if(root->left){
		getLeafInTree(root->left, vecLeaves);
	}
	if(root->right){
		getLeafInTree(root->right, vecLeaves);
	}
}

void checkVec(vector<int>& vec1, vector<int>& vec2){
	if(vec1.size() == vec2.size()){
		vector<int>::iterator it1, it2;
		for(it1 = vec1.begin(), it2 = vec2.begin();it1 != vec1.end();it1++,it2++){
			if(*it1 == *it2) continue;
			else {
				cout <<"not match\n";
				return;
			}
		}
			cout <<"match\n";
	}else{ cout <<"vectors not same size.\n";}
}
int main(){
	//first tree
	tree* root = new tree(5);
	tree* node1 = new tree(3);
	tree* node2 = new tree(4);
	tree* node3 = new tree(8);
	tree* node4 = new tree(7);
	root->left = node1;
	root->right = node3;
	node1->right = node2;
	node3->left = node4;
	//second tree
	tree* root2 = new tree(6);
	tree* node21 = new tree(4);
	tree* node22 = new tree(7);
	root2->left = node21;
	root2->right = node22;

	inorderTraversal(root);
	cout <<endl;
	inorderTraversal(root2);
	cout <<endl;
	//print leaves in tree
	vector<int> leaves1, leaves2;
	getLeafInTree(root,leaves1);
	for(auto leaf : leaves1){
		cout <<leaf<<endl;
	}
	getLeafInTree(root,leaves2);
	for(auto leaf : leaves2){
		cout <<leaf<<endl;
	}
	//check whether 2 vetors are same or not
	checkVec(leaves1, leaves2);
	return 0;
} 
