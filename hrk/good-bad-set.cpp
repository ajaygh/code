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

int insert(trnode* tn, string& str, int idx){
	trnode* &tmp = tn->children[str[idx]-offset];
	if(!tmp)
		tmp=new trnode;
	if(tmp->present) return -1;		
	if(idx == str.length()-1){
		tmp->present=true;
		return 0;		
	}else
		return insert(tmp,str,idx+1);
}

int main() {
	string tmp;
	int idx=0,n,res;
	trnode trnd;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		res = insert(&trnd,tmp,idx);	
		if(res == -1)
			cout<<"BAD SET\n"<<tmp;
		else if(res == 0 && i == n-1)
			cout<<"GOOD SET\n";
	}
	return 0;
}

