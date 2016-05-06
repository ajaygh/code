#include <vector>
#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to
	 * STDOUT */ 
    string in;
    cin >>in;
    if(in.length()>1){
	        auto it= in.begin();
	        while(it <=in.end()-1){
						if((it> in.begin()) && (*it == *(it-1)))in.erase(it-1,it+1);
			            else if((it< in.end()-1) && (*it == *(it+1))){ 
		in.erase(it,it+2);
		if(it>in.begin())it--;
	}
			            else it++;
			        }
	    }
    if(in.length() == 0) cout<<"Empty String"<<endl;
    else cout <<in<<endl;
    return 0;
}
