
#include <iostream>

using namespace std;

int func(int x){
	cout<<"parameter is "<<x<<endl;
}

int func1(int func(int)){
	return func(2);
}
int main() {
	func1(func);	
	return 0;
} 
