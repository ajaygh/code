#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main() {
	int n = 3;
	cin >> n;
	cout <<	(n&(n-1))<<endl;
	return 0;
} 
