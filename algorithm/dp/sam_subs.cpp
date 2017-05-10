#include <iostream>
#include <string>

using namespace std;

int main() {
	string bolls, stmp;
    cin >> bolls;
	int rem = 1000000007;
	int total = 0;
	for(int i = 0; i < bolls.length(); i++){
		for(int j = i; j < bolls.length(); j++){
			stmp = bolls.substr(i, j-i+1);
			total += stoi(stmp);
		}
		if(total > rem)
			total %= rem;
	}
	cout << total<<endl;
	return 0;
} 
