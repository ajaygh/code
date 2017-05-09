#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

struct Data{
	int startVal;
	int maxVal;
	int numThread;
	pthread_mutex_t* mut;
	pthread_cond_t* condCurr, condNext;
};

void* printSync(void* _data){
	Data* data = (Data*)_data;
	for(int currVal = data->startVal; currVal <= data->maxVal; currVal += data->numThread){
		//get your resource, do job, free next resource
		pthread_mutex_lock(data->mut);
		pthread_cond_wait(data->condCurr, data->mut)
		cout <<"currVal " << currVal <<"thread no "<< data->startVal << endl;
		pthread_cond_signal(next);
		pthread_mutex_unlock(data->mut);
}

int main(){
	int numThread, max;
	cin >> numThread >> max;
	vector<pthread_mutex_t> vmut(numThread, PTHREAD_MUTEX_INITIALIZER);
	vector<pthread_cond_t> vcond(numThread, PTHEAD_COND_INITIALIZER);
	for(int i = 0; i < numThread; i++){
		int next = (i == numThread-1)?0:i+1;
		pthread_t pth{i+1, max, numThread, &vmut[i], &vcond[i], condNext[next]};
	
	}
			pthread_t pth;
	if(pthread_create(&pth,NULL, test1,(void*)NULL)){
		cout << "failed to create\n";
		return -1;
	}
	pthread_exit(NULL);
	//pthread_join(pth, NULL);
	return 0;
}
