#include <vector>
#include <iostream>
#include <set>
#include <math.h> 
using namespace std;


int main() {
    int n,s,p,q;
    set<int> si;
    cin >>n>>s>>p>>q;
    int pr=(s<<2)/4;
	cout<<"sizeof long "<<sizeof(long)<<"sizeof int "<<sizeof(int)<<endl;    
    union{
        long tmp;
        int cu[2];
    };
    si.insert(pr);
    for(int i=1;i<n;i++){
        tmp = pr*p;
		if(cu[0] == 0 && pr == q)
			break;
		tmp += q;
        pr = (cu[0]<<2)/4;
        si.insert(pr);
     }
     cout<<si.size()<<endl;
     return 0;
}
