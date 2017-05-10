#include<iostream>

using namespace std;

class A
{
	protected:
	virtual void fun()
		{
			cout<<"A:fun\n";
		}
};

class B : public A
{
	public:
	void fun() override 
	{
		cout <<"B:fun\n";
	}
	void checkBase()
	{
		A::fun();
	} 
};


int main()
{
	auto b =new B();
	b->fun();
	b->checkBase();
	return 0;
}
