//find cycle in graph using dfs

#include <iostream>
#include <list>

using namespace std;

enum Color {WHITE, GREY, BLACK};

class Graph{
	public:
		Graph(int v):V(v), adj(new list<int>[V]){}
		inline void addEdje(int v1, int w);
		bool hasCycle();
		bool DFSUtil(int u, int color[]);
	private:
		int V;
		list<int> *adj;
};

void Graph:: addEdje(int v1, int v2){
	adj[v1].push_back(v2);
}

bool Graph:: DFSUtil(int u, int color[]){
	color[u] = GREY;
	for(list<int>::iterator it = adj[u].begin(); it != adj[u].end(); it++){
		if(color[*it] == GREY)
			return true;
		else if(color[*it] == WHITE && DFSUtil(*it, color))
			return true;
	}
	color[u] = BLACK;
	return false;
}

bool Graph::hasCycle(){
	int *color = new int[V];
	for(int i = 0; i < V; i++)
		color[i] = WHITE;
	for(int i = 0; i < V; i++){
		if(color[i] == WHITE && DFSUtil(i, color))
			return true;
	}
	return false;
}

int main() {
	Graph g(4);
	g.addEdje(0, 1);
	g.addEdje(0, 2);
	g.addEdje(1, 2);
	g.addEdje(2, 0);
	g.addEdje(2, 3);
	g.addEdje(3, 3);

	if(g.hasCycle())
		cout << "given graph has cycle\n";
	else
		cout << "given graph has not cycle\n";
	return 0;
} 
