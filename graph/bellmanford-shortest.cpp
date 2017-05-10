
#include <iostream>
#include <vector>
#include <list> 
#include <limits.h> 
#include <map>

using namespace std;

struct edje{
	edje(int _dst, int _val):dst(_dst),val(_val){}

	int dst;
	int val;
};

class Graph{
	public:
		Graph(int v):V(v), adj(new list<edje>[V]){}
		inline void addEdje(int v1, int v2, int val);
		bool hasCycle();
		bool DFSUtil(int u, int color[]);
//	private:
		int V;
		list<edje> *adj;
};

//for undirected graph
void Graph:: addEdje(int v1, int v2, int val){
	adj[v1].push_back(edje(v2, val));
}

int minElem(const vector<int>& dst, const vector<int>& sptSet){
	int idx = 0, minIdx = -1;
	int minVal = INT_MAX;
	while(idx < dst.size()){
		if(dst[idx] < minVal && !sptSet[idx] ){
			minIdx = idx;
			minVal = dst[idx];
		}
		idx++;
	}
	return minIdx;
}

void dijkstraShortestPath(const Graph& g, int src){
	vector<int> dst(g.V, INT_MAX);	
	vector<int> sptSet(g.V, 0);
	map<int, vector<int> > mapShtPath;

	dst[src] = 0;
	int visited = 1;
	while(visited <= g.V){
		int minIdx = minElem(dst, sptSet);
		sptSet[minIdx] = 1;
		if(mapShtPath.empty())
			mapShtPath[minIdx] = vector<int>{minIdx};
		else
			mapShtPath[minIdx].push_back(minIdx);
		for(auto& x: g.adj[minIdx]){
			if(!sptSet[x.dst] && (dst[x.dst] > dst[minIdx] + x.val)){
				dst[x.dst] = dst[minIdx] + x.val;
				mapShtPath[x.dst] = vector<int>(mapShtPath[minIdx]);
			}
		}		
		visited++;
	}	

	cout <<"shortest distance is \n";
	for(auto x: dst){
		cout <<x<<"\t";
	}
	cout <<endl;
	
	cout<<"print shortest path to vertices. \n";
	for(auto elem : mapShtPath){
		for(auto vecElem : elem.second)
			cout<<vecElem<<"\t";
		cout<<endl;
	}
}

int main() {
	
	Graph g(9);
	g.addEdje(0, 3,4);
	g.addEdje(0, 7,8);
	g.addEdje(1, 2, 8);
	g.addEdje(1, 7,11);
	g.addEdje(2, 8,2);
	g.addEdje(2, 5,4);
	g.addEdje(2, 3,7);
	g.addEdje(3, 4,9);
	g.addEdje(3, 5,14);
	g.addEdje(4, 5,10);
	g.addEdje(5,6,2);
	g.addEdje(6,8,6);
	g.addEdje(6,7,1);
	g.addEdje(7,8,7);

	dijkstraShortestPath(g, 0);
	return 0;
}

