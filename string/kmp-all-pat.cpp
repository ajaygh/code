
#include <iostream>
#include <string.h>

using namespace std;

void calculateLPS(char * lpsArr, int pLen){
	int len = 0, i = 1;
	lpsArr[0] = 0;
	while( i < pLen){
		if(lpsArr[i] == lpsArr[len]){
			len++;
			lpsArr[i] = len;
			i++;
		}else{
			if(len != 0){
				len = lpsArr[len-1];
			}else
				i++;
		}
	}
}

void KMP_Search(const char* txt, const char* pat){
	int tLen = strlen(txt);
	int pLen = strlen(pat);
	char *lpsArr = new char[pLen];
	int j = 0, i = 0;
	calculateLPS(lpsArr, pLen);

	while(i < tLen){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}
		if(j == pLen){
			cout<<"pattern found at "<< i-j<<endl;
			j = lpsArr[j-1];
		}else if(i < tLen && (txt[i] != pat[j])){
			if(j !=0 ){
				j = lpsArr[j-1];
			}else
				i++;
		}
	}
	delete[] lpsArr;
}

int main() {
	const char* txt = "taabaabcaabatgaaba";
	const char* pat = "aaba";
	KMP_Search(txt, pat);	
	return 0;
} 
