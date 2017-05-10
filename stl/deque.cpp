
#include <iostream>
#include <deque> 

using namespace std;

int main() {
	deque<int> deq1;
	deq1.push_front(1);
	deq1.push_back(2);
	cout<<"deque front is "<<deq1.front()<<endl;	
	deq1.front() -= deq1.back();
	cout<<"deque front is "<<deq1.front()<<endl;	
	deq1.push_front(3);
	deq1.push_front(4);
	deq1.push_front(5);
	deq1.push_back(6);
	deq1.push_back(7);
	deq1.push_back(8);

	//deque<int>::iterator it = deq1.begin(), end = deq1.end();
	//cout<<"current deque is \n";
	//for(;it != end; it++)
	//	cout<<*it<<"\t";
	//cout<<endl;
	cout<<"current deque is \n";
	for(auto x : deq1)
		cout<<x<<"\t";
	cout<<endl;
	cout<<"size of deq1 is "<<deq1.size() <<endl;

	deq1.erase(deq1.begin()+3);
	cout<<"current deque is \n";
	for(auto x : deq1)
		cout<<x<<"\t";
	cout<<endl;
	cout<<"size of deq1 is "<<deq1.size() <<endl;

	deq1.erase(deq1.end()-3, deq1.end());
	cout<<"current deque is \n";
	for(auto x : deq1)
		cout<<x<<"\t";
	cout<<endl;
	cout<<"size of deq1 is "<<deq1.size() <<endl;
	deq1.clear();
	cout<<"size of deq1 is "<<deq1.size() <<endl;





	return 0;
}

