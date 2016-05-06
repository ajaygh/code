//Find gcd of two numbers
#include <iostream>

using namespace std;

int modInverse(int b, int m);
int gcdExtended(int b, int m, int *x, int *y);

//Function to compute a/b under modulo m
int modDevide(int a, int b, int m){
	a %= m;
	int inv = modInverse(b, m);
	if(inv == -1)
		cout << "Devision not defined.\n";
	else
		cout << "Result of devision is " << (inv * a)%m << endl;
}

//Function to find modulo inverse of b. It returns -1 if 
//it does not exit
int modInverse(int b, int m){
	int x, y;
	int g = gcdExtended(b, m, &x, &y);
	
	//return -1 if b and m are not co-prime
	if(g != 1) return -1;
	//m is added to handle negative x
	return (x%m + m)%m;
}

//Extended euclidian algorithm to find inverse modulo
int gcdExtended(int a, int b, int *x, int *y){
	//base case
	if(a == 0){
		*x = 0, *y =1;
		return b;
	}

	int x1, y1; //to store recursive results
	int gcd = gcdExtended(b%a, a, &x1, &y1);
	//update x and y
	*x = y1 -(b/a)*x1;
	*y = x1;
	return gcd;
}

//Driver program
int main(){
	int a = 8, b = 3, m = 5;
	modDevide(a, b, m);
	return 0;
}
