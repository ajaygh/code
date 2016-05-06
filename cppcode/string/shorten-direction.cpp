
#include <iostream>
#include <assert.h> 
#include <string> 
#include <cstring> 

using namespace std;

int main() {
	string instr;
	cin >> instr;
	int len=0, n=0, e=0;
	len = instr.length();
//	cout << "input string length" << len<<endl;
	assert((len >= 1) && (len <= 100000));

	for(auto ch : instr){
		if( ch == 'N')
			n++;
		else if(ch == 'S')
			n--;
		else if( ch == 'E')
			e++;
		else if(ch == 'W')
			e--;
	}
	int len_n = (n>=0)?n:-n;
	int len_e = (e>=0)?e:-e;
	char * res = new char[len_n + len_e + 1];

	assert((n != 0) || (e != 0));

	if(len_e == 0){
		if(n> 0)
			memset(res,'N', len_n);
		else
			memset(res,'S', len_n);
		res[len_n] = '\0';
	}
	else if(len_n == 0){
		if(e> 0)
			memset(res,'E', len_e);
		else
			memset(res,'W', len_e);
		res[len_e] = '\0';
	}else{
		if(e > 0)
			for(int i = 0; i < len_e; i++)
				res[i] = 'E';
		else
			for(int i = 0; i < len_e; i++)
				res[i] = 'W';

		if(n > 0)
			for(int j = len_e; j < len_e+len_n;  j++)
				res[j] = 'N';
		else
			for(int j = len_e; j < len_e+len_n;  j++)
				res[j] = 'S';
		res[len_e+len_n] = '\0';
	}
	
	cout << res;
	return 0;
} 
