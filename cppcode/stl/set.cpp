
#include <iostream>
#include <set>

using namespace std;

int main() {
	int arr[] = {1,2,3,4,5};
	set<int> ms(arr, arr + 3);

	ms.insert(6);
	ms.erase(2);
	for(auto x: ms)
		cout <<x<<"\t";
	cout <<endl;	
	cout<<"set size is "<<ms.count(2)<<endl;
	return 0;
} 
