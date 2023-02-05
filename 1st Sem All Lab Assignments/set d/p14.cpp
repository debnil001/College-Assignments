#include<iostream>
using namespace std;
class A{
    int a,b;
    public:
    A(int a,int b){
        this->a=a;
        this->b=b;
    }
    friend void swap(A&);
    void print();
};
void A::print(){
    cout<<"a= "<<a<<"b= "<<b;
}
void swap(A& obj){
    obj.a=obj.a+obj.b;
    obj.b=obj.a-obj.b;
    obj.a=obj.a-obj.b;
    printf("\nSwapped\n");
}

int main(){
    A obj=A(5,10);
    obj.print();
    swap(obj);
    obj.print();
    return 0;
}