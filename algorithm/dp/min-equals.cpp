#include <iostream>
#include <vector>
#define vi vector<int>

using namespace std;

int partition(vi &data, int left, int right){
	int l = left, r = right;
	int pivot = data[left];
	while(l < r){
		while(data[l] <= pivot && l < right)l++;
		while(data[r] >= pivot&& r > left)r--;
		if(l >= r){
			swap(data[left],data[r]);
			return r;		
		}
		swap(data[l],data[r]);
	}
}

void quicksort(vi &data, int l, int u){
	if(l < u){
		int dividx = partition(data, l, u);
		quicksort(data, l, dividx-1);
		quicksort(data,dividx+1,u);
	}
}

void addStep(vi& data, int idx, int step){
	for(auto& el : data){
		if(el != data[idx])
			el += step;
	}
}

int findMinOps(vi& data, vi& steps){
	int count = 0;
	for(int j = 1; j < data.size();j++){
		int diff = data[j]-data[j-1];
		for(auto& step : steps){
			if(diff == 0) break;
			if(diff >= step){
				addStep(data, j, diff-diff%step);
				diff %= step;
				count++;
			}
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vi h(n);
	for(int i=0; i < n;i++) cin >> h[i];
	//sort using quick sort
	quicksort(h, 0, n-1);
	cout <<"after sorting\n";
	for(int i = 0; i <n; i++) cout << h[i]<<endl;
	vi steps = {5,2,1};
	//quicksort(steps, 0, steps.size()-1);
	int minops = findMinOps(h, steps);
	cout <<minops<<endl;
	return 0;
} 
