#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
using namespace std;

int main() {
	int n, k;
	cin >> n >>k;
	vi candy(n);
	for(int i = 0; i < n; i++) cin >> candy[i];
	
	priority_queue<int, vi, greater<int>> diff;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(candy[i] < candy[j])
				diff.push(candy[j]- candy[i]);
			else
				diff.push(candy[i]- candy[j]);
		}
	}
	int total = 0;
	int kl = k*(k-1)/2;
	for(int i = 0; i < kl; i++){
		total += diff.top();
		diff.pop();
	}

	cout << total <<endl;
	return 0;
} 
