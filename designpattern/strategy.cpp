//Strategy pattern - a class behaviour or its algorithms can be changed at runtime.
#include <iostream>

using namespace std;

class Strategy {
    public:
        virtual int doOperation(int a, int b) = 0;   
};

class AddOperation: public Strategy {
    public:
        int doOperation(int a , int b){
            return a+b;
        }
};

class SubOperation: public Strategy {
    public:
        int doOperation(int a , int b){
            return a-b;
        }
};

class MulOperation: public Strategy {
    public:
        int doOperation(int a , int b){
            return a*b;
        }
};

class Context {
    public:
        Context(Strategy *strategy) : strategy{strategy}{}
        int executeOperation(int a, int b){
            return strategy->doOperation(a, b);
        }
    private:
        Strategy *strategy;
};

int main(){
    Context *context = new Context(new AddOperation);
    cout << "10 + 5 = " << context->executeOperation(10, 5) << endl;

    context = new Context(new MulOperation);    
    cout << "10 * 5 = " << context->executeOperation(10, 5) << endl;

    context = new Context(new SubOperation);    
    cout << "10 - 5 = " << context->executeOperation(10, 5) << endl;
    
    return 0;
}