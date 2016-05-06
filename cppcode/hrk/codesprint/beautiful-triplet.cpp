#include <iostream>
#include <vector>
#define vi vector<int>
#define all(c) c.begin(), c.end()

using namespace std;

int main() {
	int n,d,t;
	cin>>n>>d;
	vi num(n);
	for(int i=0;i<n;i++){
		cin>>t;
		num[i] = t;
	}
	int trp = 0;
	if(n>2){
		for(int i=0;i<n-2;i++){
			bool br = false;
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(((num[j] - num[i]) == d)&& ((num[k] - num[j]) == d)){
						trp++;
						br = true;
						break;
					}
				}
				if(br) break;
			}
		}
	}
	cout<<trp<<endl;
	return 0;
}
