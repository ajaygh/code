#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include<pthread.h>
void* fun(void* th){
	pthread_detach(pthread_self());
	return NULL;
}

int main()
{
	for(int i = 0; i < 100000; i++){
		pthread_t pt;
		if(pthread_create(&pt, NULL, fun, (void*)NULL)){
			printf("thread %d creation failed.\n", i);
		}
		usleep(4000);
	}

	return 0;
}
