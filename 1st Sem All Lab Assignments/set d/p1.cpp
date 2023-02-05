#include <iostream>
constexpr float pi = 3.14159265;

class shape {
protected:
    float area;
public:
    shape() { std::cout<<"\nConstructor of shape"; }
    virtual void findArea() = 0;
};

class circle : public shape {
private:
    float radius;
public:
    circle() { std::cout<<"\nConstructor of circle"; }
    circle(float radius) {
        this->radius = radius;
        std::cout<<"\nConstructor of circle";
    }
    void findArea() {
        this->area = (pi*this->radius*this->radius);
    }
    void showArea() {
        std::cout<<this->area;
    }
};


int main()
{
    circle c(10);
    c.findArea();
    std::cout<<"\nArea of the given circle: ";
    c.showArea();
}