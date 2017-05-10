#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

int main() {
	int a, b,c = 0;
	cin >> a >> b;
	while(a || b){
		if(((1 ^ a)%2 != (1^b)%2) ||((0^a)%2 != (0^b)%2))
		   c++;
		a >>= 1;
		b >>= 1;	
	}
	cout <<c<<endl;
	return 0;
} 
