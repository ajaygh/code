#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define vc vector<char>
#define vvc vector<vc>
#define all(x) x.begin(), x.end()

long total=0;
vector<string> vs;
void combinations(const vvc& data, int i, vc& res){
	total++;
	if(i == data.size()-1){
		if(res.size()>0)
			vs.push_back(string(all(res)));
			//cout <<string(res.begin(),res.end())<<endl;
		return;
	}else{
		for(auto& ch : data[i+1]){
			combinations(data,i+1, res);	
			res.push_back(ch);
			combinations(data,i+1, res);	
			res.pop_back();
		}
	}
}

int main() {
	//vvc data{{'a','c'},{'q','w','r'},{'x','d','m','g'}};
	//vvc data{{'a','c'},{'q','w','r'}};
	vvc data{{'a','c'},{'q','w'}};
	//vvc data{{'a','c'}};
	for(auto& ch : data[0]){
		vc res;
		combinations(data,0,res);	
		res.push_back(ch);
		combinations(data,0,res);	
	}
	//cout <<"total function calls "<<total<<endl;
	sort(all(vs));
	auto it = unique(all(vs));
	vs.resize(distance(vs.begin(),it));
	for(auto& str: vs)
		cout <<str<<endl;
	return 0;
}
