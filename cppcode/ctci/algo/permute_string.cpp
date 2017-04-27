#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

void swap(string& str, int i, int j){
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void permute(string str, int pos){
	if(pos == str.length() - 1){
		cout << str << endl;
		return;
	}else{
		for(int i = pos; i < str.length(); i++){
			swap(str, pos, i);
			permute(str,pos+1);
			swap(str,pos, i);
		}
	}
}

int main() {
	string str;
	cin >> str;
	permute(str,0);	
	return 0;
} 
