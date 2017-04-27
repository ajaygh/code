#include <iostream>
#include <vector>
#include <numeric>

#define vi vector<int>
using namespace std;

int main() {
	int n;
	cin >> n;
	vi v(n);
	iota(&v[0], &v[n], 1);
	for(auto& el : v)
		cout << el << endl;	
	return 0;
} 
