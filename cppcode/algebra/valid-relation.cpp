
#include <iostream>
#include <assert.h>

using namespace std;

int main() {
	int T;
	cin >>T;
	assert(T>=1 && T<=5);

	for(int i =0; i< T; i++){
		int N;
		cin >> N;
		bool res=true;

		assert((N >=2) && (N <= 100));
		int min =0, max = 500;
		int x, y;
		for(int j=0;j<N;j++){
			cin >>x >>y;
			if((x<min)||(x>max)||(y<min)||(y>max)){
				res =false;
				continue;
			}
		}
		if(res) cout<<"YES\n";
		else cout<<"NO\n";
	}	
	return 0;
} 
