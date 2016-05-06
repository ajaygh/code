#include <iostream>
#include <vector>
#include <algorithm>

#define vi vector<int>
#define vvi vector<vi>
#define all(c) c.begin(), c.end()
using namespace std;

void swap(int& a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

void push(vi& heap, int v){
	heap.push_back(v);
	//heapify
	if(heap.size()>1){
		int p = (heap.size()-2)/2;
		int ch = heap.size() -1;
		while(p>=0 && heap[ch] < heap[p]){
			swap(heap[ch] , heap[p]);
			ch = p;
			p = (p-2)/2;
		}
		if(heap.size()>2){
			if(heap[1] < heap[0])
				swap(heap[0], heap[1]);
			else if(heap[2] < heap[0])
				swap(heap[0], heap[2]);
		}
	}
};

void pop(vi& heap, int v){
	if(!heap.empty()){
		if(heap.size() == 1)
			heap.clear();
		else{
			replace(all(heap),v, heap.back());
			heap.pop_back();
			//heapify down
			int p = 0;
			int ch1  = 2*p+1,ch2 = 2*p + 2;
			while((ch2 < heap.size() && heap[ch2] < heap[p])||
				(ch1 < heap.size() && heap[ch1] < heap[p])){
				if(ch1 < heap.size() && heap[ch1] < heap[p]){
					swap(heap[ch1] , heap[p]);
					p = ch1;
					ch1 = 2*p + 1;
					ch2 = 2*p + 2;
				}else if(ch2 < heap.size() && heap[ch2] < heap[p]){
					swap(heap[ch2] , heap[p]);
					p = ch2;
					ch1 = 2*p + 1;
					ch2 = 2*p + 2;
				}
			}
		}
	}
};

int main() {
	vi heap;
	int q;
	cin>>q;
	int type,v;
	for(int i=0;i<q;i++){
		cin>>type;
		switch(type){
			case 1:
				cin>>v;
				push(heap, v);
				break;
			case 2:
				cin>>v;
				pop(heap, v);
				break;
			case 3:
				cout<<heap[0]<<endl;
				break;
			default:
				break;
		}
	}  
	return 0;
}

