#include <iostream>

using namespace std;

int* add(int a, int b){
	int tmp = a+b;
	return move(&tmp);
}
int main() {
	cout << *add(3, 5) << endl;
	return 0;
} 
