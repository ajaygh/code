#include <iostream>
#include <vector>
#define vn vector<node*>
#define vi vector<int>

#define all(c) c.begin(), c.end()
	
int mod = 1000000007;

using namespace std;

struct node {
	node():data{0},left{NULL},right{NULL}{}
	int data;
	node *left, *right;
};

long query(vn& vecn, int x, int y){
	if(x == y)
		return vecn[y-1]->data%mod; 
	else{
		vi path{x-1,y-1};
		int px,py;
		if(x%2 == 0)
			px = (x-2)/2;
		else
			px = (x == 1)?0:(x-3)/2;
		if(y%2 == 0)
			py = (y-2)/2;
		else
			py = (y == 1)?0:(y-3)/2;

		if(px == py ){
			if(px != x-1 && py != y-1)
		 	  	path.push_back(px);
		}else{
		   	if(x<y){
				while(x-1<py){
					path.push_back(py);
					py = (py-1)/2;
				}
			}else{
				while(px>y-1){
					path.push_back(px);
					px = (px-1)/2;
				}
			}
			while(px!= py){
				path.push_back(px);
				path.push_back(py);
				px = (px-1)/2;
				py = (px-1)/2;
			}
			if(px != x-1 && py != y-1)
				path.push_back(px);
		}
		long sum = 0;
		for(auto& el : path)
			sum = (sum + vecn[el]->data)%mod;
		return sum;
	}
}

void updatefib(vn& vecn, int x, int k, vi& vfib){
	if(x>=vecn.size() )return;
	long nf = 0;
	if(k>= vfib.size()){
		int tmp = vfib.size();
		while(tmp<= k){
			nf = (vfib[tmp-2] +vfib[tmp-1])%mod;
			tmp++;
			vfib.push_back(nf);
		}
	}
	vecn[x]->data = (vecn[x]->data + vfib[k])%mod;
	updatefib(vecn, 2*x+1,k+1,vfib);
	updatefib(vecn, 2*x+2,k+1,vfib);
}

int main() {
	int n,m;
	cin>>n>>m;
	node *root= new node;
	int i=1;
	vn fibn;
	fibn.push_back(root);
	int t;
	while(i<n){
		cin>>t;
		node *tmp = new node;
		if(fibn[t-1]->left){
			fibn[t-1]->right = tmp;
			fibn.push_back(tmp);
		}
		else{
			fibn[t-1]->left = tmp;
			fibn.push_back(tmp);
		}
		i++;
	}
	char opt;
	int x,y,k;
	vi vfib{1,1};

	for(int i=0;i<m;i++){
		cin>>opt;
		if(opt == 'Q'){
			cin>>x>>y;
			cout<<query(fibn, x, y)<<endl;
		}else if(opt == 'U'){
			cin>>x>>k;
			updatefib(fibn, x-1, k-1, vfib);
		}
	}
	return 0;
}
