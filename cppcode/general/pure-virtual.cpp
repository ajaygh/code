
#include <iostream>

using namespace std;

class Base{
	public:
	virtual	~Base(){cout<<"Dest base\n";}
//	virtual int func()=0;
};

class Derived : public Base{
	public:
		~Derived(){cout<<"Dest Derived\n";}
		int func(){cout <<"hello\n"; return 0;}
};

int main() {
	//Derived *bs = new Derived();	
	Base *bs = new Derived();	
//	bs->func();
	delete bs;
	return 0;
}
