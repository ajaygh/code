
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	list<int> lsi;
	int n,k;
	cin >>n>>k;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		lsi.push_back(tmp);
	}
	lsi.sort();
	
	if(lsi.size() == 1){
		if(lsi.front() >= k)
			cout<<0<<endl;
		else
			cout<<(-1)<<endl;
		return 0;
	}else{
		int sweet=0,step=0,idx=0;
		if(lsi.front() >= k)
			cout<<step<<endl;
		else{
			sweet += lsi.front();
			lsi.pop_front();
			sweet += 2*lsi.front();
			lsi.pop_front();
			step++;
			if(lsi.empty()){
				if(sweet>=k)
					cout<<step<<endl;
				else
					cout<<-1<<endl;
				return 0;
			}else{
				if((lsi.front() >= k) && sweet >= k){
					cout<<step<<endl;
					return 0;
				}
				while(!lsi.empty() && (lsi.front() < k || sweet < k)){
					if(sweet> lsi.front()){
						auto it = lsi.begin();
						for(;*it < sweet;it++){}
						lsi.insert(it, sweet);
						sweet = 0;
						sweet += lsi.front();
						lsi.pop_front();
						sweet += 2*lsi.front();
						lsi.pop_front();
						step++;
					}else{
						sweet += 2*lsi.front();
						lsi.pop_front();
						step++;
					}
				}
				auto it = lsi.begin();
				for(;*it < sweet;it++){}
				lsi.insert(it, sweet);
				if(lsi.front() < k)
					cout<<-1<<endl;
				else
					cout<<step<<endl;
			}
		}
	}
	return 0;
}
