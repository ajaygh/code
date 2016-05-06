
#include <iostream>

using namespace std;

int minStepToDivide(const int& a, const int& b){
	int mult = 0, rem = 0;
	mult = a/b;
	rem = a%b;
	if(rem == 0) return 0;
	if(rem == 1 || rem == b-1 || (mult ==rem)) return 1;	
	if(mult > (b/2-1)){
		int first = (mult+rem)%(b-1);
		int second = mult>rem?(mult-rem)%(b-1):(mult-rem)%(b-1);
		return 1+(first<second?first:second);
	}
	if(rem < b/2){
		return rem/mult + rem%mult;
	}else{
		return ((b-rem)/(mult+1)) +((b-rem)%(mult+1));
	}
}

int main() {
	int a, b;
	cout <<"Enter a and b \n";
	cin >> a >>b;
	if(a > 0 && b > 0){
		if(a>b){
			cout<<"min step for "<<a <<" and "<<b<< " is "<<minStepToDivide(a,b)<<endl;
		}else
			cout<<"min step for "<<a<< " and "<<b <<" is "<<minStepToDivide(b, a)<<endl;
	}
	return 0;
} 
