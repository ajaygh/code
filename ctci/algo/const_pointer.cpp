#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main() {
	int a = 5;
	int *p = &a;
	const int *q = &a;
	int const *r = &a;
	const int *const s = &a;
	cout << "p = "<<*p<<"q = " <<*q << "r = " << *r << "s = "<<*s<<endl;
	return 0;
} 
