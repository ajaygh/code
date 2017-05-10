#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to
	 * STDOUT */ 
    int n,m;
    int mod=1000000007;
    cin >>n>>m;
    if(n < m){
	        n = n+m;
	        m = n-m;
	        n = n-m;
	}
	   vector<long> fact(m);
	       fact[0]=1;
		       for(int i=1;i<m;i++) fact[i]=(fact[i-1]*(i+1))%mod;
			       long long total=0;
				       for(int j=0;j<m-1;j++) total += fact[j];
					       total *= 2;
						       total -=2;
							       total += (n+1-m)*fact[m-1];
								       total %= mod;
									       cout << total<<endl;
										       return 0;
}

