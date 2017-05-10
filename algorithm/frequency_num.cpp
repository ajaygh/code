#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;


int findStartIndex(vi& vdata, int num){
	int left = 0, right = vdata.size()-1;
	while(left <= right ){
		int mid = (left+right)/2;
		if(vdata[mid] == num){
			if(mid >= 1){
			   	if(vdata[mid-1]< num)
					return mid;
				else
					right = mid - 1;
			}else
				return 0;
		}else if(vdata[mid] > num)
			right = mid -1;
		else 
			left = mid+1;
	}
	return -1;
}
int findEndIndex(vi& vdata, int num){
	int left = 0, right = vdata.size()-1;
	while(left <= right ){
		int mid = (left+right)/2;
		if(vdata[mid] == num){
			if(mid < (vdata.size()-1)){
			   	if(vdata[mid+1]> num)
					return mid;
				else
					left = mid + 1;
			}else
				return vdata.size()-1;
		}else if(vdata[mid] > num)
			right = mid -1;
		else 
			left = mid+1;
	}
	return -1;
}

int findFrequency(vi & vdata, int num){
	//find the start index
	int startIdx = findStartIndex(vdata, num);
	if (startIdx == -1)
		return 0;
	else{
		int endIdx = findEndIndex(vdata, num);
		return endIdx-startIdx+1;
	}
}

int main() {
	int n;
	cin >> n;
	vi vdata(n);
	for(int i = 0; i < n; i++)
		cin >> vdata[i];
	int num;
	cin >> num;
	cout << findFrequency(vdata, num) << endl;
	return 0;
} 
