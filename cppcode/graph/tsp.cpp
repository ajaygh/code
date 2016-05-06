//find cycle in graph using dfs

#include <iostream>
#include <list>
#include <vector>
#include <limits.h> 
using namespace std;

struct Edge{
	Edge(const int& _dest, const int& _weight):dest(_dest), weight(_weight){}
	int dest, weight;
};

class Graph{
	public:
		Graph(int v):V(v), adj(new list<Edge>[V]){}
		inline void addEdje(int v1, int v2, int w);
		int mtp();
		int naiveUtil(int u, vector<int>& visited);
	private:
		int V;
		list<Edge> *adj;
};

void Graph:: addEdje(int v1, int v2, int weight){
	adj[v1].push_back(Edge(v2, weight));
	adj[v2].push_back(Edge(v1, weight));
}

int Graph:: naiveUtil(int u, vector<int>& visited){
	visited[u]=1;
	int min= INT_MAX;
	for(auto& x: adj[u]){
		if(!visited[x.dest]){
			int tmp = naiveUtil(x.dest,visited);
			min=(min>tmp + x.weight)?(tmp + x.weight):min;
		}
	}
	if(min == INT_MAX) min= 0;
	visited[u] = 0;
	return min;
}

int Graph::mtp(){
	int min, cmtp;
	min = INT_MAX;
	for(int i = 0; i < V; i++){
		vector<int> visited(V, 0);
		cmtp=naiveUtil(i,visited);
		if(min>cmtp)min = cmtp;
	}
	return min;
}

int main() {
	Graph g(4);
	g.addEdje(0, 1, 5);
	g.addEdje(0, 2, 12);
	g.addEdje(0, 3, 18);
	g.addEdje(1, 2, 1);
	g.addEdje(1, 3, 2);
	g.addEdje(2, 3, 7);

	cout<<"min tsp val "<<g.mtp()<<endl;
	return 0;
} 
