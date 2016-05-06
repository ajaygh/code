#include <iostream>
#include <vector>
#include <map>

#define vi vector<int>
#define all(c) c.begin(), c.end()
#define mvi map<int, vi>
using namespace std;

void findRoute(mvi::iterator it, int &total){
	
}

int main() {
	mvi mdata;
	int n,tmp,total=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		if(mdata.find(tmp) == mdata.end())
			mdata[tmp]=vi{i};
		else
			mdata[tmp].push_back(i);
	}
	findRoute(mdata.rbegin(),total);
	return 0;
}

