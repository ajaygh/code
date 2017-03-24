#include <iostream>
#include <vector>

using namespace std;
struct node{
	node(int _l, int _r):val{0}, left{NULL}, right{NULL}, l{_l}, r{_r}{}
	unsigned long val;
	node *left, *right;
	int l, r;
};

node* buildSegmentTree(int l, int r){
	node *nd = new node(l, r);
	if(l < r){
		int mid = (l+r)/2;
		nd->left = buildSegmentTree(l, mid);
		nd->right = buildSegmentTree(mid+1, r);
	}
	return nd;
}

void updateSegmentTree(node *nd, int a, int b, int val){
	if(a == nd->l && b == nd->r){
		nd->val += val;
	}else if(a >= nd->l && b <= (nd->l+nd->r)/2)
		updateSegmentTree(nd->left, a, b, val);
	else if(a > (nd->l+nd->r)/2 && b <= nd->r)
		updateSegmentTree(nd->right, a, b, val);
	else{
		updateSegmentTree(nd->left, a, (nd->l+nd->r)/2, val);
		updateSegmentTree(nd->right, (nd->l+nd->r)/2+1,  b, val);
	}
}

void findMax(node* root, unsigned long par, unsigned long &max){
	par += root->val;
	if(root->left)
		findMax(root->left, par, max);
	if(root->right)
		findMax(root->right, par, max);
	if(!root->left && !root->right && max < par)
		max = par;
}

int main() {
	int n, m;
	cin >> n >> m;
	node *root = buildSegmentTree(1, n);
	int a, b, tmp;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> tmp;
		updateSegmentTree(root, a, b, tmp);
	}
	
	unsigned long par =0, max= 0;
    findMax(root,par, max);
	cout << max << endl;
	return 0;
} 
