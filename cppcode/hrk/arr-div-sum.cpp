#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int score(const vector<int>& vn, const int& st, const int& en){
    if(st == en) return 0;
    	
    int m = (st+en)/2;
    int ls,rs;
    ls = rs =0;
    for(int i =st; i<=m; i++) ls += vn[i];
    for(int i =m+1; i<=en; i++) rs += vn[i];
    if(ls == rs){
	        return max(score(vn, st, m), score(vn, m+1, en))+1;
	    }else if(ls <rs){
		        while(ls <rs && m < en-1){
				            m++;
							ls += vn[m];
				            rs -= vn[m];
						    	
				            if(ls == rs){
				            	return max(score(vn, st, m), score(vn, m+1, en))+1;
							}
				}
    }else{
	        while(ls >rs && m > st){
			            ls -= vn[m];
			            rs += vn[m]; 
			            m--;
			            if(ls == rs){ 
			            	return max(score(vn, st, m), score(vn, m+1, en))+1;
						}
			        }
	    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to
	 * STDOUT */ 
    int T;
    cin >>T;
    for(int i =0;i<T;i++){
	        int N;
	        cin >>N;
	        vector<int> vn;
	        int t;
	        for(int j=0;j<N;j++){
			            cin >>t;
			            vn.push_back(t);
			        }
	        cout<<score(vn, 0, N-1)<<endl;   
	    }
    return 0;
}
