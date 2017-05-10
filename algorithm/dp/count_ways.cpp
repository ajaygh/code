#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main() {
	int n;
	cin >> n;
	vi we(n);	
	for(int i = 0; i < n; i++)
		cin >> we[i];
	unsigned long long l, r;
	cin >> l >> r;
	int mod = 1000000007;
	unsigned long total = 0;
	vector<vi> sol(r+1, vi(we.size(), 0));
	for(unsigned long long j = 1; j <= r;j++){
		for(int k = 0; k < n; k++){
			if(we[k]<= j){
				if(we[k] == j){
					sol[j][k] = 1;
				}else{
					for(int t = k; t < n, j >= we[t]; t++)
						sol[j][k] += sol[j-we[k]][t];
						sol[j][k] %= mod;
				}
			}
		}
		if(j >= l){
			for(int k = 0; k < n; k++){
				total += sol[j][k];
				total %= mod;
			}
		}
	}
	cout << total <<endl;
	return 0;
} 
