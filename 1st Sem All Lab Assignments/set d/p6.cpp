#include<iostream>
using namespace std;
class Year{
    int y;
    public:
    Year(int y){
        this->y=y;
        checkLeapYear();
    }
    ~Year(){
        checkLeapYear();
    }
    void checkLeapYear();
};
void Year::checkLeapYear(){
    if(y%100==0){
        if(y%400==0)
            cout<<"Leap Year"<<endl;
        else
            cout<<"Not a leap year"<<endl;
    }
    else if(y%4==0)
        cout<<"Leap year"<<endl;
    else
        cout<<"Not a leap year"<<endl;
}
int main(){
    Year year(2022);
    // year.checkLeapYear();
}