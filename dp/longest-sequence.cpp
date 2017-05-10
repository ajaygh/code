
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> nums{5,3,4,8,6,7};
	vector<int> seq(nums.size(),1);	
	for(int i=1;i < seq.size();i++){
		for(int j=i-1;j>=0;j--){
			if(nums[i]>=nums[j] && seq[j]+1 > seq[i]){
				seq[i]=seq[j]+1;
				break;
			}
		}
	}
	cout<<"max increasing sequence is "<<*max_element(seq.begin(), seq.end())<<endl;
	return 0;
}
