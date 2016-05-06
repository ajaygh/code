
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int sid=0,pid=0;

class Person{
	public:
	virtual void getdata(){};
	virtual void putdata(){};
	protected:
	string name;
	int age;	
};

class Student: public Person{
	public:
		Student(){ marks.resize(6);
			sid++;
			id = sid;
		}
		void getdata(){
			cin >>name>>age;
			for(int i=0;i<6;i++){
				int tmp;
				cin >>tmp;
				marks.push_back(tmp);
			}
		}
		void putdata() {
			cout<<name<<" "<<age<<" "<<accumulate(marks.begin(), marks.end(), 0)<<" "<<id<<endl;
		}
	int id;
	private:
	vector<int> marks;

};

class Professor: public Person{
	public:
		Professor(){pid++; id = pid;}
		void getdata(){
			cin >>name>>age>>publications;
		}
		void putdata(){
			cout<<name<<" "<<age<<" "<<publications<<" "<<id<<endl;
		}
	int id;
	private:
	int	publications;
};

int main() {
	int n, val;
	cin>>n; 
	Person *per[n];

    for(int i = 0;i < n;i++){
				
		cin>>val;
		if(val == 1){
			per[i] = new Professor;
		}else
			per[i] = new Student;
		per[i]->getdata();
	}
	for(int i = 0;i < n;i++)
		per[i]->putdata();

	return 0;
}
