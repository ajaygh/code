#include <iostream>
#include <stack>

using namespace std;

template<typename T>
void display(stack<T> st){
	while(!st.empty()){
		cout << "stack top "<< st.top() << endl;
		st.pop();
	}
}

void insertbottom(stack<int> st, int el){
	if(st.empty())
		st.push(el);
	else{
		int top = st.top();
		st.pop();
		insertbottom(st, el);		
	}
}

void reverse(stack<int> st){
	int top = st.top();
	st.pop();
	reverse(st);
	insertbottom(st, top);
}

int main(){
	stack<int> data;
	for (auto i: {1,2,3,4,5})
		data.push(i);
//	for(int i = data.top();true != data.empty(); data.pop(), i = data.top())
	display(data);	
	return 0;
}
