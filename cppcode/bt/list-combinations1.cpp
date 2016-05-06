
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define vc vector<char>
#define vvc vector<vc>
#define all(x) x.begin(), x.end()

long total=0;
void combinations(vvc& data, int i, vc& res){
	total++;
	if(i == data.size()-1){
		if(res.size()>0)
			cout <<string(res.begin(),res.end())<<endl;
		return;
	}else{
		char c='\0';
		data[i+1].push_back(c);
		for(auto& ch : data[i+1]){
			if(ch != '\0')
				res.push_back(ch);
			combinations(data,i+1, res);	
			if(ch != '\0')
				res.pop_back();
		}
	}
}

int main() {
	vvc data{{'a','c'},{'q','w','r'},{'x','d','m','g'}};
	//vvc data{{'a','c'},{'q','w','r'}};
	//vvc data{{'a','c'},{'q','w'}};
	//vvc data{{'a','c'}};
	
	data[0].push_back('\0');
	for(auto& ch : data[0]){
		vc res;
		if(ch != '\0')
			res.push_back(ch);
		combinations(data,0,res);	
	}
	//cout <<"total function calls "<<total<<endl;
	return 0;
}
