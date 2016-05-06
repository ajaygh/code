
#include <iostream>
#include <queue> 

using namespace std;
/*
void display(const queue<int> mq){
	cout<<"current queue is \n";
	for(auto el : mq)
		cout <<el<<"\t";
	cout << endl;
	cout<<"size of queue is "<< mq.size() << endl;
}
*/

int main() {
	queue<int> mq;

	for(int i = 0; i <10; i++)
		mq.push(i);

	cout<<"queue front is "<< mq.front()<<endl;
	cout<<"queue back is "<< mq.back()<<endl;
	mq.pop();
	cout<<"queue front is "<< mq.front()<<endl;
	cout<<"queue emptyp "<< mq.empty()<<endl;
	cout<<"queue size is "<< mq.size()<<endl;

	queue<int> q2;

	for(int i = 10; i <20; i++)
		q2.push(i);

	cout<<"queue 2 front is "<< q2.front()<<endl;
	mq.swap(q2);
	cout<<"queue 2 front is "<< q2.front()<<endl;
	cout<<"queue 2 size is "<< q2.size()<<endl;
	return 0;
} 
