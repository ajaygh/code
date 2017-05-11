//template pattern an abstract class exposes defined ways/templates to execute its methods
//subclasses can override method implementation but invocation
// is controlled by abstract class

#include <iostream>

using namespace std;

class Game {
    public:
        virtual void initialize() = 0; 
        virtual void endGame() = 0; 
        virtual void startGame() = 0;
        void play(){
            initialize();
            startGame();
            endGame();
        }     
};

class Cricket : public Game {
    public:
        void initialize(){
            cout << "Cricket game initialized. Start playing.\n";
        }
        void startGame(){
            cout << "Cricket game started. Enjoy!!\n";
        }
        void endGame(){
            cout << "Cricket game finished. Stop.\n";
        }
};

class Football : public Game {
    public:
        void initialize(){
            cout << "Football game initialized. Start playing.\n";
        }
        void startGame(){
            cout << "Football game started. Enjoy!!\n";
        }
        void endGame(){
            cout << "Football game finished. Stop.\n";
        }
};

int main(){
    Game *game = new Cricket;
    game->play();

    game = new Football;
    game->play();
    return 0;
}