//find hamiltonion cycle in a graph
// time complexity !n
//brute-force method- 
// while(next_conflagration){
//	if(next_conflagration) has a path a1, a2,,,an-1,an,a1
//		return true;
//	
// }
// return false
//
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main() {
	//represent graph as adjacency matrix
	int V;
	cin >> V;
	vector<vi> graph(V, vi(V,0));
	int m;
	cin >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		graph[a-1][b-1] = 1;
	}	
	bool res = hasHamiltonCycle(s, graph);
	cout << res << endl;
	return 0;
} 
