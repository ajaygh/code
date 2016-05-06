//c++ to find maximum profit from weighted job scheduling

#include <iostream>
#include <algorithm>

using namespace std;

struct job{
	explicit job(const int& _profit, const int& _start, const int& _finish): profit(_profit), start(_start), finish(_finish){}
	int profit, start, finish;
};

int compareFintime( const int& fin1, const int& fin2){
	if(fin1 <= fin2)
		return fin1;
	else 
		return fin2;
}

int findLatestNonConflict(job* jobs[], int curr){
	for(int j = curr-1; j >=0; j--){
		if(jobs[j]->finish <= jobs[curr]->start)
			return j;
	}
	return -1;
}



int main() {
	
	return 0;
} 
