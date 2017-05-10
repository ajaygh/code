#include <iostream>
#include <vector>
#define vi vector<int>
#define all(c) c.begin(), c.end()
#define offset 'a'
#define charlen 26

using namespace std;

struct trnode {
	bool present{false};
	int count{1};
	vector<trnode*> children{charlen,NULL};
};

void insert(trnode* tn, string& str, int idx){
	trnode* &tmp = tn->children[str[idx]-offset];
	if(!tmp)
		tmp=new trnode;
	else
		tmp->count++;
	if(idx == str.length()-1){
		if(!tmp->present) tmp->present=true;		
	}else
		insert(tmp,str,idx+1);
}

int find(trnode* tn, string& str, int idx){
	trnode* &tmp = tn->children[str[idx]-offset];
	if(!tmp)
		return 0;
	if(idx == str.length()-1){
		return tmp->count;		
	}else
		return find(tmp,str,idx+1);
}

int main() {
	string tmp,type;
	int idx=0,n;
	trnode trnd;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>type>>tmp;
	if(type == "add"){
		insert(&trnd,tmp,idx);
	}else
		cout<<find(&trnd,tmp,idx)<<endl;
	}
	return 0;
}

