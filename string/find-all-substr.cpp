
#include <iostream>
#include <string>
#include <sstream> 
#include <assert.h>
#include <vector>
#include <stdlib.h> 
#include <iterator> 
#include <typeinfo> 
#include <unistd.h> 
//#include <time.h> 

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

bool KMP_Search(const string& txt, const string& pat){
	int tLen = txt.length();
	int pLen = pat.length();
	char *lpsArr = new char[pLen];
	int j = 0, i = 0;
	calculateLPS(lpsArr, pLen);

	while(i < tLen){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}
		if(j == pLen){
	//		cout<<"pattern found at "<< i-j<<endl;
			j = lpsArr[j-1];
			return true;
		}else if(i < tLen && (txt[i] != pat[j])){
			if(j !=0 ){
				j = lpsArr[j-1];
			}else
				i++;
		}
	}
	delete[] lpsArr;
	return false;
}

struct lrpat{
	lrpat(int& _l, int& _r, string& _pat)
		:l(_l), r(_r), pat(_pat){}
	int l, r;
	string pat;
};

int main() {
	int N;
	cin >> N;
	string *txt = new string[N];
	for(int i =0; i < N; i++)
		cin >> txt[i];
	int Q;
	cin >> Q;

	vector<lrpat> vecLRPat;
	for(int i =0; i < Q; i++){
		int l, r;
		string pat; //= "aaba";
		string line;

		cin >> l >> r >>pat;
		vecLRPat.push_back(lrpat(l, r, pat));
		//cout <<"l="<<l<<"r="<<r<<"pat="<<pat<<endl;
	}

	for(auto elem : vecLRPat){
		int res = 0;
		for(int j = elem.l-1; j < elem.r; j++)
			//if(KMP_Search(txt[j], elem.pat))
			if(txt[j].find(elem.pat) != string::npos)
				res++;
		cout<<res<<endl;	
	}
	return 0;
} 
