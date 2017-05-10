#include <iostream>
#include <vector>	
#include <utility> 
using namespace std;

struct node{
	node(int _data, int i, int j):rank{0},pa{make_pair(i, j)}, data{_data}{
		if(data) size = 1;
		else size = 0;
	}
	int data;
	int size;
	int rank;
	pair<int,int> pa;
};

pair<int,int> findRep(vector<vector<node*>> &vvcell, node *nt){
	if(vvcell[nt->pa.first][nt->pa.second] != nt)
		nt->pa = findRep(vvcell, vvcell[nt->pa.first][nt->pa.second]);
	return nt->pa;
}

void merge(vector<vector<node*>> & vvcell, node *na, node *nb){
	pair<int,int> pa = findRep(vvcell, na);	
	pair<int,int> pb = findRep(vvcell, nb);	
	if((pa.first != pb.first) || (pa.second != pb.second)){
			if(vvcell[pa.first][pa.second]->rank< vvcell[pb.first][pb.second]->rank){
						vvcell[pa.first][pa.second]->pa = pb;
						vvcell[pb.first][pb.second]->size += vvcell[pa.first][pa.second]->size;
					}
			else{
						vvcell[pb.first][pb.second]->pa = pa;
						vvcell[pa.first][pa.second]->size += vvcell[pb.first][pb.second]->size;
					}
			if(vvcell[pa.first][pa.second]->rank== vvcell[pb.first][pb.second]->rank) 
				vvcell[pa.first][pa.second]->rank++;
		}
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<node*>> vvcell(m, vector<node*>(n));
	int tmp;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> tmp;
			vvcell[i][j] = new node(tmp, i, j);
		}
	}	
	//connect all regions
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(vvcell[i][j]->data){
				//check left
				if((i< m-1) && vvcell[i+1][j]->data)
					merge(vvcell, vvcell[i][j], vvcell[i+1][j]);
				else if((j < n-1) && vvcell[i][j+1]->data)
					merge(vvcell, vvcell[i][j], vvcell[i][j+1]);
				else if((i < m-1) && (j < n-1)&& vvcell[i+1][j+1]->data)
					merge(vvcell, vvcell[i][j], vvcell[i+1][j+1]);
			}
		}
	}
	int max = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(max < vvcell[i][j]->size)
				max = vvcell[i][j]->size;
		}
	}
	cout << max <<endl;
	return 0;
} 
