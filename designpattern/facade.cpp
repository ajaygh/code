#include<iostream>

using namespace std;

//create interface with all methods as virtual
class Shape{
    public:
        virtual void draw() = 0;
};

class Circle:public Shape{
    public:
        void draw(){
            cout<<"Circle drawn.\n";
        }
};

class Square:public Shape{
    public:
        void draw(){
            cout<<"Square drawn.\n";
        }
};

class Rectangle:public Shape{
    public:
        void draw(){
            cout<<"Rectangle drawn.\n";
        }
};

class ShapeMaker{
    public:
        ShapeMaker(){
            circle = new Circle;
            square = new Square;
            rectangle = new Rectangle;
        }
        void drawCircle(){ circle->draw();}
        void drawSquare(){ square->draw();}
        void drawRectangle(){ rectangle->draw();}

    private:
        Circle* circle;
        Square* square;
        Rectangle* rectangle;
};

int main(){
    ShapeMaker *sm = new ShapeMaker;
    sm->drawCircle();
    sm->drawSquare();
    sm->drawRectangle();
}