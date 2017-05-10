
#include <iostream>
#include <vector> 
using namespace std;

int main() {
	vector<vector<int> > vvi;
	int N,Q;
	cin>>N>>Q;
	vvi.resize(N);
	int type,x,y,lastAns=0,seq;
	for(int i=0;i<Q;i++){
		cin>>type>>x>>y;
		if(type == 1){
			seq = (x^lastAns)%N;
			vvi[seq].push_back(y);
		}else{
			seq = (x^lastAns)%N;
			lastAns = vvi[seq][y%vvi[seq].size()];
			cout<<lastAns<<endl;
		}
	}
	return 0;
}
