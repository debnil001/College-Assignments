#include <iostream>
#include <math.h>

class Triangle {
private:
	int a,b,c;
	float area, peri;
	
public:
	Triangle() {
		//nothing
	}
	
	Triangle(int a, int b, int c) {
		this->a = a;
		this->a = b;
		this->c = c;
	}
	
	void input() {
		std::cout<<"\nEnter the sides of the triangel: ";
		std::cin >> this->a >> this->b >> this->c;
	}
	
	void show() {
		std::cout<<"\nSides of triangle: "<<a<<", "<<b<<", "<<c;
		std::cout<<"\nArea is: "<<area;
		std::cout<<"\nPerimeter is: "<<peri;
	}
	
	void findArea(void );
	void findPeri(void );
	
};

void Triangle::findArea() {
	float s = this->a + this->b + this->c;
	s = s/2;
	
	float temp = (s - this->a) * (s - this->b) * (s - this->c);
	temp = sqrt(temp);
	this->area = temp;
}

void Triangle::findPeri() {
	this->peri = this->a + this->b + this->c;
}


int main()
{
	Triangle *t = new Triangle();
	
	t->input();
	t->findArea();
	t->findPeri();
	t->show();
	
}





