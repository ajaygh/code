#include <iostream>
#include <vector>
#include <stdio.h>

#define vi vector<int>
using namespace std;

int main() {
	int i = 0x01;
	unsigned char *ch = (unsigned char *)&i;
	cout <<"ch[0] = "<<ch[0]<<" ch[1] = "<<ch[1]<<" ch[2] = "<<ch[2]<<" ch[3] = "<< ch[3] << endl;	
	cout << sizeof(int) << endl;
	for(int i = 0; i < 4; i++)
		printf("ch[%d] = %u\n", i, ch[i]);
	return 0;
}
