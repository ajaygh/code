#include <iostream>
#include <vector>
#include <set>
#include <limits.h>

#define vsi vector<set<int>>
#define all(c) c.begin(), c.end()

using namespace std;
int find(vsi& gb, int val){
	if(!gb.empty()) {
		for(int i=0;i<gb.size();i++){
			if (gb[i].find(val) != gb[i].end())
			   return i;	
		}
	}
	return -1;
}

int main() {
	int n,a,b,ia,ib,q;
	char qt;
	vsi gb;
	cin>>n;	
	for(int i=0;i<n;i++)
		gb.push_back(set<int>{i+1});
	cin>>q;	
	for(int i=0;i<q;i++){
		cin>>qt;
		if(qt == 'M'){
			cin>>a>>b;
			ia=find(gb,a);
			ib=find(gb,b);
			if(ia != ib){
				for(auto& el : gb[ib]){
					gb[ia].insert(el);
				}
				gb.erase(gb.begin()+ib);
			}
		}else if(qt == 'Q'){
			cin>>a;
			ia=find(gb,a);
			cout<<gb[ia].size()<<endl;
		}
	}
	return 0;
}

