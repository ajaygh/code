#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

void incr(int& x)
{
//	for(int i = 0; i < 5; i++){
	this_thread::sleep_for(chrono::milliseconds(202));
	cout <<"value of x incremented :"<<++x<<endl;
//	}
}
void decr(int& x)
{
//	for(int i = 0; i < 5; i++){
    this_thread::sleep_for(chrono::milliseconds(100));
	cout <<"value of x decremented :"<<--x<<endl;
//	}
}
void incr_decr(int& x, int ch, int time)
{
	for(int i = 0; i < 5; i++){
    this_thread::sleep_for(chrono::milliseconds(time));
	
	if(ch == 0)
		cout <<"value of x incremented :"<<++x<<endl;
	else 
		cout <<"value of x decremented :"<<--x<<endl;
	}
}

long count = 0;

long async_fib(int n)
{
	if(n < 2) return n;
	else{
		auto fu1 = async(launch::async, async_fib, n-1);
		auto fu2 = async(launch::async, async_fib, n-2);
		auto fib1 = fu1.get();
		auto fib2 = fu2.get();
		return fib1 + fib2;
	}
}

int main(){
	int n;
	
	cout <<"initial count"<<count<<endl;
	cout<<"enter the value of n:"<<endl;
	cin>>n;
	auto res = async_fib(n);
	cout <<"initial count"<<count<<endl;
	int x = 5;
	cout<<"initial value:"<<x<<endl;
	
	for(int i = 0; i < 5; i++){
//	async(launch::async, incr,ref(x));
//	async(launch::async, decr,ref(x));
	}
	async(launch::async, incr_decr,ref(x), 1, 100);
	async(launch::async, incr_decr,ref(x), 0, 220);
return 0;
}
