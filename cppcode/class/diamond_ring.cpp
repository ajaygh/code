#include <iostream>

using namespace std;

class A{
	public:
		A(int a):a{a}{cout << "A created with value "<<a << endl;}
	protected:
		int a;
};

class B: virtual public A{
	public:
		B(int b): A{b}{cout << "B created with value "<<b << endl;}
};

class C: virtual public A{
	public:
		C(int c): A{c}{cout << "C created with value "<<c << endl;}
};

class D: public B, C{
	public:
		D(int d): B{d+5}, C{d+10}{ cout << "D created with value "<<d << endl;}
};

class E: public B, C{
	public:
		E(int e): C{e+5}, B{e+10}{ cout << "E created with value "<<e << endl;}
};

/*
class F: public B, C{
	public:
		F(int f): A{f}{ cout << "F created with value "<<f << endl;}
};*/

int main() {
	A a{5};
	B b{6};
	C c{7};
	D d{8};
	E e{9};
	//F f{10};
	return 0;
} 
