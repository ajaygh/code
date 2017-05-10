#include <iostream>

using namespace std;

struct Employee{
	string name;
	int age;
	char sex;
};

int main() {
	Employee emp{"ramu", 45, 'm'};
	cout << emp.name << ' '<<emp.age << ' '<< emp.sex << endl;	
	return 0;
} 
