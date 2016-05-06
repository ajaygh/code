#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
	printf("float weight= %.1f\n",0.1);
	char tst[100];
	sprintf(tst,"float weight= %.1f\n",0.1);
	printf("tst--%s\n",tst);

	return 0;
}
