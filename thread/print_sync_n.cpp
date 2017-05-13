#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> 

using namespace std;

const int N = 10; //number of threads
int share = 0;
mutex mut;

void print(int id ){
	int i = id;
	while(i < 100){
		mut.lock();
		if(share == id){
			cout << id << " => " << i << endl;
			i += N;
			if(share < N-1)
			   share = share+1;
			else
				share = 0;
		}
		mut.unlock();
	}
}

int main() {
	thread* arrth[N];
	for(int i = 0; i < N; i++){
		//thread t{print, i};
		arrth[i] = new thread(print, i);
	}

	for(int i = 0; i < N; i++){
		arrth[i]->join();
	}
	return 0;
} 
