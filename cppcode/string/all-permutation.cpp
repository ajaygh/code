#include <iostream>
#include <string.h>

using namespace std;

int call=0;

void swap(char* a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm(char* str, int i, int len){
	if(i == len-1){
		cout << str<<endl;	
		call++;
		return;
	}
	for(int j = i;j < len; j++){
		swap(str+i, str+j);
		perm(str, i+1, len);
		swap(str+i, str+j);
	}
}

int main() {
	char *orig_str;
	int len;
	cout <<"Please enter the length of string.\n";
	cin >> len;
	orig_str = new char[len+1];
	for(int i = 0; i < len; i++)
		cin >> orig_str[i];
	orig_str[len] = '\0';
	cout <<"ORIGINAL STRING IS "<<orig_str<<endl;
	perm(orig_str, 0, len);
	cout<<call<<endl;
	return 0;
} 

