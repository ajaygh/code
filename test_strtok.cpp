#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
	
	char tmp_str[] = "sorter, vms, merger, input";
	vector<char*> res;
	const char * delim = ", ";
	
	const char* tt = "tt,hh,jj";
	char* test;
	test = (char*)malloc(sizeof(char) * 40);
	test = tmp_str;
	char* tmp = strtok(test, delim);
	while(tmp != NULL)
	{
		res.push_back(tmp);
		tmp = strtok(NULL, delim);	
	}

	for(auto val:res)
		cout <<val<<endl;
	return 0;
}
