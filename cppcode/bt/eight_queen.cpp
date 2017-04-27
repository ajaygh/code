//8 queen placement on chess-board so that none attacks other
//solution using backtracking
//extend the solution to n*n board

#include <iostream>
#include <vector>
#define vb vector<bool>
#define vvb vector<vb>
#define n 8

using namespace std;

bool validPlace(vvb &cb, int r, int c){
	cb[r][c] = true;
	//check row
	for(int i = 0; i < n, i != c; i++){
		if(cb[r][i]){
			cb[r][c] = false;
			return false;
		}
	}
	//check column
	for(int i = 0; i < n, i != r; i++){
		if(cb[i][c]){
			cb[r][c] = false;
			return false;
		}
	}
	//check diagonal
	for(int i = 0; i < n; i++){
		if(r-i >= 0 && c-i >= 0 && cb[r-i][c-i]){
			cb[r][c] = false;
			return false;
		}
		if(r+i >= 0 && c+i >= 0 && cb[r+i][c+i]){
			cb[r][c] = false;
			return false;
		}
		if(r-i >= 0 && c+i >= 0 && cb[r-i][c+i]){
			cb[r][c] = false;
			return false;
		}
		if(r+i >= 0 && c-i >= 0 && cb[r+i][c-i]){
			cb[r][c] = false;
			return false;
		}
	}
	return true;
}
void placeQueen(vvb &cb, int row){
	if(row == n)
		return;
	for(int i = 0; i < n; i++){
		if(validPlace(cb, row, i)){
			placeQueen(cb, row++);
			return;
		}
	}
}

void displayBoard(vvb &cb){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<cb[i][j]<<' ';
		}
		cout <<endl;
	}
}
int main() {
	vvb cb(n, vb(n, false));
	displayBoard(cb);
	placeQueen(cb, 0);
	cout <<"8 queen on board are as follows.\n";
	displayBoard(cb);
	return 0;
} 
