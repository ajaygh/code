
#include <iostream>
#include "tree.h"
#include <map>

using namespace std;

map<int, int> vsum;
void verticalSum(tree* root, int vlevel){
	if(root->left){
		verticalSum(root->left, vlevel-1);
	}
	if(root->right)
	verticalSum(root->right, vlevel+1);

	if(vsum.find(vlevel) == vsum.end())
		vsum[vlevel] = root->data;
	else
		vsum[vlevel] += root->data;
}

int main() {
	tree *root = new tree(10);
	root->left = new tree(5);	
	root->right = new tree(12);
	root->left->left = new tree(2);	
	root->left->right = new tree(6);	
	root->right->left = new tree(11);
	root->right->right = new tree(13);
	
	int rootlevel = 0;
	verticalSum(root, rootlevel);
	for(auto& levelsum : vsum)
		cout<<"level "<< levelsum.first<<"sum "<<levelsum.second<<endl;
	return 0;
}
