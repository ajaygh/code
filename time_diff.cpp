#include <iostream>
//#include <ctime>
#include <chrono>
//#include <ratio>
#include <algorithm>
//#include <stdio.h>

using namespace std;
using namespace std::chrono;

int main()
{

	high_resolution_clock:: time_point t1 = high_resolution_clock::now();
	int in = 0;
	int arr[1000];
	fill_n(arr, 1000,1);
	arr[997] = 0;
	//find first occurance of 0
	int tmp = 0;
	while(tmp < 1000)
	{
		if(arr[tmp] == 0)
		{
			cout << "found 0 at " << tmp + 1<< endl;
			break;
		}
		tmp++;
	}
	high_resolution_clock:: time_point t2 = high_resolution_clock::now();
	
	duration<double> time_span = duration_cast<duration<double>>(t2-t1);
	cout << "time taken "<<time_span.count()<<endl;
	//printf("time taken %f \n",time_span.count());

	return 0;
}
