#include <iostream>
using namespace std;

class SingleObject{
	public:
		static SingleObject* getObject(){
			return instance;
		}
		void showMessage(){
			cout<<" created address "<<instance<<endl;
		}
	private:
		explicit SingleObject(){}
		static SingleObject* instance;
};

SingleObject* SingleObject::instance = new SingleObject;

int main() {
	SingleObject* so1 = SingleObject::getObject();	
	so1->showMessage();
	SingleObject* so2 = SingleObject::getObject();	
	so2->showMessage();
	return 0;
} 
