
#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
	array<int, 6> arr{11, 10, 8, 13, 15, 7};
	int k = 9;
	map<int, vector<int> > mapRemNum;
	int sum = 0;
	sum =  accumulate(all(arr), sum);
	cout <<"sum is "<<sum<<endl;
	if(sum % k)
		cout<<"pair doesn't exist.\n";
	else
		cout<<"pair exist.\n";

	for(auto&& x: arr){
		cout<<x<<endl;
		auto it = mapRemNum.find(x%k);
		if(it != mapRemNum.end()){
			it->second.push_back(x);		
		}else
		mapRemNum[x%k] = vector<int>{x};
	}
	bool res = false;
	auto map_beg = mapRemNum.begin();
    auto map_end = --mapRemNum.end();
	while(map_beg != map_end){
		auto pa = map_beg->second;
		auto pb = map_end->second;
		if((map_beg->first + map_end->first) %k)
			break;
		if(pa.size() == pb.size()){
			if(++map_beg == map_end){
				res = true;
				break;
			}
			else
				map_end--;
		}else
			break;
	}
	if(res)
		cout <<"pairs in array exist.\n";
	else
		cout <<"pairs in array doesn't exist.\n";
	return 0;
} 
