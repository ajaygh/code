#include <iostream>
#include <vector>
#define vi vector<int>

using namespace std;

int main() {
	int n,tmp;
	cin >>n;
	vi vcloud(n);
	for(int i=0;i<n;i++){
		cin>>tmp;
		vcloud[i]=tmp;
	}	
	int jump=0,s1=1,s2=2;
	int i=0;
	while(i< n){
		if((i+s2)< n&&!vcloud[i+s2]){
			i += s2;
			jump++;
	}else if(i+s1<n&&!vcloud[i+s1]){
			i += s1;
			jump++;
	}else if(i == n-1)break;
	}
	cout<<jump<<endl;
	return 0;
}
