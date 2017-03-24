#include <iostream>
#include <vector>
#define vi vector<int>
#define all(c) c.begin(), c.end()

using namespace std;

int calcConnectedCells(int i, int j, vector<vi>& grid, vector<vi>& visit){
	if(i < 0 || i >= grid.size()) return 0;
	if(j < 0 || j >= grid[0].size()) return 0;
	if(!grid[i][j] || visit[i][j]) return 0;
	visit[i][j] = 1;
	return 1+ calcConnectedCells(i-1,j,grid,visit)+calcConnectedCells(i+1,j,grid,visit)
	+ calcConnectedCells(i-1,j+1,grid,visit)+calcConnectedCells(i,j+1,grid,visit)+calcConnectedCells(i+1,j+1,grid,visit)
	+ calcConnectedCells(i-1,j-1,grid,visit)+calcConnectedCells(i,j-1,grid,visit)+calcConnectedCells(i+1,j-1,grid,visit);
}

int main() {
	int m,n; cin >>m >>n;
	vector<vi> grid(m,vi(n)),visit(m,vi(n,0));
	for(int i=0;i<m;i++){
		 for(int j = 0;j<n;j++)
		 cin >> grid[i][j];
	}	
	
	int maxr = 0;
	for(int i=0;i<m;i++){
		for(int j = 0;j<n;j++){
			int res = calcConnectedCells(i,j,grid, visit);
			if(maxr < res) maxr = res;
		}
	}
	cout <<maxr<<endl;
	return 0;
}

