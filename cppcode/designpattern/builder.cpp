#include<iostream>
#include <vector>

using namespace std;

class Packing{
    public:
        virtual string pack() = 0;
};

class Bottle: public Packing{
    public:
        string pack(){ return "Bottle";}
};

class Wrapper: public Packing{
    public:
        string pack(){ return "Wrapper";}
};

//base interface item 
class Item{
    public:
        virtual string name() = 0;
        virtual Packing* getPacking();
        virtual float getPrice();
};

class Burger: public Item{
    public:
        Packing* getPacking(){
            return new Wrapper;
        }
};

class ColdDrink: public Item{
    public:
        Packing* getPacking(){
            return new Bottle;
        }
};

class VegBurger: public Burger{
    public:
        string name(){return "VegBurger";}
        float getPrice(){ return 10.5;}
};

class NonVegBurger: public Burger{
    public:
        string name(){return "NonVegBurger";}
        float getPrice(){ return 15.5;}
};

class Coke : public ColdDrink{
    public:
        string name(){ return "Coke"; }
        float getPrice(){ return 1.5; }
};

class Pepsi : public ColdDrink{
    public:
        string name(){ return "Pepsi"; }
        float getPrice(){ return 2.5; }
};

class Meal{
    public:
        void addItem(Item* item){
            items.push_back(item);
            cost += item->getPrice();
        }
        float getCost(){return cost;}
        void showItem(){
            for(auto item: items)
                cout<<"item name "<<item->name()<<" cost "<< item->getPrice() << endl;
        }
    private:
        vector<Item*> items;
        float cost;
};

class MealBuilder{
    public:
        void prepareVegMeal(){
            Meal* meal = new Meal;
            meal->addItem(new VegBurger);
            meal->addItem(new Coke);
            meal->showItem();
            cout<<"veg meal cost is " << meal->getCost() << endl;
        }

        void prepareNonVegMeal(){
            Meal* meal = new Meal;
            meal->addItem(new NonVegBurger);
            meal->addItem(new Pepsi);
            meal->showItem();
            cout<<"non meal cost is " << meal->getCost() << endl;
        }
};

int main(){
    MealBuilder* mb = new MealBuilder;
    mb->prepareVegMeal();
    mb->prepareNonVegMeal();

    return 0;
}