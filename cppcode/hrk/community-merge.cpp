#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define all(c) c->begin(), c->end()
#define vsint 
using namespace std;

void merge(list<set<int>>& vsi, int a, int b){
	list<set<int> >::iterator	ita,itb;
	int both = 0;
	for(auto el= vsi.begin();el!=vsi.end();el++){
		if(el->find(a) != el->end() && el->find(b) != el->end())
			return;
		else if(el->find(a) != el->end() && el->find(b) == el->end()){
			ita= el;
			both++;
		}
		else if(el->find(a) == el->end() && el->find(b) != el->end()){
			itb= el;
			both++;
		}else if(both == 2) break;
	}
		for(auto ib : *itb)
			ita->insert(ib);
		vsi.erase(itb);
}

void printSize(list<set<int>>& vsi , int a){
	for(auto& el : vsi){
		if(el.find(a) != el.end()){
			cout<<el.size()<<endl;
			break;
		}
	}
}

int main() {
	int N, Q;
	cin>>N>>Q;
	list<set<int>> vsi(N);
	for(int i=0;i<N;i++){
		set<int> tmp{i+1};
		vsi.push_back(tmp);
	}

	char type;
	int a, b;
	for(int i=0;i<Q;i++){
		cin>>type;
		if(type == 'M'){
			cin>>a>>b;
			merge(vsi, a, b);
		}else{
			cin>>a;
			printSize(vsi, a);
		}
	}
	return 0;
} 
