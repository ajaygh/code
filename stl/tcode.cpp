
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <set> 
#include <map> 
#include <sstream> 
#include <numeric>

using namespace std;

#define all(c) c.begin(), c.end()
#define present(c, elm) (c.find(elm) != c.end())
#define alpresent(c, elm) (find(all(c), elm) != c.end())

//#define tr(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

/*
template<typename T>
void reverseArrStlCompliant(T *begin, T *end){
	if(begin != end){
		end--;
		if(begin != end){
			while(true){
				swap(*begin, *end);
				begin++;
				if(begin == end){
					break;
				}
				end--;
				if(begin == end){
					break;
				}
			}
		}
	}
}
*/
void find_isum(const string& istr);

int main() {
	/*
	vector<int> v1(10);
	for(int i = 0;i < 10; i++) v1[i] = i+1;

	v1.resize(25);
	for(int i = 20; i < 25; i++)v1.push_back(i*2);
	for (auto x : v1) cout <<x<<"\t";
	cout<<endl;

	vector<string> vs(10,"ok");
	for (auto x : vs) cout <<x<<"\t";
	cout<<endl;

	vector<string> v2(vs);
	vector<string> v3(vs.begin(), vs.begin()+5);

	vector< vector<int> > mtx(10, vector<int>(10,-1));
	for (auto x : mtx){
		for (auto x1 : x) cout <<x1<<"\t";
		cout<<endl;
	}
	cout<<endl;

	*/
	vector<int> vit{111,15,8,11,33,45};
	for (auto x : vit)
		cout <<x<<"\t";
	cout<<endl;
	reverse(vit.begin(), vit.begin()+3);
	for (auto x : vit)
		cout <<x<<"\t";
	cout<<endl;

	//print all permutation 
	do{
		for (auto x : vit)
			cout <<x<<"\t";
		cout<<endl;
	}while(next_permutation(all(vit)));

	if(find(vit.begin(), vit.end(), 50) != vit.end())
		cout <<"49 found\n";
	else 
		cout <<"49 not found\n";
	if alpresent(vit, 33)
		cout <<"33 found\n";
	else 
		cout <<"33 not found\n";
	cout<<"max in vit is "<<*max_element(all(vit))<<endl;
	cout<<"min in vit is "<<*min_element(all(vit))<<endl;

	sort(all(vit));
	for (auto x : vit)
		cout <<x<<"\t";
	cout<<endl;
	/*
	int sq = 0;
	tr(vit, it){
		r += (*it)*(*it);
	}
	cout << "squared sum of vit is "<< r<<endl;
*/
	string ss = "aaaaaksdddd";
	string s1= ss.substr(0,4);
	cout <<s1<<endl;

	set<int> set1(all(vit));
	if present(set1, 111)
		cout <<"111 preset\n";
	else
		cout <<"111 not preset\n";
	
	map<string, int> mm;
	mm["aaa"] = 4;
	mm["bbb"] = 5;
	mm["ccc"] = 6;
	cout<<"sum of 2 ele map is "<<mm["aaa"] + mm["bbb"]<<endl;

	if present(mm, "aaa"){
		cout<< "aaa is present\n";
		mm.erase(mm.find("aaa"));
	}

	//read int from string
	string istr = "12 33 54 0 1";
	find_isum(istr);
	return 0;
} 

void find_isum(const string& istr){
	istringstream is(istr);

	vector<int> v;
	int tmp;
	while(is >> tmp)
		v.push_back(tmp);
	int sum = accumulate(all(v), 0);
	cout << "sum of all num in str is" <<sum<<endl;

	ostringstream os;
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		os <<' '<<*it + 5;
	}
	string ostr = os.str();

	//remove first space
	if(!ostr.empty())
		ostr = ostr.substr(1);

	cout<<"output str is "<<ostr<<endl;
}
