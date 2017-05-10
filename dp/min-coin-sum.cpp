
#include <iostream>
#include <vector>
#include <limits.h> 

using namespace std;

int main() {
	vector<int> coins{1,3,5};
	int sum=11;
	vector<int> min(sum+1,INT_MAX);
	min[0] = 0;
	for(int i=1; i <=sum;i++){
		for(auto& coin : coins){
			if(coin <= i && min[i-coin] + 1 < min[i])
				min[i] = min[i-coin] + 1;	
		}
	}	
	cout <<min[sum]<<endl;
	return 0;
}
