#include <iostream>
#include <vector>
#define vi vector<int>
#define all(c) c.begin(), c.end()
#define offset 'a'
#define charlen 26

using namespace std;

struct trnode {
	bool present{false};
	vector<trnode*> children{charlen,NULL};
};

void insert(trnode* tn, string& str, int idx){
	trnode* &tmp = tn->children[str[idx]-offset];
	if(!tmp)
		tmp=new trnode;
	if(idx == str.length()-1){
		if(!tmp->present) tmp->present=true;		
	}else
		insert(tmp,str,idx+1);
}

bool find(trnode* tn, string& str, int idx){
	trnode* &tmp = tn->children[str[idx]-offset];
	if(!tmp)
		return false;
	if(idx == str.length()-1){
		return tmp->present;		
	}else
		return find(tmp,str,idx+1);
}

int main() {
	string ss{"ajay"},st{"aj"};
	int idx=0;
	trnode trnd;
	insert(&trnd,ss,idx);	
	cout<<find(&trnd,st,idx)<<endl;
	return 0;
}

