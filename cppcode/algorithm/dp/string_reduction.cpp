#include <iostream>
#include <list>
using namespace std;

list<char> minReduce(string sin){
	list<char> lin;
	for(auto& ch: sin) lin.push_back(ch);
	//Reduce
	while(lin.size()>=2){
		auto it = lin.begin();
		it++;
		if(*it != *(it-1)){
			if((*it == 'a' && *(it-1) == 'b') || (*it == 'b' && *(it-1) == 'a')){lin.remove(it); *it = 'c';}
			if((*it == 'a' && *(it-1) == 'c') || (*it == 'c' && *(it-1) == 'a')){lin.remove(it); *it = 'b';}
			if((*it == 'b' && *(it-1) == 'c') || (*it == 'c' && *(it-1) == 'b')){lin.remove(it); *it = 'a';}
		}else
			it++;
	}
}

int main() {
	string sin;
	cin >> sin;
	cout <<"given string is "<<sin;
	list<char> lres = minReduce(sin);		
	return 0;
}
