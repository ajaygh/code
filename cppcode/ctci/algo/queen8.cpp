#include <iostream>
#include <vector>
#define vi vector<int>

using namespace std;
const int N = 8;

bool checkPrev(vector<vi>& cbord, int row, int col){
	//check row
	for(int cl = 0; cl < N, cl != col; cl++)
		if(cbord[row][cl] == cbord[row][col])
			return false;
	//check column
	for(int rw = 0; rw < N, rw != row; rw++)
		if(cbord[rw][col] == cbord[row][col])
			return false;
	//check diagonal
	int i = row-1, j = col-1;
	while(i >= 0 && j >= 0){
		if(cbord[i][j] == cbord[row][col])
			return false;
		else{
			i--;
			j--;
		}
	}
	i = row+1, j = col+1;
	while(i < N && j < N){
		if(cbord[i][j] == cbord[row][col])
			return false;
		else{
			i++;
			j++;
		}
	}
	i = row+1, j = col-1;
	while(i < N && j >= 0){
		if(cbord[i][j] == cbord[row][col])
			return false;
		else{
			i++;
			j--;
		}
	}
	i = row-1, j = col+1;
	while(i >= 0 && j < N){
		if(cbord[i][j] == cbord[row][col])
			return false;
		else{
			i--;
			j++;
		}
	}
 
}

void placeQueen(vector<vi>& cbord, int row){
	//check row, column and diagonal
	for(int col = 0; col < N; col++){
		cbord[row][col] = 1;
		if(!checkPrev(cbord, row, col))
			cbord[row][col] = 0;
	}
	if(row < N-1)
		placeQueen(cbord, row+1);
}

int main() {
	vector<vi> cbord(N, vi(N,0));
	//if true print solution	
	placeQueen(cbord, 0);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(cbord[i][j])
				cout <<i+1<<' '<<j+1<<endl;
		}
	}
	return 0;
} 
