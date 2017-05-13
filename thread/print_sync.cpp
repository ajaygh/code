#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> 

using namespace std;

int share = 0;
mutex mut;

void print(int id ){
	int i = id;
	while(i < 100){
		mut.lock();
		if(share == id){
			cout << id << " => " << i << endl;
			i += 2;
			share = 1-id;
		}
		mut.unlock();
	}
}

int main() {
	thread t1{print, 0};// even thread
	thread t2{print, 1};//odd thread
	t1.join();
	t2.join();
	return 0;
} 
