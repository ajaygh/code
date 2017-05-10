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
	int n,a,b,ia,ib;
	vsi gb;
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ia=find(gb,a);
		ib=find(gb,b);
		if(ia == -1 && ib == -1){
			gb.push_back(set<int>{a,b});
		}else if(ia == -1){
			gb[ib].insert(a);
		}else if(ib == -1){
			gb[ia].insert(b);
		}else if(ia != ib){
			for(auto& el : gb[ib]){
				gb[ia].insert(el);
			}
			gb.erase(gb.begin()+ib);
		}
	}
	//find min and max size
	int min = 2*n,max=1;
	for(auto& el : gb){
		if(el.size()<min) min = el.size();
		if(el.size()>max) max = el.size();
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}

