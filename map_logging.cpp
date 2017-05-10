#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

map<int, vector<string>> mJobid_log;

char log1[200];
#define sqr(x) ((x) * (x))

#define log_msg(jid, msg)\
sprintf(log1,msg);\
mJobid_log[jid].push_back(log1);
void log(char* par)
{
	cout<<par;
}
int main()
{
	mJobid_log[0];
	mJobid_log[1];
	log_msg(2,"done\n");
	mJobid_log[0].push_back("job created.\n");
	mJobid_log[0].push_back("job updated.\n");
	char log[100];
	sprintf(log,"job_id %d %s\n",sqr(4),"created");
	mJobid_log[1].push_back(log);
	sprintf(log,"job_id %d %s\n",sqr(5),"updated");
	mJobid_log[1].push_back(log);
	FILE* fp = fopen("map_log.txt", "a");
	for(auto it : mJobid_log[2])
	{
		cout<<it;
		fprintf(fp,it.c_str());
	}
	fclose(fp);
	return 0;
}


