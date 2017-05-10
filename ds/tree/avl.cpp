#include <iostream>
using namespace std;

struct node{
	node(int data): key{data},ht{0}, left{nullptr}, right{nullptr}{}
	int key, ht;
	node *left, *right;
};

void balancebst(node * &root);
void leftrotate(node * &root);
void rightrotate(node * &root);

void updateHeight(node *root){
	if(root->left && root->right)
		root->ht = max(root->left->ht, root->right->ht)+1;
	else if(root->left)
		root->ht = root->left->ht + 1;
	else if(root->right)
		root->ht = root->right->ht + 1;
	else
		root->ht = 0;
}

int calcBF(node *root){
	int bf = 0;
	if(root->left && root->right)
		bf = root->right->ht - root->left->ht;
	else if(root->left)
		bf = -root->left->ht - 1;
	else if(root->right)
		bf = root->right->ht + 1;
	return bf;
}

void inorderTraversal(node *root){
	if(root){
		inorderTraversal(root->left);
		cout << root->key << "bf " << calcBF(root)<<endl;
		inorderTraversal(root->right);
	}
}

node* insertbst(node *root, int key){
	if(root){
		if(key < root->key){
			root->left = insertbst(root->left, key);
		}
		else if(key > root->key){	
			root->right = insertbst(root->right, key);
		}
		updateHeight(root);
		int bf = calcBF(root);
		//if tree rooted at root is unbalanced
		if(bf == -2 || bf == 2){
			balancebst(root);
		}
		return root;
	}
	else{
		return new node(key);
	}
}

void balancebst(node* &root){
	if(calcBF(root) == -2){
		if(calcBF(root->left) > 0){
			//left right case so first left rotate root->left
			leftrotate(root->left);
		}
		//left left case so right rotate at root
		rightrotate(root);
	}else{
		if(calcBF(root->right) < 0){
			//right left case
			rightrotate(root->right);
		}
		//right right case
		leftrotate(root);
	}
}

void leftrotate(node* &root){
	node * rootr = root->right;
	node * rootrl = rootr->left;
	rootr->left = root;
	root->right = rootrl;
	root = rootr;
	updateHeight(root->left);
	updateHeight(root);
}

void rightrotate(node* &root){
	node * rootl = root->left;
	node * rootlr = rootl->right;
	rootl->right = root;
	root->left = rootlr;
	root = rootl;
	updateHeight(root->right);
	updateHeight(root);
}

node* find(node *root, int k){
	if(root){
		if(root->key == k)
			return root;
		else if(k < root->key)
			return find(root->left, k);
		else if(k > root->key)
			return find(root->right, k);
	}
	else 
		return NULL;
}
void findDelete(node *root, int k){
	
}
int main() {
	node *root;
	int n,tmp;
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >>tmp;
		root = insertbst(root, tmp);
	}
	inorderTraversal(root);
	return 0;
} 
