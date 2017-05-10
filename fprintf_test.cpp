#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char tst[] = "aaaaaaaa\r\nbbbbb\r\nccccccccc";
	//FILE* fp = fopen("/home/gor/cpp_programms/fpr_test.log", "a");
	FILE* fp = fopen("/home/gor/fpr_test.log", "a");
	char* pch = strstr(tst, "\r\n");
	if(pch != NULL)
	{
		pch = strtok(tst, "\r\n");
		while(pch != NULL )
		{
			printf("%s\n",pch);
			fprintf(fp,"%s\n", pch);
			pch = strtok(NULL, "\r\n");
		}

	}

	return 0;
}
