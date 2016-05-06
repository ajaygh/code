#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <future>
using namespace std;
using namespace std::chrono;

int count1;
long fib(int n){
	count1++;
	if (n == 1 || n == 0) return 1;
	else return fib(n-1) + fib(n-2);
}

int main()
{
	vector<int> v{1,2,3,4,5};
	//for_each(v.begin(), v.end(), [] (int val)
	//{
	//	cout<<val<<endl;
	//} );
	int input;
	cin >> input;
	auto t0 = high_resolution_clock::now();
	future<long> fib_task = async(fib,input);
	long res1 = fib_task.get();
	auto t1 = high_resolution_clock::now();
	cout<<"res: using tasks "<<res1<<"times func call"<<count1<<endl;
	cout<<"time:"<<duration_cast<nanoseconds>(t1-t0).count()<<endl;
	
	auto t3 = high_resolution_clock::now();
	long res2 = fib(input);
	auto t4 = high_resolution_clock::now();
	cout<<"res: normal "<<res2<<"times func call"<<count1<<endl;
	cout<<"time:"<<duration_cast<nanoseconds>(t4-t3).count()<<endl;
	return 0;
}

