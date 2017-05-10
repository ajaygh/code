#include <iostream>
#include <vector>
#include <algorithm>

#define vi vector<int>
using namespace std;

string findsubse_substr(string a, string b){
	vi subse(a.length(), 0);
	int i = 0,j = 0;
	for(; i < a.length(); i++){
		if(a[i] == b[j]){
			if(i>0)
				subse[i] = subse[i-1] + 1;
			else 
				subse[i] = 1;
			j++;
		}
		if(j == b.length())
			break;
	}
	if(subse[i] == b.length())
		return "YES";
	else 
		return "NO";
}

int main() {
	string a,b;
	cin >> a >> b;
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	cout <<a<<"  "<<b<<endl;
	cout <<findsubse_substr(a,b)<<endl;	
	return 0;
} 
