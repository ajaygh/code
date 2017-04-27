#include <iostream>

using namespace std;

class Test{
	public:
		Test(string str):str{str}{
			cout <<"Created string "<<str<<endl;
		}
	virtual  ~Test(){
			cout <<"Destroying string.\n";
		}
	private:
		string str;

};

class TestCh :public Test{
	public:
		TestCh(string str, int n):Test{str}, n{n}{
			cout <<"Created int "<<n<<endl;
		}
		~TestCh(){
			cout <<"Destroying int.\n";
		}
	private:
		int n;

};

int main() {
	Test*  t = new TestCh{"ajay",5};
	delete t;
	return 0;
} 

