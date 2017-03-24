
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v = {1,5,3,7,9,6};

	cout<<"Initially vector is \n";
	for(auto& el : v)cout<< el <<' ';
	cout<<endl;
	make_heap(v.begin(), v.end());
	cout<<"after making heap\n";	
	for(auto& el : v)cout<< el <<' ';
	cout<<endl;
	cout<<"after pop_heap \n";
	pop_heap(v.begin(), v.end());
	for(auto& el : v)cout<< el <<' ';
	cout<<endl;
	auto largest = v.back();
	v.pop_back();
	cout<<"largest value in v is "<<largest<<endl;
	cout<<"After removing largest element heap is \n";
	for(auto& el : v)cout<< el <<' ';
	cout<<endl;
	return 0;
} 
