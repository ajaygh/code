#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> 

using namespace std;

int share = 0;
mutex mut;
condition_variable cveven, cvodd;

void printeven(int id ){
	int i = id;
	unique_lock<mutex> lk;
	while(i < 100){
		//mut.lock();
		cveven.wait(lk);
		if(share == 0)
			cout << id << " => " << i << endl;
		i += 2;
		cvodd.notify_one();
		lk.unlock();
	}
}

void printodd(int id ){
	int i = id;
	unique_lock<mutex> lk;
	while(i < 100){
		//mut.lock();
		cvodd.wait(lk);
		if(share == 0)
			cout << id << " => " << i << endl;
		i += 2;
		cveven.notify_one();
		lk.unlock();	
	}
}
int main() {
	thread t1{printeven, 0};
	thread t2{printodd, 1};
	cveven.notify_one();
	t1.join();
	t2.join();
	return 0;
} 
