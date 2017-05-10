
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >>T;
	
	string ins;
	vector<int>vres;
	for(int i =0;i < T;i++){
		cin >>ins;
		int len=ins.length();
		int total = len*(len+1)/2;

		for(int j=0;j<len-1;j++){
			for(int k=j;k<len-1;k++){
				if((ins[k]=='0'&& ins[k+1]=='0')||(ins[k]=='1'&& ins[k+1]=='1')){
				total -= ((len-1)-k);
				break;
				}
			}
		}
		vres.push_back(total);
	}
	for(auto& x:vres) cout <<x<<endl;
	return 0;
} 
