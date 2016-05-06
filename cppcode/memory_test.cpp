#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

using namespace std;
struct MsgPath
{
	MsgPath(char* _msg, char* _path)
	{
		msg = new char[100];
		path = new char[100];
		strcpy(msg,_msg);
		strcpy(path, _path);
		cout<<"msg after construction = "<<msg<<endl;
		cout<<"size of msg at cons = "<<sizeof(msg)<<endl;
		cout<<"path after construction = "<<path<<endl;
	}

	~MsgPath()
	{
		delete[] msg;
		delete[] path;
		cout<<"msg after destruction = "<<msg<<endl;
		cout<<"size of msg at cons = "<<sizeof(msg)<<endl;
		cout<<"path after destruction = "<<path<<endl;
	}

	char* msg;
	char* path;
};

void* fun(void* data)
{
//	cout <<(char*)data<<"sizeof data "<<sizeof((char*)data)<<endl;
//	delete[] (char*)data;
//	cout <<(char*)data<<"sizeof data "<<sizeof((char*)data)<<endl;
	delete (MsgPath*)data;
}
int main()
{
/*	char* mem1 = new char[100];
	char* mem2 = (char*) malloc(sizeof(char) * 100);
	//delete[] mem1;
	//cout<< mem1<<endl;
		
	strcpy(mem2,"testing memory 2\n");
	cout<< mem2<<endl;
	free(mem2);
	cout<< mem2<<endl;

	//usleep(11);	
//	sleep(11);	
	cout<<"testing memory after free\n" <<mem1<<endl;
*/
	char* msg = (char*) malloc(sizeof(char) * 100);
	char* path = (char*) malloc(sizeof(char) * 100);
	//char* msg = new char[100];
	//char* path = new char[100];
	strcpy(msg,"msg for a96\n");	
	strcpy(path,"a96/a96.log");
	
	MsgPath* msgPath = new MsgPath(msg,path);
	
	pthread_t pmem1;
	pthread_create(&pmem1,NULL, fun, (void*)msgPath);
//	delete msgPath;
	sleep(20);
	return 0;
}
