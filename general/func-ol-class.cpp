
#include <iostream>
using namespace std;

class base{
	public:
	virtual	double f(int param){
			cout <<"f(int) ";
			return param + 4;
		}
};

class derived : base{
	public:
		double f(double param){
			cout <<"f(double) ";
			return param+ 5;
		}
};


int main() {
	base* bs = new base();
	derived* dr = new derived();
	cout<<dr->f(4)<<endl;//overloading not possible across scope	
	cout<<dr->f(4.4)<<endl;	
	return 0;
} 
