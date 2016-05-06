
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRectangle(const vector<int>& vh){
	long maxt =0;
	for(int i=0;i<vh.size();i++){
		int lmax=0, ht = vh[i],count=1;
		long maxr = 0;
		for(int j=i+1;j<vh.size();j++){
			if(vh[j] < ht){
				maxr = max(maxr,ht*count);
				ht = vh[j];
				count++;
			}else
				count++;
		}
		maxr = max(maxr,ht*count);
		maxt = max(maxt,maxr);
	}
	return maxt;
}

int main() {
	int n;
	cin >>n;
	int elm;
	vector<int> vh;
	for(int i=0;i<n;i++){
		cin>>elm;
		vh.push_back(elm);		
	}
	cout<<maxRectangle(vh)<<endl;
	return 0;
} 
