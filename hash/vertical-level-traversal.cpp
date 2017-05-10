#include <iostream>
#include <unordered_map> 
#include <vector>

using namespace std;

struct node{
	node(int _val): val{_val}{}
	int val;
	node *left{NULL}, *right{NULL};
};

void verticalTraversal(unordered_map<int, vector<int>> &mlevel, int level, node *root){
	if(root){
		if(mlevel.find(level) == mlevel.end()){
			mlevel[level] = vector<int>();
			mlevel[level].push_back(root->val);
		}else
			mlevel[level].push_back(root->val);
		verticalTraversal(mlevel, level-1, root->left);		
		verticalTraversal(mlevel, level+1, root->right);		
	}
}

int main() {
	unordered_map<int, vector<int>> mlevel;
	int level = 0;

	node* root = new node(0);
	node* rl = new node(1);
	node* rr = new node(2);
	node* rll = new node(3);
	node* rlr = new node(4);
	node* rrl = new node(5);
	node* rrr = new node(6);
	verticalTraversal(mlevel, 0, root);

	for(auto& el : mlevel){
		for(auto& val: el.second)
			cout<<val<<' ';
		cout<<endl;
	}
	return 0;
}

