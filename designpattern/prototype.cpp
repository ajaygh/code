//Prototype pattern demo
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Shape{
    public:
        virtual void draw()=0;
        string getId(){
            return id;
        }
        void setId(string _id){
            id = _id;
        }
    protected:
        string Type;
    private:
        string id;
};

class Rectangle : public Shape{
    public:
        Rectangle(){ 
            Type = "Rectangle";
        }
    void draw(){
        cout<<"Inside Rectangle : draw().\n";
    }
};

class Square : public Shape{
    public:
        Square(){
            Type = "Square";
        }
    void draw(){
        cout<<"Inside Square : draw().\n";
    }
};

class Circle : public Shape{
    public:
        Circle(){
            Type = "Circle";
        }
    void draw(){
        cout<<"Inside Circle : draw().\n";
    }
};

class ShapeCache{
    public:
        //load simulates costly database request
        static void loadCache(){
            Circle *circle = new Circle;
            circle->setId("1");
            cacheMap[circle->getId()] = circle;

            Rectangle *rectangle = new Rectangle;
            rectangle->setId("2");
            cacheMap[rectangle->getId()] = rectangle;

            Square *square = new Square;
            square->setId("3");
            cacheMap[square->getId()] = square;
        }
        static Shape* getShape(string id);
    private:
        static map<string, Shape*> cacheMap;
};

map<string, Shape*> ShapeCache:: cacheMap;
Shape* ShapeCache::getShape(string id){
            return cacheMap[id];
}
int main(){
    
    ShapeCache::loadCache();

    Shape* shape1 = ShapeCache::getShape("1");
    cout << "Shape id is "<<shape1->getId()<< endl;
    shape1->draw();

    Shape* shape2 = ShapeCache::getShape("2");
    cout << "Shape id is "<<shape2->getId()<< endl;
    shape2->draw();

    Shape* shape3 = ShapeCache::getShape("3");
    cout << "Shape id is "<<shape3->getId()<< endl;
    shape3->draw();

    return 0;
 }