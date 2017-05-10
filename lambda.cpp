#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
//	auto lambda1 = []{ cout << "simplest lambda.\n";};
//	lambda1();
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	int count = 0;
	for_each(v.begin(), v.end(), [&] (int val){
	 if(val ==3)
	{
		cout<<"found"<<val<<endl;
		return 0;
	}
	else cout<<++count<<endl;
	});
	return 0;
}
