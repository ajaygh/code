
#include <iostream>

using namespace std;

int main() {
	//int arr[] = {4,8,1,4,2,1};
	int arr[] = {9,8,2,2,5,4};
	int len = sizeof(arr)/sizeof(int);
	int total_weight = 0;
	int min_bin=0, actual_bins = 0;
	int bin_capacity = 10;

	for(int i = 0; i < len; i++)
		total_weight += arr[i];
	cout <<"total_weight = "<< total_weight<< endl;

	if(total_weight%bin_capacity){
		min_bin = total_weight/bin_capacity + 1;
		cout << "minimum bin required "<< min_bin<<endl;
		return 0;
	}else{
		min_bin = total_weight/bin_capacity;
		int *bins = new int[min_bin + 1];
		bins[min_bin] = 0;
		
		for(int i = 0; i < min_bin+1; i++)
			bins[i] = 0;
		for(int i = 0; i < len; i++){
			for(int j = 0; j < min_bin + 1; j++){
				if(bins[j] + arr[i] <= 10){
					bins[j] += arr[i];
					break;
				}
			}
		}

		for(int j = 0; j < min_bin + 1; j++)
			cout<<"bins["<<j<<"] "<<bins[j]<<endl;

		if(bins[min_bin])
			cout <<"minimum bins required = "<<min_bin + 1<<endl;
		else
			cout <<"minimum bins required = "<<min_bin<<endl;
	}
	return 0;
} 
