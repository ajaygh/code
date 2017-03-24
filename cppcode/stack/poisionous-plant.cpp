#include <iostream>
#include <stack> 
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> poision;
	int tmp;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		poision.push(tmp);
	}

	//find number of days to remove poision
	int days = 0;
	stack<int> tp;
	bool nextitr = true;
	while(nextitr){
		int ncurr = poision.size() - 1;
		//check more poisionous and remove it.
		while (poision.size()>1){
			tmp = poision.top();
			poision.pop();
			if(tmp <= poision.top()){
				tp.push(tmp);
			}
		}

		if(ncurr > tp.size()){
			days++;
			nextitr = true;
			ncurr = tp.size()+1;
		}else{
			nextitr = false;
			break;
		}

		if(nextitr){
			int left = poision.top();
			while(tp.size() != 0){
				tmp = tp.top();
				tp.pop();
				if(tmp <= left)
					poision.push(tmp);
				left = tmp;
			}
		}
		if(ncurr > poision.size())
			days++;
		else
			nextitr = false;
	}
	cout<<days<<endl;
	return 0;
} 
