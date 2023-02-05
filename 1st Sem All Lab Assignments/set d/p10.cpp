#include <iostream>
float pi = 3.14159265;

float volume(float side) { return side*side*side; } //for cube and cube

float volume(float a, float b, float c) { return a*b*c; }   //for cuboid

float volume(float radius, float height) { return pi*(radius*radius)*height; }    //for cylinder and cone


int main()
{
    int choice;
    float a,b,c,r,h;
    while(1) {
        std::cout<<"\n1 -> find volume of Cube";
        std::cout<<"\n2 -> find volume of Cuboid";
        std::cout<<"\n3 -> find volume of Cone";
        std::cout<<"\n4 -> find volume of Cylinder";
        std::cout<<"\n5 -> find volume of Shpere";
        std::cout<<"\n6 -> Exit";
        std::cout<<"\nEnter your choice: ";
        std::cin>>choice;

        switch (choice)
        {
        case 1:
            std::cout<<"\nEnter the side: ";
            std::cin>>a;
            std::cout<<"\nVolume of cube with side "<<a<<" is: "<<volume(a);
            break;
        case 2:
            std::cout<<"\nEnter three sides: ";
            std::cin>>a>>b>>c;
            std::cout<<"\nVolume of cuboid with sides "<<a<<" "<<b<<" "<<c<<" is: "<<volume(a,b,c);
            break;
        case 3:
            std::cout<<"\nEnter height and radius of cone: ";
            std::cin>>h>>r;
            std::cout<<"\nVolume of cone with height "<<h<<" and radius "<<r<<" is: "<<volume(r, h)/3;
            break;
        case 4:
            std::cout<<"\nEnter height and radius of Cylinder: ";
            std::cin>>h>>r;
            std::cout<<"\nVolume of cylinder with height "<<h<<" and radius "<<r<<" is: "<<volume(r, h);
            break;
        case 5:
            std::cout<<"\nEnter the radius of sphere: ";
            std::cin>>r;
            std::cout<<"\nVolume of sphere with radius "<<r<<" is: "<<volume(r)*(4.f/3.f)*pi;
            break;
        case 6:
            return 0;
        default:
            std::cout<<"\nInvalid option";
            break;
        }
    }
    
    return 0;
}