#include <iostream>
#include <memory> 

using namespace std;

template<typename T>
class SharedPtr{
	public:
		SharedPtr(T *pObj):pObj(pObj),refc(new int(1)){
		}

		SharedPtr<T> operator=(const SharedPtr<T>& other){
			pObj = other.pObj;
		   	refc = other.refc;
			++(*refc);
			cout <<"Total refs after assign "<<*refc<<endl;
		}

		~SharedPtr(){
			if(--(*refc) == 0){
				delete pObj;
			}
		}
	private:
		SharedPtr<T>(const SharedPtr<T>& other):pObj{other.pObj}, refc{other.refc}{
			++(*refc);
			cout <<"Total refs "<<*refc<<endl;
		}

		T* pObj;
		int *refc;
};

class Test{
	public:
		Test(int n):n{n}{
			cout <<"Constructed test with n "<<n<<endl;
		}
		~Test(){
			cout << "destroying test obj.\n";
		}

	private:
		int n;
};

int main() {
	auto test = SharedPtr<Test>(new Test(10));	
	auto test1(test);
	auto test2 = test1;
	return 0;
} 
