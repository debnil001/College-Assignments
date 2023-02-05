#include <iostream>

class Complex {
private:
    int real, img;
public:
    Complex() {};
    Complex(const Complex& object) {
        this->real = object.real;
        this->img = object.img;
    }
    Complex(const int& real, const int& img) {
        this->real = real;
        this->img = img;
    }

    void show() {
        std::cout<<this->real<<" + i"<<this->img<<"\n";
    }

    Complex sum(const Complex& ob) {
        Complex temp;
        temp.real = this->real + ob.real;
        temp.img = this->img + ob.img;
        return temp;
    }

    Complex operator+(const Complex ob) {
        Complex temp;
        temp.real = this->real + ob.real;
        temp.img = this->img + ob.img;
        return temp;
    }

};



int main()
{
    Complex *a = new Complex(10, 12);
    Complex *b = a;
    Complex *c = new Complex(6, 8);
    std::cout<<"\nComplex number a: ";
    a->show();
    std::cout<<"\nComplex number b: ";
    b->show();
    std::cout<<"\nComplex number c: ";
    c->show();

    // Complex x = a->sum(*b);
    *b = *a + *c;
    std::cout<<"\na + c = ";
    b->show();
}