//max-rec
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	stack<int> shouse, maxr;
	cin >> n;
	int tmp;
	for(int i =0; i < n; i++){
		cin >> tmp;
		shouse.push(tmp);
	}
	int max = 0;
	while(!shouse.empty()){
	int remove_count = 0;
		tmp = shouse.top();
		shouse.pop();
		if(maxr.empty())
			maxr.push(tmp);
		else{
			if(tmp >= maxr.top())
				maxr.push(tmp);
			else{
				while(tmp < maxr.top() && !maxr.empty()){
					remove_count++;
					if(max < remove_count * maxr.top())
						max = remove_count * maxr.top();
					maxr.pop();
				}
				maxr.push(tmp);
				if(max < remove_count)
			}
		}
	}
	
	cout <<max<<endl;
	return 0;
} 
