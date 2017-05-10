#include <iostream>
#include <thread>
#include <mutex> 
#include <chrono> 
#include <vector>

using namespace std, std::chrono;

void print(vector<double>& vd){
	for (auto& el : vd)
		cout << "el val "<< el << endl;
}

struct S{
	S(const vector<double>& vv, double* p):v{vv}, res{p}{}
	void operator()(){
		for(auto el : v){
			cout <<"functor el "<<el<<endl;
			*res += el;
		}
	}
	vector<double> v;
	double *res;
};

mutex m1,m2;
int sh = 0;
void f1(){
	lock_guard<mutex> lck1{m1,defer_lock};
	lock_guard<mutex> lck2{m2,defer_lock};

	lock(lck1, lck2);//acquire all locks
	sh += 7;
	cout << "f1 changed sh to "<< sh << endl;
}

void f2(){
	lock_guard<mutex> lck{m1};
	sh += 7;
	cout << "f2 changed sh to "<< sh << endl;
	auto now = high_resolution_clock::now();
	this_thread::sleep_for(milliseconds{200});
	auto after = high_resolution_clock::now();
	cout << "waited for "<<duration_cast<nanoseconds>(after-now).count()<<endl;
}
int main() {
	vector<double> vd{1,2,3,4,5,67,77};
	//thread t1{print, vd};
	//double *d{new double{0}};
	//thread t2{S{vd}};
	//thread t2{S{vd, d}};

	//t1.join();	
	//t2.join();	
	//cout << "sum of all vd is "<< *d << endl;
	thread tm1{f1};
	thread tm2{f2};

	tm1.join();
	tm2.join();
	return 0;
} 
