
#include <iostream>
#include <map> 
#include <string>
#include <vector>

using namespace std;

int main() {
	int N,Q;
	vector<string> vsq;
	map<string,int> msi;
	cin>>N;
	string tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		if(msi.find(tmp) == msi.end())
			msi[tmp]=1;
		else
			msi[tmp]++;
	}
	cin >>Q;
	for(int i=0;i<Q;i++){
		cin>>tmp;
		vsq.push_back(tmp);
	}
	for(auto& str : vsq){
		if(msi.find(str) == msi.end())
			cout<<0<<endl;
		else
			cout<<msi[str]<<endl;
	}
	return 0;
}
