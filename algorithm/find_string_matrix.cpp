#include <iostream>
#include <vector>
#include <string>
#include <utility>

#define vc vector<char>
#define vvc vector<vc>

using namespace std;

vector<pair<int, int>> dir = {{-1, -1},{-1, 0}, {-1, 1}, {0, -1},{0,1},{1,-1}, {1,0},{1,1}};

bool findStringInMatrix(vvc &cmat, string &str, int row, int col ){
	//find current pos with row and col
	if(cmat[row][col] != str[0])
		return false;

	//search in all directions and proceed in matched direction
	for(int d = 0;d < 8; d++){
		int r = row+dir[d].first, c = col+dir[d].second;
		//check for 1 to end characters
		int i = 1;
		for(; i < str.length(); i++){
			//check boundary
			if(r < 0 || r >= cmat.size() || c < 0 || c >= cmat[0].size())
				break;
			if(cmat[r][c] !=  str[i])
				break;
			//move in the matched direction
			r += dir[d].first;
			c += dir[d].second;
		}
		if(i == str.length())
			return true;
	}
	return false;
}

int main() {
	string str;
	cin >> str;
	
	int height, width;
	cin >> height >> width;
	vvc cmat(height, vector<char>(width));
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++)
			cin >> cmat[i][j];
	}
	//vc result(height*width);
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			bool found = findStringInMatrix(cmat, str, i, j);
			if(found)
				cout << str << " found in matrix at row "<< i<<" column "<< j<< endl;
			else
				cout <<"not found in given matrix\n";
		}
	}
	return 0;
} 
