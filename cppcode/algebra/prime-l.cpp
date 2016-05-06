
#include <iostream>
#include <vector> 

using namespace std;

int hcf(int a, int b){
	int rem = a%b;
	while(rem){
		a = b;		
		b = rem;
		rem = a%b;
	}
	return b;
}

int main() {
	int t;

	cin >>t;
	vector<long> inData;
	long tmp = 0;
	for(int i =0; i < t; i++){
		cin >>tmp;
		inData.push_back(tmp);
	}	
	for(auto&x : inData){
		int res = 0;
		for(long i = 1; i < x; i++){
			for(long j = i+1; j <= x; j++){
				int ih = i/hcf(j,i);
				int rh = (j-i)-ih*ih;
				int i2 = i*i;
				int t2 = (j*j*j - i2*i);
				if((j%i || (i == 1 && t2 <= x)) && !rh) res++;
			}
		}
		cout <<res<<endl;
	}
	inData.clear();
	return 0;
} 
