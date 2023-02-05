#include <iostream>
#include <string>

class Shape {
public:
    Shape() { std::cout<<"\nConstructor of Shape"; }
    virtual ~Shape() { std::cout<<"\nDestructor of Shape"; }
};

class Cirlce : public Shape {
private:
    std::string type;
public:
    Cirlce() {
        type = "Circle";
        std::cout<<"\nConstructor of Circle"; 
    }
    virtual ~Cirlce() { std::cout<<"\nDestructor of Circle"; }
    Cirlce(const Cirlce& obj) { this->type = obj.type; }
    void showType() { std::cout<<"\n"<<type<<" type object"; }
};

class GenericShape : public Shape {
private:
    std::string type;
public:
    GenericShape() { }
    GenericShape(std::string type) { this->type = type; }
    ~GenericShape() { std::cout<<"\nDestructor of Generic Shape"; }
    void showType() { std::cout<<"\n"<<type<<" type object"; }
};


int main()
{
    Cirlce *c1 = new Cirlce();
    Cirlce *c2 = c1;
    c1->showType();
    c2->showType();
    Shape *s1 = c1;

    delete s1;

    GenericShape *g1 = new GenericShape("Rectangle");
    Shape *s2 = g1;
    g1->showType();
    delete s2;
}