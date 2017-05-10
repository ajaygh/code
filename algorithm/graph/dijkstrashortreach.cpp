#include <iostream>
#include <vector>
#include <limits.h> 
#include <utility>
#define vi vector<int>
using namespace std;

int findMinIdx(vi &dist, vector<bool> &visited);

class Graph{
	public:
		Graph(int v): V(v),edges{ new vector<pair<int, int>>[V]}{}
		void addEdge(int src, int dst, int w){
			edges[src].push_back(make_pair(dst, w));
			edges[dst].push_back(make_pair(src, w));
		}
		void bfsShortReach(int s);
	private:
		int V;
		vector<pair<int, int>> *edges;
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
			if(!visited[ad.first] &&(dist[min] != INT_MAX) && dist[min]+ ad.second < dist[ad.first])
				dist[ad.first] = dist[min] + ad.second;
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
			int src, dst, w;
			cin >> src >> dst >> w;
			gh->addEdge(src-1, dst-1, w);
		}
		int s;
		cin >> s;
		gh->bfsShortReach(s-1);
	}	
	return 0;
} 
