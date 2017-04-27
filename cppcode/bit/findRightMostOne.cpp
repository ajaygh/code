#include <iostream>

using namespace std;

int findrightmost(unsigned int n){
	int idx = 0;
	int res = -1;
	while(n){
		cout <<"curr value of n"<< n << endl;
		if(n & 1)
			res = idx;
		idx++;
		n = n>>1;
	}
	return res+1;
}

int main() {
	cout <<findrightmost(2)<< endl;
	cout <<findrightmost(-5)<< endl;
	cout <<findrightmost(-1)<< endl;
	return 0;
} 
