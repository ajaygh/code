//visitor is a behavioural design pattern. visitor class changes the execution algorithm
//of element class.
#include <iostream>

using namespace std;

class Monitor;
class Mouse;
class Keyboard;
class Computer;

class ComputerPartVisitor {
    public:
        virtual void visit(Mouse*) = 0;
        virtual void visit(Monitor*) = 0;
        virtual void visit(Keyboard*) = 0;
        virtual void visit(Computer*) = 0;
};

class ComputerPart {
    public:
        virtual void accept(ComputerPartVisitor*) = 0;
};

class Mouse : public ComputerPart {
    public:
        void accept(ComputerPartVisitor *computerPartVisitor){
            computerPartVisitor->visit(this);
        }
};

class Keyboard : public ComputerPart {
    public:
        void accept(ComputerPartVisitor *computerPartVisitor){
            computerPartVisitor->visit(this);
        }
};

class Monitor : public ComputerPart {
    public:
        void accept(ComputerPartVisitor *computerPartVisitor){
            computerPartVisitor->visit(this);
        }
};

class Computer : public ComputerPart {
    public:
        Computer(){
            parts[0] = new Mouse;
            parts[1] = new Monitor;
            parts[2] = new Keyboard;
        }
        void accept(ComputerPartVisitor *computerPartVisitor){
            for(int i = 0; i < 3; i++){
                parts[i]->accept(computerPartVisitor);
            }
            computerPartVisitor->visit(this);
        }
    private:
        ComputerPart* parts[3];
};

class ComputerPartDisplayVisitor : public ComputerPartVisitor {
    public:
        void visit(Mouse* mouse){
            cout << "Displaying mouse.\n";
        }
        void visit(Monitor *monitor){
            cout << "Displaying monitor.\n";
        } 
        void visit(Keyboard *keyboard){
            cout << "Displaying Keyboard.\n";
        }
        void visit(Computer *computer){
            cout << "Displaying Computer.\n";
        }
};

int main(){
    Computer *computer = new Computer;
    computer->accept(new ComputerPartDisplayVisitor);
    return 0;
}