#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
using namespace std;

int count_red(vector<vi> &adjv){
	vi color(adjv.size(),-1); // 0 - blue
	color[0] = 1; //red
	queue<int> qv;
	qv.push(0);
	while(!qv.empty()){
		int v = qv.front();
		qv.pop();
		for (auto& ad : adjv[v]){
			if(color[ad] == -1){
				color[ad] = 1 - color[v];
				qv.push(ad);
			}
			else if(color[v] == color[ad])
				return -1;
		}
	}
	
	int red = 0, blue;
	for(auto& cl : color){
		if(cl == 1) red++;
		else if(cl == 0) blue++;
	}
	return max(red, blue);
}

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n, m;
		cin >> n >> m;
		vector<vi> adjv(n);
		for(int j = 0; j < m; j++){
			int a, b;
			cin >> a >> b;
			adjv[a-1].push_back(b-1);
			adjv[b-1].push_back(a-1);
		}
		int red = count_red(adjv);
		if(red == -1)
			cout <<"NO"<<endl;
		else
			cout << red <<endl;
	}	
	return 0;
} 
