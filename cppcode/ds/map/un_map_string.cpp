#include <iostream>
#include <map>
#include <string.h>
#include <typeinfo> 

using namespace std;

struct strCmp{
	bool operator()(const char *a, const char *b){
		return (strcmp(a, b) < 0);
	}
};

map<const char*, int,  strCmp> mt;

int fun(const char * eventCode) {
	auto it = mt.find(eventCode);
	if(it != mt.end()){
		cout << "found "<<eventCode<<" value "<<it->second<<endl;
	}else{
		cout <<"not found\n";
	}	
	return 0;
} 

int main() {
    const char a[100] = "middleware_start";
    const char *b = "middleware_restart";
    const char *c = "mtddleware_restart";
mt["middleware_restart"] = 20;
mt["middleware_start"] = 50;
	fun(a);
	fun(b);
	fun(c);
	return 0;
}
