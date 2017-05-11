//state pattern class behaviour changes as per state.
#include <iostream>

using namespace std;

class State;

class Context {
    public:
        Context():state{nullptr}{}
        State* getState(){ return state; }
        void setState(State *_state){ state = _state; }
    private:
        State *state;
};

class State {
    public:
        virtual void doAction(Context *context) = 0;
        string state;      
};

class StartState : public State {
    public:
        void doAction(Context *context){
            cout << "player is in start state.\n";
            context->setState(this);
        }   
};

class StopState : public State {
    public:
        void doAction(Context *context){
            cout << "player is in stop state.\n";
            context->setState(this);            
        }   
};

int main(){
    Context *context = new Context;
    StartState *startState = new StartState;
    startState->doAction(context);
    cout << (context->getState())->state << endl;

    StopState *stopState = new StopState;
    stopState->doAction(context);
    cout << context->getState()->state << endl;
    return 0;
}