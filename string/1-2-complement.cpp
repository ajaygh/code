#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std; 

int main(int argc, char* argv[]){
	//char num[] = {'0','0', '0', '0', '0', '0','\0'};
	char *num;
	int len1;
	cout <<"Please enter length of string.\n";
	cin >> len1;
	num = new char[len1+1];
	for(int i = 0; i < len1; i++)
		cin >> num[i];
	//find 1's complement
	//int len1 = strlen(num);
	cout <<num<<endl;
	for(int i = 0; i < len1; i++){
		if(num[i] == '0') num[i] = '1';
		else if(num[i] == '1') num[i] = '0';
		else if(num[i] == '\0') continue;
		else{
			cout << "invalid binary num\n";
			break;
		}
	}	
	cout <<num<<endl;
	//add 1 for 2's complement
	char* num2 = new char[len1+1];
	bool carry = true;
	for(int j = len1-1; j >= 0; j--){
		if(num[j] == '0'){
			num[j] = '1';
			cout <<"2's complement is "<<num<<endl;
			carry = false;
			break;
		}else if(num[j] == '1'){
			num[j] = '0';
		}
	}
	if(carry){
		num2[0] = '1';
		
		for(int i = 1; i <= len1; i++){
			num2[i] = '0';
		}
		num2[len1+1] = '\0';
		cout << num2 <<endl;
	}
	return 0;
} 
