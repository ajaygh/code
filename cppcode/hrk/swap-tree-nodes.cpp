#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct node{
    node(int _data):data(_data),left(NULL),right(NULL){}
    int data;
    node* left;
    node* right;
}*root;
void inorder(node* root){
    if(root){
	        inorder(root->left);
	        cout <<root->data<<" ";
	        inorder(root->right);
	    }
}

void insert(node* cn, int l, int r, queue<node*>& nq){
    if(l != (-1)){
	        cn->left= new node(l);
	        nq.push(cn->left);
	    }
    if(r != (-1)){
	        cn->right= new node(r);
	        nq.push(cn->right);
	    }
}

void swap(node* curr, int k, int d){
    if(curr){
		if(d == k && (curr->left || curr->right)) {
			if(curr->left)	swap(curr->left, 2*k, d+1);
			if(curr->right) swap(curr->right, 2*k, d+1);
			node* tmp = curr->left;
			curr->left = curr->right;
			curr->right = tmp;
	    }else if(d<k){
			swap(curr->left, k, d+1);
			swap(curr->right, k, d+1);
		}
	}
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to
	 * STDOUT */  
    root = new node(1);
    queue<node*> nq;
    nq.push(root);
    int n;
    cin >>n;
    int l,r;
    node* tmp;
    for(int i=0;i<n;i++){
	        cin>>l>>r;
	        tmp = nq.front();
	        nq.pop();
	        insert(tmp, l, r, nq);
	    }
    int t;
    cin >>t;
    int k;
    for(int j=0;j<t;j++){
	        cin >>k;
	        swap(root,k,1);
			inorder(root);
			cout<<endl;
	    }
    return 0;
}

