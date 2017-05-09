#include <iostream>
#include <pthread.h>
#include <sys/time.h>

using namespace std;

#define NUM_THREADS 4
#define NUM_ELEMS 10000000

struct th_data
{
	int val;
	int start_idx;
};

pthread_mutex_t exit_mutex = PTHREAD_MUTEX_INITIALIZER;
int g_data = 0;
int data[NUM_ELEMS];

void* find_num(void* t_data)
{
	th_data* tmp = (th_data*)t_data;
	int idx = tmp->start_idx*NUM_ELEMS/NUM_THREADS, end_idx = (tmp->start_idx + 1) * NUM_ELEMS/NUM_THREADS;
	for(;idx <end_idx; idx++)
	{
		if(tmp->val == data[idx])
		{
			cout<<"value found at "<< idx+1<<endl;
			g_data = 1;
		}else if(g_data == 1)
		{
			cout<<"exited\n";
//			return;
			pthread_exit(NULL);
		}
	}
}

int main()
{
	pthread_t thrs[NUM_THREADS];
	int val = 5000;

	for(int idx = 0; idx < NUM_ELEMS; idx++)
	{
		data[idx] = idx;
	}

	for(int idx = 0; idx < NUM_THREADS; idx++)
	{
		th_data thd{val, idx};
		if(g_data == 0)
		{
			pthread_create(&thrs[idx], NULL, find_num, (void*)&thd);
//			usleep(300);
		}
		else 
			cout<<"no need done\n";
		cout<<"thread created\n";
	}
	cout<<"all threads created\n";
		pthread_join(thrs[0], NULL);
		pthread_join(thrs[1], NULL);
		pthread_join(thrs[2], NULL);
		pthread_join(thrs[3], NULL);
	for(int idx = 0; idx < NUM_THREADS; idx++)
	{
//		pthread_join(thrs[idx], NULL);
	}
	cout<<"completed\n";
	return 0;
}

