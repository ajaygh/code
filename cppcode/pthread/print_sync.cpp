#include <iostream>
#include <vector>

#include <pthread.h>
#include <sys/unistd.h>

using namespace std;

struct tdata{
	tdata(int i , int n):i(i),n(n){}

	int i,n;
};

void* printNum(void* _data){
	tdata* data = (tdata*)(_data);
	int curr = data->i;
	while(curr <= 100){
		cout <<curr<<"from thread "<<data->i<<endl;
		curr += data->n;
	}
}

void* printEven(void* param){
	for(int i = 0; i < 100; i++){
		cout<<"value of i "<< i << endl;	
		usleep(1000);
	}
	pthread_exit(NULL);
}

int main() {
	int n;
	cin >> n;
	pthread_t pthread;
	//int res = pthread_create(&pthread, NULL, &printNum, (void *)(new tdata(0,2)));
		//cout <<"Error in thread creation\n";

	pthread_t peven;
	if(pthread_create(&peven,NULL, printEven, (void*)NULL)){
		cout << "error in even thread creation.\n";
		return -1;
	}

	pthread_exit(NULL);
	return 0;
} 
