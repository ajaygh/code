
#include <iostream>

using namespace std;
int func(){
	int c=0;
	return c++;
}
int main() {
//	cout<<"0 is "<<(0==0)<<endl;	
	//cout<<func()<<endl;
	cout<<!(1&&0 || 1&&1)<<endl;
	int c=0;
	cout<<c++<<c<<endl;
	return 0;
} 
