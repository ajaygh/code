
#include <iostream>
#include <string> 
#include <vector> 
#include <assert.h> 

using namespace std;

void findAndPrintAllSubstring(string str, vector<string> vecFind){
	int total = 0;
	for(int len = 1; len <= str.length(); len++){
		for(int idx = 0; idx <= str.length()-len; idx++){
			auto substring = str.substr(idx, len);
			bool found = false;
			for(auto sub : vecFind){
				if( substring.find(sub) != string::npos){
					found = true;
					break;
				}
			}	
			if(!found){
		//		cout << str.substr(idx, len) <<endl;
				total++;
			}
		}
	}
//cout <<"total substr are "<< total <<endl;
	cout << total <<endl;
}

int main() {
	string str = "0101";
	vector<string> vecFind{"00", "11"};
	int T;
	cout<<"Enter total number of test cases\n";
	cin >> T;
	assert(!(1 > T)||(T > 100));
	vector<string> vecInput;//(T);
	for(int i = 0; i < T; i++){
		string tmp;
		bool invalidChar = false;
		cin >> tmp;

		for(auto ch : tmp){
			if(!(ch == '0' || ch == '1')){
				invalidChar = true;
				break;
			}
		}
		if(!invalidChar) vecInput.push_back(tmp);
	}
	for(auto input : vecInput){
	//	cout << "element of vector is " <<input << endl;
		findAndPrintAllSubstring(input, vecFind);	
	}
	return 0;
} 
