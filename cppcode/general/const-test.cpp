
#include <iostream>

using namespace std;

class test{
	const static int mem1 = 0;
	public:
		test(){
		}
		int getTotal(){ return mem1;}
};

int main() {
	test tt;
	cout << tt.getTotal() << endl;
	return 0;
}
