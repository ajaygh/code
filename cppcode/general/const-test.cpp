
#include <iostream>

using namespace std;

class test{
	int mem1=0;
	public:
		void const_test(int& x){
			x += 2;
			mem1 +=1;
			cout <<x<<"mem1 is "<<mem1<<endl;
		}
};

int main() {
	test tt;
	int s =10;
	tt.const_test(s);
	return 0;
}
