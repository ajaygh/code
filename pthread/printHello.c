#include <stdio.h>
#include <sys/unistd.h> 

#include <pthread.h>

pthread_mutex_t printMutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct tdata{
	int i;
	pthread_mutex_t* mut;
}tdata;

void* printHello(void* param){
	tdata* td = (tdata*)param;
	int i = td->i;
	pthread_mutex_lock(td->mut);
	pthread_mutex_unlock(td->mut);

	if(i%2 == 0){
		printf("Even thread started.\n");
		for(; i < 10; i += 2 ){
			pthread_mutex_lock(&printMutex);
			printf("even thread value of i %d\n", i);
			pthread_mutex_unlock(&printMutex);
			usleep(10000);
		}
	}else{
		printf("Odd thread started.\n");
		for(; i < 10; i += 2 ){
			pthread_mutex_lock(&printMutex);
			printf("odd thread value of i %d\n", i);
			pthread_mutex_unlock(&printMutex);
			usleep(10000);
		}
	
	}
}

int main(int argc, char *argv){
	pthread_t peven, podd;
	int even = 2, odd = 1;
	pthread_mutex_t mutEven, mutOdd;
	
	pthread_mutex_init(&mutEven, NULL);
	struct tdata teven;
	teven.i = 2;
	teven.mut = &mutEven;

	pthread_mutex_lock(&mutEven);
	if(pthread_create(&peven, NULL, printHello, (void*)&teven)){
		printf("failed to create even thread.\n");
		exit(-1);
	}

	pthread_mutex_init(&mutOdd, NULL);
	struct tdata todd;
	todd.i = 1;
	todd.mut = &mutOdd;
	
	pthread_mutex_lock(&mutOdd);
	if(pthread_create(&podd, NULL, printHello, (void*)&todd)){
		printf("failed to create odd thread.\n");
		exit(-1);
	}
	pthread_mutex_unlock(&mutEven);
	pthread_mutex_unlock(&mutOdd);
	pthread_exit(NULL);
	return 0;
}
