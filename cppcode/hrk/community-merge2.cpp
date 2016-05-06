#include <iostream>
#include <algorithm>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define all(c) c.begin(), c.end()

using namespace std;
int find(vvi& gb, int val){
	if(!gb.empty()) {
		for(int i=0;i<gb.size();i++){
			int l = 0,h=gb[i].size()-1,m;
			while(l<=h){
				m = (l+h)/2;
				if(gb[i][m] == val)
					return i;
				else if(gb[i][m] < val)
					l=m+1;
				else
					h=m-1;
			}
		}
	}
	return -1;
}

int main() {
	int n,a,b,ia,ib,q;
	char qt;
	vvi gb;
	cin>>n;	
	for(int i=0;i<n;i++)
		gb.push_back(vi{i+1});
	cin>>q;	
	for(int i=0;i<q;i++){
		cin>>qt;
		if(qt == 'M'){
			cin>>a>>b;
			ia=find(gb,a);
			ib=find(gb,b);
			if(ia != ib){
				vi tmp(gb[ia].size()+gb[ib].size());
				set_union(gb[ia].begin(),gb[ia].end(),gb[ib].begin(),gb[ib].end(),tmp.begin());
				tmp.shrink_to_fit();
				gb[ia]=tmp;
				gb.erase(gb.begin()+ib);
				gb.shrink_to_fit();
			}
		}else if(qt == 'Q'){
			cin>>a;
			ia=find(gb,a);
			cout<<gb[ia].size()<<endl;
		}
	}
	return 0;
}

