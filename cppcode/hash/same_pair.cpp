#include <iostream>
#include <unordered_map> 

using namespace std;

int main() {
	unordered_map<int, int> mdata;
	for(auto& el : {1,1,2,1, 2,2,2}){
		if(mdata.find(el) == mdata.end())
			mdata[el] = 1;
		else
			mdata[el]++;
	}
	int total = 0;
	for(auto& mel : mdata){
		if(mel.second > 1 )
			total += (mel.second)*(mel.second-1)/2;
	}
	cout <<total<<endl;
	return 0;
} 
