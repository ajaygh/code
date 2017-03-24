#include <iostream>
#include <vector> 
using namespace std;

struct node{
	node(int _data): data{_data}, rank{0}, rep{_data}, size{1}{}
	int data, rank, rep, size;
};

int findRep(vector<node*>& edges, node* nd){
	if(nd->rep != nd->data)
		nd->rep = findRep(edges, edges[nd->rep]);
	return nd->rep;
}

void merge(vector<node*>& edges, node* na, node* nb){
	int pa = findRep(edges, na);
	int pb = findRep(edges, nb);
	if(pa != pb){
		if(edges[pa]->rank < edges[pb]->rank){
			edges[pa]->rep = pb;
			edges[pb]->size += edges[pa]->size;
		}else{
			edges[pb]->rep = pa;
			edges[pa]->size += edges[pa]->size;
		}
		if(edges[pa]->rank == edges[pb]->rank) edges[pa]->rank++;
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	int len = max(m, n);
	vector<node*> edges(len);
	int temp;
	for(int i = 0; i < m; i++){
		for(int j = 0;j < n; j++){
			cin >> temp;
			edges[]
			if(temp)
				merge
		}
	}
	return 0;
} 
