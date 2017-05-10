
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> stk;
	stk.push(2);	
	stk.push(4);	
	stk.push(6);	
	stk.push(8);	
	stk.push(12);
	cout <<"stack is empty "<<stk.empty()<<endl;
	cout <<"stack size is "<<stk.size()<<endl;

	while(!stk.empty()){
		cout <<"stack top is "<<stk.top()<<endl;
		stk.pop();
	}
	return 0;
} 
