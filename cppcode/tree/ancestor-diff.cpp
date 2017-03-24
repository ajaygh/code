
#include <iostream>
#include <vector>

using namespace std;

struct node{
	node(int _data): data(_data){}
	int data;
	node *l, *r;
};

void calcTotalDiff(node *root, int diff, int &res, vector<int>& ances ){
	ances.push_back(root->data);
	if (root->l) calcTotalDiff(root->l, diff, res, ances);
	if (root->r) calcTotalDiff(root->r, diff, res, ances);

	ances.pop_back();
	for(auto el : ances){
		int tdiff = root->data-el;
		if(tdiff < 0) tdiff = -tdiff;
		if(tdiff < diff) res += tdiff;
	}
	cout << "current node is "<< root->data <<"res is " <<res<<endl;
}

int main() {
	int n;
	node *root = new node(10);
	node *rol = new node (8);
	node *ror = new node (15);
	node *roll = new node (25);
	node *rolr = new node (16);
	node *rorl = new node (60);
	node *rorr = new node (-10);
	
	root->l = rol;
	root->r = ror;
	rol->l = roll;
	rol->r = rolr;
	ror->l = rorl;
	ror->r = rorr;
	int diff = 10;
	int res = 0;
	vector<int> ancestor;
	calcTotalDiff(root, diff, res, ancestor);
	cout << "total diff is " << res << endl;
	return 0;
} 
