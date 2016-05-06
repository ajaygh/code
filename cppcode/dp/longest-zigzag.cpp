
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> nums{5,3,4,8,6,7};
	vector<int> seq(nums.size(),1);	
	bool same=(nums[0]==nums[1])?true:false;
	bool next=(nums[0]<nums[1])?true:false;

	for(int i=1;i < seq.size();i++){
		for(int j=i-1;j>=0;j--){
			if(!same){
				if(next){
					if(nums[j] < nums[i]){
					   if(seq[j]+1 > seq[i]){
							seq[i] = seq[j] + 1;
							if(i != seq.size()-1){
								next=(nums[i]>nums[i+1])?true:false;
								same=(nums[i]==nums[i+1])?true:false;
							}
						}
					}else{
					 	seq[i] = seq[j];
					}
						break;
				}else{
					if(nums[j] > nums[i]){
					   if(seq[j]+1 > seq[i]){
							seq[i] = seq[j] + 1;
							if(i != seq.size()-1){
								next=(nums[i]<nums[i+1])?true:false;
								same=(nums[i]==nums[i+1])?true:false;
							}
						}
					}else{
					 	seq[i] = seq[j];
					}
						break;
				}	
			}else{
				seq[i] = seq[j];
				break;
			} 
		}
	}
	cout<<"max increasing sequence zigzag is "<<*max_element(seq.begin(), seq.end())<<endl;
	return 0;
}
