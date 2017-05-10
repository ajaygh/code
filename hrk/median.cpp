#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h> 
#define vi vector<int>
#define all(c) c.begin(), c.end()

using namespace std;

int main() {
	int n,tmp;
	float med;
	cin>>n;
	//cout<<setprecision(2);

	if(n==1){
		cin>>tmp;
		med=tmp;
		printf("%.1f\n",med);
	}else{
		vi vdata;
		cin>>tmp;
		med=tmp;
		printf("%.1f\n",med);
		vdata.push_back(tmp);
		int i1,i2;
		for(int i=1;i<n;i++){
			cin>>tmp;
			vdata.push_back(tmp);
			if(!(vdata.size()%2)){
				i2 = vdata.size()/2;
				i1 = i2-1;
				med = (vdata[i1]+vdata[i2])/2.0;
				printf("%.1f\n",med);
				//cout<<(med)f<<endl;
			}else{
				med=vdata[vdata.size()/2];
				printf("%.1f\n",med);
				//cout<<(vdata[vdata.size()/2])f<<endl;
			}
		}	
	}	
	return 0;
}
