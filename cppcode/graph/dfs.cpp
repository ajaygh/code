//depth first search

#include <iostream>
#include <vector>
#include <stack> 
using namespace std;

void dfsMatrix(vector<vector<int>>& edges, int i){
	vector<bool> visit(edges.size(), false);
	stack<int> vtxorder;
	vtxorder.push(i);
	while(!vtxorder.empty()){
		i = vtxorder.top();
		vtxorder.pop();
	
		//print only unvisited popped item
		if(!visit[i]){
			cout <<i<<' ';
			visit[i] = true;
		}
		//visit all children
		for(int k = 0; k < edges.size(); k++){
			if(edges[i][k]){
				if(visit[k]){
					cout <<"cycle found.\n";
					break;
				}else{
					vtxorder.push(k);
				}
			}
		}
	}
	cout<<endl;
}

int main() {
	int n; cin >> n;
	vector<vector<int>> edges(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j <n;j++)
			cin >> edges[i][j];
	}	
	//dfs using adj-matrix
	dfsMatrix(edges, 0);
	return 0;
} 
