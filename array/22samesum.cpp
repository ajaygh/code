//find 4 elements in given array so that a+b =c+d

#include <iostream>
#include <algorithm>

using namespace std;

void findFourSameSum(int* arr, int n){
	if(n >= 4){
		sort(arr, arr+n);
		for(int i = 0; i < n; i++) cout <<arr[i]<<"\t";
		cout <<endl;
		int ai=0, bi=n-1,ci = 1, di = n-2;
		while(ci < di){
			if(arr[ai] +arr[bi] == arr[ci] + arr[di]){
				cout<<arr[ai]<<" + "<<arr[bi]<<" = "<<arr[ci]<<" + "<<arr[di]<<endl;
				return;
			}else if(arr[ai] +arr[bi] > arr[ci] + arr[di]){
				if(ci == di-1){
					bi--;
					ci = ai + 1;
					di = bi-1;
				}else
					ci++;
			}else{
				if(ci == di-1){
					ai++;
					ci = ai + 1;
					di = bi-1;
				}else
					di--;
			}
		}
	}
}


int main() {
	int arr[]={1,2,4,5,23,83,45,55,65,3};
	findFourSameSum(arr, 10);

	return 0;
} 
