#include <iostream>
#include <vector>
#include <limits.h> 

#define vi vector<int>
using namespace std;

int findMinIdx(vi &dist, vector<bool> &visited);

class Graph{
	public:
		Graph(int v): V(v),edges{ new vi[V]}{}
		void addEdge(int src, int dst){
			edges[src].push_back(dst);
			edges[dst].push_back(src);
		}
		void bfsShortReach(int s);
	private:
		int V;
		vi *edges;
};

void Graph::bfsShortReach(int s){
	vi dist(V, INT_MAX);
	vector<bool> visited(V, false);
	dist[s] = 0;
	int count = 0;
	while(count < V){
		int min = findMinIdx(dist, visited);
		visited[min] = true;
		count++;
		for(auto& ad : edges[min]){
			if(!visited[ad] &&(dist[min] != INT_MAX) && dist[min]+ 6 < dist[ad])
				dist[ad] = dist[min] + 6;
		}
	}
	for(auto & el : dist){
		if(el != 0){
			if(el == INT_MAX)
				cout << -1 <<' ';
			else
				cout << el << ' ';
		}
	}
	cout <<endl;
}

int findMinIdx(vi &dist, vector<bool> &visited){
	int min = INT_MAX, mi = 0;
	for(int idx = 0; idx < dist.size(); idx++){
		if(min >= dist[idx] && !visited[idx]){
			min = dist[idx];
			mi = idx;
		}
	}
	return mi;
}

int main() {
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int n, m;
		cin >> n >> m;
		Graph *gh = new Graph(n);
		for(int j = 0; j < m; j++){
			int src, dst;
			cin >> src >> dst;
			gh->addEdge(src-1, dst-1);
		}
		int s;
		cin >> s;
		gh->bfsShortReach(s-1);
	}	
	return 0;
} 
