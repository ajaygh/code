//sort two array
//
#include <iostream>

using namespace std;
void sort2arr(int *arr1,int len1, int *arr2, int len2, int *res){
	int i,j,k;
	i = j = k = 0;
	while(i < len1 && j < len2){
		if(arr1[i] < arr2[j]){
			res[k] = arr1[i];
			i++,k++;
		}
	}

}
int main() {
	int arr1[]{1,4,7,9,11};
	int arr2[]{2,5,8,12};
	
	int len1 = sizeof(arr1)/sizeof(int);
	int len2 = sizeof(arr2)/sizeof(int);
	cout << len1 << "\t" << len2 << endl;

	int *res = new int[len1 + len2];

	sort2arr(arr1, len1, arr2, len2, res);
	cout<<"sorted array is \n";
	for(int i=0; i < len1 + len2; i++)
		cout <<res[i]<<"\t";
	cout <<endl;
	return 0;
} 
