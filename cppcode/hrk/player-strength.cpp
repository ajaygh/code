#include <iostream>
#include <vector>
#define vi vector<int>
#define all(c) c.begin(), c.end()

using namespace std;

struct crickter{
	crickter(int _a, int _b):a{_a},b{_b}{}
	int a,b;
};

struct player{
	player(int _c, int _d):c{_c},d{_d}{}
	int c,d;
};

int findl(const vector<crickter> &vc, int num){
	int l=0,h = vc.size()-1,m,p=-1;

	do{
		m = (l+h)/2;
		if((num <= vc[m].b) && (num >= vc[m].a)){
			if((m != 0) && num == vc[m-1].b)
				p=m-1;
			else p = m;
			break;
		}else if(num > vc[m].b)
			l=m+1;
		else if(num < vc[m].a)
			h = m-1;
	}while(l <= h);
	return p;
}

int findr(const vector<crickter> &vc, int num){
	int l=0,h = vc.size()-1,m,p=-1;

	do{
		m = (l+h)/2;
		if((num <= vc[m].b) && (num >= vc[m].a)){
			if((m != vc.size()-1) && num == vc[m+1].a)
				p=m+1;
			else p = m;
			break;
		}else if(num > vc[m].b)
			l=m+1;
		else if(num < vc[m].a)
			h = m-1;
	}while(l <= h);
	return p;
}

int main() {
	int n,m,a,b,c,d, pl, pr,total=0;
	cin>>n>>m;
	vector<crickter> vc;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		vc.push_back(crickter(a,b));
	}
	vector<player> vp;
	for(int i=0;i<m;i++){
		cin>>c>>d;
		pl = findl(vc, c);
		pr = findr(vc, d);
		if(pl != -1 && pr != -1)
			total += (pr-pl+1);
		//vc.push_back(crickter(a,b));
	}
	cout<<total<<endl;
	return 0;
}
