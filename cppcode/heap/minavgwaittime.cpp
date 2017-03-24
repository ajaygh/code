#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;


int main() {
	int n;
	cin >> n;

	auto greatwait = [&](pair<int, int> l, pair<int, int> r) -> bool {
	return l.second > r.second;
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greatwait)> ncust(greatwait);
	int t, l;
	for(int i = 0; i < n; i++){
		cin >> t >> l;
		ncust.push(make_pair(t, l));
	}	
	//calculate min avg waiting time
	int start_time = 0, total_time=0;
	while(!ncust.empty()){
		total_time += start_time + ncust.top().second - ncust.top().first;
		start_time += ncust.top().second;
		ncust.pop();
	}
	cout << total_time/n <<endl;
	return 0;
} 
