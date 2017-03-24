#include <iostream>
#include <unordered_set> 

using namespace std;

int main() {
	unordered_set<int> sa = {1,2, 3, 4, 5};
	int total=0;
	for(auto& el : {3,4,5,6,7}){
		total += sa.count(el);
	}
	cout <<total<<endl;
	return 0;
} 
