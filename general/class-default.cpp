
#include <iostream>

using namespace std;

class Base{

};

class Derived : public Base{

};

int main() {
	Base *bs = new Derived();	
	return 0;
}
