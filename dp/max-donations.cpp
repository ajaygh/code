
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> nums{5,3,4,8,6,7};
	vector<int> seq(nums);	
	seq[1] = max(seq[0], seq[1]);
	if(nums.size() > 2){
		for(int i=2;i < seq.size();i++){
					seq[i]=max(seq[i-2]+seq[i],seq[i-1]);
		}
	}
	cout<<"max increasing sequence is "<<*max_element(seq.begin(), seq.end())<<endl;
	return 0;
}
